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

// Function: dbcman_00000000
// Address: 0x0 - 0x9c
void dbcman_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x18u: goto label_18;
        case 0x38u: goto label_38;
        case 0x48u: goto label_48;
        case 0x70u: goto label_70;
        case 0x78u: goto label_78;
        case 0x80u: goto label_80;
        case 0x88u: goto label_88;
        default: break;
    }

    ctx->pc = 0x0u;

    // 0x0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x4: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xc: 0x248420c0  addiu       $a0, $a0, 0x20C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8384));
    // 0x10: 0xc00085d  jal         func_002174
    ctx->pc = 0x10u;
    SET_GPR_U32(ctx, 31, 0x18u);
    ctx->pc = 0x2174u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2174u, 0x10u, 0x18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18u;
label_18:
    // 0x18: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x18u;
    {
        const bool branch_taken_0x18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18) {
            ctx->pc = 0x8Cu;
            goto label_8c;
        }
    }
    ctx->pc = 0x20u;
    // 0x20: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x24: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x28: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x2c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x30: 0xc00089e  jal         func_002278
    ctx->pc = 0x30u;
    SET_GPR_U32(ctx, 31, 0x38u);
    // 0x34: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    ctx->pc = 0x2278u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2278u, 0x30u, 0x38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38u;
label_38:
    // 0x38: 0x2404000f  addiu       $a0, $zero, 0xF
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x3c: 0x2403003c  addiu       $v1, $zero, 0x3C
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x40: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x44: 0xac222770  sw          $v0, 0x2770($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10096), GPR_U32(ctx, 2));
label_48:
    // 0x48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x50: 0xac202778  sw          $zero, 0x2778($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10104), GPR_U32(ctx, 0));
    // 0x54: 0x2484ffff  addiu       $a0, $a0, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x58: 0x481fffb  bgez        $a0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x58u;
    {
        const bool branch_taken_0x58 = (GPR_S32(ctx, 4) >= 0);
        // 0x5c: 0x2463fffc  addiu       $v1, $v1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
        if (branch_taken_0x58) {
            ctx->pc = 0x48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_48;
        }
    }
    ctx->pc = 0x60u;
    // 0x60: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x64: 0xac202774  sw          $zero, 0x2774($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10100), GPR_U32(ctx, 0));
    // 0x68: 0xc0007e6  jal         func_001F98
    ctx->pc = 0x68u;
    SET_GPR_U32(ctx, 31, 0x70u);
    ctx->pc = 0x1F98u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1F98u, 0x68u, 0x70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x70u;
label_70:
    // 0x70: 0xc000254  jal         func_000950
    ctx->pc = 0x70u;
    SET_GPR_U32(ctx, 31, 0x78u);
    ctx->pc = 0x950u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x950u, 0x70u, 0x78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x78u;
label_78:
    // 0x78: 0xc0003c8  jal         func_000F20
    ctx->pc = 0x78u;
    SET_GPR_U32(ctx, 31, 0x80u);
    ctx->pc = 0xF20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF20u, 0x78u, 0x80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x80u;
label_80:
    // 0x80: 0xc0004f0  jal         func_0013C0
    ctx->pc = 0x80u;
    SET_GPR_U32(ctx, 31, 0x88u);
    ctx->pc = 0x13C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x13C0u, 0x80u, 0x88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x88u;
label_88:
    // 0x88: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_8c:
    // 0x8c: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x90: 0x0  nop
    // NOP
    // 0x94: 0x3e00008  jr          $ra
    ctx->pc = 0x94u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x98: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x94u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9Cu;
}


// Function: dbcman_0000009c
// Address: 0x9c - 0xa4
void dbcman_0000009c_0x9c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_0000009c_0x9c");
#endif

    ctx->pc = 0x9cu;

    // 0x9c: 0x3e00008  jr          $ra
    ctx->pc = 0x9Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA4u;
}


// Function: dbcman_000000a4
// Address: 0xa4 - 0x158
void dbcman_000000a4_0xa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000000a4_0xa4");
#endif

    switch (ctx->pc) {
        case 0xccu: goto label_cc;
        case 0xfcu: goto label_fc;
        case 0x108u: goto label_108;
        case 0x114u: goto label_114;
        case 0x128u: goto label_128;
        case 0x130u: goto label_130;
        case 0x140u: goto label_140;
        default: break;
    }

    ctx->pc = 0xa4u;

    // 0xa4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa8: 0x8c422774  lw          $v0, 0x2774($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10100)));
    // 0xac: 0x27bdff60  addiu       $sp, $sp, -0xA0
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0xb0: 0xafbf009c  sw          $ra, 0x9C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 156), GPR_U32(ctx, 31));
    // 0xb4: 0xafb00098  sw          $s0, 0x98($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 152), GPR_U32(ctx, 16));
    // 0xb8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xB8u;
    {
        const bool branch_taken_0xb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xbc: 0xafa00090  sw          $zero, 0x90($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 0));
        if (branch_taken_0xb8) {
            ctx->pc = 0xD4u;
            goto label_d4;
        }
    }
    ctx->pc = 0xC0u;
    // 0xc0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xc4: 0xc00024c  jal         func_000930
    ctx->pc = 0xC4u;
    SET_GPR_U32(ctx, 31, 0xCCu);
    // 0xc8: 0x248422ac  addiu       $a0, $a0, 0x22AC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8876));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0xC4u, 0xCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCCu;
label_cc:
    // 0xcc: 0x8000052  j           func_000148
    ctx->pc = 0xCCu;
    // 0xd0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x148u;
    goto label_148;
    ctx->pc = 0xD4u;
label_d4:
    // 0xd4: 0x27a40090  addiu       $a0, $sp, 0x90
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0xd8: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xdc: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0xe0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xe4: 0x24422778  addiu       $v0, $v0, 0x2778
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10104));
    // 0xe8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xec: 0x24020080  addiu       $v0, $zero, 0x80
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0xf0: 0xae020008  sw          $v0, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0xf4: 0xc000852  jal         func_002148
    ctx->pc = 0xF4u;
    SET_GPR_U32(ctx, 31, 0xFCu);
    // 0xf8: 0xae00000c  sw          $zero, 0xC($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    ctx->pc = 0x2148u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2148u, 0xF4u, 0xFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFCu;
label_fc:
    // 0xfc: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x100: 0xc000877  jal         func_0021DC
    ctx->pc = 0x100u;
    SET_GPR_U32(ctx, 31, 0x108u);
    // 0x104: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x21DCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21DCu, 0x100u, 0x108u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x108u;
label_108:
    // 0x108: 0x8fa40090  lw          $a0, 0x90($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x10c: 0xc000854  jal         func_002150
    ctx->pc = 0x10Cu;
    SET_GPR_U32(ctx, 31, 0x114u);
    // 0x110: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2150u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2150u, 0x10Cu, 0x114u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x114u;
label_114:
    // 0x114: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x114u;
    {
        const bool branch_taken_0x114 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x114) {
            ctx->pc = 0x128u;
            goto label_128;
        }
    }
    ctx->pc = 0x11Cu;
    // 0x11c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x120: 0xc000849  jal         func_002124
    ctx->pc = 0x120u;
    SET_GPR_U32(ctx, 31, 0x128u);
    // 0x124: 0x248422cc  addiu       $a0, $a0, 0x22CC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8908));
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x120u, 0x128u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x128u;
label_128:
    // 0x128: 0xc000879  jal         func_0021E4
    ctx->pc = 0x128u;
    SET_GPR_U32(ctx, 31, 0x130u);
    // 0x12c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x21E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21E4u, 0x128u, 0x130u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x130u;
label_130:
    // 0x130: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x130u;
    {
        const bool branch_taken_0x130 = (GPR_S32(ctx, 2) < 0);
        // 0x134: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x130) {
            ctx->pc = 0x148u;
            goto label_148;
        }
    }
    ctx->pc = 0x138u;
    // 0x138: 0xc000895  jal         func_002254
    ctx->pc = 0x138u;
    SET_GPR_U32(ctx, 31, 0x140u);
    // 0x13c: 0x24040064  addiu       $a0, $zero, 0x64 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    ctx->pc = 0x2254u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2254u, 0x138u, 0x140u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x140u;
label_140:
    // 0x140: 0x800004a  j           func_000128
    ctx->pc = 0x140u;
    ctx->pc = 0x128u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_128;
    ctx->pc = 0x148u;
label_148:
    // 0x148: 0x8fbf009c  lw          $ra, 0x9C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
    // 0x14c: 0x8fb00098  lw          $s0, 0x98($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x150: 0x3e00008  jr          $ra
    ctx->pc = 0x150u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x154: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x150u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x158u;
}


// Function: dbcman_00000158
// Address: 0x158 - 0x188
void dbcman_00000158_0x158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000158_0x158");
#endif

    switch (ctx->pc) {
        case 0x168u: goto label_168;
        default: break;
    }

    ctx->pc = 0x158u;

    // 0x158: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x15c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x160: 0xc00025e  jal         func_000978
    ctx->pc = 0x160u;
    SET_GPR_U32(ctx, 31, 0x168u);
    ctx->pc = 0x978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x978u, 0x160u, 0x168u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x168u;
label_168:
    // 0x168: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x16c: 0x4600002  bltz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x16Cu;
    {
        const bool branch_taken_0x16c = (GPR_S32(ctx, 3) < 0);
        // 0x170: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        if (branch_taken_0x16c) {
            ctx->pc = 0x178u;
            goto label_178;
        }
    }
    ctx->pc = 0x174u;
    // 0x174: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_178:
    // 0x178: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c: 0x0  nop
    // NOP
    // 0x180: 0x3e00008  jr          $ra
    ctx->pc = 0x180u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x184: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x180u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x188u;
}


// Function: dbcman_00000188
// Address: 0x188 - 0x1bc
void dbcman_00000188_0x188(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000188_0x188");
#endif

    switch (ctx->pc) {
        case 0x198u: goto label_198;
        default: break;
    }

    ctx->pc = 0x188u;

    // 0x188: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x18c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x190: 0xc000287  jal         func_000A1C
    ctx->pc = 0x190u;
    SET_GPR_U32(ctx, 31, 0x198u);
    ctx->pc = 0xA1Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA1Cu, 0x190u, 0x198u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x198u;
label_198:
    // 0x198: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x19c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A0u;
    {
        const bool branch_taken_0x1a0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        // 0x1a4: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        if (branch_taken_0x1a0) {
            ctx->pc = 0x1ACu;
            goto label_1ac;
        }
    }
    ctx->pc = 0x1A8u;
    // 0x1a8: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1ac:
    // 0x1ac: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0: 0x0  nop
    // NOP
    // 0x1b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BCu;
}


// Function: dbcman_000001bc
// Address: 0x1bc - 0x280
void dbcman_000001bc_0x1bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000001bc_0x1bc");
#endif

    switch (ctx->pc) {
        case 0x1e8u: goto label_1e8;
        case 0x1f4u: goto label_1f4;
        case 0x210u: goto label_210;
        case 0x220u: goto label_220;
        case 0x238u: goto label_238;
        case 0x250u: goto label_250;
        case 0x264u: goto label_264;
        default: break;
    }

    ctx->pc = 0x1bcu;

    // 0x1bc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1c4: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1c8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1cc: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1d4: 0x248422e4  addiu       $a0, $a0, 0x22E4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8932));
    // 0x1d8: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1dc: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1e0: 0xc00024c  jal         func_000930
    ctx->pc = 0x1E0u;
    SET_GPR_U32(ctx, 31, 0x1E8u);
    // 0x1e4: 0xafb20018  sw          $s2, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0x1E0u, 0x1E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E8u;
label_1e8:
    // 0x1e8: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x1ec: 0xc0002a1  jal         func_000A84
    ctx->pc = 0x1ECu;
    SET_GPR_U32(ctx, 31, 0x1F4u);
    // 0x1f0: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xA84u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA84u, 0x1ECu, 0x1F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F4u;
label_1f4:
    // 0x1f4: 0x409021  addu        $s2, $v0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1f8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1fc: 0x12420006  beq         $s2, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1FCu;
    {
        const bool branch_taken_0x1fc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        if (branch_taken_0x1fc) {
            ctx->pc = 0x218u;
            goto label_218;
        }
    }
    ctx->pc = 0x204u;
    // 0x204: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x208: 0xc00024c  jal         func_000930
    ctx->pc = 0x208u;
    SET_GPR_U32(ctx, 31, 0x210u);
    // 0x20c: 0x24842300  addiu       $a0, $a0, 0x2300 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8960));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0x208u, 0x210u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x210u;
label_210:
    // 0x210: 0x800009a  j           func_000268
    ctx->pc = 0x210u;
    // 0x214: 0x2402ff9d  addiu       $v0, $zero, -0x63 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967197));
    ctx->pc = 0x268u;
    goto label_268;
    ctx->pc = 0x218u;
label_218:
    // 0x218: 0xc0005b8  jal         func_0016E0
    ctx->pc = 0x218u;
    SET_GPR_U32(ctx, 31, 0x220u);
    // 0x21c: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x16E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x16E0u, 0x218u, 0x220u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x220u;
label_220:
    // 0x220: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x224: 0x600000c  bltz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x224u;
    {
        const bool branch_taken_0x224 = (GPR_S32(ctx, 16) < 0);
        if (branch_taken_0x224) {
            ctx->pc = 0x258u;
            goto label_258;
        }
    }
    ctx->pc = 0x22Cu;
    // 0x22c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x230: 0xc00024c  jal         func_000930
    ctx->pc = 0x230u;
    SET_GPR_U32(ctx, 31, 0x238u);
    // 0x234: 0x2484232c  addiu       $a0, $a0, 0x232C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9004));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0x230u, 0x238u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x238u;
label_238:
    // 0x238: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x23c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x240: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x244: 0xac322778  sw          $s2, 0x2778($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10104), GPR_U32(ctx, 18));
    // 0x248: 0xc000029  jal         func_0000A4
    ctx->pc = 0x248u;
    SET_GPR_U32(ctx, 31, 0x250u);
    ctx->pc = 0xA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA4u, 0x248u, 0x250u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x250u;
label_250:
    // 0x250: 0x800009a  j           func_000268
    ctx->pc = 0x250u;
    // 0x254: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x268u;
    goto label_268;
    ctx->pc = 0x258u;
label_258:
    // 0x258: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x25c: 0xc00024c  jal         func_000930
    ctx->pc = 0x25Cu;
    SET_GPR_U32(ctx, 31, 0x264u);
    // 0x260: 0x24842308  addiu       $a0, $a0, 0x2308 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8968));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0x25Cu, 0x264u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x264u;
label_264:
    // 0x264: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_268:
    // 0x268: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x26c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x270: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x274: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x278: 0x3e00008  jr          $ra
    ctx->pc = 0x278u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x27c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x278u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x280u;
}


// Function: dbcman_00000280
// Address: 0x280 - 0x2f4
void dbcman_00000280_0x280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000280_0x280");
#endif

    switch (ctx->pc) {
        case 0x2a0u: goto label_2a0;
        case 0x2a8u: goto label_2a8;
        case 0x2c8u: goto label_2c8;
        case 0x2d0u: goto label_2d0;
        default: break;
    }

    ctx->pc = 0x280u;

    // 0x280: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x284: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x288: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x28c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x290: 0x2484234c  addiu       $a0, $a0, 0x234C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9036));
    // 0x294: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x298: 0xc00024c  jal         func_000930
    ctx->pc = 0x298u;
    SET_GPR_U32(ctx, 31, 0x2A0u);
    // 0x29c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0x298u, 0x2A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A0u;
label_2a0:
    // 0x2a0: 0xc0005b8  jal         func_0016E0
    ctx->pc = 0x2A0u;
    SET_GPR_U32(ctx, 31, 0x2A8u);
    // 0x2a4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x16E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x16E0u, 0x2A0u, 0x2A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A8u;
label_2a8:
    // 0x2a8: 0x4400007  bltz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x2A8u;
    {
        const bool branch_taken_0x2a8 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x2a8) {
            ctx->pc = 0x2C8u;
            goto label_2c8;
        }
    }
    ctx->pc = 0x2B0u;
    // 0x2b0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x2b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x2b8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x2bc: 0xac202778  sw          $zero, 0x2778($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10104), GPR_U32(ctx, 0));
    // 0x2c0: 0xc000029  jal         func_0000A4
    ctx->pc = 0x2C0u;
    SET_GPR_U32(ctx, 31, 0x2C8u);
    ctx->pc = 0xA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA4u, 0x2C0u, 0x2C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C8u;
label_2c8:
    // 0x2c8: 0xc0002da  jal         func_000B68
    ctx->pc = 0x2C8u;
    SET_GPR_U32(ctx, 31, 0x2D0u);
    // 0x2cc: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xB68u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xB68u, 0x2C8u, 0x2D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D0u;
label_2d0:
    // 0x2d0: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2d4: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2d8: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x2D8u;
    {
        const bool branch_taken_0x2d8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        // 0x2dc: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        if (branch_taken_0x2d8) {
            ctx->pc = 0x2E4u;
            goto label_2e4;
        }
    }
    ctx->pc = 0x2E0u;
    // 0x2e0: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_2e4:
    // 0x2e4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2e8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x2ec: 0x3e00008  jr          $ra
    ctx->pc = 0x2ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2f0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2F4u;
}


// Function: dbcman_000002f4
// Address: 0x2f4 - 0x31c
void dbcman_000002f4_0x2f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000002f4_0x2f4");
#endif

    switch (ctx->pc) {
        case 0x30cu: goto label_30c;
        default: break;
    }

    ctx->pc = 0x2f4u;

    // 0x2f4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2f8: 0x8c842770  lw          $a0, 0x2770($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10096)));
    // 0x2fc: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x300: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x304: 0xc0008a2  jal         func_002288
    ctx->pc = 0x304u;
    SET_GPR_U32(ctx, 31, 0x30Cu);
    ctx->pc = 0x2288u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2288u, 0x304u, 0x30Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30Cu;
label_30c:
    // 0x30c: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x310: 0x0  nop
    // NOP
    // 0x314: 0x3e00008  jr          $ra
    ctx->pc = 0x314u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x318: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x314u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x31Cu;
}


// Function: dbcman_0000031c
// Address: 0x31c - 0x428
void dbcman_0000031c_0x31c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_0000031c_0x31c");
#endif

    switch (ctx->pc) {
        case 0x348u: goto label_348;
        case 0x370u: goto label_370;
        case 0x388u: goto label_388;
        case 0x394u: goto label_394;
        case 0x3bcu: goto label_3bc;
        case 0x3d8u: goto label_3d8;
        case 0x3e4u: goto label_3e4;
        case 0x3f8u: goto label_3f8;
        case 0x408u: goto label_408;
        default: break;
    }

    ctx->pc = 0x31cu;

    // 0x31c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x320: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x324: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x328: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x32c: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x330: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x334: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x338: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x33c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x340: 0xc0005b8  jal         func_0016E0
    ctx->pc = 0x340u;
    SET_GPR_U32(ctx, 31, 0x348u);
    // 0x344: 0xafa00010  sw          $zero, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    ctx->pc = 0x16E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x16E0u, 0x340u, 0x348u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x348u;
label_348:
    // 0x348: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x34c: 0x600002f  bltz        $s0, . + 4 + (0x2F << 2)
    ctx->pc = 0x34Cu;
    {
        const bool branch_taken_0x34c = (GPR_S32(ctx, 16) < 0);
        // 0x350: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x34c) {
            ctx->pc = 0x40Cu;
            goto label_40c;
        }
    }
    ctx->pc = 0x354u;
    // 0x354: 0x3222007f  andi        $v0, $s1, 0x7F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)127);
    // 0x358: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x358u;
    {
        const bool branch_taken_0x358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x358) {
            ctx->pc = 0x378u;
            goto label_378;
        }
    }
    ctx->pc = 0x360u;
    // 0x360: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x364: 0x2484236c  addiu       $a0, $a0, 0x236C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9068));
    // 0x368: 0xc000849  jal         func_002124
    ctx->pc = 0x368u;
    SET_GPR_U32(ctx, 31, 0x370u);
    // 0x36c: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x368u, 0x370u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x370u;
label_370:
    // 0x370: 0x8000103  j           func_00040C
    ctx->pc = 0x370u;
    // 0x374: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x40Cu;
    goto label_40c;
    ctx->pc = 0x378u;
label_378:
    // 0x378: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x37c: 0x8c842770  lw          $a0, 0x2770($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10096)));
    // 0x380: 0xc0008a4  jal         func_002290
    ctx->pc = 0x380u;
    SET_GPR_U32(ctx, 31, 0x388u);
    ctx->pc = 0x2290u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2290u, 0x380u, 0x388u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x388u;
label_388:
    // 0x388: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x38c: 0xc000420  jal         func_001080
    ctx->pc = 0x38Cu;
    SET_GPR_U32(ctx, 31, 0x394u);
    // 0x390: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x1080u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1080u, 0x38Cu, 0x394u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x394u;
label_394:
    // 0x394: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x398: 0xac222734  sw          $v0, 0x2734($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10036), GPR_U32(ctx, 2));
    // 0x39c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3a0: 0xac332730  sw          $s3, 0x2730($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10032), GPR_U32(ctx, 19));
    // 0x3a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3a8: 0xac312738  sw          $s1, 0x2738($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10040), GPR_U32(ctx, 17));
    // 0x3ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x3b0: 0xac20273c  sw          $zero, 0x273C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10044), GPR_U32(ctx, 0));
    // 0x3b4: 0xc000852  jal         func_002148
    ctx->pc = 0x3B4u;
    SET_GPR_U32(ctx, 31, 0x3BCu);
    // 0x3b8: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x2148u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2148u, 0x3B4u, 0x3BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3BCu;
label_3bc:
    // 0x3bc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3c0: 0x24842730  addiu       $a0, $a0, 0x2730
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10032));
    // 0x3c4: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3c8: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3cc: 0x24c602f4  addiu       $a2, $a2, 0x2F4
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 756));
    // 0x3d0: 0xc00087d  jal         func_0021F4
    ctx->pc = 0x3D0u;
    SET_GPR_U32(ctx, 31, 0x3D8u);
    // 0x3d4: 0x3821  addu        $a3, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x21F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21F4u, 0x3D0u, 0x3D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D8u;
label_3d8:
    // 0x3d8: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x3dc: 0xc000854  jal         func_002150
    ctx->pc = 0x3DCu;
    SET_GPR_U32(ctx, 31, 0x3E4u);
    // 0x3e0: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2150u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2150u, 0x3DCu, 0x3E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E4u;
label_3e4:
    // 0x3e4: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x3E4u;
    {
        const bool branch_taken_0x3e4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x3e8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x3e4) {
            ctx->pc = 0x40Cu;
            goto label_40c;
        }
    }
    ctx->pc = 0x3ECu;
    // 0x3ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3f0: 0xc000849  jal         func_002124
    ctx->pc = 0x3F0u;
    SET_GPR_U32(ctx, 31, 0x3F8u);
    // 0x3f4: 0x248423a8  addiu       $a0, $a0, 0x23A8 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9128));
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x3F0u, 0x3F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3F8u;
label_3f8:
    // 0x3f8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3fc: 0x8c842770  lw          $a0, 0x2770($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10096)));
    // 0x400: 0xc0008a0  jal         func_002280
    ctx->pc = 0x400u;
    SET_GPR_U32(ctx, 31, 0x408u);
    ctx->pc = 0x2280u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2280u, 0x400u, 0x408u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x408u;
label_408:
    // 0x408: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_40c:
    // 0x40c: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x410: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x414: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x418: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x41c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x420: 0x3e00008  jr          $ra
    ctx->pc = 0x420u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x424: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x420u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x428u;
}


