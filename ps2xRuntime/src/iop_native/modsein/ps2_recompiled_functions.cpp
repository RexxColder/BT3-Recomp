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

// Function: modsein_00000000
// Address: 0x0 - 0x70
void modsein_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000000_0x0");
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
    // 0x4: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x8: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0xc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x10: 0x27c20014  addiu       $v0, $fp, 0x14
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x14: 0xc00077d  jal         func_001DF4
    ctx->pc = 0x14u;
    SET_GPR_U32(ctx, 31, 0x1Cu);
    // 0x18: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1DF4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1DF4u, 0x14u, 0x1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1Cu;
label_1c:
    // 0x1c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x20: 0x24841d70  addiu       $a0, $a0, 0x1D70
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7536));
    // 0x24: 0xc000788  jal         func_001E20
    ctx->pc = 0x24u;
    SET_GPR_U32(ctx, 31, 0x2Cu);
    ctx->pc = 0x1E20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1E20u, 0x24u, 0x2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2Cu;
label_2c:
    // 0x2c: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x30: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x34: 0xc00077f  jal         func_001DFC
    ctx->pc = 0x34u;
    SET_GPR_U32(ctx, 31, 0x3Cu);
    ctx->pc = 0x1DFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1DFCu, 0x34u, 0x3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3Cu;
label_3c:
    // 0x3c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x40: 0x0  nop
    // NOP
    // 0x44: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x44u;
    {
        const bool branch_taken_0x44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x44) {
            ctx->pc = 0x54u;
            goto label_54;
        }
    }
    ctx->pc = 0x4Cu;
    // 0x4c: 0x8000017  j           func_00005C
    ctx->pc = 0x4Cu;
    // 0x50: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x5Cu;
    goto label_5c;
    ctx->pc = 0x54u;
label_54:
    // 0x54: 0x8000017  j           func_00005C
    ctx->pc = 0x54u;
    // 0x58: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x5Cu;
    goto label_5c;
    ctx->pc = 0x5Cu;
label_5c:
    // 0x5c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x60: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x64: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x68: 0x3e00008  jr          $ra
    ctx->pc = 0x68u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
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


// Function: modsein_00000070
// Address: 0x70 - 0x200
void modsein_00000070_0x70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000070_0x70");
#endif

    switch (ctx->pc) {
        case 0x144u: goto label_144;
        default: break;
    }

    ctx->pc = 0x70u;

    // 0x70: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x74: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x78: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x7c: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x80: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x84: 0x0  nop
    // NOP
    // 0x88: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x88u;
    {
        const bool branch_taken_0x88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x88) {
            ctx->pc = 0x98u;
            goto label_98;
        }
    }
    ctx->pc = 0x90u;
    // 0x90: 0x800007c  j           func_0001F0
    ctx->pc = 0x90u;
    // 0x94: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1F0u;
    goto label_1f0;
    ctx->pc = 0x98u;
label_98:
    // 0x98: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x9c: 0x0  nop
    // NOP
    // 0xa0: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0xa4: 0x0  nop
    // NOP
    // 0xa8: 0xafc30000  sw          $v1, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    // 0xac: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0xb0: 0x0  nop
    // NOP
    // 0xb4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xb8: 0x0  nop
    // NOP
    // 0xbc: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0xc0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0xC0u;
    {
        const bool branch_taken_0xc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xc0) {
            ctx->pc = 0xE0u;
            goto label_e0;
        }
    }
    ctx->pc = 0xC8u;
    // 0xc8: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0xcc: 0x0  nop
    // NOP
    // 0xd0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xD0u;
    {
        const bool branch_taken_0xd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xd0) {
            ctx->pc = 0xE8u;
            goto label_e8;
        }
    }
    ctx->pc = 0xD8u;
    // 0xd8: 0x8000038  j           func_0000E0
    ctx->pc = 0xD8u;
    ctx->pc = 0xE0u;
    goto label_e0;
    ctx->pc = 0xE0u;
label_e0:
    // 0xe0: 0x800007c  j           func_0001F0
    ctx->pc = 0xE0u;
    // 0xe4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1F0u;
    goto label_1f0;
    ctx->pc = 0xE8u;
label_e8:
    // 0xe8: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0xec: 0x0  nop
    // NOP
    // 0xf0: 0x24620008  addiu       $v0, $v1, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0xf4: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0xf8: 0x0  nop
    // NOP
    // 0xfc: 0xafc30004  sw          $v1, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 3));
    // 0x100: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x104: 0x0  nop
    // NOP
    // 0x108: 0x24620008  addiu       $v0, $v1, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x10c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x110: 0x0  nop
    // NOP
    // 0x114: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x114u;
    {
        const bool branch_taken_0x114 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x114) {
            ctx->pc = 0x134u;
            goto label_134;
        }
    }
    ctx->pc = 0x11Cu;
    // 0x11c: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x120: 0x0  nop
    // NOP
    // 0x124: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x124u;
    {
        const bool branch_taken_0x124 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x124) {
            ctx->pc = 0x13Cu;
            goto label_13c;
        }
    }
    ctx->pc = 0x12Cu;
    // 0x12c: 0x800004d  j           func_000134
    ctx->pc = 0x12Cu;
    ctx->pc = 0x134u;
    goto label_134;
    ctx->pc = 0x134u;
label_134:
    // 0x134: 0x800007c  j           func_0001F0
    ctx->pc = 0x134u;
    // 0x138: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1F0u;
    goto label_1f0;
    ctx->pc = 0x13Cu;
label_13c:
    // 0x13c: 0x0  nop
    // NOP
    // 0x140: 0xafc0000c  sw          $zero, 0xC($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
label_144:
    // 0x144: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x148: 0x0  nop
    // NOP
    // 0x14c: 0x24620008  addiu       $v0, $v1, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x150: 0x8fc3000c  lw          $v1, 0xC($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x154: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x158: 0x0  nop
    // NOP
    // 0x15c: 0x62182a  slt         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x160: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x160u;
    {
        const bool branch_taken_0x160 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x160) {
            ctx->pc = 0x170u;
            goto label_170;
        }
    }
    ctx->pc = 0x168u;
    // 0x168: 0x800007a  j           func_0001E8
    ctx->pc = 0x168u;
    ctx->pc = 0x1E8u;
    goto label_1e8;
    ctx->pc = 0x170u;
label_170:
    // 0x170: 0x8fc2000c  lw          $v0, 0xC($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x174: 0x0  nop
    // NOP
    // 0x178: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x17c: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x180: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x184: 0x0  nop
    // NOP
    // 0x188: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18c: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x190: 0x0  nop
    // NOP
    // 0x194: 0xafc30008  sw          $v1, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 3));
    // 0x198: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x19c: 0x0  nop
    // NOP
    // 0x1a0: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1A0u;
    {
        const bool branch_taken_0x1a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a0) {
            ctx->pc = 0x1CCu;
            goto label_1cc;
        }
    }
    ctx->pc = 0x1A8u;
    // 0x1a8: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1ac: 0x0  nop
    // NOP
    // 0x1b0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b4: 0x0  nop
    // NOP
    // 0x1b8: 0x2c620008  sltiu       $v0, $v1, 0x8
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x1bc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BCu;
    {
        const bool branch_taken_0x1bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bc) {
            ctx->pc = 0x1CCu;
            goto label_1cc;
        }
    }
    ctx->pc = 0x1C4u;
    // 0x1c4: 0x8000075  j           func_0001D4
    ctx->pc = 0x1C4u;
    ctx->pc = 0x1D4u;
    goto label_1d4;
    ctx->pc = 0x1CCu;
label_1cc:
    // 0x1cc: 0x800007c  j           func_0001F0
    ctx->pc = 0x1CCu;
    // 0x1d0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1F0u;
    goto label_1f0;
    ctx->pc = 0x1D4u;
label_1d4:
    // 0x1d4: 0x8fc2000c  lw          $v0, 0xC($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1d8: 0x0  nop
    // NOP
    // 0x1dc: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e0: 0x8000051  j           func_000144
    ctx->pc = 0x1E0u;
    // 0x1e4: 0xafc3000c  sw          $v1, 0xC($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 3));
    ctx->pc = 0x144u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_144;
    ctx->pc = 0x1E8u;
label_1e8:
    // 0x1e8: 0x800007c  j           func_0001F0
    ctx->pc = 0x1E8u;
    // 0x1ec: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1F0u;
    goto label_1f0;
    ctx->pc = 0x1F0u;
label_1f0:
    // 0x1f0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1f4: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1fc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x200u;
}


// Function: modsein_00000200
// Address: 0x200 - 0x228
void modsein_00000200_0x200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000200_0x200");
#endif

    ctx->pc = 0x200u;

    // 0x200: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
    // 0x204: 0xafbe0000  sw          $fp, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 30));
    // 0x208: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x20c: 0xafc40008  sw          $a0, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 4));
    // 0x210: 0x8000086  j           func_000218
    ctx->pc = 0x210u;
    // 0x214: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x218u;
    goto label_218;
    ctx->pc = 0x218u;
label_218:
    // 0x218: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x21c: 0x8fbe0000  lw          $fp, 0x0($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x220: 0x3e00008  jr          $ra
    ctx->pc = 0x220u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x224: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x220u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x228u;
}


// Function: modsein_00000228
// Address: 0x228 - 0x250
void modsein_00000228_0x228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000228_0x228");
#endif

    ctx->pc = 0x228u;

    // 0x228: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
    // 0x22c: 0xafbe0000  sw          $fp, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 30));
    // 0x230: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x234: 0xafc40008  sw          $a0, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 4));
    // 0x238: 0x8000090  j           func_000240
    ctx->pc = 0x238u;
    // 0x23c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x240u;
    goto label_240;
    ctx->pc = 0x240u;
label_240:
    // 0x240: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x244: 0x8fbe0000  lw          $fp, 0x0($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x248: 0x3e00008  jr          $ra
    ctx->pc = 0x248u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x24c: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x248u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x250u;
}


// Function: modsein_00000250
// Address: 0x250 - 0x3f0
void modsein_00000250_0x250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000250_0x250");
#endif

    switch (ctx->pc) {
        case 0x268u: goto label_268;
        case 0x2dcu: goto label_2dc;
        case 0x344u: goto label_344;
        default: break;
    }

    ctx->pc = 0x250u;

    // 0x250: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x254: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x258: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x25c: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x260: 0xafc50024  sw          $a1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 5));
    // 0x264: 0xafc00000  sw          $zero, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
