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

// Function: modmidi_00000000
// Address: 0x0 - 0x100
void modmidi_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x34u: goto label_34;
        case 0x40u: goto label_40;
        case 0x48u: goto label_48;
        case 0x54u: goto label_54;
        case 0x88u: goto label_88;
        case 0xa0u: goto label_a0;
        case 0xbcu: goto label_bc;
        case 0xfcu: goto label_fc;
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
    // 0x28: 0x10400032  beqz        $v0, . + 4 + (0x32 << 2)
    ctx->pc = 0x28u;
    {
        const bool branch_taken_0x28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2c: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x28) {
            ctx->pc = 0xF4u;
            goto label_f4;
        }
    }
    ctx->pc = 0x30u;
    // 0x30: 0x24b40004  addiu       $s4, $a1, 0x4
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
label_34:
    // 0x34: 0x8e910000  lw          $s1, 0x0($s4)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x38: 0xc000df0  jal         func_0037C0
    ctx->pc = 0x38u;
    SET_GPR_U32(ctx, 31, 0x40u);
    // 0x3c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x37C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x37C0u, 0x38u, 0x40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x40u;
label_40:
    // 0x40: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x40u;
    {
        const bool branch_taken_0x40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x40) {
            ctx->pc = 0xE4u;
            goto label_e4;
        }
    }
    ctx->pc = 0x48u;
label_48:
    // 0x48: 0x82240000  lb          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x4c: 0xc000dee  jal         func_0037B8
    ctx->pc = 0x4Cu;
    SET_GPR_U32(ctx, 31, 0x54u);
    ctx->pc = 0x37B8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x37B8u, 0x4Cu, 0x54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x54u;
label_54:
    // 0x54: 0x30420008  andi        $v0, $v0, 0x8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x58: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x58u;
    {
        const bool branch_taken_0x58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x58) {
            ctx->pc = 0x68u;
            goto label_68;
        }
    }
    ctx->pc = 0x60u;
    // 0x60: 0x8000012  j           func_000048
    ctx->pc = 0x60u;
    // 0x64: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    ctx->pc = 0x48u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_48;
    ctx->pc = 0x68u;
label_68:
    // 0x68: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x6c: 0x8c423e54  lw          $v0, 0x3E54($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15956)));
    // 0x70: 0x0  nop
    // NOP
    // 0x74: 0x1840001b  blez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x74u;
    {
        const bool branch_taken_0x74 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x74) {
            ctx->pc = 0xE4u;
            goto label_e4;
        }
    }
    ctx->pc = 0x7Cu;
    // 0x7c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x80: 0x26103e54  addiu       $s0, $s0, 0x3E54
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 15956));
    // 0x84: 0x9021  addu        $s2, $zero, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_88:
    // 0x88: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0x8c: 0xb22821  addu        $a1, $a1, $s2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 18)));
    // 0x90: 0x8ca53e50  lw          $a1, 0x3E50($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 15952)));
    // 0x94: 0x8e060000  lw          $a2, 0x0($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x98: 0xc000df2  jal         func_0037C8
    ctx->pc = 0x98u;
    SET_GPR_U32(ctx, 31, 0xA0u);
    // 0x9c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x37C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x37C8u, 0x98u, 0xA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA0u;
label_a0:
    // 0xa0: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0xA0u;
    {
        const bool branch_taken_0xa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xa4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xa0) {
            ctx->pc = 0xD0u;
            goto label_d0;
        }
    }
    ctx->pc = 0xA8u;
    // 0xa8: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xac: 0x2406000a  addiu       $a2, $zero, 0xA
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0xb0: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0xb4: 0xc000df4  jal         func_0037D0
    ctx->pc = 0xB4u;
    SET_GPR_U32(ctx, 31, 0xBCu);
    // 0xb8: 0x2242021  addu        $a0, $s1, $a0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    ctx->pc = 0x37D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x37D0u, 0xB4u, 0xBCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBCu;
label_bc:
    // 0xbc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xc0: 0x721821  addu        $v1, $v1, $s2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0xc4: 0x8c633e58  lw          $v1, 0x3E58($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 15960)));
    // 0xc8: 0x8000039  j           func_0000E4
    ctx->pc = 0xC8u;
    // 0xcc: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0xE4u;
    goto label_e4;
    ctx->pc = 0xD0u;
label_d0:
    // 0xd0: 0x2610000c  addiu       $s0, $s0, 0xC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0xd4: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xd8: 0x0  nop
    // NOP
    // 0xdc: 0x1c40ffea  bgtz        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0xDCu;
    {
        const bool branch_taken_0xdc = (GPR_S32(ctx, 2) > 0);
        // 0xe0: 0x2652000c  addiu       $s2, $s2, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
        if (branch_taken_0xdc) {
            ctx->pc = 0x88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_88;
        }
    }
    ctx->pc = 0xE4u;
label_e4:
    // 0xe4: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0xe8: 0x275102a  slt         $v0, $s3, $s5
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0xec: 0x1440ffd1  bnez        $v0, . + 4 + (-0x2F << 2)
    ctx->pc = 0xECu;
    {
        const bool branch_taken_0xec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xf0: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        if (branch_taken_0xec) {
            ctx->pc = 0x34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_34;
        }
    }
    ctx->pc = 0xF4u;
label_f4:
    // 0xf4: 0xc000dd1  jal         func_003744
    ctx->pc = 0xF4u;
    SET_GPR_U32(ctx, 31, 0xFCu);
    // 0xf8: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x3744u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3744u, 0xF4u, 0xFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFCu;
label_fc:
    // 0xfc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
}


// Function: modmidi_00000100
// Address: 0x100 - 0x11c
void modmidi_00000100_0x100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000100_0x100");
#endif

    switch (ctx->pc) {
        case 0x10cu: goto label_10c;
        case 0x118u: goto label_118;
        default: break;
    }

    ctx->pc = 0x100u;

    // 0x100: 0x248436a0  addiu       $a0, $a0, 0x36A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13984));
    // 0x104: 0xc000ddc  jal         func_003770
    ctx->pc = 0x104u;
    SET_GPR_U32(ctx, 31, 0x10Cu);
    ctx->pc = 0x3770u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3770u, 0x104u, 0x10Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10Cu;
label_10c:
    // 0x10c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x110: 0xc000dd3  jal         func_00374C
    ctx->pc = 0x110u;
    SET_GPR_U32(ctx, 31, 0x118u);
    // 0x114: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x374Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x374Cu, 0x110u, 0x118u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x118u;
label_118:
    // 0x118: 0x10102b  sltu        $v0, $zero, $s0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
}


// Function: modmidi_0000011c
// Address: 0x11c - 0x140
void modmidi_0000011c_0x11c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000011c_0x11c");
#endif

    ctx->pc = 0x11cu;

    // 0x11c: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x120: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x124: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x128: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x12c: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x130: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x134: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138: 0x3e00008  jr          $ra
    ctx->pc = 0x138u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x13c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x138u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x140u;
}


// Function: modmidi_00000140
// Address: 0x140 - 0x1b0
void modmidi_00000140_0x140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000140_0x140");
#endif

    ctx->pc = 0x140u;

    // 0x140: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x144: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
    // 0x148: 0x80a821  addu        $s5, $a0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x14c: 0x529c0  sll         $a1, $a1, 7
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x150: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x154: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
    // 0x158: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x15c: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x160: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x164: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x168: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x16c: 0xac253ed0  sw          $a1, 0x3ED0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 16080), GPR_U32(ctx, 5));
    // 0x170: 0x12a00045  beqz        $s5, . + 4 + (0x45 << 2)
    ctx->pc = 0x170u;
    {
        const bool branch_taken_0x170 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0x174: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x170) {
            ctx->pc = 0x288u;
            return;
        }
    }
    ctx->pc = 0x178u;
    // 0x178: 0x8ea20000  lw          $v0, 0x0($s5)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x17c: 0x8eb10004  lw          $s1, 0x4($s5)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x180: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x184: 0x14400040  bnez        $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x184u;
    {
        const bool branch_taken_0x184 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x188: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x184) {
            ctx->pc = 0x288u;
            return;
        }
    }
    ctx->pc = 0x18Cu;
    // 0x18c: 0x1220003e  beqz        $s1, . + 4 + (0x3E << 2)
    ctx->pc = 0x18Cu;
    {
        const bool branch_taken_0x18c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c) {
            ctx->pc = 0x288u;
            return;
        }
    }
    ctx->pc = 0x194u;
    // 0x194: 0x8e230000  lw          $v1, 0x0($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x198: 0x8e240004  lw          $a0, 0x4($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x19c: 0x30620001  andi        $v0, $v1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1a0: 0x14400039  bnez        $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x1A0u;
    {
        const bool branch_taken_0x1a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1a0) {
            ctx->pc = 0x288u;
            return;
        }
    }
    ctx->pc = 0x1A8u;
    // 0x1a8: 0x10800027  beqz        $a0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1A8u;
    {
        const bool branch_taken_0x1a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x1ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1a8) {
            ctx->pc = 0x248u;
            return;
        }
    }
    ctx->pc = 0x1B0u;
}


// Function: modmidi_000001b0
// Address: 0x1b0 - 0x2ac
void modmidi_000001b0_0x1b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000001b0_0x1b0");
#endif

    switch (ctx->pc) {
        case 0x1c8u: goto label_1c8;
        case 0x1dcu: goto label_1dc;
        case 0x210u: goto label_210;
        case 0x248u: goto label_248;
        case 0x258u: goto label_258;
        case 0x288u: goto label_288;
        default: break;
    }

    ctx->pc = 0x1b0u;

    // 0x1b0: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b4: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1B4u;
    {
        const bool branch_taken_0x1b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b8: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b4) {
            ctx->pc = 0x22Cu;
            goto label_22c;
        }
    }
    ctx->pc = 0x1BCu;
    // 0x1bc: 0x24140001  addiu       $s4, $zero, 0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0: 0x24130001  addiu       $s3, $zero, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1c8:
    // 0x1c8: 0x8e44000c  lw          $a0, 0xC($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1cc: 0x0  nop
    // NOP
    // 0x1d0: 0x1080000f  beqz        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D0u;
    {
        const bool branch_taken_0x1d0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x1d4: 0x2403000f  addiu       $v1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        if (branch_taken_0x1d0) {
            ctx->pc = 0x210u;
            goto label_210;
        }
    }
    ctx->pc = 0x1D8u;
    // 0x1d8: 0x2482001e  addiu       $v0, $a0, 0x1E
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 30));
label_1dc:
    // 0x1dc: 0xa4540010  sh          $s4, 0x10($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 16), (uint16_t)GPR_U32(ctx, 20));
    // 0x1e0: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1e4: 0x461fffd  bgez        $v1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x1E4u;
    {
        const bool branch_taken_0x1e4 = (GPR_S32(ctx, 3) >= 0);
        // 0x1e8: 0x2442fffe  addiu       $v0, $v0, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
        if (branch_taken_0x1e4) {
            ctx->pc = 0x1DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dc;
        }
    }
    ctx->pc = 0x1ECu;
    // 0x1ec: 0xa4940030  sh          $s4, 0x30($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 48), (uint16_t)GPR_U32(ctx, 20));
    // 0x1f0: 0xac800034  sw          $zero, 0x34($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x1f4: 0xac80003c  sw          $zero, 0x3C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 0));
    // 0x1f8: 0xac800044  sw          $zero, 0x44($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
    // 0x1fc: 0xac80004c  sw          $zero, 0x4C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 0));
    // 0x200: 0xac800054  sw          $zero, 0x54($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 84), GPR_U32(ctx, 0));
    // 0x204: 0x2a02021  addu        $a0, $s5, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x208: 0xc0000ea  jal         func_0003A8
    ctx->pc = 0x208u;
    SET_GPR_U32(ctx, 31, 0x210u);
    // 0x20c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x3A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3A8u, 0x208u, 0x210u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x210u;
label_210:
    // 0x210: 0x26730002  addiu       $s3, $s3, 0x2
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x214: 0x26520010  addiu       $s2, $s2, 0x10
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x218: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x21c: 0x0  nop
    // NOP
    // 0x220: 0x262102a  slt         $v0, $s3, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x224: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x224u;
    {
        const bool branch_taken_0x224 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x228: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x224) {
            ctx->pc = 0x1C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c8;
        }
    }
    ctx->pc = 0x22Cu;
label_22c:
    // 0x22c: 0x26310008  addiu       $s1, $s1, 0x8
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x230: 0x8e220000  lw          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x234: 0x8e240004  lw          $a0, 0x4($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x238: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x238u;
    {
        const bool branch_taken_0x238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x238) {
            ctx->pc = 0x248u;
            goto label_248;
        }
    }
    ctx->pc = 0x240u;
    // 0x240: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x240u;
    {
        const bool branch_taken_0x240 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x240) {
            ctx->pc = 0x250u;
            goto label_250;
        }
    }
    ctx->pc = 0x248u;
label_248:
    // 0x248: 0x80000a2  j           func_000288
    ctx->pc = 0x248u;
    // 0x24c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x288u;
    goto label_288;
    ctx->pc = 0x250u;
label_250:
    // 0x250: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x250u;
    {
        const bool branch_taken_0x250 = (GPR_S32(ctx, 2) <= 0);
        // 0x254: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x250) {
            ctx->pc = 0x284u;
            goto label_284;
        }
    }
    ctx->pc = 0x258u;
label_258:
    // 0x258: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x25c: 0x0  nop
    // NOP
    // 0x260: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x260u;
    {
        const bool branch_taken_0x260 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x260) {
            ctx->pc = 0x26Cu;
            goto label_26c;
        }
    }
    ctx->pc = 0x268u;
    // 0x268: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_26c:
    // 0x26c: 0x24840008  addiu       $a0, $a0, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x270: 0x8e230000  lw          $v1, 0x0($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x274: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x278: 0x43102a  slt         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x27c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x27Cu;
    {
        const bool branch_taken_0x27c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x280: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x27c) {
            ctx->pc = 0x258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_258;
        }
    }
    ctx->pc = 0x284u;
label_284:
    // 0x284: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_288:
    // 0x288: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x28c: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x290: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x294: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x298: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x29c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2a0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2a4: 0x3e00008  jr          $ra
    ctx->pc = 0x2A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2ACu;
}


// Function: modmidi_000002ac
// Address: 0x2ac - 0x2b0
void modmidi_000002ac_0x2ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000002ac_0x2ac");
#endif

    ctx->pc = 0x2acu;

    // 0x2ac: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
}


// Function: modmidi_000002b0
// Address: 0x2b0 - 0x3a8
void modmidi_000002b0_0x2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000002b0_0x2b0");
#endif

    switch (ctx->pc) {
        case 0x334u: goto label_334;
        case 0x344u: goto label_344;
        default: break;
    }

    ctx->pc = 0x2b0u;

    // 0x2b0: 0x8c423e4c  lw          $v0, 0x3E4C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15948)));
    // 0x2b4: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x2b8: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x2bc: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2c0: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x2c4: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2c8: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    // 0x2cc: 0x27b10040  addiu       $s1, $sp, 0x40
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x2d0: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x2d4: 0x27b00044  addiu       $s0, $sp, 0x44
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
    // 0x2d8: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x2dc: 0xafa40040  sw          $a0, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 4));
    // 0x2e0: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x2E0u;
    {
        const bool branch_taken_0x2e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2e4: 0xafa50044  sw          $a1, 0x44($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 5));
        if (branch_taken_0x2e0) {
            ctx->pc = 0x334u;
            goto label_334;
        }
    }
    ctx->pc = 0x2E8u;
    // 0x2e8: 0x83a20040  lb          $v0, 0x40($sp)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x2ec: 0x83a50043  lb          $a1, 0x43($sp)
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 67)));
    // 0x2f0: 0x83a60042  lb          $a2, 0x42($sp)
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 66)));
    // 0x2f4: 0x83a70041  lb          $a3, 0x41($sp)
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 65)));
    // 0x2f8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x2fc: 0x82020003  lb          $v0, 0x3($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x300: 0x0  nop
    // NOP
    // 0x304: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x308: 0x82020002  lb          $v0, 0x2($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x30c: 0x0  nop
    // NOP
    // 0x310: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x314: 0x82020001  lb          $v0, 0x1($s0)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x318: 0x0  nop
    // NOP
    // 0x31c: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x320: 0x83a20044  lb          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x324: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x328: 0x24843834  addiu       $a0, $a0, 0x3834
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14388));
    // 0x32c: 0xc000de5  jal         func_003794
    ctx->pc = 0x32Cu;
    SET_GPR_U32(ctx, 31, 0x334u);
    // 0x330: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x32Cu, 0x334u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x334u;
label_334:
    // 0x334: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x338: 0x26460003  addiu       $a2, $s2, 0x3
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
    // 0x33c: 0x26670003  addiu       $a3, $s3, 0x3
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 3));
    // 0x340: 0x2251021  addu        $v0, $s1, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
label_344:
    // 0x344: 0xc51823  subu        $v1, $a2, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x348: 0x80440000  lb          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x34c: 0x80620000  lb          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x350: 0x0  nop
    // NOP
    // 0x354: 0x1482000d  bne         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x354u;
    {
        const bool branch_taken_0x354 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x358: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x354) {
            ctx->pc = 0x38Cu;
            goto label_38c;
        }
    }
    ctx->pc = 0x35Cu;
    // 0x35c: 0x2051021  addu        $v0, $s0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x360: 0xe51823  subu        $v1, $a3, $a1
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x364: 0x80440000  lb          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x368: 0x80620000  lb          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x36c: 0x0  nop
    // NOP
    // 0x370: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x370u;
    {
        const bool branch_taken_0x370 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x374: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x370) {
            ctx->pc = 0x38Cu;
            goto label_38c;
        }
    }
    ctx->pc = 0x378u;
    // 0x378: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x37c: 0x2ca20004  sltiu       $v0, $a1, 0x4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x380: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x380u;
    {
        const bool branch_taken_0x380 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x384: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        if (branch_taken_0x380) {
            ctx->pc = 0x344u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_344;
        }
    }
    ctx->pc = 0x388u;
    // 0x388: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_38c:
    // 0x38c: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x390: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x394: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x398: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x39c: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x3a0: 0x3e00008  jr          $ra
    ctx->pc = 0x3A0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3a4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3A0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3A8u;
}


// Function: modmidi_000003a8
// Address: 0x3a8 - 0x400
void modmidi_000003a8_0x3a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000003a8_0x3a8");
#endif

    ctx->pc = 0x3a8u;

    // 0x3a8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x3ac: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x3b0: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
    // 0x3b4: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
    // 0x3b8: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x3bc: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x3c0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x3c4: 0x10800034  beqz        $a0, . + 4 + (0x34 << 2)
    ctx->pc = 0x3C4u;
    {
        const bool branch_taken_0x3c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x3c8: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x3c4) {
            ctx->pc = 0x498u;
            return;
        }
    }
    ctx->pc = 0x3CCu;
    // 0x3cc: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x3d0: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x3d4: 0x8cc30000  lw          $v1, 0x0($a2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x3d8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x3dc: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x3e0: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x3E0u;
    {
        const bool branch_taken_0x3e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3e4: 0x51100  sll         $v0, $a1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
        if (branch_taken_0x3e0) {
            ctx->pc = 0x498u;
            return;
        }
    }
    ctx->pc = 0x3E8u;
    // 0x3e8: 0x8cc30004  lw          $v1, 0x4($a2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x3ec: 0x0  nop
    // NOP
    // 0x3f0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x3f4: 0x8c52000c  lw          $s2, 0xC($v0)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x3f8: 0x0  nop
    // NOP
    // 0x3fc: 0x12400026  beqz        $s2, . + 4 + (0x26 << 2)
    ctx->pc = 0x3FCu;
    {
        const bool branch_taken_0x3fc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x3fc) {
            ctx->pc = 0x498u;
            return;
        }
    }
    ctx->pc = 0x404u;
}


// Function: modmidi_00000400
// Address: 0x400 - 0x56c
void modmidi_00000400_0x400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000400_0x400");
#endif

    switch (ctx->pc) {
        case 0x434u: goto label_434;
        case 0x490u: goto label_490;
        case 0x498u: goto label_498;
        case 0x4c4u: goto label_4c4;
        case 0x4f4u: goto label_4f4;
        case 0x52cu: goto label_52c;
        default: break;
    }

    ctx->pc = 0x400u;

    // 0x400: 0x24070080  addiu       $a3, $zero, 0x80
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x404: 0x2406000f  addiu       $a2, $zero, 0xF
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x408: 0x2643006b  addiu       $v1, $s2, 0x6B
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 107));
    // 0x40c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x410: 0x2653005c  addiu       $s3, $s2, 0x5C
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 92));
    // 0x414: 0xae420000  sw          $v0, 0x0($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x418: 0xae420004  sw          $v0, 0x4($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x41c: 0xae400008  sw          $zero, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 0));
    // 0x420: 0xae40000c  sw          $zero, 0xC($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 0));
    // 0x424: 0xae40005c  sw          $zero, 0x5C($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 92), GPR_U32(ctx, 0));
    // 0x428: 0xae600004  sw          $zero, 0x4($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 0));
    // 0x42c: 0xae600008  sw          $zero, 0x8($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 0));
    // 0x430: 0xa660003a  sh          $zero, 0x3A($s3)
    WRITE16(ADD32(GPR_U32(ctx, 19), 58), (uint16_t)GPR_U32(ctx, 0));
label_434:
    // 0x434: 0xa067004c  sb          $a3, 0x4C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 76), (uint8_t)GPR_U32(ctx, 7));
    // 0x438: 0x24c6ffff  addiu       $a2, $a2, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x43c: 0x4c1fffd  bgez        $a2, . + 4 + (-0x3 << 2)
    ctx->pc = 0x43Cu;
    {
        const bool branch_taken_0x43c = (GPR_S32(ctx, 6) >= 0);
        // 0x440: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        if (branch_taken_0x43c) {
            ctx->pc = 0x434u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_434;
        }
    }
    ctx->pc = 0x444u;
    // 0x444: 0x24020080  addiu       $v0, $zero, 0x80
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x448: 0xa2620032  sb          $v0, 0x32($s3)
    WRITE8(ADD32(GPR_U32(ctx, 19), 50), (uint8_t)GPR_U32(ctx, 2));
    // 0x44c: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x450: 0x0  nop
    // NOP
    // 0x454: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x458: 0x51100  sll         $v0, $a1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x45c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x460: 0x8c500004  lw          $s0, 0x4($v0)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x464: 0x0  nop
    // NOP
    // 0x468: 0x12000037  beqz        $s0, . + 4 + (0x37 << 2)
    ctx->pc = 0x468u;
    {
        const bool branch_taken_0x468 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x46c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x468) {
            ctx->pc = 0x548u;
            goto label_548;
        }
    }
    ctx->pc = 0x470u;
    // 0x470: 0x3c150000  lui         $s5, 0x0
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)0 << 16));
    // 0x474: 0x26b5384c  addiu       $s5, $s5, 0x384C
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 14412));
    // 0x478: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x47c: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x480: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x484: 0x24e73854  addiu       $a3, $a3, 0x3854
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 14420));
    // 0x488: 0xc0000ab  jal         func_0002AC
    ctx->pc = 0x488u;
    SET_GPR_U32(ctx, 31, 0x490u);
    // 0x48c: 0x2a03021  addu        $a2, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x2ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2ACu, 0x488u, 0x490u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x490u;
label_490:
    // 0x490: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x490u;
    {
        const bool branch_taken_0x490 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x490) {
            ctx->pc = 0x4A0u;
            goto label_4a0;
        }
    }
    ctx->pc = 0x498u;
label_498:
    // 0x498: 0x8000152  j           func_000548
    ctx->pc = 0x498u;
    // 0x49c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x548u;
    goto label_548;
    ctx->pc = 0x4A0u;
label_4a0:
    // 0x4a0: 0x8e020008  lw          $v0, 0x8($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x4a4: 0x0  nop
    // NOP
    // 0x4a8: 0x202a021  addu        $s4, $s0, $v0
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x4ac: 0x8e840000  lw          $a0, 0x0($s4)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x4b0: 0x8e850004  lw          $a1, 0x4($s4)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x4b4: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x4b8: 0x24e7385c  addiu       $a3, $a3, 0x385C
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 14428));
    // 0x4bc: 0xc0000ab  jal         func_0002AC
    ctx->pc = 0x4BCu;
    SET_GPR_U32(ctx, 31, 0x4C4u);
    // 0x4c0: 0x2a03021  addu        $a2, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x2ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2ACu, 0x4BCu, 0x4C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4C4u;
label_4c4:
    // 0x4c4: 0x1040fff4  beqz        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x4C4u;
    {
        const bool branch_taken_0x4c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x4c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x4c4) {
            ctx->pc = 0x498u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_498;
        }
    }
    ctx->pc = 0x4CCu;
    // 0x4cc: 0x8e840010  lw          $a0, 0x10($s4)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 16)));
    // 0x4d0: 0x0  nop
    // NOP
    // 0x4d4: 0x10820009  beq         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x4D4u;
    {
        const bool branch_taken_0x4d4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x4d8: 0x2048821  addu        $s1, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        if (branch_taken_0x4d4) {
            ctx->pc = 0x4FCu;
            goto label_4fc;
        }
    }
    ctx->pc = 0x4DCu;
    // 0x4dc: 0x8e240000  lw          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x4e0: 0x8e250004  lw          $a1, 0x4($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x4e4: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x4e8: 0x24e73864  addiu       $a3, $a3, 0x3864
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 14436));
    // 0x4ec: 0xc0000ab  jal         func_0002AC
    ctx->pc = 0x4ECu;
    SET_GPR_U32(ctx, 31, 0x4F4u);
    // 0x4f0: 0x2a03021  addu        $a2, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x2ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2ACu, 0x4ECu, 0x4F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4F4u;
label_4f4:
    // 0x4f4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x4F4u;
    {
        const bool branch_taken_0x4f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4f4) {
            ctx->pc = 0x500u;
            goto label_500;
        }
    }
    ctx->pc = 0x4FCu;
label_4fc:
    // 0x4fc: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_500:
    // 0x500: 0x8e840014  lw          $a0, 0x14($s4)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
    // 0x504: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x508: 0x1082000f  beq         $a0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x508u;
    {
        const bool branch_taken_0x508 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x50c: 0x2048021  addu        $s0, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        if (branch_taken_0x508) {
            ctx->pc = 0x548u;
            goto label_548;
        }
    }
    ctx->pc = 0x510u;
    // 0x510: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x514: 0x24c6384c  addiu       $a2, $a2, 0x384C
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 14412));
    // 0x518: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x51c: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x520: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x524: 0xc0000ab  jal         func_0002AC
    ctx->pc = 0x524u;
    SET_GPR_U32(ctx, 31, 0x52Cu);
    // 0x528: 0x24e7386c  addiu       $a3, $a3, 0x386C (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 14444));
    ctx->pc = 0x2ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2ACu, 0x524u, 0x52Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x52Cu;
label_52c:
    // 0x52c: 0x1040ffda  beqz        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x52Cu;
    {
        const bool branch_taken_0x52c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x530: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x52c) {
            ctx->pc = 0x498u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_498;
        }
    }
    ctx->pc = 0x534u;
    // 0x534: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x538: 0xae740000  sw          $s4, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 20));
    // 0x53c: 0xae700004  sw          $s0, 0x4($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
    // 0x540: 0xae710008  sw          $s1, 0x8($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 17));
    // 0x544: 0xae43000c  sw          $v1, 0xC($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 3));
label_548:
    // 0x548: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x54c: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x550: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x554: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x558: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x55c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x560: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x564: 0x3e00008  jr          $ra
    ctx->pc = 0x564u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x568: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x564u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x56Cu;
}


// Function: modmidi_0000056c
// Address: 0x56c - 0x5b0
void modmidi_0000056c_0x56c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000056c_0x56c");
#endif

    ctx->pc = 0x56cu;

    // 0x56c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x570: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x574: 0x1080000f  beqz        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x574u;
    {
        const bool branch_taken_0x574 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x578: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x574) {
            ctx->pc = 0x5B4u;
            return;
        }
    }
    ctx->pc = 0x57Cu;
    // 0x57c: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x580: 0x51840  sll         $v1, $a1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x584: 0x8cc20000  lw          $v0, 0x0($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x588: 0x24650001  addiu       $a1, $v1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x58c: 0xa2102b  sltu        $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x590: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x590u;
    {
        const bool branch_taken_0x590 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x594: 0x510c0  sll         $v0, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x590) {
            ctx->pc = 0x5B4u;
            return;
        }
    }
    ctx->pc = 0x598u;
    // 0x598: 0x8cc30004  lw          $v1, 0x4($a2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x59c: 0x0  nop
    // NOP
    // 0x5a0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x5a4: 0x8c500004  lw          $s0, 0x4($v0)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x5a8: 0x0  nop
    // NOP
    // 0x5ac: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x5ACu;
    {
        const bool branch_taken_0x5ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x5ac) {
            ctx->pc = 0x5BCu;
            return;
        }
    }
    ctx->pc = 0x5B4u;
}


// Function: modmidi_000005b0
// Address: 0x5b0 - 0x6b0
void modmidi_000005b0_0x5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000005b0_0x5b0");
#endif

    switch (ctx->pc) {
        case 0x5b4u: goto label_5b4;
        case 0x5bcu: goto label_5bc;
        case 0x5d8u: goto label_5d8;
        case 0x648u: goto label_648;
        default: break;
    }

    ctx->pc = 0x5b0u;

    // 0x5b0: 0x0  nop
    // NOP
label_5b4:
    // 0x5b4: 0x80001a5  j           func_000694
    ctx->pc = 0x5B4u;
    // 0x5b8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x694u;
    goto label_694;
    ctx->pc = 0x5BCu;
label_5bc:
    // 0x5bc: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x5c0: 0x0  nop
    // NOP
    // 0x5c4: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x5c8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x5C8u;
    {
        const bool branch_taken_0x5c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x5cc: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x5c8) {
            ctx->pc = 0x5DCu;
            goto label_5dc;
        }
    }
    ctx->pc = 0x5D0u;
    // 0x5d0: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x5D0u;
    SET_GPR_U32(ctx, 31, 0x5D8u);
    // 0x5d4: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x5D0u, 0x5D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5D8u;
label_5d8:
    // 0x5d8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_5dc:
    // 0x5dc: 0x240500ff  addiu       $a1, $zero, 0xFF
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x5e0: 0x3407ffff  ori         $a3, $zero, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x5e4: 0x2604005c  addiu       $a0, $s0, 0x5C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 92));
    // 0x5e8: 0x801821  addu        $v1, $a0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x5ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x5f0: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x5f4: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x5f8: 0x24020080  addiu       $v0, $zero, 0x80
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x5fc: 0xae00000c  sw          $zero, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x600: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x604: 0xae00005c  sw          $zero, 0x5C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 0));
    // 0x608: 0xa0820032  sb          $v0, 0x32($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 50), (uint8_t)GPR_U32(ctx, 2));
    // 0x60c: 0xa01021  addu        $v0, $a1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x610: 0xac800004  sw          $zero, 0x4($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x614: 0xac800008  sw          $zero, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x618: 0xac80000c  sw          $zero, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x61c: 0xac800010  sw          $zero, 0x10($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x620: 0xac800018  sw          $zero, 0x18($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x624: 0xac80001c  sw          $zero, 0x1C($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x628: 0xac800020  sw          $zero, 0x20($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x62c: 0xa0800030  sb          $zero, 0x30($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 48), (uint8_t)GPR_U32(ctx, 0));
    // 0x630: 0xa0800031  sb          $zero, 0x31($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 49), (uint8_t)GPR_U32(ctx, 0));
    // 0x634: 0xa0820034  sb          $v0, 0x34($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 52), (uint8_t)GPR_U32(ctx, 2));
    // 0x638: 0xa0820033  sb          $v0, 0x33($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 51), (uint8_t)GPR_U32(ctx, 2));
    // 0x63c: 0xa0820036  sb          $v0, 0x36($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 54), (uint8_t)GPR_U32(ctx, 2));
    // 0x640: 0xa0820035  sb          $v0, 0x35($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 53), (uint8_t)GPR_U32(ctx, 2));
    // 0x644: 0xa480003a  sh          $zero, 0x3A($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 58), (uint16_t)GPR_U32(ctx, 0));
label_648:
    // 0x648: 0x861021  addu        $v0, $a0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x64c: 0xa040003c  sb          $zero, 0x3C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 60), (uint8_t)GPR_U32(ctx, 0));
    // 0x650: 0xa040004c  sb          $zero, 0x4C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 76), (uint8_t)GPR_U32(ctx, 0));
    // 0x654: 0xa065005c  sb          $a1, 0x5C($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 92), (uint8_t)GPR_U32(ctx, 5));
    // 0x658: 0xa065005d  sb          $a1, 0x5D($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 93), (uint8_t)GPR_U32(ctx, 5));
    // 0x65c: 0xa065005e  sb          $a1, 0x5E($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 94), (uint8_t)GPR_U32(ctx, 5));
    // 0x660: 0xa065005f  sb          $a1, 0x5F($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 95), (uint8_t)GPR_U32(ctx, 5));
    // 0x664: 0xa0650060  sb          $a1, 0x60($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 96), (uint8_t)GPR_U32(ctx, 5));
    // 0x668: 0xa0650061  sb          $a1, 0x61($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 97), (uint8_t)GPR_U32(ctx, 5));
    // 0x66c: 0xa0650062  sb          $a1, 0x62($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 98), (uint8_t)GPR_U32(ctx, 5));
    // 0x670: 0xa0650063  sb          $a1, 0x63($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 99), (uint8_t)GPR_U32(ctx, 5));
    // 0x674: 0xa0650064  sb          $a1, 0x64($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 100), (uint8_t)GPR_U32(ctx, 5));
    // 0x678: 0xa0650065  sb          $a1, 0x65($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 101), (uint8_t)GPR_U32(ctx, 5));
    // 0x67c: 0xa4670066  sh          $a3, 0x66($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 102), (uint16_t)GPR_U32(ctx, 7));
    // 0x680: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x684: 0x28c20010  slti        $v0, $a2, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x688: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x688u;
    {
        const bool branch_taken_0x688 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x68c: 0x2463000c  addiu       $v1, $v1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 12));
        if (branch_taken_0x688) {
            ctx->pc = 0x648u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_648;
        }
    }
    ctx->pc = 0x690u;
    // 0x690: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_694:
    // 0x694: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x698: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x69c: 0x3e00008  jr          $ra
    ctx->pc = 0x69Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6a0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x69Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6A4u;
    // 0x6a4: 0x0  nop
    // NOP
    // 0x6a8: 0x0  nop
    // NOP
    // 0x6ac: 0x0  nop
    // NOP
}


// Function: modmidi_000006b0
// Address: 0x6b0 - 0x790
void modmidi_000006b0_0x6b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000006b0_0x6b0");
#endif

    switch (ctx->pc) {
        case 0x6ecu: goto label_6ec;
        case 0x724u: goto label_724;
        case 0x74cu: goto label_74c;
        default: break;
    }

    ctx->pc = 0x6b0u;

    // 0x6b0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x6b4: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x6b8: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x6bc: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x6c0: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
    // 0x6c4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x6c8: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x6cc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x6d0: 0x8e720004  lw          $s2, 0x4($s3)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x6d4: 0x24110001  addiu       $s1, $zero, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6d8: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x6dc: 0x0  nop
    // NOP
    // 0x6e0: 0x222102a  slt         $v0, $s1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x6e4: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x6E4u;
    {
        const bool branch_taken_0x6e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x6e8: 0x26540008  addiu       $s4, $s2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
        if (branch_taken_0x6e4) {
            ctx->pc = 0x760u;
            goto label_760;
        }
    }
    ctx->pc = 0x6ECu;
label_6ec:
    // 0x6ec: 0x8e430004  lw          $v1, 0x4($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x6f0: 0x1110c0  sll         $v0, $s1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x6f4: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x6f8: 0x8c500004  lw          $s0, 0x4($v0)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x6fc: 0x0  nop
    // NOP
    // 0x700: 0x12000012  beqz        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x700u;
    {
        const bool branch_taken_0x700 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x700) {
            ctx->pc = 0x74Cu;
            goto label_74c;
        }
    }
    ctx->pc = 0x708u;
    // 0x708: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x70c: 0x0  nop
    // NOP
    // 0x710: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x714: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x714u;
    {
        const bool branch_taken_0x714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x718: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x714) {
            ctx->pc = 0x724u;
            goto label_724;
        }
    }
    ctx->pc = 0x71Cu;
    // 0x71c: 0xc000618  jal         func_001860
    ctx->pc = 0x71Cu;
    SET_GPR_U32(ctx, 31, 0x724u);
    // 0x720: 0x2802821  addu        $a1, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x1860u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1860u, 0x71Cu, 0x724u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x724u;
label_724:
    // 0x724: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x728: 0x0  nop
    // NOP
    // 0x72c: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x730: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x730u;
    {
        const bool branch_taken_0x730 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x734: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x730) {
            ctx->pc = 0x74Cu;
            goto label_74c;
        }
    }
    ctx->pc = 0x738u;
    // 0x738: 0x112fc2  srl         $a1, $s1, 31
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 17), 31));
    // 0x73c: 0x2252821  addu        $a1, $s1, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x740: 0x52843  sra         $a1, $a1, 1
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 1));
    // 0x744: 0xc000c3c  jal         func_0030F0
    ctx->pc = 0x744u;
    SET_GPR_U32(ctx, 31, 0x74Cu);
    // 0x748: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x30F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x30F0u, 0x744u, 0x74Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x74Cu;
label_74c:
    // 0x74c: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x750: 0x26310002  addiu       $s1, $s1, 0x2
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x754: 0x222102a  slt         $v0, $s1, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x758: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x758u;
    {
        const bool branch_taken_0x758 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x758) {
            ctx->pc = 0x6ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_6ec;
        }
    }
    ctx->pc = 0x760u;
label_760:
    // 0x760: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x764: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x768: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x76c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x770: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x774: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x778: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x77c: 0x3e00008  jr          $ra
    ctx->pc = 0x77Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x780: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x77Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x784u;
    // 0x784: 0x0  nop
    // NOP
    // 0x788: 0x0  nop
    // NOP
    // 0x78c: 0x0  nop
    // NOP
}


// Function: modmidi_00000790
// Address: 0x790 - 0x7b0
void modmidi_00000790_0x790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000790_0x790");
#endif

    switch (ctx->pc) {
        case 0x79cu: goto label_79c;
        default: break;
    }

    ctx->pc = 0x790u;

    // 0x790: 0x24030007  addiu       $v1, $zero, 0x7
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x794: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x798: 0x2406ffff  addiu       $a2, $zero, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_79c:
    // 0x79c: 0x90820000  lbu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x7a0: 0x0  nop
    // NOP
    // 0x7a4: 0x14450003  bne         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x7A4u;
    {
        const bool branch_taken_0x7a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        // 0x7a8: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        if (branch_taken_0x7a4) {
            ctx->pc = 0x7B4u;
            return;
        }
    }
    ctx->pc = 0x7ACu;
    // 0x7ac: 0x3e00008  jr          $ra
    ctx->pc = 0x7ACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
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


// Function: modmidi_000007b0
// Address: 0x7b0 - 0x7c4
void modmidi_000007b0_0x7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000007b0_0x7b0");
#endif

    switch (ctx->pc) {
        case 0x7b4u: goto label_7b4;
        default: break;
    }

    ctx->pc = 0x7b0u;

    // 0x7b0: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_7b4:
    // 0x7b4: 0x1466fff9  bne         $v1, $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x7B4u;
    {
        const bool branch_taken_0x7b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        // 0x7b8: 0x2484000c  addiu       $a0, $a0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
        if (branch_taken_0x7b4) {
            ctx->pc = 0x79Cu;
            return;
        }
    }
    ctx->pc = 0x7BCu;
    // 0x7bc: 0x3e00008  jr          $ra
    ctx->pc = 0x7BCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7c0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7BCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7C4u;
}


// Function: modmidi_000007c4
// Address: 0x7c4 - 0xab0
void modmidi_000007c4_0x7c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000007c4_0x7c4");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0x7c4u;

label_7c4:
    // 0x7c4: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_7c8:
    // 0x7c8: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_7cc:
    // 0x7cc: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_7d0:
    // 0x7d0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_7d4:
    // 0x7d4: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_7d8:
    // 0x7d8: 0x30e700ff  andi        $a3, $a3, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
label_7dc:
    // 0x7dc: 0x8fa30038  lw          $v1, 0x38($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_7e0:
    // 0x7e0: 0x8fa4003c  lw          $a0, 0x3C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_7e4:
    // 0x7e4: 0x24020026  addiu       $v0, $zero, 0x26
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 38));
label_7e8:
    // 0x7e8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_7ec:
    // 0x7ec: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_7f0:
    // 0x7f0: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_7f4:
    // 0x7f4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_7f8:
    // 0x7f8: 0x10e20016  beq         $a3, $v0, . + 4 + (0x16 << 2)
label_7fc:
    if (ctx->pc == 0x7FCu) {
        // 0x7fc: 0x602821  addu        $a1, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        ctx->pc = 0x800u;
        goto label_800;
    }
    ctx->pc = 0x7F8u;
    {
        const bool branch_taken_0x7f8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        // 0x7fc: 0x602821  addu        $a1, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x7f8) {
            ctx->pc = 0x854u;
            goto label_854;
        }
    }
    ctx->pc = 0x800u;
label_800:
    // 0x800: 0x28e20027  slti        $v0, $a3, 0x27
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)39) ? 1 : 0);
label_804:
    // 0x804: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_808:
    if (ctx->pc == 0x808u) {
        // 0x808: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->pc = 0x80Cu;
        goto label_80c;
    }
    ctx->pc = 0x804u;
    {
        const bool branch_taken_0x804 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x808: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x804) {
            ctx->pc = 0x81Cu;
            goto label_81c;
        }
    }
    ctx->pc = 0x80Cu;
label_80c:
    // 0x80c: 0x10e2000f  beq         $a3, $v0, . + 4 + (0xF << 2)
label_810:
    if (ctx->pc == 0x810u) {
        ctx->pc = 0x814u;
        goto label_814;
    }
    ctx->pc = 0x80Cu;
    {
        const bool branch_taken_0x80c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        if (branch_taken_0x80c) {
            ctx->pc = 0x84Cu;
            goto label_84c;
        }
    }
    ctx->pc = 0x814u;
label_814:
    // 0x814: 0x8000300  j           func_000C00
label_818:
    if (ctx->pc == 0x818u) {
        ctx->pc = 0x81Cu;
        goto label_81c;
    }
    ctx->pc = 0x814u;
    ctx->pc = 0xC00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC00u, 0x814u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x81Cu;
label_81c:
    // 0x81c: 0x24020062  addiu       $v0, $zero, 0x62
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
label_820:
    // 0x820: 0x10e20005  beq         $a3, $v0, . + 4 + (0x5 << 2)
label_824:
    if (ctx->pc == 0x824u) {
        // 0x824: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->pc = 0x828u;
        goto label_828;
    }
    ctx->pc = 0x820u;
    {
        const bool branch_taken_0x820 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        // 0x824: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        if (branch_taken_0x820) {
            ctx->pc = 0x838u;
            goto label_838;
        }
    }
    ctx->pc = 0x828u;
label_828:
    // 0x828: 0x14e200f5  bne         $a3, $v0, . + 4 + (0xF5 << 2)
label_82c:
    if (ctx->pc == 0x82Cu) {
        // 0x82c: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->pc = 0x830u;
        goto label_830;
    }
    ctx->pc = 0x828u;
    {
        const bool branch_taken_0x828 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        // 0x82c: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x828) {
            ctx->pc = 0xC00u;
            return;
        }
    }
    ctx->pc = 0x830u;
label_830:
    // 0x830: 0x8000210  j           func_000840
label_834:
    if (ctx->pc == 0x834u) {
        // 0x834: 0xa2230033  sb          $v1, 0x33($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 51), (uint8_t)GPR_U32(ctx, 3));
        ctx->pc = 0x838u;
        goto label_838;
    }
    ctx->pc = 0x830u;
    // 0x834: 0xa2230033  sb          $v1, 0x33($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 51), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x840u;
    goto label_840;
    ctx->pc = 0x838u;
label_838:
    // 0x838: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_83c:
    // 0x83c: 0xa2230035  sb          $v1, 0x35($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 53), (uint8_t)GPR_U32(ctx, 3));
label_840:
    // 0x840: 0xa2220036  sb          $v0, 0x36($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 54), (uint8_t)GPR_U32(ctx, 2));
label_844:
    // 0x844: 0x8000216  j           func_000858
label_848:
    if (ctx->pc == 0x848u) {
        // 0x848: 0xa2220034  sb          $v0, 0x34($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 52), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0x84Cu;
        goto label_84c;
    }
    ctx->pc = 0x844u;
    // 0x848: 0xa2220034  sb          $v0, 0x34($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 52), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x858u;
    goto label_858;
    ctx->pc = 0x84Cu;
label_84c:
    // 0x84c: 0x8000216  j           func_000858
label_850:
    if (ctx->pc == 0x850u) {
        // 0x850: 0xa2230034  sb          $v1, 0x34($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 52), (uint8_t)GPR_U32(ctx, 3));
        ctx->pc = 0x854u;
        goto label_854;
    }
    ctx->pc = 0x84Cu;
    // 0x850: 0xa2230034  sb          $v1, 0x34($s1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 17), 52), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x858u;
    goto label_858;
    ctx->pc = 0x854u;
label_854:
    // 0x854: 0xa2230036  sb          $v1, 0x36($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 54), (uint8_t)GPR_U32(ctx, 3));
label_858:
    // 0x858: 0x92230033  lbu         $v1, 0x33($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 51)));
label_85c:
    // 0x85c: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_860:
    // 0x860: 0x106200ad  beq         $v1, $v0, . + 4 + (0xAD << 2)
label_864:
    if (ctx->pc == 0x864u) {
        // 0x864: 0x9821  addu        $s3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x868u;
        goto label_868;
    }
    ctx->pc = 0x860u;
    {
        const bool branch_taken_0x860 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x864: 0x9821  addu        $s3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x860) {
            ctx->pc = 0xB18u;
            return;
        }
    }
    ctx->pc = 0x868u;
label_868:
    // 0x868: 0x28620011  slti        $v0, $v1, 0x11
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)17) ? 1 : 0);
label_86c:
    // 0x86c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
label_870:
    if (ctx->pc == 0x870u) {
        // 0x870: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->pc = 0x874u;
        goto label_874;
    }
    ctx->pc = 0x86Cu;
    {
        const bool branch_taken_0x86c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x870: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        if (branch_taken_0x86c) {
            ctx->pc = 0x88Cu;
            goto label_88c;
        }
    }
    ctx->pc = 0x874u;
label_874:
    // 0x874: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
label_878:
    if (ctx->pc == 0x878u) {
        // 0x878: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x87Cu;
        goto label_87c;
    }
    ctx->pc = 0x874u;
    {
        const bool branch_taken_0x874 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x878: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x874) {
            ctx->pc = 0x8ACu;
            goto label_8ac;
        }
    }
    ctx->pc = 0x87Cu;
label_87c:
    // 0x87c: 0x10620049  beq         $v1, $v0, . + 4 + (0x49 << 2)
label_880:
    if (ctx->pc == 0x880u) {
        // 0x880: 0x241400ff  addiu       $s4, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->pc = 0x884u;
        goto label_884;
    }
    ctx->pc = 0x87Cu;
    {
        const bool branch_taken_0x87c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x880: 0x241400ff  addiu       $s4, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x87c) {
            ctx->pc = 0x9A4u;
            goto label_9a4;
        }
    }
    ctx->pc = 0x884u;
label_884:
    // 0x884: 0x80002fa  j           func_000BE8
label_888:
    if (ctx->pc == 0x888u) {
        ctx->pc = 0x88Cu;
        goto label_88c;
    }
    ctx->pc = 0x884u;
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0x884u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x88Cu;
label_88c:
    // 0x88c: 0x106200ba  beq         $v1, $v0, . + 4 + (0xBA << 2)
label_890:
    if (ctx->pc == 0x890u) {
        // 0x890: 0x62102a  slt         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
        ctx->pc = 0x894u;
        goto label_894;
    }
    ctx->pc = 0x88Cu;
    {
        const bool branch_taken_0x88c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x890: 0x62102a  slt         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
        if (branch_taken_0x88c) {
            ctx->pc = 0xB78u;
            return;
        }
    }
    ctx->pc = 0x894u;
label_894:
    // 0x894: 0x144000a8  bnez        $v0, . + 4 + (0xA8 << 2)
label_898:
    if (ctx->pc == 0x898u) {
        // 0x898: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->pc = 0x89Cu;
        goto label_89c;
    }
    ctx->pc = 0x894u;
    {
        const bool branch_taken_0x894 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x898: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        if (branch_taken_0x894) {
            ctx->pc = 0xB38u;
            return;
        }
    }
    ctx->pc = 0x89Cu;
label_89c:
    // 0x89c: 0x106200cd  beq         $v1, $v0, . + 4 + (0xCD << 2)
label_8a0:
    if (ctx->pc == 0x8A0u) {
        ctx->pc = 0x8A4u;
        goto label_8a4;
    }
    ctx->pc = 0x89Cu;
    {
        const bool branch_taken_0x89c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x89c) {
            ctx->pc = 0xBD4u;
            return;
        }
    }
    ctx->pc = 0x8A4u;
label_8a4:
    // 0x8a4: 0x80002fa  j           func_000BE8
label_8a8:
    if (ctx->pc == 0x8A8u) {
        ctx->pc = 0x8ACu;
        goto label_8ac;
    }
    ctx->pc = 0x8A4u;
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0x8A4u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x8ACu;
label_8ac:
    // 0x8ac: 0x92220034  lbu         $v0, 0x34($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_8b0:
    // 0x8b0: 0x241400ff  addiu       $s4, $zero, 0xFF
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_8b4:
    // 0x8b4: 0x105400cc  beq         $v0, $s4, . + 4 + (0xCC << 2)
label_8b8:
    if (ctx->pc == 0x8B8u) {
        // 0x8b8: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x8BCu;
        goto label_8bc;
    }
    ctx->pc = 0x8B4u;
    {
        const bool branch_taken_0x8b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        // 0x8b8: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x8b4) {
            ctx->pc = 0xBE8u;
            return;
        }
    }
    ctx->pc = 0x8BCu;
label_8bc:
    // 0x8bc: 0x26320178  addiu       $s2, $s1, 0x178
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 376));
label_8c0:
    // 0x8c0: 0xc0001e4  jal         func_000790
label_8c4:
    if (ctx->pc == 0x8C4u) {
        // 0x8c4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x8C8u;
        goto label_8c8;
    }
    ctx->pc = 0x8C0u;
    SET_GPR_U32(ctx, 31, 0x8C8u);
    // 0x8c4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x790u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x790u, 0x8C0u, 0x8C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8C8u;
label_8c8:
    // 0x8c8: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_8cc:
    // 0x8cc: 0x1600000c  bnez        $s0, . + 4 + (0xC << 2)
label_8d0:
    if (ctx->pc == 0x8D0u) {
        // 0x8d0: 0x24030007  addiu       $v1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->pc = 0x8D4u;
        goto label_8d4;
    }
    ctx->pc = 0x8CCu;
    {
        const bool branch_taken_0x8cc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x8d0: 0x24030007  addiu       $v1, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        if (branch_taken_0x8cc) {
            ctx->pc = 0x900u;
            goto label_900;
        }
    }
    ctx->pc = 0x8D4u;
label_8d4:
    // 0x8d4: 0x2408021  addu        $s0, $s2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_8d8:
    // 0x8d8: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_8dc:
    // 0x8dc: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_8e0:
    // 0x8e0: 0x92020000  lbu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_8e4:
    // 0x8e4: 0x0  nop
    // NOP
label_8e8:
    // 0x8e8: 0x10450012  beq         $v0, $a1, . + 4 + (0x12 << 2)
label_8ec:
    if (ctx->pc == 0x8ECu) {
        // 0x8ec: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->pc = 0x8F0u;
        goto label_8f0;
    }
    ctx->pc = 0x8E8u;
    {
        const bool branch_taken_0x8e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        // 0x8ec: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        if (branch_taken_0x8e8) {
            ctx->pc = 0x934u;
            goto label_934;
        }
    }
    ctx->pc = 0x8F0u;
label_8f0:
    // 0x8f0: 0x1464fffb  bne         $v1, $a0, . + 4 + (-0x5 << 2)
label_8f4:
    if (ctx->pc == 0x8F4u) {
        // 0x8f4: 0x2610000c  addiu       $s0, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->pc = 0x8F8u;
        goto label_8f8;
    }
    ctx->pc = 0x8F0u;
    {
        const bool branch_taken_0x8f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        // 0x8f4: 0x2610000c  addiu       $s0, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        if (branch_taken_0x8f0) {
            ctx->pc = 0x8E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_8e0;
        }
    }
    ctx->pc = 0x8F8u;
label_8f8:
    // 0x8f8: 0x800024d  j           func_000934
label_8fc:
    if (ctx->pc == 0x8FCu) {
        ctx->pc = 0x900u;
        goto label_900;
    }
    ctx->pc = 0x8F8u;
    ctx->pc = 0x934u;
    goto label_934;
    ctx->pc = 0x900u;
label_900:
    // 0x900: 0x92020001  lbu         $v0, 0x1($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_904:
    // 0x904: 0x0  nop
    // NOP
label_908:
    // 0x908: 0x1054000a  beq         $v0, $s4, . + 4 + (0xA << 2)
label_90c:
    if (ctx->pc == 0x90Cu) {
        ctx->pc = 0x910u;
        goto label_910;
    }
    ctx->pc = 0x908u;
    {
        const bool branch_taken_0x908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        if (branch_taken_0x908) {
            ctx->pc = 0x934u;
            goto label_934;
        }
    }
    ctx->pc = 0x910u;
label_910:
    // 0x910: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_914:
    // 0x914: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_918:
    // 0x918: 0x0  nop
    // NOP
label_91c:
    // 0x91c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_920:
    if (ctx->pc == 0x920u) {
        ctx->pc = 0x924u;
        goto label_924;
    }
    ctx->pc = 0x91Cu;
    {
        const bool branch_taken_0x91c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x91c) {
            ctx->pc = 0x934u;
            goto label_934;
        }
    }
    ctx->pc = 0x924u;
label_924:
    // 0x924: 0x92250034  lbu         $a1, 0x34($s1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_928:
    // 0x928: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_92c:
    // 0x92c: 0xc000de5  jal         func_003794
label_930:
    if (ctx->pc == 0x930u) {
        // 0x930: 0x24843880  addiu       $a0, $a0, 0x3880 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14464));
        ctx->pc = 0x934u;
        goto label_934;
    }
    ctx->pc = 0x92Cu;
    SET_GPR_U32(ctx, 31, 0x934u);
    // 0x930: 0x24843880  addiu       $a0, $a0, 0x3880 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14464));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x92Cu, 0x934u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x934u;
label_934:
    // 0x934: 0x12000010  beqz        $s0, . + 4 + (0x10 << 2)
label_938:
    if (ctx->pc == 0x938u) {
        // 0x938: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->pc = 0x93Cu;
        goto label_93c;
    }
    ctx->pc = 0x934u;
    {
        const bool branch_taken_0x934 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x938: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x934) {
            ctx->pc = 0x978u;
            goto label_978;
        }
    }
    ctx->pc = 0x93Cu;
label_93c:
    // 0x93c: 0x92230034  lbu         $v1, 0x34($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_940:
    // 0x940: 0xa2020001  sb          $v0, 0x1($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_944:
    // 0x944: 0xa2030000  sb          $v1, 0x0($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
label_948:
    // 0x948: 0x92220030  lbu         $v0, 0x30($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 48)));
label_94c:
    // 0x94c: 0x0  nop
    // NOP
label_950:
    // 0x950: 0xa2020002  sb          $v0, 0x2($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
label_954:
    // 0x954: 0x92220031  lbu         $v0, 0x31($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 49)));
label_958:
    // 0x958: 0x0  nop
    // NOP
label_95c:
    // 0x95c: 0xa2020003  sb          $v0, 0x3($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
label_960:
    // 0x960: 0x8e220018  lw          $v0, 0x18($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
label_964:
    // 0x964: 0x0  nop
    // NOP
label_968:
    // 0x968: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_96c:
    // 0x96c: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_970:
    // 0x970: 0x80002f3  j           func_000BCC
label_974:
    if (ctx->pc == 0x974u) {
        // 0x974: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->pc = 0x978u;
        goto label_978;
    }
    ctx->pc = 0x970u;
    // 0x974: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    ctx->pc = 0xBCCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBCCu, 0x970u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x978u;
label_978:
    // 0x978: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_97c:
    // 0x97c: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_980:
    // 0x980: 0x0  nop
    // NOP
label_984:
    // 0x984: 0x10400091  beqz        $v0, . + 4 + (0x91 << 2)
label_988:
    if (ctx->pc == 0x988u) {
        ctx->pc = 0x98Cu;
        goto label_98c;
    }
    ctx->pc = 0x984u;
    {
        const bool branch_taken_0x984 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x984) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0x98Cu;
label_98c:
    // 0x98c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_990:
    // 0x990: 0x24843898  addiu       $a0, $a0, 0x3898
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14488));
label_994:
    // 0x994: 0xc000de5  jal         func_003794
label_998:
    if (ctx->pc == 0x998u) {
        // 0x998: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0x99Cu;
        goto label_99c;
    }
    ctx->pc = 0x994u;
    SET_GPR_U32(ctx, 31, 0x99Cu);
    // 0x998: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x994u, 0x99Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x99Cu;
label_99c:
    // 0x99c: 0x80002fa  j           func_000BE8
label_9a0:
    if (ctx->pc == 0x9A0u) {
        ctx->pc = 0x9A4u;
        goto label_9a4;
    }
    ctx->pc = 0x99Cu;
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0x99Cu, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0x9A4u;
label_9a4:
    // 0x9a4: 0x92220034  lbu         $v0, 0x34($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_9a8:
    // 0x9a8: 0x0  nop
    // NOP
label_9ac:
    // 0x9ac: 0x1054008e  beq         $v0, $s4, . + 4 + (0x8E << 2)
label_9b0:
    if (ctx->pc == 0x9B0u) {
        ctx->pc = 0x9B4u;
        goto label_9b4;
    }
    ctx->pc = 0x9ACu;
    {
        const bool branch_taken_0x9ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        if (branch_taken_0x9ac) {
            ctx->pc = 0xBE8u;
            return;
        }
    }
    ctx->pc = 0x9B4u;
label_9b4:
    // 0x9b4: 0x92220036  lbu         $v0, 0x36($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 54)));
label_9b8:
    // 0x9b8: 0x0  nop
    // NOP
label_9bc:
    // 0x9bc: 0x1054008a  beq         $v0, $s4, . + 4 + (0x8A << 2)
label_9c0:
    if (ctx->pc == 0x9C0u) {
        ctx->pc = 0x9C4u;
        goto label_9c4;
    }
    ctx->pc = 0x9BCu;
    {
        const bool branch_taken_0x9bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        if (branch_taken_0x9bc) {
            ctx->pc = 0xBE8u;
            return;
        }
    }
    ctx->pc = 0x9C4u;
label_9c4:
    // 0x9c4: 0x8e42000c  lw          $v0, 0xC($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
label_9c8:
    // 0x9c8: 0x0  nop
    // NOP
label_9cc:
    // 0x9cc: 0x30420008  andi        $v0, $v0, 0x8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
label_9d0:
    // 0x9d0: 0x1440007e  bnez        $v0, . + 4 + (0x7E << 2)
label_9d4:
    if (ctx->pc == 0x9D4u) {
        ctx->pc = 0x9D8u;
        goto label_9d8;
    }
    ctx->pc = 0x9D0u;
    {
        const bool branch_taken_0x9d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x9d0) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0x9D8u;
label_9d8:
    // 0x9d8: 0x1080007c  beqz        $a0, . + 4 + (0x7C << 2)
label_9dc:
    if (ctx->pc == 0x9DCu) {
        ctx->pc = 0x9E0u;
        goto label_9e0;
    }
    ctx->pc = 0x9D8u;
    {
        const bool branch_taken_0x9d8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x9d8) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0x9E0u;
label_9e0:
    // 0x9e0: 0x92250034  lbu         $a1, 0x34($s1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_9e4:
    // 0x9e4: 0xc0001e4  jal         func_000790
label_9e8:
    if (ctx->pc == 0x9E8u) {
        // 0x9e8: 0x26240178  addiu       $a0, $s1, 0x178 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 376));
        ctx->pc = 0x9ECu;
        goto label_9ec;
    }
    ctx->pc = 0x9E4u;
    SET_GPR_U32(ctx, 31, 0x9ECu);
    // 0x9e8: 0x26240178  addiu       $a0, $s1, 0x178 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 376));
    ctx->pc = 0x790u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x790u, 0x9E4u, 0x9ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9ECu;
label_9ec:
    // 0x9ec: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_9f0:
    // 0x9f0: 0x1200003d  beqz        $s0, . + 4 + (0x3D << 2)
label_9f4:
    if (ctx->pc == 0x9F4u) {
        ctx->pc = 0x9F8u;
        goto label_9f8;
    }
    ctx->pc = 0x9F0u;
    {
        const bool branch_taken_0x9f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x9f0) {
            ctx->pc = 0xAE8u;
            return;
        }
    }
    ctx->pc = 0x9F8u;
label_9f8:
    // 0x9f8: 0x92020001  lbu         $v0, 0x1($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_9fc:
    // 0x9fc: 0x0  nop
    // NOP
label_a00:
    // 0xa00: 0x14540004  bne         $v0, $s4, . + 4 + (0x4 << 2)
label_a04:
    if (ctx->pc == 0xA04u) {
        ctx->pc = 0xA08u;
        goto label_a08;
    }
    ctx->pc = 0xA00u;
    {
        const bool branch_taken_0xa00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        if (branch_taken_0xa00) {
            ctx->pc = 0xA14u;
            goto label_a14;
        }
    }
    ctx->pc = 0xA08u;
label_a08:
    // 0xa08: 0x92220036  lbu         $v0, 0x36($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 54)));
label_a0c:
    // 0xa0c: 0x0  nop
    // NOP
label_a10:
    // 0xa10: 0xa2020001  sb          $v0, 0x1($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_a14:
    // 0xa14: 0x92230036  lbu         $v1, 0x36($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 54)));
label_a18:
    // 0xa18: 0x0  nop
    // NOP
label_a1c:
    // 0xa1c: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
label_a20:
    if (ctx->pc == 0xA20u) {
        ctx->pc = 0xA24u;
        goto label_a24;
    }
    ctx->pc = 0xA1Cu;
    {
        const bool branch_taken_0xa1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0xa1c) {
            ctx->pc = 0xA34u;
            goto label_a34;
        }
    }
    ctx->pc = 0xA24u;
label_a24:
    // 0xa24: 0x92020001  lbu         $v0, 0x1($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_a28:
    // 0xa28: 0x0  nop
    // NOP
label_a2c:
    // 0xa2c: 0x1040002c  beqz        $v0, . + 4 + (0x2C << 2)
label_a30:
    if (ctx->pc == 0xA30u) {
        ctx->pc = 0xA34u;
        goto label_a34;
    }
    ctx->pc = 0xA2Cu;
    {
        const bool branch_taken_0xa2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xa2c) {
            ctx->pc = 0xAE0u;
            return;
        }
    }
    ctx->pc = 0xA34u;
label_a34:
    // 0xa34: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_a38:
    // 0xa38: 0x0  nop
    // NOP
label_a3c:
    // 0xa3c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
label_a40:
    if (ctx->pc == 0xA40u) {
        ctx->pc = 0xA44u;
        goto label_a44;
    }
    ctx->pc = 0xA3Cu;
    {
        const bool branch_taken_0xa3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xa3c) {
            ctx->pc = 0xA98u;
            goto label_a98;
        }
    }
    ctx->pc = 0xA44u;
label_a44:
    // 0xa44: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_a48:
    // 0xa48: 0x24843eb1  addiu       $a0, $a0, 0x3EB1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16049));
label_a4c:
    // 0xa4c: 0xa0830000  sb          $v1, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
label_a50:
    // 0xa50: 0x92220036  lbu         $v0, 0x36($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 54)));
label_a54:
    // 0xa54: 0x92030001  lbu         $v1, 0x1($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_a58:
    // 0xa58: 0x0  nop
    // NOP
label_a5c:
    // 0xa5c: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_a60:
    // 0xa60: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_a64:
    // 0xa64: 0xa0820001  sb          $v0, 0x1($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 2));
label_a68:
    // 0xa68: 0x92020000  lbu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_a6c:
    // 0xa6c: 0x0  nop
    // NOP
label_a70:
    // 0xa70: 0xac820003  sw          $v0, 0x3($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 3), GPR_U32(ctx, 2));
label_a74:
    // 0xa74: 0x8e450050  lw          $a1, 0x50($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
label_a78:
    // 0xa78: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_a7c:
    // 0xa7c: 0x0  nop
    // NOP
label_a80:
    // 0xa80: 0x40f809  jalr        $v0
label_a84:
    if (ctx->pc == 0xA84u) {
        // 0xa84: 0x2484ffff  addiu       $a0, $a0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
        ctx->pc = 0xA88u;
        goto label_a88;
    }
    ctx->pc = 0xA80u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0xA88u);
        // 0xa84: 0x2484ffff  addiu       $a0, $a0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xA80u, 0xA88u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xA88u;
label_a88:
    // 0xa88: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_a8c:
    if (ctx->pc == 0xA8Cu) {
        ctx->pc = 0xA90u;
        goto label_a90;
    }
    ctx->pc = 0xA88u;
    {
        const bool branch_taken_0xa88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xa88) {
            ctx->pc = 0xA98u;
            goto label_a98;
        }
    }
    ctx->pc = 0xA90u;
label_a90:
    // 0xa90: 0x80002fa  j           func_000BE8
label_a94:
    if (ctx->pc == 0xA94u) {
        // 0xa94: 0xa2140001  sb          $s4, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 20));
        ctx->pc = 0xA98u;
        goto label_a98;
    }
    ctx->pc = 0xA90u;
    // 0xa94: 0xa2140001  sb          $s4, 0x1($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 20));
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0xA90u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0xA98u;
label_a98:
    // 0xa98: 0x8e020008  lw          $v0, 0x8($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_a9c:
    // 0xa9c: 0x0  nop
    // NOP
label_aa0:
    // 0xaa0: 0xae220014  sw          $v0, 0x14($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
label_aa4:
    // 0xaa4: 0x8e020004  lw          $v0, 0x4($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_aa8:
    // 0xaa8: 0x0  nop
    // NOP
label_aac:
    // 0xaac: 0xae420008  sw          $v0, 0x8($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
}


// Function: modmidi_00000ab0
// Address: 0xab0 - 0xbb0
void modmidi_00000ab0_0xab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000ab0_0xab0");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0xab0u;

label_ab0:
    // 0xab0: 0xae220018  sw          $v0, 0x18($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
label_ab4:
    // 0xab4: 0x92020003  lbu         $v0, 0x3($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
label_ab8:
    // 0xab8: 0x92230036  lbu         $v1, 0x36($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 54)));
label_abc:
    // 0xabc: 0xa2220031  sb          $v0, 0x31($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 49), (uint8_t)GPR_U32(ctx, 2));
label_ac0:
    // 0xac0: 0x92020002  lbu         $v0, 0x2($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
label_ac4:
    // 0xac4: 0x10600041  beqz        $v1, . + 4 + (0x41 << 2)
label_ac8:
    if (ctx->pc == 0xAC8u) {
        // 0xac8: 0xa2220030  sb          $v0, 0x30($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 48), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0xACCu;
        goto label_acc;
    }
    ctx->pc = 0xAC4u;
    {
        const bool branch_taken_0xac4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xac8: 0xa2220030  sb          $v0, 0x30($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 48), (uint8_t)GPR_U32(ctx, 2));
        if (branch_taken_0xac4) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0xACCu;
label_acc:
    // 0xacc: 0x92020001  lbu         $v0, 0x1($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_ad0:
    // 0xad0: 0x0  nop
    // NOP
label_ad4:
    // 0xad4: 0x2442ffff  addiu       $v0, $v0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_ad8:
    // 0xad8: 0x80002f3  j           func_000BCC
label_adc:
    if (ctx->pc == 0xADCu) {
        // 0xadc: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->pc = 0xAE0u;
        goto label_ae0;
    }
    ctx->pc = 0xAD8u;
    // 0xadc: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0xBCCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBCCu, 0xAD8u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0xAE0u;
label_ae0:
    // 0xae0: 0x80002f3  j           func_000BCC
label_ae4:
    if (ctx->pc == 0xAE4u) {
        // 0xae4: 0xa2140001  sb          $s4, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 20));
        ctx->pc = 0xAE8u;
        goto label_ae8;
    }
    ctx->pc = 0xAE0u;
    // 0xae4: 0xa2140001  sb          $s4, 0x1($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 20));
    ctx->pc = 0xBCCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBCCu, 0xAE0u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0xAE8u;
label_ae8:
    // 0xae8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_aec:
    // 0xaec: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_af0:
    // 0xaf0: 0x0  nop
    // NOP
label_af4:
    // 0xaf4: 0x10400035  beqz        $v0, . + 4 + (0x35 << 2)
label_af8:
    if (ctx->pc == 0xAF8u) {
        ctx->pc = 0xAFCu;
        goto label_afc;
    }
    ctx->pc = 0xAF4u;
    {
        const bool branch_taken_0xaf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xaf4) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0xAFCu;
label_afc:
    // 0xafc: 0x92250034  lbu         $a1, 0x34($s1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_b00:
    // 0xb00: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_b04:
    // 0xb04: 0x248438b0  addiu       $a0, $a0, 0x38B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14512));
label_b08:
    // 0xb08: 0xc000de5  jal         func_003794
label_b0c:
    if (ctx->pc == 0xB0Cu) {
        // 0xb0c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0xB10u;
        goto label_b10;
    }
    ctx->pc = 0xB08u;
    SET_GPR_U32(ctx, 31, 0xB10u);
    // 0xb0c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0xB08u, 0xB10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB10u;
label_b10:
    // 0xb10: 0x80002fa  j           func_000BE8
label_b14:
    if (ctx->pc == 0xB14u) {
        ctx->pc = 0xB18u;
        goto label_b18;
    }
    ctx->pc = 0xB10u;
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0xB10u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0xB18u;
label_b18:
    // 0xb18: 0x92230035  lbu         $v1, 0x35($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 53)));
label_b1c:
    // 0xb1c: 0x0  nop
    // NOP
label_b20:
    // 0xb20: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
label_b24:
    if (ctx->pc == 0xB24u) {
        // 0xb24: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xB28u;
        goto label_b28;
    }
    ctx->pc = 0xB20u;
    {
        const bool branch_taken_0xb20 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xb24: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xb20) {
            ctx->pc = 0xB38u;
            goto label_b38;
        }
    }
    ctx->pc = 0xB28u;
label_b28:
    // 0xb28: 0x10620013  beq         $v1, $v0, . + 4 + (0x13 << 2)
label_b2c:
    if (ctx->pc == 0xB2Cu) {
        ctx->pc = 0xB30u;
        goto label_b30;
    }
    ctx->pc = 0xB28u;
    {
        const bool branch_taken_0xb28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xb28) {
            ctx->pc = 0xB78u;
            goto label_b78;
        }
    }
    ctx->pc = 0xB30u;
label_b30:
    // 0xb30: 0x80002fa  j           func_000BE8
label_b34:
    if (ctx->pc == 0xB34u) {
        ctx->pc = 0xB38u;
        goto label_b38;
    }
    ctx->pc = 0xB30u;
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0xB30u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0xB38u;
label_b38:
    // 0xb38: 0x92230034  lbu         $v1, 0x34($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_b3c:
    // 0xb3c: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_b40:
    // 0xb40: 0x10620029  beq         $v1, $v0, . + 4 + (0x29 << 2)
label_b44:
    if (ctx->pc == 0xB44u) {
        ctx->pc = 0xB48u;
        goto label_b48;
    }
    ctx->pc = 0xB40u;
    {
        const bool branch_taken_0xb40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0xb40) {
            ctx->pc = 0xBE8u;
            return;
        }
    }
    ctx->pc = 0xB48u;
label_b48:
    // 0xb48: 0x10800020  beqz        $a0, . + 4 + (0x20 << 2)
label_b4c:
    if (ctx->pc == 0xB4Cu) {
        ctx->pc = 0xB50u;
        goto label_b50;
    }
    ctx->pc = 0xB48u;
    {
        const bool branch_taken_0xb48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0xb48) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0xB50u;
label_b50:
    // 0xb50: 0x8e420054  lw          $v0, 0x54($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
label_b54:
    // 0xb54: 0x0  nop
    // NOP
label_b58:
    // 0xb58: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
label_b5c:
    if (ctx->pc == 0xB5Cu) {
        // 0xb5c: 0x30c4000f  andi        $a0, $a2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
        ctx->pc = 0xB60u;
        goto label_b60;
    }
    ctx->pc = 0xB58u;
    {
        const bool branch_taken_0xb58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xb5c: 0x30c4000f  andi        $a0, $a2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
        if (branch_taken_0xb58) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0xB60u;
label_b60:
    // 0xb60: 0x8e260014  lw          $a2, 0x14($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_b64:
    // 0xb64: 0x8e470058  lw          $a3, 0x58($s2)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 88)));
label_b68:
    // 0xb68: 0x40f809  jalr        $v0
label_b6c:
    if (ctx->pc == 0xB6Cu) {
        // 0xb6c: 0x30a500ff  andi        $a1, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->pc = 0xB70u;
        goto label_b70;
    }
    ctx->pc = 0xB68u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0xB70u);
        // 0xb6c: 0x30a500ff  andi        $a1, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xB68u, 0xB70u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xB70u;
label_b70:
    // 0xb70: 0x80002fa  j           func_000BE8
label_b74:
    if (ctx->pc == 0xB74u) {
        // 0xb74: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0xB78u;
        goto label_b78;
    }
    ctx->pc = 0xB70u;
    // 0xb74: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    ctx->pc = 0xBE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xBE8u, 0xB70u, 0x0u, PS2Runtime::GuestBranchKind::DirectJump, "J")) {
        return;
    }
    ctx->pc = 0xB78u;
label_b78:
    // 0xb78: 0x92250034  lbu         $a1, 0x34($s1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 52)));
label_b7c:
    // 0xb7c: 0x240300ff  addiu       $v1, $zero, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_b80:
    // 0xb80: 0x10a30019  beq         $a1, $v1, . + 4 + (0x19 << 2)
label_b84:
    if (ctx->pc == 0xB84u) {
        ctx->pc = 0xB88u;
        goto label_b88;
    }
    ctx->pc = 0xB80u;
    {
        const bool branch_taken_0xb80 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0xb80) {
            ctx->pc = 0xBE8u;
            return;
        }
    }
    ctx->pc = 0xB88u;
label_b88:
    // 0xb88: 0x92220036  lbu         $v0, 0x36($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 54)));
label_b8c:
    // 0xb8c: 0x0  nop
    // NOP
label_b90:
    // 0xb90: 0x10430015  beq         $v0, $v1, . + 4 + (0x15 << 2)
label_b94:
    if (ctx->pc == 0xB94u) {
        ctx->pc = 0xB98u;
        goto label_b98;
    }
    ctx->pc = 0xB90u;
    {
        const bool branch_taken_0xb90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0xb90) {
            ctx->pc = 0xBE8u;
            return;
        }
    }
    ctx->pc = 0xB98u;
label_b98:
    // 0xb98: 0x1080000c  beqz        $a0, . + 4 + (0xC << 2)
label_b9c:
    if (ctx->pc == 0xB9Cu) {
        ctx->pc = 0xBA0u;
        goto label_ba0;
    }
    ctx->pc = 0xB98u;
    {
        const bool branch_taken_0xb98 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0xb98) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
    ctx->pc = 0xBA0u;
label_ba0:
    // 0xba0: 0x8e430054  lw          $v1, 0x54($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
label_ba4:
    // 0xba4: 0x0  nop
    // NOP
label_ba8:
    // 0xba8: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
label_bac:
    if (ctx->pc == 0xBACu) {
        // 0xbac: 0x30c4000f  andi        $a0, $a2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
        ctx->pc = 0xBB0u;
        goto label_fallthrough_0xba8;
    }
    ctx->pc = 0xBA8u;
    {
        const bool branch_taken_0xba8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xbac: 0x30c4000f  andi        $a0, $a2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
        if (branch_taken_0xba8) {
            ctx->pc = 0xBCCu;
            return;
        }
    }
label_fallthrough_0xba8:
    ctx->pc = 0xBB0u;
}


// Function: modmidi_00000bb0
// Address: 0xbb0 - 0xc20
void modmidi_00000bb0_0xbb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000bb0_0xbb0");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0xbb0u;

label_bb0:
    // 0xbb0: 0x30a5007f  andi        $a1, $a1, 0x7F
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)127);
label_bb4:
    // 0xbb4: 0x529c0  sll         $a1, $a1, 7
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
label_bb8:
    // 0xbb8: 0x3042007f  andi        $v0, $v0, 0x7F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
label_bbc:
    // 0xbbc: 0x8e260014  lw          $a2, 0x14($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_bc0:
    // 0xbc0: 0x8e470058  lw          $a3, 0x58($s2)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 88)));
label_bc4:
    // 0xbc4: 0x60f809  jalr        $v1
label_bc8:
    if (ctx->pc == 0xBC8u) {
        // 0xbc8: 0xa22825  or          $a1, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
        ctx->pc = 0xBCCu;
        goto label_bcc;
    }
    ctx->pc = 0xBC4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0xBCCu);
        // 0xbc8: 0xa22825  or          $a1, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xBC4u, 0xBCCu, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xBCCu;
label_bcc:
    // 0xbcc: 0x80002fa  j           func_000BE8
label_bd0:
    if (ctx->pc == 0xBD0u) {
        // 0xbd0: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0xBD4u;
        goto label_bd4;
    }
    ctx->pc = 0xBCCu;
    // 0xbd0: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    ctx->pc = 0xBE8u;
    goto label_be8;
    ctx->pc = 0xBD4u;
label_bd4:
    // 0xbd4: 0x92220035  lbu         $v0, 0x35($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 53)));
label_bd8:
    // 0xbd8: 0x0  nop
    // NOP
label_bdc:
    // 0xbdc: 0x14430002  bne         $v0, $v1, . + 4 + (0x2 << 2)
label_be0:
    if (ctx->pc == 0xBE0u) {
        ctx->pc = 0xBE4u;
        goto label_be4;
    }
    ctx->pc = 0xBDCu;
    {
        const bool branch_taken_0xbdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0xbdc) {
            ctx->pc = 0xBE8u;
            goto label_be8;
        }
    }
    ctx->pc = 0xBE4u;
label_be4:
    // 0xbe4: 0x24130001  addiu       $s3, $zero, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_be8:
    // 0xbe8: 0x12600005  beqz        $s3, . + 4 + (0x5 << 2)
label_bec:
    if (ctx->pc == 0xBECu) {
        // 0xbec: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->pc = 0xBF0u;
        goto label_bf0;
    }
    ctx->pc = 0xBE8u;
    {
        const bool branch_taken_0xbe8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0xbec: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0xbe8) {
            ctx->pc = 0xC00u;
            goto label_c00;
        }
    }
    ctx->pc = 0xBF0u;
label_bf0:
    // 0xbf0: 0xa2220036  sb          $v0, 0x36($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 54), (uint8_t)GPR_U32(ctx, 2));
label_bf4:
    // 0xbf4: 0xa2220034  sb          $v0, 0x34($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 52), (uint8_t)GPR_U32(ctx, 2));
label_bf8:
    // 0xbf8: 0xa2220035  sb          $v0, 0x35($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 53), (uint8_t)GPR_U32(ctx, 2));
label_bfc:
    // 0xbfc: 0xa2220033  sb          $v0, 0x33($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 51), (uint8_t)GPR_U32(ctx, 2));
label_c00:
    // 0xc00: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_c04:
    // 0xc04: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_c08:
    // 0xc08: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_c0c:
    // 0xc0c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_c10:
    // 0xc10: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_c14:
    // 0xc14: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_c18:
    // 0xc18: 0x3e00008  jr          $ra
label_c1c:
    if (ctx->pc == 0xC1Cu) {
        // 0xc1c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0xC20u;
        goto label_fallthrough_0xc18;
    }
    ctx->pc = 0xC18u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc1c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC18u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0xc18:
    ctx->pc = 0xC20u;
}


// Function: modmidi_00000c20
// Address: 0xc20 - 0xc5c
void modmidi_00000c20_0xc20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000c20_0xc20");
#endif

    ctx->pc = 0xc20u;

    // 0xc20: 0x8c820028  lw          $v0, 0x28($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0xc24: 0x8c830024  lw          $v1, 0x24($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0xc28: 0x211c0  sll         $v0, $v0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0xc2c: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0xC2Cu;
    {
        const bool branch_taken_0xc2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xc30: 0x43001b  divu        $zero, $v0, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0xc2c) {
            ctx->pc = 0xC38u;
            goto label_c38;
        }
    }
    ctx->pc = 0xC34u;
    // 0xc34: 0x7000d  break       7
    ctx->pc = 0xc34u;
    runtime->handleBreak(rdram, ctx);
label_c38:
    // 0xc38: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0xc3c: 0x8c83002c  lw          $v1, 0x2C($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0xc40: 0x21200  sll         $v0, $v0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0xc44: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0xC44u;
    {
        const bool branch_taken_0xc44 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xc48: 0x43001b  divu        $zero, $v0, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0xc44) {
            ctx->pc = 0xC50u;
            goto label_c50;
        }
    }
    ctx->pc = 0xC4Cu;
    // 0xc4c: 0x7000d  break       7
    ctx->pc = 0xc4cu;
    runtime->handleBreak(rdram, ctx);
label_c50:
    // 0xc50: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0xc54: 0x3e00008  jr          $ra
    ctx->pc = 0xC54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc58: 0xac820020  sw          $v0, 0x20($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 2));
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


// Function: modmidi_00000c5c
// Address: 0xc5c - 0xc90
void modmidi_00000c5c_0xc5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000c5c_0xc5c");
#endif

    switch (ctx->pc) {
        case 0xc68u: goto label_c68;
        default: break;
    }

    ctx->pc = 0xc5cu;

    // 0xc5c: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc60: 0x8cc50014  lw          $a1, 0x14($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0xc64: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_c68:
    // 0xc68: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0xc6c: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0xc70: 0x421c0  sll         $a0, $a0, 7
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0xc74: 0x3043007f  andi        $v1, $v0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0xc78: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0xc7c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0xC7Cu;
    {
        const bool branch_taken_0xc7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xc80: 0x832021  addu        $a0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        if (branch_taken_0xc7c) {
            ctx->pc = 0xC68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_c68;
        }
    }
    ctx->pc = 0xC84u;
    // 0xc84: 0xacc50014  sw          $a1, 0x14($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 5));
    // 0xc88: 0x3e00008  jr          $ra
    ctx->pc = 0xC88u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc8c: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC88u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC90u;
}


// Function: modmidi_00000c90
// Address: 0xc90 - 0xce8
void modmidi_00000c90_0xc90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000c90_0xc90");
#endif

    switch (ctx->pc) {
        case 0xcb4u: goto label_cb4;
        default: break;
    }

    ctx->pc = 0xc90u;

    // 0xc90: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc94: 0x90c20031  lbu         $v0, 0x31($a2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 49)));
    // 0xc98: 0x0  nop
    // NOP
    // 0xc9c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xC9Cu;
    {
        const bool branch_taken_0xc9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xca0: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xc9c) {
            ctx->pc = 0xCACu;
            goto label_cac;
        }
    }
    ctx->pc = 0xCA4u;
    // 0xca4: 0x8000338  j           func_000CE0
    ctx->pc = 0xCA4u;
    // 0xca8: 0xa0c00031  sb          $zero, 0x31($a2) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 6), 49), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0xCE0u;
    goto label_ce0;
    ctx->pc = 0xCACu;
label_cac:
    // 0xcac: 0x8cc50014  lw          $a1, 0x14($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0xcb0: 0x0  nop
    // NOP
label_cb4:
    // 0xcb4: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0xcb8: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0xcbc: 0x421c0  sll         $a0, $a0, 7
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0xcc0: 0x3043007f  andi        $v1, $v0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0xcc4: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0xcc8: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0xCC8u;
    {
        const bool branch_taken_0xcc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xccc: 0x832021  addu        $a0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        if (branch_taken_0xcc8) {
            ctx->pc = 0xCB4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_cb4;
        }
    }
    ctx->pc = 0xCD0u;
    // 0xcd0: 0x8cc20018  lw          $v0, 0x18($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 24)));
    // 0xcd4: 0xacc50014  sw          $a1, 0x14($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 5));
    // 0xcd8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xcdc: 0xacc20018  sw          $v0, 0x18($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 2));
label_ce0:
    // 0xce0: 0x3e00008  jr          $ra
    ctx->pc = 0xCE0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xce4: 0x801021  addu        $v0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCE0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCE8u;
}


// Function: modmidi_00000ce8
// Address: 0xce8 - 0xd2c
void modmidi_00000ce8_0xce8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000ce8_0xce8");
#endif

    switch (ctx->pc) {
        case 0xd0cu: goto label_d0c;
        default: break;
    }

    ctx->pc = 0xce8u;

    // 0xce8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xcec: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0xcf0: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xcf4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xcf8: 0x8e020014  lw          $v0, 0x14($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0xcfc: 0x0  nop
    // NOP
    // 0xd00: 0x2442ffff  addiu       $v0, $v0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0xd04: 0xc000317  jal         func_000C5C
    ctx->pc = 0xD04u;
    SET_GPR_U32(ctx, 31, 0xD0Cu);
    // 0xd08: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    ctx->pc = 0xC5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC5Cu, 0xD04u, 0xD0Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD0Cu;
label_d0c:
    // 0xd0c: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0xd10: 0x0  nop
    // NOP
    // 0xd14: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xd18: 0xae030014  sw          $v1, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0xd1c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xd20: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xd24: 0x3e00008  jr          $ra
    ctx->pc = 0xD24u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd28: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD24u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD2Cu;
}


// Function: modmidi_00000d2c
// Address: 0xd2c - 0xebc
void modmidi_00000d2c_0xd2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000d2c_0xd2c");
#endif

    switch (ctx->pc) {
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
        case 0xdc8u: goto label_dc8;
        case 0xdccu: goto label_dcc;
        case 0xdd0u: goto label_dd0;
        case 0xdd4u: goto label_dd4;
        case 0xdd8u: goto label_dd8;
        case 0xddcu: goto label_ddc;
        case 0xde0u: goto label_de0;
        case 0xde4u: goto label_de4;
        case 0xde8u: goto label_de8;
        case 0xdecu: goto label_dec;
        case 0xdf0u: goto label_df0;
        case 0xdf4u: goto label_df4;
        case 0xdf8u: goto label_df8;
        case 0xdfcu: goto label_dfc;
        case 0xe00u: goto label_e00;
        case 0xe04u: goto label_e04;
        case 0xe08u: goto label_e08;
        case 0xe0cu: goto label_e0c;
        case 0xe10u: goto label_e10;
        case 0xe14u: goto label_e14;
        case 0xe18u: goto label_e18;
        case 0xe1cu: goto label_e1c;
        case 0xe20u: goto label_e20;
        case 0xe24u: goto label_e24;
        case 0xe28u: goto label_e28;
        case 0xe2cu: goto label_e2c;
        case 0xe30u: goto label_e30;
        case 0xe34u: goto label_e34;
        case 0xe38u: goto label_e38;
        case 0xe3cu: goto label_e3c;
        case 0xe40u: goto label_e40;
        case 0xe44u: goto label_e44;
        case 0xe48u: goto label_e48;
        case 0xe4cu: goto label_e4c;
        case 0xe50u: goto label_e50;
        case 0xe54u: goto label_e54;
        case 0xe58u: goto label_e58;
        case 0xe5cu: goto label_e5c;
        case 0xe60u: goto label_e60;
        case 0xe64u: goto label_e64;
        case 0xe68u: goto label_e68;
        case 0xe6cu: goto label_e6c;
        case 0xe70u: goto label_e70;
        case 0xe74u: goto label_e74;
        case 0xe78u: goto label_e78;
        case 0xe7cu: goto label_e7c;
        case 0xe80u: goto label_e80;
        case 0xe84u: goto label_e84;
        case 0xe88u: goto label_e88;
        case 0xe8cu: goto label_e8c;
        case 0xe90u: goto label_e90;
        case 0xe94u: goto label_e94;
        case 0xe98u: goto label_e98;
        case 0xe9cu: goto label_e9c;
        case 0xea0u: goto label_ea0;
        case 0xea4u: goto label_ea4;
        case 0xea8u: goto label_ea8;
        case 0xeacu: goto label_eac;
        case 0xeb0u: goto label_eb0;
        case 0xeb4u: goto label_eb4;
        case 0xeb8u: goto label_eb8;
        default: break;
    }

    ctx->pc = 0xd2cu;

label_d2c:
    // 0xd2c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_d30:
    // 0xd30: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_d34:
    // 0xd34: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_d38:
    // 0xd38: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_d3c:
    // 0xd3c: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_d40:
    // 0xd40: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_d44:
    // 0xd44: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_d48:
    // 0xd48: 0xc0a021  addu        $s4, $a2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_d4c:
    // 0xd4c: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_d50:
    // 0xd50: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_d54:
    // 0xd54: 0xc000317  jal         func_000C5C
label_d58:
    if (ctx->pc == 0xD58u) {
        // 0xd58: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        ctx->pc = 0xD5Cu;
        goto label_d5c;
    }
    ctx->pc = 0xD54u;
    SET_GPR_U32(ctx, 31, 0xD5Cu);
    // 0xd58: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0xC5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC5Cu, 0xD54u, 0xD5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD5Cu;
label_d5c:
    // 0xd5c: 0x8e63003c  lw          $v1, 0x3C($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 60)));
label_d60:
    // 0xd60: 0x0  nop
    // NOP
label_d64:
    // 0xd64: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
label_d68:
    if (ctx->pc == 0xD68u) {
        // 0xd68: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0xD6Cu;
        goto label_d6c;
    }
    ctx->pc = 0xD64u;
    {
        const bool branch_taken_0xd64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xd68: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0xd64) {
            ctx->pc = 0xDA4u;
            goto label_da4;
        }
    }
    ctx->pc = 0xD6Cu;
label_d6c:
    // 0xd6c: 0x329200ff  andi        $s2, $s4, 0xFF
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
label_d70:
    // 0xd70: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_d74:
    // 0xd74: 0x8e250014  lw          $a1, 0x14($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_d78:
    // 0xd78: 0x8e670040  lw          $a3, 0x40($s3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 64)));
label_d7c:
    // 0xd7c: 0x60f809  jalr        $v1
label_d80:
    if (ctx->pc == 0xD80u) {
        // 0xd80: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0xD84u;
        goto label_d84;
    }
    ctx->pc = 0xD7Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0xD84u);
        // 0xd80: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xD7Cu, 0xD84u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xD84u;
label_d84:
    // 0xd84: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_d88:
    if (ctx->pc == 0xD88u) {
        // 0xd88: 0x328600ff  andi        $a2, $s4, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
        ctx->pc = 0xD8Cu;
        goto label_d8c;
    }
    ctx->pc = 0xD84u;
    {
        const bool branch_taken_0xd84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd88: 0x328600ff  andi        $a2, $s4, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
        if (branch_taken_0xd84) {
            ctx->pc = 0xDA8u;
            goto label_da8;
        }
    }
    ctx->pc = 0xD8Cu;
label_d8c:
    // 0xd8c: 0x3a42002f  xori        $v0, $s2, 0x2F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) ^ (uint64_t)(uint16_t)47);
label_d90:
    // 0xd90: 0x8e230014  lw          $v1, 0x14($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_d94:
    // 0xd94: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_d98:
    // 0xd98: 0x701821  addu        $v1, $v1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
label_d9c:
    // 0xd9c: 0x80003a7  j           func_000E9C
label_da0:
    if (ctx->pc == 0xDA0u) {
        // 0xda0: 0xae230014  sw          $v1, 0x14($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 3));
        ctx->pc = 0xDA4u;
        goto label_da4;
    }
    ctx->pc = 0xD9Cu;
    // 0xda0: 0xae230014  sw          $v1, 0x14($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 3));
    ctx->pc = 0xE9Cu;
    goto label_e9c;
    ctx->pc = 0xDA4u;
label_da4:
    // 0xda4: 0x328600ff  andi        $a2, $s4, 0xFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
label_da8:
    // 0xda8: 0x2402002f  addiu       $v0, $zero, 0x2F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
label_dac:
    // 0xdac: 0x10c20031  beq         $a2, $v0, . + 4 + (0x31 << 2)
label_db0:
    if (ctx->pc == 0xDB0u) {
        // 0xdb0: 0x24020051  addiu       $v0, $zero, 0x51 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
        ctx->pc = 0xDB4u;
        goto label_db4;
    }
    ctx->pc = 0xDACu;
    {
        const bool branch_taken_0xdac = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        // 0xdb0: 0x24020051  addiu       $v0, $zero, 0x51 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 81));
        if (branch_taken_0xdac) {
            ctx->pc = 0xE74u;
            goto label_e74;
        }
    }
    ctx->pc = 0xDB4u;
label_db4:
    // 0xdb4: 0x14c20034  bne         $a2, $v0, . + 4 + (0x34 << 2)
label_db8:
    if (ctx->pc == 0xDB8u) {
        // 0xdb8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0xDBCu;
        goto label_dbc;
    }
    ctx->pc = 0xDB4u;
    {
        const bool branch_taken_0xdb4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        // 0xdb8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0xdb4) {
            ctx->pc = 0xE88u;
            goto label_e88;
        }
    }
    ctx->pc = 0xDBCu;
label_dbc:
    // 0xdbc: 0x1202000c  beq         $s0, $v0, . + 4 + (0xC << 2)
label_dc0:
    if (ctx->pc == 0xDC0u) {
        ctx->pc = 0xDC4u;
        goto label_dc4;
    }
    ctx->pc = 0xDBCu;
    {
        const bool branch_taken_0xdbc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0xdbc) {
            ctx->pc = 0xDF0u;
            goto label_df0;
        }
    }
    ctx->pc = 0xDC4u;
label_dc4:
    // 0xdc4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_dc8:
    // 0xdc8: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_dcc:
    // 0xdcc: 0x0  nop
    // NOP
label_dd0:
    // 0xdd0: 0x10400032  beqz        $v0, . + 4 + (0x32 << 2)
label_dd4:
    if (ctx->pc == 0xDD4u) {
        // 0xdd4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xDD8u;
        goto label_dd8;
    }
    ctx->pc = 0xDD0u;
    {
        const bool branch_taken_0xdd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xdd4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xdd0) {
            ctx->pc = 0xE9Cu;
            goto label_e9c;
        }
    }
    ctx->pc = 0xDD8u;
label_dd8:
    // 0xdd8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_ddc:
    // 0xddc: 0x248438cc  addiu       $a0, $a0, 0x38CC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14540));
label_de0:
    // 0xde0: 0xc000de5  jal         func_003794
label_de4:
    if (ctx->pc == 0xDE4u) {
        // 0xde4: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0xDE8u;
        goto label_de8;
    }
    ctx->pc = 0xDE0u;
    SET_GPR_U32(ctx, 31, 0xDE8u);
    // 0xde4: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0xDE0u, 0xDE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDE8u;
label_de8:
    // 0xde8: 0x80003a7  j           func_000E9C
label_dec:
    if (ctx->pc == 0xDECu) {
        // 0xdec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xDF0u;
        goto label_df0;
    }
    ctx->pc = 0xDE8u;
    // 0xdec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xE9Cu;
    goto label_e9c;
    ctx->pc = 0xDF0u;
label_df0:
    // 0xdf0: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_df4:
    // 0xdf4: 0x0  nop
    // NOP
label_df8:
    // 0xdf8: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_dfc:
    // 0xdfc: 0x0  nop
    // NOP
label_e00:
    // 0xe00: 0x31c00  sll         $v1, $v1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
label_e04:
    // 0xe04: 0xae230028  sw          $v1, 0x28($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 3));
label_e08:
    // 0xe08: 0x90420001  lbu         $v0, 0x1($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
label_e0c:
    // 0xe0c: 0x8e240014  lw          $a0, 0x14($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_e10:
    // 0xe10: 0x21200  sll         $v0, $v0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
label_e14:
    // 0xe14: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_e18:
    // 0xe18: 0xae230028  sw          $v1, 0x28($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 3));
label_e1c:
    // 0xe1c: 0x90820002  lbu         $v0, 0x2($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
label_e20:
    // 0xe20: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_e24:
    // 0xe24: 0x8c843e4c  lw          $a0, 0x3E4C($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 15948)));
label_e28:
    // 0xe28: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_e2c:
    // 0xe2c: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
label_e30:
    if (ctx->pc == 0xE30u) {
        // 0xe30: 0xae230028  sw          $v1, 0x28($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 3));
        ctx->pc = 0xE34u;
        goto label_e34;
    }
    ctx->pc = 0xE2Cu;
    {
        const bool branch_taken_0xe2c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0xe30: 0xae230028  sw          $v1, 0x28($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 3));
        if (branch_taken_0xe2c) {
            ctx->pc = 0xE58u;
            goto label_e58;
        }
    }
    ctx->pc = 0xE34u;
label_e34:
    // 0xe34: 0x3c050393  lui         $a1, 0x393
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)915 << 16));
label_e38:
    // 0xe38: 0x34a58700  ori         $a1, $a1, 0x8700
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)34560);
label_e3c:
    // 0xe3c: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
label_e40:
    if (ctx->pc == 0xE40u) {
        // 0xe40: 0xa3001b  divu        $zero, $a1, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
        ctx->pc = 0xE44u;
        goto label_e44;
    }
    ctx->pc = 0xE3Cu;
    {
        const bool branch_taken_0xe3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xe40: 0xa3001b  divu        $zero, $a1, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
        if (branch_taken_0xe3c) {
            ctx->pc = 0xE48u;
            goto label_e48;
        }
    }
    ctx->pc = 0xE44u;
label_e44:
    // 0xe44: 0x7000d  break       7
    ctx->pc = 0xe44u;
    runtime->handleBreak(rdram, ctx);
label_e48:
    // 0xe48: 0x2812  mflo        $a1
    SET_GPR_U64(ctx, 5, ctx->lo);
label_e4c:
    // 0xe4c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_e50:
    // 0xe50: 0xc000de5  jal         func_003794
label_e54:
    if (ctx->pc == 0xE54u) {
        // 0xe54: 0x248438f4  addiu       $a0, $a0, 0x38F4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14580));
        ctx->pc = 0xE58u;
        goto label_e58;
    }
    ctx->pc = 0xE50u;
    SET_GPR_U32(ctx, 31, 0xE58u);
    // 0xe54: 0x248438f4  addiu       $a0, $a0, 0x38F4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14580));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0xE50u, 0xE58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE58u;
label_e58:
    // 0xe58: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_e5c:
    // 0xe5c: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_e60:
    // 0xe60: 0x24420003  addiu       $v0, $v0, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 3));
label_e64:
    // 0xe64: 0xc000308  jal         func_000C20
label_e68:
    if (ctx->pc == 0xE68u) {
        // 0xe68: 0xac820014  sw          $v0, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
        ctx->pc = 0xE6Cu;
        goto label_e6c;
    }
    ctx->pc = 0xE64u;
    SET_GPR_U32(ctx, 31, 0xE6Cu);
    // 0xe68: 0xac820014  sw          $v0, 0x14($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    ctx->pc = 0xC20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC20u, 0xE64u, 0xE6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE6Cu;
label_e6c:
    // 0xe6c: 0x80003a7  j           func_000E9C
label_e70:
    if (ctx->pc == 0xE70u) {
        // 0xe70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xE74u;
        goto label_e74;
    }
    ctx->pc = 0xE6Cu;
    // 0xe70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xE9Cu;
    goto label_e9c;
    ctx->pc = 0xE74u;
label_e74:
    // 0xe74: 0x8e63000c  lw          $v1, 0xC($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
label_e78:
    // 0xe78: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_e7c:
    // 0xe7c: 0x34630004  ori         $v1, $v1, 0x4
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4);
label_e80:
    // 0xe80: 0x80003a7  j           func_000E9C
label_e84:
    if (ctx->pc == 0xE84u) {
        // 0xe84: 0xae63000c  sw          $v1, 0xC($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 3));
        ctx->pc = 0xE88u;
        goto label_e88;
    }
    ctx->pc = 0xE80u;
    // 0xe84: 0xae63000c  sw          $v1, 0xC($s3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 3));
    ctx->pc = 0xE9Cu;
    goto label_e9c;
    ctx->pc = 0xE88u;
label_e88:
    // 0xe88: 0x8e220014  lw          $v0, 0x14($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
label_e8c:
    // 0xe8c: 0x0  nop
    // NOP
label_e90:
    // 0xe90: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_e94:
    // 0xe94: 0xae220014  sw          $v0, 0x14($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
label_e98:
    // 0xe98: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_e9c:
    // 0xe9c: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_ea0:
    // 0xea0: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_ea4:
    // 0xea4: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_ea8:
    // 0xea8: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_eac:
    // 0xeac: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_eb0:
    // 0xeb0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_eb4:
    // 0xeb4: 0x3e00008  jr          $ra
label_eb8:
    if (ctx->pc == 0xEB8u) {
        // 0xeb8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0xEBCu;
        goto label_fallthrough_0xeb4;
    }
    ctx->pc = 0xEB4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xeb8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xEB4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0xeb4:
    ctx->pc = 0xEBCu;
}


// Function: modmidi_00000ebc
// Address: 0xebc - 0xee4
void modmidi_00000ebc_0xebc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000ebc_0xebc");
#endif

    ctx->pc = 0xebcu;

    // 0xebc: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0xec0: 0x0  nop
    // NOP
    // 0xec4: 0x82102b  sltu        $v0, $a0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0xec8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0xEC8u;
    {
        const bool branch_taken_0xec8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xecc: 0x410c0  sll         $v0, $a0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
        if (branch_taken_0xec8) {
            ctx->pc = 0xEDCu;
            goto label_edc;
        }
    }
    ctx->pc = 0xED0u;
    // 0xed0: 0x8ca30004  lw          $v1, 0x4($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0xed4: 0x3e00008  jr          $ra
    ctx->pc = 0xED4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xed8: 0x621021  addu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xED4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xEDCu;
label_edc:
    // 0xedc: 0x3e00008  jr          $ra
    ctx->pc = 0xEDCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xee0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xEDCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xEE4u;
}


// Function: modmidi_00000ee4
// Address: 0xee4 - 0x1084
void modmidi_00000ee4_0xee4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00000ee4_0xee4");
#endif

    switch (ctx->pc) {
        case 0xee4u: goto label_ee4;
        case 0xee8u: goto label_ee8;
        case 0xeecu: goto label_eec;
        case 0xef0u: goto label_ef0;
        case 0xef4u: goto label_ef4;
        case 0xef8u: goto label_ef8;
        case 0xefcu: goto label_efc;
        case 0xf00u: goto label_f00;
        case 0xf04u: goto label_f04;
        case 0xf08u: goto label_f08;
        case 0xf0cu: goto label_f0c;
        case 0xf10u: goto label_f10;
        case 0xf14u: goto label_f14;
        case 0xf18u: goto label_f18;
        case 0xf1cu: goto label_f1c;
        case 0xf20u: goto label_f20;
        case 0xf24u: goto label_f24;
        case 0xf28u: goto label_f28;
        case 0xf2cu: goto label_f2c;
        case 0xf30u: goto label_f30;
        case 0xf34u: goto label_f34;
        case 0xf38u: goto label_f38;
        case 0xf3cu: goto label_f3c;
        case 0xf40u: goto label_f40;
        case 0xf44u: goto label_f44;
        case 0xf48u: goto label_f48;
        case 0xf4cu: goto label_f4c;
        case 0xf50u: goto label_f50;
        case 0xf54u: goto label_f54;
        case 0xf58u: goto label_f58;
        case 0xf5cu: goto label_f5c;
        case 0xf60u: goto label_f60;
        case 0xf64u: goto label_f64;
        case 0xf68u: goto label_f68;
        case 0xf6cu: goto label_f6c;
        case 0xf70u: goto label_f70;
        case 0xf74u: goto label_f74;
        case 0xf78u: goto label_f78;
        case 0xf7cu: goto label_f7c;
        case 0xf80u: goto label_f80;
        case 0xf84u: goto label_f84;
        case 0xf88u: goto label_f88;
        case 0xf8cu: goto label_f8c;
        case 0xf90u: goto label_f90;
        case 0xf94u: goto label_f94;
        case 0xf98u: goto label_f98;
        case 0xf9cu: goto label_f9c;
        case 0xfa0u: goto label_fa0;
        case 0xfa4u: goto label_fa4;
        case 0xfa8u: goto label_fa8;
        case 0xfacu: goto label_fac;
        case 0xfb0u: goto label_fb0;
        case 0xfb4u: goto label_fb4;
        case 0xfb8u: goto label_fb8;
        case 0xfbcu: goto label_fbc;
        case 0xfc0u: goto label_fc0;
        case 0xfc4u: goto label_fc4;
        case 0xfc8u: goto label_fc8;
        case 0xfccu: goto label_fcc;
        case 0xfd0u: goto label_fd0;
        case 0xfd4u: goto label_fd4;
        case 0xfd8u: goto label_fd8;
        case 0xfdcu: goto label_fdc;
        case 0xfe0u: goto label_fe0;
        case 0xfe4u: goto label_fe4;
        case 0xfe8u: goto label_fe8;
        case 0xfecu: goto label_fec;
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
        default: break;
    }

    ctx->pc = 0xee4u;

label_ee4:
    // 0xee4: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
label_ee8:
    // 0xee8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_eec:
    // 0xeec: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_ef0:
    // 0xef0: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_ef4:
    // 0xef4: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_ef8:
    // 0xef8: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
label_efc:
    // 0xefc: 0xc0a821  addu        $s5, $a2, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_f00:
    // 0xf00: 0x2802021  addu        $a0, $s4, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_f04:
    // 0xf04: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
label_f08:
    // 0xf08: 0xafb7002c  sw          $s7, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 23));
label_f0c:
    // 0xf0c: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
label_f10:
    // 0xf10: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_f14:
    // 0xf14: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_f18:
    // 0xf18: 0xc000317  jal         func_000C5C
label_f1c:
    if (ctx->pc == 0xF1Cu) {
        // 0xf1c: 0xafb10014  sw          $s1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
        ctx->pc = 0xF20u;
        goto label_f20;
    }
    ctx->pc = 0xF18u;
    SET_GPR_U32(ctx, 31, 0xF20u);
    // 0xf1c: 0xafb10014  sw          $s1, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    ctx->pc = 0xC5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC5Cu, 0xF18u, 0xF20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF20u;
label_f20:
    // 0xf20: 0x8e030044  lw          $v1, 0x44($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
label_f24:
    // 0xf24: 0x0  nop
    // NOP
label_f28:
    // 0xf28: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
label_f2c:
    if (ctx->pc == 0xF2Cu) {
        // 0xf2c: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0xF30u;
        goto label_f30;
    }
    ctx->pc = 0xF28u;
    {
        const bool branch_taken_0xf28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xf2c: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0xf28) {
            ctx->pc = 0xF48u;
            goto label_f48;
        }
    }
    ctx->pc = 0xF30u;
label_f30:
    // 0xf30: 0x8e840014  lw          $a0, 0x14($s4)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
label_f34:
    // 0xf34: 0x8e060048  lw          $a2, 0x48($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_f38:
    // 0xf38: 0x60f809  jalr        $v1
label_f3c:
    if (ctx->pc == 0xF3Cu) {
        // 0xf3c: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0xF40u;
        goto label_f40;
    }
    ctx->pc = 0xF38u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0xF40u);
        // 0xf3c: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xF38u, 0xF40u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xF40u;
label_f40:
    // 0xf40: 0x10400041  beqz        $v0, . + 4 + (0x41 << 2)
label_f44:
    if (ctx->pc == 0xF44u) {
        ctx->pc = 0xF48u;
        goto label_f48;
    }
    ctx->pc = 0xF40u;
    {
        const bool branch_taken_0xf40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xf40) {
            ctx->pc = 0x1048u;
            goto label_1048;
        }
    }
    ctx->pc = 0xF48u;
label_f48:
    // 0xf48: 0x12a0003f  beqz        $s5, . + 4 + (0x3F << 2)
label_f4c:
    if (ctx->pc == 0xF4Cu) {
        ctx->pc = 0xF50u;
        goto label_f50;
    }
    ctx->pc = 0xF48u;
    {
        const bool branch_taken_0xf48 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0xf48) {
            ctx->pc = 0x1048u;
            goto label_1048;
        }
    }
    ctx->pc = 0xF50u;
label_f50:
    // 0xf50: 0x96100030  lhu         $s0, 0x30($s0)
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 48)));
label_f54:
    // 0xf54: 0x0  nop
    // NOP
label_f58:
    // 0xf58: 0x1200003b  beqz        $s0, . + 4 + (0x3B << 2)
label_f5c:
    if (ctx->pc == 0xF5Cu) {
        // 0xf5c: 0x9821  addu        $s3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0xF60u;
        goto label_f60;
    }
    ctx->pc = 0xF58u;
    {
        const bool branch_taken_0xf58 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0xf5c: 0x9821  addu        $s3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xf58) {
            ctx->pc = 0x1048u;
            goto label_1048;
        }
    }
    ctx->pc = 0xF60u;
label_f60:
    // 0xf60: 0x241700f0  addiu       $s7, $zero, 0xF0
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
label_f64:
    // 0xf64: 0x2416ffff  addiu       $s6, $zero, -0x1
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_f68:
    // 0xf68: 0x24110001  addiu       $s1, $zero, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_f6c:
    // 0xf6c: 0x2111024  and         $v0, $s0, $s1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 17));
label_f70:
    // 0xf70: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
label_f74:
    if (ctx->pc == 0xF74u) {
        // 0xf74: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0xF78u;
        goto label_f78;
    }
    ctx->pc = 0xF70u;
    {
        const bool branch_taken_0xf70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xf74: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0xf70) {
            ctx->pc = 0x1028u;
            goto label_1028;
        }
    }
    ctx->pc = 0xF78u;
label_f78:
    // 0xf78: 0xc0003af  jal         func_000EBC
label_f7c:
    if (ctx->pc == 0xF7Cu) {
        // 0xf7c: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        ctx->pc = 0xF80u;
        goto label_f80;
    }
    ctx->pc = 0xF78u;
    SET_GPR_U32(ctx, 31, 0xF80u);
    // 0xf7c: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0xEBCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEBCu, 0xF78u, 0xF80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF80u;
label_f80:
    // 0xf80: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
label_f84:
    if (ctx->pc == 0xF84u) {
        ctx->pc = 0xF88u;
        goto label_f88;
    }
    ctx->pc = 0xF80u;
    {
        const bool branch_taken_0xf80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xf80) {
            ctx->pc = 0x1038u;
            goto label_1038;
        }
    }
    ctx->pc = 0xF88u;
label_f88:
    // 0xf88: 0x8c450004  lw          $a1, 0x4($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_f8c:
    // 0xf8c: 0x0  nop
    // NOP
label_f90:
    // 0xf90: 0x10a00029  beqz        $a1, . + 4 + (0x29 << 2)
label_f94:
    if (ctx->pc == 0xF94u) {
        ctx->pc = 0xF98u;
        goto label_f98;
    }
    ctx->pc = 0xF90u;
    {
        const bool branch_taken_0xf90 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0xf90) {
            ctx->pc = 0x1038u;
            goto label_1038;
        }
    }
    ctx->pc = 0xF98u;
label_f98:
    // 0xf98: 0x8ca60004  lw          $a2, 0x4($a1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
label_f9c:
    // 0xf9c: 0x8ca30000  lw          $v1, 0x0($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
label_fa0:
    // 0xfa0: 0xd21021  addu        $v0, $a2, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
label_fa4:
    // 0xfa4: 0x24420009  addiu       $v0, $v0, 0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9));
label_fa8:
    // 0xfa8: 0x62182b  sltu        $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_fac:
    // 0xfac: 0x14600013  bnez        $v1, . + 4 + (0x13 << 2)
label_fb0:
    if (ctx->pc == 0xFB0u) {
        // 0xfb0: 0x24c20008  addiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->pc = 0xFB4u;
        goto label_fb4;
    }
    ctx->pc = 0xFACu;
    {
        const bool branch_taken_0xfac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xfb0: 0x24c20008  addiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0xfac) {
            ctx->pc = 0xFFCu;
            goto label_ffc;
        }
    }
    ctx->pc = 0xFB4u;
label_fb4:
    // 0xfb4: 0xa22021  addu        $a0, $a1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_fb8:
    // 0xfb8: 0xd11021  addu        $v0, $a2, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
label_fbc:
    // 0xfbc: 0x8e870014  lw          $a3, 0x14($s4)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
label_fc0:
    // 0xfc0: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_fc4:
    // 0xfc4: 0xaca20004  sw          $v0, 0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
label_fc8:
    // 0xfc8: 0xa0970000  sb          $s7, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 23));
label_fcc:
    // 0xfcc: 0x2643ffff  addiu       $v1, $s2, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
label_fd0:
    // 0xfd0: 0x10760019  beq         $v1, $s6, . + 4 + (0x19 << 2)
label_fd4:
    if (ctx->pc == 0xFD4u) {
        // 0xfd4: 0x912021  addu        $a0, $a0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
        ctx->pc = 0xFD8u;
        goto label_fd8;
    }
    ctx->pc = 0xFD0u;
    {
        const bool branch_taken_0xfd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 22));
        // 0xfd4: 0x912021  addu        $a0, $a0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
        if (branch_taken_0xfd0) {
            ctx->pc = 0x1038u;
            goto label_1038;
        }
    }
    ctx->pc = 0xFD8u;
label_fd8:
    // 0xfd8: 0x2405ffff  addiu       $a1, $zero, -0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_fdc:
    // 0xfdc: 0x90e20000  lbu         $v0, 0x0($a3)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
label_fe0:
    // 0xfe0: 0x24e70001  addiu       $a3, $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_fe4:
    // 0xfe4: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_fe8:
    // 0xfe8: 0xa0820000  sb          $v0, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
label_fec:
    // 0xfec: 0x1465fffb  bne         $v1, $a1, . + 4 + (-0x5 << 2)
label_ff0:
    if (ctx->pc == 0xFF0u) {
        // 0xff0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->pc = 0xFF4u;
        goto label_ff4;
    }
    ctx->pc = 0xFECu;
    {
        const bool branch_taken_0xfec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        // 0xff0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0xfec) {
            ctx->pc = 0xFDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_fdc;
        }
    }
    ctx->pc = 0xFF4u;
label_ff4:
    // 0xff4: 0x800040f  j           func_00103C
label_ff8:
    if (ctx->pc == 0xFF8u) {
        // 0xff8: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
        ctx->pc = 0xFFCu;
        goto label_ffc;
    }
    ctx->pc = 0xFF4u;
    // 0xff8: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
    ctx->pc = 0x103Cu;
    goto label_103c;
    ctx->pc = 0xFFCu;
label_ffc:
    // 0xffc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1000:
    // 0x1000: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_1004:
    // 0x1004: 0x0  nop
    // NOP
label_1008:
    // 0x1008: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
label_100c:
    if (ctx->pc == 0x100Cu) {
        ctx->pc = 0x1010u;
        goto label_1010;
    }
    ctx->pc = 0x1008u;
    {
        const bool branch_taken_0x1008 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1008) {
            ctx->pc = 0x1038u;
            goto label_1038;
        }
    }
    ctx->pc = 0x1010u;
label_1010:
    // 0x1010: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1014:
    // 0x1014: 0x24843900  addiu       $a0, $a0, 0x3900
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14592));
label_1018:
    // 0x1018: 0xc000de5  jal         func_003794
label_101c:
    if (ctx->pc == 0x101Cu) {
        // 0x101c: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
        ctx->pc = 0x1020u;
        goto label_1020;
    }
    ctx->pc = 0x1018u;
    SET_GPR_U32(ctx, 31, 0x1020u);
    // 0x101c: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x1018u, 0x1020u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1020u;
label_1020:
    // 0x1020: 0x8000410  j           func_001040
label_1024:
    if (ctx->pc == 0x1024u) {
        // 0x1024: 0x2719821  addu        $s3, $s3, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
        ctx->pc = 0x1028u;
        goto label_1028;
    }
    ctx->pc = 0x1020u;
    // 0x1024: 0x2719821  addu        $s3, $s3, $s1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    ctx->pc = 0x1040u;
    goto label_1040;
    ctx->pc = 0x1028u;
label_1028:
    // 0x1028: 0x3202000f  andi        $v0, $s0, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
label_102c:
    // 0x102c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
label_1030:
    if (ctx->pc == 0x1030u) {
        ctx->pc = 0x1034u;
        goto label_1034;
    }
    ctx->pc = 0x102Cu;
    {
        const bool branch_taken_0x102c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x102c) {
            ctx->pc = 0x1038u;
            goto label_1038;
        }
    }
    ctx->pc = 0x1034u;
label_1034:
    // 0x1034: 0x24110004  addiu       $s1, $zero, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_1038:
    // 0x1038: 0x2308006  srlv        $s0, $s0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
label_103c:
    // 0x103c: 0x2719821  addu        $s3, $s3, $s1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
label_1040:
    // 0x1040: 0x1600ffca  bnez        $s0, . + 4 + (-0x36 << 2)
label_1044:
    if (ctx->pc == 0x1044u) {
        // 0x1044: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1048u;
        goto label_1048;
    }
    ctx->pc = 0x1040u;
    {
        const bool branch_taken_0x1040 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x1044: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1040) {
            ctx->pc = 0xF6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_f6c;
        }
    }
    ctx->pc = 0x1048u;
label_1048:
    // 0x1048: 0x8e820014  lw          $v0, 0x14($s4)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
label_104c:
    // 0x104c: 0x0  nop
    // NOP
label_1050:
    // 0x1050: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_1054:
    // 0x1054: 0xae820014  sw          $v0, 0x14($s4)
    WRITE32(ADD32(GPR_U32(ctx, 20), 20), GPR_U32(ctx, 2));
label_1058:
    // 0x1058: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_105c:
    // 0x105c: 0x8fb7002c  lw          $s7, 0x2C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1060:
    // 0x1060: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_1064:
    // 0x1064: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_1068:
    // 0x1068: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_106c:
    // 0x106c: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1070:
    // 0x1070: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1074:
    // 0x1074: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_1078:
    // 0x1078: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_107c:
    // 0x107c: 0x3e00008  jr          $ra
label_1080:
    if (ctx->pc == 0x1080u) {
        // 0x1080: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = 0x1084u;
        goto label_fallthrough_0x107c;
    }
    ctx->pc = 0x107Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1080: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x107Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x107c:
    ctx->pc = 0x1084u;
}


// Function: modmidi_00001084
// Address: 0x1084 - 0x1218
void modmidi_00001084_0x1084(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001084_0x1084");
#endif

    switch (ctx->pc) {
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
        case 0x10d4u: goto label_10d4;
        case 0x10d8u: goto label_10d8;
        case 0x10dcu: goto label_10dc;
        case 0x10e0u: goto label_10e0;
        case 0x10e4u: goto label_10e4;
        case 0x10e8u: goto label_10e8;
        case 0x10ecu: goto label_10ec;
        case 0x10f0u: goto label_10f0;
        case 0x10f4u: goto label_10f4;
        case 0x10f8u: goto label_10f8;
        case 0x10fcu: goto label_10fc;
        case 0x1100u: goto label_1100;
        case 0x1104u: goto label_1104;
        case 0x1108u: goto label_1108;
        case 0x110cu: goto label_110c;
        case 0x1110u: goto label_1110;
        case 0x1114u: goto label_1114;
        case 0x1118u: goto label_1118;
        case 0x111cu: goto label_111c;
        case 0x1120u: goto label_1120;
        case 0x1124u: goto label_1124;
        case 0x1128u: goto label_1128;
        case 0x112cu: goto label_112c;
        case 0x1130u: goto label_1130;
        case 0x1134u: goto label_1134;
        case 0x1138u: goto label_1138;
        case 0x113cu: goto label_113c;
        case 0x1140u: goto label_1140;
        case 0x1144u: goto label_1144;
        case 0x1148u: goto label_1148;
        case 0x114cu: goto label_114c;
        case 0x1150u: goto label_1150;
        case 0x1154u: goto label_1154;
        case 0x1158u: goto label_1158;
        case 0x115cu: goto label_115c;
        case 0x1160u: goto label_1160;
        case 0x1164u: goto label_1164;
        case 0x1168u: goto label_1168;
        case 0x116cu: goto label_116c;
        case 0x1170u: goto label_1170;
        case 0x1174u: goto label_1174;
        case 0x1178u: goto label_1178;
        case 0x117cu: goto label_117c;
        case 0x1180u: goto label_1180;
        case 0x1184u: goto label_1184;
        case 0x1188u: goto label_1188;
        case 0x118cu: goto label_118c;
        case 0x1190u: goto label_1190;
        case 0x1194u: goto label_1194;
        case 0x1198u: goto label_1198;
        case 0x119cu: goto label_119c;
        case 0x11a0u: goto label_11a0;
        case 0x11a4u: goto label_11a4;
        case 0x11a8u: goto label_11a8;
        case 0x11acu: goto label_11ac;
        case 0x11b0u: goto label_11b0;
        case 0x11b4u: goto label_11b4;
        case 0x11b8u: goto label_11b8;
        case 0x11bcu: goto label_11bc;
        case 0x11c0u: goto label_11c0;
        case 0x11c4u: goto label_11c4;
        case 0x11c8u: goto label_11c8;
        case 0x11ccu: goto label_11cc;
        case 0x11d0u: goto label_11d0;
        case 0x11d4u: goto label_11d4;
        case 0x11d8u: goto label_11d8;
        case 0x11dcu: goto label_11dc;
        case 0x11e0u: goto label_11e0;
        case 0x11e4u: goto label_11e4;
        case 0x11e8u: goto label_11e8;
        case 0x11ecu: goto label_11ec;
        case 0x11f0u: goto label_11f0;
        case 0x11f4u: goto label_11f4;
        case 0x11f8u: goto label_11f8;
        case 0x11fcu: goto label_11fc;
        case 0x1200u: goto label_1200;
        case 0x1204u: goto label_1204;
        case 0x1208u: goto label_1208;
        case 0x120cu: goto label_120c;
        case 0x1210u: goto label_1210;
        case 0x1214u: goto label_1214;
        default: break;
    }

    ctx->pc = 0x1084u;

label_1084:
    // 0x1084: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_1088:
    // 0x1088: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_108c:
    // 0x108c: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1090:
    // 0x1090: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_1094:
    // 0x1094: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_1098:
    // 0x1098: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
label_109c:
    // 0x109c: 0x3c02007f  lui         $v0, 0x7F
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
label_10a0:
    // 0x10a0: 0x34427fff  ori         $v0, $v0, 0x7FFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32767);
label_10a4:
    // 0x10a4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_10a8:
    // 0x10a8: 0xe29024  and         $s2, $a3, $v0
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 7) & GPR_U64(ctx, 2));
label_10ac:
    // 0x10ac: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_10b0:
    // 0x10b0: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
label_10b4:
    // 0x10b4: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_10b8:
    // 0x10b8: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_10bc:
    // 0x10bc: 0x8e020034  lw          $v0, 0x34($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
label_10c0:
    // 0x10c0: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_10c4:
    // 0x10c4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
label_10c8:
    if (ctx->pc == 0x10C8u) {
        // 0x10c8: 0xc0a821  addu        $s5, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        ctx->pc = 0x10CCu;
        goto label_10cc;
    }
    ctx->pc = 0x10C4u;
    {
        const bool branch_taken_0x10c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x10c8: 0xc0a821  addu        $s5, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0x10c4) {
            ctx->pc = 0x10E4u;
            goto label_10e4;
        }
    }
    ctx->pc = 0x10CCu;
label_10cc:
    // 0x10cc: 0x8e050038  lw          $a1, 0x38($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
label_10d0:
    // 0x10d0: 0x40f809  jalr        $v0
label_10d4:
    if (ctx->pc == 0x10D4u) {
        // 0x10d4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x10D8u;
        goto label_10d8;
    }
    ctx->pc = 0x10D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x10D8u);
        // 0x10d4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x10D0u, 0x10D8u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x10D8u;
label_10d8:
    // 0x10d8: 0x409021  addu        $s2, $v0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_10dc:
    // 0x10dc: 0x12400044  beqz        $s2, . + 4 + (0x44 << 2)
label_10e0:
    if (ctx->pc == 0x10E0u) {
        ctx->pc = 0x10E4u;
        goto label_10e4;
    }
    ctx->pc = 0x10DCu;
    {
        const bool branch_taken_0x10dc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x10dc) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x10E4u;
label_10e4:
    // 0x10e4: 0x3242000f  andi        $v0, $s2, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)15);
label_10e8:
    // 0x10e8: 0x22040  sll         $a0, $v0, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_10ec:
    // 0x10ec: 0x9622003a  lhu         $v0, 0x3A($s1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 58)));
label_10f0:
    // 0x10f0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_10f4:
    // 0x10f4: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_10f8:
    // 0x10f8: 0x94633e90  lhu         $v1, 0x3E90($v1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 16016)));
label_10fc:
    // 0x10fc: 0x0  nop
    // NOP
label_1100:
    // 0x1100: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
label_1104:
    // 0x1104: 0x12a0003a  beqz        $s5, . + 4 + (0x3A << 2)
label_1108:
    if (ctx->pc == 0x1108u) {
        // 0x1108: 0xa622003a  sh          $v0, 0x3A($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 58), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x110Cu;
        goto label_110c;
    }
    ctx->pc = 0x1104u;
    {
        const bool branch_taken_0x1104 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0x1108: 0xa622003a  sh          $v0, 0x3A($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 58), (uint16_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1104) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x110Cu;
label_110c:
    // 0x110c: 0x2041021  addu        $v0, $s0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_1110:
    // 0x1110: 0x94500010  lhu         $s0, 0x10($v0)
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 16)));
label_1114:
    // 0x1114: 0x0  nop
    // NOP
label_1118:
    // 0x1118: 0x12000035  beqz        $s0, . + 4 + (0x35 << 2)
label_111c:
    if (ctx->pc == 0x111Cu) {
        // 0x111c: 0x9821  addu        $s3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1120u;
        goto label_1120;
    }
    ctx->pc = 0x1118u;
    {
        const bool branch_taken_0x1118 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x111c: 0x9821  addu        $s3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1118) {
            ctx->pc = 0x11F0u;
            goto label_11f0;
        }
    }
    ctx->pc = 0x1120u;
label_1120:
    // 0x1120: 0x2416ffff  addiu       $s6, $zero, -0x1
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1124:
    // 0x1124: 0x24110001  addiu       $s1, $zero, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1128:
    // 0x1128: 0x2111024  and         $v0, $s0, $s1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 17));
label_112c:
    // 0x112c: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
label_1130:
    if (ctx->pc == 0x1130u) {
        // 0x1130: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x1134u;
        goto label_1134;
    }
    ctx->pc = 0x112Cu;
    {
        const bool branch_taken_0x112c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1130: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x112c) {
            ctx->pc = 0x11D0u;
            goto label_11d0;
        }
    }
    ctx->pc = 0x1134u;
label_1134:
    // 0x1134: 0xc0003af  jal         func_000EBC
label_1138:
    if (ctx->pc == 0x1138u) {
        // 0x1138: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        ctx->pc = 0x113Cu;
        goto label_113c;
    }
    ctx->pc = 0x1134u;
    SET_GPR_U32(ctx, 31, 0x113Cu);
    // 0x1138: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0xEBCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEBCu, 0x1134u, 0x113Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x113Cu;
label_113c:
    // 0x113c: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
label_1140:
    if (ctx->pc == 0x1140u) {
        ctx->pc = 0x1144u;
        goto label_1144;
    }
    ctx->pc = 0x113Cu;
    {
        const bool branch_taken_0x113c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x113c) {
            ctx->pc = 0x11E0u;
            goto label_11e0;
        }
    }
    ctx->pc = 0x1144u;
label_1144:
    // 0x1144: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_1148:
    // 0x1148: 0x0  nop
    // NOP
label_114c:
    // 0x114c: 0x10800024  beqz        $a0, . + 4 + (0x24 << 2)
label_1150:
    if (ctx->pc == 0x1150u) {
        ctx->pc = 0x1154u;
        goto label_1154;
    }
    ctx->pc = 0x114Cu;
    {
        const bool branch_taken_0x114c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x114c) {
            ctx->pc = 0x11E0u;
            goto label_11e0;
        }
    }
    ctx->pc = 0x1154u;
label_1154:
    // 0x1154: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
label_1158:
    // 0x1158: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_115c:
    // 0x115c: 0xd43821  addu        $a3, $a2, $s4
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 20)));
label_1160:
    // 0x1160: 0x24e30008  addiu       $v1, $a3, 0x8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
label_1164:
    // 0x1164: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
label_1168:
    // 0x1168: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
label_116c:
    if (ctx->pc == 0x116Cu) {
        // 0x116c: 0x24c20008  addiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->pc = 0x1170u;
        goto label_1170;
    }
    ctx->pc = 0x1168u;
    {
        const bool branch_taken_0x1168 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x116c: 0x24c20008  addiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x1168) {
            ctx->pc = 0x119Cu;
            goto label_119c;
        }
    }
    ctx->pc = 0x1170u;
label_1170:
    // 0x1170: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1174:
    // 0x1174: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_1178:
    // 0x1178: 0x0  nop
    // NOP
label_117c:
    // 0x117c: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
label_1180:
    if (ctx->pc == 0x1180u) {
        ctx->pc = 0x1184u;
        goto label_1184;
    }
    ctx->pc = 0x117Cu;
    {
        const bool branch_taken_0x117c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x117c) {
            ctx->pc = 0x11E0u;
            goto label_11e0;
        }
    }
    ctx->pc = 0x1184u;
label_1184:
    // 0x1184: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1188:
    // 0x1188: 0x24843920  addiu       $a0, $a0, 0x3920
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14624));
label_118c:
    // 0x118c: 0xc000de5  jal         func_003794
label_1190:
    if (ctx->pc == 0x1190u) {
        // 0x1190: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
        ctx->pc = 0x1194u;
        goto label_1194;
    }
    ctx->pc = 0x118Cu;
    SET_GPR_U32(ctx, 31, 0x1194u);
    // 0x1190: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x118Cu, 0x1194u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1194u;
label_1194:
    // 0x1194: 0x800047a  j           func_0011E8
label_1198:
    if (ctx->pc == 0x1198u) {
        // 0x1198: 0x2719821  addu        $s3, $s3, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
        ctx->pc = 0x119Cu;
        goto label_119c;
    }
    ctx->pc = 0x1194u;
    // 0x1198: 0x2719821  addu        $s3, $s3, $s1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    ctx->pc = 0x11E8u;
    goto label_11e8;
    ctx->pc = 0x119Cu;
label_119c:
    // 0x119c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_11a0:
    // 0x11a0: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_11a4:
    // 0x11a4: 0x2682ffff  addiu       $v0, $s4, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
label_11a8:
    // 0x11a8: 0x1056000d  beq         $v0, $s6, . + 4 + (0xD << 2)
label_11ac:
    if (ctx->pc == 0x11ACu) {
        // 0x11ac: 0xac870004  sw          $a3, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 7));
        ctx->pc = 0x11B0u;
        goto label_11b0;
    }
    ctx->pc = 0x11A8u;
    {
        const bool branch_taken_0x11a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 22));
        // 0x11ac: 0xac870004  sw          $a3, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 7));
        if (branch_taken_0x11a8) {
            ctx->pc = 0x11E0u;
            goto label_11e0;
        }
    }
    ctx->pc = 0x11B0u;
label_11b0:
    // 0x11b0: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_11b4:
    // 0x11b4: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
label_11b8:
    // 0x11b8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_11bc:
    // 0x11bc: 0x2442ffff  addiu       $v0, $v0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_11c0:
    // 0x11c0: 0x1444fffc  bne         $v0, $a0, . + 4 + (-0x4 << 2)
label_11c4:
    if (ctx->pc == 0x11C4u) {
        // 0x11c4: 0x52a02  srl         $a1, $a1, 8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
        ctx->pc = 0x11C8u;
        goto label_11c8;
    }
    ctx->pc = 0x11C0u;
    {
        const bool branch_taken_0x11c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        // 0x11c4: 0x52a02  srl         $a1, $a1, 8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
        if (branch_taken_0x11c0) {
            ctx->pc = 0x11B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b4;
        }
    }
    ctx->pc = 0x11C8u;
label_11c8:
    // 0x11c8: 0x8000479  j           func_0011E4
label_11cc:
    if (ctx->pc == 0x11CCu) {
        // 0x11cc: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
        ctx->pc = 0x11D0u;
        goto label_11d0;
    }
    ctx->pc = 0x11C8u;
    // 0x11cc: 0x2308006  srlv        $s0, $s0, $s1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
    ctx->pc = 0x11E4u;
    goto label_11e4;
    ctx->pc = 0x11D0u;
label_11d0:
    // 0x11d0: 0x3202000f  andi        $v0, $s0, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
label_11d4:
    // 0x11d4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
label_11d8:
    if (ctx->pc == 0x11D8u) {
        ctx->pc = 0x11DCu;
        goto label_11dc;
    }
    ctx->pc = 0x11D4u;
    {
        const bool branch_taken_0x11d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d4) {
            ctx->pc = 0x11E0u;
            goto label_11e0;
        }
    }
    ctx->pc = 0x11DCu;
label_11dc:
    // 0x11dc: 0x24110004  addiu       $s1, $zero, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_11e0:
    // 0x11e0: 0x2308006  srlv        $s0, $s0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 17) & 0x1F));
label_11e4:
    // 0x11e4: 0x2719821  addu        $s3, $s3, $s1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
label_11e8:
    // 0x11e8: 0x1600ffcf  bnez        $s0, . + 4 + (-0x31 << 2)
label_11ec:
    if (ctx->pc == 0x11ECu) {
        // 0x11ec: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x11F0u;
        goto label_11f0;
    }
    ctx->pc = 0x11E8u;
    {
        const bool branch_taken_0x11e8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x11ec: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x11e8) {
            ctx->pc = 0x1128u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1128;
        }
    }
    ctx->pc = 0x11F0u;
label_11f0:
    // 0x11f0: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_11f4:
    // 0x11f4: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_11f8:
    // 0x11f8: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_11fc:
    // 0x11fc: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_1200:
    // 0x1200: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1204:
    // 0x1204: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1208:
    // 0x1208: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_120c:
    // 0x120c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1210:
    // 0x1210: 0x3e00008  jr          $ra
label_1214:
    if (ctx->pc == 0x1214u) {
        // 0x1214: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x1218u;
        goto label_fallthrough_0x1210;
    }
    ctx->pc = 0x1210u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1214: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1210u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x1210:
    ctx->pc = 0x1218u;
}


// Function: modmidi_00001218
// Address: 0x1218 - 0x1260
void modmidi_00001218_0x1218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001218_0x1218");
#endif

    ctx->pc = 0x1218u;

    // 0x1218: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x121c: 0x852821  addu        $a1, $a0, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1220: 0x90a3003c  lbu         $v1, 0x3C($a1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 60)));
    // 0x1224: 0x90a2004c  lbu         $v0, 0x4C($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x1228: 0x0  nop
    // NOP
    // 0x122c: 0x620018  mult        $zero, $v1, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1230: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1234: 0x90820032  lbu         $v0, 0x32($a0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 50)));
    // 0x1238: 0x0  nop
    // NOP
    // 0x123c: 0xc20018  mult        $zero, $a2, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1240: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1244: 0x61b82  srl         $v1, $a2, 14
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 6), 14));
    // 0x1248: 0x2c620080  sltiu       $v0, $v1, 0x80
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x124c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x124Cu;
    {
        const bool branch_taken_0x124c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x124c) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x1254u;
    // 0x1254: 0x2403007f  addiu       $v1, $zero, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_1258:
    // 0x1258: 0x3e00008  jr          $ra
    ctx->pc = 0x1258u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x125c: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1258u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1260u;
}


// Function: modmidi_00001260
// Address: 0x1260 - 0x17ac
void modmidi_00001260_0x1260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001260_0x1260");
#endif

    switch (ctx->pc) {
        case 0x12a4u: goto label_12a4;
        case 0x1310u: goto label_1310;
        case 0x154cu: goto label_154c;
        case 0x1618u: goto label_1618;
        case 0x168cu: goto label_168c;
        case 0x16b0u: goto label_16b0;
        case 0x1700u: goto label_1700;
        case 0x171cu: goto label_171c;
        case 0x172cu: goto label_172c;
        case 0x1758u: goto label_1758;
        case 0x1768u: goto label_1768;
        default: break;
    }

    ctx->pc = 0x1260u;

    // 0x1260: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1264: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x1268: 0x80a821  addu        $s5, $a0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x126c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1270: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1274: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x1278: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
    // 0x127c: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x1280: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x1284: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1288: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x128c: 0x8e430018  lw          $v1, 0x18($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x1290: 0x8ea20008  lw          $v0, 0x8($s5)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x1294: 0x0  nop
    // NOP
    // 0x1298: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x129c: 0x14400138  bnez        $v0, . + 4 + (0x138 << 2)
    ctx->pc = 0x129Cu;
    {
        const bool branch_taken_0x129c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x12a0: 0xc0b021  addu        $s6, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0x129c) {
            ctx->pc = 0x1780u;
            goto label_1780;
        }
    }
    ctx->pc = 0x12A4u;
label_12a4:
    // 0x12a4: 0x8e430014  lw          $v1, 0x14($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x12a8: 0x0  nop
    // NOP
    // 0x12ac: 0x90670000  lbu         $a3, 0x0($v1)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12b0: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12b4: 0xae420014  sw          $v0, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x12b8: 0x30e20080  andi        $v0, $a3, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)128);
    // 0x12bc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12BCu;
    {
        const bool branch_taken_0x12bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x12c0: 0x24620002  addiu       $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x12bc) {
            ctx->pc = 0x12D0u;
            goto label_12d0;
        }
    }
    ctx->pc = 0x12C4u;
    // 0x12c4: 0x90740001  lbu         $s4, 0x1($v1)
    SET_GPR_U32(ctx, 20, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x12c8: 0x80004c6  j           func_001318
    ctx->pc = 0x12C8u;
    // 0x12cc: 0xae420014  sw          $v0, 0x14($s2) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x1318u;
    goto label_1318;
    ctx->pc = 0x12D0u;
label_12d0:
    // 0x12d0: 0x92420030  lbu         $v0, 0x30($s2)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x12d4: 0x0  nop
    // NOP
    // 0x12d8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12D8u;
    {
        const bool branch_taken_0x12d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x12dc: 0xe0a021  addu        $s4, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        if (branch_taken_0x12d8) {
            ctx->pc = 0x12E8u;
            goto label_12e8;
        }
    }
    ctx->pc = 0x12E0u;
    // 0x12e0: 0x80004c6  j           func_001318
    ctx->pc = 0x12E0u;
    // 0x12e4: 0x403821  addu        $a3, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1318u;
    goto label_1318;
    ctx->pc = 0x12E8u;
label_12e8:
    // 0x12e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x12ec: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x12f0: 0x0  nop
    // NOP
    // 0x12f4: 0x10400123  beqz        $v0, . + 4 + (0x123 << 2)
    ctx->pc = 0x12F4u;
    {
        const bool branch_taken_0x12f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x12f8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x12f4) {
            ctx->pc = 0x1784u;
            goto label_1784;
        }
    }
    ctx->pc = 0x12FCu;
    // 0x12fc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1300: 0x2484393c  addiu       $a0, $a0, 0x393C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14652));
    // 0x1304: 0x92460030  lbu         $a2, 0x30($s2)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x1308: 0xc000de5  jal         func_003794
    ctx->pc = 0x1308u;
    SET_GPR_U32(ctx, 31, 0x1310u);
    // 0x130c: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x1308u, 0x1310u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1310u;
label_1310:
    // 0x1310: 0x80005e1  j           func_001784
    ctx->pc = 0x1310u;
    // 0x1314: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1784u;
    goto label_1784;
    ctx->pc = 0x1318u;
label_1318:
    // 0x1318: 0x30e300ff  andi        $v1, $a3, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x131c: 0x2c6200f0  sltiu       $v0, $v1, 0xF0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)240) ? 1 : 0);
    // 0x1320: 0x104000e7  beqz        $v0, . + 4 + (0xE7 << 2)
    ctx->pc = 0x1320u;
    {
        const bool branch_taken_0x1320 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1324: 0x328400ff  andi        $a0, $s4, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x1320) {
            ctx->pc = 0x16C0u;
            goto label_16c0;
        }
    }
    ctx->pc = 0x1328u;
    // 0x1328: 0x41200  sll         $v0, $a0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x132c: 0x628825  or          $s1, $v1, $v0
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1330: 0xa2470030  sb          $a3, 0x30($s2)
    WRITE8(ADD32(GPR_U32(ctx, 18), 48), (uint8_t)GPR_U32(ctx, 7));
    // 0x1334: 0x30e6000f  andi        $a2, $a3, 0xF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x1338: 0x30e300f0  andi        $v1, $a3, 0xF0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)240);
    // 0x133c: 0x240200b0  addiu       $v0, $zero, 0xB0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 176));
    // 0x1340: 0x10620049  beq         $v1, $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x1340u;
    {
        const bool branch_taken_0x1340 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1344: 0xc02821  addu        $a1, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        if (branch_taken_0x1340) {
            ctx->pc = 0x1468u;
            goto label_1468;
        }
    }
    ctx->pc = 0x1348u;
    // 0x1348: 0x286200b1  slti        $v0, $v1, 0xB1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)177) ? 1 : 0);
    // 0x134c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x134Cu;
    {
        const bool branch_taken_0x134c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1350: 0x24020090  addiu       $v0, $zero, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
        if (branch_taken_0x134c) {
            ctx->pc = 0x1388u;
            goto label_1388;
        }
    }
    ctx->pc = 0x1354u;
    // 0x1354: 0x106200b2  beq         $v1, $v0, . + 4 + (0xB2 << 2)
    ctx->pc = 0x1354u;
    {
        const bool branch_taken_0x1354 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1358: 0x28620091  slti        $v0, $v1, 0x91 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)145) ? 1 : 0);
        if (branch_taken_0x1354) {
            ctx->pc = 0x1620u;
            goto label_1620;
        }
    }
    ctx->pc = 0x135Cu;
    // 0x135c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x135Cu;
    {
        const bool branch_taken_0x135c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1360: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        if (branch_taken_0x135c) {
            ctx->pc = 0x1374u;
            goto label_1374;
        }
    }
    ctx->pc = 0x1364u;
    // 0x1364: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1364u;
    {
        const bool branch_taken_0x1364 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1368: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1364) {
            ctx->pc = 0x13D8u;
            goto label_13d8;
        }
    }
    ctx->pc = 0x136Cu;
    // 0x136c: 0x800059a  j           func_001668
    ctx->pc = 0x136Cu;
    ctx->pc = 0x1668u;
    goto label_1668;
    ctx->pc = 0x1374u;
label_1374:
    // 0x1374: 0x240200a0  addiu       $v0, $zero, 0xA0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
    // 0x1378: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1378u;
    {
        const bool branch_taken_0x1378 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1378) {
            ctx->pc = 0x13E0u;
            goto label_13e0;
        }
    }
    ctx->pc = 0x1380u;
    // 0x1380: 0x800059a  j           func_001668
    ctx->pc = 0x1380u;
    ctx->pc = 0x1668u;
    goto label_1668;
    ctx->pc = 0x1388u;
label_1388:
    // 0x1388: 0x240200d0  addiu       $v0, $zero, 0xD0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 208));
    // 0x138c: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x138Cu;
    {
        const bool branch_taken_0x138c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1390: 0x286200d1  slti        $v0, $v1, 0xD1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)209) ? 1 : 0);
        if (branch_taken_0x138c) {
            ctx->pc = 0x13D4u;
            goto label_13d4;
        }
    }
    ctx->pc = 0x1394u;
    // 0x1394: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1394u;
    {
        const bool branch_taken_0x1394 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1398: 0x240200c0  addiu       $v0, $zero, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
        if (branch_taken_0x1394) {
            ctx->pc = 0x13ACu;
            goto label_13ac;
        }
    }
    ctx->pc = 0x139Cu;
    // 0x139c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x139Cu;
    {
        const bool branch_taken_0x139c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x13a0: 0x51040  sll         $v0, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x139c) {
            ctx->pc = 0x13C0u;
            goto label_13c0;
        }
    }
    ctx->pc = 0x13A4u;
    // 0x13a4: 0x800059a  j           func_001668
    ctx->pc = 0x13A4u;
    ctx->pc = 0x1668u;
    goto label_1668;
    ctx->pc = 0x13ACu;
label_13ac:
    // 0x13ac: 0x240200e0  addiu       $v0, $zero, 0xE0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x13b0: 0x1062009b  beq         $v1, $v0, . + 4 + (0x9B << 2)
    ctx->pc = 0x13B0u;
    {
        const bool branch_taken_0x13b0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x13b0) {
            ctx->pc = 0x1620u;
            goto label_1620;
        }
    }
    ctx->pc = 0x13B8u;
    // 0x13b8: 0x800059a  j           func_001668
    ctx->pc = 0x13B8u;
    ctx->pc = 0x1668u;
    goto label_1668;
    ctx->pc = 0x13C0u;
label_13c0:
    // 0x13c0: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x13c4: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x13c8: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x13cc: 0x3283007f  andi        $v1, $s4, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)127);
    // 0x13d0: 0xa043005c  sb          $v1, 0x5C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 92), (uint8_t)GPR_U32(ctx, 3));
label_13d4:
    // 0x13d4: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_13d8:
    // 0x13d8: 0x80005a5  j           func_001694
    ctx->pc = 0x13D8u;
    // 0x13dc: 0x24130002  addiu       $s3, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x13E0u;
label_13e0:
    // 0x13e0: 0x8e44000c  lw          $a0, 0xC($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x13e4: 0x0  nop
    // NOP
    // 0x13e8: 0x10800016  beqz        $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x13E8u;
    {
        const bool branch_taken_0x13e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x13ec: 0x328200f0  andi        $v0, $s4, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)240);
        if (branch_taken_0x13e8) {
            ctx->pc = 0x1444u;
            goto label_1444;
        }
    }
    ctx->pc = 0x13F0u;
    // 0x13f0: 0xc21025  or          $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x13f4: 0x94830002  lhu         $v1, 0x2($a0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x13f8: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x13fc: 0x43182b  sltu        $v1, $v0, $v1
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1400: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1400u;
    {
        const bool branch_taken_0x1400 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x1404: 0x24130003  addiu       $s3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1400) {
            ctx->pc = 0x1438u;
            goto label_1438;
        }
    }
    ctx->pc = 0x1408u;
    // 0x1408: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x140c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1410: 0x90420005  lbu         $v0, 0x5($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 5)));
    // 0x1414: 0x90710004  lbu         $s1, 0x4($v1)
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1418: 0x21200  sll         $v0, $v0, 8
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x141c: 0x2228825  or          $s1, $s1, $v0
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x1420: 0x3282000f  andi        $v0, $s4, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)15);
    // 0x1424: 0x2621004  sllv        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 19) & 0x1F));
    // 0x1428: 0x34420007  ori         $v0, $v0, 0x7
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)7);
    // 0x142c: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1430: 0x800050f  j           func_00143C
    ctx->pc = 0x1430u;
    // 0x1434: 0x2228825  or          $s1, $s1, $v0 (Delay Slot)
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    ctx->pc = 0x143Cu;
    goto label_143c;
    ctx->pc = 0x1438u;
label_1438:
    // 0x1438: 0x9821  addu        $s3, $zero, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_143c:
    // 0x143c: 0x80005a5  j           func_001694
    ctx->pc = 0x143Cu;
    // 0x1440: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1444u;
label_1444:
    // 0x1444: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1448: 0x24130003  addiu       $s3, $zero, 0x3
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x144c: 0x90500000  lbu         $s0, 0x0($v0)
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1450: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1454: 0xae420014  sw          $v0, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x1458: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x145c: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1460: 0x80005a5  j           func_001694
    ctx->pc = 0x1460u;
    // 0x1464: 0x2228825  or          $s1, $s1, $v0 (Delay Slot)
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1468u;
label_1468:
    // 0x1468: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x146c: 0x0  nop
    // NOP
    // 0x1470: 0x90500000  lbu         $s0, 0x0($v0)
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1474: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1478: 0xae420014  sw          $v0, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x147c: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1480: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1484: 0x2228825  or          $s1, $s1, $v0
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x1488: 0x2c820064  sltiu       $v0, $a0, 0x64
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)100) ? 1 : 0);
    // 0x148c: 0x10400081  beqz        $v0, . + 4 + (0x81 << 2)
    ctx->pc = 0x148Cu;
    {
        const bool branch_taken_0x148c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1490: 0x24130003  addiu       $s3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x148c) {
            ctx->pc = 0x1694u;
            goto label_1694;
        }
    }
    ctx->pc = 0x1494u;
    // 0x1494: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1498: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x149c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x14a0: 0x8c223988  lw          $v0, 0x3988($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 14728)));
    // 0x14a4: 0x0  nop
    // NOP
    // 0x14a8: 0x400008  jr          $v0
    ctx->pc = 0x14A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14B0u: goto label_14b0;
            case 0x14CCu: goto label_14cc;
            case 0x14E8u: goto label_14e8;
            case 0x1504u: goto label_1504;
            case 0x1520u: goto label_1520;
            case 0x156Cu: goto label_156c;
            case 0x1588u: goto label_1588;
            case 0x15A4u: goto label_15a4;
            case 0x15C0u: goto label_15c0;
            case 0x15DCu: goto label_15dc;
            case 0x15F8u: goto label_15f8;
            case 0x1694u: goto label_1694;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x14A8u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x14B0u;
label_14b0:
    // 0x14b0: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x14b4: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x14b8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14bc: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x14c0: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x14c4: 0x80005a5  j           func_001694
    ctx->pc = 0x14C4u;
    // 0x14c8: 0xa043005d  sb          $v1, 0x5D($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 93), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x14CCu;
label_14cc:
    // 0x14cc: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x14d0: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x14d4: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14d8: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x14dc: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x14e0: 0x80005a5  j           func_001694
    ctx->pc = 0x14E0u;
    // 0x14e4: 0xa043005e  sb          $v1, 0x5E($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 94), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x14E8u;
label_14e8:
    // 0x14e8: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x14ec: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x14f0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14f4: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x14f8: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x14fc: 0x80005a5  j           func_001694
    ctx->pc = 0x14FCu;
    // 0x1500: 0xa043005f  sb          $v1, 0x5F($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 95), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1504u;
label_1504:
    // 0x1504: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1508: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x150c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1510: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1514: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x1518: 0x80005a5  j           func_001694
    ctx->pc = 0x1518u;
    // 0x151c: 0xa0430060  sb          $v1, 0x60($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 96), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1520u;
label_1520:
    // 0x1520: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1524: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1528: 0x2451021  addu        $v0, $s2, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x152c: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x1530: 0xa043003c  sb          $v1, 0x3C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 60), (uint8_t)GPR_U32(ctx, 3));
    // 0x1534: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1538: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x153c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1540: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1544: 0xc000486  jal         func_001218
    ctx->pc = 0x1544u;
    SET_GPR_U32(ctx, 31, 0x154Cu);
    // 0x1548: 0xa0430061  sb          $v1, 0x61($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 97), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1218u, 0x1544u, 0x154Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x154Cu;
label_154c:
    // 0x154c: 0x32030080  andi        $v1, $s0, 0x80
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)128);
    // 0x1550: 0x628025  or          $s0, $v1, $v0
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1554: 0x3223ffff  andi        $v1, $s1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1558: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x155c: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1560: 0x628825  or          $s1, $v1, $v0
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1564: 0x80005a5  j           func_001694
    ctx->pc = 0x1564u;
    // 0x1568: 0x24130003  addiu       $s3, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x156Cu;
label_156c:
    // 0x156c: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1570: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1574: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1578: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x157c: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x1580: 0x80005a5  j           func_001694
    ctx->pc = 0x1580u;
    // 0x1584: 0xa0430062  sb          $v1, 0x62($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 98), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1588u;
label_1588:
    // 0x1588: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x158c: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1590: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1594: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1598: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x159c: 0x80005a5  j           func_001694
    ctx->pc = 0x159Cu;
    // 0x15a0: 0xa0430063  sb          $v1, 0x63($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 99), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x15A4u;
label_15a4:
    // 0x15a4: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x15a8: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15ac: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x15b0: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x15b4: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x15b8: 0x80005a5  j           func_001694
    ctx->pc = 0x15B8u;
    // 0x15bc: 0xa0430064  sb          $v1, 0x64($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 100), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x15C0u;
label_15c0:
    // 0x15c0: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x15c4: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15c8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x15cc: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x15d0: 0x3203007f  andi        $v1, $s0, 0x7F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x15d4: 0x80005a5  j           func_001694
    ctx->pc = 0x15D4u;
    // 0x15d8: 0xa0430065  sb          $v1, 0x65($v0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 2), 101), (uint8_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x15DCu;
label_15dc:
    // 0x15dc: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x15e0: 0x2a21021  addu        $v0, $s5, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x15e4: 0x3204000f  andi        $a0, $s0, 0xF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)15);
    // 0x15e8: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ec: 0x831804  sllv        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x15f0: 0x80005a5  j           func_001694
    ctx->pc = 0x15F0u;
    // 0x15f4: 0xa4430010  sh          $v1, 0x10($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 16), (uint16_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x15F8u;
label_15f8:
    // 0x15f8: 0x2a02021  addu        $a0, $s5, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x15fc: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1600: 0xe03021  addu        $a2, $a3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1604: 0x328700ff  andi        $a3, $s4, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    // 0x1608: 0x3202007f  andi        $v0, $s0, 0x7F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)127);
    // 0x160c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1610: 0xc0001f1  jal         func_0007C4
    ctx->pc = 0x1610u;
    SET_GPR_U32(ctx, 31, 0x1618u);
    // 0x1614: 0xafb60014  sw          $s6, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 22));
    ctx->pc = 0x7C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7C4u, 0x1610u, 0x1618u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1618u;
label_1618:
    // 0x1618: 0x80005a5  j           func_001694
    ctx->pc = 0x1618u;
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1620u;
label_1620:
    // 0x1620: 0x8e420014  lw          $v0, 0x14($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1624: 0x0  nop
    // NOP
    // 0x1628: 0x90500000  lbu         $s0, 0x0($v0)
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x162c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1630: 0xae420014  sw          $v0, 0x14($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x1634: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1638: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x163c: 0x2228825  or          $s1, $s1, $v0
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x1640: 0x2ce200e0  sltiu       $v0, $a3, 0xE0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
    // 0x1644: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1644u;
    {
        const bool branch_taken_0x1644 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1648: 0x24130003  addiu       $s3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1644) {
            ctx->pc = 0x1694u;
            goto label_1694;
        }
    }
    ctx->pc = 0x164Cu;
    // 0x164c: 0x51040  sll         $v0, $a1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1650: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1654: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1658: 0x2421021  addu        $v0, $s2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x165c: 0x111a02  srl         $v1, $s1, 8
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 17), 8));
    // 0x1660: 0x80005a5  j           func_001694
    ctx->pc = 0x1660u;
    // 0x1664: 0xa4430066  sh          $v1, 0x66($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 102), (uint16_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1694u;
    goto label_1694;
    ctx->pc = 0x1668u;
label_1668:
    // 0x1668: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x166c: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x1670: 0x0  nop
    // NOP
    // 0x1674: 0x10400043  beqz        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1674u;
    {
        const bool branch_taken_0x1674 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1678: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1674) {
            ctx->pc = 0x1784u;
            goto label_1784;
        }
    }
    ctx->pc = 0x167Cu;
    // 0x167c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1680: 0x24843964  addiu       $a0, $a0, 0x3964
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14692));
    // 0x1684: 0xc000de5  jal         func_003794
    ctx->pc = 0x1684u;
    SET_GPR_U32(ctx, 31, 0x168Cu);
    // 0x1688: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x1684u, 0x168Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x168Cu;
label_168c:
    // 0x168c: 0x80005e1  j           func_001784
    ctx->pc = 0x168Cu;
    // 0x1690: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1784u;
    goto label_1784;
    ctx->pc = 0x1694u;
label_1694:
    // 0x1694: 0x12600006  beqz        $s3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1694u;
    {
        const bool branch_taken_0x1694 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0x1698: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x1694) {
            ctx->pc = 0x16B0u;
            goto label_16b0;
        }
    }
    ctx->pc = 0x169Cu;
    // 0x169c: 0xafb30010  sw          $s3, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x16a0: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x16a4: 0x2c03021  addu        $a2, $s6, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    // 0x16a8: 0xc000421  jal         func_001084
    ctx->pc = 0x16A8u;
    SET_GPR_U32(ctx, 31, 0x16B0u);
    // 0x16ac: 0x2203821  addu        $a3, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x16A8u, 0x16B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16B0u;
label_16b0:
    // 0x16b0: 0x2901025  or          $v0, $s4, $s0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 16));
    // 0x16b4: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x16b8: 0x80005d8  j           func_001760
    ctx->pc = 0x16B8u;
    // 0x16bc: 0xa2420031  sb          $v0, 0x31($s2) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 18), 49), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x1760u;
    goto label_1760;
    ctx->pc = 0x16C0u;
label_16c0:
    // 0x16c0: 0x240200f7  addiu       $v0, $zero, 0xF7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 247));
    // 0x16c4: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x16C4u;
    {
        const bool branch_taken_0x16c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16c8: 0xa2400031  sb          $zero, 0x31($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 49), (uint8_t)GPR_U32(ctx, 0));
        if (branch_taken_0x16c4) {
            ctx->pc = 0x1724u;
            goto label_1724;
        }
    }
    ctx->pc = 0x16CCu;
    // 0x16cc: 0x286200f8  slti        $v0, $v1, 0xF8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)248) ? 1 : 0);
    // 0x16d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16D0u;
    {
        const bool branch_taken_0x16d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x16d4: 0x240200f0  addiu       $v0, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        if (branch_taken_0x16d0) {
            ctx->pc = 0x16E8u;
            goto label_16e8;
        }
    }
    ctx->pc = 0x16D8u;
    // 0x16d8: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16D8u;
    {
        const bool branch_taken_0x16d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x16dc: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x16d8) {
            ctx->pc = 0x1710u;
            goto label_1710;
        }
    }
    ctx->pc = 0x16E0u;
    // 0x16e0: 0x80005cd  j           func_001734
    ctx->pc = 0x16E0u;
    ctx->pc = 0x1734u;
    goto label_1734;
    ctx->pc = 0x16E8u;
label_16e8:
    // 0x16e8: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x16ec: 0x14620011  bne         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x16ECu;
    {
        const bool branch_taken_0x16ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x16f0: 0x2a02021  addu        $a0, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        if (branch_taken_0x16ec) {
            ctx->pc = 0x1734u;
            goto label_1734;
        }
    }
    ctx->pc = 0x16F4u;
    // 0x16f4: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x16f8: 0xc00034b  jal         func_000D2C
    ctx->pc = 0x16F8u;
    SET_GPR_U32(ctx, 31, 0x1700u);
    // 0x16fc: 0x328600ff  andi        $a2, $s4, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)255);
    ctx->pc = 0xD2Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xD2Cu, 0x16F8u, 0x1700u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1700u;
label_1700:
    // 0x1700: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1700u;
    {
        const bool branch_taken_0x1700 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1704: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1700) {
            ctx->pc = 0x1760u;
            goto label_1760;
        }
    }
    ctx->pc = 0x1708u;
    // 0x1708: 0x80005e1  j           func_001784
    ctx->pc = 0x1708u;
    ctx->pc = 0x1784u;
    goto label_1784;
    ctx->pc = 0x1710u;
label_1710:
    // 0x1710: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1714: 0xc0003b9  jal         func_000EE4
    ctx->pc = 0x1714u;
    SET_GPR_U32(ctx, 31, 0x171Cu);
    // 0x1718: 0x2c03021  addu        $a2, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0xEE4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEE4u, 0x1714u, 0x171Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x171Cu;
label_171c:
    // 0x171c: 0x80005d8  j           func_001760
    ctx->pc = 0x171Cu;
    ctx->pc = 0x1760u;
    goto label_1760;
    ctx->pc = 0x1724u;
label_1724:
    // 0x1724: 0xc00033a  jal         func_000CE8
    ctx->pc = 0x1724u;
    SET_GPR_U32(ctx, 31, 0x172Cu);
    // 0x1728: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0xCE8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xCE8u, 0x1724u, 0x172Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x172Cu;
label_172c:
    // 0x172c: 0x80005d8  j           func_001760
    ctx->pc = 0x172Cu;
    ctx->pc = 0x1760u;
    goto label_1760;
    ctx->pc = 0x1734u;
label_1734:
    // 0x1734: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1738: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x173c: 0x0  nop
    // NOP
    // 0x1740: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1740u;
    {
        const bool branch_taken_0x1740 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1744: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1740) {
            ctx->pc = 0x1784u;
            goto label_1784;
        }
    }
    ctx->pc = 0x1748u;
    // 0x1748: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x174c: 0x24843964  addiu       $a0, $a0, 0x3964
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14692));
    // 0x1750: 0xc000de5  jal         func_003794
    ctx->pc = 0x1750u;
    SET_GPR_U32(ctx, 31, 0x1758u);
    // 0x1754: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x1750u, 0x1758u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1758u;
label_1758:
    // 0x1758: 0x80005e1  j           func_001784
    ctx->pc = 0x1758u;
    // 0x175c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1784u;
    goto label_1784;
    ctx->pc = 0x1760u;
label_1760:
    // 0x1760: 0xc000324  jal         func_000C90
    ctx->pc = 0x1760u;
    SET_GPR_U32(ctx, 31, 0x1768u);
    // 0x1764: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0xC90u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC90u, 0x1760u, 0x1768u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1768u;
label_1768:
    // 0x1768: 0x8e430018  lw          $v1, 0x18($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x176c: 0x8ea20008  lw          $v0, 0x8($s5)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x1770: 0x0  nop
    // NOP
    // 0x1774: 0x43102b  sltu        $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1778: 0x1040feca  beqz        $v0, . + 4 + (-0x136 << 2)
    ctx->pc = 0x1778u;
    {
        const bool branch_taken_0x1778 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1778) {
            ctx->pc = 0x12A4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12a4;
        }
    }
    ctx->pc = 0x1780u;
label_1780:
    // 0x1780: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1784:
    // 0x1784: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1788: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178c: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1790: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1794: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1798: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x179c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x17a0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a4: 0x3e00008  jr          $ra
    ctx->pc = 0x17A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x17a8: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x17A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x17ACu;
}


// Function: modmidi_000017ac
// Address: 0x17ac - 0x1860
void modmidi_000017ac_0x17ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000017ac_0x17ac");
#endif

    switch (ctx->pc) {
        case 0x17dcu: goto label_17dc;
        case 0x1814u: goto label_1814;
        case 0x182cu: goto label_182c;
        default: break;
    }

    ctx->pc = 0x17acu;

    // 0x17ac: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17b0: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x17b4: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x17b8: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x17bc: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x17c0: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x17c4: 0x2651005c  addiu       $s1, $s2, 0x5C
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 92));
    // 0x17c8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x17cc: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x17d0: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x17d4: 0x24130003  addiu       $s3, $zero, 0x3
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x17d8: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_17dc:
    // 0x17dc: 0x101040  sll         $v0, $s0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x17e0: 0x9623003a  lhu         $v1, 0x3A($s1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 58)));
    // 0x17e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x17e8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x17ec: 0x94223e90  lhu         $v0, 0x3E90($at)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 16016)));
    // 0x17f0: 0x0  nop
    // NOP
    // 0x17f4: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x17f8: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x17F8u;
    {
        const bool branch_taken_0x17f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x17fc: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x17f8) {
            ctx->pc = 0x182Cu;
            goto label_182c;
        }
    }
    ctx->pc = 0x1800u;
    // 0x1800: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1804: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1808: 0x360740b0  ori         $a3, $s0, 0x40B0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)16560);
    // 0x180c: 0xc000421  jal         func_001084
    ctx->pc = 0x180Cu;
    SET_GPR_U32(ctx, 31, 0x1814u);
    // 0x1810: 0xafb30010  sw          $s3, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x180Cu, 0x1814u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1814u;
label_1814:
    // 0x1814: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1818: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x181c: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1820: 0x36077bb0  ori         $a3, $s0, 0x7BB0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)31664);
    // 0x1824: 0xc000421  jal         func_001084
    ctx->pc = 0x1824u;
    SET_GPR_U32(ctx, 31, 0x182Cu);
    // 0x1828: 0xafb30010  sw          $s3, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1824u, 0x182Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x182Cu;
label_182c:
    // 0x182c: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1830: 0x2e020010  sltiu       $v0, $s0, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1834: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1834u;
    {
        const bool branch_taken_0x1834 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1834) {
            ctx->pc = 0x17DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17dc;
        }
    }
    ctx->pc = 0x183Cu;
    // 0x183c: 0xa620003a  sh          $zero, 0x3A($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 58), (uint16_t)GPR_U32(ctx, 0));
    // 0x1840: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1844: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1848: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x184c: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1850: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1854: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1858: 0x3e00008  jr          $ra
    ctx->pc = 0x1858u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x185c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
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


// Function: modmidi_00001860
// Address: 0x1860 - 0x1910
void modmidi_00001860_0x1860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001860_0x1860");
#endif

    switch (ctx->pc) {
        case 0x1898u: goto label_1898;
        case 0x18a4u: goto label_18a4;
        case 0x18f0u: goto label_18f0;
        default: break;
    }

    ctx->pc = 0x1860u;

    // 0x1860: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1864: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1868: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x186c: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1870: 0x2632005c  addiu       $s2, $s1, 0x5C
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 92));
    // 0x1874: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x1878: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x187c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1880: 0x8e43001c  lw          $v1, 0x1C($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x1884: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1888: 0x8c423ed0  lw          $v0, 0x3ED0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16080)));
    // 0x188c: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1890: 0x628021  addu        $s0, $v1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1894: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_1898:
    // 0x1898: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x189c: 0xc000498  jal         func_001260
    ctx->pc = 0x189Cu;
    SET_GPR_U32(ctx, 31, 0x18A4u);
    // 0x18a0: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x1260u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1260u, 0x189Cu, 0x18A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18A4u;
label_18a4:
    // 0x18a4: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x18A4u;
    {
        const bool branch_taken_0x18a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x18a8: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x18a4) {
            ctx->pc = 0x18D4u;
            goto label_18d4;
        }
    }
    ctx->pc = 0x18ACu;
    // 0x18ac: 0x8e430020  lw          $v1, 0x20($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x18b0: 0x0  nop
    // NOP
    // 0x18b4: 0x203102b  sltu        $v0, $s0, $v1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x18b8: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x18B8u;
    {
        const bool branch_taken_0x18b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18b8) {
            ctx->pc = 0x18F0u;
            goto label_18f0;
        }
    }
    ctx->pc = 0x18C0u;
    // 0x18c0: 0x8e220008  lw          $v0, 0x8($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x18c4: 0x2038023  subu        $s0, $s0, $v1
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x18c8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18cc: 0x8000626  j           func_001898
    ctx->pc = 0x18CCu;
    // 0x18d0: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x1898u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1898;
    ctx->pc = 0x18D4u;
label_18d4:
    // 0x18d4: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x18d8: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x18dc: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x18e0: 0x2403fffd  addiu       $v1, $zero, -0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x18e4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x18e8: 0xc0005eb  jal         func_0017AC
    ctx->pc = 0x18E8u;
    SET_GPR_U32(ctx, 31, 0x18F0u);
    // 0x18ec: 0xac82000c  sw          $v0, 0xC($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    ctx->pc = 0x17ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x17ACu, 0x18E8u, 0x18F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18F0u;
label_18f0:
    // 0x18f0: 0xae50001c  sw          $s0, 0x1C($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 16));
    // 0x18f4: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18f8: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x18fc: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1900: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1904: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1908: 0x3e00008  jr          $ra
    ctx->pc = 0x1908u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x190c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1908u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1910u;
}


// Function: modmidi_00001910
// Address: 0x1910 - 0x1bb4
void modmidi_00001910_0x1910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001910_0x1910");
#endif

    switch (ctx->pc) {
        case 0x1948u: goto label_1948;
        case 0x197cu: goto label_197c;
        case 0x19b4u: goto label_19b4;
        case 0x19e8u: goto label_19e8;
        case 0x1a1cu: goto label_1a1c;
        case 0x1a50u: goto label_1a50;
        case 0x1a7cu: goto label_1a7c;
        case 0x1ab0u: goto label_1ab0;
        case 0x1ae4u: goto label_1ae4;
        case 0x1b18u: goto label_1b18;
        case 0x1b4cu: goto label_1b4c;
        case 0x1b80u: goto label_1b80;
        default: break;
    }

    ctx->pc = 0x1910u;

    // 0x1910: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1914: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x1918: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x191c: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x1920: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1924: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1928: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x192c: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x1930: 0x24150003  addiu       $s5, $zero, 0x3
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1934: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1938: 0x2672005c  addiu       $s2, $s3, 0x5C
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), 92));
    // 0x193c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1940: 0x2408021  addu        $s0, $s2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1944: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
label_1948:
    // 0x1948: 0x9202005d  lbu         $v0, 0x5D($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 93)));
    // 0x194c: 0x0  nop
    // NOP
    // 0x1950: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1954: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1954u;
    {
        const bool branch_taken_0x1954 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1958: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1954) {
            ctx->pc = 0x197Cu;
            goto label_197c;
        }
    }
    ctx->pc = 0x195Cu;
    // 0x195c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1960: 0x9207005d  lbu         $a3, 0x5D($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 93)));
    // 0x1964: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1968: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x196c: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1970: 0x34e700b0  ori         $a3, $a3, 0xB0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)176);
    // 0x1974: 0xc000421  jal         func_001084
    ctx->pc = 0x1974u;
    SET_GPR_U32(ctx, 31, 0x197Cu);
    // 0x1978: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1974u, 0x197Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x197Cu;
label_197c:
    // 0x197c: 0x9202005c  lbu         $v0, 0x5C($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x1980: 0x0  nop
    // NOP
    // 0x1984: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1988: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1988u;
    {
        const bool branch_taken_0x1988 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x198c: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1988) {
            ctx->pc = 0x19B4u;
            goto label_19b4;
        }
    }
    ctx->pc = 0x1990u;
    // 0x1990: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1994: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1998: 0x9207005c  lbu         $a3, 0x5C($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 92)));
    // 0x199c: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19a0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x19a4: 0x73a00  sll         $a3, $a3, 8
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x19a8: 0x34e700c0  ori         $a3, $a3, 0xC0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)192);
    // 0x19ac: 0xc000421  jal         func_001084
    ctx->pc = 0x19ACu;
    SET_GPR_U32(ctx, 31, 0x19B4u);
    // 0x19b0: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x19ACu, 0x19B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19B4u;
label_19b4:
    // 0x19b4: 0x9202005e  lbu         $v0, 0x5E($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 94)));
    // 0x19b8: 0x0  nop
    // NOP
    // 0x19bc: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x19c0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x19C0u;
    {
        const bool branch_taken_0x19c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x19c4: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x19c0) {
            ctx->pc = 0x19E8u;
            goto label_19e8;
        }
    }
    ctx->pc = 0x19C8u;
    // 0x19c8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x19cc: 0x9207005e  lbu         $a3, 0x5E($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 94)));
    // 0x19d0: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x19d4: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x19d8: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x19dc: 0x34e701b0  ori         $a3, $a3, 0x1B0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)432);
    // 0x19e0: 0xc000421  jal         func_001084
    ctx->pc = 0x19E0u;
    SET_GPR_U32(ctx, 31, 0x19E8u);
    // 0x19e4: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x19E0u, 0x19E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19E8u;
label_19e8:
    // 0x19e8: 0x9202005f  lbu         $v0, 0x5F($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 95)));
    // 0x19ec: 0x0  nop
    // NOP
    // 0x19f0: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x19f4: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x19F4u;
    {
        const bool branch_taken_0x19f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x19f8: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x19f4) {
            ctx->pc = 0x1A1Cu;
            goto label_1a1c;
        }
    }
    ctx->pc = 0x19FCu;
    // 0x19fc: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1a00: 0x9207005f  lbu         $a3, 0x5F($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 95)));
    // 0x1a04: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1a08: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1a0c: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1a10: 0x34e702b0  ori         $a3, $a3, 0x2B0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)688);
    // 0x1a14: 0xc000421  jal         func_001084
    ctx->pc = 0x1A14u;
    SET_GPR_U32(ctx, 31, 0x1A1Cu);
    // 0x1a18: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1A14u, 0x1A1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A1Cu;
label_1a1c:
    // 0x1a1c: 0x92020060  lbu         $v0, 0x60($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1a20: 0x0  nop
    // NOP
    // 0x1a24: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1a28: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A28u;
    {
        const bool branch_taken_0x1a28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1a2c: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1a28) {
            ctx->pc = 0x1A50u;
            goto label_1a50;
        }
    }
    ctx->pc = 0x1A30u;
    // 0x1a30: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1a34: 0x92070060  lbu         $a3, 0x60($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1a38: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1a3c: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1a40: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1a44: 0x34e705b0  ori         $a3, $a3, 0x5B0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1456);
    // 0x1a48: 0xc000421  jal         func_001084
    ctx->pc = 0x1A48u;
    SET_GPR_U32(ctx, 31, 0x1A50u);
    // 0x1a4c: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1A48u, 0x1A50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A50u;
label_1a50:
    // 0x1a50: 0x92030061  lbu         $v1, 0x61($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 97)));
    // 0x1a54: 0x0  nop
    // NOP
    // 0x1a58: 0x30620080  andi        $v0, $v1, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)128);
    // 0x1a5c: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A5Cu;
    {
        const bool branch_taken_0x1a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1a60: 0x2511021  addu        $v0, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        if (branch_taken_0x1a5c) {
            ctx->pc = 0x1A7Cu;
            goto label_1a7c;
        }
    }
    ctx->pc = 0x1A64u;
    // 0x1a64: 0xa043003c  sb          $v1, 0x3C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 60), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a68: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x1a6c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1a70: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1a74: 0xc0007fb  jal         func_001FEC
    ctx->pc = 0x1A74u;
    SET_GPR_U32(ctx, 31, 0x1A7Cu);
    // 0x1a78: 0x2203821  addu        $a3, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x1FECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1FECu, 0x1A74u, 0x1A7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A7Cu;
label_1a7c:
    // 0x1a7c: 0x92020062  lbu         $v0, 0x62($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 98)));
    // 0x1a80: 0x0  nop
    // NOP
    // 0x1a84: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1a88: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A88u;
    {
        const bool branch_taken_0x1a88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1a8c: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1a88) {
            ctx->pc = 0x1AB0u;
            goto label_1ab0;
        }
    }
    ctx->pc = 0x1A90u;
    // 0x1a90: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1a94: 0x92070062  lbu         $a3, 0x62($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 98)));
    // 0x1a98: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1a9c: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1aa0: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1aa4: 0x34e70ab0  ori         $a3, $a3, 0xAB0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)2736);
    // 0x1aa8: 0xc000421  jal         func_001084
    ctx->pc = 0x1AA8u;
    SET_GPR_U32(ctx, 31, 0x1AB0u);
    // 0x1aac: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1AA8u, 0x1AB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AB0u;
label_1ab0:
    // 0x1ab0: 0x92020063  lbu         $v0, 0x63($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 99)));
    // 0x1ab4: 0x0  nop
    // NOP
    // 0x1ab8: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1abc: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1ABCu;
    {
        const bool branch_taken_0x1abc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1ac0: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1abc) {
            ctx->pc = 0x1AE4u;
            goto label_1ae4;
        }
    }
    ctx->pc = 0x1AC4u;
    // 0x1ac4: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1ac8: 0x92070063  lbu         $a3, 0x63($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 99)));
    // 0x1acc: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1ad0: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1ad4: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1ad8: 0x34e70bb0  ori         $a3, $a3, 0xBB0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)2992);
    // 0x1adc: 0xc000421  jal         func_001084
    ctx->pc = 0x1ADCu;
    SET_GPR_U32(ctx, 31, 0x1AE4u);
    // 0x1ae0: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1ADCu, 0x1AE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AE4u;
label_1ae4:
    // 0x1ae4: 0x92020064  lbu         $v0, 0x64($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1ae8: 0x0  nop
    // NOP
    // 0x1aec: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1af0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AF0u;
    {
        const bool branch_taken_0x1af0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1af4: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1af0) {
            ctx->pc = 0x1B18u;
            goto label_1b18;
        }
    }
    ctx->pc = 0x1AF8u;
    // 0x1af8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1afc: 0x92070064  lbu         $a3, 0x64($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b00: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1b04: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1b08: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1b0c: 0x34e740b0  ori         $a3, $a3, 0x40B0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)16560);
    // 0x1b10: 0xc000421  jal         func_001084
    ctx->pc = 0x1B10u;
    SET_GPR_U32(ctx, 31, 0x1B18u);
    // 0x1b14: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1B10u, 0x1B18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B18u;
label_1b18:
    // 0x1b18: 0x92020065  lbu         $v0, 0x65($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 101)));
    // 0x1b1c: 0x0  nop
    // NOP
    // 0x1b20: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1b24: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B24u;
    {
        const bool branch_taken_0x1b24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1b28: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b24) {
            ctx->pc = 0x1B4Cu;
            goto label_1b4c;
        }
    }
    ctx->pc = 0x1B2Cu;
    // 0x1b2c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1b30: 0x92070065  lbu         $a3, 0x65($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 101)));
    // 0x1b34: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1b38: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1b3c: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1b40: 0x34e741b0  ori         $a3, $a3, 0x41B0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)16816);
    // 0x1b44: 0xc000421  jal         func_001084
    ctx->pc = 0x1B44u;
    SET_GPR_U32(ctx, 31, 0x1B4Cu);
    // 0x1b48: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1B44u, 0x1B4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B4Cu;
label_1b4c:
    // 0x1b4c: 0x96020066  lhu         $v0, 0x66($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 102)));
    // 0x1b50: 0x0  nop
    // NOP
    // 0x1b54: 0x30428080  andi        $v0, $v0, 0x8080
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32896);
    // 0x1b58: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B58u;
    {
        const bool branch_taken_0x1b58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1b5c: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x1b58) {
            ctx->pc = 0x1B80u;
            goto label_1b80;
        }
    }
    ctx->pc = 0x1B60u;
    // 0x1b60: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1b64: 0x96070066  lhu         $a3, 0x66($s0)
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 102)));
    // 0x1b68: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x1b6c: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x1b70: 0x73a00  sll         $a3, $a3, 8
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1b74: 0x34e700e0  ori         $a3, $a3, 0xE0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)224);
    // 0x1b78: 0xc000421  jal         func_001084
    ctx->pc = 0x1B78u;
    SET_GPR_U32(ctx, 31, 0x1B80u);
    // 0x1b7c: 0x2273825  or          $a3, $s1, $a3 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 7));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x1B78u, 0x1B80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B80u;
label_1b80:
    // 0x1b80: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b84: 0x2e220010  sltiu       $v0, $s1, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b88: 0x1440ff6f  bnez        $v0, . + 4 + (-0x91 << 2)
    ctx->pc = 0x1B88u;
    {
        const bool branch_taken_0x1b88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1b8c: 0x2610000c  addiu       $s0, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        if (branch_taken_0x1b88) {
            ctx->pc = 0x1948u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1948;
        }
    }
    ctx->pc = 0x1B90u;
    // 0x1b90: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b94: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1b98: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1b9c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1ba0: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ba4: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1ba8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1bac: 0x3e00008  jr          $ra
    ctx->pc = 0x1BACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1bb0: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1BACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BB4u;
}


// Function: modmidi_00001bb4
// Address: 0x1bb4 - 0x1c90
void modmidi_00001bb4_0x1bb4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001bb4_0x1bb4");
#endif

    switch (ctx->pc) {
        case 0x1c44u: goto label_1c44;
        case 0x1c6cu: goto label_1c6c;
        default: break;
    }

    ctx->pc = 0x1bb4u;

    // 0x1bb4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1bb8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1bbc: 0x1080001d  beqz        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1BBCu;
    {
        const bool branch_taken_0x1bbc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x1bc0: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x1bbc) {
            ctx->pc = 0x1C34u;
            goto label_1c34;
        }
    }
    ctx->pc = 0x1BC4u;
    // 0x1bc4: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bc8: 0x51840  sll         $v1, $a1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1bcc: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1bd0: 0x24650001  addiu       $a1, $v1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bd4: 0xa2102b  sltu        $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1bd8: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1BD8u;
    {
        const bool branch_taken_0x1bd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1bdc: 0x510c0  sll         $v0, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x1bd8) {
            ctx->pc = 0x1C34u;
            goto label_1c34;
        }
    }
    ctx->pc = 0x1BE0u;
    // 0x1be0: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1be4: 0x0  nop
    // NOP
    // 0x1be8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bec: 0x8c500004  lw          $s0, 0x4($v0)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1bf0: 0x0  nop
    // NOP
    // 0x1bf4: 0x12000022  beqz        $s0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1BF4u;
    {
        const bool branch_taken_0x1bf4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x1bf8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1bf4) {
            ctx->pc = 0x1C80u;
            goto label_1c80;
        }
    }
    ctx->pc = 0x1BFCu;
    // 0x1bfc: 0x10c00014  beqz        $a2, . + 4 + (0x14 << 2)
    ctx->pc = 0x1BFCu;
    {
        const bool branch_taken_0x1bfc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x1c00: 0x24850008  addiu       $a1, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        if (branch_taken_0x1bfc) {
            ctx->pc = 0x1C50u;
            goto label_1c50;
        }
    }
    ctx->pc = 0x1C04u;
    // 0x1c04: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c08: 0x14c2001d  bne         $a2, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C08u;
    {
        const bool branch_taken_0x1c08 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        // 0x1c0c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1c08) {
            ctx->pc = 0x1C80u;
            goto label_1c80;
        }
    }
    ctx->pc = 0x1C10u;
    // 0x1c10: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c14: 0x0  nop
    // NOP
    // 0x1c18: 0x30420005  andi        $v0, $v0, 0x5
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)5);
    // 0x1c1c: 0x14460018  bne         $v0, $a2, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C1Cu;
    {
        const bool branch_taken_0x1c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        // 0x1c20: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1c1c) {
            ctx->pc = 0x1C80u;
            goto label_1c80;
        }
    }
    ctx->pc = 0x1C24u;
    // 0x1c24: 0x8e030004  lw          $v1, 0x4($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c28: 0x0  nop
    // NOP
    // 0x1c2c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2Cu;
    {
        const bool branch_taken_0x1c2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c2c) {
            ctx->pc = 0x1C3Cu;
            goto label_1c3c;
        }
    }
    ctx->pc = 0x1C34u;
label_1c34:
    // 0x1c34: 0x8000720  j           func_001C80
    ctx->pc = 0x1C34u;
    // 0x1c38: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1C80u;
    goto label_1c80;
    ctx->pc = 0x1C3Cu;
label_1c3c:
    // 0x1c3c: 0xc000644  jal         func_001910
    ctx->pc = 0x1C3Cu;
    SET_GPR_U32(ctx, 31, 0x1C44u);
    // 0x1c40: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1910u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1910u, 0x1C3Cu, 0x1C44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C44u;
label_1c44:
    // 0x1c44: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c48: 0x800071e  j           func_001C78
    ctx->pc = 0x1C48u;
    // 0x1c4c: 0x34420002  ori         $v0, $v0, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x1C78u;
    goto label_1c78;
    ctx->pc = 0x1C50u;
label_1c50:
    // 0x1c50: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c54: 0x0  nop
    // NOP
    // 0x1c58: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1c5c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C5Cu;
    {
        const bool branch_taken_0x1c5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1c60: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1c5c) {
            ctx->pc = 0x1C80u;
            goto label_1c80;
        }
    }
    ctx->pc = 0x1C64u;
    // 0x1c64: 0xc0005eb  jal         func_0017AC
    ctx->pc = 0x1C64u;
    SET_GPR_U32(ctx, 31, 0x1C6Cu);
    // 0x1c68: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x17ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x17ACu, 0x1C64u, 0x1C6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C6Cu;
label_1c6c:
    // 0x1c6c: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c70: 0x2403fffd  addiu       $v1, $zero, -0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1c74: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_1c78:
    // 0x1c78: 0xae02000c  sw          $v0, 0xC($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x1c7c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1c80:
    // 0x1c80: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1c84: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c88: 0x3e00008  jr          $ra
    ctx->pc = 0x1C88u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c8c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C88u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C90u;
}


// Function: modmidi_00001c90
// Address: 0x1c90 - 0x1d50
void modmidi_00001c90_0x1c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001c90_0x1c90");
#endif

    switch (ctx->pc) {
        case 0x1ce8u: goto label_1ce8;
        case 0x1d34u: goto label_1d34;
        case 0x1d3cu: goto label_1d3c;
        default: break;
    }

    ctx->pc = 0x1c90u;

    // 0x1c90: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1c94: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1c98: 0x2409007f  addiu       $t1, $zero, 0x7F
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1c9c: 0x240600ff  addiu       $a2, $zero, 0xFF
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1ca0: 0x3408ffff  ori         $t0, $zero, 0xFFFF
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1ca4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1ca8: 0x2490005c  addiu       $s0, $a0, 0x5C
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x1cac: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1cb0: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1cb4: 0xac800008  sw          $zero, 0x8($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1cb8: 0x8e030010  lw          $v1, 0x10($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1cbc: 0xc01021  addu        $v0, $a2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1cc0: 0xae000018  sw          $zero, 0x18($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x1cc4: 0xae00001c  sw          $zero, 0x1C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1cc8: 0xae000020  sw          $zero, 0x20($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x1ccc: 0xa2000030  sb          $zero, 0x30($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 48), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cd0: 0xa2000031  sb          $zero, 0x31($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 49), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cd4: 0xa2020034  sb          $v0, 0x34($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 52), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cd8: 0xa2020033  sb          $v0, 0x33($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 51), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cdc: 0xa2020036  sb          $v0, 0x36($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 54), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ce0: 0xa2020035  sb          $v0, 0x35($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 53), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ce4: 0xae030014  sw          $v1, 0x14($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
label_1ce8:
    // 0x1ce8: 0x2071021  addu        $v0, $s0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 7)));
    // 0x1cec: 0xa049003c  sb          $t1, 0x3C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 60), (uint8_t)GPR_U32(ctx, 9));
    // 0x1cf0: 0xa0a6005c  sb          $a2, 0x5C($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 92), (uint8_t)GPR_U32(ctx, 6));
    // 0x1cf4: 0xa0a6005d  sb          $a2, 0x5D($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 93), (uint8_t)GPR_U32(ctx, 6));
    // 0x1cf8: 0xa0a6005e  sb          $a2, 0x5E($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 94), (uint8_t)GPR_U32(ctx, 6));
    // 0x1cfc: 0xa0a6005f  sb          $a2, 0x5F($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 95), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d00: 0xa0a60060  sb          $a2, 0x60($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 96), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d04: 0xa0a60061  sb          $a2, 0x61($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 97), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d08: 0xa0a60062  sb          $a2, 0x62($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 98), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d0c: 0xa0a60063  sb          $a2, 0x63($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 99), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d10: 0xa0a60064  sb          $a2, 0x64($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 100), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d14: 0xa0a60065  sb          $a2, 0x65($a1)
    WRITE8(ADD32(GPR_U32(ctx, 5), 101), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d18: 0xa4a80066  sh          $t0, 0x66($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 102), (uint16_t)GPR_U32(ctx, 8));
    // 0x1d1c: 0x24e70001  addiu       $a3, $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d20: 0x28e20010  slti        $v0, $a3, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1d24: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1D24u;
    {
        const bool branch_taken_0x1d24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1d28: 0x24a5000c  addiu       $a1, $a1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
        if (branch_taken_0x1d24) {
            ctx->pc = 0x1CE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ce8;
        }
    }
    ctx->pc = 0x1D2Cu;
    // 0x1d2c: 0xc000308  jal         func_000C20
    ctx->pc = 0x1D2Cu;
    SET_GPR_U32(ctx, 31, 0x1D34u);
    // 0x1d30: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xC20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC20u, 0x1D2Cu, 0x1D34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D34u;
label_1d34:
    // 0x1d34: 0xc000324  jal         func_000C90
    ctx->pc = 0x1D34u;
    SET_GPR_U32(ctx, 31, 0x1D3Cu);
    // 0x1d38: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xC90u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC90u, 0x1D34u, 0x1D3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D3Cu;
label_1d3c:
    // 0x1d3c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1d40: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d44: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
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


// Function: modmidi_00001d50
// Address: 0x1d50 - 0x1efc
void modmidi_00001d50_0x1d50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001d50_0x1d50");
#endif

    switch (ctx->pc) {
        case 0x1d80u: goto label_1d80;
        case 0x1db0u: goto label_1db0;
        case 0x1e68u: goto label_1e68;
        case 0x1ec8u: goto label_1ec8;
        default: break;
    }

    ctx->pc = 0x1d50u;

    // 0x1d50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d54: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1d58: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1d5c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1d60: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1d64: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x1d68: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1d6c: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d70: 0x27a70014  addiu       $a3, $sp, 0x14
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x1d74: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x1d78: 0xc000985  jal         func_002614
    ctx->pc = 0x1D78u;
    SET_GPR_U32(ctx, 31, 0x1D80u);
    // 0x1d7c: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x1D78u, 0x1D80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D80u;
label_1d80:
    // 0x1d80: 0x10400057  beqz        $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x1D80u;
    {
        const bool branch_taken_0x1d80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1d84: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1d80) {
            ctx->pc = 0x1EE0u;
            goto label_1ee0;
        }
    }
    ctx->pc = 0x1D88u;
    // 0x1d88: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8c: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1d90: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1d94: 0x8c700004  lw          $s0, 0x4($v1)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d98: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x1d9c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9Cu;
    {
        const bool branch_taken_0x1d9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1da0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1d9c) {
            ctx->pc = 0x1DB0u;
            goto label_1db0;
        }
    }
    ctx->pc = 0x1DA4u;
    // 0x1da4: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1da8: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x1DA8u;
    SET_GPR_U32(ctx, 31, 0x1DB0u);
    // 0x1dac: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x1DA8u, 0x1DB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DB0u;
label_1db0:
    // 0x1db0: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db4: 0x0  nop
    // NOP
    // 0x1db8: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1dbc: 0x2403fff9  addiu       $v1, $zero, -0x7
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967289));
    // 0x1dc0: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1dc4: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dc8: 0xac82000c  sw          $v0, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x1dcc: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1dd0: 0x10400042  beqz        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x1DD0u;
    {
        const bool branch_taken_0x1dd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1dd4: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        if (branch_taken_0x1dd0) {
            ctx->pc = 0x1EDCu;
            goto label_1edc;
        }
    }
    ctx->pc = 0x1DD8u;
    // 0x1dd8: 0x12000041  beqz        $s0, . + 4 + (0x41 << 2)
    ctx->pc = 0x1DD8u;
    {
        const bool branch_taken_0x1dd8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x1ddc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1dd8) {
            ctx->pc = 0x1EE0u;
            goto label_1ee0;
        }
    }
    ctx->pc = 0x1DE0u;
    // 0x1de0: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1de4: 0x0  nop
    // NOP
    // 0x1de8: 0x53102b  sltu        $v0, $v0, $s3
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x1dec: 0x1440003c  bnez        $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x1DECu;
    {
        const bool branch_taken_0x1dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1df0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1dec) {
            ctx->pc = 0x1EE0u;
            goto label_1ee0;
        }
    }
    ctx->pc = 0x1DF4u;
    // 0x1df4: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x1df8: 0x2021021  addu        $v0, $s0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1dfc: 0x8c420010  lw          $v0, 0x10($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1e00: 0x0  nop
    // NOP
    // 0x1e04: 0x10430035  beq         $v0, $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0x1E04u;
    {
        const bool branch_taken_0x1e04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        // 0x1e08: 0x2023821  addu        $a3, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        if (branch_taken_0x1e04) {
            ctx->pc = 0x1EDCu;
            goto label_1edc;
        }
    }
    ctx->pc = 0x1E0Cu;
    // 0x1e0c: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1e10: 0x24e40006  addiu       $a0, $a3, 0x6
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 6));
    // 0x1e14: 0xac44000c  sw          $a0, 0xC($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x1e18: 0x8ce50000  lw          $a1, 0x0($a3)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1e1c: 0x0  nop
    // NOP
    // 0x1e20: 0x10a3002e  beq         $a1, $v1, . + 4 + (0x2E << 2)
    ctx->pc = 0x1E20u;
    {
        const bool branch_taken_0x1e20 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        // 0x1e24: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x1e20) {
            ctx->pc = 0x1EDCu;
            goto label_1edc;
        }
    }
    ctx->pc = 0x1E28u;
    // 0x1e28: 0x94e30006  lhu         $v1, 0x6($a3)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 6)));
    // 0x1e2c: 0x0  nop
    // NOP
    // 0x1e30: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1E30u;
    {
        const bool branch_taken_0x1e30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e30) {
            ctx->pc = 0x1E50u;
            goto label_1e50;
        }
    }
    ctx->pc = 0x1E38u;
    // 0x1e38: 0x94820002  lhu         $v0, 0x2($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1e3c: 0x0  nop
    // NOP
    // 0x1e40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E40u;
    {
        const bool branch_taken_0x1e40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1e44: 0x2ca2000c  sltiu       $v0, $a1, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)12) ? 1 : 0);
        if (branch_taken_0x1e40) {
            ctx->pc = 0x1E50u;
            goto label_1e50;
        }
    }
    ctx->pc = 0x1E48u;
    // 0x1e48: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1E48u;
    {
        const bool branch_taken_0x1e48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1e4c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1e48) {
            ctx->pc = 0x1E60u;
            goto label_1e60;
        }
    }
    ctx->pc = 0x1E50u;
label_1e50:
    // 0x1e50: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1e54: 0x0  nop
    // NOP
    // 0x1e58: 0xac40000c  sw          $zero, 0xC($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x1e5c: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1e60:
    // 0x1e60: 0x240500ff  addiu       $a1, $zero, 0xFF
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1e64: 0x801821  addu        $v1, $a0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1e68:
    // 0x1e68: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1e6c: 0x0  nop
    // NOP
    // 0x1e70: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e74: 0xa0450178  sb          $a1, 0x178($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 376), (uint8_t)GPR_U32(ctx, 5));
    // 0x1e78: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1e7c: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1e80: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e84: 0xa0450179  sb          $a1, 0x179($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 377), (uint8_t)GPR_U32(ctx, 5));
    // 0x1e88: 0x28820008  slti        $v0, $a0, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1e8c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1E8Cu;
    {
        const bool branch_taken_0x1e8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1e90: 0x2463000c  addiu       $v1, $v1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 12));
        if (branch_taken_0x1e8c) {
            ctx->pc = 0x1E68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e68;
        }
    }
    ctx->pc = 0x1E94u;
    // 0x1e94: 0x3c060007  lui         $a2, 0x7
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)7 << 16));
    // 0x1e98: 0x34c6a120  ori         $a2, $a2, 0xA120
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)41248);
    // 0x1e9c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ea0: 0x8ce20000  lw          $v0, 0x0($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1ea4: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1ea8: 0xe21021  addu        $v0, $a3, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1eac: 0xac620010  sw          $v0, 0x10($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1eb0: 0x94e50004  lhu         $a1, 0x4($a3)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1eb4: 0x24020100  addiu       $v0, $zero, 0x100
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1eb8: 0xac660028  sw          $a2, 0x28($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 40), GPR_U32(ctx, 6));
    // 0x1ebc: 0xac62002c  sw          $v0, 0x2C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 44), GPR_U32(ctx, 2));
    // 0x1ec0: 0xc000724  jal         func_001C90
    ctx->pc = 0x1EC0u;
    SET_GPR_U32(ctx, 31, 0x1EC8u);
    // 0x1ec4: 0xac650024  sw          $a1, 0x24($v1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 3), 36), GPR_U32(ctx, 5));
    ctx->pc = 0x1C90u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C90u, 0x1EC0u, 0x1EC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EC8u;
label_1ec8:
    // 0x1ec8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1EC8u;
    {
        const bool branch_taken_0x1ec8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ecc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1ec8) {
            ctx->pc = 0x1EDCu;
            goto label_1edc;
        }
    }
    ctx->pc = 0x1ED0u;
    // 0x1ed0: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ed4: 0x80007b8  j           func_001EE0
    ctx->pc = 0x1ED4u;
    // 0x1ed8: 0xac730004  sw          $s3, 0x4($v1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 19));
    ctx->pc = 0x1EE0u;
    goto label_1ee0;
    ctx->pc = 0x1EDCu;
label_1edc:
    // 0x1edc: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1ee0:
    // 0x1ee0: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1ee4: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1ee8: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1eec: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1ef0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1ef4: 0x3e00008  jr          $ra
    ctx->pc = 0x1EF4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ef8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1EF4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1EFCu;
}


// Function: modmidi_00001efc
// Address: 0x1efc - 0x1fec
void modmidi_00001efc_0x1efc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001efc_0x1efc");
#endif

    switch (ctx->pc) {
        case 0x1f18u: goto label_1f18;
        case 0x1f44u: goto label_1f44;
        case 0x1f54u: goto label_1f54;
        case 0x1f5cu: goto label_1f5c;
        case 0x1f98u: goto label_1f98;
        default: break;
    }

    ctx->pc = 0x1efcu;

    // 0x1efc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f00: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1f04: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1f08: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f0c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1f10: 0xc000985  jal         func_002614
    ctx->pc = 0x1F10u;
    SET_GPR_U32(ctx, 31, 0x1F18u);
    // 0x1f14: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x1F10u, 0x1F18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F18u;
label_1f18:
    // 0x1f18: 0x10400030  beqz        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1F18u;
    {
        const bool branch_taken_0x1f18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f1c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1f18) {
            ctx->pc = 0x1FDCu;
            goto label_1fdc;
        }
    }
    ctx->pc = 0x1F20u;
    // 0x1f20: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f24: 0x0  nop
    // NOP
    // 0x1f28: 0x8c820008  lw          $v0, 0x8($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1f2c: 0x0  nop
    // NOP
    // 0x1f30: 0x202102b  sltu        $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f34: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1F34u;
    {
        const bool branch_taken_0x1f34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f34) {
            ctx->pc = 0x1FA0u;
            goto label_1fa0;
        }
    }
    ctx->pc = 0x1F3Cu;
    // 0x1f3c: 0xc000724  jal         func_001C90
    ctx->pc = 0x1F3Cu;
    SET_GPR_U32(ctx, 31, 0x1F44u);
    ctx->pc = 0x1C90u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C90u, 0x1F3Cu, 0x1F44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F44u;
label_1f44:
    // 0x1f44: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1F44u;
    {
        const bool branch_taken_0x1f44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1f48: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1f44) {
            ctx->pc = 0x1FA0u;
            goto label_1fa0;
        }
    }
    ctx->pc = 0x1F4Cu;
    // 0x1f4c: 0x80007f7  j           func_001FDC
    ctx->pc = 0x1F4Cu;
    ctx->pc = 0x1FDCu;
    goto label_1fdc;
    ctx->pc = 0x1F54u;
label_1f54:
    // 0x1f54: 0x80007ef  j           func_001FBC
    ctx->pc = 0x1F54u;
    // 0x1f58: 0xacf00008  sw          $s0, 0x8($a3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 7), 8), GPR_U32(ctx, 16));
    ctx->pc = 0x1FBCu;
    goto label_1fbc;
    ctx->pc = 0x1F5Cu;
label_1f5c:
    // 0x1f5c: 0x8ce2000c  lw          $v0, 0xC($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x1f60: 0x0  nop
    // NOP
    // 0x1f64: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x1f68: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1F68u;
    {
        const bool branch_taken_0x1f68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1f6c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1f68) {
            ctx->pc = 0x1FDCu;
            goto label_1fdc;
        }
    }
    ctx->pc = 0x1F70u;
    // 0x1f70: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1f74: 0x0  nop
    // NOP
    // 0x1f78: 0x8ca30018  lw          $v1, 0x18($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x1f7c: 0x0  nop
    // NOP
    // 0x1f80: 0x70102b  sltu        $v0, $v1, $s0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1f84: 0x1040fff3  beqz        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1F84u;
    {
        const bool branch_taken_0x1f84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f88: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1f84) {
            ctx->pc = 0x1F54u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f54;
        }
    }
    ctx->pc = 0x1F8Cu;
    // 0x1f8c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f90: 0xc000498  jal         func_001260
    ctx->pc = 0x1F90u;
    SET_GPR_U32(ctx, 31, 0x1F98u);
    // 0x1f94: 0xace30008  sw          $v1, 0x8($a3) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 7), 8), GPR_U32(ctx, 3));
    ctx->pc = 0x1260u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1260u, 0x1F90u, 0x1F98u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F98u;
label_1f98:
    // 0x1f98: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F98u;
    {
        const bool branch_taken_0x1f98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f98) {
            ctx->pc = 0x1FBCu;
            goto label_1fbc;
        }
    }
    ctx->pc = 0x1FA0u;
label_1fa0:
    // 0x1fa0: 0x8fa70010  lw          $a3, 0x10($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1fa4: 0x0  nop
    // NOP
    // 0x1fa8: 0x8ce20008  lw          $v0, 0x8($a3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1fac: 0x0  nop
    // NOP
    // 0x1fb0: 0x50102b  sltu        $v0, $v0, $s0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1fb4: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1FB4u;
    {
        const bool branch_taken_0x1fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1fb4) {
            ctx->pc = 0x1F5Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f5c;
        }
    }
    ctx->pc = 0x1FBCu;
label_1fbc:
    // 0x1fbc: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1fc0: 0x0  nop
    // NOP
    // 0x1fc4: 0x8c420008  lw          $v0, 0x8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1fc8: 0x0  nop
    // NOP
    // 0x1fcc: 0x10500002  beq         $v0, $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1FCCu;
    {
        const bool branch_taken_0x1fcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        // 0x1fd0: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1fcc) {
            ctx->pc = 0x1FD8u;
            goto label_1fd8;
        }
    }
    ctx->pc = 0x1FD4u;
    // 0x1fd4: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1fd8:
    // 0x1fd8: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1fdc:
    // 0x1fdc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1fe0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1fe4: 0x3e00008  jr          $ra
    ctx->pc = 0x1FE4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1fe8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1FE4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1FECu;
}


// Function: modmidi_00001fec
// Address: 0x1fec - 0x2064
void modmidi_00001fec_0x1fec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00001fec_0x1fec");
#endif

    switch (ctx->pc) {
        case 0x2020u: goto label_2020;
        case 0x2044u: goto label_2044;
        default: break;
    }

    ctx->pc = 0x1fecu;

    // 0x1fec: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ff0: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1ff4: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1ff8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1ffc: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2000: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x2004: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2008: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x200c: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2010: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2014: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x2018: 0xc000486  jal         func_001218
    ctx->pc = 0x2018u;
    SET_GPR_U32(ctx, 31, 0x2020u);
    // 0x201c: 0x322500ff  andi        $a1, $s1, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x1218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1218u, 0x2018u, 0x2020u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2020u;
label_2020:
    // 0x2020: 0x24030003  addiu       $v1, $zero, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x2024: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2028: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x202c: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x2030: 0x344207b0  ori         $v0, $v0, 0x7B0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1968);
    // 0x2034: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2038: 0x2223825  or          $a3, $s1, $v0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x203c: 0xc000421  jal         func_001084
    ctx->pc = 0x203Cu;
    SET_GPR_U32(ctx, 31, 0x2044u);
    // 0x2040: 0xafa30010  sw          $v1, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x203Cu, 0x2044u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2044u;
label_2044:
    // 0x2044: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2048: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x204c: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2050: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2054: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2058: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x205c: 0x3e00008  jr          $ra
    ctx->pc = 0x205Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2060: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x205Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2064u;
}


// Function: modmidi_00002064
// Address: 0x2064 - 0x2154
void modmidi_00002064_0x2064(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002064_0x2064");
#endif

    switch (ctx->pc) {
        case 0x2090u: goto label_2090;
        case 0x20d8u: goto label_20d8;
        case 0x2114u: goto label_2114;
        case 0x2128u: goto label_2128;
        default: break;
    }

    ctx->pc = 0x2064u;

    // 0x2064: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x2068: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x206c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2070: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2074: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2078: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x207c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x2080: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2084: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x2088: 0xc000985  jal         func_002614
    ctx->pc = 0x2088u;
    SET_GPR_U32(ctx, 31, 0x2090u);
    // 0x208c: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x2088u, 0x2090u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2090u;
label_2090:
    // 0x2090: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2090u;
    {
        const bool branch_taken_0x2090 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2094: 0x320700ff  andi        $a3, $s0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x2090) {
            ctx->pc = 0x20A0u;
            goto label_20a0;
        }
    }
    ctx->pc = 0x2098u;
    // 0x2098: 0x800084f  j           func_00213C
    ctx->pc = 0x2098u;
    // 0x209c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x213Cu;
    goto label_213c;
    ctx->pc = 0x20A0u;
label_20a0:
    // 0x20a0: 0x8e220004  lw          $v0, 0x4($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x20a4: 0x0  nop
    // NOP
    // 0x20a8: 0x24510008  addiu       $s1, $v0, 0x8
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x20ac: 0x2ce20010  sltiu       $v0, $a3, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x20b0: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x20B0u;
    {
        const bool branch_taken_0x20b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x20b4: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x20b0) {
            ctx->pc = 0x20E0u;
            goto label_20e0;
        }
    }
    ctx->pc = 0x20B8u;
    // 0x20b8: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x20bc: 0x0  nop
    // NOP
    // 0x20c0: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x20c4: 0xa052004c  sb          $s2, 0x4C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 76), (uint8_t)GPR_U32(ctx, 18));
    // 0x20c8: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20cc: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x20d0: 0xc0007fb  jal         func_001FEC
    ctx->pc = 0x20D0u;
    SET_GPR_U32(ctx, 31, 0x20D8u);
    // 0x20d4: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x1FECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1FECu, 0x20D0u, 0x20D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x20D8u;
label_20d8:
    // 0x20d8: 0x800084f  j           func_00213C
    ctx->pc = 0x20D8u;
    // 0x20dc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x213Cu;
    goto label_213c;
    ctx->pc = 0x20E0u;
label_20e0:
    // 0x20e0: 0x14e20016  bne         $a3, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x20E0u;
    {
        const bool branch_taken_0x20e0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        // 0x20e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x20e0) {
            ctx->pc = 0x213Cu;
            goto label_213c;
        }
    }
    ctx->pc = 0x20E8u;
    // 0x20e8: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x20ec: 0x0  nop
    // NOP
    // 0x20f0: 0xa0520032  sb          $s2, 0x32($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 50), (uint8_t)GPR_U32(ctx, 18));
    // 0x20f4: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20f8: 0x0  nop
    // NOP
    // 0x20fc: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x2100: 0x0  nop
    // NOP
    // 0x2104: 0x30420002  andi        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x2108: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x2108u;
    {
        const bool branch_taken_0x2108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x210c: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2108) {
            ctx->pc = 0x2138u;
            goto label_2138;
        }
    }
    ctx->pc = 0x2110u;
    // 0x2110: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_2114:
    // 0x2114: 0x320700ff  andi        $a3, $s0, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x2118: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x211c: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2120: 0xc0007fb  jal         func_001FEC
    ctx->pc = 0x2120u;
    SET_GPR_U32(ctx, 31, 0x2128u);
    // 0x2124: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0x1FECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1FECu, 0x2120u, 0x2128u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2128u;
label_2128:
    // 0x2128: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x212c: 0x2c420010  sltiu       $v0, $v0, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x2130: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x2130u;
    {
        const bool branch_taken_0x2130 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2134: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2130) {
            ctx->pc = 0x2114u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2114;
        }
    }
    ctx->pc = 0x2138u;
label_2138:
    // 0x2138: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_213c:
    // 0x213c: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2140: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2144: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2148: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x214c: 0x3e00008  jr          $ra
    ctx->pc = 0x214Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2150: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x214Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2154u;
}


// Function: modmidi_00002154
// Address: 0x2154 - 0x2268
void modmidi_00002154_0x2154(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002154_0x2154");
#endif

    switch (ctx->pc) {
        case 0x2188u: goto label_2188;
        case 0x21ecu: goto label_21ec;
        case 0x2204u: goto label_2204;
        case 0x2238u: goto label_2238;
        default: break;
    }

    ctx->pc = 0x2154u;

    // 0x2154: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x2158: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x215c: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2160: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2164: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2168: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x216c: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2170: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x2174: 0x2408821  addu        $s1, $s2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2178: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x217c: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x2180: 0xc000985  jal         func_002614
    ctx->pc = 0x2180u;
    SET_GPR_U32(ctx, 31, 0x2188u);
    // 0x2184: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x2180u, 0x2188u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2188u;
label_2188:
    // 0x2188: 0x10400030  beqz        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x2188u;
    {
        const bool branch_taken_0x2188 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x218c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2188) {
            ctx->pc = 0x224Cu;
            goto label_224c;
        }
    }
    ctx->pc = 0x2190u;
    // 0x2190: 0x8e620004  lw          $v0, 0x4($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x2194: 0x0  nop
    // NOP
    // 0x2198: 0x24530008  addiu       $s3, $v0, 0x8
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x219c: 0x121600  sll         $v0, $s2, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 24));
    // 0x21a0: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x21A0u;
    {
        const bool branch_taken_0x21a0 = (GPR_S32(ctx, 2) >= 0);
        // 0x21a4: 0x320700ff  andi        $a3, $s0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x21a0) {
            ctx->pc = 0x21ACu;
            goto label_21ac;
        }
    }
    ctx->pc = 0x21A8u;
    // 0x21a8: 0x2411007f  addiu       $s1, $zero, 0x7F
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_21ac:
    // 0x21ac: 0x2ce20010  sltiu       $v0, $a3, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x21b0: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x21B0u;
    {
        const bool branch_taken_0x21b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x21b4: 0x240200ff  addiu       $v0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x21b0) {
            ctx->pc = 0x21F4u;
            goto label_21f4;
        }
    }
    ctx->pc = 0x21B8u;
    // 0x21b8: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x21bc: 0x0  nop
    // NOP
    // 0x21c0: 0x671021  addu        $v0, $v1, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x21c4: 0xa051003c  sb          $s1, 0x3C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 60), (uint8_t)GPR_U32(ctx, 17));
    // 0x21c8: 0x71040  sll         $v0, $a3, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x21cc: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x21d0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x21d4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x21d8: 0xa0710061  sb          $s1, 0x61($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 97), (uint8_t)GPR_U32(ctx, 17));
    // 0x21dc: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x21e0: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x21e4: 0xc0007fb  jal         func_001FEC
    ctx->pc = 0x21E4u;
    SET_GPR_U32(ctx, 31, 0x21ECu);
    // 0x21e8: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x1FECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1FECu, 0x21E4u, 0x21ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x21ECu;
label_21ec:
    // 0x21ec: 0x8000893  j           func_00224C
    ctx->pc = 0x21ECu;
    // 0x21f0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x224Cu;
    goto label_224c;
    ctx->pc = 0x21F4u;
label_21f4:
    // 0x21f4: 0x14e20015  bne         $a3, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x21F4u;
    {
        const bool branch_taken_0x21f4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        // 0x21f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x21f4) {
            ctx->pc = 0x224Cu;
            goto label_224c;
        }
    }
    ctx->pc = 0x21FCu;
    // 0x21fc: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2200: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_2204:
    // 0x2204: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2208: 0x320700ff  andi        $a3, $s0, 0xFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x220c: 0x671021  addu        $v0, $v1, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x2210: 0xa051003c  sb          $s1, 0x3C($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 60), (uint8_t)GPR_U32(ctx, 17));
    // 0x2214: 0x71040  sll         $v0, $a3, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x2218: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x221c: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2220: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x2224: 0xa0710061  sb          $s1, 0x61($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 97), (uint8_t)GPR_U32(ctx, 17));
    // 0x2228: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x222c: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2230: 0xc0007fb  jal         func_001FEC
    ctx->pc = 0x2230u;
    SET_GPR_U32(ctx, 31, 0x2238u);
    // 0x2234: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0x1FECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1FECu, 0x2230u, 0x2238u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2238u;
label_2238:
    // 0x2238: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x223c: 0x2c420010  sltiu       $v0, $v0, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x2240: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x2240u;
    {
        const bool branch_taken_0x2240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2244: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x2240) {
            ctx->pc = 0x2204u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2204;
        }
    }
    ctx->pc = 0x2248u;
    // 0x2248: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_224c:
    // 0x224c: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x2250: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2254: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2258: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x225c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2260: 0x3e00008  jr          $ra
    ctx->pc = 0x2260u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2264: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2260u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2268u;
}


// Function: modmidi_00002268
// Address: 0x2268 - 0x22cc
void modmidi_00002268_0x2268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002268_0x2268");
#endif

    switch (ctx->pc) {
        case 0x2284u: goto label_2284;
        case 0x22b0u: goto label_22b0;
        default: break;
    }

    ctx->pc = 0x2268u;

    // 0x2268: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x226c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2270: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2274: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2278: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x227c: 0xc000985  jal         func_002614
    ctx->pc = 0x227Cu;
    SET_GPR_U32(ctx, 31, 0x2284u);
    // 0x2280: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x227Cu, 0x2284u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2284u;
label_2284:
    // 0x2284: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x2284u;
    {
        const bool branch_taken_0x2284 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2288: 0x3c030393  lui         $v1, 0x393 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)915 << 16));
        if (branch_taken_0x2284) {
            ctx->pc = 0x22B8u;
            goto label_22b8;
        }
    }
    ctx->pc = 0x228Cu;
    // 0x228c: 0x34638700  ori         $v1, $v1, 0x8700
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)34560);
    // 0x2290: 0x320200ff  andi        $v0, $s0, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x2294: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2294u;
    {
        const bool branch_taken_0x2294 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2298: 0x62001b  divu        $zero, $v1, $v0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
        if (branch_taken_0x2294) {
            ctx->pc = 0x22A0u;
            goto label_22a0;
        }
    }
    ctx->pc = 0x229Cu;
    // 0x229c: 0x7000d  break       7
    ctx->pc = 0x229cu;
    runtime->handleBreak(rdram, ctx);
label_22a0:
    // 0x22a0: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x22a4: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x22a8: 0xc000308  jal         func_000C20
    ctx->pc = 0x22A8u;
    SET_GPR_U32(ctx, 31, 0x22B0u);
    // 0x22ac: 0xac830028  sw          $v1, 0x28($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 3));
    ctx->pc = 0xC20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC20u, 0x22A8u, 0x22B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22B0u;
label_22b0:
    // 0x22b0: 0x80008af  j           func_0022BC
    ctx->pc = 0x22B0u;
    // 0x22b4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x22BCu;
    goto label_22bc;
    ctx->pc = 0x22B8u;
label_22b8:
    // 0x22b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_22bc:
    // 0x22bc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x22c0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x22c4: 0x3e00008  jr          $ra
    ctx->pc = 0x22C4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x22c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x22C4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x22CCu;
}


// Function: modmidi_000022cc
// Address: 0x22cc - 0x2368
void modmidi_000022cc_0x22cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000022cc_0x22cc");
#endif

    switch (ctx->pc) {
        case 0x22e0u: goto label_22e0;
        default: break;
    }

    ctx->pc = 0x22ccu;

    // 0x22cc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x22d0: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x22d4: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x22d8: 0xc000985  jal         func_002614
    ctx->pc = 0x22D8u;
    SET_GPR_U32(ctx, 31, 0x22E0u);
    // 0x22dc: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x22D8u, 0x22E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22E0u;
label_22e0:
    // 0x22e0: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x22E0u;
    {
        const bool branch_taken_0x22e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x22e4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x22e0) {
            ctx->pc = 0x2358u;
            goto label_2358;
        }
    }
    ctx->pc = 0x22E8u;
    // 0x22e8: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x22ec: 0x0  nop
    // NOP
    // 0x22f0: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x22f4: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x22f8: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x22F8u;
    {
        const bool branch_taken_0x22f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x22fc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x22f8) {
            ctx->pc = 0x2358u;
            goto label_2358;
        }
    }
    ctx->pc = 0x2300u;
    // 0x2300: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2304: 0x0  nop
    // NOP
    // 0x2308: 0x8c430028  lw          $v1, 0x28($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x230c: 0x0  nop
    // NOP
    // 0x2310: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2310u;
    {
        const bool branch_taken_0x2310 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x2314: 0x3c020393  lui         $v0, 0x393 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)915 << 16));
        if (branch_taken_0x2310) {
            ctx->pc = 0x2320u;
            goto label_2320;
        }
    }
    ctx->pc = 0x2318u;
    // 0x2318: 0x80008d6  j           func_002358
    ctx->pc = 0x2318u;
    // 0x231c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2358u;
    goto label_2358;
    ctx->pc = 0x2320u;
label_2320:
    // 0x2320: 0x34428700  ori         $v0, $v0, 0x8700
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)34560);
    // 0x2324: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2324u;
    {
        const bool branch_taken_0x2324 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x2328: 0x43001b  divu        $zero, $v0, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x2324) {
            ctx->pc = 0x2330u;
            goto label_2330;
        }
    }
    ctx->pc = 0x232Cu;
    // 0x232c: 0x7000d  break       7
    ctx->pc = 0x232cu;
    runtime->handleBreak(rdram, ctx);
label_2330:
    // 0x2330: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x2334: 0x2c620014  sltiu       $v0, $v1, 0x14
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
    // 0x2338: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2338u;
    {
        const bool branch_taken_0x2338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x233c: 0x2c620100  sltiu       $v0, $v1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        if (branch_taken_0x2338) {
            ctx->pc = 0x2348u;
            goto label_2348;
        }
    }
    ctx->pc = 0x2340u;
    // 0x2340: 0x80008d5  j           func_002354
    ctx->pc = 0x2340u;
    // 0x2344: 0x24030014  addiu       $v1, $zero, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    ctx->pc = 0x2354u;
    goto label_2354;
    ctx->pc = 0x2348u;
label_2348:
    // 0x2348: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2348u;
    {
        const bool branch_taken_0x2348 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x234c: 0x306200ff  andi        $v0, $v1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x2348) {
            ctx->pc = 0x2358u;
            goto label_2358;
        }
    }
    ctx->pc = 0x2350u;
    // 0x2350: 0x240300ff  addiu       $v1, $zero, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_2354:
    // 0x2354: 0x306200ff  andi        $v0, $v1, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
label_2358:
    // 0x2358: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x235c: 0x0  nop
    // NOP
    // 0x2360: 0x3e00008  jr          $ra
    ctx->pc = 0x2360u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2364: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2360u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2368u;
}


// Function: modmidi_00002368
// Address: 0x2368 - 0x23b4
void modmidi_00002368_0x2368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002368_0x2368");
#endif

    switch (ctx->pc) {
        case 0x2384u: goto label_2384;
        case 0x2398u: goto label_2398;
        default: break;
    }

    ctx->pc = 0x2368u;

    // 0x2368: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x236c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2370: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2374: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2378: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x237c: 0xc000985  jal         func_002614
    ctx->pc = 0x237Cu;
    SET_GPR_U32(ctx, 31, 0x2384u);
    // 0x2380: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x237Cu, 0x2384u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2384u;
label_2384:
    // 0x2384: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2384u;
    {
        const bool branch_taken_0x2384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2388: 0x3202ffff  andi        $v0, $s0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
        if (branch_taken_0x2384) {
            ctx->pc = 0x23A0u;
            goto label_23a0;
        }
    }
    ctx->pc = 0x238Cu;
    // 0x238c: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2390: 0xc000308  jal         func_000C20
    ctx->pc = 0x2390u;
    SET_GPR_U32(ctx, 31, 0x2398u);
    // 0x2394: 0xac82002c  sw          $v0, 0x2C($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 2));
    ctx->pc = 0xC20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC20u, 0x2390u, 0x2398u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2398u;
label_2398:
    // 0x2398: 0x80008e9  j           func_0023A4
    ctx->pc = 0x2398u;
    // 0x239c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x23A4u;
    goto label_23a4;
    ctx->pc = 0x23A0u;
label_23a0:
    // 0x23a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_23a4:
    // 0x23a4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x23a8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x23ac: 0x3e00008  jr          $ra
    ctx->pc = 0x23ACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x23b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x23ACu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x23B4u;
}


// Function: modmidi_000023b4
// Address: 0x23b4 - 0x2404
void modmidi_000023b4_0x23b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000023b4_0x23b4");
#endif

    switch (ctx->pc) {
        case 0x23c8u: goto label_23c8;
        default: break;
    }

    ctx->pc = 0x23b4u;

    // 0x23b4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x23b8: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x23bc: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x23c0: 0xc000985  jal         func_002614
    ctx->pc = 0x23C0u;
    SET_GPR_U32(ctx, 31, 0x23C8u);
    // 0x23c4: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x23C0u, 0x23C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23C8u;
label_23c8:
    // 0x23c8: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x23C8u;
    {
        const bool branch_taken_0x23c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x23cc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x23c8) {
            ctx->pc = 0x23F4u;
            goto label_23f4;
        }
    }
    ctx->pc = 0x23D0u;
    // 0x23d0: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x23d4: 0x0  nop
    // NOP
    // 0x23d8: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x23dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x23e0: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x23E0u;
    {
        const bool branch_taken_0x23e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x23e4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x23e0) {
            ctx->pc = 0x23F4u;
            goto label_23f4;
        }
    }
    ctx->pc = 0x23E8u;
    // 0x23e8: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x23ec: 0x0  nop
    // NOP
    // 0x23f0: 0x9442002c  lhu         $v0, 0x2C($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 44)));
label_23f4:
    // 0x23f4: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x23f8: 0x0  nop
    // NOP
    // 0x23fc: 0x3e00008  jr          $ra
    ctx->pc = 0x23FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2400: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x23FCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2404u;
}


// Function: modmidi_00002404
// Address: 0x2404 - 0x2448
void modmidi_00002404_0x2404(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002404_0x2404");
#endif

    switch (ctx->pc) {
        case 0x2420u: goto label_2420;
        case 0x2434u: goto label_2434;
        default: break;
    }

    ctx->pc = 0x2404u;

    // 0x2404: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2408: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x240c: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2410: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2414: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x2418: 0xc000985  jal         func_002614
    ctx->pc = 0x2418u;
    SET_GPR_U32(ctx, 31, 0x2420u);
    // 0x241c: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x2418u, 0x2420u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2420u;
label_2420:
    // 0x2420: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2420u;
    {
        const bool branch_taken_0x2420 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2424: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2420) {
            ctx->pc = 0x2438u;
            goto label_2438;
        }
    }
    ctx->pc = 0x2428u;
    // 0x2428: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x242c: 0xc000308  jal         func_000C20
    ctx->pc = 0x242Cu;
    SET_GPR_U32(ctx, 31, 0x2434u);
    // 0x2430: 0xac900028  sw          $s0, 0x28($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 16));
    ctx->pc = 0xC20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC20u, 0x242Cu, 0x2434u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2434u;
label_2434:
    // 0x2434: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2438:
    // 0x2438: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x243c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2440: 0x3e00008  jr          $ra
    ctx->pc = 0x2440u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2444: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2440u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2448u;
}


// Function: modmidi_00002448
// Address: 0x2448 - 0x2498
void modmidi_00002448_0x2448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002448_0x2448");
#endif

    switch (ctx->pc) {
        case 0x245cu: goto label_245c;
        default: break;
    }

    ctx->pc = 0x2448u;

    // 0x2448: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x244c: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x2450: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2454: 0xc000985  jal         func_002614
    ctx->pc = 0x2454u;
    SET_GPR_U32(ctx, 31, 0x245Cu);
    // 0x2458: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x2454u, 0x245Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x245Cu;
label_245c:
    // 0x245c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x245Cu;
    {
        const bool branch_taken_0x245c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2460: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x245c) {
            ctx->pc = 0x2488u;
            goto label_2488;
        }
    }
    ctx->pc = 0x2464u;
    // 0x2464: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2468: 0x0  nop
    // NOP
    // 0x246c: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x2470: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2474: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2474u;
    {
        const bool branch_taken_0x2474 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2478: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2474) {
            ctx->pc = 0x2488u;
            goto label_2488;
        }
    }
    ctx->pc = 0x247Cu;
    // 0x247c: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2480: 0x0  nop
    // NOP
    // 0x2484: 0x8c420028  lw          $v0, 0x28($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
label_2488:
    // 0x2488: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x248c: 0x0  nop
    // NOP
    // 0x2490: 0x3e00008  jr          $ra
    ctx->pc = 0x2490u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2494: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2490u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2498u;
}


// Function: modmidi_00002498
// Address: 0x2498 - 0x2550
void modmidi_00002498_0x2498(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002498_0x2498");
#endif

    switch (ctx->pc) {
        case 0x24f8u: goto label_24f8;
        case 0x2510u: goto label_2510;
        default: break;
    }

    ctx->pc = 0x2498u;

    // 0x2498: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x249c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x24a0: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x24a4: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0x24a8: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
    // 0x24ac: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
    // 0x24b0: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x24b4: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x24b8: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x24bc: 0x8c860004  lw          $a2, 0x4($a0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x24c0: 0x52900  sll         $a1, $a1, 4
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x24c4: 0x8cc20004  lw          $v0, 0x4($a2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x24c8: 0x34a50008  ori         $a1, $a1, 0x8
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)8);
    // 0x24cc: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x24d0: 0x8cb10004  lw          $s1, 0x4($a1)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x24d4: 0x0  nop
    // NOP
    // 0x24d8: 0x12200011  beqz        $s1, . + 4 + (0x11 << 2)
    ctx->pc = 0x24D8u;
    {
        const bool branch_taken_0x24d8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0x24dc: 0xe0a821  addu        $s5, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        if (branch_taken_0x24d8) {
            ctx->pc = 0x2520u;
            goto label_2520;
        }
    }
    ctx->pc = 0x24E0u;
    // 0x24e0: 0x2634005c  addiu       $s4, $s1, 0x5C
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 92));
    // 0x24e4: 0x24d30008  addiu       $s3, $a2, 0x8
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x24e8: 0x3c0200ff  lui         $v0, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x24ec: 0x3442fff0  ori         $v0, $v0, 0xFFF0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65520);
    // 0x24f0: 0x2429024  and         $s2, $s2, $v0
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & GPR_U64(ctx, 2));
    // 0x24f4: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_24f8:
    // 0x24f8: 0xafb50010  sw          $s5, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 21));
    // 0x24fc: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2500: 0x2802821  addu        $a1, $s4, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    // 0x2504: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2508: 0xc000421  jal         func_001084
    ctx->pc = 0x2508u;
    SET_GPR_U32(ctx, 31, 0x2510u);
    // 0x250c: 0x2503825  or          $a3, $s2, $s0 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 18) | GPR_U64(ctx, 16));
    ctx->pc = 0x1084u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1084u, 0x2508u, 0x2510u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2510u;
label_2510:
    // 0x2510: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x2514: 0x2e020010  sltiu       $v0, $s0, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x2518: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x2518u;
    {
        const bool branch_taken_0x2518 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2518) {
            ctx->pc = 0x24F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_24f8;
        }
    }
    ctx->pc = 0x2520u;
label_2520:
    // 0x2520: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2524: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x2528: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x252c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2530: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2534: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2538: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x253c: 0x3e00008  jr          $ra
    ctx->pc = 0x253Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2540: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x253Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2544u;
    // 0x2544: 0x0  nop
    // NOP
    // 0x2548: 0x0  nop
    // NOP
    // 0x254c: 0x0  nop
    // NOP
}


// Function: modmidi_00002550
// Address: 0x2550 - 0x2614
void modmidi_00002550_0x2550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002550_0x2550");
#endif

    switch (ctx->pc) {
        case 0x25fcu: goto label_25fc;
        default: break;
    }

    ctx->pc = 0x2550u;

    // 0x2550: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2554: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x2558: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x255c: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x2560: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x2564: 0x8e260128  lw          $a2, 0x128($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 296)));
    // 0x2568: 0x0  nop
    // NOP
    // 0x256c: 0x10c00015  beqz        $a2, . + 4 + (0x15 << 2)
    ctx->pc = 0x256Cu;
    {
        const bool branch_taken_0x256c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x256c) {
            ctx->pc = 0x25C4u;
            goto label_25c4;
        }
    }
    ctx->pc = 0x2574u;
    // 0x2574: 0x9222012d  lbu         $v0, 0x12D($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 301)));
    // 0x2578: 0x9223012c  lbu         $v1, 0x12C($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 300)));
    // 0x257c: 0x0  nop
    // NOP
    // 0x2580: 0x438023  subu        $s0, $v0, $v1
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2584: 0x2060018  mult        $zero, $s0, $a2
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x2588: 0x8012  mflo        $s0
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x258c: 0x8e220124  lw          $v0, 0x124($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 292)));
    // 0x2590: 0x0  nop
    // NOP
    // 0x2594: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2594u;
    {
        const bool branch_taken_0x2594 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2598: 0x202001a  div         $zero, $s0, $v0 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 16);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        if (branch_taken_0x2594) {
            ctx->pc = 0x25A0u;
            goto label_25a0;
        }
    }
    ctx->pc = 0x259Cu;
    // 0x259c: 0x7000d  break       7
    ctx->pc = 0x259cu;
    runtime->handleBreak(rdram, ctx);
label_25a0:
    // 0x25a0: 0x2401ffff  addiu       $at, $zero, -0x1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x25a4: 0x14410004  bne         $v0, $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x25A4u;
    {
        const bool branch_taken_0x25a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 1));
        // 0x25a8: 0x3c018000  lui         $at, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)32768 << 16));
        if (branch_taken_0x25a4) {
            ctx->pc = 0x25B8u;
            goto label_25b8;
        }
    }
    ctx->pc = 0x25ACu;
    // 0x25ac: 0x16010002  bne         $s0, $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x25ACu;
    {
        const bool branch_taken_0x25ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 1));
        if (branch_taken_0x25ac) {
            ctx->pc = 0x25B8u;
            goto label_25b8;
        }
    }
    ctx->pc = 0x25B4u;
    // 0x25b4: 0x6000d  break       6
    ctx->pc = 0x25b4u;
    runtime->handleBreak(rdram, ctx);
label_25b8:
    // 0x25b8: 0x8012  mflo        $s0
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x25bc: 0x8000972  j           func_0025C8
    ctx->pc = 0x25BCu;
    // 0x25c0: 0x2038021  addu        $s0, $s0, $v1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    ctx->pc = 0x25C8u;
    goto label_25c8;
    ctx->pc = 0x25C4u;
label_25c4:
    // 0x25c4: 0x9230012d  lbu         $s0, 0x12D($s1)
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 301)));
label_25c8:
    // 0x25c8: 0x9222012e  lbu         $v0, 0x12E($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 302)));
    // 0x25cc: 0x0  nop
    // NOP
    // 0x25d0: 0x2020018  mult        $zero, $s0, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x25d4: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x25d8: 0x4e10002  bgez        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x25D8u;
    {
        const bool branch_taken_0x25d8 = (GPR_S32(ctx, 7) >= 0);
        if (branch_taken_0x25d8) {
            ctx->pc = 0x25E4u;
            goto label_25e4;
        }
    }
    ctx->pc = 0x25E0u;
    // 0x25e0: 0x24e7007f  addiu       $a3, $a3, 0x7F
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 127));
label_25e4:
    // 0x25e4: 0x9222012f  lbu         $v0, 0x12F($s1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 303)));
    // 0x25e8: 0x781c3  sra         $s0, $a3, 7
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 7), 7));
    // 0x25ec: 0x10500004  beq         $v0, $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x25ECu;
    {
        const bool branch_taken_0x25ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        // 0x25f0: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        if (branch_taken_0x25ec) {
            ctx->pc = 0x2600u;
            goto label_2600;
        }
    }
    ctx->pc = 0x25F4u;
    // 0x25f4: 0xc000819  jal         func_002064
    ctx->pc = 0x25F4u;
    SET_GPR_U32(ctx, 31, 0x25FCu);
    // 0x25f8: 0x320700ff  andi        $a3, $s0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x2064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2064u, 0x25F4u, 0x25FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x25FCu;
label_25fc:
    // 0x25fc: 0xa230012f  sb          $s0, 0x12F($s1)
    WRITE8(ADD32(GPR_U32(ctx, 17), 303), (uint8_t)GPR_U32(ctx, 16));
label_2600:
    // 0x2600: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2604: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2608: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x260c: 0x3e00008  jr          $ra
    ctx->pc = 0x260Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2610: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x260Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2614u;
}


// Function: modmidi_00002614
// Address: 0x2614 - 0x2670
void modmidi_00002614_0x2614(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002614_0x2614");
#endif

    ctx->pc = 0x2614u;

    // 0x2614: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x2614u;
    {
        const bool branch_taken_0x2614 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x2618: 0x51840  sll         $v1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x2614) {
            ctx->pc = 0x2668u;
            goto label_2668;
        }
    }
    ctx->pc = 0x261Cu;
    // 0x261c: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2620: 0x0  nop
    // NOP
    // 0x2624: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2628: 0x24650001  addiu       $a1, $v1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x262c: 0xa2102b  sltu        $v0, $a1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x2630: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x2630u;
    {
        const bool branch_taken_0x2630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2634: 0x510c0  sll         $v0, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x2630) {
            ctx->pc = 0x2668u;
            goto label_2668;
        }
    }
    ctx->pc = 0x2638u;
    // 0x2638: 0x8c830004  lw          $v1, 0x4($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x263c: 0x0  nop
    // NOP
    // 0x2640: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2644: 0x8c420004  lw          $v0, 0x4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x2648: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x2648u;
    {
        const bool branch_taken_0x2648 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x264c: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x2648) {
            ctx->pc = 0x2658u;
            goto label_2658;
        }
    }
    ctx->pc = 0x2650u;
    // 0x2650: 0x3e00008  jr          $ra
    ctx->pc = 0x2650u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2654: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2650u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2658u;
label_2658:
    // 0x2658: 0x2442005c  addiu       $v0, $v0, 0x5C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 92));
    // 0x265c: 0xace20000  sw          $v0, 0x0($a3)
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x2660: 0x3e00008  jr          $ra
    ctx->pc = 0x2660u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2664: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2660u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2668u;
label_2668:
    // 0x2668: 0x3e00008  jr          $ra
    ctx->pc = 0x2668u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x266c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2668u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2670u;
}


// Function: modmidi_00002670
// Address: 0x2670 - 0x26a8
void modmidi_00002670_0x2670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002670_0x2670");
#endif

    switch (ctx->pc) {
        case 0x2690u: goto label_2690;
        default: break;
    }

    ctx->pc = 0x2670u;

    // 0x2670: 0x24060007  addiu       $a2, $zero, 0x7
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x2674: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x2678: 0x2403f8ff  addiu       $v1, $zero, -0x701
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294965503));
    // 0x267c: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2680: 0xac82000c  sw          $v0, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x2684: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x2688: 0x24a30038  addiu       $v1, $a1, 0x38
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 56));
    // 0x268c: 0xaca20004  sw          $v0, 0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
label_2690:
    // 0x2690: 0xac60001c  sw          $zero, 0x1C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 0));
    // 0x2694: 0x24c6ffff  addiu       $a2, $a2, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x2698: 0x4c1fffd  bgez        $a2, . + 4 + (-0x3 << 2)
    ctx->pc = 0x2698u;
    {
        const bool branch_taken_0x2698 = (GPR_S32(ctx, 6) >= 0);
        // 0x269c: 0x2463fff8  addiu       $v1, $v1, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967288));
        if (branch_taken_0x2698) {
            ctx->pc = 0x2690u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2690;
        }
    }
    ctx->pc = 0x26A0u;
    // 0x26a0: 0x3e00008  jr          $ra
    ctx->pc = 0x26A0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x26A0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x26A8u;
}


// Function: modmidi_000026a8
// Address: 0x26a8 - 0x27f4
void modmidi_000026a8_0x26a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000026a8_0x26a8");
#endif

    switch (ctx->pc) {
        case 0x26d8u: goto label_26d8;
        case 0x2750u: goto label_2750;
        case 0x27d4u: goto label_27d4;
        default: break;
    }

    ctx->pc = 0x26a8u;

    // 0x26a8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x26ac: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x26b0: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x26b4: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x26b8: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x26bc: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x26c0: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x26c4: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x26c8: 0x27a70014  addiu       $a3, $sp, 0x14
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x26cc: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x26d0: 0xc000985  jal         func_002614
    ctx->pc = 0x26D0u;
    SET_GPR_U32(ctx, 31, 0x26D8u);
    // 0x26d4: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x26D0u, 0x26D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26D8u;
label_26d8:
    // 0x26d8: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x26D8u;
    {
        const bool branch_taken_0x26d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x26d8) {
            ctx->pc = 0x270Cu;
            goto label_270c;
        }
    }
    ctx->pc = 0x26E0u;
    // 0x26e0: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x26e4: 0x0  nop
    // NOP
    // 0x26e8: 0x8c430008  lw          $v1, 0x8($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x26ec: 0x0  nop
    // NOP
    // 0x26f0: 0x10600039  beqz        $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x26F0u;
    {
        const bool branch_taken_0x26f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x26f4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x26f0) {
            ctx->pc = 0x27D8u;
            goto label_27d8;
        }
    }
    ctx->pc = 0x26F8u;
    // 0x26f8: 0x8c62000c  lw          $v0, 0xC($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x26fc: 0x0  nop
    // NOP
    // 0x2700: 0x51102b  sltu        $v0, $v0, $s1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x2704: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2704u;
    {
        const bool branch_taken_0x2704 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2708: 0x118080  sll         $s0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x2704) {
            ctx->pc = 0x2714u;
            goto label_2714;
        }
    }
    ctx->pc = 0x270Cu;
label_270c:
    // 0x270c: 0x80009f6  j           func_0027D8
    ctx->pc = 0x270Cu;
    // 0x2710: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x27D8u;
    goto label_27d8;
    ctx->pc = 0x2714u;
label_2714:
    // 0x2714: 0x701021  addu        $v0, $v1, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x2718: 0x8c430010  lw          $v1, 0x10($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x271c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x2720: 0x1062002d  beq         $v1, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x2720u;
    {
        const bool branch_taken_0x2720 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x2720) {
            ctx->pc = 0x27D8u;
            goto label_27d8;
        }
    }
    ctx->pc = 0x2728u;
    // 0x2728: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x272c: 0x0  nop
    // NOP
    // 0x2730: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x2734: 0x0  nop
    // NOP
    // 0x2738: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x273c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x273Cu;
    {
        const bool branch_taken_0x273c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2740: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x273c) {
            ctx->pc = 0x2750u;
            goto label_2750;
        }
    }
    ctx->pc = 0x2744u;
    // 0x2744: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2748: 0xc000bd1  jal         func_002F44
    ctx->pc = 0x2748u;
    SET_GPR_U32(ctx, 31, 0x2750u);
    // 0x274c: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F44u, 0x2748u, 0x2750u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2750u;
label_2750:
    // 0x2750: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2754: 0x0  nop
    // NOP
    // 0x2758: 0x8c640008  lw          $a0, 0x8($v1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x275c: 0x0  nop
    // NOP
    // 0x2760: 0x901021  addu        $v0, $a0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x2764: 0x8c460010  lw          $a2, 0x10($v0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x2768: 0x24050080  addiu       $a1, $zero, 0x80
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x276c: 0xac600124  sw          $zero, 0x124($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 292), GPR_U32(ctx, 0));
    // 0x2770: 0xac600128  sw          $zero, 0x128($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 296), GPR_U32(ctx, 0));
    // 0x2774: 0xa065012d  sb          $a1, 0x12D($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 301), (uint8_t)GPR_U32(ctx, 5));
    // 0x2778: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x277c: 0x862021  addu        $a0, $a0, $a2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x2780: 0xac64011c  sw          $a0, 0x11C($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 284), GPR_U32(ctx, 4));
    // 0x2784: 0xa045012e  sb          $a1, 0x12E($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 302), (uint8_t)GPR_U32(ctx, 5));
    // 0x2788: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x278c: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x2790: 0xa062012f  sb          $v0, 0x12F($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 303), (uint8_t)GPR_U32(ctx, 2));
    // 0x2794: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2798: 0x0  nop
    // NOP
    // 0x279c: 0xa0400130  sb          $zero, 0x130($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 304), (uint8_t)GPR_U32(ctx, 0));
    // 0x27a0: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x27a4: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x27a8: 0xa0620132  sb          $v0, 0x132($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 306), (uint8_t)GPR_U32(ctx, 2));
    // 0x27ac: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x27b0: 0x24020078  addiu       $v0, $zero, 0x78
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
    // 0x27b4: 0xa0620133  sb          $v0, 0x133($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 307), (uint8_t)GPR_U32(ctx, 2));
    // 0x27b8: 0x24020100  addiu       $v0, $zero, 0x100
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x27bc: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x27c0: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x27c4: 0x2465011c  addiu       $a1, $v1, 0x11C
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 284));
    // 0x27c8: 0xa4620134  sh          $v0, 0x134($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 308), (uint16_t)GPR_U32(ctx, 2));
    // 0x27cc: 0xc00099c  jal         func_002670
    ctx->pc = 0x27CCu;
    SET_GPR_U32(ctx, 31, 0x27D4u);
    // 0x27d0: 0xac910000  sw          $s1, 0x0($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 17));
    ctx->pc = 0x2670u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2670u, 0x27CCu, 0x27D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x27D4u;
label_27d4:
    // 0x27d4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_27d8:
    // 0x27d8: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x27dc: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x27e0: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x27e4: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x27e8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x27ec: 0x3e00008  jr          $ra
    ctx->pc = 0x27ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x27f0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x27ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x27F4u;
}


// Function: modmidi_000027f4
// Address: 0x27f4 - 0x2818
void modmidi_000027f4_0x27f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000027f4_0x27f4");
#endif

    ctx->pc = 0x27f4u;

    // 0x27f4: 0x4a10003  bgez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x27F4u;
    {
        const bool branch_taken_0x27f4 = (GPR_S32(ctx, 5) >= 0);
        // 0x27f8: 0x28a20081  slti        $v0, $a1, 0x81 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)129) ? 1 : 0);
        if (branch_taken_0x27f4) {
            ctx->pc = 0x2804u;
            goto label_2804;
        }
    }
    ctx->pc = 0x27FCu;
    // 0x27fc: 0x8000a04  j           func_002810
    ctx->pc = 0x27FCu;
    // 0x2800: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2810u;
    goto label_2810;
    ctx->pc = 0x2804u;
label_2804:
    // 0x2804: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2804u;
    {
        const bool branch_taken_0x2804 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2804) {
            ctx->pc = 0x2810u;
            goto label_2810;
        }
    }
    ctx->pc = 0x280Cu;
    // 0x280c: 0x24050080  addiu       $a1, $zero, 0x80
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
label_2810:
    // 0x2810: 0x3e00008  jr          $ra
    ctx->pc = 0x2810u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2814: 0xa085012d  sb          $a1, 0x12D($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 301), (uint8_t)GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2810u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2818u;
}


// Function: modmidi_00002818
// Address: 0x2818 - 0x283c
void modmidi_00002818_0x2818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002818_0x2818");
#endif

    ctx->pc = 0x2818u;

    // 0x2818: 0x4a10003  bgez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2818u;
    {
        const bool branch_taken_0x2818 = (GPR_S32(ctx, 5) >= 0);
        // 0x281c: 0x28a20080  slti        $v0, $a1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)128) ? 1 : 0);
        if (branch_taken_0x2818) {
            ctx->pc = 0x2828u;
            goto label_2828;
        }
    }
    ctx->pc = 0x2820u;
    // 0x2820: 0x8000a0d  j           func_002834
    ctx->pc = 0x2820u;
    // 0x2824: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2834u;
    goto label_2834;
    ctx->pc = 0x2828u;
label_2828:
    // 0x2828: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2828u;
    {
        const bool branch_taken_0x2828 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2828) {
            ctx->pc = 0x2834u;
            goto label_2834;
        }
    }
    ctx->pc = 0x2830u;
    // 0x2830: 0x2405007f  addiu       $a1, $zero, 0x7F
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_2834:
    // 0x2834: 0x3e00008  jr          $ra
    ctx->pc = 0x2834u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2838: 0xa0850132  sb          $a1, 0x132($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 306), (uint8_t)GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2834u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x283Cu;
}


// Function: modmidi_0000283c
// Address: 0x283c - 0x2864
void modmidi_0000283c_0x283c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000283c_0x283c");
#endif

    ctx->pc = 0x283cu;

    // 0x283c: 0x28a2000a  slti        $v0, $a1, 0xA
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x2840: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2840u;
    {
        const bool branch_taken_0x2840 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2844: 0x28a20100  slti        $v0, $a1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
        if (branch_taken_0x2840) {
            ctx->pc = 0x2850u;
            goto label_2850;
        }
    }
    ctx->pc = 0x2848u;
    // 0x2848: 0x8000a17  j           func_00285C
    ctx->pc = 0x2848u;
    // 0x284c: 0x2405000a  addiu       $a1, $zero, 0xA (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    ctx->pc = 0x285Cu;
    goto label_285c;
    ctx->pc = 0x2850u;
label_2850:
    // 0x2850: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x2850u;
    {
        const bool branch_taken_0x2850 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2850) {
            ctx->pc = 0x285Cu;
            goto label_285c;
        }
    }
    ctx->pc = 0x2858u;
    // 0x2858: 0x240500ff  addiu       $a1, $zero, 0xFF
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_285c:
    // 0x285c: 0x3e00008  jr          $ra
    ctx->pc = 0x285Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2860: 0xa0850133  sb          $a1, 0x133($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 307), (uint8_t)GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x285Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2864u;
}


// Function: modmidi_00002864
// Address: 0x2864 - 0x292c
void modmidi_00002864_0x2864(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002864_0x2864");
#endif

    switch (ctx->pc) {
        case 0x2894u: goto label_2894;
        case 0x28acu: goto label_28ac;
        case 0x28bcu: goto label_28bc;
        case 0x28ccu: goto label_28cc;
        case 0x28e4u: goto label_28e4;
        case 0x2900u: goto label_2900;
        default: break;
    }

    ctx->pc = 0x2864u;

    // 0x2864: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x2868: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x286c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2870: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x2874: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2878: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x287c: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2880: 0xe03021  addu        $a2, $a3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x2884: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x2888: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x288c: 0xc000754  jal         func_001D50
    ctx->pc = 0x288Cu;
    SET_GPR_U32(ctx, 31, 0x2894u);
    // 0x2890: 0x2670005c  addiu       $s0, $s3, 0x5C (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 92));
    ctx->pc = 0x1D50u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D50u, 0x288Cu, 0x2894u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2894u;
label_2894:
    // 0x2894: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x2894u;
    {
        const bool branch_taken_0x2894 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2898: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2894) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x289Cu;
    // 0x289c: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x28a0: 0x96060134  lhu         $a2, 0x134($s0)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 308)));
    // 0x28a4: 0xc0008da  jal         func_002368
    ctx->pc = 0x28A4u;
    SET_GPR_U32(ctx, 31, 0x28ACu);
    // 0x28a8: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x2368u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2368u, 0x28A4u, 0x28ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x28ACu;
label_28ac:
    // 0x28ac: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x28b0: 0x92060133  lbu         $a2, 0x133($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 307)));
    // 0x28b4: 0xc00089a  jal         func_002268
    ctx->pc = 0x28B4u;
    SET_GPR_U32(ctx, 31, 0x28BCu);
    // 0x28b8: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x2268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2268u, 0x28B4u, 0x28BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x28BCu;
label_28bc:
    // 0x28bc: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x28c0: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x28c4: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x28C4u;
    SET_GPR_U32(ctx, 31, 0x28CCu);
    // 0x28c8: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x28C4u, 0x28CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x28CCu;
label_28cc:
    // 0x28cc: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x28CCu;
    {
        const bool branch_taken_0x28cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x28d0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x28cc) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x28D4u;
    // 0x28d4: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x28d8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x28dc: 0xc000954  jal         func_002550
    ctx->pc = 0x28DCu;
    SET_GPR_U32(ctx, 31, 0x28E4u);
    // 0x28e0: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2550u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2550u, 0x28DCu, 0x28E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x28E4u;
label_28e4:
    // 0x28e4: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x28e8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x28ec: 0x92060132  lbu         $a2, 0x132($s0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 306)));
    // 0x28f0: 0x24070003  addiu       $a3, $zero, 0x3
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x28f4: 0x63400  sll         $a2, $a2, 16
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x28f8: 0xc000926  jal         func_002498
    ctx->pc = 0x28F8u;
    SET_GPR_U32(ctx, 31, 0x2900u);
    // 0x28fc: 0x34c60ab0  ori         $a2, $a2, 0xAB0 (Delay Slot)
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)2736);
    ctx->pc = 0x2498u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2498u, 0x28F8u, 0x2900u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2900u;
label_2900:
    // 0x2900: 0x8e63000c  lw          $v1, 0xC($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x2904: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2908: 0x34630200  ori         $v1, $v1, 0x200
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)512);
    // 0x290c: 0xae63000c  sw          $v1, 0xC($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 3));
label_2910:
    // 0x2910: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2914: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2918: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x291c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2920: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2924: 0x3e00008  jr          $ra
    ctx->pc = 0x2924u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2928: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2924u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x292Cu;
}


// Function: modmidi_0000292c
// Address: 0x292c - 0x2b6c
void modmidi_0000292c_0x292c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000292c_0x292c");
#endif

    switch (ctx->pc) {
        case 0x292cu: goto label_292c;
        case 0x2930u: goto label_2930;
        case 0x2934u: goto label_2934;
        case 0x2938u: goto label_2938;
        case 0x293cu: goto label_293c;
        case 0x2940u: goto label_2940;
        case 0x2944u: goto label_2944;
        case 0x2948u: goto label_2948;
        case 0x294cu: goto label_294c;
        case 0x2950u: goto label_2950;
        case 0x2954u: goto label_2954;
        case 0x2958u: goto label_2958;
        case 0x295cu: goto label_295c;
        case 0x2960u: goto label_2960;
        case 0x2964u: goto label_2964;
        case 0x2968u: goto label_2968;
        case 0x296cu: goto label_296c;
        case 0x2970u: goto label_2970;
        case 0x2974u: goto label_2974;
        case 0x2978u: goto label_2978;
        case 0x297cu: goto label_297c;
        case 0x2980u: goto label_2980;
        case 0x2984u: goto label_2984;
        case 0x2988u: goto label_2988;
        case 0x298cu: goto label_298c;
        case 0x2990u: goto label_2990;
        case 0x2994u: goto label_2994;
        case 0x2998u: goto label_2998;
        case 0x299cu: goto label_299c;
        case 0x29a0u: goto label_29a0;
        case 0x29a4u: goto label_29a4;
        case 0x29a8u: goto label_29a8;
        case 0x29acu: goto label_29ac;
        case 0x29b0u: goto label_29b0;
        case 0x29b4u: goto label_29b4;
        case 0x29b8u: goto label_29b8;
        case 0x29bcu: goto label_29bc;
        case 0x29c0u: goto label_29c0;
        case 0x29c4u: goto label_29c4;
        case 0x29c8u: goto label_29c8;
        case 0x29ccu: goto label_29cc;
        case 0x29d0u: goto label_29d0;
        case 0x29d4u: goto label_29d4;
        case 0x29d8u: goto label_29d8;
        case 0x29dcu: goto label_29dc;
        case 0x29e0u: goto label_29e0;
        case 0x29e4u: goto label_29e4;
        case 0x29e8u: goto label_29e8;
        case 0x29ecu: goto label_29ec;
        case 0x29f0u: goto label_29f0;
        case 0x29f4u: goto label_29f4;
        case 0x29f8u: goto label_29f8;
        case 0x29fcu: goto label_29fc;
        case 0x2a00u: goto label_2a00;
        case 0x2a04u: goto label_2a04;
        case 0x2a08u: goto label_2a08;
        case 0x2a0cu: goto label_2a0c;
        case 0x2a10u: goto label_2a10;
        case 0x2a14u: goto label_2a14;
        case 0x2a18u: goto label_2a18;
        case 0x2a1cu: goto label_2a1c;
        case 0x2a20u: goto label_2a20;
        case 0x2a24u: goto label_2a24;
        case 0x2a28u: goto label_2a28;
        case 0x2a2cu: goto label_2a2c;
        case 0x2a30u: goto label_2a30;
        case 0x2a34u: goto label_2a34;
        case 0x2a38u: goto label_2a38;
        case 0x2a3cu: goto label_2a3c;
        case 0x2a40u: goto label_2a40;
        case 0x2a44u: goto label_2a44;
        case 0x2a48u: goto label_2a48;
        case 0x2a4cu: goto label_2a4c;
        case 0x2a50u: goto label_2a50;
        case 0x2a54u: goto label_2a54;
        case 0x2a58u: goto label_2a58;
        case 0x2a5cu: goto label_2a5c;
        case 0x2a60u: goto label_2a60;
        case 0x2a64u: goto label_2a64;
        case 0x2a68u: goto label_2a68;
        case 0x2a6cu: goto label_2a6c;
        case 0x2a70u: goto label_2a70;
        case 0x2a74u: goto label_2a74;
        case 0x2a78u: goto label_2a78;
        case 0x2a7cu: goto label_2a7c;
        case 0x2a80u: goto label_2a80;
        case 0x2a84u: goto label_2a84;
        case 0x2a88u: goto label_2a88;
        case 0x2a8cu: goto label_2a8c;
        case 0x2a90u: goto label_2a90;
        case 0x2a94u: goto label_2a94;
        case 0x2a98u: goto label_2a98;
        case 0x2a9cu: goto label_2a9c;
        case 0x2aa0u: goto label_2aa0;
        case 0x2aa4u: goto label_2aa4;
        case 0x2aa8u: goto label_2aa8;
        case 0x2aacu: goto label_2aac;
        case 0x2ab0u: goto label_2ab0;
        case 0x2ab4u: goto label_2ab4;
        case 0x2ab8u: goto label_2ab8;
        case 0x2abcu: goto label_2abc;
        case 0x2ac0u: goto label_2ac0;
        case 0x2ac4u: goto label_2ac4;
        case 0x2ac8u: goto label_2ac8;
        case 0x2accu: goto label_2acc;
        case 0x2ad0u: goto label_2ad0;
        case 0x2ad4u: goto label_2ad4;
        case 0x2ad8u: goto label_2ad8;
        case 0x2adcu: goto label_2adc;
        case 0x2ae0u: goto label_2ae0;
        case 0x2ae4u: goto label_2ae4;
        case 0x2ae8u: goto label_2ae8;
        case 0x2aecu: goto label_2aec;
        case 0x2af0u: goto label_2af0;
        case 0x2af4u: goto label_2af4;
        case 0x2af8u: goto label_2af8;
        case 0x2afcu: goto label_2afc;
        case 0x2b00u: goto label_2b00;
        case 0x2b04u: goto label_2b04;
        case 0x2b08u: goto label_2b08;
        case 0x2b0cu: goto label_2b0c;
        case 0x2b10u: goto label_2b10;
        case 0x2b14u: goto label_2b14;
        case 0x2b18u: goto label_2b18;
        case 0x2b1cu: goto label_2b1c;
        case 0x2b20u: goto label_2b20;
        case 0x2b24u: goto label_2b24;
        case 0x2b28u: goto label_2b28;
        case 0x2b2cu: goto label_2b2c;
        case 0x2b30u: goto label_2b30;
        case 0x2b34u: goto label_2b34;
        case 0x2b38u: goto label_2b38;
        case 0x2b3cu: goto label_2b3c;
        case 0x2b40u: goto label_2b40;
        case 0x2b44u: goto label_2b44;
        case 0x2b48u: goto label_2b48;
        case 0x2b4cu: goto label_2b4c;
        case 0x2b50u: goto label_2b50;
        case 0x2b54u: goto label_2b54;
        case 0x2b58u: goto label_2b58;
        case 0x2b5cu: goto label_2b5c;
        case 0x2b60u: goto label_2b60;
        case 0x2b64u: goto label_2b64;
        case 0x2b68u: goto label_2b68;
        default: break;
    }

    ctx->pc = 0x292cu;

label_292c:
    // 0x292c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_2930:
    // 0x2930: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_2934:
    // 0x2934: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_2938:
    // 0x2938: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_293c:
    // 0x293c: 0x2653005c  addiu       $s3, $s2, 0x5C
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 92));
label_2940:
    // 0x2940: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_2944:
    // 0x2944: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
label_2948:
    // 0x2948: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
label_294c:
    // 0x294c: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_2950:
    // 0x2950: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_2954:
    // 0x2954: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_2958:
    // 0x2958: 0x8e660120  lw          $a2, 0x120($s3)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 288)));
label_295c:
    // 0x295c: 0x0  nop
    // NOP
label_2960:
    // 0x2960: 0x90c30000  lbu         $v1, 0x0($a2)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
label_2964:
    // 0x2964: 0x240200a1  addiu       $v0, $zero, 0xA1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 161));
label_2968:
    // 0x2968: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
label_296c:
    if (ctx->pc == 0x296Cu) {
        // 0x296c: 0xa0a821  addu        $s5, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        ctx->pc = 0x2970u;
        goto label_2970;
    }
    ctx->pc = 0x2968u;
    {
        const bool branch_taken_0x2968 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x296c: 0xa0a821  addu        $s5, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        if (branch_taken_0x2968) {
            ctx->pc = 0x299Cu;
            goto label_299c;
        }
    }
    ctx->pc = 0x2970u;
label_2970:
    // 0x2970: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2974:
    // 0x2974: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_2978:
    // 0x2978: 0x0  nop
    // NOP
label_297c:
    // 0x297c: 0x10400071  beqz        $v0, . + 4 + (0x71 << 2)
label_2980:
    if (ctx->pc == 0x2980u) {
        // 0x2980: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2984u;
        goto label_2984;
    }
    ctx->pc = 0x297Cu;
    {
        const bool branch_taken_0x297c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2980: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x297c) {
            ctx->pc = 0x2B44u;
            goto label_2b44;
        }
    }
    ctx->pc = 0x2984u;
label_2984:
    // 0x2984: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_2988:
    // 0x2988: 0x24843b20  addiu       $a0, $a0, 0x3B20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15136));
label_298c:
    // 0x298c: 0xc000de5  jal         func_003794
label_2990:
    if (ctx->pc == 0x2990u) {
        // 0x2990: 0x602821  addu        $a1, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        ctx->pc = 0x2994u;
        goto label_2994;
    }
    ctx->pc = 0x298Cu;
    SET_GPR_U32(ctx, 31, 0x2994u);
    // 0x2990: 0x602821  addu        $a1, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x298Cu, 0x2994u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2994u;
label_2994:
    // 0x2994: 0x8000ad1  j           func_002B44
label_2998:
    if (ctx->pc == 0x2998u) {
        // 0x2998: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x299Cu;
        goto label_299c;
    }
    ctx->pc = 0x2994u;
    // 0x2998: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2B44u;
    goto label_2b44;
    ctx->pc = 0x299Cu;
label_299c:
    // 0x299c: 0x24c20001  addiu       $v0, $a2, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_29a0:
    // 0x29a0: 0xae620120  sw          $v0, 0x120($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 288), GPR_U32(ctx, 2));
label_29a4:
    // 0x29a4: 0x90c40001  lbu         $a0, 0x1($a2)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
label_29a8:
    // 0x29a8: 0x24c20002  addiu       $v0, $a2, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
label_29ac:
    // 0x29ac: 0xae620120  sw          $v0, 0x120($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 288), GPR_U32(ctx, 2));
label_29b0:
    // 0x29b0: 0x24c20003  addiu       $v0, $a2, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 3));
label_29b4:
    // 0x29b4: 0x90c30002  lbu         $v1, 0x2($a2)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 2)));
label_29b8:
    // 0x29b8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_29bc:
    // 0x29bc: 0x24c63ec1  addiu       $a2, $a2, 0x3EC1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16065));
label_29c0:
    // 0x29c0: 0xae620120  sw          $v0, 0x120($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 288), GPR_U32(ctx, 2));
label_29c4:
    // 0x29c4: 0xa0c50000  sb          $a1, 0x0($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 5));
label_29c8:
    // 0x29c8: 0x8e620120  lw          $v0, 0x120($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 288)));
label_29cc:
    // 0x29cc: 0x4b200  sll         $s6, $a0, 8
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
label_29d0:
    // 0x29d0: 0xacc20003  sw          $v0, 0x3($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 3), GPR_U32(ctx, 2));
label_29d4:
    // 0x29d4: 0x32a200ff  andi        $v0, $s5, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)255);
label_29d8:
    // 0x29d8: 0x1040004a  beqz        $v0, . + 4 + (0x4A << 2)
label_29dc:
    if (ctx->pc == 0x29DCu) {
        // 0x29dc: 0x2c3b021  addu        $s6, $s6, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
        ctx->pc = 0x29E0u;
        goto label_29e0;
    }
    ctx->pc = 0x29D8u;
    {
        const bool branch_taken_0x29d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x29dc: 0x2c3b021  addu        $s6, $s6, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
        if (branch_taken_0x29d8) {
            ctx->pc = 0x2B04u;
            goto label_2b04;
        }
    }
    ctx->pc = 0x29E0u;
label_29e0:
    // 0x29e0: 0x8e740120  lw          $s4, 0x120($s3)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 288)));
label_29e4:
    // 0x29e4: 0x26500194  addiu       $s0, $s2, 0x194
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 404));
label_29e8:
    // 0x29e8: 0x24110008  addiu       $s1, $zero, 0x8
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_29ec:
    // 0x29ec: 0x24c40001  addiu       $a0, $a2, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_29f0:
    // 0x29f0: 0x26450198  addiu       $a1, $s2, 0x198
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 408));
label_29f4:
    // 0x29f4: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_29f8:
    // 0x29f8: 0x0  nop
    // NOP
label_29fc:
    // 0x29fc: 0x14540017  bne         $v0, $s4, . + 4 + (0x17 << 2)
label_2a00:
    if (ctx->pc == 0x2A00u) {
        ctx->pc = 0x2A04u;
        goto label_2a04;
    }
    ctx->pc = 0x29FCu;
    {
        const bool branch_taken_0x29fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        if (branch_taken_0x29fc) {
            ctx->pc = 0x2A5Cu;
            goto label_2a5c;
        }
    }
    ctx->pc = 0x2A04u;
label_2a04:
    // 0x2a04: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
label_2a08:
    // 0x2a08: 0x0  nop
    // NOP
label_2a0c:
    // 0x2a0c: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_2a10:
    // 0x2a10: 0x306200ff  andi        $v0, $v1, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
label_2a14:
    // 0x2a14: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
label_2a18:
    if (ctx->pc == 0x2A18u) {
        // 0x2a18: 0xa0a30000  sb          $v1, 0x0($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->pc = 0x2A1Cu;
        goto label_2a1c;
    }
    ctx->pc = 0x2A14u;
    {
        const bool branch_taken_0x2a14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2a18: 0xa0a30000  sb          $v1, 0x0($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
        if (branch_taken_0x2a14) {
            ctx->pc = 0x2A50u;
            goto label_2a50;
        }
    }
    ctx->pc = 0x2A1Cu;
label_2a1c:
    // 0x2a1c: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_2a20:
    // 0x2a20: 0x0  nop
    // NOP
label_2a24:
    // 0x2a24: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
label_2a28:
    if (ctx->pc == 0x2A28u) {
        // 0x2a28: 0x2a31023  subu        $v0, $s5, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
        ctx->pc = 0x2A2Cu;
        goto label_2a2c;
    }
    ctx->pc = 0x2A24u;
    {
        const bool branch_taken_0x2a24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2a28: 0x2a31023  subu        $v0, $s5, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
        if (branch_taken_0x2a24) {
            ctx->pc = 0x2A6Cu;
            goto label_2a6c;
        }
    }
    ctx->pc = 0x2A2Cu;
label_2a2c:
    // 0x2a2c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_2a30:
    // 0x2a30: 0xa0820000  sb          $v0, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
label_2a34:
    // 0x2a34: 0x8e450050  lw          $a1, 0x50($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
label_2a38:
    // 0x2a38: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_2a3c:
    // 0x2a3c: 0x0  nop
    // NOP
label_2a40:
    // 0x2a40: 0x40f809  jalr        $v0
label_2a44:
    if (ctx->pc == 0x2A44u) {
        // 0x2a44: 0x2484fffe  addiu       $a0, $a0, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
        ctx->pc = 0x2A48u;
        goto label_2a48;
    }
    ctx->pc = 0x2A40u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2A48u);
        // 0x2a44: 0x2484fffe  addiu       $a0, $a0, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2A40u, 0x2A48u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2A48u;
label_2a48:
    // 0x2a48: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_2a4c:
    if (ctx->pc == 0x2A4Cu) {
        ctx->pc = 0x2A50u;
        goto label_2a50;
    }
    ctx->pc = 0x2A48u;
    {
        const bool branch_taken_0x2a48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2a48) {
            ctx->pc = 0x2A6Cu;
            goto label_2a6c;
        }
    }
    ctx->pc = 0x2A50u;
label_2a50:
    // 0x2a50: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_2a54:
    // 0x2a54: 0x8000ad1  j           func_002B44
label_2a58:
    if (ctx->pc == 0x2A58u) {
        // 0x2a58: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2A5Cu;
        goto label_2a5c;
    }
    ctx->pc = 0x2A54u;
    // 0x2a58: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2B44u;
    goto label_2b44;
    ctx->pc = 0x2A5Cu;
label_2a5c:
    // 0x2a5c: 0x2631ffff  addiu       $s1, $s1, -0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_2a60:
    // 0x2a60: 0x24a50008  addiu       $a1, $a1, 0x8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
label_2a64:
    // 0x2a64: 0x1620ffe3  bnez        $s1, . + 4 + (-0x1D << 2)
label_2a68:
    if (ctx->pc == 0x2A68u) {
        // 0x2a68: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->pc = 0x2A6Cu;
        goto label_2a6c;
    }
    ctx->pc = 0x2A64u;
    {
        const bool branch_taken_0x2a64 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2a68: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        if (branch_taken_0x2a64) {
            ctx->pc = 0x29F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_29f4;
        }
    }
    ctx->pc = 0x2A6Cu;
label_2a6c:
    // 0x2a6c: 0x16200031  bnez        $s1, . + 4 + (0x31 << 2)
label_2a70:
    if (ctx->pc == 0x2A70u) {
        // 0x2a70: 0x26700138  addiu       $s0, $s3, 0x138 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 312));
        ctx->pc = 0x2A74u;
        goto label_2a74;
    }
    ctx->pc = 0x2A6Cu;
    {
        const bool branch_taken_0x2a6c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2a70: 0x26700138  addiu       $s0, $s3, 0x138 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 312));
        if (branch_taken_0x2a6c) {
            ctx->pc = 0x2B34u;
            goto label_2b34;
        }
    }
    ctx->pc = 0x2A74u;
label_2a74:
    // 0x2a74: 0x24110008  addiu       $s1, $zero, 0x8
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_2a78:
    // 0x2a78: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_2a7c:
    // 0x2a7c: 0x24843ec2  addiu       $a0, $a0, 0x3EC2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16066));
label_2a80:
    // 0x2a80: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2a84:
    // 0x2a84: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_2a88:
    // 0x2a88: 0x0  nop
    // NOP
label_2a8c:
    // 0x2a8c: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
label_2a90:
    if (ctx->pc == 0x2A90u) {
        ctx->pc = 0x2A94u;
        goto label_2a94;
    }
    ctx->pc = 0x2A8Cu;
    {
        const bool branch_taken_0x2a8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2a8c) {
            ctx->pc = 0x2AC8u;
            goto label_2ac8;
        }
    }
    ctx->pc = 0x2A94u;
label_2a94:
    // 0x2a94: 0xa0830000  sb          $v1, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
label_2a98:
    // 0x2a98: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_2a9c:
    // 0x2a9c: 0x0  nop
    // NOP
label_2aa0:
    // 0x2aa0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
label_2aa4:
    if (ctx->pc == 0x2AA4u) {
        ctx->pc = 0x2AA8u;
        goto label_2aa8;
    }
    ctx->pc = 0x2AA0u;
    {
        const bool branch_taken_0x2aa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2aa0) {
            ctx->pc = 0x2ABCu;
            goto label_2abc;
        }
    }
    ctx->pc = 0x2AA8u;
label_2aa8:
    // 0x2aa8: 0x8e450050  lw          $a1, 0x50($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
label_2aac:
    // 0x2aac: 0x40f809  jalr        $v0
label_2ab0:
    if (ctx->pc == 0x2AB0u) {
        // 0x2ab0: 0x2484fffe  addiu       $a0, $a0, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
        ctx->pc = 0x2AB4u;
        goto label_2ab4;
    }
    ctx->pc = 0x2AACu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2AB4u);
        // 0x2ab0: 0x2484fffe  addiu       $a0, $a0, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2AACu, 0x2AB4u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2AB4u;
label_2ab4:
    // 0x2ab4: 0x10400023  beqz        $v0, . + 4 + (0x23 << 2)
label_2ab8:
    if (ctx->pc == 0x2AB8u) {
        // 0x2ab8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2ABCu;
        goto label_2abc;
    }
    ctx->pc = 0x2AB4u;
    {
        const bool branch_taken_0x2ab4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2ab8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2ab4) {
            ctx->pc = 0x2B44u;
            goto label_2b44;
        }
    }
    ctx->pc = 0x2ABCu;
label_2abc:
    // 0x2abc: 0xae140000  sw          $s4, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 20));
label_2ac0:
    // 0x2ac0: 0x8000ab5  j           func_002AD4
label_2ac4:
    if (ctx->pc == 0x2AC4u) {
        // 0x2ac4: 0xa2150004  sb          $s5, 0x4($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 21));
        ctx->pc = 0x2AC8u;
        goto label_2ac8;
    }
    ctx->pc = 0x2AC0u;
    // 0x2ac4: 0xa2150004  sb          $s5, 0x4($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 21));
    ctx->pc = 0x2AD4u;
    goto label_2ad4;
    ctx->pc = 0x2AC8u;
label_2ac8:
    // 0x2ac8: 0x2631ffff  addiu       $s1, $s1, -0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_2acc:
    // 0x2acc: 0x1620ffed  bnez        $s1, . + 4 + (-0x13 << 2)
label_2ad0:
    if (ctx->pc == 0x2AD0u) {
        // 0x2ad0: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->pc = 0x2AD4u;
        goto label_2ad4;
    }
    ctx->pc = 0x2ACCu;
    {
        const bool branch_taken_0x2acc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2ad0: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        if (branch_taken_0x2acc) {
            ctx->pc = 0x2A84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2a84;
        }
    }
    ctx->pc = 0x2AD4u;
label_2ad4:
    // 0x2ad4: 0x16200017  bnez        $s1, . + 4 + (0x17 << 2)
label_2ad8:
    if (ctx->pc == 0x2AD8u) {
        ctx->pc = 0x2ADCu;
        goto label_2adc;
    }
    ctx->pc = 0x2AD4u;
    {
        const bool branch_taken_0x2ad4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x2ad4) {
            ctx->pc = 0x2B34u;
            goto label_2b34;
        }
    }
    ctx->pc = 0x2ADCu;
label_2adc:
    // 0x2adc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2ae0:
    // 0x2ae0: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
label_2ae4:
    // 0x2ae4: 0x0  nop
    // NOP
label_2ae8:
    // 0x2ae8: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
label_2aec:
    if (ctx->pc == 0x2AECu) {
        // 0x2aec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2AF0u;
        goto label_2af0;
    }
    ctx->pc = 0x2AE8u;
    {
        const bool branch_taken_0x2ae8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2aec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2ae8) {
            ctx->pc = 0x2B44u;
            goto label_2b44;
        }
    }
    ctx->pc = 0x2AF0u;
label_2af0:
    // 0x2af0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_2af4:
    // 0x2af4: 0xc000de5  jal         func_003794
label_2af8:
    if (ctx->pc == 0x2AF8u) {
        // 0x2af8: 0x24843b40  addiu       $a0, $a0, 0x3B40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15168));
        ctx->pc = 0x2AFCu;
        goto label_2afc;
    }
    ctx->pc = 0x2AF4u;
    SET_GPR_U32(ctx, 31, 0x2AFCu);
    // 0x2af8: 0x24843b40  addiu       $a0, $a0, 0x3B40 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15168));
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x2AF4u, 0x2AFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2AFCu;
label_2afc:
    // 0x2afc: 0x8000ad1  j           func_002B44
label_2b00:
    if (ctx->pc == 0x2B00u) {
        // 0x2b00: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2B04u;
        goto label_2b04;
    }
    ctx->pc = 0x2AFCu;
    // 0x2b00: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2B44u;
    goto label_2b44;
    ctx->pc = 0x2B04u;
label_2b04:
    // 0x2b04: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_2b08:
    // 0x2b08: 0x0  nop
    // NOP
label_2b0c:
    // 0x2b0c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
label_2b10:
    if (ctx->pc == 0x2B10u) {
        ctx->pc = 0x2B14u;
        goto label_2b14;
    }
    ctx->pc = 0x2B0Cu;
    {
        const bool branch_taken_0x2b0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2b0c) {
            ctx->pc = 0x2B34u;
            goto label_2b34;
        }
    }
    ctx->pc = 0x2B14u;
label_2b14:
    // 0x2b14: 0xa0c00001  sb          $zero, 0x1($a2)
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 0));
label_2b18:
    // 0x2b18: 0x8e450050  lw          $a1, 0x50($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
label_2b1c:
    // 0x2b1c: 0x8e42004c  lw          $v0, 0x4C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_2b20:
    // 0x2b20: 0x0  nop
    // NOP
label_2b24:
    // 0x2b24: 0x40f809  jalr        $v0
label_2b28:
    if (ctx->pc == 0x2B28u) {
        // 0x2b28: 0x24c4ffff  addiu       $a0, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->pc = 0x2B2Cu;
        goto label_2b2c;
    }
    ctx->pc = 0x2B24u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2B2Cu);
        // 0x2b28: 0x24c4ffff  addiu       $a0, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2B24u, 0x2B2Cu, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2B2Cu;
label_2b2c:
    // 0x2b2c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_2b30:
    if (ctx->pc == 0x2B30u) {
        // 0x2b30: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2B34u;
        goto label_2b34;
    }
    ctx->pc = 0x2B2Cu;
    {
        const bool branch_taken_0x2b2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2b30: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2b2c) {
            ctx->pc = 0x2B44u;
            goto label_2b44;
        }
    }
    ctx->pc = 0x2B34u;
label_2b34:
    // 0x2b34: 0x8e63011c  lw          $v1, 0x11C($s3)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 284)));
label_2b38:
    // 0x2b38: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2b3c:
    // 0x2b3c: 0x761821  addu        $v1, $v1, $s6
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
label_2b40:
    // 0x2b40: 0xae630120  sw          $v1, 0x120($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 288), GPR_U32(ctx, 3));
label_2b44:
    // 0x2b44: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_2b48:
    // 0x2b48: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_2b4c:
    // 0x2b4c: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_2b50:
    // 0x2b50: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_2b54:
    // 0x2b54: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_2b58:
    // 0x2b58: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_2b5c:
    // 0x2b5c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_2b60:
    // 0x2b60: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_2b64:
    // 0x2b64: 0x3e00008  jr          $ra
label_2b68:
    if (ctx->pc == 0x2B68u) {
        // 0x2b68: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x2B6Cu;
        goto label_fallthrough_0x2b64;
    }
    ctx->pc = 0x2B64u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2b68: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2B64u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x2b64:
    ctx->pc = 0x2B6Cu;
}


// Function: modmidi_00002b6c
// Address: 0x2b6c - 0x2f44
void modmidi_00002b6c_0x2b6c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002b6c_0x2b6c");
#endif

    switch (ctx->pc) {
        case 0x2ba4u: goto label_2ba4;
        case 0x2be4u: goto label_2be4;
        case 0x2becu: goto label_2bec;
        case 0x2bf0u: goto label_2bf0;
        case 0x2bfcu: goto label_2bfc;
        case 0x2c54u: goto label_2c54;
        case 0x2c84u: goto label_2c84;
        case 0x2ca0u: goto label_2ca0;
        case 0x2cb4u: goto label_2cb4;
        case 0x2cd0u: goto label_2cd0;
        case 0x2cecu: goto label_2cec;
        case 0x2d80u: goto label_2d80;
        case 0x2de8u: goto label_2de8;
        case 0x2e04u: goto label_2e04;
        case 0x2e20u: goto label_2e20;
        case 0x2e3cu: goto label_2e3c;
        case 0x2e88u: goto label_2e88;
        case 0x2e9cu: goto label_2e9c;
        case 0x2eb4u: goto label_2eb4;
        default: break;
    }

    ctx->pc = 0x2b6cu;

    // 0x2b6c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x2b70: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x2b74: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2b78: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x2b7c: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2b80: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x2b84: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2b88: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x2b8c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x2b90: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x2b94: 0x0  nop
    // NOP
    // 0x2b98: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x2b9c: 0x104000e2  beqz        $v0, . + 4 + (0xE2 << 2)
    ctx->pc = 0x2B9Cu;
    {
        const bool branch_taken_0x2b9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2ba0: 0x2630005c  addiu       $s0, $s1, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 92));
        if (branch_taken_0x2b9c) {
            ctx->pc = 0x2F28u;
            goto label_2f28;
        }
    }
    ctx->pc = 0x2BA4u;
label_2ba4:
    // 0x2ba4: 0x8e030120  lw          $v1, 0x120($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x2ba8: 0x0  nop
    // NOP
    // 0x2bac: 0x90650000  lbu         $a1, 0x0($v1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x2bb0: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x2bb4: 0xae020120  sw          $v0, 0x120($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
    // 0x2bb8: 0x240200a0  addiu       $v0, $zero, 0xA0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
    // 0x2bbc: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x2bc0: 0x10a20010  beq         $a1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x2BC0u;
    {
        const bool branch_taken_0x2bc0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x2bc4: 0x24620002  addiu       $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x2bc0) {
            ctx->pc = 0x2C04u;
            goto label_2c04;
        }
    }
    ctx->pc = 0x2BC8u;
    // 0x2bc8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2bcc: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x2bd0: 0x0  nop
    // NOP
    // 0x2bd4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x2BD4u;
    {
        const bool branch_taken_0x2bd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2bd8: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2bd4) {
            ctx->pc = 0x2BF0u;
            goto label_2bf0;
        }
    }
    ctx->pc = 0x2BDCu;
    // 0x2bdc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2be0: 0x24843b64  addiu       $a0, $a0, 0x3B64
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15204));
label_2be4:
    // 0x2be4: 0xc000de5  jal         func_003794
    ctx->pc = 0x2BE4u;
    SET_GPR_U32(ctx, 31, 0x2BECu);
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x2BE4u, 0x2BECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2BECu;
label_2bec:
    // 0x2bec: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_2bf0:
    // 0x2bf0: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2bf4: 0xc000bd1  jal         func_002F44
    ctx->pc = 0x2BF4u;
    SET_GPR_U32(ctx, 31, 0x2BFCu);
    // 0x2bf8: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2F44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F44u, 0x2BF4u, 0x2BFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2BFCu;
label_2bfc:
    // 0x2bfc: 0x8000bca  j           func_002F28
    ctx->pc = 0x2BFCu;
    ctx->pc = 0x2F28u;
    goto label_2f28;
    ctx->pc = 0x2C04u;
label_2c04:
    // 0x2c04: 0x90650001  lbu         $a1, 0x1($v1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x2c08: 0xae020120  sw          $v0, 0x120($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
    // 0x2c0c: 0x90670002  lbu         $a3, 0x2($v1)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x2c10: 0x24620003  addiu       $v0, $v1, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x2c14: 0xae020120  sw          $v0, 0x120($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
    // 0x2c18: 0x30a300ff  andi        $v1, $a1, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x2c1c: 0x2c620080  sltiu       $v0, $v1, 0x80
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x2c20: 0x104000b4  beqz        $v0, . + 4 + (0xB4 << 2)
    ctx->pc = 0x2C20u;
    {
        const bool branch_taken_0x2c20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2c24: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x2c20) {
            ctx->pc = 0x2EF4u;
            goto label_2ef4;
        }
    }
    ctx->pc = 0x2C28u;
    // 0x2c28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2c2c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2c30: 0x8c223bf0  lw          $v0, 0x3BF0($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 15344)));
    // 0x2c34: 0x0  nop
    // NOP
    // 0x2c38: 0x400008  jr          $v0
    ctx->pc = 0x2C38u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x2C40u: goto label_2c40;
            case 0x2C70u: goto label_2c70;
            case 0x2C8Cu: goto label_2c8c;
            case 0x2CA8u: goto label_2ca8;
            case 0x2CBCu: goto label_2cbc;
            case 0x2CD8u: goto label_2cd8;
            case 0x2CF4u: goto label_2cf4;
            case 0x2D3Cu: goto label_2d3c;
            case 0x2D74u: goto label_2d74;
            case 0x2D88u: goto label_2d88;
            case 0x2DF8u: goto label_2df8;
            case 0x2E0Cu: goto label_2e0c;
            case 0x2E28u: goto label_2e28;
            case 0x2E44u: goto label_2e44;
            case 0x2EF4u: goto label_2ef4;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2C38u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x2C40u;
label_2c40:
    // 0x2c40: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2c44: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2c48: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2c4c: 0xc000a19  jal         func_002864
    ctx->pc = 0x2C4Cu;
    SET_GPR_U32(ctx, 31, 0x2C54u);
    // 0x2c50: 0x30e700ff  andi        $a3, $a3, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x2864u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2864u, 0x2C4Cu, 0x2C54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C54u;
label_2c54:
    // 0x2c54: 0x144000b4  bnez        $v0, . + 4 + (0xB4 << 2)
    ctx->pc = 0x2C54u;
    {
        const bool branch_taken_0x2c54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2c54) {
            ctx->pc = 0x2F28u;
            goto label_2f28;
        }
    }
    ctx->pc = 0x2C5Cu;
    // 0x2c5c: 0x92020130  lbu         $v0, 0x130($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x2c60: 0x0  nop
    // NOP
    // 0x2c64: 0x304200fb  andi        $v0, $v0, 0xFB
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)251);
    // 0x2c68: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2C68u;
    // 0x2c6c: 0xa2020130  sb          $v0, 0x130($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 304), (uint8_t)GPR_U32(ctx, 2));
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2C70u;
label_2c70:
    // 0x2c70: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2c74: 0x9202012d  lbu         $v0, 0x12D($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 301)));
    // 0x2c78: 0x30e500ff  andi        $a1, $a3, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2c7c: 0xc0009fd  jal         func_0027F4
    ctx->pc = 0x2C7Cu;
    SET_GPR_U32(ctx, 31, 0x2C84u);
    // 0x2c80: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0x27F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F4u, 0x2C7Cu, 0x2C84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C84u;
label_2c84:
    // 0x2c84: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2C84u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2C8Cu;
label_2c8c:
    // 0x2c8c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2c90: 0x9202012d  lbu         $v0, 0x12D($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 301)));
    // 0x2c94: 0x30e500ff  andi        $a1, $a3, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2c98: 0xc0009fd  jal         func_0027F4
    ctx->pc = 0x2C98u;
    SET_GPR_U32(ctx, 31, 0x2CA0u);
    // 0x2c9c: 0x452823  subu        $a1, $v0, $a1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    ctx->pc = 0x27F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F4u, 0x2C98u, 0x2CA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CA0u;
label_2ca0:
    // 0x2ca0: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2CA0u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2CA8u;
label_2ca8:
    // 0x2ca8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2cac: 0xc000a06  jal         func_002818
    ctx->pc = 0x2CACu;
    SET_GPR_U32(ctx, 31, 0x2CB4u);
    // 0x2cb0: 0x30e500ff  andi        $a1, $a3, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x2818u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2818u, 0x2CACu, 0x2CB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CB4u;
label_2cb4:
    // 0x2cb4: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2CB4u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2CBCu;
label_2cbc:
    // 0x2cbc: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2cc0: 0x92020132  lbu         $v0, 0x132($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 306)));
    // 0x2cc4: 0x30e500ff  andi        $a1, $a3, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2cc8: 0xc000a06  jal         func_002818
    ctx->pc = 0x2CC8u;
    SET_GPR_U32(ctx, 31, 0x2CD0u);
    // 0x2ccc: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0x2818u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2818u, 0x2CC8u, 0x2CD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CD0u;
label_2cd0:
    // 0x2cd0: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2CD0u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2CD8u;
label_2cd8:
    // 0x2cd8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2cdc: 0x92020132  lbu         $v0, 0x132($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 306)));
    // 0x2ce0: 0x30e500ff  andi        $a1, $a3, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2ce4: 0xc000a06  jal         func_002818
    ctx->pc = 0x2CE4u;
    SET_GPR_U32(ctx, 31, 0x2CECu);
    // 0x2ce8: 0x452823  subu        $a1, $v0, $a1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    ctx->pc = 0x2818u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2818u, 0x2CE4u, 0x2CECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2CECu;
label_2cec:
    // 0x2cec: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2CECu;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2CF4u;
label_2cf4:
    // 0x2cf4: 0x30e400ff  andi        $a0, $a3, 0xFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2cf8: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x2cfc: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x2d00: 0x21980  sll         $v1, $v0, 6
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x2d04: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2d08: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2d0c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x2d10: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2d14: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x2d18: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x2d1c: 0x8c633ed0  lw          $v1, 0x3ED0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16080)));
    // 0x2d20: 0x21300  sll         $v0, $v0, 12
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 12));
    // 0x2d24: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2D24u;
    {
        const bool branch_taken_0x2d24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x2d28: 0x43001b  divu        $zero, $v0, $v1 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
        if (branch_taken_0x2d24) {
            ctx->pc = 0x2D30u;
            goto label_2d30;
        }
    }
    ctx->pc = 0x2D2Cu;
    // 0x2d2c: 0x7000d  break       7
    ctx->pc = 0x2d2cu;
    runtime->handleBreak(rdram, ctx);
label_2d30:
    // 0x2d30: 0x1012  mflo        $v0
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x2d34: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2D34u;
    // 0x2d38: 0xae020124  sw          $v0, 0x124($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 292), GPR_U32(ctx, 2));
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2D3Cu;
label_2d3c:
    // 0x2d3c: 0x9203012d  lbu         $v1, 0x12D($s0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 301)));
    // 0x2d40: 0x30e200ff  andi        $v0, $a3, 0xFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2d44: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2D44u;
    {
        const bool branch_taken_0x2d44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x2d44) {
            ctx->pc = 0x2D58u;
            goto label_2d58;
        }
    }
    ctx->pc = 0x2D4Cu;
    // 0x2d4c: 0x8e020124  lw          $v0, 0x124($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 292)));
    // 0x2d50: 0x8000b57  j           func_002D5C
    ctx->pc = 0x2D50u;
    // 0x2d54: 0xae020128  sw          $v0, 0x128($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
    ctx->pc = 0x2D5Cu;
    goto label_2d5c;
    ctx->pc = 0x2D58u;
label_2d58:
    // 0x2d58: 0xae000128  sw          $zero, 0x128($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 0));
label_2d5c:
    // 0x2d5c: 0x8e020128  lw          $v0, 0x128($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x2d60: 0x0  nop
    // NOP
    // 0x2d64: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2D64u;
    {
        const bool branch_taken_0x2d64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2d68: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x2d64) {
            ctx->pc = 0x2D78u;
            goto label_2d78;
        }
    }
    ctx->pc = 0x2D6Cu;
    // 0x2d6c: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2D6Cu;
    // 0x2d70: 0xa207012c  sb          $a3, 0x12C($s0) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 16), 300), (uint8_t)GPR_U32(ctx, 7));
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2D74u;
label_2d74:
    // 0x2d74: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_2d78:
    // 0x2d78: 0xc0009fd  jal         func_0027F4
    ctx->pc = 0x2D78u;
    SET_GPR_U32(ctx, 31, 0x2D80u);
    // 0x2d7c: 0x30e500ff  andi        $a1, $a3, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x27F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F4u, 0x2D78u, 0x2D80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D80u;
label_2d80:
    // 0x2d80: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2D80u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2D88u;
label_2d88:
    // 0x2d88: 0x92020130  lbu         $v0, 0x130($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x2d8c: 0x0  nop
    // NOP
    // 0x2d90: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x2d94: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x2D94u;
    {
        const bool branch_taken_0x2d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2d98: 0x240200a1  addiu       $v0, $zero, 0xA1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 161));
        if (branch_taken_0x2d94) {
            ctx->pc = 0x2DDCu;
            goto label_2ddc;
        }
    }
    ctx->pc = 0x2D9Cu;
    // 0x2d9c: 0x8e030120  lw          $v1, 0x120($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x2da0: 0x0  nop
    // NOP
    // 0x2da4: 0x90650000  lbu         $a1, 0x0($v1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x2da8: 0x0  nop
    // NOP
    // 0x2dac: 0x10a20009  beq         $a1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2DACu;
    {
        const bool branch_taken_0x2dac = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        // 0x2db0: 0x24620003  addiu       $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
        if (branch_taken_0x2dac) {
            ctx->pc = 0x2DD4u;
            goto label_2dd4;
        }
    }
    ctx->pc = 0x2DB4u;
    // 0x2db4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2db8: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x2dbc: 0x0  nop
    // NOP
    // 0x2dc0: 0x1040ff8b  beqz        $v0, . + 4 + (-0x75 << 2)
    ctx->pc = 0x2DC0u;
    {
        const bool branch_taken_0x2dc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2dc4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2dc0) {
            ctx->pc = 0x2BF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2bf0;
        }
    }
    ctx->pc = 0x2DC8u;
    // 0x2dc8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2dcc: 0x8000af9  j           func_002BE4
    ctx->pc = 0x2DCCu;
    // 0x2dd0: 0x24843b84  addiu       $a0, $a0, 0x3B84 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15236));
    ctx->pc = 0x2BE4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2be4;
    ctx->pc = 0x2DD4u;
label_2dd4:
    // 0x2dd4: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2DD4u;
    // 0x2dd8: 0xae020120  sw          $v0, 0x120($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2DDCu;
label_2ddc:
    // 0x2ddc: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2de0: 0xc000a4b  jal         func_00292C
    ctx->pc = 0x2DE0u;
    SET_GPR_U32(ctx, 31, 0x2DE8u);
    // 0x2de4: 0x30e500ff  andi        $a1, $a3, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x292Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x292Cu, 0x2DE0u, 0x2DE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DE8u;
label_2de8:
    // 0x2de8: 0x1040ff81  beqz        $v0, . + 4 + (-0x7F << 2)
    ctx->pc = 0x2DE8u;
    {
        const bool branch_taken_0x2de8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2dec: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2de8) {
            ctx->pc = 0x2BF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2bf0;
        }
    }
    ctx->pc = 0x2DF0u;
    // 0x2df0: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2DF0u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2DF8u;
label_2df8:
    // 0x2df8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2dfc: 0xc000a0f  jal         func_00283C
    ctx->pc = 0x2DFCu;
    SET_GPR_U32(ctx, 31, 0x2E04u);
    // 0x2e00: 0x30e500ff  andi        $a1, $a3, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x283Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x283Cu, 0x2DFCu, 0x2E04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E04u;
label_2e04:
    // 0x2e04: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2E04u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2E0Cu;
label_2e0c:
    // 0x2e0c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2e10: 0x92020133  lbu         $v0, 0x133($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 307)));
    // 0x2e14: 0x30e500ff  andi        $a1, $a3, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2e18: 0xc000a0f  jal         func_00283C
    ctx->pc = 0x2E18u;
    SET_GPR_U32(ctx, 31, 0x2E20u);
    // 0x2e1c: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0x283Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x283Cu, 0x2E18u, 0x2E20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E20u;
label_2e20:
    // 0x2e20: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2E20u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2E28u;
label_2e28:
    // 0x2e28: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2e2c: 0x92020133  lbu         $v0, 0x133($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 307)));
    // 0x2e30: 0x30e500ff  andi        $a1, $a3, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2e34: 0xc000a0f  jal         func_00283C
    ctx->pc = 0x2E34u;
    SET_GPR_U32(ctx, 31, 0x2E3Cu);
    // 0x2e38: 0x452823  subu        $a1, $v0, $a1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    ctx->pc = 0x283Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x283Cu, 0x2E34u, 0x2E3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E3Cu;
label_2e3c:
    // 0x2e3c: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2E3Cu;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2E44u;
label_2e44:
    // 0x2e44: 0x30e300ff  andi        $v1, $a3, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x2e48: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2e4c: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x2E4Cu;
    {
        const bool branch_taken_0x2e4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2e50: 0x28620002  slti        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x2e4c) {
            ctx->pc = 0x2EA4u;
            goto label_2ea4;
        }
    }
    ctx->pc = 0x2E54u;
    // 0x2e54: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2E54u;
    {
        const bool branch_taken_0x2e54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2e58: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        if (branch_taken_0x2e54) {
            ctx->pc = 0x2E6Cu;
            goto label_2e6c;
        }
    }
    ctx->pc = 0x2E5Cu;
    // 0x2e5c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x2E5Cu;
    {
        const bool branch_taken_0x2e5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x2e60: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2e5c) {
            ctx->pc = 0x2E7Cu;
            goto label_2e7c;
        }
    }
    ctx->pc = 0x2E64u;
    // 0x2e64: 0x8000bb5  j           func_002ED4
    ctx->pc = 0x2E64u;
    ctx->pc = 0x2ED4u;
    goto label_2ed4;
    ctx->pc = 0x2E6Cu;
label_2e6c:
    // 0x2e6c: 0x10620013  beq         $v1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x2E6Cu;
    {
        const bool branch_taken_0x2e6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x2e70: 0x2403fcff  addiu       $v1, $zero, -0x301 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966527));
        if (branch_taken_0x2e6c) {
            ctx->pc = 0x2EBCu;
            goto label_2ebc;
        }
    }
    ctx->pc = 0x2E74u;
    // 0x2e74: 0x8000bb5  j           func_002ED4
    ctx->pc = 0x2E74u;
    ctx->pc = 0x2ED4u;
    goto label_2ed4;
    ctx->pc = 0x2E7Cu;
label_2e7c:
    // 0x2e7c: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2e80: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x2E80u;
    SET_GPR_U32(ctx, 31, 0x2E88u);
    // 0x2e84: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x2E80u, 0x2E88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E88u;
label_2e88:
    // 0x2e88: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2e8c: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2e90: 0x240678b0  addiu       $a2, $zero, 0x78B0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 30896));
    // 0x2e94: 0xc000926  jal         func_002498
    ctx->pc = 0x2E94u;
    SET_GPR_U32(ctx, 31, 0x2E9Cu);
    // 0x2e98: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x2498u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2498u, 0x2E94u, 0x2E9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E9Cu;
label_2e9c:
    // 0x2e9c: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2E9Cu;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2EA4u;
label_2ea4:
    // 0x2ea4: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2ea8: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x2eac: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x2EACu;
    SET_GPR_U32(ctx, 31, 0x2EB4u);
    // 0x2eb0: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x2EACu, 0x2EB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EB4u;
label_2eb4:
    // 0x2eb4: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2EB4u;
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2EBCu;
label_2ebc:
    // 0x2ebc: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x2ec0: 0x0  nop
    // NOP
    // 0x2ec4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2ec8: 0x34420400  ori         $v0, $v0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1024);
    // 0x2ecc: 0x8000bc5  j           func_002F14
    ctx->pc = 0x2ECCu;
    // 0x2ed0: 0xae22000c  sw          $v0, 0xC($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    ctx->pc = 0x2F14u;
    goto label_2f14;
    ctx->pc = 0x2ED4u;
label_2ed4:
    // 0x2ed4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ed8: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x2edc: 0x0  nop
    // NOP
    // 0x2ee0: 0x1040ff42  beqz        $v0, . + 4 + (-0xBE << 2)
    ctx->pc = 0x2EE0u;
    {
        const bool branch_taken_0x2ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2ee4: 0x30e500ff  andi        $a1, $a3, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x2ee0) {
            ctx->pc = 0x2BECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2bec;
        }
    }
    ctx->pc = 0x2EE8u;
    // 0x2ee8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2eec: 0x8000af9  j           func_002BE4
    ctx->pc = 0x2EECu;
    // 0x2ef0: 0x24843bac  addiu       $a0, $a0, 0x3BAC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15276));
    ctx->pc = 0x2BE4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2be4;
    ctx->pc = 0x2EF4u;
label_2ef4:
    // 0x2ef4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x2ef8: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x2efc: 0x0  nop
    // NOP
    // 0x2f00: 0x1040ff3b  beqz        $v0, . + 4 + (-0xC5 << 2)
    ctx->pc = 0x2F00u;
    {
        const bool branch_taken_0x2f00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2f04: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x2f00) {
            ctx->pc = 0x2BF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2bf0;
        }
    }
    ctx->pc = 0x2F08u;
    // 0x2f08: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2f0c: 0x8000af9  j           func_002BE4
    ctx->pc = 0x2F0Cu;
    // 0x2f10: 0x24843bcc  addiu       $a0, $a0, 0x3BCC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15308));
    ctx->pc = 0x2BE4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2be4;
    ctx->pc = 0x2F14u;
label_2f14:
    // 0x2f14: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x2f18: 0x0  nop
    // NOP
    // 0x2f1c: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x2f20: 0x1440ff20  bnez        $v0, . + 4 + (-0xE0 << 2)
    ctx->pc = 0x2F20u;
    {
        const bool branch_taken_0x2f20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2f20) {
            ctx->pc = 0x2BA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2ba4;
        }
    }
    ctx->pc = 0x2F28u;
label_2f28:
    // 0x2f28: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2f2c: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2f30: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2f34: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2f38: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2f3c: 0x3e00008  jr          $ra
    ctx->pc = 0x2F3Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2f40: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2F3Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2F44u;
}


// Function: modmidi_00002f44
// Address: 0x2f44 - 0x30f0
void modmidi_00002f44_0x2f44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00002f44_0x2f44");
#endif

    switch (ctx->pc) {
        case 0x2f70u: goto label_2f70;
        case 0x2fecu: goto label_2fec;
        case 0x3020u: goto label_3020;
        case 0x3050u: goto label_3050;
        case 0x30c8u: goto label_30c8;
        default: break;
    }

    ctx->pc = 0x2f44u;

    // 0x2f44: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x2f48: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x2f4c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x2f50: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x2f54: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x2f58: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x2f5c: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x2f60: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x2f64: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x2f68: 0xc000985  jal         func_002614
    ctx->pc = 0x2F68u;
    SET_GPR_U32(ctx, 31, 0x2F70u);
    // 0x2f6c: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x2F68u, 0x2F70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2F70u;
label_2f70:
    // 0x2f70: 0x10400059  beqz        $v0, . + 4 + (0x59 << 2)
    ctx->pc = 0x2F70u;
    {
        const bool branch_taken_0x2f70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2f74: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2f70) {
            ctx->pc = 0x30D8u;
            goto label_30d8;
        }
    }
    ctx->pc = 0x2F78u;
    // 0x2f78: 0x8fa80010  lw          $t0, 0x10($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2f7c: 0x0  nop
    // NOP
    // 0x2f80: 0x8d030000  lw          $v1, 0x0($t0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x2f84: 0x0  nop
    // NOP
    // 0x2f88: 0x10620053  beq         $v1, $v0, . + 4 + (0x53 << 2)
    ctx->pc = 0x2F88u;
    {
        const bool branch_taken_0x2f88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x2f88) {
            ctx->pc = 0x30D8u;
            goto label_30d8;
        }
    }
    ctx->pc = 0x2F90u;
    // 0x2f90: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2f94: 0x12020024  beq         $s0, $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x2F94u;
    {
        const bool branch_taken_0x2f94 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x2f98: 0x2a020002  slti        $v0, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
        if (branch_taken_0x2f94) {
            ctx->pc = 0x3028u;
            goto label_3028;
        }
    }
    ctx->pc = 0x2F9Cu;
    // 0x2f9c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x2F9Cu;
    {
        const bool branch_taken_0x2f9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2fa0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x2f9c) {
            ctx->pc = 0x2FB4u;
            goto label_2fb4;
        }
    }
    ctx->pc = 0x2FA4u;
    // 0x2fa4: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2FA4u;
    {
        const bool branch_taken_0x2fa4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x2fa8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2fa4) {
            ctx->pc = 0x2FC4u;
            goto label_2fc4;
        }
    }
    ctx->pc = 0x2FACu;
    // 0x2fac: 0x8000c36  j           func_0030D8
    ctx->pc = 0x2FACu;
    ctx->pc = 0x30D8u;
    goto label_30d8;
    ctx->pc = 0x2FB4u;
label_2fb4:
    // 0x2fb4: 0x12020028  beq         $s0, $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x2FB4u;
    {
        const bool branch_taken_0x2fb4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x2fb8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x2fb4) {
            ctx->pc = 0x3058u;
            goto label_3058;
        }
    }
    ctx->pc = 0x2FBCu;
    // 0x2fbc: 0x8000c36  j           func_0030D8
    ctx->pc = 0x2FBCu;
    ctx->pc = 0x30D8u;
    goto label_30d8;
    ctx->pc = 0x2FC4u;
label_2fc4:
    // 0x2fc4: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x2fc8: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x2fcc: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x2fd0: 0x2403f8ff  addiu       $v1, $zero, -0x701
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294965503));
    // 0x2fd4: 0x8d02000c  lw          $v0, 0xC($t0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x2fd8: 0x8fa70014  lw          $a3, 0x14($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2fdc: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x2fe0: 0xad02000c  sw          $v0, 0xC($t0)
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 2));
    // 0x2fe4: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x2FE4u;
    SET_GPR_U32(ctx, 31, 0x2FECu);
    // 0x2fe8: 0xa0e00130  sb          $zero, 0x130($a3) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 7), 304), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x2FE4u, 0x2FECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2FECu;
label_2fec:
    // 0x2fec: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2ff0: 0x0  nop
    // NOP
    // 0x2ff4: 0x8c620128  lw          $v0, 0x128($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 296)));
    // 0x2ff8: 0x0  nop
    // NOP
    // 0x2ffc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x2FFCu;
    {
        const bool branch_taken_0x2ffc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2ffc) {
            ctx->pc = 0x3010u;
            goto label_3010;
        }
    }
    ctx->pc = 0x3004u;
    // 0x3004: 0x9062012c  lbu         $v0, 0x12C($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 300)));
    // 0x3008: 0xac600128  sw          $zero, 0x128($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 296), GPR_U32(ctx, 0));
    // 0x300c: 0xa062012d  sb          $v0, 0x12D($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 301), (uint8_t)GPR_U32(ctx, 2));
label_3010:
    // 0x3010: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3014: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3018: 0xc00099c  jal         func_002670
    ctx->pc = 0x3018u;
    SET_GPR_U32(ctx, 31, 0x3020u);
    // 0x301c: 0x24a5011c  addiu       $a1, $a1, 0x11C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 284));
    ctx->pc = 0x2670u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2670u, 0x3018u, 0x3020u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3020u;
label_3020:
    // 0x3020: 0x8000c36  j           func_0030D8
    ctx->pc = 0x3020u;
    // 0x3024: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x30D8u;
    goto label_30d8;
    ctx->pc = 0x3028u;
label_3028:
    // 0x3028: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x302c: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x3030: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x3034: 0x2402feff  addiu       $v0, $zero, -0x101
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967039));
    // 0x3038: 0x8d03000c  lw          $v1, 0xC($t0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x303c: 0x8fa70014  lw          $a3, 0x14($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3040: 0x621824  and         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x3044: 0xad03000c  sw          $v1, 0xC($t0)
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 3));
    // 0x3048: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x3048u;
    SET_GPR_U32(ctx, 31, 0x3050u);
    // 0x304c: 0xa0e00130  sb          $zero, 0x130($a3) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 7), 304), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x3048u, 0x3050u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3050u;
label_3050:
    // 0x3050: 0x8000c36  j           func_0030D8
    ctx->pc = 0x3050u;
    // 0x3054: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x30D8u;
    goto label_30d8;
    ctx->pc = 0x3058u;
label_3058:
    // 0x3058: 0x8d02000c  lw          $v0, 0xC($t0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x305c: 0x0  nop
    // NOP
    // 0x3060: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x3064: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x3064u;
    {
        const bool branch_taken_0x3064 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3068: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3064) {
            ctx->pc = 0x30D8u;
            goto label_30d8;
        }
    }
    ctx->pc = 0x306Cu;
    // 0x306c: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3070: 0x0  nop
    // NOP
    // 0x3074: 0x90430130  lbu         $v1, 0x130($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 304)));
    // 0x3078: 0x0  nop
    // NOP
    // 0x307c: 0x306300fc  andi        $v1, $v1, 0xFC
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)252);
    // 0x3080: 0xa0430130  sb          $v1, 0x130($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 304), (uint8_t)GPR_U32(ctx, 3));
    // 0x3084: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3088: 0x0  nop
    // NOP
    // 0x308c: 0x8c83000c  lw          $v1, 0xC($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x3090: 0x0  nop
    // NOP
    // 0x3094: 0x30620400  andi        $v0, $v1, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1024);
    // 0x3098: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x3098u;
    {
        const bool branch_taken_0x3098 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x309c: 0x2402fcff  addiu       $v0, $zero, -0x301 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966527));
        if (branch_taken_0x3098) {
            ctx->pc = 0x30A8u;
            goto label_30a8;
        }
    }
    ctx->pc = 0x30A0u;
    // 0x30a0: 0x8000c34  j           func_0030D0
    ctx->pc = 0x30A0u;
    // 0x30a4: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    ctx->pc = 0x30D0u;
    goto label_30d0;
    ctx->pc = 0x30A8u;
label_30a8:
    // 0x30a8: 0x30620200  andi        $v0, $v1, 0x200
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)512);
    // 0x30ac: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x30ACu;
    {
        const bool branch_taken_0x30ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x30b0: 0x34620100  ori         $v0, $v1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)256);
        if (branch_taken_0x30ac) {
            ctx->pc = 0x30D0u;
            goto label_30d0;
        }
    }
    ctx->pc = 0x30B4u;
    // 0x30b4: 0xac82000c  sw          $v0, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x30b8: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x30bc: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x30c0: 0xc0006ed  jal         func_001BB4
    ctx->pc = 0x30C0u;
    SET_GPR_U32(ctx, 31, 0x30C8u);
    // 0x30c4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x30C0u, 0x30C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30C8u;
label_30c8:
    // 0x30c8: 0x8000c36  j           func_0030D8
    ctx->pc = 0x30C8u;
    // 0x30cc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x30D8u;
    goto label_30d8;
    ctx->pc = 0x30D0u;
label_30d0:
    // 0x30d0: 0xac82000c  sw          $v0, 0xC($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x30d4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_30d8:
    // 0x30d8: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x30dc: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x30e0: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x30e4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x30e8: 0x3e00008  jr          $ra
    ctx->pc = 0x30E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x30ec: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x30E8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x30F0u;
}


// Function: modmidi_000030f0
// Address: 0x30f0 - 0x31dc
void modmidi_000030f0_0x30f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000030f0_0x30f0");
#endif

    switch (ctx->pc) {
        case 0x315cu: goto label_315c;
        case 0x3198u: goto label_3198;
        case 0x31c0u: goto label_31c0;
        default: break;
    }

    ctx->pc = 0x30f0u;

    // 0x30f0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x30f4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x30f8: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x30fc: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x3100: 0xc08821  addu        $s1, $a2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3104: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x3108: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x310c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x3110: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x3114: 0x0  nop
    // NOP
    // 0x3118: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x311c: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x311Cu;
    {
        const bool branch_taken_0x311c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3120: 0xa09821  addu        $s3, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        if (branch_taken_0x311c) {
            ctx->pc = 0x31C0u;
            goto label_31c0;
        }
    }
    ctx->pc = 0x3124u;
    // 0x3124: 0x2630005c  addiu       $s0, $s1, 0x5C
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 92));
    // 0x3128: 0x8e020128  lw          $v0, 0x128($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x312c: 0x0  nop
    // NOP
    // 0x3130: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x3130u;
    {
        const bool branch_taken_0x3130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3134: 0x2442ffff  addiu       $v0, $v0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
        if (branch_taken_0x3130) {
            ctx->pc = 0x315Cu;
            goto label_315c;
        }
    }
    ctx->pc = 0x3138u;
    // 0x3138: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3138u;
    {
        const bool branch_taken_0x3138 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x313c: 0xae020128  sw          $v0, 0x128($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
        if (branch_taken_0x3138) {
            ctx->pc = 0x314Cu;
            goto label_314c;
        }
    }
    ctx->pc = 0x3140u;
    // 0x3140: 0x9202012c  lbu         $v0, 0x12C($s0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 300)));
    // 0x3144: 0x0  nop
    // NOP
    // 0x3148: 0xa202012d  sb          $v0, 0x12D($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 301), (uint8_t)GPR_U32(ctx, 2));
label_314c:
    // 0x314c: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x3150: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x3154: 0xc000954  jal         func_002550
    ctx->pc = 0x3154u;
    SET_GPR_U32(ctx, 31, 0x315Cu);
    // 0x3158: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2550u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2550u, 0x3154u, 0x315Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x315Cu;
label_315c:
    // 0x315c: 0x8e28000c  lw          $t0, 0xC($s1)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x3160: 0x24020202  addiu       $v0, $zero, 0x202
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 514));
    // 0x3164: 0x31030202  andi        $v1, $t0, 0x202
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)514);
    // 0x3168: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x3168u;
    {
        const bool branch_taken_0x3168 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x3168) {
            ctx->pc = 0x31C0u;
            goto label_31c0;
        }
    }
    ctx->pc = 0x3170u;
    // 0x3170: 0x92070130  lbu         $a3, 0x130($s0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x3174: 0x0  nop
    // NOP
    // 0x3178: 0x30e20001  andi        $v0, $a3, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)1);
    // 0x317c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x317Cu;
    {
        const bool branch_taken_0x317c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3180: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x317c) {
            ctx->pc = 0x31B0u;
            goto label_31b0;
        }
    }
    ctx->pc = 0x3184u;
    // 0x3184: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x3188: 0x90a60131  lbu         $a2, 0x131($a1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 305)));
    // 0x318c: 0x31100700  andi        $s0, $t0, 0x700
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)1792);
    // 0x3190: 0xc000cf0  jal         func_0033C0
    ctx->pc = 0x3190u;
    SET_GPR_U32(ctx, 31, 0x3198u);
    // 0x3194: 0x30e70002  andi        $a3, $a3, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)2);
    ctx->pc = 0x33C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x33C0u, 0x3190u, 0x3198u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3198u;
label_3198:
    // 0x3198: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3198u;
    {
        const bool branch_taken_0x3198 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3198) {
            ctx->pc = 0x31C0u;
            goto label_31c0;
        }
    }
    ctx->pc = 0x31A0u;
    // 0x31a0: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x31a4: 0x0  nop
    // NOP
    // 0x31a8: 0x501025  or          $v0, $v0, $s0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 16));
    // 0x31ac: 0xae22000c  sw          $v0, 0xC($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
label_31b0:
    // 0x31b0: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x31b4: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x31b8: 0xc000adb  jal         func_002B6C
    ctx->pc = 0x31B8u;
    SET_GPR_U32(ctx, 31, 0x31C0u);
    // 0x31bc: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x2B6Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2B6Cu, 0x31B8u, 0x31C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31C0u;
label_31c0:
    // 0x31c0: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x31c4: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x31c8: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x31cc: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x31d0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x31d4: 0x3e00008  jr          $ra
    ctx->pc = 0x31D4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x31d8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x31D4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x31DCu;
}


// Function: modmidi_000031dc
// Address: 0x31dc - 0x324c
void modmidi_000031dc_0x31dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000031dc_0x31dc");
#endif

    switch (ctx->pc) {
        case 0x3208u: goto label_3208;
        case 0x3228u: goto label_3228;
        default: break;
    }

    ctx->pc = 0x31dcu;

    // 0x31dc: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x31e0: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x31e4: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x31e8: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x31ec: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x31f0: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x31f4: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x31f8: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x31fc: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x3200: 0xc000985  jal         func_002614
    ctx->pc = 0x3200u;
    SET_GPR_U32(ctx, 31, 0x3208u);
    // 0x3204: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x3200u, 0x3208u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3208u;
label_3208:
    // 0x3208: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3208u;
    {
        const bool branch_taken_0x3208 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x320c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x3208) {
            ctx->pc = 0x3230u;
            goto label_3230;
        }
    }
    ctx->pc = 0x3210u;
    // 0x3210: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3214: 0x0  nop
    // NOP
    // 0x3218: 0xa050012e  sb          $s0, 0x12E($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 302), (uint8_t)GPR_U32(ctx, 16));
    // 0x321c: 0x8fa60014  lw          $a2, 0x14($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3220: 0xc000954  jal         func_002550
    ctx->pc = 0x3220u;
    SET_GPR_U32(ctx, 31, 0x3228u);
    // 0x3224: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x2550u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2550u, 0x3220u, 0x3228u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3228u;
label_3228:
    // 0x3228: 0x8000c8d  j           func_003234
    ctx->pc = 0x3228u;
    // 0x322c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x3234u;
    goto label_3234;
    ctx->pc = 0x3230u;
label_3230:
    // 0x3230: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_3234:
    // 0x3234: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3238: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x323c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3240: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3244: 0x3e00008  jr          $ra
    ctx->pc = 0x3244u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3248: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3244u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x324Cu;
}


// Function: modmidi_0000324c
// Address: 0x324c - 0x32b8
void modmidi_0000324c_0x324c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000324c_0x324c");
#endif

    switch (ctx->pc) {
        case 0x3278u: goto label_3278;
        case 0x328cu: goto label_328c;
        case 0x329cu: goto label_329c;
        default: break;
    }

    ctx->pc = 0x324cu;

    // 0x324c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3250: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x3254: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3258: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x325c: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x3260: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x3264: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3268: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x326c: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x3270: 0xc000985  jal         func_002614
    ctx->pc = 0x3270u;
    SET_GPR_U32(ctx, 31, 0x3278u);
    // 0x3274: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x3270u, 0x3278u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3278u;
label_3278:
    // 0x3278: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3278u;
    {
        const bool branch_taken_0x3278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x327c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x3278) {
            ctx->pc = 0x32A0u;
            goto label_32a0;
        }
    }
    ctx->pc = 0x3280u;
    // 0x3280: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3284: 0xc0009fd  jal         func_0027F4
    ctx->pc = 0x3284u;
    SET_GPR_U32(ctx, 31, 0x328Cu);
    // 0x3288: 0x320500ff  andi        $a1, $s0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x27F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27F4u, 0x3284u, 0x328Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x328Cu;
label_328c:
    // 0x328c: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x3290: 0x8fa60014  lw          $a2, 0x14($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3294: 0xc000954  jal         func_002550
    ctx->pc = 0x3294u;
    SET_GPR_U32(ctx, 31, 0x329Cu);
    // 0x3298: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x2550u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2550u, 0x3294u, 0x329Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x329Cu;
label_329c:
    // 0x329c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_32a0:
    // 0x32a0: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x32a4: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x32a8: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x32ac: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x32b0: 0x3e00008  jr          $ra
    ctx->pc = 0x32B0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x32b4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x32B0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x32B8u;
}


// Function: modmidi_000032b8
// Address: 0x32b8 - 0x3344
void modmidi_000032b8_0x32b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000032b8_0x32b8");
#endif

    switch (ctx->pc) {
        case 0x32e4u: goto label_32e4;
        case 0x32f8u: goto label_32f8;
        case 0x3328u: goto label_3328;
        default: break;
    }

    ctx->pc = 0x32b8u;

    // 0x32b8: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x32bc: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x32c0: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x32c4: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x32c8: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x32cc: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x32d0: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x32d4: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x32d8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x32dc: 0xc000985  jal         func_002614
    ctx->pc = 0x32DCu;
    SET_GPR_U32(ctx, 31, 0x32E4u);
    // 0x32e0: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x32DCu, 0x32E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32E4u;
label_32e4:
    // 0x32e4: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x32E4u;
    {
        const bool branch_taken_0x32e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x32e8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x32e4) {
            ctx->pc = 0x332Cu;
            goto label_332c;
        }
    }
    ctx->pc = 0x32ECu;
    // 0x32ec: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x32f0: 0xc000a0f  jal         func_00283C
    ctx->pc = 0x32F0u;
    SET_GPR_U32(ctx, 31, 0x32F8u);
    // 0x32f4: 0x320500ff  andi        $a1, $s0, 0xFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    ctx->pc = 0x283Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x283Cu, 0x32F0u, 0x32F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x32F8u;
label_32f8:
    // 0x32f8: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x32fc: 0x0  nop
    // NOP
    // 0x3300: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x3304: 0x0  nop
    // NOP
    // 0x3308: 0x30420200  andi        $v0, $v0, 0x200
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)512);
    // 0x330c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x330Cu;
    {
        const bool branch_taken_0x330c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3310: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x330c) {
            ctx->pc = 0x3328u;
            goto label_3328;
        }
    }
    ctx->pc = 0x3314u;
    // 0x3314: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3318: 0x0  nop
    // NOP
    // 0x331c: 0x90460133  lbu         $a2, 0x133($v0)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 307)));
    // 0x3320: 0xc00089a  jal         func_002268
    ctx->pc = 0x3320u;
    SET_GPR_U32(ctx, 31, 0x3328u);
    // 0x3324: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x2268u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2268u, 0x3320u, 0x3328u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3328u;
label_3328:
    // 0x3328: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_332c:
    // 0x332c: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3330: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3334: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3338: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x333c: 0x3e00008  jr          $ra
    ctx->pc = 0x333Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3340: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x333Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3344u;
}


// Function: modmidi_00003344
// Address: 0x3344 - 0x33c0
void modmidi_00003344_0x3344(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00003344_0x3344");
#endif

    switch (ctx->pc) {
        case 0x3370u: goto label_3370;
        case 0x33a4u: goto label_33a4;
        default: break;
    }

    ctx->pc = 0x3344u;

    // 0x3344: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x3348: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x334c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x3350: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x3354: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x3358: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x335c: 0xc08021  addu        $s0, $a2, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x3360: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x3364: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x3368: 0xc000985  jal         func_002614
    ctx->pc = 0x3368u;
    SET_GPR_U32(ctx, 31, 0x3370u);
    // 0x336c: 0x27a70014  addiu       $a3, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x3368u, 0x3370u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3370u;
label_3370:
    // 0x3370: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x3370u;
    {
        const bool branch_taken_0x3370 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3374: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x3370) {
            ctx->pc = 0x33A8u;
            goto label_33a8;
        }
    }
    ctx->pc = 0x3378u;
    // 0x3378: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x337c: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3380: 0xa4700134  sh          $s0, 0x134($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 308), (uint16_t)GPR_U32(ctx, 16));
    // 0x3384: 0x8c42000c  lw          $v0, 0xC($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x3388: 0x0  nop
    // NOP
    // 0x338c: 0x30420200  andi        $v0, $v0, 0x200
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)512);
    // 0x3390: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3390u;
    {
        const bool branch_taken_0x3390 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3394: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x3390) {
            ctx->pc = 0x33A4u;
            goto label_33a4;
        }
    }
    ctx->pc = 0x3398u;
    // 0x3398: 0x3206ffff  andi        $a2, $s0, 0xFFFF
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x339c: 0xc0008da  jal         func_002368
    ctx->pc = 0x339Cu;
    SET_GPR_U32(ctx, 31, 0x33A4u);
    // 0x33a0: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x2368u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2368u, 0x339Cu, 0x33A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33A4u;
label_33a4:
    // 0x33a4: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_33a8:
    // 0x33a8: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x33ac: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x33b0: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x33b4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x33b8: 0x3e00008  jr          $ra
    ctx->pc = 0x33B8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x33bc: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x33B8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x33C0u;
}


// Function: modmidi_000033c0
// Address: 0x33c0 - 0x355c
void modmidi_000033c0_0x33c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000033c0_0x33c0");
#endif

    switch (ctx->pc) {
        case 0x33f8u: goto label_33f8;
        case 0x3414u: goto label_3414;
        case 0x3520u: goto label_3520;
        default: break;
    }

    ctx->pc = 0x33c0u;

    // 0x33c0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x33c4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x33c8: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x33cc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x33d0: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x33d4: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x33d8: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x33dc: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
    // 0x33e0: 0xe0a021  addu        $s4, $a3, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x33e4: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x33e8: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x33ec: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x33f0: 0xc00099c  jal         func_002670
    ctx->pc = 0x33F0u;
    SET_GPR_U32(ctx, 31, 0x33F8u);
    // 0x33f4: 0x2605011c  addiu       $a1, $s0, 0x11C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 284));
    ctx->pc = 0x2670u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2670u, 0x33F0u, 0x33F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33F8u;
label_33f8:
    // 0x33f8: 0x240b00a0  addiu       $t3, $zero, 0xA0
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
    // 0x33fc: 0x240a0011  addiu       $t2, $zero, 0x11
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x3400: 0x2409007f  addiu       $t1, $zero, 0x7F
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x3404: 0x240800a1  addiu       $t0, $zero, 0xA1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 161));
    // 0x3408: 0x8e070120  lw          $a3, 0x120($s0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x340c: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x3410: 0xa2020130  sb          $v0, 0x130($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 304), (uint8_t)GPR_U32(ctx, 2));
label_3414:
    // 0x3414: 0x8e030120  lw          $v1, 0x120($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x3418: 0x0  nop
    // NOP
    // 0x341c: 0x90650000  lbu         $a1, 0x0($v1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x3420: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3424: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x3428: 0x10ab0009  beq         $a1, $t3, . + 4 + (0x9 << 2)
    ctx->pc = 0x3428u;
    {
        const bool branch_taken_0x3428 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 11));
        // 0x342c: 0xae020120  sw          $v0, 0x120($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
        if (branch_taken_0x3428) {
            ctx->pc = 0x3450u;
            goto label_3450;
        }
    }
    ctx->pc = 0x3430u;
    // 0x3430: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3434: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x3438: 0x0  nop
    // NOP
    // 0x343c: 0x10400039  beqz        $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x343Cu;
    {
        const bool branch_taken_0x343c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3440: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x343c) {
            ctx->pc = 0x3524u;
            goto label_3524;
        }
    }
    ctx->pc = 0x3444u;
    // 0x3444: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3448: 0x8000d46  j           func_003518
    ctx->pc = 0x3448u;
    // 0x344c: 0x24843df0  addiu       $a0, $a0, 0x3DF0 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15856));
    ctx->pc = 0x3518u;
    goto label_3518;
    ctx->pc = 0x3450u;
label_3450:
    // 0x3450: 0x90650001  lbu         $a1, 0x1($v1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x3454: 0x24620002  addiu       $v0, $v1, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x3458: 0xae020120  sw          $v0, 0x120($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
    // 0x345c: 0x90660002  lbu         $a2, 0x2($v1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x3460: 0x24640003  addiu       $a0, $v1, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x3464: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x3468: 0x10aa001e  beq         $a1, $t2, . + 4 + (0x1E << 2)
    ctx->pc = 0x3468u;
    {
        const bool branch_taken_0x3468 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 10));
        // 0x346c: 0xae040120  sw          $a0, 0x120($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 4));
        if (branch_taken_0x3468) {
            ctx->pc = 0x34E4u;
            goto label_34e4;
        }
    }
    ctx->pc = 0x3470u;
    // 0x3470: 0x28a20012  slti        $v0, $a1, 0x12
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x3474: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x3474u;
    {
        const bool branch_taken_0x3474 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3474) {
            ctx->pc = 0x348Cu;
            goto label_348c;
        }
    }
    ctx->pc = 0x347Cu;
    // 0x347c: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x347Cu;
    {
        const bool branch_taken_0x347c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x347c) {
            ctx->pc = 0x349Cu;
            goto label_349c;
        }
    }
    ctx->pc = 0x3484u;
    // 0x3484: 0x8000d05  j           func_003414
    ctx->pc = 0x3484u;
    ctx->pc = 0x3414u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3414;
    ctx->pc = 0x348Cu;
label_348c:
    // 0x348c: 0x10a90011  beq         $a1, $t1, . + 4 + (0x11 << 2)
    ctx->pc = 0x348Cu;
    {
        const bool branch_taken_0x348c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 9));
        // 0x3490: 0x30c200ff  andi        $v0, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        if (branch_taken_0x348c) {
            ctx->pc = 0x34D4u;
            goto label_34d4;
        }
    }
    ctx->pc = 0x3494u;
    // 0x3494: 0x8000d05  j           func_003414
    ctx->pc = 0x3494u;
    ctx->pc = 0x3414u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3414;
    ctx->pc = 0x349Cu;
label_349c:
    // 0x349c: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x34a0: 0x271102b  sltu        $v0, $s3, $s1
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x34a4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x34A4u;
    {
        const bool branch_taken_0x34a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x34a4) {
            ctx->pc = 0x34CCu;
            goto label_34cc;
        }
    }
    ctx->pc = 0x34ACu;
    // 0x34ac: 0x16800003  bnez        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x34ACu;
    {
        const bool branch_taken_0x34ac = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0x34ac) {
            ctx->pc = 0x34BCu;
            goto label_34bc;
        }
    }
    ctx->pc = 0x34B4u;
    // 0x34b4: 0x8000d30  j           func_0034C0
    ctx->pc = 0x34B4u;
    // 0x34b8: 0xae030120  sw          $v1, 0x120($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 3));
    ctx->pc = 0x34C0u;
    goto label_34c0;
    ctx->pc = 0x34BCu;
label_34bc:
    // 0x34bc: 0xae070120  sw          $a3, 0x120($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 7));
label_34c0:
    // 0x34c0: 0xa2000130  sb          $zero, 0x130($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 304), (uint8_t)GPR_U32(ctx, 0));
    // 0x34c4: 0x8000d4f  j           func_00353C
    ctx->pc = 0x34C4u;
    // 0x34c8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x353Cu;
    goto label_353c;
    ctx->pc = 0x34CCu;
label_34cc:
    // 0x34cc: 0x8000d05  j           func_003414
    ctx->pc = 0x34CCu;
    // 0x34d0: 0x803821  addu        $a3, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x3414u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3414;
    ctx->pc = 0x34D4u;
label_34d4:
    // 0x34d4: 0x10450013  beq         $v0, $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x34D4u;
    {
        const bool branch_taken_0x34d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        // 0x34d8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x34d4) {
            ctx->pc = 0x3524u;
            goto label_3524;
        }
    }
    ctx->pc = 0x34DCu;
    // 0x34dc: 0x8000d05  j           func_003414
    ctx->pc = 0x34DCu;
    ctx->pc = 0x3414u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3414;
    ctx->pc = 0x34E4u;
label_34e4:
    // 0x34e4: 0x90650003  lbu         $a1, 0x3($v1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3)));
    // 0x34e8: 0x0  nop
    // NOP
    // 0x34ec: 0x14a80003  bne         $a1, $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x34ECu;
    {
        const bool branch_taken_0x34ec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 8));
        // 0x34f0: 0x24620006  addiu       $v0, $v1, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 6));
        if (branch_taken_0x34ec) {
            ctx->pc = 0x34FCu;
            goto label_34fc;
        }
    }
    ctx->pc = 0x34F4u;
    // 0x34f4: 0x8000d05  j           func_003414
    ctx->pc = 0x34F4u;
    // 0x34f8: 0xae020120  sw          $v0, 0x120($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 2));
    ctx->pc = 0x3414u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3414;
    ctx->pc = 0x34FCu;
label_34fc:
    // 0x34fc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x3500: 0x8c423e48  lw          $v0, 0x3E48($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 15944)));
    // 0x3504: 0x0  nop
    // NOP
    // 0x3508: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x3508u;
    {
        const bool branch_taken_0x3508 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x350c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3508) {
            ctx->pc = 0x3524u;
            goto label_3524;
        }
    }
    ctx->pc = 0x3510u;
    // 0x3510: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3514: 0x24843e10  addiu       $a0, $a0, 0x3E10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 15888));
label_3518:
    // 0x3518: 0xc000de5  jal         func_003794
    ctx->pc = 0x3518u;
    SET_GPR_U32(ctx, 31, 0x3520u);
    ctx->pc = 0x3794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3794u, 0x3518u, 0x3520u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3520u;
label_3520:
    // 0x3520: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3524:
    // 0x3524: 0x8e43000c  lw          $v1, 0xC($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x3528: 0x2404fcff  addiu       $a0, $zero, -0x301
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966527));
    // 0x352c: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x3530: 0x34630400  ori         $v1, $v1, 0x400
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1024);
    // 0x3534: 0xae43000c  sw          $v1, 0xC($s2)
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 3));
    // 0x3538: 0xa2000130  sb          $zero, 0x130($s0)
    WRITE8(ADD32(GPR_U32(ctx, 16), 304), (uint8_t)GPR_U32(ctx, 0));
label_353c:
    // 0x353c: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x3540: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3544: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x3548: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x354c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x3550: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3554: 0x3e00008  jr          $ra
    ctx->pc = 0x3554u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3558: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3554u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x355Cu;
}


// Function: modmidi_0000355c
// Address: 0x355c - 0x3744
void modmidi_0000355c_0x355c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000355c_0x355c");
#endif

    switch (ctx->pc) {
        case 0x355cu: goto label_355c;
        case 0x3560u: goto label_3560;
        case 0x3564u: goto label_3564;
        case 0x3568u: goto label_3568;
        case 0x356cu: goto label_356c;
        case 0x3570u: goto label_3570;
        case 0x3574u: goto label_3574;
        case 0x3578u: goto label_3578;
        case 0x357cu: goto label_357c;
        case 0x3580u: goto label_3580;
        case 0x3584u: goto label_3584;
        case 0x3588u: goto label_3588;
        case 0x358cu: goto label_358c;
        case 0x3590u: goto label_3590;
        case 0x3594u: goto label_3594;
        case 0x3598u: goto label_3598;
        case 0x359cu: goto label_359c;
        case 0x35a0u: goto label_35a0;
        case 0x35a4u: goto label_35a4;
        case 0x35a8u: goto label_35a8;
        case 0x35acu: goto label_35ac;
        case 0x35b0u: goto label_35b0;
        case 0x35b4u: goto label_35b4;
        case 0x35b8u: goto label_35b8;
        case 0x35bcu: goto label_35bc;
        case 0x35c0u: goto label_35c0;
        case 0x35c4u: goto label_35c4;
        case 0x35c8u: goto label_35c8;
        case 0x35ccu: goto label_35cc;
        case 0x35d0u: goto label_35d0;
        case 0x35d4u: goto label_35d4;
        case 0x35d8u: goto label_35d8;
        case 0x35dcu: goto label_35dc;
        case 0x35e0u: goto label_35e0;
        case 0x35e4u: goto label_35e4;
        case 0x35e8u: goto label_35e8;
        case 0x35ecu: goto label_35ec;
        case 0x35f0u: goto label_35f0;
        case 0x35f4u: goto label_35f4;
        case 0x35f8u: goto label_35f8;
        case 0x35fcu: goto label_35fc;
        case 0x3600u: goto label_3600;
        case 0x3604u: goto label_3604;
        case 0x3608u: goto label_3608;
        case 0x360cu: goto label_360c;
        case 0x3610u: goto label_3610;
        case 0x3614u: goto label_3614;
        case 0x3618u: goto label_3618;
        case 0x361cu: goto label_361c;
        case 0x3620u: goto label_3620;
        case 0x3624u: goto label_3624;
        case 0x3628u: goto label_3628;
        case 0x362cu: goto label_362c;
        case 0x3630u: goto label_3630;
        case 0x3634u: goto label_3634;
        case 0x3638u: goto label_3638;
        case 0x363cu: goto label_363c;
        case 0x3640u: goto label_3640;
        case 0x3644u: goto label_3644;
        case 0x3648u: goto label_3648;
        case 0x364cu: goto label_364c;
        case 0x3650u: goto label_3650;
        case 0x3654u: goto label_3654;
        case 0x3658u: goto label_3658;
        case 0x365cu: goto label_365c;
        case 0x3660u: goto label_3660;
        case 0x3664u: goto label_3664;
        case 0x3668u: goto label_3668;
        case 0x366cu: goto label_366c;
        case 0x3670u: goto label_3670;
        case 0x3674u: goto label_3674;
        case 0x3678u: goto label_3678;
        case 0x367cu: goto label_367c;
        case 0x3680u: goto label_3680;
        case 0x3684u: goto label_3684;
        case 0x3688u: goto label_3688;
        case 0x368cu: goto label_368c;
        case 0x3690u: goto label_3690;
        case 0x3694u: goto label_3694;
        case 0x3698u: goto label_3698;
        case 0x369cu: goto label_369c;
        case 0x36a0u: goto label_36a0;
        case 0x36a4u: goto label_36a4;
        case 0x36a8u: goto label_36a8;
        case 0x36acu: goto label_36ac;
        case 0x36b0u: goto label_36b0;
        case 0x36b4u: goto label_36b4;
        case 0x36b8u: goto label_36b8;
        case 0x36bcu: goto label_36bc;
        case 0x36c0u: goto label_36c0;
        case 0x36c4u: goto label_36c4;
        case 0x36c8u: goto label_36c8;
        case 0x36ccu: goto label_36cc;
        case 0x36d0u: goto label_36d0;
        case 0x36d4u: goto label_36d4;
        case 0x36d8u: goto label_36d8;
        case 0x36dcu: goto label_36dc;
        case 0x36e0u: goto label_36e0;
        case 0x36e4u: goto label_36e4;
        case 0x36e8u: goto label_36e8;
        case 0x36ecu: goto label_36ec;
        case 0x36f0u: goto label_36f0;
        case 0x36f4u: goto label_36f4;
        case 0x36f8u: goto label_36f8;
        case 0x36fcu: goto label_36fc;
        case 0x3700u: goto label_3700;
        case 0x3704u: goto label_3704;
        case 0x3708u: goto label_3708;
        case 0x370cu: goto label_370c;
        case 0x3710u: goto label_3710;
        case 0x3714u: goto label_3714;
        case 0x3718u: goto label_3718;
        case 0x371cu: goto label_371c;
        case 0x3720u: goto label_3720;
        case 0x3724u: goto label_3724;
        case 0x3728u: goto label_3728;
        case 0x372cu: goto label_372c;
        case 0x3730u: goto label_3730;
        case 0x3734u: goto label_3734;
        case 0x3738u: goto label_3738;
        case 0x373cu: goto label_373c;
        case 0x3740u: goto label_3740;
        default: break;
    }

    ctx->pc = 0x355cu;

label_355c:
    // 0x355c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_3560:
    // 0x3560: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_3564:
    // 0x3564: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_3568:
    // 0x3568: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_356c:
    // 0x356c: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_3570:
    // 0x3570: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_3574:
    // 0x3574: 0xc0a021  addu        $s4, $a2, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_3578:
    // 0x3578: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_357c:
    // 0x357c: 0xe08021  addu        $s0, $a3, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_3580:
    // 0x3580: 0x27a60010  addiu       $a2, $sp, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_3584:
    // 0x3584: 0x27a70014  addiu       $a3, $sp, 0x14
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
label_3588:
    // 0x3588: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_358c:
    // 0x358c: 0xc000985  jal         func_002614
label_3590:
    if (ctx->pc == 0x3590u) {
        // 0x3590: 0xafb30024  sw          $s3, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
        ctx->pc = 0x3594u;
        goto label_3594;
    }
    ctx->pc = 0x358Cu;
    SET_GPR_U32(ctx, 31, 0x3594u);
    // 0x3590: 0xafb30024  sw          $s3, 0x24($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    ctx->pc = 0x2614u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2614u, 0x358Cu, 0x3594u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3594u;
label_3594:
    // 0x3594: 0x1040002e  beqz        $v0, . + 4 + (0x2E << 2)
label_3598:
    if (ctx->pc == 0x3598u) {
        // 0x3598: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x359Cu;
        goto label_359c;
    }
    ctx->pc = 0x3594u;
    {
        const bool branch_taken_0x3594 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3598: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x3594) {
            ctx->pc = 0x3650u;
            goto label_3650;
        }
    }
    ctx->pc = 0x359Cu;
label_359c:
    // 0x359c: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_35a0:
    // 0x35a0: 0x0  nop
    // NOP
label_35a4:
    // 0x35a4: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_35a8:
    // 0x35a8: 0x0  nop
    // NOP
label_35ac:
    // 0x35ac: 0x10620031  beq         $v1, $v0, . + 4 + (0x31 << 2)
label_35b0:
    if (ctx->pc == 0x35B0u) {
        ctx->pc = 0x35B4u;
        goto label_35b4;
    }
    ctx->pc = 0x35ACu;
    {
        const bool branch_taken_0x35ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x35ac) {
            ctx->pc = 0x3674u;
            goto label_3674;
        }
    }
    ctx->pc = 0x35B4u;
label_35b4:
    // 0x35b4: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
label_35b8:
    // 0x35b8: 0x0  nop
    // NOP
label_35bc:
    // 0x35bc: 0x30530700  andi        $s3, $v0, 0x700
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1792);
label_35c0:
    // 0x35c0: 0x30420100  andi        $v0, $v0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
label_35c4:
    // 0x35c4: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
label_35c8:
    if (ctx->pc == 0x35C8u) {
        // 0x35c8: 0x32020001  andi        $v0, $s0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
        ctx->pc = 0x35CCu;
        goto label_35cc;
    }
    ctx->pc = 0x35C4u;
    {
        const bool branch_taken_0x35c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x35c8: 0x32020001  andi        $v0, $s0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
        if (branch_taken_0x35c4) {
            ctx->pc = 0x362Cu;
            goto label_362c;
        }
    }
    ctx->pc = 0x35CCu;
label_35cc:
    // 0x35cc: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
label_35d0:
    if (ctx->pc == 0x35D0u) {
        // 0x35d0: 0x32020002  andi        $v0, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)2);
        ctx->pc = 0x35D4u;
        goto label_35d4;
    }
    ctx->pc = 0x35CCu;
    {
        const bool branch_taken_0x35cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x35d0: 0x32020002  andi        $v0, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)2);
        if (branch_taken_0x35cc) {
            ctx->pc = 0x35F8u;
            goto label_35f8;
        }
    }
    ctx->pc = 0x35D4u;
label_35d4:
    // 0x35d4: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_35d8:
    // 0x35d8: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
label_35dc:
    if (ctx->pc == 0x35DCu) {
        // 0x35dc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x35E0u;
        goto label_35e0;
    }
    ctx->pc = 0x35D8u;
    {
        const bool branch_taken_0x35d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x35dc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x35d8) {
            ctx->pc = 0x35E4u;
            goto label_35e4;
        }
    }
    ctx->pc = 0x35E0u;
label_35e0:
    // 0x35e0: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_35e4:
    // 0x35e4: 0xa0620130  sb          $v0, 0x130($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 304), (uint8_t)GPR_U32(ctx, 2));
label_35e8:
    // 0x35e8: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_35ec:
    // 0x35ec: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_35f0:
    // 0x35f0: 0x8000d9d  j           func_003674
label_35f4:
    if (ctx->pc == 0x35F4u) {
        // 0x35f4: 0xa0740131  sb          $s4, 0x131($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 305), (uint8_t)GPR_U32(ctx, 20));
        ctx->pc = 0x35F8u;
        goto label_35f8;
    }
    ctx->pc = 0x35F0u;
    // 0x35f4: 0xa0740131  sb          $s4, 0x131($v1) (Delay Slot)
    WRITE8(ADD32(GPR_U32(ctx, 3), 305), (uint8_t)GPR_U32(ctx, 20));
    ctx->pc = 0x3674u;
    goto label_3674;
    ctx->pc = 0x35F8u;
label_35f8:
    // 0x35f8: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_35fc:
    // 0x35fc: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_3600:
    // 0x3600: 0xc0006ed  jal         func_001BB4
label_3604:
    if (ctx->pc == 0x3604u) {
        // 0x3604: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x3608u;
        goto label_3608;
    }
    ctx->pc = 0x3600u;
    SET_GPR_U32(ctx, 31, 0x3608u);
    // 0x3604: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1BB4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1BB4u, 0x3600u, 0x3608u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3608u;
label_3608:
    // 0x3608: 0x8fa30014  lw          $v1, 0x14($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_360c:
    // 0x360c: 0x0  nop
    // NOP
label_3610:
    // 0x3610: 0x8c620128  lw          $v0, 0x128($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 296)));
label_3614:
    // 0x3614: 0x0  nop
    // NOP
label_3618:
    // 0x3618: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_361c:
    if (ctx->pc == 0x361Cu) {
        // 0x361c: 0x2803021  addu        $a2, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x3620u;
        goto label_3620;
    }
    ctx->pc = 0x3618u;
    {
        const bool branch_taken_0x3618 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x361c: 0x2803021  addu        $a2, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0x3618) {
            ctx->pc = 0x3630u;
            goto label_3630;
        }
    }
    ctx->pc = 0x3620u;
label_3620:
    // 0x3620: 0x9062012c  lbu         $v0, 0x12C($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 300)));
label_3624:
    // 0x3624: 0xac600128  sw          $zero, 0x128($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 296), GPR_U32(ctx, 0));
label_3628:
    // 0x3628: 0xa062012d  sb          $v0, 0x12D($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 301), (uint8_t)GPR_U32(ctx, 2));
label_362c:
    // 0x362c: 0x2803021  addu        $a2, $s4, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_3630:
    // 0x3630: 0x103842  srl         $a3, $s0, 1
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 16), 1));
label_3634:
    // 0x3634: 0x38e70001  xori        $a3, $a3, 0x1
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) ^ (uint64_t)(uint16_t)1);
label_3638:
    // 0x3638: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_363c:
    // 0x363c: 0x8fa50014  lw          $a1, 0x14($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_3640:
    // 0x3640: 0xc000cf0  jal         func_0033C0
label_3644:
    if (ctx->pc == 0x3644u) {
        // 0x3644: 0x30e70001  andi        $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)1);
        ctx->pc = 0x3648u;
        goto label_3648;
    }
    ctx->pc = 0x3640u;
    SET_GPR_U32(ctx, 31, 0x3648u);
    // 0x3644: 0x30e70001  andi        $a3, $a3, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x33C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x33C0u, 0x3640u, 0x3648u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3648u;
label_3648:
    // 0x3648: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_364c:
    if (ctx->pc == 0x364Cu) {
        // 0x364c: 0x32620100  andi        $v0, $s3, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)256);
        ctx->pc = 0x3650u;
        goto label_3650;
    }
    ctx->pc = 0x3648u;
    {
        const bool branch_taken_0x3648 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x364c: 0x32620100  andi        $v0, $s3, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)256);
        if (branch_taken_0x3648) {
            ctx->pc = 0x3658u;
            goto label_3658;
        }
    }
    ctx->pc = 0x3650u;
label_3650:
    // 0x3650: 0x8000d9d  j           func_003674
label_3654:
    if (ctx->pc == 0x3654u) {
        // 0x3654: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x3658u;
        goto label_3658;
    }
    ctx->pc = 0x3650u;
    // 0x3654: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x3674u;
    goto label_3674;
    ctx->pc = 0x3658u;
label_3658:
    // 0x3658: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_365c:
    if (ctx->pc == 0x365Cu) {
        // 0x365c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x3660u;
        goto label_3660;
    }
    ctx->pc = 0x3658u;
    {
        const bool branch_taken_0x3658 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x365c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x3658) {
            ctx->pc = 0x3668u;
            goto label_3668;
        }
    }
    ctx->pc = 0x3660u;
label_3660:
    // 0x3660: 0x8000d9d  j           func_003674
label_3664:
    if (ctx->pc == 0x3664u) {
        // 0x3664: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x3668u;
        goto label_3668;
    }
    ctx->pc = 0x3660u;
    // 0x3664: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x3674u;
    goto label_3674;
    ctx->pc = 0x3668u;
label_3668:
    // 0x3668: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_366c:
    // 0x366c: 0xc000bd1  jal         func_002F44
label_3670:
    if (ctx->pc == 0x3670u) {
        // 0x3670: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x3674u;
        goto label_3674;
    }
    ctx->pc = 0x366Cu;
    SET_GPR_U32(ctx, 31, 0x3674u);
    // 0x3670: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x2F44u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2F44u, 0x366Cu, 0x3674u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3674u;
label_3674:
    // 0x3674: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_3678:
    // 0x3678: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_367c:
    // 0x367c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_3680:
    // 0x3680: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_3684:
    // 0x3684: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_3688:
    // 0x3688: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_368c:
    // 0x368c: 0x3e00008  jr          $ra
label_3690:
    if (ctx->pc == 0x3690u) {
        // 0x3690: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x3694u;
        goto label_3694;
    }
    ctx->pc = 0x368Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3690: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x368Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3694u;
label_3694:
    // 0x3694: 0x0  nop
    // NOP
label_3698:
    // 0x3698: 0x0  nop
    // NOP
label_369c:
    // 0x369c: 0x0  nop
    // NOP
label_36a0:
    // 0x36a0: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x36A0 raw=0x41C00000");
label_36a4:
    // 0x36a4: 0x0  nop
    // NOP
label_36a8:
    // 0x36a8: 0x105  .word       0x00000105                   # INVALID     $zero, $zero, 0x105 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x5 at 0x36A8 raw=0x00000105");
label_36ac:
    // 0x36ac: 0x6d646f6d  ldr         $a0, 0x6F6D($t3)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x36AC raw=0x6D646F6D");
label_36b0:
    // 0x36b0: 0x696469  .word       0x00696469                   # mtsa        $v1 # 00096440 <InstrIdType: R5900_SPECIAL>
    ctx->sa = GPR_U32(ctx, 3) & 0x7F;
label_36b4:
    // 0x36b4: 0x0  nop
    // NOP
label_36b8:
    // 0x36b8: 0x3720  .word       0x00003720                   # add         $a2, $zero, $zero # 00000700 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x36b8u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 6, (int32_t)result);     } }
label_36bc:
    // 0x36bc: 0x3720  .word       0x00003720                   # add         $a2, $zero, $zero # 00000700 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x36bcu;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 6, (int32_t)result);     } }
label_36c0:
    // 0x36c0: 0x3720  .word       0x00003720                   # add         $a2, $zero, $zero # 00000700 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x36c0u;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 6, (int32_t)result);     } }
label_36c4:
    // 0x36c4: 0x140  sll         $zero, $zero, 5
    
label_36c8:
    // 0x36c8: 0x6b0  tge         $zero, $zero, 26
    ctx->pc = 0x36c8u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_36cc:
    // 0x36cc: 0x3a8  .word       0x000003A8                   # mfsa        $zero # 00000380 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 0, ctx->sa);
label_36d0:
    // 0x36d0: 0x26a8  .word       0x000026A8                   # mfsa        $a0 # 00000680 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 4, ctx->sa);
label_36d4:
    // 0x36d4: 0x2f44  .word       0x00002F44                   # sllv        $a1, $zero, $zero # 00000740 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_36d8:
    // 0x36d8: 0x31dc  .word       0x000031DC                   # dmult       $zero, $zero # 000031C0 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0x36D8 raw=0x000031DC");
label_36dc:
    // 0x36dc: 0x324c  syscall     201
    ctx->pc = 0x36dcu;
    runtime->handleSyscall(rdram, ctx, 0xC9u);
label_36e0:
    // 0x36e0: 0x32b8  dsll        $a2, $zero, 10
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) << 10);
label_36e4:
    // 0x36e4: 0x3344  .word       0x00003344                   # sllv        $a2, $zero, $zero # 00000340 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_36e8:
    // 0x36e8: 0x355c  .word       0x0000355C                   # dmult       $zero, $zero # 00003540 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0x36E8 raw=0x0000355C");
label_36ec:
    // 0x36ec: 0x1d50  .word       0x00001D50                   # mfhi        $v1 # 00000540 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 3, ctx->hi);
label_36f0:
    // 0x36f0: 0x1bb4  teq         $zero, $zero, 110
    ctx->pc = 0x36f0u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_36f4:
    // 0x36f4: 0x1efc  dsll32      $v1, $zero, 27
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) << (32 + 27));
label_36f8:
    // 0x36f8: 0x2064  .word       0x00002064                   # and         $a0, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_36fc:
    // 0x36fc: 0x2154  .word       0x00002154                   # dsllv       $a0, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_3700:
    // 0x3700: 0x2268  .word       0x00002268                   # mfsa        $a0 # 00000240 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 4, ctx->sa);
label_3704:
    // 0x3704: 0x22cc  syscall     139
    ctx->pc = 0x3704u;
    runtime->handleSyscall(rdram, ctx, 0x8Bu);
label_3708:
    // 0x3708: 0x2368  .word       0x00002368                   # mfsa        $a0 # 00000340 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 4, ctx->sa);
label_370c:
    // 0x370c: 0x23b4  teq         $zero, $zero, 142
    ctx->pc = 0x370cu;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_3710:
    // 0x3710: 0x2404  .word       0x00002404                   # sllv        $a0, $zero, $zero # 00000400 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_3714:
    // 0x3714: 0x2448  .word       0x00002448                   # jr          $zero # 00002440 <InstrIdType: CPU_SPECIAL>
label_3718:
    if (ctx->pc == 0x3718u) {
        ctx->pc = 0x3718u;
        ctx->in_delay_slot = true;
        ctx->branch_pc = 0x3714u;
        // 0x3718: 0x56c  .word       0x0000056C                   # dadd        $zero, $zero, $zero # 00000540 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 0, r); }
        ctx->in_delay_slot = false;
        ctx->pc = 0x371Cu;
        goto label_371c;
    }
    ctx->pc = 0x3714u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        ctx->pc = 0x3718u;
        ctx->in_delay_slot = true;
        ctx->branch_pc = 0x3714u;
        // 0x3718: 0x56c  .word       0x0000056C                   # dadd        $zero, $zero, $zero # 00000540 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 0, r); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3714u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x371Cu;
label_371c:
    // 0x371c: 0x0  nop
    // NOP
label_3720:
    // 0x3720: 0x3e00008  jr          $ra
label_3724:
    if (ctx->pc == 0x3724u) {
        ctx->pc = 0x3728u;
        goto label_3728;
    }
    ctx->pc = 0x3720u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3720u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3728u;
label_3728:
    // 0x3728: 0x0  nop
    // NOP
label_372c:
    // 0x372c: 0x0  nop
    // NOP
label_3730:
    // 0x3730: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x3730 raw=0x41E00000");
label_3734:
    // 0x3734: 0x0  nop
    // NOP
label_3738:
    // 0x3738: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
label_373c:
    // 0x373c: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x373C raw=0x72746E69");
label_3740:
    // 0x3740: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: modmidi_00003744
// Address: 0x3744 - 0x374c
void modmidi_00003744_0x3744(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00003744_0x3744");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: modmidi_0000374c
// Address: 0x374c - 0x3770
void modmidi_0000374c_0x374c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_0000374c_0x374c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: modmidi_00003770
// Address: 0x3770 - 0x3794
void modmidi_00003770_0x3770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00003770_0x3770");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: modmidi_00003794
// Address: 0x3794 - 0x37b8
void modmidi_00003794_0x3794(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_00003794_0x3794");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: modmidi_000037b8
// Address: 0x37b8 - 0x37c0
void modmidi_000037b8_0x37b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000037b8_0x37b8");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 8u);
}


// Function: modmidi_000037c0
// Address: 0x37c0 - 0x37c8
void modmidi_000037c0_0x37c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000037c0_0x37c0");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 27u);
}


// Function: modmidi_000037c8
// Address: 0x37c8 - 0x37d0
void modmidi_000037c8_0x37c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modmidi_000037c8_0x37c8");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