// Function: dbcman_00000428
// Address: 0x428 - 0x54c
void dbcman_00000428_0x428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000428_0x428");
#endif

    switch (ctx->pc) {
        case 0x454u: goto label_454;
        case 0x494u: goto label_494;
        case 0x4a4u: goto label_4a4;
        case 0x4b4u: goto label_4b4;
        case 0x4e0u: goto label_4e0;
        case 0x4fcu: goto label_4fc;
        case 0x508u: goto label_508;
        case 0x51cu: goto label_51c;
        case 0x52cu: goto label_52c;
        default: break;
    }

    ctx->pc = 0x428u;

    // 0x428: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x42c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x430: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x434: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x438: 0xc09821  addu        $s3, $a2, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x43c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x440: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x444: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x448: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x44c: 0xc0005b8  jal         func_0016E0
    ctx->pc = 0x44Cu;
    SET_GPR_U32(ctx, 31, 0x454u);
    // 0x450: 0xafa00010  sw          $zero, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    ctx->pc = 0x16E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x16E0u, 0x44Cu, 0x454u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x454u;
label_454:
    // 0x454: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x458: 0x4800035  bltz        $a0, . + 4 + (0x35 << 2)
    ctx->pc = 0x458u;
    {
        const bool branch_taken_0x458 = (GPR_S32(ctx, 4) < 0);
        // 0x45c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x458) {
            ctx->pc = 0x530u;
            goto label_530;
        }
    }
    ctx->pc = 0x460u;
    // 0x460: 0x3242007f  andi        $v0, $s2, 0x7F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)127);
    // 0x464: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x464u;
    {
        const bool branch_taken_0x464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x468: 0x2402821  addu        $a1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x464) {
            ctx->pc = 0x478u;
            goto label_478;
        }
    }
    ctx->pc = 0x46Cu;
    // 0x46c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x470: 0x8000123  j           func_00048C
    ctx->pc = 0x470u;
    // 0x474: 0x248423c4  addiu       $a0, $a0, 0x23C4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9156));
    ctx->pc = 0x48Cu;
    goto label_48c;
    ctx->pc = 0x478u;
label_478:
    // 0x478: 0x3222003f  andi        $v0, $s1, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
    // 0x47c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x47Cu;
    {
        const bool branch_taken_0x47c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x480: 0x2202821  addu        $a1, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x47c) {
            ctx->pc = 0x49Cu;
            goto label_49c;
        }
    }
    ctx->pc = 0x484u;
    // 0x484: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x488: 0x24842400  addiu       $a0, $a0, 0x2400
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9216));
label_48c:
    // 0x48c: 0xc000849  jal         func_002124
    ctx->pc = 0x48Cu;
    SET_GPR_U32(ctx, 31, 0x494u);
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x48Cu, 0x494u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x494u;
label_494:
    // 0x494: 0x800014c  j           func_000530
    ctx->pc = 0x494u;
    // 0x498: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x530u;
    goto label_530;
    ctx->pc = 0x49Cu;
label_49c:
    // 0x49c: 0xc000420  jal         func_001080
    ctx->pc = 0x49Cu;
    SET_GPR_U32(ctx, 31, 0x4A4u);
    // 0x4a0: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1080u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1080u, 0x49Cu, 0x4A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4A4u;
label_4a4:
    // 0x4a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4a8: 0x8c842770  lw          $a0, 0x2770($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10096)));
    // 0x4ac: 0xc0008a4  jal         func_002290
    ctx->pc = 0x4ACu;
    SET_GPR_U32(ctx, 31, 0x4B4u);
    // 0x4b0: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2290u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2290u, 0x4ACu, 0x4B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4B4u;
label_4b4:
    // 0x4b4: 0x2118021  addu        $s0, $s0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x4b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4bc: 0xac302754  sw          $s0, 0x2754($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10068), GPR_U32(ctx, 16));
    // 0x4c0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4c4: 0xac332750  sw          $s3, 0x2750($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10064), GPR_U32(ctx, 19));
    // 0x4c8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4cc: 0xac322758  sw          $s2, 0x2758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10072), GPR_U32(ctx, 18));
    // 0x4d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x4d4: 0xac20275c  sw          $zero, 0x275C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10076), GPR_U32(ctx, 0));
    // 0x4d8: 0xc000852  jal         func_002148
    ctx->pc = 0x4D8u;
    SET_GPR_U32(ctx, 31, 0x4E0u);
    // 0x4dc: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x2148u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2148u, 0x4D8u, 0x4E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4E0u;
label_4e0:
    // 0x4e0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4e4: 0x24842750  addiu       $a0, $a0, 0x2750
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10064));
    // 0x4e8: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x4ec: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x4f0: 0x24c602f4  addiu       $a2, $a2, 0x2F4
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 756));
    // 0x4f4: 0xc00087d  jal         func_0021F4
    ctx->pc = 0x4F4u;
    SET_GPR_U32(ctx, 31, 0x4FCu);
    // 0x4f8: 0x3821  addu        $a3, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x21F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21F4u, 0x4F4u, 0x4FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4FCu;
label_4fc:
    // 0x4fc: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x500: 0xc000854  jal         func_002150
    ctx->pc = 0x500u;
    SET_GPR_U32(ctx, 31, 0x508u);
    // 0x504: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2150u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2150u, 0x500u, 0x508u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x508u;
label_508:
    // 0x508: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x508u;
    {
        const bool branch_taken_0x508 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x50c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x508) {
            ctx->pc = 0x530u;
            goto label_530;
        }
    }
    ctx->pc = 0x510u;
    // 0x510: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x514: 0xc000849  jal         func_002124
    ctx->pc = 0x514u;
    SET_GPR_U32(ctx, 31, 0x51Cu);
    // 0x518: 0x248423a8  addiu       $a0, $a0, 0x23A8 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9128));
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x514u, 0x51Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x51Cu;
label_51c:
    // 0x51c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x520: 0x8c842770  lw          $a0, 0x2770($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10096)));
    // 0x524: 0xc0008a0  jal         func_002280
    ctx->pc = 0x524u;
    SET_GPR_U32(ctx, 31, 0x52Cu);
    ctx->pc = 0x2280u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2280u, 0x524u, 0x52Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x52Cu;
label_52c:
    // 0x52c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_530:
    // 0x530: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x534: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x538: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x53c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x540: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x544: 0x3e00008  jr          $ra
    ctx->pc = 0x544u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x548: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x544u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x54Cu;
}


// Function: dbcman_0000054c
// Address: 0x54c - 0x5a4
void dbcman_0000054c_0x54c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_0000054c_0x54c");
#endif

    switch (ctx->pc) {
        case 0x55cu: goto label_55c;
        case 0x570u: goto label_570;
        case 0x590u: goto label_590;
        default: break;
    }

    ctx->pc = 0x54cu;

    // 0x54c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x550: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x554: 0xc0003d2  jal         func_000F48
    ctx->pc = 0x554u;
    SET_GPR_U32(ctx, 31, 0x55Cu);
    // 0x558: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0xF48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF48u, 0x554u, 0x55Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x55Cu;
label_55c:
    // 0x55c: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x560: 0x600000c  bltz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x560u;
    {
        const bool branch_taken_0x560 = (GPR_S32(ctx, 16) < 0);
        // 0x564: 0x2402ffeb  addiu       $v0, $zero, -0x15 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967275));
        if (branch_taken_0x560) {
            ctx->pc = 0x594u;
            goto label_594;
        }
    }
    ctx->pc = 0x568u;
    // 0x568: 0xc0005a6  jal         func_001698
    ctx->pc = 0x568u;
    SET_GPR_U32(ctx, 31, 0x570u);
    // 0x56c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x568u, 0x570u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x570u;
label_570:
    // 0x570: 0x4400007  bltz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x570u;
    {
        const bool branch_taken_0x570 = (GPR_S32(ctx, 2) < 0);
        // 0x574: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x570) {
            ctx->pc = 0x590u;
            goto label_590;
        }
    }
    ctx->pc = 0x578u;
    // 0x578: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x57c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x580: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x584: 0xac222778  sw          $v0, 0x2778($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10104), GPR_U32(ctx, 2));
    // 0x588: 0xc000029  jal         func_0000A4
    ctx->pc = 0x588u;
    SET_GPR_U32(ctx, 31, 0x590u);
    ctx->pc = 0xA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA4u, 0x588u, 0x590u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x590u;
label_590:
    // 0x590: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_594:
    // 0x594: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x598: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x59c: 0x3e00008  jr          $ra
    ctx->pc = 0x59Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x5a0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x59Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x5A4u;
}


// Function: dbcman_000005a4
// Address: 0x5a4 - 0x5f4
void dbcman_000005a4_0x5a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000005a4_0x5a4");
#endif

    switch (ctx->pc) {
        case 0x5b8u: goto label_5b8;
        case 0x5d8u: goto label_5d8;
        default: break;
    }

    ctx->pc = 0x5a4u;

    // 0x5a4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x5a8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x5ac: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x5b0: 0xc000438  jal         func_0010E0
    ctx->pc = 0x5B0u;
    SET_GPR_U32(ctx, 31, 0x5B8u);
    // 0x5b4: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x10E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10E0u, 0x5B0u, 0x5B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5B8u;
label_5b8:
    // 0x5b8: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x5bc: 0x14430008  bne         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x5BCu;
    {
        const bool branch_taken_0x5bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x5c0: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x5bc) {
            ctx->pc = 0x5E0u;
            goto label_5e0;
        }
    }
    ctx->pc = 0x5C4u;
    // 0x5c4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5c8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x5cc: 0xac202778  sw          $zero, 0x2778($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10104), GPR_U32(ctx, 0));
    // 0x5d0: 0xc000029  jal         func_0000A4
    ctx->pc = 0x5D0u;
    SET_GPR_U32(ctx, 31, 0x5D8u);
    ctx->pc = 0xA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA4u, 0x5D0u, 0x5D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5D8u;
label_5d8:
    // 0x5d8: 0x8000179  j           func_0005E4
    ctx->pc = 0x5D8u;
    // 0x5dc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x5E4u;
    goto label_5e4;
    ctx->pc = 0x5E0u;
label_5e0:
    // 0x5e0: 0x2402ffea  addiu       $v0, $zero, -0x16
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
label_5e4:
    // 0x5e4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x5e8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x5ec: 0x3e00008  jr          $ra
    ctx->pc = 0x5ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x5f0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x5ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x5F4u;
}


// Function: dbcman_000005f4
// Address: 0x5f4 - 0x624
void dbcman_000005f4_0x5f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000005f4_0x5f4");
#endif

    switch (ctx->pc) {
        case 0x604u: goto label_604;
        default: break;
    }

    ctx->pc = 0x5f4u;

    // 0x5f4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x5f8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x5fc: 0xc0005a6  jal         func_001698
    ctx->pc = 0x5FCu;
    SET_GPR_U32(ctx, 31, 0x604u);
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x5FCu, 0x604u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x604u;
label_604:
    // 0x604: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x608: 0x4600002  bltz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x608u;
    {
        const bool branch_taken_0x608 = (GPR_S32(ctx, 3) < 0);
        // 0x60c: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        if (branch_taken_0x608) {
            ctx->pc = 0x614u;
            goto label_614;
        }
    }
    ctx->pc = 0x610u;
    // 0x610: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_614:
    // 0x614: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x618: 0x0  nop
    // NOP
    // 0x61c: 0x3e00008  jr          $ra
    ctx->pc = 0x61Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x620: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x61Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x624u;
}


// Function: dbcman_00000624
// Address: 0x624 - 0x670
void dbcman_00000624_0x624(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000624_0x624");
#endif

    switch (ctx->pc) {
        case 0x638u: goto label_638;
        case 0x648u: goto label_648;
        default: break;
    }

    ctx->pc = 0x624u;

    // 0x624: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x628: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x62c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x630: 0xc000349  jal         func_000D24
    ctx->pc = 0x630u;
    SET_GPR_U32(ctx, 31, 0x638u);
    // 0x634: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    ctx->pc = 0xD24u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xD24u, 0x630u, 0x638u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x638u;
label_638:
    // 0x638: 0x4400008  bltz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x638u;
    {
        const bool branch_taken_0x638 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x638) {
            ctx->pc = 0x65Cu;
            goto label_65c;
        }
    }
    ctx->pc = 0x640u;
    // 0x640: 0xc0005b8  jal         func_0016E0
    ctx->pc = 0x640u;
    SET_GPR_U32(ctx, 31, 0x648u);
    // 0x644: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x16E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x16E0u, 0x640u, 0x648u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x648u;
label_648:
    // 0x648: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x64c: 0x4600004  bltz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x64Cu;
    {
        const bool branch_taken_0x64c = (GPR_S32(ctx, 3) < 0);
        // 0x650: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        if (branch_taken_0x64c) {
            ctx->pc = 0x660u;
            goto label_660;
        }
    }
    ctx->pc = 0x654u;
    // 0x654: 0x8000198  j           func_000660
    ctx->pc = 0x654u;
    // 0x658: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0x65Cu;
label_65c:
    // 0x65c: 0x2402fff4  addiu       $v0, $zero, -0xC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
label_660:
    // 0x660: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x664: 0x0  nop
    // NOP
    // 0x668: 0x3e00008  jr          $ra
    ctx->pc = 0x668u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x66c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x668u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x670u;
}


// Function: dbcman_00000670
// Address: 0x670 - 0x6c4
void dbcman_00000670_0x670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000670_0x670");
#endif

    switch (ctx->pc) {
        case 0x684u: goto label_684;
        case 0x698u: goto label_698;
        case 0x6a8u: goto label_6a8;
        default: break;
    }

    ctx->pc = 0x670u;

    // 0x670: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x674: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x678: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x67c: 0xc0004bd  jal         func_0012F4
    ctx->pc = 0x67Cu;
    SET_GPR_U32(ctx, 31, 0x684u);
    // 0x680: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x12F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12F4u, 0x67Cu, 0x684u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x684u;
label_684:
    // 0x684: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x688: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x688u;
    {
        const bool branch_taken_0x688 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x68c: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        if (branch_taken_0x688) {
            ctx->pc = 0x6B4u;
            goto label_6b4;
        }
    }
    ctx->pc = 0x690u;
    // 0x690: 0xc0005a6  jal         func_001698
    ctx->pc = 0x690u;
    SET_GPR_U32(ctx, 31, 0x698u);
    // 0x694: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x690u, 0x698u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x698u;
    {
        const bool branch_taken_0x698 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x698) {
            ctx->pc = 0x6B0u;
            goto label_6b0;
        }
    }
    ctx->pc = 0x6A0u;
    // 0x6a0: 0xc0005cc  jal         func_001730
    ctx->pc = 0x6A0u;
    SET_GPR_U32(ctx, 31, 0x6A8u);
    // 0x6a4: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1730u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1730u, 0x6A0u, 0x6A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6A8u;
label_6a8:
    // 0x6a8: 0x80001ad  j           func_0006B4
    ctx->pc = 0x6A8u;
    // 0x6ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x6B4u;
    goto label_6b4;
    ctx->pc = 0x6B0u;
label_6b0:
    // 0x6b0: 0x2402ffe9  addiu       $v0, $zero, -0x17
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
label_6b4:
    // 0x6b4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x6b8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x6bc: 0x3e00008  jr          $ra
    ctx->pc = 0x6BCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6c0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x6BCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6C4u;
}


// Function: dbcman_000006c4
// Address: 0x6c4 - 0x718
void dbcman_000006c4_0x6c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000006c4_0x6c4");
#endif

    switch (ctx->pc) {
        case 0x6d8u: goto label_6d8;
        case 0x6ecu: goto label_6ec;
        case 0x6fcu: goto label_6fc;
        default: break;
    }

    ctx->pc = 0x6c4u;

    // 0x6c4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x6c8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x6cc: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x6d0: 0xc0004bd  jal         func_0012F4
    ctx->pc = 0x6D0u;
    SET_GPR_U32(ctx, 31, 0x6D8u);
    // 0x6d4: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x12F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12F4u, 0x6D0u, 0x6D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6D8u;
label_6d8:
    // 0x6d8: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6dc: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x6DCu;
    {
        const bool branch_taken_0x6dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x6e0: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        if (branch_taken_0x6dc) {
            ctx->pc = 0x708u;
            goto label_708;
        }
    }
    ctx->pc = 0x6E4u;
    // 0x6e4: 0xc0005a6  jal         func_001698
    ctx->pc = 0x6E4u;
    SET_GPR_U32(ctx, 31, 0x6ECu);
    // 0x6e8: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x6E4u, 0x6ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6ECu;
label_6ec:
    // 0x6ec: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x6ECu;
    {
        const bool branch_taken_0x6ec = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x6ec) {
            ctx->pc = 0x704u;
            goto label_704;
        }
    }
    ctx->pc = 0x6F4u;
    // 0x6f4: 0xc0005da  jal         func_001768
    ctx->pc = 0x6F4u;
    SET_GPR_U32(ctx, 31, 0x6FCu);
    // 0x6f8: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1768u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1768u, 0x6F4u, 0x6FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6FCu;
label_6fc:
    // 0x6fc: 0x80001c2  j           func_000708
    ctx->pc = 0x6FCu;
    // 0x700: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x708u;
    goto label_708;
    ctx->pc = 0x704u;
label_704:
    // 0x704: 0x2402ffe9  addiu       $v0, $zero, -0x17
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
label_708:
    // 0x708: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x70c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x710: 0x3e00008  jr          $ra
    ctx->pc = 0x710u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x714: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x710u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x718u;
}


// Function: dbcman_00000718
// Address: 0x718 - 0x740
void dbcman_00000718_0x718(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000718_0x718");
#endif

    switch (ctx->pc) {
        case 0x730u: goto label_730;
        default: break;
    }

    ctx->pc = 0x718u;

    // 0x718: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x71c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x720: 0x24842438  addiu       $a0, $a0, 0x2438
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9272));
    // 0x724: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x728: 0xc000886  jal         func_002218
    ctx->pc = 0x728u;
    SET_GPR_U32(ctx, 31, 0x730u);
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x728u, 0x730u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x730u;
label_730:
    // 0x730: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x734: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x738: 0x3e00008  jr          $ra
    ctx->pc = 0x738u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x73c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x738u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x740u;
}


// Function: dbcman_00000740
// Address: 0x740 - 0x7d0
void dbcman_00000740_0x740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000740_0x740");
#endif

    switch (ctx->pc) {
        case 0x76cu: goto label_76c;
        case 0x780u: goto label_780;
        case 0x7a8u: goto label_7a8;
        default: break;
    }

    ctx->pc = 0x740u;

    // 0x740: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x744: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x748: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x74c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x750: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x754: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x758: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x75c: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x760: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x764: 0xc0004bd  jal         func_0012F4
    ctx->pc = 0x764u;
    SET_GPR_U32(ctx, 31, 0x76Cu);
    // 0x768: 0xe09821  addu        $s3, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x12F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12F4u, 0x764u, 0x76Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x76Cu;
label_76c:
    // 0x76c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x770: 0x14430010  bne         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x770u;
    {
        const bool branch_taken_0x770 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x774: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        if (branch_taken_0x770) {
            ctx->pc = 0x7B4u;
            goto label_7b4;
        }
    }
    ctx->pc = 0x778u;
    // 0x778: 0xc0005a6  jal         func_001698
    ctx->pc = 0x778u;
    SET_GPR_U32(ctx, 31, 0x780u);
    // 0x77c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x778u, 0x780u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x780u;
label_780:
    // 0x780: 0x440000b  bltz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x780u;
    {
        const bool branch_taken_0x780 = (GPR_S32(ctx, 2) < 0);
        // 0x784: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x780) {
            ctx->pc = 0x7B0u;
            goto label_7b0;
        }
    }
    ctx->pc = 0x788u;
    // 0x788: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x78c: 0x8fa20040  lw          $v0, 0x40($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x790: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x794: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x798: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x79c: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x7a0: 0xc000612  jal         func_001848
    ctx->pc = 0x7A0u;
    SET_GPR_U32(ctx, 31, 0x7A8u);
    // 0x7a4: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x1848u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1848u, 0x7A0u, 0x7A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7A8u;
label_7a8:
    // 0x7a8: 0x80001ed  j           func_0007B4
    ctx->pc = 0x7A8u;
    ctx->pc = 0x7B4u;
    goto label_7b4;
    ctx->pc = 0x7B0u;
label_7b0:
    // 0x7b0: 0x2402ffe9  addiu       $v0, $zero, -0x17
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
label_7b4:
    // 0x7b4: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x7b8: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x7bc: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x7c0: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x7c4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x7c8: 0x3e00008  jr          $ra
    ctx->pc = 0x7C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x7cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x7D0u;
}


// Function: dbcman_000007d0
// Address: 0x7d0 - 0x850
void dbcman_000007d0_0x7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000007d0_0x7d0");
#endif

    switch (ctx->pc) {
        case 0x7fcu: goto label_7fc;
        case 0x810u: goto label_810;
        case 0x828u: goto label_828;
        default: break;
    }

    ctx->pc = 0x7d0u;

    // 0x7d0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x7d4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x7d8: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x7dc: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x7e0: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x7e4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x7e8: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x7ec: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x7f0: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x7f4: 0xc0004bd  jal         func_0012F4
    ctx->pc = 0x7F4u;
    SET_GPR_U32(ctx, 31, 0x7FCu);
    // 0x7f8: 0xe09821  addu        $s3, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x12F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12F4u, 0x7F4u, 0x7FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7FCu;
label_7fc:
    // 0x7fc: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x800: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x800u;
    {
        const bool branch_taken_0x800 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x804: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        if (branch_taken_0x800) {
            ctx->pc = 0x834u;
            goto label_834;
        }
    }
    ctx->pc = 0x808u;
    // 0x808: 0xc0005a6  jal         func_001698
    ctx->pc = 0x808u;
    SET_GPR_U32(ctx, 31, 0x810u);
    // 0x80c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x808u, 0x810u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x810u;
label_810:
    // 0x810: 0x4400007  bltz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x810u;
    {
        const bool branch_taken_0x810 = (GPR_S32(ctx, 2) < 0);
        // 0x814: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x810) {
            ctx->pc = 0x830u;
            goto label_830;
        }
    }
    ctx->pc = 0x818u;
    // 0x818: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x81c: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x820: 0xc000633  jal         func_0018CC
    ctx->pc = 0x820u;
    SET_GPR_U32(ctx, 31, 0x828u);
    // 0x824: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x18CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x18CCu, 0x820u, 0x828u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x828u;
label_828:
    // 0x828: 0x800020d  j           func_000834
    ctx->pc = 0x828u;
    ctx->pc = 0x834u;
    goto label_834;
    ctx->pc = 0x830u;
label_830:
    // 0x830: 0x2402ffe9  addiu       $v0, $zero, -0x17
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
label_834:
    // 0x834: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x838: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x83c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x840: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x844: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x848: 0x3e00008  jr          $ra
    ctx->pc = 0x848u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x84c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x848u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x850u;
}


// Function: dbcman_00000850
// Address: 0x850 - 0x8d0
void dbcman_00000850_0x850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000850_0x850");
#endif

    switch (ctx->pc) {
        case 0x87cu: goto label_87c;
        case 0x890u: goto label_890;
        case 0x8a8u: goto label_8a8;
        default: break;
    }

    ctx->pc = 0x850u;

    // 0x850: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x854: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x858: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x85c: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x860: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x864: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x868: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x86c: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0x870: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x874: 0xc0004bd  jal         func_0012F4
    ctx->pc = 0x874u;
    SET_GPR_U32(ctx, 31, 0x87Cu);
    // 0x878: 0xe09821  addu        $s3, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x12F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12F4u, 0x874u, 0x87Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x87Cu;
label_87c:
    // 0x87c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x880: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x880u;
    {
        const bool branch_taken_0x880 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x884: 0x2402ffea  addiu       $v0, $zero, -0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967274));
        if (branch_taken_0x880) {
            ctx->pc = 0x8B4u;
            goto label_8b4;
        }
    }
    ctx->pc = 0x888u;
    // 0x888: 0xc0005a6  jal         func_001698
    ctx->pc = 0x888u;
    SET_GPR_U32(ctx, 31, 0x890u);
    // 0x88c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1698u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1698u, 0x888u, 0x890u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x890u;