label_268:
    // 0x268: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x26c: 0x0  nop
    // NOP
    // 0x270: 0x28430004  slti        $v1, $v0, 0x4
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x274: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x274u;
    {
        const bool branch_taken_0x274 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x274) {
            ctx->pc = 0x284u;
            goto label_284;
        }
    }
    ctx->pc = 0x27Cu;
    // 0x27c: 0x80000b1  j           func_0002C4
    ctx->pc = 0x27Cu;
    ctx->pc = 0x2C4u;
    goto label_2c4;
    ctx->pc = 0x284u;
label_284:
    // 0x284: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x288: 0x27c30010  addiu       $v1, $fp, 0x10
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x28c: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x290: 0x93c30020  lbu         $v1, 0x20($fp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x294: 0x0  nop
    // NOP
    // 0x298: 0x3064007f  andi        $a0, $v1, 0x7F
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
    // 0x29c: 0xa0440000  sb          $a0, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x2a0: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2a4: 0x0  nop
    // NOP
    // 0x2a8: 0x219c2  srl         $v1, $v0, 7
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 7));
    // 0x2ac: 0xafc30020  sw          $v1, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 3));
    // 0x2b0: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x2b4: 0x0  nop
    // NOP
    // 0x2b8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x2bc: 0x800009a  j           func_000268
    ctx->pc = 0x2BCu;
    // 0x2c0: 0xafc30000  sw          $v1, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x268u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_268;
    ctx->pc = 0x2C4u;
label_2c4:
    // 0x2c4: 0x93c20020  lbu         $v0, 0x20($fp)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2c8: 0x0  nop
    // NOP
    // 0x2cc: 0x3043000f  andi        $v1, $v0, 0xF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x2d0: 0xa3c30014  sb          $v1, 0x14($fp)
    WRITE8(ADD32(GPR_U32(ctx, 30), 20), (uint8_t)GPR_U32(ctx, 3));
    // 0x2d4: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x2d8: 0xafc20004  sw          $v0, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_2dc:
    // 0x2dc: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x2e0: 0x27c30010  addiu       $v1, $fp, 0x10
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x2e4: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x2e8: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2ec: 0x0  nop
    // NOP
    // 0x2f0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2F0u;
    {
        const bool branch_taken_0x2f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x2f0) {
            ctx->pc = 0x300u;
            goto label_300;
        }
    }
    ctx->pc = 0x2F8u;
    // 0x2f8: 0x80000cc  j           func_000330
    ctx->pc = 0x2F8u;
    ctx->pc = 0x330u;
    goto label_330;
    ctx->pc = 0x300u;
label_300:
    // 0x300: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x304: 0x0  nop
    // NOP
    // 0x308: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x30c: 0xafc30004  sw          $v1, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 3));
    // 0x310: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x314: 0x0  nop
    // NOP
    // 0x318: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x318u;
    {
        const bool branch_taken_0x318 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x318) {
            ctx->pc = 0x328u;
            goto label_328;
        }
    }
    ctx->pc = 0x320u;
    // 0x320: 0x80000cc  j           func_000330
    ctx->pc = 0x320u;
    ctx->pc = 0x330u;
    goto label_330;
    ctx->pc = 0x328u;
label_328:
    // 0x328: 0x80000b7  j           func_0002DC
    ctx->pc = 0x328u;
    ctx->pc = 0x2DCu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2dc;
    ctx->pc = 0x330u;
label_330:
    // 0x330: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x334: 0xafc20008  sw          $v0, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x338: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x33c: 0x0  nop
    // NOP
    // 0x340: 0xafc20000  sw          $v0, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
label_344:
    // 0x344: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x348: 0x0  nop
    // NOP
    // 0x34c: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x34Cu;
    {
        const bool branch_taken_0x34c = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x34c) {
            ctx->pc = 0x35Cu;
            goto label_35c;
        }
    }
    ctx->pc = 0x354u;
    // 0x354: 0x80000ec  j           func_0003B0
    ctx->pc = 0x354u;
    ctx->pc = 0x3B0u;
    goto label_3b0;
    ctx->pc = 0x35Cu;
label_35c:
    // 0x35c: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x360: 0x0  nop
    // NOP
    // 0x364: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x368: 0x8fc40000  lw          $a0, 0x0($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x36c: 0x27c50010  addiu       $a1, $fp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x370: 0xa42021  addu        $a0, $a1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x374: 0x90850000  lbu         $a1, 0x0($a0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x378: 0x0  nop
    // NOP
    // 0x37c: 0x34a40080  ori         $a0, $a1, 0x80
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)128);
    // 0x380: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x384: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x388: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x38c: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x390: 0x0  nop
    // NOP
    // 0x394: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x398: 0xafc30008  sw          $v1, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 3));
    // 0x39c: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x3a0: 0x0  nop
    // NOP
    // 0x3a4: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x3a8: 0x80000d1  j           func_000344
    ctx->pc = 0x3A8u;
    // 0x3ac: 0xafc30000  sw          $v1, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x344u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_344;
    ctx->pc = 0x3B0u;
label_3b0:
    // 0x3b0: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x3b4: 0x0  nop
    // NOP
    // 0x3b8: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x3bc: 0x93c40010  lbu         $a0, 0x10($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x3c0: 0x0  nop
    // NOP
    // 0x3c4: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x3c8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x3cc: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x3d0: 0x8fc30008  lw          $v1, 0x8($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x3d4: 0x0  nop
    // NOP
    // 0x3d8: 0x80000f8  j           func_0003E0
    ctx->pc = 0x3D8u;
    // 0x3dc: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x3E0u;
    goto label_3e0;
    ctx->pc = 0x3E0u;
label_3e0:
    // 0x3e0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x3e4: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x3e8: 0x3e00008  jr          $ra
    ctx->pc = 0x3E8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3E8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3F0u;
}


// Function: modsein_000003f0
// Address: 0x3f0 - 0x664
void modsein_000003f0_0x3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_000003f0_0x3f0");
#endif

    switch (ctx->pc) {
        case 0x5d0u: goto label_5d0;
        default: break;
    }

    ctx->pc = 0x3f0u;

    // 0x3f0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x3f4: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x3f8: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x3fc: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x400: 0xafc5001c  sw          $a1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 5));
    // 0x404: 0xafc60020  sw          $a2, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 6));
    // 0x408: 0xafc70024  sw          $a3, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 7));
    // 0x40c: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x410: 0x0  nop
    // NOP
    // 0x414: 0x24430006  addiu       $v1, $v0, 0x6
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0x418: 0xafc3000c  sw          $v1, 0xC($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 3));
    // 0x41c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x420: 0x0  nop
    // NOP
    // 0x424: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x424u;
    {
        const bool branch_taken_0x424 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x424) {
            ctx->pc = 0x434u;
            goto label_434;
        }
    }
    ctx->pc = 0x42Cu;
    // 0x42c: 0x8000195  j           func_000654
    ctx->pc = 0x42Cu;
    // 0x430: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x654u;
    goto label_654;
    ctx->pc = 0x434u;
label_434:
    // 0x434: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x438: 0x0  nop
    // NOP
    // 0x43c: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x440: 0x0  nop
    // NOP
    // 0x444: 0x24620008  addiu       $v0, $v1, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x448: 0xafc20000  sw          $v0, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x44c: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x450: 0x8fc3001c  lw          $v1, 0x1C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x454: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x458: 0x0  nop
    // NOP
    // 0x45c: 0x62182b  sltu        $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x460: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x460u;
    {
        const bool branch_taken_0x460 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x460) {
            ctx->pc = 0x470u;
            goto label_470;
        }
    }
    ctx->pc = 0x468u;
    // 0x468: 0x8000195  j           func_000654
    ctx->pc = 0x468u;
    // 0x46c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x654u;
    goto label_654;
    ctx->pc = 0x470u;
label_470:
    // 0x470: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x474: 0x8fc3001c  lw          $v1, 0x1C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x478: 0x0  nop
    // NOP
    // 0x47c: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x480: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x484: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x488: 0x0  nop
    // NOP
    // 0x48c: 0x641021  addu        $v0, $v1, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x490: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x494: 0x0  nop
    // NOP
    // 0x498: 0xafc30004  sw          $v1, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 3));
    // 0x49c: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x4a0: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x4a4: 0x8fc5000c  lw          $a1, 0xC($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x4a8: 0x0  nop
    // NOP
    // 0x4ac: 0x24a40008  addiu       $a0, $a1, 0x8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x4b0: 0x8c650004  lw          $a1, 0x4($v1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x4b4: 0x0  nop
    // NOP
    // 0x4b8: 0x851821  addu        $v1, $a0, $a1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x4bc: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x4c0: 0x0  nop
    // NOP
    // 0x4c4: 0x43182b  sltu        $v1, $v0, $v1
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x4c8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x4C8u;
    {
        const bool branch_taken_0x4c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x4c8) {
            ctx->pc = 0x4D8u;
            goto label_4d8;
        }
    }
    ctx->pc = 0x4D0u;
    // 0x4d0: 0x8000195  j           func_000654
    ctx->pc = 0x4D0u;
    // 0x4d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x654u;
    goto label_654;
    ctx->pc = 0x4D8u;
label_4d8:
    // 0x4d8: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x4dc: 0x0  nop
    // NOP
    // 0x4e0: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x4e4: 0x0  nop
    // NOP
    // 0x4e8: 0x24620008  addiu       $v0, $v1, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x4ec: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x4f0: 0x0  nop
    // NOP
    // 0x4f4: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x4f8: 0xafc20008  sw          $v0, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x4fc: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x500: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x504: 0x240400fe  addiu       $a0, $zero, 0xFE
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x508: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x50c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x510: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x514: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x518: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x51c: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x520: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x524: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x528: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x52c: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x530: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x534: 0x93c40020  lbu         $a0, 0x20($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x538: 0x0  nop
    // NOP
    // 0x53c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x540: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x544: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x548: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x54c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x550: 0x8fc50020  lw          $a1, 0x20($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x554: 0x0  nop
    // NOP
    // 0x558: 0x30a4ff00  andi        $a0, $a1, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x55c: 0x42a02  srl         $a1, $a0, 8
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x560: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x564: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x568: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x56c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x570: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x574: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x578: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x57c: 0x3c0500ff  lui         $a1, 0xFF
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)255 << 16));
    // 0x580: 0x852024  and         $a0, $a0, $a1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x584: 0x42c02  srl         $a1, $a0, 16
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x588: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x58c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x590: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x594: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x598: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x59c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x5a0: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x5a4: 0x3c05ff00  lui         $a1, 0xFF00
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x5a8: 0x852024  and         $a0, $a0, $a1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x5ac: 0x42e02  srl         $a1, $a0, 24
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x5b0: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x5b4: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x5b8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x5bc: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x5c0: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x5c4: 0x0  nop
    // NOP
    // 0x5c8: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x5C8u;
    {
        const bool branch_taken_0x5c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5c8) {
            ctx->pc = 0x62Cu;
            goto label_62c;
        }
    }
    ctx->pc = 0x5D0u;
label_5d0:
    // 0x5d0: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x5d4: 0x0  nop
    // NOP
    // 0x5d8: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x5dc: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x5e0: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x5e4: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x5e8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x5E8u;
    {
        const bool branch_taken_0x5e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x5e8) {
            ctx->pc = 0x5F8u;
            goto label_5f8;
        }
    }
    ctx->pc = 0x5F0u;
    // 0x5f0: 0x800018b  j           func_00062C
    ctx->pc = 0x5F0u;
    ctx->pc = 0x62Cu;
    goto label_62c;
    ctx->pc = 0x5F8u;
label_5f8:
    // 0x5f8: 0x27c20008  addiu       $v0, $fp, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x5fc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x600: 0x27c40024  addiu       $a0, $fp, 0x24
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x604: 0x8c850000  lw          $a1, 0x0($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x608: 0x0  nop
    // NOP
    // 0x60c: 0x90a60000  lbu         $a2, 0x0($a1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x610: 0x0  nop
    // NOP
    // 0x614: 0xa0660000  sb          $a2, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x618: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x61c: 0xac850000  sw          $a1, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x620: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x624: 0x8000174  j           func_0005D0
    ctx->pc = 0x624u;
    // 0x628: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x5D0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_5d0;
    ctx->pc = 0x62Cu;
label_62c:
    // 0x62c: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x630: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x634: 0x0  nop
    // NOP
    // 0x638: 0x8c640004  lw          $a0, 0x4($v1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x63c: 0x8fc3000c  lw          $v1, 0xC($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x640: 0x0  nop
    // NOP
    // 0x644: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x648: 0xac440004  sw          $a0, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 4));
    // 0x64c: 0x8000195  j           func_000654
    ctx->pc = 0x64Cu;
    // 0x650: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x654u;
    goto label_654;
    ctx->pc = 0x654u;
label_654:
    // 0x654: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x658: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x65c: 0x3e00008  jr          $ra
    ctx->pc = 0x65Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x660: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x65Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x664u;
}


// Function: modsein_00000664
// Address: 0x664 - 0x828
void modsein_00000664_0x664(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000664_0x664");
#endif

    switch (ctx->pc) {
        case 0x6fcu: goto label_6fc;
        case 0x778u: goto label_778;
        case 0x808u: goto label_808;
        default: break;
    }

    ctx->pc = 0x664u;

    // 0x664: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0x668: 0xafbf0044  sw          $ra, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 31));
    // 0x66c: 0xafbe0040  sw          $fp, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 30));
    // 0x670: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x674: 0xafc40048  sw          $a0, 0x48($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 72), GPR_U32(ctx, 4));
    // 0x678: 0xafc5004c  sw          $a1, 0x4C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 76), GPR_U32(ctx, 5));
    // 0x67c: 0xafc60050  sw          $a2, 0x50($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 80), GPR_U32(ctx, 6));
    // 0x680: 0xafc70054  sw          $a3, 0x54($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 84), GPR_U32(ctx, 7));
    // 0x684: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x688: 0xafc20030  sw          $v0, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x68c: 0x27c20054  addiu       $v0, $fp, 0x54
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 84));
    // 0x690: 0xafc20038  sw          $v0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x694: 0x27c20058  addiu       $v0, $fp, 0x58
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 88));
    // 0x698: 0xafc2003c  sw          $v0, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x69c: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x6a0: 0xafc00018  sw          $zero, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x6a4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6a8: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x6ac: 0x8fc30054  lw          $v1, 0x54($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x6b0: 0x0  nop
    // NOP
    // 0x6b4: 0x306200f0  andi        $v0, $v1, 0xF0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)240);
    // 0x6b8: 0x240300a0  addiu       $v1, $zero, 0xA0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 160));
    // 0x6bc: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x6BCu;
    {
        const bool branch_taken_0x6bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x6bc) {
            ctx->pc = 0x6CCu;
            goto label_6cc;
        }
    }
    ctx->pc = 0x6C4u;
    // 0x6c4: 0x80001b8  j           func_0006E0
    ctx->pc = 0x6C4u;
    ctx->pc = 0x6E0u;
    goto label_6e0;
    ctx->pc = 0x6CCu;
label_6cc:
    // 0x6cc: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x6d0: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x6d4: 0x24020003  addiu       $v0, $zero, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x6d8: 0x80001ba  j           func_0006E8
    ctx->pc = 0x6D8u;
    // 0x6dc: 0xafc2001c  sw          $v0, 0x1C($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    ctx->pc = 0x6E8u;
    goto label_6e8;
    ctx->pc = 0x6E0u;
label_6e0:
    // 0x6e0: 0x8000205  j           func_000814
    ctx->pc = 0x6E0u;
    // 0x6e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x814u;
    goto label_814;
    ctx->pc = 0x6E8u;
label_6e8:
    // 0x6e8: 0xafc00034  sw          $zero, 0x34($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 0));
    // 0x6ec: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x6f0: 0x0  nop
    // NOP
    // 0x6f4: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x6F4u;
    {
        const bool branch_taken_0x6f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x6f4) {
            ctx->pc = 0x768u;
            goto label_768;
        }
    }
    ctx->pc = 0x6FCu;
label_6fc:
    // 0x6fc: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x700: 0x0  nop
    // NOP
    // 0x704: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x708: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x70c: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x710: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x714: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x714u;
    {
        const bool branch_taken_0x714 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x714) {
            ctx->pc = 0x724u;
            goto label_724;
        }
    }
    ctx->pc = 0x71Cu;
    // 0x71c: 0x80001da  j           func_000768
    ctx->pc = 0x71Cu;
    ctx->pc = 0x768u;
    goto label_768;
    ctx->pc = 0x724u;
label_724:
    // 0x724: 0x27c20030  addiu       $v0, $fp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 48));
    // 0x728: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x72c: 0x27c40038  addiu       $a0, $fp, 0x38
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 56));
    // 0x730: 0x8c850000  lw          $a1, 0x0($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x734: 0x0  nop
    // NOP
    // 0x738: 0x90a60000  lbu         $a2, 0x0($a1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x73c: 0x0  nop
    // NOP
    // 0x740: 0xa0660000  sb          $a2, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x744: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x748: 0xac850000  sw          $a1, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x74c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x750: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x754: 0x8fc20034  lw          $v0, 0x34($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x758: 0x0  nop
    // NOP
    // 0x75c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x760: 0x80001bf  j           func_0006FC
    ctx->pc = 0x760u;
    // 0x764: 0xafc30034  sw          $v1, 0x34($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 3));
    ctx->pc = 0x6FCu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_6fc;
    ctx->pc = 0x768u;
label_768:
    // 0x768: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x76c: 0x0  nop
    // NOP
    // 0x770: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x770u;
    {
        const bool branch_taken_0x770 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x770) {
            ctx->pc = 0x7E4u;
            goto label_7e4;
        }
    }
    ctx->pc = 0x778u;
label_778:
    // 0x778: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x77c: 0x0  nop
    // NOP
    // 0x780: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x784: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x788: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x78c: 0x2403ffff  addiu       $v1, $zero, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x790: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x790u;
    {
        const bool branch_taken_0x790 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x790) {
            ctx->pc = 0x7A0u;
            goto label_7a0;
        }
    }
    ctx->pc = 0x798u;
    // 0x798: 0x80001f9  j           func_0007E4
    ctx->pc = 0x798u;
    ctx->pc = 0x7E4u;
    goto label_7e4;
    ctx->pc = 0x7A0u;
label_7a0:
    // 0x7a0: 0x27c20030  addiu       $v0, $fp, 0x30
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 48));
    // 0x7a4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x7a8: 0x27c4003c  addiu       $a0, $fp, 0x3C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 60));
    // 0x7ac: 0x8c850000  lw          $a1, 0x0($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x7b0: 0x0  nop
    // NOP
    // 0x7b4: 0x90a60000  lbu         $a2, 0x0($a1)
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x7b8: 0x0  nop
    // NOP
    // 0x7bc: 0xa0660000  sb          $a2, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x7c0: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x7c4: 0xac850000  sw          $a1, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x7c8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x7cc: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x7d0: 0x8fc20034  lw          $v0, 0x34($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x7d4: 0x0  nop
    // NOP
    // 0x7d8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x7dc: 0x80001de  j           func_000778
    ctx->pc = 0x7DCu;
    // 0x7e0: 0xafc30034  sw          $v1, 0x34($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 3));
    ctx->pc = 0x778u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_778;
    ctx->pc = 0x7E4u;
label_7e4:
    // 0x7e4: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x7e8: 0x8fc30034  lw          $v1, 0x34($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x7ec: 0x0  nop
    // NOP
    // 0x7f0: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x7f4: 0x8fc40048  lw          $a0, 0x48($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x7f8: 0x8fc5004c  lw          $a1, 0x4C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x7fc: 0x8fc60050  lw          $a2, 0x50($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x800: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x800u;
    SET_GPR_U32(ctx, 31, 0x808u);
    // 0x804: 0x403821  addu        $a3, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x800u, 0x808u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x808u;
label_808:
    // 0x808: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x80c: 0x8000205  j           func_000814
    ctx->pc = 0x80Cu;
    // 0x810: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x814u;
    goto label_814;
    ctx->pc = 0x814u;
label_814:
    // 0x814: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x818: 0x8fbf0044  lw          $ra, 0x44($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x81c: 0x8fbe0040  lw          $fp, 0x40($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x820: 0x3e00008  jr          $ra
    ctx->pc = 0x820u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x824: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x820u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x828u;
}


// Function: modsein_00000828
// Address: 0x828 - 0x9e0
void modsein_00000828_0x828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000828_0x828");
#endif

    switch (ctx->pc) {
        case 0x9c0u: goto label_9c0;
        default: break;
    }

    ctx->pc = 0x828u;

    // 0x828: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x82c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x830: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x834: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x838: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x83c: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x840: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x844: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x848: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x84c: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x850: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x854: 0x0  nop
    // NOP
    // 0x858: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x85c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x85Cu;
    {
        const bool branch_taken_0x85c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x85c) {
            ctx->pc = 0x86Cu;
            goto label_86c;
        }
    }
    ctx->pc = 0x864u;
    // 0x864: 0x8000273  j           func_0009CC
    ctx->pc = 0x864u;
    // 0x868: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x9CCu;
    goto label_9cc;
    ctx->pc = 0x86Cu;