label_890:
    // 0x890: 0x4400007  bltz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x890u;
    {
        const bool branch_taken_0x890 = (GPR_S32(ctx, 2) < 0);
        // 0x894: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x890) {
            ctx->pc = 0x8B0u;
            goto label_8b0;
        }
    }
    ctx->pc = 0x898u;
    // 0x898: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0x89c: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x8a0: 0xc0005f6  jal         func_0017D8
    ctx->pc = 0x8A0u;
    SET_GPR_U32(ctx, 31, 0x8A8u);
    // 0x8a4: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x17D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x17D8u, 0x8A0u, 0x8A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8A8u;
label_8a8:
    // 0x8a8: 0x800022d  j           func_0008B4
    ctx->pc = 0x8A8u;
    ctx->pc = 0x8B4u;
    goto label_8b4;
    ctx->pc = 0x8B0u;
label_8b0:
    // 0x8b0: 0x2402ffe9  addiu       $v0, $zero, -0x17
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967273));
label_8b4:
    // 0x8b4: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x8b8: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x8bc: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x8c0: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x8c4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x8c8: 0x3e00008  jr          $ra
    ctx->pc = 0x8C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8cc: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8D0u;
}


// Function: dbcman_000008d0
// Address: 0x8d0 - 0x8f8
void dbcman_000008d0_0x8d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000008d0_0x8d0");
#endif

    switch (ctx->pc) {
        case 0x8e8u: goto label_8e8;
        default: break;
    }

    ctx->pc = 0x8d0u;

    // 0x8d0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x8d4: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x8d8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x8dc: 0xac242774  sw          $a0, 0x2774($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10100), GPR_U32(ctx, 4));
    // 0x8e0: 0xc000029  jal         func_0000A4
    ctx->pc = 0x8E0u;
    SET_GPR_U32(ctx, 31, 0x8E8u);
    ctx->pc = 0xA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xA4u, 0x8E0u, 0x8E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8E8u;
label_8e8:
    // 0x8e8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x8ec: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x8f0: 0x3e00008  jr          $ra
    ctx->pc = 0x8F0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8f4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8F0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8F8u;
}


// Function: dbcman_000008f8
// Address: 0x8f8 - 0x930
void dbcman_000008f8_0x8f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000008f8_0x8f8");
#endif

    switch (ctx->pc) {
        case 0x91cu: goto label_91c;
        default: break;
    }

    ctx->pc = 0x8f8u;

    // 0x8f8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x8fc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x900: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x904: 0x26102714  addiu       $s0, $s0, 0x2714
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 10004));
    // 0x908: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x90c: 0x96050000  lhu         $a1, 0x0($s0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x910: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x914: 0xc00024c  jal         func_000930
    ctx->pc = 0x914u;
    SET_GPR_U32(ctx, 31, 0x91Cu);
    // 0x918: 0x24842464  addiu       $a0, $a0, 0x2464 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9316));
    ctx->pc = 0x930u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x930u, 0x914u, 0x91Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x91Cu;
label_91c:
    // 0x91c: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x920: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x924: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x928: 0x3e00008  jr          $ra
    ctx->pc = 0x928u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x92c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x928u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x930u;
}


// Function: dbcman_00000930
// Address: 0x930 - 0x950
void dbcman_00000930_0x930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000930_0x930");
#endif

    ctx->pc = 0x930u;

    // 0x930: 0xafa40000  sw          $a0, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x934: 0xafa50004  sw          $a1, 0x4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x938: 0xafa60008  sw          $a2, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x93c: 0x3e00008  jr          $ra
    ctx->pc = 0x93Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x940: 0xafa7000c  sw          $a3, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 7));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x93Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x944u;
    // 0x944: 0x0  nop
    // NOP
    // 0x948: 0x0  nop
    // NOP
    // 0x94c: 0x0  nop
    // NOP
}


// Function: dbcman_00000950
// Address: 0x950 - 0x978
void dbcman_00000950_0x950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000950_0x950");
#endif

    switch (ctx->pc) {
        case 0x958u: goto label_958;
        default: break;
    }

    ctx->pc = 0x950u;

    // 0x950: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x954: 0x24020258  addiu       $v0, $zero, 0x258
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 600));
label_958:
    // 0x958: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x95c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x960: 0xac2027c0  sw          $zero, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 0));
    // 0x964: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x968: 0x461fffb  bgez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x968u;
    {
        const bool branch_taken_0x968 = (GPR_S32(ctx, 3) >= 0);
        // 0x96c: 0x2442ffd8  addiu       $v0, $v0, -0x28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967256));
        if (branch_taken_0x968) {
            ctx->pc = 0x958u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_958;
        }
    }
    ctx->pc = 0x970u;
    // 0x970: 0x3e00008  jr          $ra
    ctx->pc = 0x970u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
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


// Function: dbcman_00000978
// Address: 0x978 - 0xa1c
void dbcman_00000978_0x978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000978_0x978");
#endif

    switch (ctx->pc) {
        case 0x990u: goto label_990;
        default: break;
    }

    ctx->pc = 0x978u;

    // 0x978: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x97c: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x980: 0x2407ffff  addiu       $a3, $zero, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x984: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x988: 0x246327c0  addiu       $v1, $v1, 0x27C0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 10176));
    // 0x98c: 0xc02821  addu        $a1, $a2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_990:
    // 0x990: 0x8c620000  lw          $v0, 0x0($v1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x994: 0x0  nop
    // NOP
    // 0x998: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x998u;
    {
        const bool branch_taken_0x998 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x998) {
            ctx->pc = 0xA00u;
            goto label_a00;
        }
    }
    ctx->pc = 0x9A0u;
    // 0x9a0: 0xac680000  sw          $t0, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 8));
    // 0x9a4: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x9a8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9ac: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x9b0: 0xac2227c4  sw          $v0, 0x27C4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10180), GPR_U32(ctx, 2));
    // 0x9b4: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x9b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9bc: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x9c0: 0xac2227c8  sw          $v0, 0x27C8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10184), GPR_U32(ctx, 2));
    // 0x9c4: 0x8c830008  lw          $v1, 0x8($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x9c8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9cc: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x9d0: 0xac2727d0  sw          $a3, 0x27D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10192), GPR_U32(ctx, 7));
    // 0x9d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9d8: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x9dc: 0xac2727d4  sw          $a3, 0x27D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10196), GPR_U32(ctx, 7));
    // 0x9e0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9e4: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x9e8: 0xa02027d8  sb          $zero, 0x27D8($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 10200), (uint8_t)GPR_U32(ctx, 0));
    // 0x9ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9f0: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
    // 0x9f4: 0xac2327cc  sw          $v1, 0x27CC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10188), GPR_U32(ctx, 3));
    // 0x9f8: 0x3e00008  jr          $ra
    ctx->pc = 0x9F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9fc: 0xc01021  addu        $v0, $a2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA00u;
label_a00:
    // 0xa00: 0x24630028  addiu       $v1, $v1, 0x28
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 40));
    // 0xa04: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0xa08: 0x28c20010  slti        $v0, $a2, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xa0c: 0x1440ffe0  bnez        $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0xA0Cu;
    {
        const bool branch_taken_0xa0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xa10: 0x24a50028  addiu       $a1, $a1, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 40));
        if (branch_taken_0xa0c) {
            ctx->pc = 0x990u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_990;
        }
    }
    ctx->pc = 0xA14u;
    // 0xa14: 0x3e00008  jr          $ra
    ctx->pc = 0xA14u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa18: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
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


// Function: dbcman_00000a1c
// Address: 0xa1c - 0xa84
void dbcman_00000a1c_0xa1c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000a1c_0xa1c");
#endif

    switch (ctx->pc) {
        case 0xa64u: goto label_a64;
        default: break;
    }

    ctx->pc = 0xa1cu;

    // 0xa1c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xa20: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xa24: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xa28: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0xa2c: 0x280c0  sll         $s0, $v0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xa30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa34: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0xa38: 0x8c4227c0  lw          $v0, 0x27C0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10176)));
    // 0xa3c: 0x0  nop
    // NOP
    // 0xa40: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA40u;
    {
        const bool branch_taken_0xa40 = (GPR_S32(ctx, 2) > 0);
        // 0xa44: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0xa40) {
            ctx->pc = 0xA50u;
            goto label_a50;
        }
    }
    ctx->pc = 0xA48u;
    // 0xa48: 0x800029d  j           func_000A74
    ctx->pc = 0xA48u;
    // 0xa4c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xA74u;
    goto label_a74;
    ctx->pc = 0xA50u;
label_a50:
    // 0xa50: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0xa54: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xA54u;
    {
        const bool branch_taken_0xa54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xa54) {
            ctx->pc = 0xA64u;
            goto label_a64;
        }
    }
    ctx->pc = 0xA5Cu;
    // 0xa5c: 0xc000533  jal         func_0014CC
    ctx->pc = 0xA5Cu;
    SET_GPR_U32(ctx, 31, 0xA64u);
    ctx->pc = 0x14CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x14CCu, 0xA5Cu, 0xA64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA64u;
label_a64:
    // 0xa64: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa68: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xa6c: 0xac2027c0  sw          $zero, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 0));
    // 0xa70: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_a74:
    // 0xa74: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xa78: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xa7c: 0x3e00008  jr          $ra
    ctx->pc = 0xA7Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa80: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA7Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA84u;
}


// Function: dbcman_00000a84
// Address: 0xa84 - 0xb68
void dbcman_00000a84_0xa84(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000a84_0xa84");
#endif

    switch (ctx->pc) {
        case 0xad0u: goto label_ad0;
        case 0xb38u: goto label_b38;
        default: break;
    }

    ctx->pc = 0xa84u;

    // 0xa84: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xa88: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xa8c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xa90: 0x238c0  sll         $a3, $v0, 3
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xa94: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xa98: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xa9c: 0x8c6327c0  lw          $v1, 0x27C0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10176)));
    // 0xaa0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xaa4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xaa8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xAA8u;
    {
        const bool branch_taken_0xaa8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xaac: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0xaa8) {
            ctx->pc = 0xAB8u;
            goto label_ab8;
        }
    }
    ctx->pc = 0xAB0u;
    // 0xab0: 0x80002d6  j           func_000B58
    ctx->pc = 0xAB0u;
    // 0xab4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xB58u;
    goto label_b58;
    ctx->pc = 0xAB8u;
label_ab8:
    // 0xab8: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xabc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xac0: 0x270821  addu        $at, $at, $a3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 7)));
    // 0xac4: 0xac2227c0  sw          $v0, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 2));
    // 0xac8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xacc: 0xc71821  addu        $v1, $a2, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
label_ad0:
    // 0xad0: 0xa61021  addu        $v0, $a1, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0xad4: 0x90420008  lbu         $v0, 0x8($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0xad8: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0xadc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xae0: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xae4: 0xa02227d8  sb          $v0, 0x27D8($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 10200), (uint8_t)GPR_U32(ctx, 2));
    // 0xae8: 0x28c20010  slti        $v0, $a2, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xaec: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0xAECu;
    {
        const bool branch_taken_0xaec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xaf0: 0xc71821  addu        $v1, $a2, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
        if (branch_taken_0xaec) {
            ctx->pc = 0xAD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_ad0;
        }
    }
    ctx->pc = 0xAF4u;
    // 0xaf4: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xaf8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xafc: 0x8ca30000  lw          $v1, 0x0($a1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0xb00: 0x280c0  sll         $s0, $v0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xb04: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb08: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xb0c: 0xac2327d0  sw          $v1, 0x27D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10192), GPR_U32(ctx, 3));
    // 0xb10: 0x8ca20004  lw          $v0, 0x4($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0xb14: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xb18: 0x24a527c4  addiu       $a1, $a1, 0x27C4
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10180));
    // 0xb1c: 0x24a6000c  addiu       $a2, $a1, 0xC
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
    // 0xb20: 0x2052821  addu        $a1, $s0, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0xb24: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb28: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xb2c: 0xac2227d4  sw          $v0, 0x27D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10196), GPR_U32(ctx, 2));
    // 0xb30: 0xc0004ff  jal         func_0013FC
    ctx->pc = 0xB30u;
    SET_GPR_U32(ctx, 31, 0xB38u);
    // 0xb34: 0x2063021  addu        $a2, $s0, $a2 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    ctx->pc = 0x13FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x13FCu, 0xB30u, 0xB38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB38u;
label_b38:
    // 0xb38: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xb3c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0xB3Cu;
    {
        const bool branch_taken_0xb3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0xb40: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xb3c) {
            ctx->pc = 0xB58u;
            goto label_b58;
        }
    }
    ctx->pc = 0xB44u;
    // 0xb44: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0xb48: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb4c: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xb50: 0xac2227c0  sw          $v0, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 2));
    // 0xb54: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_b58:
    // 0xb58: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xb5c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xb60: 0x3e00008  jr          $ra
    ctx->pc = 0xB60u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xb64: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB60u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB68u;
}


// Function: dbcman_00000b68
// Address: 0xb68 - 0xc00
void dbcman_00000b68_0xb68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000b68_0xb68");
#endif

    switch (ctx->pc) {
        case 0xbb4u: goto label_bb4;
        default: break;
    }

    ctx->pc = 0xb68u;

    // 0xb68: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xb6c: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xb70: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xb74: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0xb78: 0x280c0  sll         $s0, $v0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xb7c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xb80: 0x701821  addu        $v1, $v1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0xb84: 0x8c6327c0  lw          $v1, 0x27C0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10176)));
    // 0xb88: 0x0  nop
    // NOP
    // 0xb8c: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0xb90: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0xB90u;
    {
        const bool branch_taken_0xb90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xb94: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0xb90) {
            ctx->pc = 0xBA0u;
            goto label_ba0;
        }
    }
    ctx->pc = 0xB98u;
    // 0xb98: 0x80002fc  j           func_000BF0
    ctx->pc = 0xB98u;
    // 0xb9c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xBF0u;
    goto label_bf0;
    ctx->pc = 0xBA0u;
label_ba0:
    // 0xba0: 0x28620003  slti        $v0, $v1, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0xba4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0xBA4u;
    {
        const bool branch_taken_0xba4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xba8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xba4) {
            ctx->pc = 0xBB8u;
            goto label_bb8;
        }
    }
    ctx->pc = 0xBACu;
    // 0xbac: 0xc000533  jal         func_0014CC
    ctx->pc = 0xBACu;
    SET_GPR_U32(ctx, 31, 0xBB4u);
    ctx->pc = 0x14CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x14CCu, 0xBACu, 0xBB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBB4u;
label_bb4:
    // 0xbb4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_bb8:
    // 0xbb8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xbbc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbc0: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xbc4: 0xac2327c0  sw          $v1, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 3));
    // 0xbc8: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xbcc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbd0: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xbd4: 0xac2327d0  sw          $v1, 0x27D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10192), GPR_U32(ctx, 3));
    // 0xbd8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbdc: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xbe0: 0xac2327d4  sw          $v1, 0x27D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10196), GPR_U32(ctx, 3));
    // 0xbe4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbe8: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0xbec: 0xa02027d8  sb          $zero, 0x27D8($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 10200), (uint8_t)GPR_U32(ctx, 0));
label_bf0:
    // 0xbf0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xbf4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xbf8: 0x3e00008  jr          $ra
    ctx->pc = 0xBF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xbfc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xBF8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC00u;
}


// Function: dbcman_00000c00
// Address: 0xc00 - 0xd24
void dbcman_00000c00_0xc00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000c00_0xc00");
#endif

    switch (ctx->pc) {
        case 0xc10u: goto label_c10;
        case 0xcccu: goto label_ccc;
        default: break;
    }

    ctx->pc = 0xc00u;

    // 0xc00: 0x5021  addu        $t2, $zero, $zero
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xc04: 0x240c0002  addiu       $t4, $zero, 0x2
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xc08: 0x240b0001  addiu       $t3, $zero, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xc0c: 0x1403821  addu        $a3, $t2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
label_c10:
    // 0xc10: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xc14: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0xc18: 0x8c4227c0  lw          $v0, 0x27C0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10176)));
    // 0xc1c: 0x0  nop
    // NOP
    // 0xc20: 0x144c003a  bne         $v0, $t4, . + 4 + (0x3A << 2)
    ctx->pc = 0xC20u;
    {
        const bool branch_taken_0xc20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 12));
        if (branch_taken_0xc20) {
            ctx->pc = 0xD0Cu;
            goto label_d0c;
        }
    }
    ctx->pc = 0xC28u;
    // 0xc28: 0x8c850000  lw          $a1, 0x0($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0xc2c: 0x0  nop
    // NOP
    // 0xc30: 0x30a20001  andi        $v0, $a1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
    // 0xc34: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xC34u;
    {
        const bool branch_taken_0xc34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc38: 0x30a20002  andi        $v0, $a1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
        if (branch_taken_0xc34) {
            ctx->pc = 0xC58u;
            goto label_c58;
        }
    }
    ctx->pc = 0xC3Cu;
    // 0xc3c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xc40: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xc44: 0x8c6327c4  lw          $v1, 0x27C4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10180)));
    // 0xc48: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0xc4c: 0x0  nop
    // NOP
    // 0xc50: 0x1462002e  bne         $v1, $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0xC50u;
    {
        const bool branch_taken_0xc50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xc54: 0x30a20002  andi        $v0, $a1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
        if (branch_taken_0xc50) {
            ctx->pc = 0xD0Cu;
            goto label_d0c;
        }
    }
    ctx->pc = 0xC58u;
label_c58:
    // 0xc58: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0xC58u;
    {
        const bool branch_taken_0xc58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc5c: 0x30a20004  andi        $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
        if (branch_taken_0xc58) {
            ctx->pc = 0xC98u;
            goto label_c98;
        }
    }
    ctx->pc = 0xC60u;
    // 0xc60: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xc64: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xc68: 0x8c6327d0  lw          $v1, 0x27D0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10192)));
    // 0xc6c: 0x8c820008  lw          $v0, 0x8($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0xc70: 0x0  nop
    // NOP
    // 0xc74: 0x14620025  bne         $v1, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0xC74u;
    {
        const bool branch_taken_0xc74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0xc74) {
            ctx->pc = 0xD0Cu;
            goto label_d0c;
        }
    }
    ctx->pc = 0xC7Cu;
    // 0xc7c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xc80: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xc84: 0x8c6327d4  lw          $v1, 0x27D4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10196)));
    // 0xc88: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0xc8c: 0x0  nop
    // NOP
    // 0xc90: 0x1462001e  bne         $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0xC90u;
    {
        const bool branch_taken_0xc90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xc94: 0x30a20004  andi        $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
        if (branch_taken_0xc90) {
            ctx->pc = 0xD0Cu;
            goto label_d0c;
        }
    }
    ctx->pc = 0xC98u;
label_c98:
    // 0xc98: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xC98u;
    {
        const bool branch_taken_0xc98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc9c: 0x30a20008  andi        $v0, $a1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)8);
        if (branch_taken_0xc98) {
            ctx->pc = 0xCBCu;
            goto label_cbc;
        }
    }
    ctx->pc = 0xCA0u;
    // 0xca0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xca4: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xca8: 0x8c6327c8  lw          $v1, 0x27C8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10184)));
    // 0xcac: 0x8c820010  lw          $v0, 0x10($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0xcb0: 0x0  nop
    // NOP
    // 0xcb4: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0xCB4u;
    {
        const bool branch_taken_0xcb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xcb8: 0x30a20008  andi        $v0, $a1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)8);
        if (branch_taken_0xcb4) {
            ctx->pc = 0xD0Cu;
            goto label_d0c;
        }
    }
    ctx->pc = 0xCBCu;
label_cbc:
    // 0xcbc: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0xCBCu;
    {
        const bool branch_taken_0xcbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xcc0: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xcbc) {
            ctx->pc = 0xD04u;
            goto label_d04;
        }
    }
    ctx->pc = 0xCC4u;
    // 0xcc4: 0xc04021  addu        $t0, $a2, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0xcc8: 0xe04821  addu        $t1, $a3, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_ccc:
    // 0xccc: 0xc91021  addu        $v0, $a2, $t1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0xcd0: 0x861821  addu        $v1, $a0, $a2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0xcd4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xcd8: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0xcdc: 0x90a527d8  lbu         $a1, 0x27D8($a1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10200)));
    // 0xce0: 0x90620014  lbu         $v0, 0x14($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 20)));
    // 0xce4: 0x0  nop
    // NOP
    // 0xce8: 0x10a20002  beq         $a1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xCE8u;
    {
        const bool branch_taken_0xce8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0xce8) {
            ctx->pc = 0xCF4u;
            goto label_cf4;
        }
    }
    ctx->pc = 0xCF0u;
    // 0xcf0: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_cf4:
    // 0xcf4: 0x14a0fff5  bnez        $a1, . + 4 + (-0xB << 2)
    ctx->pc = 0xCF4u;
    {
        const bool branch_taken_0xcf4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        // 0xcf8: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0xcf4) {
            ctx->pc = 0xCCCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_ccc;
        }
    }
    ctx->pc = 0xCFCu;
    // 0xcfc: 0x110b0003  beq         $t0, $t3, . + 4 + (0x3 << 2)
    ctx->pc = 0xCFCu;
    {
        const bool branch_taken_0xcfc = (GPR_U64(ctx, 8) == GPR_U64(ctx, 11));
        if (branch_taken_0xcfc) {
            ctx->pc = 0xD0Cu;
            goto label_d0c;
        }
    }
    ctx->pc = 0xD04u;
label_d04:
    // 0xd04: 0x3e00008  jr          $ra
    ctx->pc = 0xD04u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd08: 0x1401021  addu        $v0, $t2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD04u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD0Cu;
label_d0c:
    // 0xd0c: 0x254a0001  addiu       $t2, $t2, 0x1
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0xd10: 0x29420010  slti        $v0, $t2, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xd14: 0x1440ffbe  bnez        $v0, . + 4 + (-0x42 << 2)
    ctx->pc = 0xD14u;
    {
        const bool branch_taken_0xd14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xd18: 0x24e70028  addiu       $a3, $a3, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 40));
        if (branch_taken_0xd14) {
            ctx->pc = 0xC10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_c10;
        }
    }
    ctx->pc = 0xD1Cu;
    // 0xd1c: 0x3e00008  jr          $ra
    ctx->pc = 0xD1Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd20: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD1Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD24u;
}


// Function: dbcman_00000d24
// Address: 0xd24 - 0xe48
void dbcman_00000d24_0xd24(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000d24_0xd24");
#endif

    switch (ctx->pc) {
        case 0xd30u: goto label_d30;
        case 0xdf0u: goto label_df0;
        default: break;
    }

    ctx->pc = 0xd24u;

    // 0xd24: 0x5021  addu        $t2, $zero, $zero
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xd28: 0x240b0001  addiu       $t3, $zero, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xd2c: 0x1403821  addu        $a3, $t2, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
label_d30:
    // 0xd30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xd34: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0xd38: 0x8c4227c0  lw          $v0, 0x27C0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10176)));
    // 0xd3c: 0x0  nop
    // NOP
    // 0xd40: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0xd44: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0xD44u;
    {
        const bool branch_taken_0xd44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xd44) {
            ctx->pc = 0xE30u;
            goto label_e30;
        }
    }
    ctx->pc = 0xD4Cu;
    // 0xd4c: 0x8c850000  lw          $a1, 0x0($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0xd50: 0x0  nop
    // NOP
    // 0xd54: 0x30a20001  andi        $v0, $a1, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
    // 0xd58: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xD58u;
    {
        const bool branch_taken_0xd58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xd5c: 0x30a20002  andi        $v0, $a1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
        if (branch_taken_0xd58) {
            ctx->pc = 0xD7Cu;
            goto label_d7c;
        }
    }
    ctx->pc = 0xD60u;
    // 0xd60: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xd64: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xd68: 0x8c6327c4  lw          $v1, 0x27C4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10180)));
    // 0xd6c: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0xd70: 0x0  nop
    // NOP
    // 0xd74: 0x1462002e  bne         $v1, $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0xD74u;
    {
        const bool branch_taken_0xd74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xd78: 0x30a20002  andi        $v0, $a1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
        if (branch_taken_0xd74) {
            ctx->pc = 0xE30u;
            goto label_e30;
        }
    }
    ctx->pc = 0xD7Cu;