label_86c:
    // 0x86c: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x870: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x874: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x878: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x87c: 0x0  nop
    // NOP
    // 0x880: 0x348500a0  ori         $a1, $a0, 0xA0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)160);
    // 0x884: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x888: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x88c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x890: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x894: 0x0  nop
    // NOP
    // 0x898: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x89c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x8a0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x8a4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x8a8: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x8ac: 0x0  nop
    // NOP
    // 0x8b0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x8b4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x8b8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x8bc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x8c0: 0x0  nop
    // NOP
    // 0x8c4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x8c8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x8cc: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x8d0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x8d4: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x8d8: 0x0  nop
    // NOP
    // 0x8dc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x8e0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x8e4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x8e8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x8ec: 0x0  nop
    // NOP
    // 0x8f0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x8f4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x8f8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x8fc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x900: 0x93c40050  lbu         $a0, 0x50($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x904: 0x0  nop
    // NOP
    // 0x908: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x90c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x910: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x914: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x918: 0x0  nop
    // NOP
    // 0x91c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x920: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x924: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x928: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x92c: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x930: 0x0  nop
    // NOP
    // 0x934: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x938: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x93c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x940: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x944: 0x0  nop
    // NOP
    // 0x948: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x94c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x950: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x954: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x958: 0x0  nop
    // NOP
    // 0x95c: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x960: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x964: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x968: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x96c: 0x0  nop
    // NOP
    // 0x970: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x974: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x978: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x97c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x980: 0x0  nop
    // NOP
    // 0x984: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x988: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x98c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x990: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x994: 0x0  nop
    // NOP
    // 0x998: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x99c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x9a0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x9a4: 0x0  nop
    // NOP
    // 0x9a8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x9ac: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x9b0: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x9b4: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x9b8: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x9B8u;
    SET_GPR_U32(ctx, 31, 0x9C0u);
    // 0x9bc: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x9B8u, 0x9C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9C0u;
label_9c0:
    // 0x9c0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x9c4: 0x8000273  j           func_0009CC
    ctx->pc = 0x9C4u;
    // 0x9c8: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x9CCu;
    goto label_9cc;
    ctx->pc = 0x9CCu;
label_9cc:
    // 0x9cc: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x9d0: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x9d4: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x9d8: 0x3e00008  jr          $ra
    ctx->pc = 0x9D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9dc: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x9D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9E0u;
}


// Function: modsein_000009e0
// Address: 0x9e0 - 0xbb0
void modsein_000009e0_0x9e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_000009e0_0x9e0");
#endif

    switch (ctx->pc) {
        case 0xb90u: goto label_b90;
        default: break;
    }

    ctx->pc = 0x9e0u;

    // 0x9e0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x9e4: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x9e8: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x9ec: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x9f0: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x9f4: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x9f8: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x9fc: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0xa00: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xa04: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0xa08: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0xa0c: 0x0  nop
    // NOP
    // 0xa10: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0xa14: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xA14u;
    {
        const bool branch_taken_0xa14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xa14) {
            ctx->pc = 0xA24u;
            goto label_a24;
        }
    }
    ctx->pc = 0xA1Cu;
    // 0xa1c: 0x80002e7  j           func_000B9C
    ctx->pc = 0xA1Cu;
    // 0xa20: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xB9Cu;
    goto label_b9c;
    ctx->pc = 0xA24u;
label_a24:
    // 0xa24: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0xa28: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xa2c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xa30: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0xa34: 0x0  nop
    // NOP
    // 0xa38: 0x348500a0  ori         $a1, $a0, 0xA0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)160);
    // 0xa3c: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xa40: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa44: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xa48: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xa4c: 0x0  nop
    // NOP
    // 0xa50: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xa54: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xa58: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xa5c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xa60: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0xa64: 0x0  nop
    // NOP
    // 0xa68: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xa6c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa70: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xa74: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xa78: 0x0  nop
    // NOP
    // 0xa7c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xa80: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xa84: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xa88: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xa8c: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0xa90: 0x0  nop
    // NOP
    // 0xa94: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xa98: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xa9c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xaa0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xaa4: 0x0  nop
    // NOP
    // 0xaa8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xaac: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xab0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xab4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xab8: 0x93c40050  lbu         $a0, 0x50($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 80)));
    // 0xabc: 0x0  nop
    // NOP
    // 0xac0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xac4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xac8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xacc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xad0: 0x0  nop
    // NOP
    // 0xad4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xad8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xadc: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xae0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xae4: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0xae8: 0x0  nop
    // NOP
    // 0xaec: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xaf0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xaf4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xaf8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xafc: 0x0  nop
    // NOP
    // 0xb00: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xb04: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xb08: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xb0c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xb10: 0x93c40058  lbu         $a0, 0x58($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 88)));
    // 0xb14: 0x0  nop
    // NOP
    // 0xb18: 0x3085007f  andi        $a1, $a0, 0x7F
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
    // 0xb1c: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xb20: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xb24: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xb28: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xb2c: 0x0  nop
    // NOP
    // 0xb30: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xb34: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xb38: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xb3c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xb40: 0x8fc50058  lw          $a1, 0x58($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0xb44: 0x0  nop
    // NOP
    // 0xb48: 0x30a43f80  andi        $a0, $a1, 0x3F80
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16256);
    // 0xb4c: 0x429c2  srl         $a1, $a0, 7
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 7));
    // 0xb50: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0xb54: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xb58: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xb5c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xb60: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xb64: 0x0  nop
    // NOP
    // 0xb68: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xb6c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xb70: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xb74: 0x0  nop
    // NOP
    // 0xb78: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xb7c: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0xb80: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0xb84: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0xb88: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0xB88u;
    SET_GPR_U32(ctx, 31, 0xB90u);
    // 0xb8c: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0xB88u, 0xB90u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB90u;
label_b90:
    // 0xb90: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb94: 0x80002e7  j           func_000B9C
    ctx->pc = 0xB94u;
    // 0xb98: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0xB9Cu;
    goto label_b9c;
    ctx->pc = 0xB9Cu;
label_b9c:
    // 0xb9c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xba0: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xba4: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
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


// Function: modsein_00000bb0
// Address: 0xbb0 - 0xd68
void modsein_00000bb0_0xbb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000bb0_0xbb0");
#endif

    switch (ctx->pc) {
        case 0xd48u: goto label_d48;
        default: break;
    }

    ctx->pc = 0xbb0u;

    // 0xbb0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xbb4: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xbb8: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0xbbc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xbc0: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0xbc4: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0xbc8: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0xbcc: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0xbd0: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xbd4: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0xbd8: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0xbdc: 0x0  nop
    // NOP
    // 0xbe0: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0xbe4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xBE4u;
    {
        const bool branch_taken_0xbe4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xbe4) {
            ctx->pc = 0xBF4u;
            goto label_bf4;
        }
    }
    ctx->pc = 0xBECu;
    // 0xbec: 0x8000355  j           func_000D54
    ctx->pc = 0xBECu;
    // 0xbf0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xBF4u;
label_bf4:
    // 0xbf4: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0xbf8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xbfc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xc00: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0xc04: 0x0  nop
    // NOP
    // 0xc08: 0x34850090  ori         $a1, $a0, 0x90
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)144);
    // 0xc0c: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xc10: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xc14: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xc18: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xc1c: 0x0  nop
    // NOP
    // 0xc20: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xc24: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xc28: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xc2c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xc30: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0xc34: 0x0  nop
    // NOP
    // 0xc38: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xc3c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xc40: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xc44: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xc48: 0x0  nop
    // NOP
    // 0xc4c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xc50: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xc54: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xc58: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xc5c: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0xc60: 0x0  nop
    // NOP
    // 0xc64: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xc68: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xc6c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xc70: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xc74: 0x0  nop
    // NOP
    // 0xc78: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xc7c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xc80: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xc84: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xc88: 0x93c40050  lbu         $a0, 0x50($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 80)));
    // 0xc8c: 0x0  nop
    // NOP
    // 0xc90: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xc94: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xc98: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xc9c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xca0: 0x0  nop
    // NOP
    // 0xca4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xca8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xcac: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xcb0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xcb4: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0xcb8: 0x0  nop
    // NOP
    // 0xcbc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xcc0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xcc4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xcc8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xccc: 0x0  nop
    // NOP
    // 0xcd0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xcd4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xcd8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xcdc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xce0: 0x0  nop
    // NOP
    // 0xce4: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xce8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xcec: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xcf0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xcf4: 0x0  nop
    // NOP
    // 0xcf8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xcfc: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xd00: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xd04: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xd08: 0x0  nop
    // NOP
    // 0xd0c: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0xd10: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xd14: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xd18: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xd1c: 0x0  nop
    // NOP
    // 0xd20: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xd24: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xd28: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xd2c: 0x0  nop
    // NOP
    // 0xd30: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xd34: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0xd38: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0xd3c: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0xd40: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0xD40u;
    SET_GPR_U32(ctx, 31, 0xD48u);
    // 0xd44: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0xD40u, 0xD48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD48u;
label_d48:
    // 0xd48: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xd4c: 0x8000355  j           func_000D54
    ctx->pc = 0xD4Cu;
    // 0xd50: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0xD54u;
    goto label_d54;
    ctx->pc = 0xD54u;
label_d54:
    // 0xd54: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xd58: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xd5c: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xd60: 0x3e00008  jr          $ra
    ctx->pc = 0xD60u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd64: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD60u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD68u;
}


// Function: modsein_00000d68
// Address: 0xd68 - 0xf38
void modsein_00000d68_0xd68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000d68_0xd68");
#endif

    switch (ctx->pc) {
        case 0xf18u: goto label_f18;
        default: break;
    }

    ctx->pc = 0xd68u;

    // 0xd68: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xd6c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xd70: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0xd74: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xd78: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0xd7c: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0xd80: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0xd84: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0xd88: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xd8c: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0xd90: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0xd94: 0x0  nop
    // NOP
    // 0xd98: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0xd9c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xD9Cu;
    {
        const bool branch_taken_0xd9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xd9c) {
            ctx->pc = 0xDACu;
            goto label_dac;
        }
    }
    ctx->pc = 0xDA4u;
    // 0xda4: 0x80003c9  j           func_000F24
    ctx->pc = 0xDA4u;
    // 0xda8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0xF24u;
    goto label_f24;
    ctx->pc = 0xDACu;
label_dac:
    // 0xdac: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0xdb0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xdb4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xdb8: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0xdbc: 0x0  nop
    // NOP
    // 0xdc0: 0x34850090  ori         $a1, $a0, 0x90
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)144);
    // 0xdc4: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xdc8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xdcc: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xdd0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xdd4: 0x0  nop
    // NOP
    // 0xdd8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xddc: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xde0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xde4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xde8: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0xdec: 0x0  nop
    // NOP
    // 0xdf0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xdf4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xdf8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xdfc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xe00: 0x0  nop
    // NOP
    // 0xe04: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe08: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xe0c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xe10: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xe14: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0xe18: 0x0  nop
    // NOP
    // 0xe1c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xe20: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe24: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xe28: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xe2c: 0x0  nop
    // NOP
    // 0xe30: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe34: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xe38: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xe3c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xe40: 0x93c40050  lbu         $a0, 0x50($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 80)));
    // 0xe44: 0x0  nop
    // NOP
    // 0xe48: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xe4c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe50: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xe54: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xe58: 0x0  nop
    // NOP
    // 0xe5c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe60: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xe64: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xe68: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xe6c: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0xe70: 0x0  nop
    // NOP
    // 0xe74: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xe78: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xe7c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xe80: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xe84: 0x0  nop
    // NOP
    // 0xe88: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xe8c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xe90: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xe94: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xe98: 0x93c40058  lbu         $a0, 0x58($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 88)));
    // 0xe9c: 0x0  nop
    // NOP
    // 0xea0: 0x3085007f  andi        $a1, $a0, 0x7F
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
    // 0xea4: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0xea8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xeac: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xeb0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xeb4: 0x0  nop
    // NOP
    // 0xeb8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xebc: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xec0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xec4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xec8: 0x8fc50058  lw          $a1, 0x58($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0xecc: 0x0  nop
    // NOP
    // 0xed0: 0x30a43f80  andi        $a0, $a1, 0x3F80
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16256);
    // 0xed4: 0x429c2  srl         $a1, $a0, 7
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 7));
    // 0xed8: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0xedc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xee0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xee4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xee8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xeec: 0x0  nop
    // NOP
    // 0xef0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xef4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xef8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xefc: 0x0  nop
    // NOP
    // 0xf00: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xf04: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0xf08: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0xf0c: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0xf10: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0xF10u;
    SET_GPR_U32(ctx, 31, 0xF18u);
    // 0xf14: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0xF10u, 0xF18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF18u;
label_f18:
    // 0xf18: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xf1c: 0x80003c9  j           func_000F24
    ctx->pc = 0xF1Cu;
    // 0xf20: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0xF24u;
    goto label_f24;
    ctx->pc = 0xF24u;
label_f24:
    // 0xf24: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xf28: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xf2c: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xf30: 0x3e00008  jr          $ra
    ctx->pc = 0xF30u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf34: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF30u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF38u;
}


// Function: modsein_00000f38
// Address: 0xf38 - 0xff0
void modsein_00000f38_0xf38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000f38_0xf38");
#endif

    switch (ctx->pc) {
        case 0xfd0u: goto label_fd0;
        default: break;
    }

    ctx->pc = 0xf38u;

    // 0xf38: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xf3c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xf40: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0xf44: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xf48: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0xf4c: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0xf50: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0xf54: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xf58: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0xf5c: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0xf60: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xf64: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf68: 0x240400c0  addiu       $a0, $zero, 0xC0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0xf6c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xf70: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xf74: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xf78: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xf7c: 0x0  nop
    // NOP
    // 0xf80: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xf84: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xf88: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0xf8c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xf90: 0x2404001f  addiu       $a0, $zero, 0x1F
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0xf94: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0xf98: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0xf9c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xfa0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xfa4: 0x0  nop
    // NOP
    // 0xfa8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xfac: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0xfb0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0xfb4: 0x0  nop
    // NOP
    // 0xfb8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xfbc: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0xfc0: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0xfc4: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0xfc8: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0xFC8u;
    SET_GPR_U32(ctx, 31, 0xFD0u);
    // 0xfcc: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0xFC8u, 0xFD0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFD0u;
label_fd0:
    // 0xfd0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xfd4: 0x80003f7  j           func_000FDC
    ctx->pc = 0xFD4u;
    // 0xfd8: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0xFDCu;
    goto label_fdc;
    ctx->pc = 0xFDCu;
label_fdc:
    // 0xfdc: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xfe0: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xfe4: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xfe8: 0x3e00008  jr          $ra
    ctx->pc = 0xFE8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xfec: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
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


// Function: modsein_00000ff0
// Address: 0xff0 - 0x1254
void modsein_00000ff0_0xff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00000ff0_0xff0");
#endif

    switch (ctx->pc) {
        case 0x1234u: goto label_1234;
        default: break;
    }

    ctx->pc = 0xff0u;

    // 0xff0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xff4: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0xff8: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0xffc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1000: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x1004: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x1008: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x100c: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x1010: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1014: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1018: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x101c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1020: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1024: 0x240400c0  addiu       $a0, $zero, 0xC0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x1028: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x102c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1030: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1034: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1038: 0x0  nop
    // NOP
    // 0x103c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1040: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1044: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1048: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x104c: 0x2404001e  addiu       $a0, $zero, 0x1E
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1050: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1054: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1058: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x105c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1060: 0x0  nop
    // NOP
    // 0x1064: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1068: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x106c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1070: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1074: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1078: 0x0  nop
    // NOP
    // 0x107c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1080: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1084: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1088: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x108c: 0x0  nop
    // NOP
    // 0x1090: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1094: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1098: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x109c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10a0: 0x8fc50044  lw          $a1, 0x44($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x10a4: 0x0  nop
    // NOP
    // 0x10a8: 0x30a4ff00  andi        $a0, $a1, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x10ac: 0x42a02  srl         $a1, $a0, 8
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x10b0: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x10b4: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x10b8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10bc: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x10c0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x10c4: 0x0  nop
    // NOP
    // 0x10c8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10cc: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x10d0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x10d4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d8: 0x8fc40044  lw          $a0, 0x44($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x10dc: 0x3c0500ff  lui         $a1, 0xFF
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)255 << 16));
    // 0x10e0: 0x852024  and         $a0, $a0, $a1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x10e4: 0x42c02  srl         $a1, $a0, 16
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x10e8: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x10ec: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x10f0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10f4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x10f8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x10fc: 0x0  nop
    // NOP
    // 0x1100: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1104: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1108: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x110c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1110: 0x8fc40044  lw          $a0, 0x44($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1114: 0x3c05ff00  lui         $a1, 0xFF00
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1118: 0x852024  and         $a0, $a0, $a1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x111c: 0x42e02  srl         $a1, $a0, 24
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x1120: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1124: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1128: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x112c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1130: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1134: 0x0  nop
    // NOP
    // 0x1138: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x113c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1140: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1144: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1148: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x114c: 0x0  nop
    // NOP
    // 0x1150: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1154: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1158: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x115c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1160: 0x0  nop
    // NOP
    // 0x1164: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1168: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x116c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1170: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1174: 0x8fc50048  lw          $a1, 0x48($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1178: 0x0  nop
    // NOP
    // 0x117c: 0x30a4ff00  andi        $a0, $a1, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x1180: 0x42a02  srl         $a1, $a0, 8
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1184: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1188: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x118c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1190: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1194: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1198: 0x0  nop
    // NOP
    // 0x119c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11a0: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x11a4: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x11a8: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11ac: 0x8fc40048  lw          $a0, 0x48($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x11b0: 0x3c0500ff  lui         $a1, 0xFF
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)255 << 16));
    // 0x11b4: 0x852024  and         $a0, $a0, $a1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11b8: 0x42c02  srl         $a1, $a0, 16
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x11bc: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x11c0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x11c4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x11c8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x11cc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x11d0: 0x0  nop
    // NOP
    // 0x11d4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11d8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x11dc: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x11e0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11e4: 0x8fc40048  lw          $a0, 0x48($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x11e8: 0x3c05ff00  lui         $a1, 0xFF00
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x11ec: 0x852024  and         $a0, $a0, $a1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11f0: 0x42e02  srl         $a1, $a0, 24
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x11f4: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x11f8: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x11fc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1200: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1204: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1208: 0x0  nop
    // NOP
    // 0x120c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1210: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1214: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1218: 0x0  nop
    // NOP
    // 0x121c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1220: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1224: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1228: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x122c: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x122Cu;
    SET_GPR_U32(ctx, 31, 0x1234u);
    // 0x1230: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x122Cu, 0x1234u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1234u;
label_1234:
    // 0x1234: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1238: 0x8000490  j           func_001240
    ctx->pc = 0x1238u;
    // 0x123c: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1240u;
    goto label_1240;
    ctx->pc = 0x1240u;
label_1240:
    // 0x1240: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1244: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1248: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x124c: 0x3e00008  jr          $ra
    ctx->pc = 0x124Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1250: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x124Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1254u;
}


// Function: modsein_00001254
// Address: 0x1254 - 0x15a4
void modsein_00001254_0x1254(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00001254_0x1254");
#endif

    switch (ctx->pc) {
        case 0x135cu: goto label_135c;
        case 0x13e0u: goto label_13e0;
        case 0x1534u: goto label_1534;
        case 0x1554u: goto label_1554;
        case 0x1584u: goto label_1584;
        default: break;
    }

    ctx->pc = 0x1254u;

    // 0x1254: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1258: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x125c: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x1260: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1264: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x1268: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x126c: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x1270: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x1274: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1278: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x127c: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1280: 0x0  nop
    // NOP
    // 0x1284: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1288: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1288u;
    {
        const bool branch_taken_0x1288 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1288) {
            ctx->pc = 0x1298u;
            goto label_1298;
        }
    }
    ctx->pc = 0x1290u;
    // 0x1290: 0x80004fb  j           func_0013EC
    ctx->pc = 0x1290u;
    // 0x1294: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x13ECu;
    goto label_13ec;
    ctx->pc = 0x1298u;