label_d7c:
    // 0xd7c: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0xD7Cu;
    {
        const bool branch_taken_0xd7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xd80: 0x30a20004  andi        $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
        if (branch_taken_0xd7c) {
            ctx->pc = 0xDBCu;
            goto label_dbc;
        }
    }
    ctx->pc = 0xD84u;
    // 0xd84: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xd88: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xd8c: 0x8c6327d0  lw          $v1, 0x27D0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10192)));
    // 0xd90: 0x8c820008  lw          $v0, 0x8($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0xd94: 0x0  nop
    // NOP
    // 0xd98: 0x14620025  bne         $v1, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0xD98u;
    {
        const bool branch_taken_0xd98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0xd98) {
            ctx->pc = 0xE30u;
            goto label_e30;
        }
    }
    ctx->pc = 0xDA0u;
    // 0xda0: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xda4: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xda8: 0x8c6327d4  lw          $v1, 0x27D4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10196)));
    // 0xdac: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0xdb0: 0x0  nop
    // NOP
    // 0xdb4: 0x1462001e  bne         $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0xDB4u;
    {
        const bool branch_taken_0xdb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xdb8: 0x30a20004  andi        $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
        if (branch_taken_0xdb4) {
            ctx->pc = 0xE30u;
            goto label_e30;
        }
    }
    ctx->pc = 0xDBCu;
label_dbc:
    // 0xdbc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0xDBCu;
    {
        const bool branch_taken_0xdbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xdc0: 0x30a20008  andi        $v0, $a1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)8);
        if (branch_taken_0xdbc) {
            ctx->pc = 0xDE0u;
            goto label_de0;
        }
    }
    ctx->pc = 0xDC4u;
    // 0xdc4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xdc8: 0x671821  addu        $v1, $v1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0xdcc: 0x8c6327c8  lw          $v1, 0x27C8($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10184)));
    // 0xdd0: 0x8c820010  lw          $v0, 0x10($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0xdd4: 0x0  nop
    // NOP
    // 0xdd8: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0xDD8u;
    {
        const bool branch_taken_0xdd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xddc: 0x30a20008  andi        $v0, $a1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)8);
        if (branch_taken_0xdd8) {
            ctx->pc = 0xE30u;
            goto label_e30;
        }
    }
    ctx->pc = 0xDE0u;
label_de0:
    // 0xde0: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0xDE0u;
    {
        const bool branch_taken_0xde0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xde4: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xde0) {
            ctx->pc = 0xE28u;
            goto label_e28;
        }
    }
    ctx->pc = 0xDE8u;
    // 0xde8: 0xc04021  addu        $t0, $a2, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0xdec: 0xe04821  addu        $t1, $a3, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_df0:
    // 0xdf0: 0xc91021  addu        $v0, $a2, $t1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0xdf4: 0x861821  addu        $v1, $a0, $a2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0xdf8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
    // 0xdfc: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0xe00: 0x90a527d8  lbu         $a1, 0x27D8($a1)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10200)));
    // 0xe04: 0x90620014  lbu         $v0, 0x14($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 20)));
    // 0xe08: 0x0  nop
    // NOP
    // 0xe0c: 0x10a20002  beq         $a1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xE0Cu;
    {
        const bool branch_taken_0xe0c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0xe0c) {
            ctx->pc = 0xE18u;
            goto label_e18;
        }
    }
    ctx->pc = 0xE14u;
    // 0xe14: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_e18:
    // 0xe18: 0x14a0fff5  bnez        $a1, . + 4 + (-0xB << 2)
    ctx->pc = 0xE18u;
    {
        const bool branch_taken_0xe18 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        // 0xe1c: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0xe18) {
            ctx->pc = 0xDF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_df0;
        }
    }
    ctx->pc = 0xE20u;
    // 0xe20: 0x110b0003  beq         $t0, $t3, . + 4 + (0x3 << 2)
    ctx->pc = 0xE20u;
    {
        const bool branch_taken_0xe20 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 11));
        if (branch_taken_0xe20) {
            ctx->pc = 0xE30u;
            goto label_e30;
        }
    }
    ctx->pc = 0xE28u;
label_e28:
    // 0xe28: 0x3e00008  jr          $ra
    ctx->pc = 0xE28u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe2c: 0x1401021  addu        $v0, $t2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE28u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE30u;
label_e30:
    // 0xe30: 0x254a0001  addiu       $t2, $t2, 0x1
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0xe34: 0x29420010  slti        $v0, $t2, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0xe38: 0x1440ffbd  bnez        $v0, . + 4 + (-0x43 << 2)
    ctx->pc = 0xE38u;
    {
        const bool branch_taken_0xe38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xe3c: 0x24e70028  addiu       $a3, $a3, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 40));
        if (branch_taken_0xe38) {
            ctx->pc = 0xD30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_d30;
        }
    }
    ctx->pc = 0xE40u;
    // 0xe40: 0x3e00008  jr          $ra
    ctx->pc = 0xE40u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe44: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE40u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE48u;
}


// Function: dbcman_00000e48
// Address: 0xe48 - 0xe88
void dbcman_00000e48_0xe48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000e48_0xe48");
#endif

    ctx->pc = 0xe48u;

    // 0xe48: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xe4c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xe50: 0x220c0  sll         $a0, $v0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xe54: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0xe58: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0xe5c: 0x8c6327c0  lw          $v1, 0x27C0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10176)));
    // 0xe60: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xe64: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xE64u;
    {
        const bool branch_taken_0xe64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0xe68: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0xe64) {
            ctx->pc = 0xE80u;
            goto label_e80;
        }
    }
    ctx->pc = 0xE6Cu;
    // 0xe6c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xe70: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0xe74: 0xac2227c0  sw          $v0, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 2));
    // 0xe78: 0x3e00008  jr          $ra
    ctx->pc = 0xE78u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe7c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
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
label_e80:
    // 0xe80: 0x3e00008  jr          $ra
    ctx->pc = 0xE80u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe84: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE80u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE88u;
}


// Function: dbcman_00000e88
// Address: 0xe88 - 0xecc
void dbcman_00000e88_0xe88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000e88_0xe88");
#endif

    ctx->pc = 0xe88u;

    // 0xe88: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xe8c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xe90: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xe94: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xe98: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xe9c: 0x8c4227c0  lw          $v0, 0x27C0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10176)));
    // 0xea0: 0x0  nop
    // NOP
    // 0xea4: 0x28420003  slti        $v0, $v0, 0x3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0xea8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xEA8u;
    {
        const bool branch_taken_0xea8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xeac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0xea8) {
            ctx->pc = 0xEC4u;
            goto label_ec4;
        }
    }
    ctx->pc = 0xEB0u;
    // 0xeb0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xeb4: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xeb8: 0xac2227c0  sw          $v0, 0x27C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10176), GPR_U32(ctx, 2));
    // 0xebc: 0x3e00008  jr          $ra
    ctx->pc = 0xEBCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xec0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xEBCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xEC4u;
label_ec4:
    // 0xec4: 0x3e00008  jr          $ra
    ctx->pc = 0xEC4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xec8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xEC4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xECCu;
}


// Function: dbcman_00000ecc
// Address: 0xecc - 0xf20
void dbcman_00000ecc_0xecc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000ecc_0xecc");
#endif

    ctx->pc = 0xeccu;

    // 0xecc: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xed0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xed4: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xed8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xedc: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xee0: 0x8c4227c0  lw          $v0, 0x27C0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10176)));
    // 0xee4: 0x0  nop
    // NOP
    // 0xee8: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0xeec: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0xEECu;
    {
        const bool branch_taken_0xeec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xef0: 0x51080  sll         $v0, $a1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
        if (branch_taken_0xeec) {
            ctx->pc = 0xF14u;
            goto label_f14;
        }
    }
    ctx->pc = 0xEF4u;
    // 0xef4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xef8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xefc: 0x8c2327cc  lw          $v1, 0x27CC($at)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 10188)));
    // 0xf00: 0x0  nop
    // NOP
    // 0xf04: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xf08: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf0c: 0x3e00008  jr          $ra
    ctx->pc = 0xF0Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF0Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF14u;
label_f14:
    // 0xf14: 0x3e00008  jr          $ra
    ctx->pc = 0xF14u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf18: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF14u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF1Cu;
    // 0xf1c: 0x0  nop
    // NOP
}


// Function: dbcman_00000f20
// Address: 0xf20 - 0xf48
void dbcman_00000f20_0xf20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000f20_0xf20");
#endif

    switch (ctx->pc) {
        case 0xf28u: goto label_f28;
        default: break;
    }

    ctx->pc = 0xf20u;

    // 0xf20: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0xf24: 0x240202d0  addiu       $v0, $zero, 0x2D0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 720));
label_f28:
    // 0xf28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf2c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xf30: 0xac202a40  sw          $zero, 0x2A40($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10816), GPR_U32(ctx, 0));
    // 0xf34: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0xf38: 0x461fffb  bgez        $v1, . + 4 + (-0x5 << 2)
    ctx->pc = 0xF38u;
    {
        const bool branch_taken_0xf38 = (GPR_S32(ctx, 3) >= 0);
        // 0xf3c: 0x2442ffd0  addiu       $v0, $v0, -0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967248));
        if (branch_taken_0xf38) {
            ctx->pc = 0xF28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_f28;
        }
    }
    ctx->pc = 0xF40u;
    // 0xf40: 0x3e00008  jr          $ra
    ctx->pc = 0xF40u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF40u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF48u;
}


// Function: dbcman_00000f48
// Address: 0xf48 - 0x1080
void dbcman_00000f48_0xf48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00000f48_0xf48");
#endif

    switch (ctx->pc) {
        case 0xf84u: goto label_f84;
        case 0x100cu: goto label_100c;
        case 0x1038u: goto label_1038;
        default: break;
    }

    ctx->pc = 0xf48u;

    // 0xf48: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0xf4c: 0xa03821  addu        $a3, $a1, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0xf50: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0xf54: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xf58: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0xf5c: 0x24120001  addiu       $s2, $zero, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xf60: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
    // 0xf64: 0x24130002  addiu       $s3, $zero, 0x2
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0xf68: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xf6c: 0x24422a44  addiu       $v0, $v0, 0x2A44
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10820));
    // 0xf70: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0xf74: 0x2450fffc  addiu       $s0, $v0, -0x4
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0xf78: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xf7c: 0x2201821  addu        $v1, $s1, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xf80: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_f84:
    // 0xf84: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xf88: 0x0  nop
    // NOP
    // 0xf8c: 0x1c40002e  bgtz        $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0xF8Cu;
    {
        const bool branch_taken_0xf8c = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0xf8c) {
            ctx->pc = 0x1048u;
            goto label_1048;
        }
    }
    ctx->pc = 0xF94u;
    // 0xf94: 0xae120000  sw          $s2, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0xf98: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xf9c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xfa0: 0xac272a68  sw          $a3, 0x2A68($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10856), GPR_U32(ctx, 7));
    // 0xfa4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfa8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xfac: 0xac262a6c  sw          $a2, 0x2A6C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10860), GPR_U32(ctx, 6));
    // 0xfb0: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0xfb4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfb8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xfbc: 0xac222a44  sw          $v0, 0x2A44($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10820), GPR_U32(ctx, 2));
    // 0xfc0: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0xfc4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfc8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xfcc: 0xac222a48  sw          $v0, 0x2A48($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10824), GPR_U32(ctx, 2));
    // 0xfd0: 0x8c820008  lw          $v0, 0x8($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0xfd4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfd8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xfdc: 0xac222a4c  sw          $v0, 0x2A4C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10828), GPR_U32(ctx, 2));
    // 0xfe0: 0x8c82000c  lw          $v0, 0xC($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0xfe4: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xfe8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xfec: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xff0: 0xac222a50  sw          $v0, 0x2A50($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10832), GPR_U32(ctx, 2));
    // 0xff4: 0x8c820010  lw          $v0, 0x10($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0xff8: 0x603821  addu        $a3, $v1, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xffc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1000: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x1004: 0xac222a54  sw          $v0, 0x2A54($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10836), GPR_U32(ctx, 2));
    // 0x1008: 0xc71821  addu        $v1, $a2, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
label_100c:
    // 0x100c: 0x861021  addu        $v0, $a0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1010: 0x90420014  lbu         $v0, 0x14($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1014: 0x24c60001  addiu       $a2, $a2, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1018: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x101c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x1020: 0xa0222a58  sb          $v0, 0x2A58($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 10840), (uint8_t)GPR_U32(ctx, 2));
    // 0x1024: 0x28c20010  slti        $v0, $a2, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1028: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1028u;
    {
        const bool branch_taken_0x1028 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x102c: 0xc71821  addu        $v1, $a2, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
        if (branch_taken_0x1028) {
            ctx->pc = 0x100Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100c;
        }
    }
    ctx->pc = 0x1030u;
    // 0x1030: 0xc000553  jal         func_00154C
    ctx->pc = 0x1030u;
    SET_GPR_U32(ctx, 31, 0x1038u);
    // 0x1034: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x154Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x154Cu, 0x1030u, 0x1038u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1038u;
label_1038:
    // 0x1038: 0x1452000a  bne         $v0, $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x1038u;
    {
        const bool branch_taken_0x1038 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        // 0x103c: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1038) {
            ctx->pc = 0x1064u;
            goto label_1064;
        }
    }
    ctx->pc = 0x1040u;
    // 0x1040: 0x8000419  j           func_001064
    ctx->pc = 0x1040u;
    // 0x1044: 0xae130000  sw          $s3, 0x0($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 19));
    ctx->pc = 0x1064u;
    goto label_1064;
    ctx->pc = 0x1048u;
label_1048:
    // 0x1048: 0x26100030  addiu       $s0, $s0, 0x30
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x104c: 0x24a50030  addiu       $a1, $a1, 0x30
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x1050: 0x26310001  addiu       $s1, $s1, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1054: 0x2a220010  slti        $v0, $s1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1058: 0x1440ffca  bnez        $v0, . + 4 + (-0x36 << 2)
    ctx->pc = 0x1058u;
    {
        const bool branch_taken_0x1058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x105c: 0x24630030  addiu       $v1, $v1, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 48));
        if (branch_taken_0x1058) {
            ctx->pc = 0xF84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_f84;
        }
    }
    ctx->pc = 0x1060u;
    // 0x1060: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1064:
    // 0x1064: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1068: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x106c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1070: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1074: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1078: 0x3e00008  jr          $ra
    ctx->pc = 0x1078u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x107c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1078u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1080u;
}


// Function: dbcman_00001080
// Address: 0x1080 - 0x10e0
void dbcman_00001080_0x1080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001080_0x1080");
#endif

    switch (ctx->pc) {
        case 0x10ccu: goto label_10cc;
        default: break;
    }

    ctx->pc = 0x1080u;

    // 0x1080: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1084: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1088: 0x21900  sll         $v1, $v0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x108c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1090: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1094: 0x8c422a40  lw          $v0, 0x2A40($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10816)));
    // 0x1098: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x109c: 0x18400008  blez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x109Cu;
    {
        const bool branch_taken_0x109c = (GPR_S32(ctx, 2) <= 0);
        // 0x10a0: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0x109c) {
            ctx->pc = 0x10C0u;
            goto label_10c0;
        }
    }
    ctx->pc = 0x10A4u;
    // 0x10a4: 0x51080  sll         $v0, $a1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x10a8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10ac: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x10b0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x10b4: 0x8c222a68  lw          $v0, 0x2A68($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 10856)));
    // 0x10b8: 0x8000434  j           func_0010D0
    ctx->pc = 0x10B8u;
    ctx->pc = 0x10D0u;
    goto label_10d0;
    ctx->pc = 0x10C0u;
label_10c0:
    // 0x10c0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x10c4: 0xc0004c9  jal         func_001324
    ctx->pc = 0x10C4u;
    SET_GPR_U32(ctx, 31, 0x10CCu);
    // 0x10c8: 0x24842480  addiu       $a0, $a0, 0x2480 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9344));
    ctx->pc = 0x1324u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1324u, 0x10C4u, 0x10CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10CCu;
label_10cc:
    // 0x10cc: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_10d0:
    // 0x10d0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10d4: 0x0  nop
    // NOP
    // 0x10d8: 0x3e00008  jr          $ra
    ctx->pc = 0x10D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x10dc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x10D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x10E0u;
}


// Function: dbcman_000010e0
// Address: 0x10e0 - 0x1148
void dbcman_000010e0_0x10e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000010e0_0x10e0");
#endif

    switch (ctx->pc) {
        case 0x1128u: goto label_1128;
        default: break;
    }

    ctx->pc = 0x10e0u;

    // 0x10e0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x10e4: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x10e8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10ec: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x10f0: 0x28100  sll         $s0, $v0, 4
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x10f4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x10f8: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10fc: 0x8c422a40  lw          $v0, 0x2A40($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10816)));
    // 0x1100: 0x0  nop
    // NOP
    // 0x1104: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1104u;
    {
        const bool branch_taken_0x1104 = (GPR_S32(ctx, 2) > 0);
        // 0x1108: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x1104) {
            ctx->pc = 0x1114u;
            goto label_1114;
        }
    }
    ctx->pc = 0x110Cu;
    // 0x110c: 0x800044e  j           func_001138
    ctx->pc = 0x110Cu;
    // 0x1110: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1138u;
    goto label_1138;
    ctx->pc = 0x1114u;
label_1114:
    // 0x1114: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1118: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1118u;
    {
        const bool branch_taken_0x1118 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1118) {
            ctx->pc = 0x1128u;
            goto label_1128;
        }
    }
    ctx->pc = 0x1120u;
    // 0x1120: 0xc000586  jal         func_001618
    ctx->pc = 0x1120u;
    SET_GPR_U32(ctx, 31, 0x1128u);
    ctx->pc = 0x1618u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1618u, 0x1120u, 0x1128u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1128u;
label_1128:
    // 0x1128: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x112c: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
    // 0x1130: 0xac202a40  sw          $zero, 0x2A40($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10816), GPR_U32(ctx, 0));
    // 0x1134: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1138:
    // 0x1138: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x113c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1140: 0x3e00008  jr          $ra
    ctx->pc = 0x1140u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1144: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1140u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1148u;
}


// Function: dbcman_00001148
// Address: 0x1148 - 0x1270
void dbcman_00001148_0x1148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001148_0x1148");
#endif

    switch (ctx->pc) {
        case 0x1154u: goto label_1154;
        case 0x1218u: goto label_1218;
        default: break;
    }

    ctx->pc = 0x1148u;

    // 0x1148: 0x5821  addu        $t3, $zero, $zero
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x114c: 0x240c0001  addiu       $t4, $zero, 0x1
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1150: 0x1604021  addu        $t0, $t3, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 0)));
label_1154:
    // 0x1154: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1158: 0x481021  addu        $v0, $v0, $t0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x115c: 0x8c422a40  lw          $v0, 0x2A40($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10816)));
    // 0x1160: 0x0  nop
    // NOP
    // 0x1164: 0x144c003c  bne         $v0, $t4, . + 4 + (0x3C << 2)
    ctx->pc = 0x1164u;
    {
        const bool branch_taken_0x1164 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 12));
        if (branch_taken_0x1164) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x116Cu;
    // 0x116c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1170: 0xc83021  addu        $a2, $a2, $t0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x1174: 0x8cc62a44  lw          $a2, 0x2A44($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 10820)));
    // 0x1178: 0x0  nop
    // NOP
    // 0x117c: 0x30c20001  andi        $v0, $a2, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1);
    // 0x1180: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1180u;
    {
        const bool branch_taken_0x1180 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1184: 0x30c20002  andi        $v0, $a2, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)2);
        if (branch_taken_0x1180) {
            ctx->pc = 0x11A4u;
            goto label_11a4;
        }
    }
    ctx->pc = 0x1188u;
    // 0x1188: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x118c: 0x681821  addu        $v1, $v1, $t0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1190: 0x8c632a48  lw          $v1, 0x2A48($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10824)));
    // 0x1194: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1198: 0x0  nop
    // NOP
    // 0x119c: 0x1462002e  bne         $v1, $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x119Cu;
    {
        const bool branch_taken_0x119c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x11a0: 0x30c20002  andi        $v0, $a2, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)2);
        if (branch_taken_0x119c) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x11A4u;
label_11a4:
    // 0x11a4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x11A4u;
    {
        const bool branch_taken_0x11a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x11a8: 0x30c20004  andi        $v0, $a2, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)4);
        if (branch_taken_0x11a4) {
            ctx->pc = 0x11E4u;
            goto label_11e4;
        }
    }
    ctx->pc = 0x11ACu;
    // 0x11ac: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x11b0: 0x681821  addu        $v1, $v1, $t0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x11b4: 0x8c632a4c  lw          $v1, 0x2A4C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10828)));
    // 0x11b8: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11bc: 0x0  nop
    // NOP
    // 0x11c0: 0x14620025  bne         $v1, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x11C0u;
    {
        const bool branch_taken_0x11c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x11c0) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x11C8u;
    // 0x11c8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x11cc: 0x681821  addu        $v1, $v1, $t0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x11d0: 0x8c632a50  lw          $v1, 0x2A50($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10832)));
    // 0x11d4: 0x8ca20004  lw          $v0, 0x4($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x11d8: 0x0  nop
    // NOP
    // 0x11dc: 0x1462001e  bne         $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11DCu;
    {
        const bool branch_taken_0x11dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x11e0: 0x30c20004  andi        $v0, $a2, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)4);
        if (branch_taken_0x11dc) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x11E4u;
label_11e4:
    // 0x11e4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11E4u;
    {
        const bool branch_taken_0x11e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x11e8: 0x30c20008  andi        $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)8);
        if (branch_taken_0x11e4) {
            ctx->pc = 0x1208u;
            goto label_1208;
        }
    }
    ctx->pc = 0x11ECu;
    // 0x11ec: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x11f0: 0x681821  addu        $v1, $v1, $t0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x11f4: 0x8c632a54  lw          $v1, 0x2A54($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10836)));
    // 0x11f8: 0x8c820004  lw          $v0, 0x4($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x11fc: 0x0  nop
    // NOP
    // 0x1200: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1200u;
    {
        const bool branch_taken_0x1200 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1204: 0x30c20008  andi        $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)8);
        if (branch_taken_0x1200) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x1208u;
label_1208:
    // 0x1208: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1208u;
    {
        const bool branch_taken_0x1208 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x120c: 0x3821  addu        $a3, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1208) {
            ctx->pc = 0x1250u;
            goto label_1250;
        }
    }
    ctx->pc = 0x1210u;
    // 0x1210: 0xe04821  addu        $t1, $a3, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    // 0x1214: 0x1005021  addu        $t2, $t0, $zero
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 0)));
label_1218:
    // 0x1218: 0xea1021  addu        $v0, $a3, $t2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x121c: 0xa71821  addu        $v1, $a1, $a3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1220: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1224: 0xc23021  addu        $a2, $a2, $v0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1228: 0x90c62a58  lbu         $a2, 0x2A58($a2)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 10840)));
    // 0x122c: 0x90620008  lbu         $v0, 0x8($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1230: 0x0  nop
    // NOP
    // 0x1234: 0x10c20002  beq         $a2, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1234u;
    {
        const bool branch_taken_0x1234 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        if (branch_taken_0x1234) {
            ctx->pc = 0x1240u;
            goto label_1240;
        }
    }
    ctx->pc = 0x123Cu;
    // 0x123c: 0x24090001  addiu       $t1, $zero, 0x1
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1240:
    // 0x1240: 0x14c0fff5  bnez        $a2, . + 4 + (-0xB << 2)
    ctx->pc = 0x1240u;
    {
        const bool branch_taken_0x1240 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        // 0x1244: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        if (branch_taken_0x1240) {
            ctx->pc = 0x1218u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1218;
        }
    }
    ctx->pc = 0x1248u;
    // 0x1248: 0x112c0003  beq         $t1, $t4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1248u;
    {
        const bool branch_taken_0x1248 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 12));
        if (branch_taken_0x1248) {
            ctx->pc = 0x1258u;
            goto label_1258;
        }
    }
    ctx->pc = 0x1250u;
label_1250:
    // 0x1250: 0x3e00008  jr          $ra
    ctx->pc = 0x1250u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1254: 0x1601021  addu        $v0, $t3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1250u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1258u;