label_1298:
    // 0x1298: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x129c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x12a0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12a4: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x12a8: 0x0  nop
    // NOP
    // 0x12ac: 0x348500b0  ori         $a1, $a0, 0xB0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)176);
    // 0x12b0: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x12b4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12b8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x12bc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x12c0: 0x0  nop
    // NOP
    // 0x12c4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12c8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x12cc: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x12d0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12d4: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x12d8: 0x0  nop
    // NOP
    // 0x12dc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x12e0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12e4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x12e8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x12ec: 0x0  nop
    // NOP
    // 0x12f0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12f4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x12f8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x12fc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1300: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x1304: 0x0  nop
    // NOP
    // 0x1308: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x130c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1310: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1314: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1318: 0x0  nop
    // NOP
    // 0x131c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1320: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1324: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1328: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x132c: 0x24040007  addiu       $a0, $zero, 0x7
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1330: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1334: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1338: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x133c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1340: 0x0  nop
    // NOP
    // 0x1344: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1348: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x134c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1350: 0x8fc40050  lw          $a0, 0x50($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1354: 0xc000094  jal         func_000250
    ctx->pc = 0x1354u;
    SET_GPR_U32(ctx, 31, 0x135Cu);
    // 0x1358: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x1354u, 0x135Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x135Cu;
label_135c:
    // 0x135c: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1360: 0x0  nop
    // NOP
    // 0x1364: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1368: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x136c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1370: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1374: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1378: 0x0  nop
    // NOP
    // 0x137c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1380: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1384: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1388: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x138c: 0x0  nop
    // NOP
    // 0x1390: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1394: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1398: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x139c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13a0: 0x0  nop
    // NOP
    // 0x13a4: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13a8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13ac: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x13b0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x13b4: 0x0  nop
    // NOP
    // 0x13b8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x13bc: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x13c0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x13c4: 0x0  nop
    // NOP
    // 0x13c8: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x13cc: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x13d0: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x13d4: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x13d8: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x13D8u;
    SET_GPR_U32(ctx, 31, 0x13E0u);
    // 0x13dc: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x13D8u, 0x13E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x13E0u;
label_13e0:
    // 0x13e0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x13e4: 0x80004fb  j           func_0013EC
    ctx->pc = 0x13E4u;
    // 0x13e8: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x13ECu;
    goto label_13ec;
    ctx->pc = 0x13ECu;
label_13ec:
    // 0x13ec: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x13f0: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x13f4: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13f8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x13fc: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x13F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1400u;
    // 0x1400: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1404: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x1408: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x140c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1410: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x1414: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x1418: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x141c: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x1420: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1424: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1428: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x142c: 0x0  nop
    // NOP
    // 0x1430: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1434: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1434u;
    {
        const bool branch_taken_0x1434 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1434) {
            ctx->pc = 0x1444u;
            goto label_1444;
        }
    }
    ctx->pc = 0x143Cu;
    // 0x143c: 0x8000564  j           func_001590
    ctx->pc = 0x143Cu;
    // 0x1440: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1590u;
    goto label_1590;
    ctx->pc = 0x1444u;
label_1444:
    // 0x1444: 0x8fc20058  lw          $v0, 0x58($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1448: 0x2403000a  addiu       $v1, $zero, 0xA
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x144c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x144Cu;
    {
        const bool branch_taken_0x144c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x144c) {
            ctx->pc = 0x146Cu;
            goto label_146c;
        }
    }
    ctx->pc = 0x1454u;
    // 0x1454: 0x8fc20058  lw          $v0, 0x58($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1458: 0x2403000b  addiu       $v1, $zero, 0xB
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x145c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x145Cu;
    {
        const bool branch_taken_0x145c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x145c) {
            ctx->pc = 0x146Cu;
            goto label_146c;
        }
    }
    ctx->pc = 0x1464u;
    // 0x1464: 0x8000564  j           func_001590
    ctx->pc = 0x1464u;
    // 0x1468: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1590u;
    goto label_1590;
    ctx->pc = 0x146Cu;
label_146c:
    // 0x146c: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x1470: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1474: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1478: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x147c: 0x0  nop
    // NOP
    // 0x1480: 0x348500b0  ori         $a1, $a0, 0xB0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)176);
    // 0x1484: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1488: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x148c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1490: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1494: 0x0  nop
    // NOP
    // 0x1498: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x149c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x14a0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x14a4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a8: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x14ac: 0x0  nop
    // NOP
    // 0x14b0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x14b4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x14b8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x14bc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x14c0: 0x0  nop
    // NOP
    // 0x14c4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x14c8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x14cc: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x14d0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14d4: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x14d8: 0x0  nop
    // NOP
    // 0x14dc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x14e0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x14e4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x14e8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x14ec: 0x0  nop
    // NOP
    // 0x14f0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x14f4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x14f8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x14fc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1500: 0x93c40058  lbu         $a0, 0x58($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1504: 0x0  nop
    // NOP
    // 0x1508: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x150c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1510: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1514: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1518: 0x0  nop
    // NOP
    // 0x151c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1520: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1524: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1528: 0x8fc40050  lw          $a0, 0x50($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x152c: 0xc000094  jal         func_000250
    ctx->pc = 0x152Cu;
    SET_GPR_U32(ctx, 31, 0x1534u);
    // 0x1530: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x152Cu, 0x1534u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1534u;
label_1534:
    // 0x1534: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1538: 0x0  nop
    // NOP
    // 0x153c: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1540: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1544: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1548: 0x8fc40054  lw          $a0, 0x54($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x154c: 0xc000094  jal         func_000250
    ctx->pc = 0x154Cu;
    SET_GPR_U32(ctx, 31, 0x1554u);
    // 0x1550: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x154Cu, 0x1554u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1554u;
label_1554:
    // 0x1554: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1558: 0x0  nop
    // NOP
    // 0x155c: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1560: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1564: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1568: 0x0  nop
    // NOP
    // 0x156c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1570: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1574: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1578: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x157c: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x157Cu;
    SET_GPR_U32(ctx, 31, 0x1584u);
    // 0x1580: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x157Cu, 0x1584u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1584u;
label_1584:
    // 0x1584: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1588: 0x8000564  j           func_001590
    ctx->pc = 0x1588u;
    // 0x158c: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1590u;
    goto label_1590;
    ctx->pc = 0x1590u;
label_1590:
    // 0x1590: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1594: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1598: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x159c: 0x3e00008  jr          $ra
    ctx->pc = 0x159Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x15a0: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x159Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x15A4u;
}


// Function: modsein_000015a4
// Address: 0x15a4 - 0x177c
void modsein_000015a4_0x15a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_000015a4_0x15a4");
#endif

    switch (ctx->pc) {
        case 0x16d8u: goto label_16d8;
        case 0x175cu: goto label_175c;
        default: break;
    }

    ctx->pc = 0x15a4u;

    // 0x15a4: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x15a8: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x15ac: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x15b0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x15b4: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x15b8: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x15bc: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x15c0: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x15c4: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x15c8: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x15cc: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x15d0: 0x0  nop
    // NOP
    // 0x15d4: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x15d8: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15D8u;
    {
        const bool branch_taken_0x15d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x15d8) {
            ctx->pc = 0x15E8u;
            goto label_15e8;
        }
    }
    ctx->pc = 0x15E0u;
    // 0x15e0: 0x80005da  j           func_001768
    ctx->pc = 0x15E0u;
    // 0x15e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1768u;
    goto label_1768;
    ctx->pc = 0x15E8u;
label_15e8:
    // 0x15e8: 0x8fc20058  lw          $v0, 0x58($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x15ec: 0x2403000c  addiu       $v1, $zero, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x15f0: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15F0u;
    {
        const bool branch_taken_0x15f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x15f0) {
            ctx->pc = 0x1610u;
            goto label_1610;
        }
    }
    ctx->pc = 0x15F8u;
    // 0x15f8: 0x8fc20058  lw          $v0, 0x58($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x15fc: 0x2403000d  addiu       $v1, $zero, 0xD
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1600: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1600u;
    {
        const bool branch_taken_0x1600 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1600) {
            ctx->pc = 0x1610u;
            goto label_1610;
        }
    }
    ctx->pc = 0x1608u;
    // 0x1608: 0x80005da  j           func_001768
    ctx->pc = 0x1608u;
    // 0x160c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1768u;
    goto label_1768;
    ctx->pc = 0x1610u;
label_1610:
    // 0x1610: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x1614: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1618: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x161c: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1620: 0x0  nop
    // NOP
    // 0x1624: 0x348500b0  ori         $a1, $a0, 0xB0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)176);
    // 0x1628: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x162c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1630: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1634: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1638: 0x0  nop
    // NOP
    // 0x163c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1640: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1644: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1648: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x164c: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1650: 0x0  nop
    // NOP
    // 0x1654: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1658: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x165c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1660: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1664: 0x0  nop
    // NOP
    // 0x1668: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x166c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1670: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1674: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1678: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x167c: 0x0  nop
    // NOP
    // 0x1680: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1684: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1688: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x168c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1690: 0x0  nop
    // NOP
    // 0x1694: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1698: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x169c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x16a0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16a4: 0x93c40058  lbu         $a0, 0x58($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x16a8: 0x0  nop
    // NOP
    // 0x16ac: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x16b0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x16b4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x16b8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x16bc: 0x0  nop
    // NOP
    // 0x16c0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16c4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x16c8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x16cc: 0x8fc40050  lw          $a0, 0x50($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x16d0: 0xc000094  jal         func_000250
    ctx->pc = 0x16D0u;
    SET_GPR_U32(ctx, 31, 0x16D8u);
    // 0x16d4: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x16D0u, 0x16D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x16D8u;
label_16d8:
    // 0x16d8: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x16dc: 0x0  nop
    // NOP
    // 0x16e0: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16e4: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x16e8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x16ec: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16f0: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x16f4: 0x0  nop
    // NOP
    // 0x16f8: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x16fc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1700: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1704: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1708: 0x0  nop
    // NOP
    // 0x170c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1710: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1714: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1718: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x171c: 0x0  nop
    // NOP
    // 0x1720: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1724: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1728: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x172c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1730: 0x0  nop
    // NOP
    // 0x1734: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1738: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x173c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1740: 0x0  nop
    // NOP
    // 0x1744: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1748: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x174c: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1750: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1754: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x1754u;
    SET_GPR_U32(ctx, 31, 0x175Cu);
    // 0x1758: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x1754u, 0x175Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x175Cu;
label_175c:
    // 0x175c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1760: 0x80005da  j           func_001768
    ctx->pc = 0x1760u;
    // 0x1764: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1768u;
    goto label_1768;
    ctx->pc = 0x1768u;
label_1768:
    // 0x1768: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x176c: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1770: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1774: 0x3e00008  jr          $ra
    ctx->pc = 0x1774u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1778: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1774u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x177Cu;
}


// Function: modsein_0000177c
// Address: 0x177c - 0x1964
void modsein_0000177c_0x177c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_0000177c_0x177c");
#endif

    switch (ctx->pc) {
        case 0x18b0u: goto label_18b0;
        case 0x1944u: goto label_1944;
        default: break;
    }

    ctx->pc = 0x177cu;

    // 0x177c: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1780: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x1784: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x1788: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x178c: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x1790: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x1794: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x1798: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x179c: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x17a0: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x17a4: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x17a8: 0x0  nop
    // NOP
    // 0x17ac: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x17b0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17B0u;
    {
        const bool branch_taken_0x17b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b0) {
            ctx->pc = 0x17C0u;
            goto label_17c0;
        }
    }
    ctx->pc = 0x17B8u;
    // 0x17b8: 0x8000654  j           func_001950
    ctx->pc = 0x17B8u;
    // 0x17bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1950u;
    goto label_1950;
    ctx->pc = 0x17C0u;
label_17c0:
    // 0x17c0: 0x8fc20058  lw          $v0, 0x58($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x17c4: 0x2403000e  addiu       $v1, $zero, 0xE
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x17c8: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17C8u;
    {
        const bool branch_taken_0x17c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x17c8) {
            ctx->pc = 0x17E8u;
            goto label_17e8;
        }
    }
    ctx->pc = 0x17D0u;
    // 0x17d0: 0x8fc20058  lw          $v0, 0x58($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x17d4: 0x2403000f  addiu       $v1, $zero, 0xF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x17d8: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x17D8u;
    {
        const bool branch_taken_0x17d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x17d8) {
            ctx->pc = 0x17E8u;
            goto label_17e8;
        }
    }
    ctx->pc = 0x17E0u;
    // 0x17e0: 0x8000654  j           func_001950
    ctx->pc = 0x17E0u;
    // 0x17e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1950u;
    goto label_1950;
    ctx->pc = 0x17E8u;
label_17e8:
    // 0x17e8: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x17ec: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x17f0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17f4: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x17f8: 0x0  nop
    // NOP
    // 0x17fc: 0x348500b0  ori         $a1, $a0, 0xB0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)176);
    // 0x1800: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1804: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1808: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x180c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1810: 0x0  nop
    // NOP
    // 0x1814: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1818: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x181c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1820: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1824: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1828: 0x0  nop
    // NOP
    // 0x182c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1830: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1834: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1838: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x183c: 0x0  nop
    // NOP
    // 0x1840: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1844: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1848: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x184c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1850: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x1854: 0x0  nop
    // NOP
    // 0x1858: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x185c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1860: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1864: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1868: 0x0  nop
    // NOP
    // 0x186c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1870: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1874: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1878: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x187c: 0x93c40058  lbu         $a0, 0x58($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1880: 0x0  nop
    // NOP
    // 0x1884: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1888: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x188c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1890: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1894: 0x0  nop
    // NOP
    // 0x1898: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x189c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x18a0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x18a4: 0x8fc40050  lw          $a0, 0x50($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x18a8: 0xc000094  jal         func_000250
    ctx->pc = 0x18A8u;
    SET_GPR_U32(ctx, 31, 0x18B0u);
    // 0x18ac: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x18A8u, 0x18B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18B0u;
label_18b0:
    // 0x18b0: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x18b4: 0x0  nop
    // NOP
    // 0x18b8: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18bc: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x18c0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x18c4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18c8: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x18cc: 0x0  nop
    // NOP
    // 0x18d0: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x18d4: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18d8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x18dc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x18e0: 0x0  nop
    // NOP
    // 0x18e4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x18e8: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x18ec: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x18f0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18f4: 0x8fc50054  lw          $a1, 0x54($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x18f8: 0x0  nop
    // NOP
    // 0x18fc: 0x30a4ff00  andi        $a0, $a1, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x1900: 0x42a02  srl         $a1, $a0, 8
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1904: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1908: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x190c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1910: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1914: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1918: 0x0  nop
    // NOP
    // 0x191c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1920: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1924: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1928: 0x0  nop
    // NOP
    // 0x192c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1930: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1934: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1938: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x193c: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x193Cu;
    SET_GPR_U32(ctx, 31, 0x1944u);
    // 0x1940: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x193Cu, 0x1944u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1944u;
label_1944:
    // 0x1944: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1948: 0x8000654  j           func_001950
    ctx->pc = 0x1948u;
    // 0x194c: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1950u;
    goto label_1950;
    ctx->pc = 0x1950u;
label_1950:
    // 0x1950: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1954: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1958: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x195c: 0x3e00008  jr          $ra
    ctx->pc = 0x195Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1960: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x195Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1964u;
}


// Function: modsein_00001964
// Address: 0x1964 - 0x1b70
void modsein_00001964_0x1964(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00001964_0x1964");
#endif

    switch (ctx->pc) {
        case 0x1ab8u: goto label_1ab8;
        case 0x1b50u: goto label_1b50;
        default: break;
    }

    ctx->pc = 0x1964u;

    // 0x1964: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1968: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x196c: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x1970: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1974: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x1978: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x197c: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x1980: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x1984: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1988: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x198c: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1990: 0x0  nop
    // NOP
    // 0x1994: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1998: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1998u;
    {
        const bool branch_taken_0x1998 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1998) {
            ctx->pc = 0x19A8u;
            goto label_19a8;
        }
    }
    ctx->pc = 0x19A0u;
    // 0x19a0: 0x80006d7  j           func_001B5C
    ctx->pc = 0x19A0u;
    // 0x19a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1B5Cu;
    goto label_1b5c;
    ctx->pc = 0x19A8u;
label_19a8:
    // 0x19a8: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x19ac: 0x24030010  addiu       $v1, $zero, 0x10
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19b0: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x19B0u;
    {
        const bool branch_taken_0x19b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x19b0) {
            ctx->pc = 0x19E0u;
            goto label_19e0;
        }
    }
    ctx->pc = 0x19B8u;
    // 0x19b8: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x19bc: 0x24030011  addiu       $v1, $zero, 0x11
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x19c0: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x19C0u;
    {
        const bool branch_taken_0x19c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x19c0) {
            ctx->pc = 0x19E0u;
            goto label_19e0;
        }
    }
    ctx->pc = 0x19C8u;
    // 0x19c8: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x19cc: 0x24030012  addiu       $v1, $zero, 0x12
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x19d0: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D0u;
    {
        const bool branch_taken_0x19d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x19d0) {
            ctx->pc = 0x19E0u;
            goto label_19e0;
        }
    }
    ctx->pc = 0x19D8u;
    // 0x19d8: 0x80006d7  j           func_001B5C
    ctx->pc = 0x19D8u;
    // 0x19dc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1B5Cu;
    goto label_1b5c;
    ctx->pc = 0x19E0u;
label_19e0:
    // 0x19e0: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x19e4: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x19e8: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x19ec: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x19f0: 0x0  nop
    // NOP
    // 0x19f4: 0x348500b0  ori         $a1, $a0, 0xB0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)176);
    // 0x19f8: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x19fc: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a00: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a04: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1a08: 0x0  nop
    // NOP
    // 0x1a0c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a10: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1a14: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1a18: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a1c: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1a20: 0x0  nop
    // NOP
    // 0x1a24: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a28: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a2c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a30: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1a34: 0x0  nop
    // NOP
    // 0x1a38: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a3c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1a40: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1a44: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a48: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x1a4c: 0x0  nop
    // NOP
    // 0x1a50: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a54: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a58: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a5c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1a60: 0x0  nop
    // NOP
    // 0x1a64: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a68: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1a6c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1a70: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a74: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1a78: 0x0  nop
    // NOP
    // 0x1a7c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a80: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a84: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a88: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1a8c: 0x0  nop
    // NOP
    // 0x1a90: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a94: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1a98: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1a9c: 0x24030012  addiu       $v1, $zero, 0x12
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1aa0: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1AA0u;
    {
        const bool branch_taken_0x1aa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1aa0) {
            ctx->pc = 0x1ACCu;
            goto label_1acc;
        }
    }
    ctx->pc = 0x1AA8u;
    // 0x1aa8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1aac: 0x8fc40050  lw          $a0, 0x50($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1ab0: 0xc000094  jal         func_000250
    ctx->pc = 0x1AB0u;
    SET_GPR_U32(ctx, 31, 0x1AB8u);
    // 0x1ab4: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x1AB0u, 0x1AB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AB8u;
label_1ab8:
    // 0x1ab8: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1abc: 0x0  nop
    // NOP
    // 0x1ac0: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1ac4: 0x80006cc  j           func_001B30
    ctx->pc = 0x1AC4u;
    // 0x1ac8: 0xafc2002c  sw          $v0, 0x2C($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    ctx->pc = 0x1B30u;
    goto label_1b30;
    ctx->pc = 0x1ACCu;
label_1acc:
    // 0x1acc: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1ad0: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ad4: 0x93c40050  lbu         $a0, 0x50($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1ad8: 0x0  nop
    // NOP
    // 0x1adc: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ae0: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ae4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1ae8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1aec: 0x0  nop
    // NOP
    // 0x1af0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1af4: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1af8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1afc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b00: 0x8fc50050  lw          $a1, 0x50($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1b04: 0x0  nop
    // NOP
    // 0x1b08: 0x30a4ff00  andi        $a0, $a1, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x1b0c: 0x42a02  srl         $a1, $a0, 8
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1b10: 0xa02021  addu        $a0, $a1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x1b14: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b18: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b1c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1b20: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1b24: 0x0  nop
    // NOP
    // 0x1b28: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b2c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
label_1b30:
    // 0x1b30: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1b34: 0x0  nop
    // NOP
    // 0x1b38: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1b3c: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1b40: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1b44: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1b48: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x1B48u;
    SET_GPR_U32(ctx, 31, 0x1B50u);
    // 0x1b4c: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x1B48u, 0x1B50u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B50u;
label_1b50:
    // 0x1b50: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1b54: 0x80006d7  j           func_001B5C
    ctx->pc = 0x1B54u;
    // 0x1b58: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1B5Cu;
    goto label_1b5c;
    ctx->pc = 0x1B5Cu;
label_1b5c:
    // 0x1b5c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1b60: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1b64: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b68: 0x3e00008  jr          $ra
    ctx->pc = 0x1B68u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1b6c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
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