label_1258:
    // 0x1258: 0x256b0001  addiu       $t3, $t3, 0x1
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x125c: 0x29620010  slti        $v0, $t3, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1260: 0x1440ffbc  bnez        $v0, . + 4 + (-0x44 << 2)
    ctx->pc = 0x1260u;
    {
        const bool branch_taken_0x1260 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1264: 0x25080030  addiu       $t0, $t0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 48));
        if (branch_taken_0x1260) {
            ctx->pc = 0x1154u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1154;
        }
    }
    ctx->pc = 0x1268u;
    // 0x1268: 0x3e00008  jr          $ra
    ctx->pc = 0x1268u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x126c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1268u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1270u;
}


// Function: dbcman_00001270
// Address: 0x1270 - 0x12b0
void dbcman_00001270_0x1270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001270_0x1270");
#endif

    ctx->pc = 0x1270u;

    // 0x1270: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1274: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1278: 0x22100  sll         $a0, $v0, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x127c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1280: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1284: 0x8c632a40  lw          $v1, 0x2A40($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10816)));
    // 0x1288: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128c: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x128Cu;
    {
        const bool branch_taken_0x128c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1290: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x128c) {
            ctx->pc = 0x12A8u;
            goto label_12a8;
        }
    }
    ctx->pc = 0x1294u;
    // 0x1294: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1298: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x129c: 0xac222a40  sw          $v0, 0x2A40($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10816), GPR_U32(ctx, 2));
    // 0x12a0: 0x3e00008  jr          $ra
    ctx->pc = 0x12A0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x12a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x12A0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x12A8u;
label_12a8:
    // 0x12a8: 0x3e00008  jr          $ra
    ctx->pc = 0x12A8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x12ac: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x12A8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x12B0u;
}


// Function: dbcman_000012b0
// Address: 0x12b0 - 0x12f4
void dbcman_000012b0_0x12b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000012b0_0x12b0");
#endif

    ctx->pc = 0x12b0u;

    // 0x12b0: 0x41040  sll         $v0, $a0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x12b4: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12b8: 0x21900  sll         $v1, $v0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x12bc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x12c0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12c4: 0x8c422a40  lw          $v0, 0x2A40($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10816)));
    // 0x12c8: 0x0  nop
    // NOP
    // 0x12cc: 0x28420002  slti        $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x12d0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x12D0u;
    {
        const bool branch_taken_0x12d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x12d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x12d0) {
            ctx->pc = 0x12ECu;
            goto label_12ec;
        }
    }
    ctx->pc = 0x12D8u;
    // 0x12d8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12dc: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x12e0: 0xac222a40  sw          $v0, 0x2A40($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 10816), GPR_U32(ctx, 2));
    // 0x12e4: 0x3e00008  jr          $ra
    ctx->pc = 0x12E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x12E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x12ECu;
label_12ec:
    // 0x12ec: 0x3e00008  jr          $ra
    ctx->pc = 0x12ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x12f0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x12ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x12F4u;
}


// Function: dbcman_000012f4
// Address: 0x12f4 - 0x1324
void dbcman_000012f4_0x12f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000012f4_0x12f4");
#endif

    ctx->pc = 0x12f4u;

    // 0x12f4: 0x2c820010  sltiu       $v0, $a0, 0x10
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x12f8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12F8u;
    {
        const bool branch_taken_0x12f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x12fc: 0x41040  sll         $v0, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x12f8) {
            ctx->pc = 0x131Cu;
            goto label_131c;
        }
    }
    ctx->pc = 0x1300u;
    // 0x1300: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1304: 0x21100  sll         $v0, $v0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1308: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x130c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1310: 0x8c222a40  lw          $v0, 0x2A40($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 10816)));
    // 0x1314: 0x3e00008  jr          $ra
    ctx->pc = 0x1314u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1318: 0x2102a  slt         $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1314u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x131Cu;
label_131c:
    // 0x131c: 0x3e00008  jr          $ra
    ctx->pc = 0x131Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1320: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x131Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1324u;
}


// Function: dbcman_00001324
// Address: 0x1324 - 0x13c0
void dbcman_00001324_0x1324(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001324_0x1324");
#endif

    switch (ctx->pc) {
        case 0x1358u: goto label_1358;
        case 0x1360u: goto label_1360;
        case 0x1394u: goto label_1394;
        case 0x13b0u: goto label_13b0;
        default: break;
    }

    ctx->pc = 0x1324u;

    // 0x1324: 0xafa40000  sw          $a0, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x1328: 0xafa50004  sw          $a1, 0x4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x132c: 0xafa60008  sw          $a2, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x1330: 0x3e00008  jr          $ra
    ctx->pc = 0x1330u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1334: 0xafa7000c  sw          $a3, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 7));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1330u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1338u;
    // 0x1338: 0x0  nop
    // NOP
    // 0x133c: 0x0  nop
    // NOP
    // 0x1340: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1344: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1348: 0x248424a0  addiu       $a0, $a0, 0x24A0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9376));
    // 0x134c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1350: 0xc000886  jal         func_002218
    ctx->pc = 0x1350u;
    SET_GPR_U32(ctx, 31, 0x1358u);
    // 0x1354: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x1350u, 0x1358u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1358u;
label_1358:
    // 0x1358: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x135c: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_1360:
    // 0x1360: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1364: 0xc23021  addu        $a2, $a2, $v0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1368: 0x84c62d40  lh          $a2, 0x2D40($a2)
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 11584)));
    // 0x136c: 0x0  nop
    // NOP
    // 0x1370: 0x4c00008  bltz        $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1370u;
    {
        const bool branch_taken_0x1370 = (GPR_S32(ctx, 6) < 0);
        if (branch_taken_0x1370) {
            ctx->pc = 0x1394u;
            goto label_1394;
        }
    }
    ctx->pc = 0x1378u;
    // 0x1378: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x137c: 0x248424bc  addiu       $a0, $a0, 0x24BC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9404));
    // 0x1380: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x1384: 0xe23821  addu        $a3, $a3, $v0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1388: 0x84e72d42  lh          $a3, 0x2D42($a3)
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 11586)));
    // 0x138c: 0xc000886  jal         func_002218
    ctx->pc = 0x138Cu;
    SET_GPR_U32(ctx, 31, 0x1394u);
    // 0x1390: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x138Cu, 0x1394u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1394u;
label_1394:
    // 0x1394: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1398: 0x2a020010  slti        $v0, $s0, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x139c: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x139Cu;
    {
        const bool branch_taken_0x139c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13a0: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x139c) {
            ctx->pc = 0x1360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1360;
        }
    }
    ctx->pc = 0x13A4u;
    // 0x13a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x13a8: 0xc000886  jal         func_002218
    ctx->pc = 0x13A8u;
    SET_GPR_U32(ctx, 31, 0x13B0u);
    // 0x13ac: 0x248424dc  addiu       $a0, $a0, 0x24DC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9436));
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x13A8u, 0x13B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13B0u;
label_13b0:
    // 0x13b0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x13b4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b8: 0x3e00008  jr          $ra
    ctx->pc = 0x13B8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x13bc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x13B8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x13C0u;
}


// Function: dbcman_000013c0
// Address: 0x13c0 - 0x13fc
void dbcman_000013c0_0x13c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000013c0_0x13c0");
#endif

    switch (ctx->pc) {
        case 0x13ccu: goto label_13cc;
        default: break;
    }

    ctx->pc = 0x13c0u;

    // 0x13c0: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x13c4: 0x2404ffff  addiu       $a0, $zero, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x13c8: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_13cc:
    // 0x13cc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x13d4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x13d8: 0xa4242d40  sh          $a0, 0x2D40($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 11584), (uint16_t)GPR_U32(ctx, 4));
    // 0x13dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x13e0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x13e4: 0xa4242d42  sh          $a0, 0x2D42($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 11586), (uint16_t)GPR_U32(ctx, 4));
    // 0x13e8: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13ec: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x13ECu;
    {
        const bool branch_taken_0x13ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13f0: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x13ec) {
            ctx->pc = 0x13CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13cc;
        }
    }
    ctx->pc = 0x13F4u;
    // 0x13f4: 0x3e00008  jr          $ra
    ctx->pc = 0x13F4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x13F4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x13FCu;
}


// Function: dbcman_000013fc
// Address: 0x13fc - 0x14cc
void dbcman_000013fc_0x13fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000013fc_0x13fc");
#endif

    switch (ctx->pc) {
        case 0x1428u: goto label_1428;
        case 0x1450u: goto label_1450;
        case 0x1474u: goto label_1474;
        case 0x1488u: goto label_1488;
        default: break;
    }

    ctx->pc = 0x13fcu;

    // 0x13fc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1400: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1404: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1408: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x140c: 0xc02821  addu        $a1, $a2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1410: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1414: 0x2411ffff  addiu       $s1, $zero, -0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1418: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x141c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1420: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1424: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1428:
    // 0x1428: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x142c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1430: 0x84222d40  lh          $v0, 0x2D40($at)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 11584)));
    // 0x1434: 0x0  nop
    // NOP
    // 0x1438: 0x440000a  bltz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1438u;
    {
        const bool branch_taken_0x1438 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1438) {
            ctx->pc = 0x1464u;
            goto label_1464;
        }
    }
    ctx->pc = 0x1440u;
    // 0x1440: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1444: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1448: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1448u;
    {
        const bool branch_taken_0x1448 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x144c: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1448) {
            ctx->pc = 0x1428u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1428;
        }
    }
    ctx->pc = 0x1450u;
label_1450:
    // 0x1450: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1454: 0x16220005  bne         $s1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1454u;
    {
        const bool branch_taken_0x1454 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x1458: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1454) {
            ctx->pc = 0x146Cu;
            goto label_146c;
        }
    }
    ctx->pc = 0x145Cu;
    // 0x145c: 0x800052d  j           func_0014B4
    ctx->pc = 0x145Cu;
    ctx->pc = 0x14B4u;
    goto label_14b4;
    ctx->pc = 0x1464u;
label_1464:
    // 0x1464: 0x8000514  j           func_001450
    ctx->pc = 0x1464u;
    // 0x1468: 0x608821  addu        $s1, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1450u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1450;
    ctx->pc = 0x146Cu;
label_146c:
    // 0x146c: 0xc000452  jal         func_001148
    ctx->pc = 0x146Cu;
    SET_GPR_U32(ctx, 31, 0x1474u);
    ctx->pc = 0x1148u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1148u, 0x146Cu, 0x1474u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1474u;
label_1474:
    // 0x1474: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1478: 0x600000e  bltz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x1478u;
    {
        const bool branch_taken_0x1478 = (GPR_S32(ctx, 16) < 0);
        // 0x147c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1478) {
            ctx->pc = 0x14B4u;
            goto label_14b4;
        }
    }
    ctx->pc = 0x1480u;
    // 0x1480: 0xc00049c  jal         func_001270
    ctx->pc = 0x1480u;
    SET_GPR_U32(ctx, 31, 0x1488u);
    // 0x1484: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1270u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1270u, 0x1480u, 0x1488u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1488u;
label_1488:
    // 0x1488: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148c: 0x14430009  bne         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x148Cu;
    {
        const bool branch_taken_0x148c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x1490: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x148c) {
            ctx->pc = 0x14B4u;
            goto label_14b4;
        }
    }
    ctx->pc = 0x1494u;
    // 0x1494: 0x111880  sll         $v1, $s1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1498: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x149c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x14a0: 0xa4322d42  sh          $s2, 0x2D42($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 11586), (uint16_t)GPR_U32(ctx, 18));
    // 0x14a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x14a8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x14ac: 0xa4302d40  sh          $s0, 0x2D40($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 11584), (uint16_t)GPR_U32(ctx, 16));
    // 0x14b0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_14b4:
    // 0x14b4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x14b8: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14bc: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x14c0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14c4: 0x3e00008  jr          $ra
    ctx->pc = 0x14C4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x14c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x14C4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x14CCu;
}


// Function: dbcman_000014cc
// Address: 0x14cc - 0x154c
void dbcman_000014cc_0x14cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000014cc_0x14cc");
#endif

    switch (ctx->pc) {
        case 0x14f4u: goto label_14f4;
        case 0x1510u: goto label_1510;
        default: break;
    }

    ctx->pc = 0x14ccu;

    // 0x14cc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x14d0: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x14d4: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x14d8: 0x2412ffff  addiu       $s2, $zero, -0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x14dc: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x14e0: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0x14e4: 0x26312d40  addiu       $s1, $s1, 0x2D40
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 11584));
    // 0x14e8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x14ec: 0x26300002  addiu       $s0, $s1, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x14f0: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_14f4:
    // 0x14f4: 0x86020000  lh          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14f8: 0x0  nop
    // NOP
    // 0x14fc: 0x14440008  bne         $v0, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x14FCu;
    {
        const bool branch_taken_0x14fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        // 0x1500: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x14fc) {
            ctx->pc = 0x1520u;
            goto label_1520;
        }
    }
    ctx->pc = 0x1504u;
    // 0x1504: 0x86240000  lh          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1508: 0xc0004ac  jal         func_0012B0
    ctx->pc = 0x1508u;
    SET_GPR_U32(ctx, 31, 0x1510u);
    ctx->pc = 0x12B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x12B0u, 0x1508u, 0x1510u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1510u;
label_1510:
    // 0x1510: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1514: 0xa6120000  sh          $s2, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1518: 0x800054d  j           func_001534
    ctx->pc = 0x1518u;
    // 0x151c: 0xa6320000  sh          $s2, 0x0($s1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 18));
    ctx->pc = 0x1534u;
    goto label_1534;
    ctx->pc = 0x1520u;
label_1520:
    // 0x1520: 0x26310004  addiu       $s1, $s1, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x1524: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1528: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1528u;
    {
        const bool branch_taken_0x1528 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x152c: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        if (branch_taken_0x1528) {
            ctx->pc = 0x14F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14f4;
        }
    }
    ctx->pc = 0x1530u;
    // 0x1530: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1534:
    // 0x1534: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1538: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x153c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1540: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1544: 0x3e00008  jr          $ra
    ctx->pc = 0x1544u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1548: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1544u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x154Cu;
}


// Function: dbcman_0000154c
// Address: 0x154c - 0x1618
void dbcman_0000154c_0x154c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_0000154c_0x154c");
#endif

    switch (ctx->pc) {
        case 0x1574u: goto label_1574;
        case 0x159cu: goto label_159c;
        case 0x15c0u: goto label_15c0;
        case 0x15d4u: goto label_15d4;
        default: break;
    }

    ctx->pc = 0x154cu;

    // 0x154c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1550: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1554: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1558: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x155c: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x1560: 0x2411ffff  addiu       $s1, $zero, -0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1564: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1568: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x156c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1570: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1574:
    // 0x1574: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1578: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x157c: 0x84222d40  lh          $v0, 0x2D40($at)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 11584)));
    // 0x1580: 0x0  nop
    // NOP
    // 0x1584: 0x440000a  bltz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1584u;
    {
        const bool branch_taken_0x1584 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1584) {
            ctx->pc = 0x15B0u;
            goto label_15b0;
        }
    }
    ctx->pc = 0x158Cu;
    // 0x158c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1590: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1594: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1594u;
    {
        const bool branch_taken_0x1594 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1598: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1594) {
            ctx->pc = 0x1574u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1574;
        }
    }
    ctx->pc = 0x159Cu;
label_159c:
    // 0x159c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15a0: 0x16220005  bne         $s1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15A0u;
    {
        const bool branch_taken_0x15a0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        // 0x15a4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x15a0) {
            ctx->pc = 0x15B8u;
            goto label_15b8;
        }
    }
    ctx->pc = 0x15A8u;
    // 0x15a8: 0x8000580  j           func_001600
    ctx->pc = 0x15A8u;
    ctx->pc = 0x1600u;
    goto label_1600;
    ctx->pc = 0x15B0u;
label_15b0:
    // 0x15b0: 0x8000567  j           func_00159C
    ctx->pc = 0x15B0u;
    // 0x15b4: 0x608821  addu        $s1, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x159Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_159c;
    ctx->pc = 0x15B8u;
label_15b8:
    // 0x15b8: 0xc000300  jal         func_000C00
    ctx->pc = 0x15B8u;
    SET_GPR_U32(ctx, 31, 0x15C0u);
    ctx->pc = 0xC00u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xC00u, 0x15B8u, 0x15C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15C0u;
label_15c0:
    // 0x15c0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x15c4: 0x600000e  bltz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x15C4u;
    {
        const bool branch_taken_0x15c4 = (GPR_S32(ctx, 16) < 0);
        // 0x15c8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x15c4) {
            ctx->pc = 0x1600u;
            goto label_1600;
        }
    }
    ctx->pc = 0x15CCu;
    // 0x15cc: 0xc000392  jal         func_000E48
    ctx->pc = 0x15CCu;
    SET_GPR_U32(ctx, 31, 0x15D4u);
    // 0x15d0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xE48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE48u, 0x15CCu, 0x15D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15D4u;
label_15d4:
    // 0x15d4: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15d8: 0x14430009  bne         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x15D8u;
    {
        const bool branch_taken_0x15d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        // 0x15dc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x15d8) {
            ctx->pc = 0x1600u;
            goto label_1600;
        }
    }
    ctx->pc = 0x15E0u;
    // 0x15e0: 0x111880  sll         $v1, $s1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x15e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x15e8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x15ec: 0xa4302d42  sh          $s0, 0x2D42($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 11586), (uint16_t)GPR_U32(ctx, 16));
    // 0x15f0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x15f4: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x15f8: 0xa4322d40  sh          $s2, 0x2D40($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 11584), (uint16_t)GPR_U32(ctx, 18));
    // 0x15fc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1600:
    // 0x1600: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1604: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1608: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x160c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1610: 0x3e00008  jr          $ra
    ctx->pc = 0x1610u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1614: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1610u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1618u;
}


// Function: dbcman_00001618
// Address: 0x1618 - 0x1698
void dbcman_00001618_0x1618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001618_0x1618");
#endif

    switch (ctx->pc) {
        case 0x1640u: goto label_1640;
        case 0x165cu: goto label_165c;
        default: break;
    }

    ctx->pc = 0x1618u;

    // 0x1618: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161c: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1620: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x1624: 0x2412ffff  addiu       $s2, $zero, -0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1628: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x162c: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0x1630: 0x26312d40  addiu       $s1, $s1, 0x2D40
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 11584));
    // 0x1634: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1638: 0x26300002  addiu       $s0, $s1, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x163c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_1640:
    // 0x1640: 0x86220000  lh          $v0, 0x0($s1)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1644: 0x0  nop
    // NOP
    // 0x1648: 0x14440008  bne         $v0, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1648u;
    {
        const bool branch_taken_0x1648 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        // 0x164c: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x1648) {
            ctx->pc = 0x166Cu;
            goto label_166c;
        }
    }
    ctx->pc = 0x1650u;
    // 0x1650: 0x86040000  lh          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1654: 0xc0003a2  jal         func_000E88
    ctx->pc = 0x1654u;
    SET_GPR_U32(ctx, 31, 0x165Cu);
    ctx->pc = 0xE88u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE88u, 0x1654u, 0x165Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x165Cu;
label_165c:
    // 0x165c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1660: 0xa6120000  sh          $s2, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 18));
    // 0x1664: 0x80005a0  j           func_001680
    ctx->pc = 0x1664u;
    // 0x1668: 0xa6320000  sh          $s2, 0x0($s1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 18));
    ctx->pc = 0x1680u;
    goto label_1680;
    ctx->pc = 0x166Cu;
label_166c:
    // 0x166c: 0x26310004  addiu       $s1, $s1, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x1670: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1674: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1674u;
    {
        const bool branch_taken_0x1674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1678: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        if (branch_taken_0x1674) {
            ctx->pc = 0x1640u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1640;
        }
    }
    ctx->pc = 0x167Cu;
    // 0x167c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1680:
    // 0x1680: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1684: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1688: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x168c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1690: 0x3e00008  jr          $ra
    ctx->pc = 0x1690u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1694: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1690u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1698u;
}


// Function: dbcman_00001698
// Address: 0x1698 - 0x16e0
void dbcman_00001698_0x1698(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001698_0x1698");
#endif

    switch (ctx->pc) {
        case 0x16a0u: goto label_16a0;
        default: break;
    }

    ctx->pc = 0x1698u;

    // 0x1698: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x169c: 0x32880  sll         $a1, $v1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_16a0:
    // 0x16a0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x16a4: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16a8: 0x84422d40  lh          $v0, 0x2D40($v0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 11584)));
    // 0x16ac: 0x0  nop
    // NOP
    // 0x16b0: 0x14440006  bne         $v0, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16B0u;
    {
        const bool branch_taken_0x16b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        // 0x16b4: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x16b0) {
            ctx->pc = 0x16CCu;
            goto label_16cc;
        }
    }
    ctx->pc = 0x16B8u;
    // 0x16b8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x16bc: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16c0: 0x84422d42  lh          $v0, 0x2D42($v0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 11586)));
    // 0x16c4: 0x3e00008  jr          $ra
    ctx->pc = 0x16C4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x16C4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x16CCu;
label_16cc:
    // 0x16cc: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x16d0: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x16D0u;
    {
        const bool branch_taken_0x16d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x16d4: 0x32880  sll         $a1, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x16d0) {
            ctx->pc = 0x16A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16a0;
        }
    }
    ctx->pc = 0x16D8u;
    // 0x16d8: 0x3e00008  jr          $ra
    ctx->pc = 0x16D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x16dc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x16D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x16E0u;
}


// Function: dbcman_000016e0
// Address: 0x16e0 - 0x1730
void dbcman_000016e0_0x16e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000016e0_0x16e0");
#endif

    switch (ctx->pc) {
        case 0x16e8u: goto label_16e8;
        default: break;
    }

    ctx->pc = 0x16e0u;

    // 0x16e0: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x16e4: 0x32880  sll         $a1, $v1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_16e8:
    // 0x16e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x16ec: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16f0: 0x84422d42  lh          $v0, 0x2D42($v0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 11586)));
    // 0x16f4: 0x0  nop
    // NOP
    // 0x16f8: 0x14440006  bne         $v0, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16F8u;
    {
        const bool branch_taken_0x16f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        // 0x16fc: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x16f8) {
            ctx->pc = 0x1714u;
            goto label_1714;
        }
    }
    ctx->pc = 0x1700u;
    // 0x1700: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1704: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1708: 0x84422d40  lh          $v0, 0x2D40($v0)
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 11584)));
    // 0x170c: 0x3e00008  jr          $ra
    ctx->pc = 0x170Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x170Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1714u;
label_1714:
    // 0x1714: 0x28620010  slti        $v0, $v1, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1718: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1718u;
    {
        const bool branch_taken_0x1718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x171c: 0x32880  sll         $a1, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1718) {
            ctx->pc = 0x16E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16e8;
        }
    }
    ctx->pc = 0x1720u;
    // 0x1720: 0x3e00008  jr          $ra
    ctx->pc = 0x1720u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1724: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
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
    // 0x1728: 0x0  nop
    // NOP
    // 0x172c: 0x0  nop
    // NOP
}


// Function: dbcman_00001730
// Address: 0x1730 - 0x1768
void dbcman_00001730_0x1730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001730_0x1730");
#endif

    switch (ctx->pc) {
        case 0x1730u: goto label_1730;
        case 0x1734u: goto label_1734;
        case 0x1738u: goto label_1738;
        case 0x173cu: goto label_173c;
        case 0x1740u: goto label_1740;
        case 0x1744u: goto label_1744;
        case 0x1748u: goto label_1748;
        case 0x174cu: goto label_174c;
        case 0x1750u: goto label_1750;
        case 0x1754u: goto label_1754;
        case 0x1758u: goto label_1758;
        case 0x175cu: goto label_175c;
        case 0x1760u: goto label_1760;
        case 0x1764u: goto label_1764;
        default: break;
    }

    ctx->pc = 0x1730u;

label_1730:
    // 0x1730: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_1734:
    // 0x1734: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_1738:
    // 0x1738: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_173c:
    // 0x173c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
label_1740:
    // 0x1740: 0xc0003b3  jal         func_000ECC
label_1744:
    if (ctx->pc == 0x1744u) {
        // 0x1744: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1748u;
        goto label_1748;
    }
    ctx->pc = 0x1740u;
    SET_GPR_U32(ctx, 31, 0x1748u);
    // 0x1744: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xECCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECCu, 0x1740u, 0x1748u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1748u;
label_1748:
    // 0x1748: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_174c:
    if (ctx->pc == 0x174Cu) {
        ctx->pc = 0x1750u;
        goto label_1750;
    }
    ctx->pc = 0x1748u;
    {
        const bool branch_taken_0x1748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1748) {
            ctx->pc = 0x1758u;
            goto label_1758;
        }
    }
    ctx->pc = 0x1750u;
label_1750:
    // 0x1750: 0x40f809  jalr        $v0
label_1754:
    if (ctx->pc == 0x1754u) {
        // 0x1754: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x1758u;
        goto label_1758;
    }
    ctx->pc = 0x1750u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1758u);
        // 0x1754: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x1750u, 0x1758u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x1758u;
label_1758:
    // 0x1758: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_175c:
    // 0x175c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1760:
    // 0x1760: 0x3e00008  jr          $ra
label_1764:
    if (ctx->pc == 0x1764u) {
        // 0x1764: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x1768u;
        goto label_fallthrough_0x1760;
    }
    ctx->pc = 0x1760u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1764: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1760u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x1760:
    ctx->pc = 0x1768u;
}


// Function: dbcman_00001768
// Address: 0x1768 - 0x17d8
void dbcman_00001768_0x1768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001768_0x1768");
#endif

    switch (ctx->pc) {
        case 0x1768u: goto label_1768;
        case 0x176cu: goto label_176c;
        case 0x1770u: goto label_1770;
        case 0x1774u: goto label_1774;
        case 0x1778u: goto label_1778;
        case 0x177cu: goto label_177c;
        case 0x1780u: goto label_1780;
        case 0x1784u: goto label_1784;
        case 0x1788u: goto label_1788;
        case 0x178cu: goto label_178c;
        case 0x1790u: goto label_1790;
        case 0x1794u: goto label_1794;
        case 0x1798u: goto label_1798;
        case 0x179cu: goto label_179c;
        case 0x17a0u: goto label_17a0;
        case 0x17a4u: goto label_17a4;
        case 0x17a8u: goto label_17a8;
        case 0x17acu: goto label_17ac;
        case 0x17b0u: goto label_17b0;
        case 0x17b4u: goto label_17b4;
        case 0x17b8u: goto label_17b8;
        case 0x17bcu: goto label_17bc;
        case 0x17c0u: goto label_17c0;
        case 0x17c4u: goto label_17c4;
        case 0x17c8u: goto label_17c8;
        case 0x17ccu: goto label_17cc;
        case 0x17d0u: goto label_17d0;
        case 0x17d4u: goto label_17d4;
        default: break;
    }

    ctx->pc = 0x1768u;

label_1768:
    // 0x1768: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_176c:
    // 0x176c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_1770:
    // 0x1770: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1774:
    // 0x1774: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
label_1778:
    // 0x1778: 0xc0003b3  jal         func_000ECC
label_177c:
    if (ctx->pc == 0x177Cu) {
        // 0x177c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1780u;
        goto label_1780;
    }
    ctx->pc = 0x1778u;
    SET_GPR_U32(ctx, 31, 0x1780u);
    // 0x177c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xECCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECCu, 0x1778u, 0x1780u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1780u;
label_1780:
    // 0x1780: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_1784:
    if (ctx->pc == 0x1784u) {
        ctx->pc = 0x1788u;
        goto label_1788;
    }
    ctx->pc = 0x1780u;
    {
        const bool branch_taken_0x1780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1780) {
            ctx->pc = 0x1790u;
            goto label_1790;
        }
    }
    ctx->pc = 0x1788u;
label_1788:
    // 0x1788: 0x40f809  jalr        $v0
label_178c:
    if (ctx->pc == 0x178Cu) {
        // 0x178c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x1790u;
        goto label_1790;
    }
    ctx->pc = 0x1788u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1790u);
        // 0x178c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x1788u, 0x1790u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x1790u;
label_1790:
    // 0x1790: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_1794:
    // 0x1794: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1798:
    // 0x1798: 0x3e00008  jr          $ra
label_179c:
    if (ctx->pc == 0x179Cu) {
        // 0x179c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x17A0u;
        goto label_17a0;
    }
    ctx->pc = 0x1798u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x179c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1798u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x17A0u;
label_17a0:
    // 0x17a0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_17a4:
    // 0x17a4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_17a8:
    // 0x17a8: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_17ac:
    // 0x17ac: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
label_17b0:
    // 0x17b0: 0xc0003b3  jal         func_000ECC
label_17b4:
    if (ctx->pc == 0x17B4u) {
        // 0x17b4: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x17B8u;
        goto label_17b8;
    }
    ctx->pc = 0x17B0u;
    SET_GPR_U32(ctx, 31, 0x17B8u);
    // 0x17b4: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0xECCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECCu, 0x17B0u, 0x17B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17B8u;
label_17b8:
    // 0x17b8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_17bc:
    if (ctx->pc == 0x17BCu) {
        ctx->pc = 0x17C0u;
        goto label_17c0;
    }
    ctx->pc = 0x17B8u;
    {
        const bool branch_taken_0x17b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b8) {
            ctx->pc = 0x17C8u;
            goto label_17c8;
        }
    }
    ctx->pc = 0x17C0u;
label_17c0:
    // 0x17c0: 0x40f809  jalr        $v0
label_17c4:
    if (ctx->pc == 0x17C4u) {
        // 0x17c4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x17C8u;
        goto label_17c8;
    }
    ctx->pc = 0x17C0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x17C8u);
        // 0x17c4: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x17C0u, 0x17C8u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x17C8u;
label_17c8:
    // 0x17c8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_17cc:
    // 0x17cc: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_17d0:
    // 0x17d0: 0x3e00008  jr          $ra
label_17d4:
    if (ctx->pc == 0x17D4u) {
        // 0x17d4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x17D8u;
        goto label_fallthrough_0x17d0;
    }
    ctx->pc = 0x17D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x17d4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x17D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x17d0:
    ctx->pc = 0x17D8u;
}


// Function: dbcman_000017d8
// Address: 0x17d8 - 0x1848
void dbcman_000017d8_0x17d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000017d8_0x17d8");
#endif

    switch (ctx->pc) {
        case 0x17d8u: goto label_17d8;
        case 0x17dcu: goto label_17dc;
        case 0x17e0u: goto label_17e0;
        case 0x17e4u: goto label_17e4;
        case 0x17e8u: goto label_17e8;
        case 0x17ecu: goto label_17ec;
        case 0x17f0u: goto label_17f0;
        case 0x17f4u: goto label_17f4;
        case 0x17f8u: goto label_17f8;
        case 0x17fcu: goto label_17fc;
        case 0x1800u: goto label_1800;
        case 0x1804u: goto label_1804;
        case 0x1808u: goto label_1808;
        case 0x180cu: goto label_180c;
        case 0x1810u: goto label_1810;
        case 0x1814u: goto label_1814;
        case 0x1818u: goto label_1818;
        case 0x181cu: goto label_181c;
        case 0x1820u: goto label_1820;
        case 0x1824u: goto label_1824;
        case 0x1828u: goto label_1828;
        case 0x182cu: goto label_182c;
        case 0x1830u: goto label_1830;
        case 0x1834u: goto label_1834;
        case 0x1838u: goto label_1838;
        case 0x183cu: goto label_183c;
        case 0x1840u: goto label_1840;
        case 0x1844u: goto label_1844;
        default: break;
    }

    ctx->pc = 0x17d8u;

label_17d8:
    // 0x17d8: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_17dc:
    // 0x17dc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_17e0:
    // 0x17e0: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_17e4:
    // 0x17e4: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_17e8:
    // 0x17e8: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_17ec:
    // 0x17ec: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_17f0:
    // 0x17f0: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_17f4:
    // 0x17f4: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_17f8:
    // 0x17f8: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_17fc:
    // 0x17fc: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_1800:
    // 0x1800: 0xc0003b3  jal         func_000ECC
label_1804:
    if (ctx->pc == 0x1804u) {
        // 0x1804: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0x1808u;
        goto label_1808;
    }
    ctx->pc = 0x1800u;
    SET_GPR_U32(ctx, 31, 0x1808u);
    // 0x1804: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0xECCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECCu, 0x1800u, 0x1808u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1808u;
label_1808:
    // 0x1808: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
label_180c:
    if (ctx->pc == 0x180Cu) {
        // 0x180c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x1810u;
        goto label_1810;
    }
    ctx->pc = 0x1808u;
    {
        const bool branch_taken_0x1808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x180c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x1808) {
            ctx->pc = 0x1828u;
            goto label_1828;
        }
    }
    ctx->pc = 0x1810u;
label_1810:
    // 0x1810: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_1814:
    // 0x1814: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1818:
    // 0x1818: 0x40f809  jalr        $v0
label_181c:
    if (ctx->pc == 0x181Cu) {
        // 0x181c: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x1820u;
        goto label_1820;
    }
    ctx->pc = 0x1818u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1820u);
        // 0x181c: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x1818u, 0x1820u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x1820u;
label_1820:
    // 0x1820: 0x800060b  j           func_00182C
label_1824:
    if (ctx->pc == 0x1824u) {
        ctx->pc = 0x1828u;
        goto label_1828;
    }
    ctx->pc = 0x1820u;
    ctx->pc = 0x182Cu;
    goto label_182c;
    ctx->pc = 0x1828u;
label_1828:
    // 0x1828: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_182c:
    // 0x182c: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_1830:
    // 0x1830: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1834:
    // 0x1834: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1838:
    // 0x1838: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_183c:
    // 0x183c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1840:
    // 0x1840: 0x3e00008  jr          $ra
label_1844:
    if (ctx->pc == 0x1844u) {
        // 0x1844: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x1848u;
        goto label_fallthrough_0x1840;
    }
    ctx->pc = 0x1840u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1844: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1840u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x1840:
    ctx->pc = 0x1848u;
}


// Function: dbcman_00001848
// Address: 0x1848 - 0x18cc
void dbcman_00001848_0x1848(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001848_0x1848");
#endif

    switch (ctx->pc) {
        case 0x1848u: goto label_1848;
        case 0x184cu: goto label_184c;
        case 0x1850u: goto label_1850;
        case 0x1854u: goto label_1854;
        case 0x1858u: goto label_1858;
        case 0x185cu: goto label_185c;
        case 0x1860u: goto label_1860;
        case 0x1864u: goto label_1864;
        case 0x1868u: goto label_1868;
        case 0x186cu: goto label_186c;
        case 0x1870u: goto label_1870;
        case 0x1874u: goto label_1874;
        case 0x1878u: goto label_1878;
        case 0x187cu: goto label_187c;
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
        default: break;
    }

    ctx->pc = 0x1848u;

label_1848:
    // 0x1848: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_184c:
    // 0x184c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_1850:
    // 0x1850: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1854:
    // 0x1854: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_1858:
    // 0x1858: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_185c:
    // 0x185c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_1860:
    // 0x1860: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_1864:
    // 0x1864: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_1868:
    // 0x1868: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_186c:
    // 0x186c: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
label_1870:
    // 0x1870: 0xc0003b3  jal         func_000ECC
label_1874:
    if (ctx->pc == 0x1874u) {
        // 0x1874: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x1878u;
        goto label_1878;
    }
    ctx->pc = 0x1870u;
    SET_GPR_U32(ctx, 31, 0x1878u);
    // 0x1874: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0xECCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECCu, 0x1870u, 0x1878u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1878u;
label_1878:
    // 0x1878: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_187c:
    // 0x187c: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
label_1880:
    if (ctx->pc == 0x1880u) {
        // 0x1880: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x1884u;
        goto label_1884;
    }
    ctx->pc = 0x187Cu;
    {
        const bool branch_taken_0x187c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x1880: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x187c) {
            ctx->pc = 0x18ACu;
            goto label_18ac;
        }
    }
    ctx->pc = 0x1884u;
label_1884:
    // 0x1884: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_1888:
    // 0x1888: 0x8fa20040  lw          $v0, 0x40($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_188c:
    // 0x188c: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1890:
    // 0x1890: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_1894:
    // 0x1894: 0x8fa20044  lw          $v0, 0x44($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
label_1898:
    // 0x1898: 0x2603821  addu        $a3, $s3, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_189c:
    // 0x189c: 0x60f809  jalr        $v1
label_18a0:
    if (ctx->pc == 0x18A0u) {
        // 0x18a0: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->pc = 0x18A4u;
        goto label_18a4;
    }
    ctx->pc = 0x189Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x18A4u);
        // 0x18a0: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x189Cu, 0x18A4u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x18A4u;
label_18a4:
    // 0x18a4: 0x800062c  j           func_0018B0
label_18a8:
    if (ctx->pc == 0x18A8u) {
        ctx->pc = 0x18ACu;
        goto label_18ac;
    }
    ctx->pc = 0x18A4u;
    ctx->pc = 0x18B0u;
    goto label_18b0;
    ctx->pc = 0x18ACu;
label_18ac:
    // 0x18ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_18b0:
    // 0x18b0: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_18b4:
    // 0x18b4: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_18b8:
    // 0x18b8: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_18bc:
    // 0x18bc: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_18c0:
    // 0x18c0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_18c4:
    // 0x18c4: 0x3e00008  jr          $ra
label_18c8:
    if (ctx->pc == 0x18C8u) {
        // 0x18c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x18CCu;
        goto label_fallthrough_0x18c4;
    }
    ctx->pc = 0x18C4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x18c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x18C4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x18c4:
    ctx->pc = 0x18CCu;
}


// Function: dbcman_000018cc
// Address: 0x18cc - 0x1940
void dbcman_000018cc_0x18cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000018cc_0x18cc");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0x18ccu;

label_18cc:
    // 0x18cc: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_18d0:
    // 0x18d0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_18d4:
    // 0x18d4: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_18d8:
    // 0x18d8: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_18dc:
    // 0x18dc: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_18e0:
    // 0x18e0: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_18e4:
    // 0x18e4: 0xc09021  addu        $s2, $a2, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_18e8:
    // 0x18e8: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_18ec:
    // 0x18ec: 0xe09821  addu        $s3, $a3, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_18f0:
    // 0x18f0: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_18f4:
    // 0x18f4: 0xc0003b3  jal         func_000ECC
label_18f8:
    if (ctx->pc == 0x18F8u) {
        // 0x18f8: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->pc = 0x18FCu;
        goto label_18fc;
    }
    ctx->pc = 0x18F4u;
    SET_GPR_U32(ctx, 31, 0x18FCu);
    // 0x18f8: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0xECCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xECCu, 0x18F4u, 0x18FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18FCu;
label_18fc:
    // 0x18fc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
label_1900:
    if (ctx->pc == 0x1900u) {
        // 0x1900: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x1904u;
        goto label_1904;
    }
    ctx->pc = 0x18FCu;
    {
        const bool branch_taken_0x18fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1900: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x18fc) {
            ctx->pc = 0x191Cu;
            goto label_191c;
        }
    }
    ctx->pc = 0x1904u;
label_1904:
    // 0x1904: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_1908:
    // 0x1908: 0x2403021  addu        $a2, $s2, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_190c:
    // 0x190c: 0x40f809  jalr        $v0
label_1910:
    if (ctx->pc == 0x1910u) {
        // 0x1910: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x1914u;
        goto label_1914;
    }
    ctx->pc = 0x190Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1914u);
        // 0x1910: 0x2603821  addu        $a3, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x190Cu, 0x1914u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x1914u;
label_1914:
    // 0x1914: 0x8000648  j           func_001920
label_1918:
    if (ctx->pc == 0x1918u) {
        ctx->pc = 0x191Cu;
        goto label_191c;
    }
    ctx->pc = 0x1914u;
    ctx->pc = 0x1920u;
    goto label_1920;
    ctx->pc = 0x191Cu;
label_191c:
    // 0x191c: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1920:
    // 0x1920: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_1924:
    // 0x1924: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1928:
    // 0x1928: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_192c:
    // 0x192c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_1930:
    // 0x1930: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1934:
    // 0x1934: 0x3e00008  jr          $ra
label_1938:
    if (ctx->pc == 0x1938u) {
        // 0x1938: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x193Cu;
        goto label_193c;
    }
    ctx->pc = 0x1934u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1938: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1934u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x193Cu;
label_193c:
    // 0x193c: 0x0  nop
    // NOP
    ;
}


// Function: dbcman_00001940
// Address: 0x1940 - 0x1978
void dbcman_00001940_0x1940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001940_0x1940");
#endif

    switch (ctx->pc) {
        case 0x1960u: goto label_1960;
        default: break;
    }

    ctx->pc = 0x1940u;

    // 0x1940: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1944: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1948: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x194c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1950: 0x8e050028  lw          $a1, 0x28($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1954: 0x8e06002c  lw          $a2, 0x2C($s0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1958: 0xc000153  jal         func_00054C
    ctx->pc = 0x1958u;
    SET_GPR_U32(ctx, 31, 0x1960u);
    // 0x195c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x54Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x54Cu, 0x1958u, 0x1960u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1960u;
label_1960:
    // 0x1960: 0xae020024  sw          $v0, 0x24($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x1964: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1968: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x196c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1970: 0x3e00008  jr          $ra
    ctx->pc = 0x1970u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1974: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1970u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1978u;
}


// Function: dbcman_00001978
// Address: 0x1978 - 0x19ac
void dbcman_00001978_0x1978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001978_0x1978");
#endif

    switch (ctx->pc) {
        case 0x1994u: goto label_1994;
        default: break;
    }

    ctx->pc = 0x1978u;

    // 0x1978: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x197c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1980: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1984: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1988: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x198c: 0xc000169  jal         func_0005A4
    ctx->pc = 0x198Cu;
    SET_GPR_U32(ctx, 31, 0x1994u);
    ctx->pc = 0x5A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5A4u, 0x198Cu, 0x1994u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1994u;
label_1994:
    // 0x1994: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1998: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x199c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x19a0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a4: 0x3e00008  jr          $ra
    ctx->pc = 0x19A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x19a8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x19A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x19ACu;
}


// Function: dbcman_000019ac
// Address: 0x19ac - 0x19e0
void dbcman_000019ac_0x19ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000019ac_0x19ac");
#endif

    switch (ctx->pc) {
        case 0x19c8u: goto label_19c8;
        default: break;
    }

    ctx->pc = 0x19acu;

    // 0x19ac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x19b0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x19b4: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x19b8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x19bc: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19c0: 0xc00017d  jal         func_0005F4
    ctx->pc = 0x19C0u;
    SET_GPR_U32(ctx, 31, 0x19C8u);
    ctx->pc = 0x5F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5F4u, 0x19C0u, 0x19C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19C8u;
label_19c8:
    // 0x19c8: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x19cc: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x19d0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x19d4: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19d8: 0x3e00008  jr          $ra
    ctx->pc = 0x19D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x19dc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x19D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x19E0u;
}


// Function: dbcman_000019e0
// Address: 0x19e0 - 0x1a14
void dbcman_000019e0_0x19e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000019e0_0x19e0");
#endif

    switch (ctx->pc) {
        case 0x19fcu: goto label_19fc;
        default: break;
    }

    ctx->pc = 0x19e0u;

    // 0x19e0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x19e4: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x19e8: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x19ec: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x19f0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19f4: 0xc00019c  jal         func_000670
    ctx->pc = 0x19F4u;
    SET_GPR_U32(ctx, 31, 0x19FCu);
    ctx->pc = 0x670u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x670u, 0x19F4u, 0x19FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19FCu;
label_19fc:
    // 0x19fc: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1a00: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1a04: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1a08: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a10: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A0Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A14u;
}


// Function: dbcman_00001a14
// Address: 0x1a14 - 0x1a48
void dbcman_00001a14_0x1a14(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001a14_0x1a14");
#endif

    switch (ctx->pc) {
        case 0x1a30u: goto label_1a30;
        default: break;
    }

    ctx->pc = 0x1a14u;

    // 0x1a14: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1a18: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1a1c: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1a20: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1a24: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a28: 0xc0001b1  jal         func_0006C4
    ctx->pc = 0x1A28u;
    SET_GPR_U32(ctx, 31, 0x1A30u);
    ctx->pc = 0x6C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x6C4u, 0x1A28u, 0x1A30u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A30u;
label_1a30:
    // 0x1a30: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1a34: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1a38: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1a3c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a40: 0x3e00008  jr          $ra
    ctx->pc = 0x1A40u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a44: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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


// Function: dbcman_00001a48
// Address: 0x1a48 - 0x1a7c
void dbcman_00001a48_0x1a48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001a48_0x1a48");
#endif

    switch (ctx->pc) {
        case 0x1a64u: goto label_1a64;
        default: break;
    }

    ctx->pc = 0x1a48u;

    // 0x1a48: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1a4c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1a50: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1a54: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1a58: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a5c: 0xc0001c6  jal         func_000718
    ctx->pc = 0x1A5Cu;
    SET_GPR_U32(ctx, 31, 0x1A64u);
    ctx->pc = 0x718u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x718u, 0x1A5Cu, 0x1A64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A64u;
label_1a64:
    // 0x1a64: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1a68: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1a6c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1a70: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a74: 0x3e00008  jr          $ra
    ctx->pc = 0x1A74u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a78: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A74u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1A7Cu;
}


// Function: dbcman_00001a7c
// Address: 0x1a7c - 0x1aac
void dbcman_00001a7c_0x1a7c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001a7c_0x1a7c");
#endif

    switch (ctx->pc) {
        case 0x1a94u: goto label_1a94;
        default: break;
    }

    ctx->pc = 0x1a7cu;

    // 0x1a7c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1a80: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1a84: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1a88: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1a8c: 0xc000189  jal         func_000624
    ctx->pc = 0x1A8Cu;
    SET_GPR_U32(ctx, 31, 0x1A94u);
    // 0x1a90: 0x26040008  addiu       $a0, $s0, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    ctx->pc = 0x624u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x624u, 0x1A8Cu, 0x1A94u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A94u;
label_1a94:
    // 0x1a94: 0xae020004  sw          $v0, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1a98: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1a9c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1aa0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1aa8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AA4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AACu;
}


// Function: dbcman_00001aac
// Address: 0x1aac - 0x1af8
void dbcman_00001aac_0x1aac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001aac_0x1aac");
#endif

    switch (ctx->pc) {
        case 0x1ae0u: goto label_1ae0;
        default: break;
    }

    ctx->pc = 0x1aacu;

    // 0x1aac: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ab0: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1ab4: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1ab8: 0x2602000c  addiu       $v0, $s0, 0xC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x1abc: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1ac0: 0x26020090  addiu       $v0, $s0, 0x90
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
    // 0x1ac4: 0x26060008  addiu       $a2, $s0, 0x8
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1ac8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1acc: 0xafa20014  sw          $v0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x1ad0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ad4: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1ad8: 0xc0001d0  jal         func_000740
    ctx->pc = 0x1AD8u;
    SET_GPR_U32(ctx, 31, 0x1AE0u);
    // 0x1adc: 0x26070010  addiu       $a3, $s0, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    ctx->pc = 0x740u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x740u, 0x1AD8u, 0x1AE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AE0u;
label_1ae0:
    // 0x1ae0: 0xae020110  sw          $v0, 0x110($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 272), GPR_U32(ctx, 2));
    // 0x1ae4: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1ae8: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1aec: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1af0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1af4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AF0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AF8u;
}


// Function: dbcman_00001af8
// Address: 0x1af8 - 0x1b34
void dbcman_00001af8_0x1af8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001af8_0x1af8");
#endif

    switch (ctx->pc) {
        case 0x1b1cu: goto label_1b1c;
        default: break;
    }

    ctx->pc = 0x1af8u;

    // 0x1af8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1afc: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1b00: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1b04: 0x26060008  addiu       $a2, $s0, 0x8
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1b08: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1b0c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b10: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b14: 0xc0001f4  jal         func_0007D0
    ctx->pc = 0x1B14u;
    SET_GPR_U32(ctx, 31, 0x1B1Cu);
    // 0x1b18: 0x2607000c  addiu       $a3, $s0, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    ctx->pc = 0x7D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7D0u, 0x1B14u, 0x1B1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B1Cu;