// Function: modsein_00001b70
// Address: 0x1b70 - 0x1df4
void modsein_00001b70_0x1b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00001b70_0x1b70");
#endif

    switch (ctx->pc) {
        case 0x1cc4u: goto label_1cc4;
        case 0x1d4cu: goto label_1d4c;
        default: break;
    }

    ctx->pc = 0x1b70u;

    // 0x1b70: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x1b74: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x1b78: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x1b7c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1b80: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x1b84: 0xafc5003c  sw          $a1, 0x3C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 5));
    // 0x1b88: 0xafc60040  sw          $a2, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 6));
    // 0x1b8c: 0xafc70044  sw          $a3, 0x44($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 7));
    // 0x1b90: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0x1b94: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1b98: 0x8fc20044  lw          $v0, 0x44($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1b9c: 0x0  nop
    // NOP
    // 0x1ba0: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1ba4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA4u;
    {
        const bool branch_taken_0x1ba4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ba4) {
            ctx->pc = 0x1BB4u;
            goto label_1bb4;
        }
    }
    ctx->pc = 0x1BACu;
    // 0x1bac: 0x8000756  j           func_001D58
    ctx->pc = 0x1BACu;
    // 0x1bb0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1D58u;
    goto label_1d58;
    ctx->pc = 0x1BB4u;
label_1bb4:
    // 0x1bb4: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1bb8: 0x24030020  addiu       $v1, $zero, 0x20
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1bbc: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1BBCu;
    {
        const bool branch_taken_0x1bbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bbc) {
            ctx->pc = 0x1BECu;
            goto label_1bec;
        }
    }
    ctx->pc = 0x1BC4u;
    // 0x1bc4: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1bc8: 0x24030021  addiu       $v1, $zero, 0x21
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1bcc: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BCCu;
    {
        const bool branch_taken_0x1bcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bcc) {
            ctx->pc = 0x1BECu;
            goto label_1bec;
        }
    }
    ctx->pc = 0x1BD4u;
    // 0x1bd4: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1bd8: 0x24030022  addiu       $v1, $zero, 0x22
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1bdc: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BDCu;
    {
        const bool branch_taken_0x1bdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bdc) {
            ctx->pc = 0x1BECu;
            goto label_1bec;
        }
    }
    ctx->pc = 0x1BE4u;
    // 0x1be4: 0x8000756  j           func_001D58
    ctx->pc = 0x1BE4u;
    // 0x1be8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x1D58u;
    goto label_1d58;
    ctx->pc = 0x1BECu;
label_1bec:
    // 0x1bec: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
    // 0x1bf0: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1bf4: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bf8: 0x93c40044  lbu         $a0, 0x44($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1bfc: 0x0  nop
    // NOP
    // 0x1c00: 0x348500b0  ori         $a1, $a0, 0xB0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)176);
    // 0x1c04: 0xa0650000  sb          $a1, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1c08: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c0c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1c10: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1c14: 0x0  nop
    // NOP
    // 0x1c18: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c1c: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1c20: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1c24: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c28: 0x93c40048  lbu         $a0, 0x48($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 72)));
    // 0x1c2c: 0x0  nop
    // NOP
    // 0x1c30: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c34: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c38: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1c3c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1c40: 0x0  nop
    // NOP
    // 0x1c44: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c48: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1c4c: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1c50: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c54: 0x93c4004c  lbu         $a0, 0x4C($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x1c58: 0x0  nop
    // NOP
    // 0x1c5c: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c60: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c64: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1c68: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1c6c: 0x0  nop
    // NOP
    // 0x1c70: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c74: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1c78: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1c7c: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c80: 0x93c40054  lbu         $a0, 0x54($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1c84: 0x0  nop
    // NOP
    // 0x1c88: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c8c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c90: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1c94: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1c98: 0x0  nop
    // NOP
    // 0x1c9c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca0: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1ca4: 0x8fc20054  lw          $v0, 0x54($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1ca8: 0x24030022  addiu       $v1, $zero, 0x22
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1cac: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1CACu;
    {
        const bool branch_taken_0x1cac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1cac) {
            ctx->pc = 0x1CD8u;
            goto label_1cd8;
        }
    }
    ctx->pc = 0x1CB4u;
    // 0x1cb4: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1cb8: 0x8fc40050  lw          $a0, 0x50($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1cbc: 0xc000094  jal         func_000250
    ctx->pc = 0x1CBCu;
    SET_GPR_U32(ctx, 31, 0x1CC4u);
    // 0x1cc0: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x250u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x250u, 0x1CBCu, 0x1CC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1CC4u;
label_1cc4:
    // 0x1cc4: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1cc8: 0x0  nop
    // NOP
    // 0x1ccc: 0x621021  addu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1cd0: 0x800074b  j           func_001D2C
    ctx->pc = 0x1CD0u;
    // 0x1cd4: 0xafc2002c  sw          $v0, 0x2C($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    ctx->pc = 0x1D2Cu;
    goto label_1d2c;
    ctx->pc = 0x1CD8u;
label_1cd8:
    // 0x1cd8: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1cdc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ce0: 0x93c40050  lbu         $a0, 0x50($fp)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1ce4: 0x0  nop
    // NOP
    // 0x1ce8: 0xa0640000  sb          $a0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1cec: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cf0: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1cf4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1cf8: 0x0  nop
    // NOP
    // 0x1cfc: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d00: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
    // 0x1d04: 0x27c20028  addiu       $v0, $fp, 0x28
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 40));
    // 0x1d08: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d0c: 0x0  nop
    // NOP
    // 0x1d10: 0xa0600000  sb          $zero, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d14: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1d18: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1d1c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1d20: 0x0  nop
    // NOP
    // 0x1d24: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d28: 0xafc3002c  sw          $v1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
label_1d2c:
    // 0x1d2c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1d30: 0x0  nop
    // NOP
    // 0x1d34: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x1d38: 0x8fc40038  lw          $a0, 0x38($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1d3c: 0x8fc5003c  lw          $a1, 0x3C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1d40: 0x8fc60040  lw          $a2, 0x40($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1d44: 0xc0000fc  jal         func_0003F0
    ctx->pc = 0x1D44u;
    SET_GPR_U32(ctx, 31, 0x1D4Cu);
    // 0x1d48: 0x27c70018  addiu       $a3, $fp, 0x18 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    ctx->pc = 0x3F0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3F0u, 0x1D44u, 0x1D4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D4Cu;
label_1d4c:
    // 0x1d4c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1d50: 0x8000756  j           func_001D58
    ctx->pc = 0x1D50u;
    // 0x1d54: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1D58u;
    goto label_1d58;
    ctx->pc = 0x1D58u;
label_1d58:
    // 0x1d58: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1d5c: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1d60: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d64: 0x3e00008  jr          $ra
    ctx->pc = 0x1D64u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d68: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
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
    // 0x1d6c: 0x0  nop
    // NOP
    // 0x1d70: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0x1D70 raw=0x41C00000");
    // 0x1d74: 0x0  nop
    // NOP
    // 0x1d78: 0x101  .word       0x00000101                   # INVALID     $zero, $zero, 0x101 # 00000000 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1 at 0x1D78 raw=0x00000101");
    // 0x1d7c: 0x73646f6d  .word       0x73646F6D                   # INVALID     $k1, $a0, 0x6F6D # 00000000 <InstrIdType: R5900_MMI>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x1D7C raw=0x73646F6D");
    // 0x1d80: 0x6e6965  .word       0x006E6965                   # or          $t5, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 3) | GPR_U64(ctx, 14));
    // 0x1d84: 0x0  nop
    // NOP
    // 0x1d88: 0x1dd8  .word       0x00001DD8                   # mult        $v1, $zero, $zero # 000005C0 <InstrIdType: R5900_SPECIAL>
    { int64_t result = (int64_t)GPR_S32(ctx, 0) * (int64_t)GPR_S32(ctx, 0); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d8c: 0x1dd8  .word       0x00001DD8                   # mult        $v1, $zero, $zero # 000005C0 <InstrIdType: R5900_SPECIAL>
    { int64_t result = (int64_t)GPR_S32(ctx, 0) * (int64_t)GPR_S32(ctx, 0); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d90: 0x1dd8  .word       0x00001DD8                   # mult        $v1, $zero, $zero # 000005C0 <InstrIdType: R5900_SPECIAL>
    { int64_t result = (int64_t)GPR_S32(ctx, 0) * (int64_t)GPR_S32(ctx, 0); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d94: 0x70  tge         $zero, $zero, 1
    ctx->pc = 0x1d94u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x1d98: 0x200  sll         $zero, $zero, 8
    
    // 0x1d9c: 0x228  .word       0x00000228                   # mfsa        $zero # 00000200 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 0, ctx->sa);
    // 0x1da0: 0x664  .word       0x00000664                   # and         $zero, $zero, $zero # 00000640 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
    // 0x1da4: 0x3f0  tge         $zero, $zero, 15
    ctx->pc = 0x1da4u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x1da8: 0x828  mfsa        $at
    SET_GPR_U32(ctx, 1, ctx->sa);
    // 0x1dac: 0x9e0  .word       0x000009E0                   # add         $at, $zero, $zero # 000001C0 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0x1dacu;
    {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 1, (int32_t)result);     } }
    // 0x1db0: 0x1254  .word       0x00001254                   # dsllv       $v0, $zero, $zero # 00000240 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
    // 0x1db4: 0x15a4  .word       0x000015A4                   # and         $v0, $zero, $zero # 00000580 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
    // 0x1db8: 0x177c  dsll32      $v0, $zero, 29
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) << (32 + 29));
    // 0x1dbc: 0x1964  .word       0x00001964                   # and         $v1, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
    // 0x1dc0: 0x1b70  tge         $zero, $zero, 109
    ctx->pc = 0x1dc0u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x1dc4: 0xf38  dsll        $at, $zero, 28
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << 28);
    // 0x1dc8: 0xff0  tge         $zero, $zero, 63
    ctx->pc = 0x1dc8u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x1dcc: 0xbb0  tge         $zero, $zero, 46
    ctx->pc = 0x1dccu;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
    // 0x1dd0: 0xd68  .word       0x00000D68                   # mfsa        $at # 00000540 <InstrIdType: R5900_SPECIAL>
    SET_GPR_U32(ctx, 1, ctx->sa);
    // 0x1dd4: 0x0  nop
    // NOP
    // 0x1dd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DD8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1DD8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DE0u;
    // 0x1de0: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x1DE0 raw=0x41E00000");
    // 0x1de4: 0x0  nop
    // NOP
    // 0x1de8: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
    // 0x1dec: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x1DEC raw=0x72746E69");
    // 0x1df0: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: modsein_00001df4
// Address: 0x1df4 - 0x1dfc
void modsein_00001df4_0x1df4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00001df4_0x1df4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: modsein_00001dfc
// Address: 0x1dfc - 0x1e20
void modsein_00001dfc_0x1dfc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("modsein_00001dfc_0x1dfc");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