label_1b1c:
    // 0x1b1c: 0xae02008c  sw          $v0, 0x8C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 2));
    // 0x1b20: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1b24: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1b28: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b30: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B2Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1B34u;
}


// Function: dbcman_00001b34
// Address: 0x1b34 - 0x1b70
void dbcman_00001b34_0x1b34(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001b34_0x1b34");
#endif

    switch (ctx->pc) {
        case 0x1b58u: goto label_1b58;
        default: break;
    }

    ctx->pc = 0x1b34u;

    // 0x1b34: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1b38: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1b3c: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1b40: 0x26060008  addiu       $a2, $s0, 0x8
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1b44: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1b48: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b4c: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b50: 0xc000214  jal         func_000850
    ctx->pc = 0x1B50u;
    SET_GPR_U32(ctx, 31, 0x1B58u);
    // 0x1b54: 0x2607000c  addiu       $a3, $s0, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    ctx->pc = 0x850u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x850u, 0x1B50u, 0x1B58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B58u;
label_1b58:
    // 0x1b58: 0xae02008c  sw          $v0, 0x8C($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 2));
    // 0x1b5c: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1b60: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1b64: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b68: 0x3e00008  jr          $ra
    ctx->pc = 0x1B68u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b6c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1B68u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1B70u;
}


// Function: dbcman_00001b70
// Address: 0x1b70 - 0x1bcc
void dbcman_00001b70_0x1b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001b70_0x1b70");
#endif

    switch (ctx->pc) {
        case 0x1ba0u: goto label_1ba0;
        case 0x1bb8u: goto label_1bb8;
        default: break;
    }

    ctx->pc = 0x1b70u;

    // 0x1b70: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1b74: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1b78: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1b7c: 0xc02821  addu        $a1, $a2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1b80: 0x2ca20091  sltiu       $v0, $a1, 0x91
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)145) ? 1 : 0);
    // 0x1b84: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B84u;
    {
        const bool branch_taken_0x1b84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b88: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x1b84) {
            ctx->pc = 0x1BA8u;
            goto label_1ba8;
        }
    }
    ctx->pc = 0x1B8Cu;
    // 0x1b8c: 0x26060008  addiu       $a2, $s0, 0x8
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1b90: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b94: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b98: 0xc0001f4  jal         func_0007D0
    ctx->pc = 0x1B98u;
    SET_GPR_U32(ctx, 31, 0x1BA0u);
    // 0x1b9c: 0x2607000c  addiu       $a3, $s0, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    ctx->pc = 0x7D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7D0u, 0x1B98u, 0x1BA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BA0u;
label_1ba0:
    // 0x1ba0: 0x80006ee  j           func_001BB8
    ctx->pc = 0x1BA0u;
    // 0x1ba4: 0xae02008c  sw          $v0, 0x8C($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 2));
    ctx->pc = 0x1BB8u;
    goto label_1bb8;
    ctx->pc = 0x1BA8u;
label_1ba8:
    // 0x1ba8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1bac: 0x24842500  addiu       $a0, $a0, 0x2500
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9472));
    // 0x1bb0: 0xc000849  jal         func_002124
    ctx->pc = 0x1BB0u;
    SET_GPR_U32(ctx, 31, 0x1BB8u);
    // 0x1bb4: 0x24060090  addiu       $a2, $zero, 0x90 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 144));
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x1BB0u, 0x1BB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BB8u;
label_1bb8:
    // 0x1bb8: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1bbc: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1bc0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bc4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1bc8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1BC4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BCCu;
}


// Function: dbcman_00001bcc
// Address: 0x1bcc - 0x1c28
void dbcman_00001bcc_0x1bcc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001bcc_0x1bcc");
#endif

    switch (ctx->pc) {
        case 0x1bfcu: goto label_1bfc;
        case 0x1c14u: goto label_1c14;
        default: break;
    }

    ctx->pc = 0x1bccu;

    // 0x1bcc: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1bd0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1bd4: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1bd8: 0xc02821  addu        $a1, $a2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    // 0x1bdc: 0x2ca22091  sltiu       $v0, $a1, 0x2091
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)8337) ? 1 : 0);
    // 0x1be0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BE0u;
    {
        const bool branch_taken_0x1be0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1be4: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x1be0) {
            ctx->pc = 0x1C04u;
            goto label_1c04;
        }
    }
    ctx->pc = 0x1BE8u;
    // 0x1be8: 0x26060008  addiu       $a2, $s0, 0x8
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1bec: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bf0: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bf4: 0xc0001f4  jal         func_0007D0
    ctx->pc = 0x1BF4u;
    SET_GPR_U32(ctx, 31, 0x1BFCu);
    // 0x1bf8: 0x2607000c  addiu       $a3, $s0, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    ctx->pc = 0x7D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x7D0u, 0x1BF4u, 0x1BFCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BFCu;
label_1bfc:
    // 0x1bfc: 0x8000705  j           func_001C14
    ctx->pc = 0x1BFCu;
    // 0x1c00: 0xae02208c  sw          $v0, 0x208C($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8332), GPR_U32(ctx, 2));
    ctx->pc = 0x1C14u;
    goto label_1c14;
    ctx->pc = 0x1C04u;
label_1c04:
    // 0x1c04: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c08: 0x24842530  addiu       $a0, $a0, 0x2530
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9520));
    // 0x1c0c: 0xc000849  jal         func_002124
    ctx->pc = 0x1C0Cu;
    SET_GPR_U32(ctx, 31, 0x1C14u);
    // 0x1c10: 0x24062090  addiu       $a2, $zero, 0x2090 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8336));
    ctx->pc = 0x2124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2124u, 0x1C0Cu, 0x1C14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C14u;
label_1c14:
    // 0x1c14: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1c18: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1c1c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c20: 0x3e00008  jr          $ra
    ctx->pc = 0x1C20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c24: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C28u;
}


// Function: dbcman_00001c28
// Address: 0x1c28 - 0x1c5c
void dbcman_00001c28_0x1c28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001c28_0x1c28");
#endif

    switch (ctx->pc) {
        case 0x1c44u: goto label_1c44;
        default: break;
    }

    ctx->pc = 0x1c28u;

    // 0x1c28: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1c2c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1c30: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1c34: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1c38: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c3c: 0xc000234  jal         func_0008D0
    ctx->pc = 0x1C3Cu;
    SET_GPR_U32(ctx, 31, 0x1C44u);
    ctx->pc = 0x8D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8D0u, 0x1C3Cu, 0x1C44u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C44u;
label_1c44:
    // 0x1c44: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1c48: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1c4c: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1c50: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c54: 0x3e00008  jr          $ra
    ctx->pc = 0x1C54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c58: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C54u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C5Cu;
}


// Function: dbcman_00001c5c
// Address: 0x1c5c - 0x1c88
void dbcman_00001c5c_0x1c5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001c5c_0x1c5c");
#endif

    switch (ctx->pc) {
        case 0x1c70u: goto label_1c70;
        default: break;
    }

    ctx->pc = 0x1c5cu;

    // 0x1c5c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1c60: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1c64: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x1c68: 0xc00023e  jal         func_0008F8
    ctx->pc = 0x1C68u;
    SET_GPR_U32(ctx, 31, 0x1C70u);
    // 0x1c6c: 0xa08021  addu        $s0, $a1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    ctx->pc = 0x8F8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8F8u, 0x1C68u, 0x1C70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C70u;
label_1c70:
    // 0x1c70: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1c74: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1c78: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1c7c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c80: 0x3e00008  jr          $ra
    ctx->pc = 0x1C80u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c84: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C80u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C88u;
}


// Function: dbcman_00001c88
// Address: 0x1c88 - 0x1d94
void dbcman_00001c88_0x1c88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001c88_0x1c88");
#endif

    switch (ctx->pc) {
        case 0x1cd0u: goto label_1cd0;
        case 0x1ce0u: goto label_1ce0;
        case 0x1cf0u: goto label_1cf0;
        case 0x1d00u: goto label_1d00;
        case 0x1d10u: goto label_1d10;
        case 0x1d20u: goto label_1d20;
        case 0x1d30u: goto label_1d30;
        case 0x1d40u: goto label_1d40;
        case 0x1d50u: goto label_1d50;
        case 0x1d60u: goto label_1d60;
        case 0x1d70u: goto label_1d70;
        case 0x1d80u: goto label_1d80;
        default: break;
    }

    ctx->pc = 0x1c88u;

    // 0x1c88: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1c8c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x1c90: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1c94: 0x3c027fff  lui         $v0, 0x7FFF
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x1c98: 0x3442ecff  ori         $v0, $v0, 0xECFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60671);
    // 0x1c9c: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1ca0: 0x2c620063  sltiu       $v0, $v1, 0x63
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)99) ? 1 : 0);
    // 0x1ca4: 0x10400036  beqz        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x1CA4u;
    {
        const bool branch_taken_0x1ca4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ca8: 0xafbf0014  sw          $ra, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
        if (branch_taken_0x1ca4) {
            ctx->pc = 0x1D80u;
            goto label_1d80;
        }
    }
    ctx->pc = 0x1CACu;
    // 0x1cac: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1cb0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1cb4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1cb8: 0x8c222560  lw          $v0, 0x2560($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9568)));
    // 0x1cbc: 0x0  nop
    // NOP
    // 0x1cc0: 0x400008  jr          $v0
    ctx->pc = 0x1CC0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC8u: goto label_1cc8;
            case 0x1CD8u: goto label_1cd8;
            case 0x1CE8u: goto label_1ce8;
            case 0x1CF8u: goto label_1cf8;
            case 0x1D08u: goto label_1d08;
            case 0x1D18u: goto label_1d18;
            case 0x1D28u: goto label_1d28;
            case 0x1D38u: goto label_1d38;
            case 0x1D48u: goto label_1d48;
            case 0x1D58u: goto label_1d58;
            case 0x1D68u: goto label_1d68;
            case 0x1D78u: goto label_1d78;
            case 0x1D80u: goto label_1d80;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x1CC0u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x1CC8u;
label_1cc8:
    // 0x1cc8: 0xc00070a  jal         func_001C28
    ctx->pc = 0x1CC8u;
    SET_GPR_U32(ctx, 31, 0x1CD0u);
    // 0x1ccc: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1C28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C28u, 0x1CC8u, 0x1CD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CD0u;
label_1cd0:
    // 0x1cd0: 0x8000761  j           func_001D84
    ctx->pc = 0x1CD0u;
    // 0x1cd4: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1CD8u;
label_1cd8:
    // 0x1cd8: 0xc000650  jal         func_001940
    ctx->pc = 0x1CD8u;
    SET_GPR_U32(ctx, 31, 0x1CE0u);
    // 0x1cdc: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1940u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1940u, 0x1CD8u, 0x1CE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CE0u;
label_1ce0:
    // 0x1ce0: 0x8000761  j           func_001D84
    ctx->pc = 0x1CE0u;
    // 0x1ce4: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1CE8u;
label_1ce8:
    // 0x1ce8: 0xc00065e  jal         func_001978
    ctx->pc = 0x1CE8u;
    SET_GPR_U32(ctx, 31, 0x1CF0u);
    // 0x1cec: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1978u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1978u, 0x1CE8u, 0x1CF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CF0u;
label_1cf0:
    // 0x1cf0: 0x8000761  j           func_001D84
    ctx->pc = 0x1CF0u;
    // 0x1cf4: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1CF8u;
label_1cf8:
    // 0x1cf8: 0xc00066b  jal         func_0019AC
    ctx->pc = 0x1CF8u;
    SET_GPR_U32(ctx, 31, 0x1D00u);
    // 0x1cfc: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x19ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19ACu, 0x1CF8u, 0x1D00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D00u;
label_1d00:
    // 0x1d00: 0x8000761  j           func_001D84
    ctx->pc = 0x1D00u;
    // 0x1d04: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D08u;
label_1d08:
    // 0x1d08: 0xc000678  jal         func_0019E0
    ctx->pc = 0x1D08u;
    SET_GPR_U32(ctx, 31, 0x1D10u);
    // 0x1d0c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x19E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x19E0u, 0x1D08u, 0x1D10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D10u;
label_1d10:
    // 0x1d10: 0x8000761  j           func_001D84
    ctx->pc = 0x1D10u;
    // 0x1d14: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D18u;
label_1d18:
    // 0x1d18: 0xc000685  jal         func_001A14
    ctx->pc = 0x1D18u;
    SET_GPR_U32(ctx, 31, 0x1D20u);
    // 0x1d1c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A14u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A14u, 0x1D18u, 0x1D20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D20u;
label_1d20:
    // 0x1d20: 0x8000761  j           func_001D84
    ctx->pc = 0x1D20u;
    // 0x1d24: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D28u;
label_1d28:
    // 0x1d28: 0xc000692  jal         func_001A48
    ctx->pc = 0x1D28u;
    SET_GPR_U32(ctx, 31, 0x1D30u);
    // 0x1d2c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A48u, 0x1D28u, 0x1D30u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D30u;
label_1d30:
    // 0x1d30: 0x8000761  j           func_001D84
    ctx->pc = 0x1D30u;
    // 0x1d34: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D38u;
label_1d38:
    // 0x1d38: 0xc0006ab  jal         func_001AAC
    ctx->pc = 0x1D38u;
    SET_GPR_U32(ctx, 31, 0x1D40u);
    // 0x1d3c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1AACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AACu, 0x1D38u, 0x1D40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D40u;
label_1d40:
    // 0x1d40: 0x8000761  j           func_001D84
    ctx->pc = 0x1D40u;
    // 0x1d44: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D48u;
label_1d48:
    // 0x1d48: 0xc0006be  jal         func_001AF8
    ctx->pc = 0x1D48u;
    SET_GPR_U32(ctx, 31, 0x1D50u);
    // 0x1d4c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1AF8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AF8u, 0x1D48u, 0x1D50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D50u;
label_1d50:
    // 0x1d50: 0x8000761  j           func_001D84
    ctx->pc = 0x1D50u;
    // 0x1d54: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D58u;
label_1d58:
    // 0x1d58: 0xc0006cd  jal         func_001B34
    ctx->pc = 0x1D58u;
    SET_GPR_U32(ctx, 31, 0x1D60u);
    // 0x1d5c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1B34u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1B34u, 0x1D58u, 0x1D60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D60u;
label_1d60:
    // 0x1d60: 0x8000761  j           func_001D84
    ctx->pc = 0x1D60u;
    // 0x1d64: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D68u;
label_1d68:
    // 0x1d68: 0xc000717  jal         func_001C5C
    ctx->pc = 0x1D68u;
    SET_GPR_U32(ctx, 31, 0x1D70u);
    // 0x1d6c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1C5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C5Cu, 0x1D68u, 0x1D70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D70u;
label_1d70:
    // 0x1d70: 0x8000761  j           func_001D84
    ctx->pc = 0x1D70u;
    // 0x1d74: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D84u;
    goto label_1d84;
    ctx->pc = 0x1D78u;
label_1d78:
    // 0x1d78: 0xc00069f  jal         func_001A7C
    ctx->pc = 0x1D78u;
    SET_GPR_U32(ctx, 31, 0x1D80u);
    // 0x1d7c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1A7Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1A7Cu, 0x1D78u, 0x1D80u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D80u;
label_1d80:
    // 0x1d80: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_1d84:
    // 0x1d84: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1d88: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d90: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D8Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D94u;
}


// Function: dbcman_00001d94
// Address: 0x1d94 - 0x1e2c
void dbcman_00001d94_0x1d94(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001d94_0x1d94");
#endif

    switch (ctx->pc) {
        case 0x1da4u: goto label_1da4;
        case 0x1db8u: goto label_1db8;
        case 0x1dc0u: goto label_1dc0;
        case 0x1dc8u: goto label_1dc8;
        case 0x1dd0u: goto label_1dd0;
        case 0x1de4u: goto label_1de4;
        case 0x1e14u: goto label_1e14;
        case 0x1e1cu: goto label_1e1c;
        default: break;
    }

    ctx->pc = 0x1d94u;

    // 0x1d94: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1d98: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1d9c: 0xc00087b  jal         func_0021EC
    ctx->pc = 0x1D9Cu;
    SET_GPR_U32(ctx, 31, 0x1DA4u);
    // 0x1da0: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x21ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21ECu, 0x1D9Cu, 0x1DA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DA4u;
label_1da4:
    // 0x1da4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA4u;
    {
        const bool branch_taken_0x1da4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da4) {
            ctx->pc = 0x1DC0u;
            goto label_1dc0;
        }
    }
    ctx->pc = 0x1DACu;
    // 0x1dac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1db0: 0xc000886  jal         func_002218
    ctx->pc = 0x1DB0u;
    SET_GPR_U32(ctx, 31, 0x1DB8u);
    // 0x1db4: 0x248426ec  addiu       $a0, $a0, 0x26EC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9964));
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x1DB0u, 0x1DB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DB8u;
label_1db8:
    // 0x1db8: 0xc000875  jal         func_0021D4
    ctx->pc = 0x1DB8u;
    SET_GPR_U32(ctx, 31, 0x1DC0u);
    ctx->pc = 0x21D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21D4u, 0x1DB8u, 0x1DC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DC0u;
label_1dc0:
    // 0x1dc0: 0xc000866  jal         func_002198
    ctx->pc = 0x1DC0u;
    SET_GPR_U32(ctx, 31, 0x1DC8u);
    // 0x1dc4: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2198u, 0x1DC0u, 0x1DC8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DC8u;
label_1dc8:
    // 0x1dc8: 0xc000893  jal         func_00224C
    ctx->pc = 0x1DC8u;
    SET_GPR_U32(ctx, 31, 0x1DD0u);
    ctx->pc = 0x224Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x224Cu, 0x1DC8u, 0x1DD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DD0u;
label_1dd0:
    // 0x1dd0: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x1dd4: 0x26102d80  addiu       $s0, $s0, 0x2D80
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 11648));
    // 0x1dd8: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1ddc: 0xc00086a  jal         func_0021A8
    ctx->pc = 0x1DDCu;
    SET_GPR_U32(ctx, 31, 0x1DE4u);
    // 0x1de0: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x21A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A8u, 0x1DDCu, 0x1DE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DE4u;
label_1de4:
    // 0x1de4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1de8: 0x24842de0  addiu       $a0, $a0, 0x2DE0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11744));
    // 0x1dec: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1df0: 0x34a51300  ori         $a1, $a1, 0x1300
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4864);
    // 0x1df4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1df8: 0x24c61c88  addiu       $a2, $a2, 0x1C88
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 7304));
    // 0x1dfc: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x1e00: 0x24e72f08  addiu       $a3, $a3, 0x2F08
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 12040));
    // 0x1e04: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1e08: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x1e0c: 0xc000868  jal         func_0021A0
    ctx->pc = 0x1E0Cu;
    SET_GPR_U32(ctx, 31, 0x1E14u);
    // 0x1e10: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x21A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A0u, 0x1E0Cu, 0x1E14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E14u;
label_1e14:
    // 0x1e14: 0xc00086c  jal         func_0021B0
    ctx->pc = 0x1E14u;
    SET_GPR_U32(ctx, 31, 0x1E1Cu);
    // 0x1e18: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x21B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21B0u, 0x1E14u, 0x1E1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E1Cu;
label_1e1c:
    // 0x1e1c: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1e20: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e24: 0x3e00008  jr          $ra
    ctx->pc = 0x1E24u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e28: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E24u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E2Cu;
}


// Function: dbcman_00001e2c
// Address: 0x1e2c - 0x1ec4
void dbcman_00001e2c_0x1e2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001e2c_0x1e2c");
#endif

    switch (ctx->pc) {
        case 0x1e3cu: goto label_1e3c;
        case 0x1e50u: goto label_1e50;
        case 0x1e58u: goto label_1e58;
        case 0x1e60u: goto label_1e60;
        case 0x1e68u: goto label_1e68;
        case 0x1e7cu: goto label_1e7c;
        case 0x1eacu: goto label_1eac;
        case 0x1eb4u: goto label_1eb4;
        default: break;
    }

    ctx->pc = 0x1e2cu;

    // 0x1e2c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1e30: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1e34: 0xc00087b  jal         func_0021EC
    ctx->pc = 0x1E34u;
    SET_GPR_U32(ctx, 31, 0x1E3Cu);
    // 0x1e38: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x21ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21ECu, 0x1E34u, 0x1E3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E3Cu;
label_1e3c:
    // 0x1e3c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E3Cu;
    {
        const bool branch_taken_0x1e3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e3c) {
            ctx->pc = 0x1E58u;
            goto label_1e58;
        }
    }
    ctx->pc = 0x1E44u;
    // 0x1e44: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1e48: 0xc000886  jal         func_002218
    ctx->pc = 0x1E48u;
    SET_GPR_U32(ctx, 31, 0x1E50u);
    // 0x1e4c: 0x248426ec  addiu       $a0, $a0, 0x26EC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9964));
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x1E48u, 0x1E50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E50u;
label_1e50:
    // 0x1e50: 0xc000875  jal         func_0021D4
    ctx->pc = 0x1E50u;
    SET_GPR_U32(ctx, 31, 0x1E58u);
    ctx->pc = 0x21D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21D4u, 0x1E50u, 0x1E58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E58u;
label_1e58:
    // 0x1e58: 0xc000866  jal         func_002198
    ctx->pc = 0x1E58u;
    SET_GPR_U32(ctx, 31, 0x1E60u);
    // 0x1e5c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2198u, 0x1E58u, 0x1E60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E60u;
label_1e60:
    // 0x1e60: 0xc000893  jal         func_00224C
    ctx->pc = 0x1E60u;
    SET_GPR_U32(ctx, 31, 0x1E68u);
    ctx->pc = 0x224Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x224Cu, 0x1E60u, 0x1E68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E68u;
label_1e68:
    // 0x1e68: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x1e6c: 0x26102d98  addiu       $s0, $s0, 0x2D98
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 11672));
    // 0x1e70: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1e74: 0xc00086a  jal         func_0021A8
    ctx->pc = 0x1E74u;
    SET_GPR_U32(ctx, 31, 0x1E7Cu);
    // 0x1e78: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x21A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A8u, 0x1E74u, 0x1E7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E7Cu;
label_1e7c:
    // 0x1e7c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1e80: 0x24842e28  addiu       $a0, $a0, 0x2E28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11816));
    // 0x1e84: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1e88: 0x34a5131c  ori         $a1, $a1, 0x131C
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4892);
    // 0x1e8c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1e90: 0x24c61bcc  addiu       $a2, $a2, 0x1BCC
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 7116));
    // 0x1e94: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x1e98: 0x24e72f98  addiu       $a3, $a3, 0x2F98
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 12184));
    // 0x1e9c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1ea0: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x1ea4: 0xc000868  jal         func_0021A0
    ctx->pc = 0x1EA4u;
    SET_GPR_U32(ctx, 31, 0x1EACu);
    // 0x1ea8: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x21A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A0u, 0x1EA4u, 0x1EACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EACu;
label_1eac:
    // 0x1eac: 0xc00086c  jal         func_0021B0
    ctx->pc = 0x1EACu;
    SET_GPR_U32(ctx, 31, 0x1EB4u);
    // 0x1eb0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x21B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21B0u, 0x1EACu, 0x1EB4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EB4u;
label_1eb4:
    // 0x1eb4: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1eb8: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ebc: 0x3e00008  jr          $ra
    ctx->pc = 0x1EBCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ec0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1EBCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1EC4u;
}


// Function: dbcman_00001ec4
// Address: 0x1ec4 - 0x1f98
void dbcman_00001ec4_0x1ec4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001ec4_0x1ec4");
#endif

    switch (ctx->pc) {
        case 0x1edcu: goto label_1edc;
        case 0x1ef0u: goto label_1ef0;
        case 0x1ef8u: goto label_1ef8;
        case 0x1f00u: goto label_1f00;
        case 0x1f08u: goto label_1f08;
        case 0x1f28u: goto label_1f28;
        case 0x1f7cu: goto label_1f7c;
        case 0x1f84u: goto label_1f84;
        default: break;
    }

    ctx->pc = 0x1ec4u;

    // 0x1ec4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ec8: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
    // 0x1ecc: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1ed0: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x1ed4: 0xc00087b  jal         func_0021EC
    ctx->pc = 0x1ED4u;
    SET_GPR_U32(ctx, 31, 0x1EDCu);
    // 0x1ed8: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x21ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21ECu, 0x1ED4u, 0x1EDCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EDCu;
label_1edc:
    // 0x1edc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1EDCu;
    {
        const bool branch_taken_0x1edc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1edc) {
            ctx->pc = 0x1EF8u;
            goto label_1ef8;
        }
    }
    ctx->pc = 0x1EE4u;
    // 0x1ee4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1ee8: 0xc000886  jal         func_002218
    ctx->pc = 0x1EE8u;
    SET_GPR_U32(ctx, 31, 0x1EF0u);
    // 0x1eec: 0x248426ec  addiu       $a0, $a0, 0x26EC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9964));
    ctx->pc = 0x2218u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2218u, 0x1EE8u, 0x1EF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EF0u;
label_1ef0:
    // 0x1ef0: 0xc000875  jal         func_0021D4
    ctx->pc = 0x1EF0u;
    SET_GPR_U32(ctx, 31, 0x1EF8u);
    ctx->pc = 0x21D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21D4u, 0x1EF0u, 0x1EF8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EF8u;
label_1ef8:
    // 0x1ef8: 0xc000866  jal         func_002198
    ctx->pc = 0x1EF8u;
    SET_GPR_U32(ctx, 31, 0x1F00u);
    // 0x1efc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2198u, 0x1EF8u, 0x1F00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F00u;
label_1f00:
    // 0x1f00: 0xc000893  jal         func_00224C
    ctx->pc = 0x1F00u;
    SET_GPR_U32(ctx, 31, 0x1F08u);
    // 0x1f04: 0x118040  sll         $s0, $s1, 1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    ctx->pc = 0x224Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x224Cu, 0x1F00u, 0x1F08u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F08u;
label_1f08:
    // 0x1f08: 0x2118021  addu        $s0, $s0, $s1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1f0c: 0x1080c0  sll         $s0, $s0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1f10: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x1f14: 0x24632db0  addiu       $v1, $v1, 0x2DB0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11696));
    // 0x1f18: 0x2038021  addu        $s0, $s0, $v1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1f1c: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x1f20: 0xc00086a  jal         func_0021A8
    ctx->pc = 0x1F20u;
    SET_GPR_U32(ctx, 31, 0x1F28u);
    // 0x1f24: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x21A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A8u, 0x1F20u, 0x1F28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F28u;
label_1f28:
    // 0x1f28: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1f2c: 0x34a5131e  ori         $a1, $a1, 0x131E
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4894);
    // 0x1f30: 0x112100  sll         $a0, $s1, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x1f34: 0x912021  addu        $a0, $a0, $s1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1f38: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1f3c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1f40: 0x24422e70  addiu       $v0, $v0, 0x2E70
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 11888));
    // 0x1f44: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f48: 0x2252821  addu        $a1, $s1, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x1f4c: 0x1138c0  sll         $a3, $s1, 3
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1f50: 0xf13821  addu        $a3, $a3, $s1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 17)));
    // 0x1f54: 0x73900  sll         $a3, $a3, 4
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1f58: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x1f5c: 0x24425028  addiu       $v0, $v0, 0x5028
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20520));
    // 0x1f60: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x1f64: 0x24c61b70  addiu       $a2, $a2, 0x1B70
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 7024));
    // 0x1f68: 0xe23821  addu        $a3, $a3, $v0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1f6c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1f70: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x1f74: 0xc000868  jal         func_0021A0
    ctx->pc = 0x1F74u;
    SET_GPR_U32(ctx, 31, 0x1F7Cu);
    // 0x1f78: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x21A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21A0u, 0x1F74u, 0x1F7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F7Cu;
label_1f7c:
    // 0x1f7c: 0xc00086c  jal         func_0021B0
    ctx->pc = 0x1F7Cu;
    SET_GPR_U32(ctx, 31, 0x1F84u);
    // 0x1f80: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x21B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x21B0u, 0x1F7Cu, 0x1F84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1F84u;
label_1f84:
    // 0x1f84: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f88: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1f8c: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f90: 0x3e00008  jr          $ra
    ctx->pc = 0x1F90u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1f94: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1F90u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1F98u;
}


// Function: dbcman_00001f98
// Address: 0x1f98 - 0x2124
void dbcman_00001f98_0x1f98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00001f98_0x1f98");
#endif

    switch (ctx->pc) {
        case 0x1f98u: goto label_1f98;
        case 0x1f9cu: goto label_1f9c;
        case 0x1fa0u: goto label_1fa0;
        case 0x1fa4u: goto label_1fa4;
        case 0x1fa8u: goto label_1fa8;
        case 0x1facu: goto label_1fac;
        case 0x1fb0u: goto label_1fb0;
        case 0x1fb4u: goto label_1fb4;
        case 0x1fb8u: goto label_1fb8;
        case 0x1fbcu: goto label_1fbc;
        case 0x1fc0u: goto label_1fc0;
        case 0x1fc4u: goto label_1fc4;
        case 0x1fc8u: goto label_1fc8;
        case 0x1fccu: goto label_1fcc;
        case 0x1fd0u: goto label_1fd0;
        case 0x1fd4u: goto label_1fd4;
        case 0x1fd8u: goto label_1fd8;
        case 0x1fdcu: goto label_1fdc;
        case 0x1fe0u: goto label_1fe0;
        case 0x1fe4u: goto label_1fe4;
        case 0x1fe8u: goto label_1fe8;
        case 0x1fecu: goto label_1fec;
        case 0x1ff0u: goto label_1ff0;
        case 0x1ff4u: goto label_1ff4;
        case 0x1ff8u: goto label_1ff8;
        case 0x1ffcu: goto label_1ffc;
        case 0x2000u: goto label_2000;
        case 0x2004u: goto label_2004;
        case 0x2008u: goto label_2008;
        case 0x200cu: goto label_200c;
        case 0x2010u: goto label_2010;
        case 0x2014u: goto label_2014;
        case 0x2018u: goto label_2018;
        case 0x201cu: goto label_201c;
        case 0x2020u: goto label_2020;
        case 0x2024u: goto label_2024;
        case 0x2028u: goto label_2028;
        case 0x202cu: goto label_202c;
        case 0x2030u: goto label_2030;
        case 0x2034u: goto label_2034;
        case 0x2038u: goto label_2038;
        case 0x203cu: goto label_203c;
        case 0x2040u: goto label_2040;
        case 0x2044u: goto label_2044;
        case 0x2048u: goto label_2048;
        case 0x204cu: goto label_204c;
        case 0x2050u: goto label_2050;
        case 0x2054u: goto label_2054;
        case 0x2058u: goto label_2058;
        case 0x205cu: goto label_205c;
        case 0x2060u: goto label_2060;
        case 0x2064u: goto label_2064;
        case 0x2068u: goto label_2068;
        case 0x206cu: goto label_206c;
        case 0x2070u: goto label_2070;
        case 0x2074u: goto label_2074;
        case 0x2078u: goto label_2078;
        case 0x207cu: goto label_207c;
        case 0x2080u: goto label_2080;
        case 0x2084u: goto label_2084;
        case 0x2088u: goto label_2088;
        case 0x208cu: goto label_208c;
        case 0x2090u: goto label_2090;
        case 0x2094u: goto label_2094;
        case 0x2098u: goto label_2098;
        case 0x209cu: goto label_209c;
        case 0x20a0u: goto label_20a0;
        case 0x20a4u: goto label_20a4;
        case 0x20a8u: goto label_20a8;
        case 0x20acu: goto label_20ac;
        case 0x20b0u: goto label_20b0;
        case 0x20b4u: goto label_20b4;
        case 0x20b8u: goto label_20b8;
        case 0x20bcu: goto label_20bc;
        case 0x20c0u: goto label_20c0;
        case 0x20c4u: goto label_20c4;
        case 0x20c8u: goto label_20c8;
        case 0x20ccu: goto label_20cc;
        case 0x20d0u: goto label_20d0;
        case 0x20d4u: goto label_20d4;
        case 0x20d8u: goto label_20d8;
        case 0x20dcu: goto label_20dc;
        case 0x20e0u: goto label_20e0;
        case 0x20e4u: goto label_20e4;
        case 0x20e8u: goto label_20e8;
        case 0x20ecu: goto label_20ec;
        case 0x20f0u: goto label_20f0;
        case 0x20f4u: goto label_20f4;
        case 0x20f8u: goto label_20f8;
        case 0x20fcu: goto label_20fc;
        case 0x2100u: goto label_2100;
        case 0x2104u: goto label_2104;
        case 0x2108u: goto label_2108;
        case 0x210cu: goto label_210c;
        case 0x2110u: goto label_2110;
        case 0x2114u: goto label_2114;
        case 0x2118u: goto label_2118;
        case 0x211cu: goto label_211c;
        case 0x2120u: goto label_2120;
        default: break;
    }

    ctx->pc = 0x1f98u;

label_1f98:
    // 0x1f98: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_1f9c:
    // 0x1f9c: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_1fa0:
    // 0x1fa0: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
label_1fa4:
    // 0x1fa4: 0x3c120200  lui         $s2, 0x200
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)512 << 16));
label_1fa8:
    // 0x1fa8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1fac:
    // 0x1fac: 0x24421d94  addiu       $v0, $v0, 0x1D94
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7572));
label_1fb0:
    // 0x1fb0: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
label_1fb4:
    // 0x1fb4: 0x24110014  addiu       $s1, $zero, 0x14
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
label_1fb8:
    // 0x1fb8: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
label_1fbc:
    // 0x1fbc: 0x24100800  addiu       $s0, $zero, 0x800
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
label_1fc0:
    // 0x1fc0: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
label_1fc4:
    // 0x1fc4: 0xafb40038  sw          $s4, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 20));
label_1fc8:
    // 0x1fc8: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
label_1fcc:
    // 0x1fcc: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
label_1fd0:
    // 0x1fd0: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_1fd4:
    // 0x1fd4: 0xafb10020  sw          $s1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 17));
label_1fd8:
    // 0x1fd8: 0xc00088f  jal         func_00223C
label_1fdc:
    if (ctx->pc == 0x1FDCu) {
        // 0x1fdc: 0xafb0001c  sw          $s0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 16));
        ctx->pc = 0x1FE0u;
        goto label_1fe0;
    }
    ctx->pc = 0x1FD8u;
    SET_GPR_U32(ctx, 31, 0x1FE0u);
    // 0x1fdc: 0xafb0001c  sw          $s0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 16));
    ctx->pc = 0x223Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x223Cu, 0x1FD8u, 0x1FE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FE0u;
label_1fe0:
    // 0x1fe0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1fe4:
    // 0x1fe4: 0xac222ef8  sw          $v0, 0x2EF8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12024), GPR_U32(ctx, 2));
label_1fe8:
    // 0x1fe8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
label_1fec:
    if (ctx->pc == 0x1FECu) {
        // 0x1fec: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x1FF0u;
        goto label_1ff0;
    }
    ctx->pc = 0x1FE8u;
    {
        const bool branch_taken_0x1fe8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1fec: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x1fe8) {
            ctx->pc = 0x2028u;
            goto label_2028;
        }
    }
    ctx->pc = 0x1FF0u;
label_1ff0:
    // 0x1ff0: 0xc000891  jal         func_002244
label_1ff4:
    if (ctx->pc == 0x1FF4u) {
        // 0x1ff4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1FF8u;
        goto label_1ff8;
    }
    ctx->pc = 0x1FF0u;
    SET_GPR_U32(ctx, 31, 0x1FF8u);
    // 0x1ff4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2244u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2244u, 0x1FF0u, 0x1FF8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FF8u;
label_1ff8:
    // 0x1ff8: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_1ffc:
    // 0x1ffc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2000:
    // 0x2000: 0x24421e2c  addiu       $v0, $v0, 0x1E2C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7724));
label_2004:
    // 0x2004: 0xafb20010  sw          $s2, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 18));
label_2008:
    // 0x2008: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_200c:
    // 0x200c: 0xafb10020  sw          $s1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 17));
label_2010:
    // 0x2010: 0xc00088f  jal         func_00223C
label_2014:
    if (ctx->pc == 0x2014u) {
        // 0x2014: 0xafb0001c  sw          $s0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 16));
        ctx->pc = 0x2018u;
        goto label_2018;
    }
    ctx->pc = 0x2010u;
    SET_GPR_U32(ctx, 31, 0x2018u);
    // 0x2014: 0xafb0001c  sw          $s0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 16));
    ctx->pc = 0x223Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x223Cu, 0x2010u, 0x2018u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2018u;
label_2018:
    // 0x2018: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_201c:
    // 0x201c: 0xac222efc  sw          $v0, 0x2EFC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12028), GPR_U32(ctx, 2));
label_2020:
    // 0x2020: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_2024:
    if (ctx->pc == 0x2024u) {
        // 0x2024: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x2028u;
        goto label_2028;
    }
    ctx->pc = 0x2020u;
    {
        const bool branch_taken_0x2020 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2024: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x2020) {
            ctx->pc = 0x2030u;
            goto label_2030;
        }
    }
    ctx->pc = 0x2028u;
label_2028:
    // 0x2028: 0x8000828  j           func_0020A0
label_202c:
    if (ctx->pc == 0x202Cu) {
        // 0x202c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2030u;
        goto label_2030;
    }
    ctx->pc = 0x2028u;
    // 0x202c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x20A0u;
    goto label_20a0;
    ctx->pc = 0x2030u;
label_2030:
    // 0x2030: 0xc000891  jal         func_002244
label_2034:
    if (ctx->pc == 0x2034u) {
        // 0x2034: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2038u;
        goto label_2038;
    }
    ctx->pc = 0x2030u;
    SET_GPR_U32(ctx, 31, 0x2038u);
    // 0x2034: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2244u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2244u, 0x2030u, 0x2038u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2038u;
label_2038:
    // 0x2038: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_203c:
    // 0x203c: 0x3c140200  lui         $s4, 0x200
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)512 << 16));
label_2040:
    // 0x2040: 0x3c130000  lui         $s3, 0x0
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)0 << 16));
label_2044:
    // 0x2044: 0x26731ec4  addiu       $s3, $s3, 0x1EC4
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 7876));
label_2048:
    // 0x2048: 0x24120014  addiu       $s2, $zero, 0x14
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
label_204c:
    // 0x204c: 0x24110400  addiu       $s1, $zero, 0x400
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_2050:
    // 0x2050: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_2054:
    // 0x2054: 0xafb40010  sw          $s4, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
label_2058:
    // 0x2058: 0xafb30018  sw          $s3, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 19));
label_205c:
    // 0x205c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_2060:
    // 0x2060: 0xc00088f  jal         func_00223C
label_2064:
    if (ctx->pc == 0x2064u) {
        // 0x2064: 0xafb1001c  sw          $s1, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
        ctx->pc = 0x2068u;
        goto label_2068;
    }
    ctx->pc = 0x2060u;
    SET_GPR_U32(ctx, 31, 0x2068u);
    // 0x2064: 0xafb1001c  sw          $s1, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    ctx->pc = 0x223Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x223Cu, 0x2060u, 0x2068u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2068u;
label_2068:
    // 0x2068: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_206c:
    // 0x206c: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_2070:
    // 0x2070: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2074:
    // 0x2074: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_2078:
    // 0x2078: 0xac242f00  sw          $a0, 0x2F00($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12032), GPR_U32(ctx, 4));
label_207c:
    // 0x207c: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
label_2080:
    if (ctx->pc == 0x2080u) {
        // 0x2080: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2084u;
        goto label_2084;
    }
    ctx->pc = 0x207Cu;
    {
        const bool branch_taken_0x207c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x2080: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x207c) {
            ctx->pc = 0x20A0u;
            goto label_20a0;
        }
    }
    ctx->pc = 0x2084u;
label_2084:
    // 0x2084: 0xc000891  jal         func_002244
label_2088:
    if (ctx->pc == 0x2088u) {
        // 0x2088: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x208Cu;
        goto label_208c;
    }
    ctx->pc = 0x2084u;
    SET_GPR_U32(ctx, 31, 0x208Cu);
    // 0x2088: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x2244u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2244u, 0x2084u, 0x208Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x208Cu;
label_208c:
    // 0x208c: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_2090:
    // 0x2090: 0x2a020002  slti        $v0, $s0, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
label_2094:
    // 0x2094: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
label_2098:
    if (ctx->pc == 0x2098u) {
        // 0x2098: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x209Cu;
        goto label_209c;
    }
    ctx->pc = 0x2094u;
    {
        const bool branch_taken_0x2094 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2098: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        if (branch_taken_0x2094) {
            ctx->pc = 0x2054u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2054;
        }
    }
    ctx->pc = 0x209Cu;
label_209c:
    // 0x209c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_20a0:
    // 0x20a0: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_20a4:
    // 0x20a4: 0x8fb40038  lw          $s4, 0x38($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_20a8:
    // 0x20a8: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_20ac:
    // 0x20ac: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_20b0:
    // 0x20b0: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_20b4:
    // 0x20b4: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_20b8:
    // 0x20b8: 0x3e00008  jr          $ra
label_20bc:
    if (ctx->pc == 0x20BCu) {
        // 0x20bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x20C0u;
        goto label_20c0;
    }
    ctx->pc = 0x20B8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x20bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x20B8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x20C0u;
label_20c0:
    // 0x20c0: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x20C0 raw=0x41C00000");
label_20c4:
    // 0x20c4: 0x0  nop
    // NOP
label_20c8:
    // 0x20c8: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
label_20cc:
    // 0x20cc: 0x6d636264  ldr         $v1, 0x6264($t3)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x20CC raw=0x6D636264");
label_20d0:
    // 0x20d0: 0x6e61  .word       0x00006E61                   # addu        $t5, $zero, $zero # 00000640 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_20d4:
    // 0x20d4: 0x0  nop
    // NOP
label_20d8:
    // 0x20d8: 0x2100  sll         $a0, $zero, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 0), 4));
label_20dc:
    // 0x20dc: 0x9c  .word       0x0000009C                   # dmult       $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0x20DC raw=0x0000009C");
label_20e0:
    // 0x20e0: 0x2100  sll         $a0, $zero, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 0), 4));
label_20e4:
    // 0x20e4: 0x158  .word       0x00000158                   # mult        $zero, $zero, $zero # 00000140 <InstrIdType: R5900_SPECIAL>
    { int64_t result = (int64_t)GPR_S32(ctx, 0) * (int64_t)GPR_S32(ctx, 0); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_20e8:
    // 0x20e8: 0x188  .word       0x00000188                   # jr          $zero # 00000180 <InstrIdType: CPU_SPECIAL>
label_20ec:
    if (ctx->pc == 0x20ECu) {
        // 0x20ec: 0x1bc  dsll32      $zero, $zero, 6 (Delay Slot)
        SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (32 + 6));
        ctx->pc = 0x20F0u;
        goto label_20f0;
    }
    ctx->pc = 0x20E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        // 0x20ec: 0x1bc  dsll32      $zero, $zero, 6 (Delay Slot)
        SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (32 + 6));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x20E8u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x20F0u;
label_20f0:
    // 0x20f0: 0x280  sll         $zero, $zero, 10
    
label_20f4:
    // 0x20f4: 0x31c  .word       0x0000031C                   # dmult       $zero, $zero # 00000300 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0x20F4 raw=0x0000031C");
label_20f8:
    // 0x20f8: 0x428  .word       0x00000428                   # mfsa        $zero # 00000400 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 0, ctx->sa);
label_20fc:
    // 0x20fc: 0x0  nop
    // NOP
label_2100:
    // 0x2100: 0x3e00008  jr          $ra
label_2104:
    if (ctx->pc == 0x2104u) {
        ctx->pc = 0x2108u;
        goto label_2108;
    }
    ctx->pc = 0x2100u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2100u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2108u;
label_2108:
    // 0x2108: 0x0  nop
    // NOP
label_210c:
    // 0x210c: 0x0  nop
    // NOP
label_2110:
    // 0x2110: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x2110 raw=0x41E00000");
label_2114:
    // 0x2114: 0x0  nop
    // NOP
label_2118:
    // 0x2118: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
label_211c:
    // 0x211c: 0x6d737973  ldr         $s3, 0x7973($t3)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x211C raw=0x6D737973");
label_2120:
    // 0x2120: 0x6d65  .word       0x00006D65                   # move        $t5, $zero # 00000540 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 0) | GPR_U64(ctx, 0));
}


// Function: dbcman_00002124
// Address: 0x2124 - 0x2148
void dbcman_00002124_0x2124(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002124_0x2124");
#endif

    runtime->iopImport(rdram, ctx, "sysmem", 14u);
}


// Function: dbcman_00002148
// Address: 0x2148 - 0x2150
void dbcman_00002148_0x2148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002148_0x2148");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: dbcman_00002150
// Address: 0x2150 - 0x2174
void dbcman_00002150_0x2150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002150_0x2150");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: dbcman_00002174
// Address: 0x2174 - 0x2198
void dbcman_00002174_0x2174(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002174_0x2174");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: dbcman_00002198
// Address: 0x2198 - 0x21a0
void dbcman_00002198_0x2198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002198_0x2198");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 14u);
}


// Function: dbcman_000021a0
// Address: 0x21a0 - 0x21a8
void dbcman_000021a0_0x21a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021a0_0x21a0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 17u);
}


// Function: dbcman_000021a8
// Address: 0x21a8 - 0x21b0
void dbcman_000021a8_0x21a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021a8_0x21a8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 19u);
}


// Function: dbcman_000021b0
// Address: 0x21b0 - 0x21d4
void dbcman_000021b0_0x21b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021b0_0x21b0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 22u);
}


// Function: dbcman_000021d4
// Address: 0x21d4 - 0x21dc
void dbcman_000021d4_0x21d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021d4_0x21d4");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 5u);
}


// Function: dbcman_000021dc
// Address: 0x21dc - 0x21e4
void dbcman_000021dc_0x21dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021dc_0x21dc");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 7u);
}


// Function: dbcman_000021e4
// Address: 0x21e4 - 0x21ec
void dbcman_000021e4_0x21e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021e4_0x21e4");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 8u);
}


// Function: dbcman_000021ec
// Address: 0x21ec - 0x21f4
void dbcman_000021ec_0x21ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021ec_0x21ec");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 29u);
}


// Function: dbcman_000021f4
// Address: 0x21f4 - 0x2218
void dbcman_000021f4_0x21f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_000021f4_0x21f4");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 32u);
}


// Function: dbcman_00002218
// Address: 0x2218 - 0x223c
void dbcman_00002218_0x2218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002218_0x2218");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: dbcman_0000223c
// Address: 0x223c - 0x2244
void dbcman_0000223c_0x223c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_0000223c_0x223c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: dbcman_00002244
// Address: 0x2244 - 0x224c
void dbcman_00002244_0x2244(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002244_0x2244");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: dbcman_0000224c
// Address: 0x224c - 0x2254
void dbcman_0000224c_0x224c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_0000224c_0x224c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 20u);
}


// Function: dbcman_00002254
// Address: 0x2254 - 0x2278
void dbcman_00002254_0x2254(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002254_0x2254");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 33u);
}


// Function: dbcman_00002278
// Address: 0x2278 - 0x2280
void dbcman_00002278_0x2278(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002278_0x2278");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 4u);
}


// Function: dbcman_00002280
// Address: 0x2280 - 0x2288
void dbcman_00002280_0x2280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002280_0x2280");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 6u);
}


// Function: dbcman_00002288
// Address: 0x2288 - 0x2290
void dbcman_00002288_0x2288(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("dbcman_00002288_0x2288");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 7u);
}


