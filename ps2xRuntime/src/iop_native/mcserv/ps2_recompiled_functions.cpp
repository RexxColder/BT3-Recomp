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

// Function: mcserv_00000040
// Address: 0x40 - 0xfa4
void mcserv_00000040_0x40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00000040_0x40");
#endif

    switch (ctx->pc) {
        case 0x6cu: goto label_6c;
        case 0x84u: goto label_84;
        case 0x98u: goto label_98;
        case 0xacu: goto label_ac;
        case 0xc4u: goto label_c4;
        case 0xe8u: goto label_e8;
        case 0x124u: goto label_124;
        case 0x138u: goto label_138;
        case 0x178u: goto label_178;
        case 0x188u: goto label_188;
        case 0x194u: goto label_194;
        case 0x1b4u: goto label_1b4;
        case 0x1c4u: goto label_1c4;
        case 0x1dcu: goto label_1dc;
        case 0x1e4u: goto label_1e4;
        case 0x230u: goto label_230;
        case 0x23cu: goto label_23c;
        case 0x258u: goto label_258;
        case 0x26cu: goto label_26c;
        case 0x2a0u: goto label_2a0;
        case 0x2a8u: goto label_2a8;
        case 0x2b8u: goto label_2b8;
        case 0x2c0u: goto label_2c0;
        case 0x2c8u: goto label_2c8;
        case 0x2dcu: goto label_2dc;
        case 0x30cu: goto label_30c;
        case 0x314u: goto label_314;
        case 0x338u: goto label_338;
        case 0x340u: goto label_340;
        case 0x440u: goto label_440;
        case 0x45cu: goto label_45c;
        case 0x478u: goto label_478;
        case 0x490u: goto label_490;
        case 0x4a8u: goto label_4a8;
        case 0x4c0u: goto label_4c0;
        case 0x4d8u: goto label_4d8;
        case 0x4f0u: goto label_4f0;
        case 0x508u: goto label_508;
        case 0x520u: goto label_520;
        case 0x538u: goto label_538;
        case 0x550u: goto label_550;
        case 0x568u: goto label_568;
        case 0x580u: goto label_580;
        case 0x598u: goto label_598;
        case 0x5b0u: goto label_5b0;
        case 0x5c8u: goto label_5c8;
        case 0x5e0u: goto label_5e0;
        case 0x5f8u: goto label_5f8;
        case 0x608u: goto label_608;
        case 0x610u: goto label_610;
        case 0x618u: goto label_618;
        case 0x64cu: goto label_64c;
        case 0x684u: goto label_684;
        case 0x6acu: goto label_6ac;
        case 0x6dcu: goto label_6dc;
        case 0x700u: goto label_700;
        case 0x730u: goto label_730;
        case 0x7f0u: goto label_7f0;
        case 0x800u: goto label_800;
        case 0x83cu: goto label_83c;
        case 0x85cu: goto label_85c;
        case 0x894u: goto label_894;
        case 0x8d0u: goto label_8d0;
        case 0x8dcu: goto label_8dc;
        case 0x8e8u: goto label_8e8;
        case 0x91cu: goto label_91c;
        case 0x958u: goto label_958;
        case 0x964u: goto label_964;
        case 0x970u: goto label_970;
        case 0x978u: goto label_978;
        case 0x988u: goto label_988;
        case 0x9fcu: goto label_9fc;
        case 0xa14u: goto label_a14;
        case 0xa34u: goto label_a34;
        case 0xa64u: goto label_a64;
        case 0xa74u: goto label_a74;
        case 0xb2cu: goto label_b2c;
        case 0xb58u: goto label_b58;
        case 0xb74u: goto label_b74;
        case 0xba0u: goto label_ba0;
        case 0xbacu: goto label_bac;
        case 0xbb8u: goto label_bb8;
        case 0xbe0u: goto label_be0;
        case 0xbe8u: goto label_be8;
        case 0xbf8u: goto label_bf8;
        case 0xc58u: goto label_c58;
        case 0xc7cu: goto label_c7c;
        case 0xc88u: goto label_c88;
        case 0xc94u: goto label_c94;
        case 0xc9cu: goto label_c9c;
        case 0xcacu: goto label_cac;
        case 0xce4u: goto label_ce4;
        case 0xd10u: goto label_d10;
        case 0xd48u: goto label_d48;
        case 0xd68u: goto label_d68;
        case 0xda4u: goto label_da4;
        case 0xdf0u: goto label_df0;
        case 0xe1cu: goto label_e1c;
        case 0xe28u: goto label_e28;
        case 0xe34u: goto label_e34;
        case 0xe3cu: goto label_e3c;
        case 0xe4cu: goto label_e4c;
        case 0xe94u: goto label_e94;
        case 0xec4u: goto label_ec4;
        case 0xee8u: goto label_ee8;
        case 0xf2cu: goto label_f2c;
        case 0xf48u: goto label_f48;
        case 0xf7cu: goto label_f7c;
        default: break;
    }

    ctx->pc = 0x40u;

    // 0x40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x44: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x48: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x4c: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x50: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x54: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
    // 0x58: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x5c: 0x6610005  bgez        $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x5Cu;
    {
        const bool branch_taken_0x5c = (GPR_S32(ctx, 19) >= 0);
        // 0x60: 0xafb1002c  sw          $s1, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
        if (branch_taken_0x5c) {
            ctx->pc = 0x74u;
            goto label_74;
        }
    }
    ctx->pc = 0x64u;
    // 0x64: 0xc000056  jal         func_000158
    ctx->pc = 0x64u;
    SET_GPR_U32(ctx, 31, 0x6Cu);
    // 0x68: 0x132023  negu        $a0, $s3 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
    ctx->pc = 0x158u;
    goto label_158;
    ctx->pc = 0x6Cu;
label_6c:
    // 0x6c: 0x800004f  j           func_00013C
    ctx->pc = 0x6Cu;
    ctx->pc = 0x13Cu;
    goto label_13c;
    ctx->pc = 0x74u;
label_74:
    // 0x74: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x78: 0x24840000  addiu       $a0, $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
    // 0x7c: 0xc0003e9  jal         func_000FA4
    ctx->pc = 0x7Cu;
    SET_GPR_U32(ctx, 31, 0x84u);
    ctx->pc = 0xFA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFA4u, 0x7Cu, 0x84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x84u;
label_84:
    // 0x84: 0x1440002d  bnez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x84u;
    {
        const bool branch_taken_0x84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x88: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x84) {
            ctx->pc = 0x13Cu;
            goto label_13c;
        }
    }
    ctx->pc = 0x8Cu;
    // 0x8c: 0x24110068  addiu       $s1, $zero, 0x68
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x90: 0x1a600019  blez        $s3, . + 4 + (0x19 << 2)
    ctx->pc = 0x90u;
    {
        const bool branch_taken_0x90 = (GPR_S32(ctx, 19) <= 0);
        // 0x94: 0x9021  addu        $s2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x90) {
            ctx->pc = 0xF8u;
            goto label_f8;
        }
    }
    ctx->pc = 0x98u;
label_98:
    // 0x98: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x9c: 0x24841248  addiu       $a0, $a0, 0x1248
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4680));
    // 0xa0: 0x8e050000  lw          $a1, 0x0($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa4: 0xc000403  jal         func_00100C
    ctx->pc = 0xA4u;
    SET_GPR_U32(ctx, 31, 0xACu);
    // 0xa8: 0x24060006  addiu       $a2, $zero, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    ctx->pc = 0x100Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x100Cu, 0xA4u, 0xACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xACu;
label_ac:
    // 0xac: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0xACu;
    {
        const bool branch_taken_0xac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xb0: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0xac) {
            ctx->pc = 0xE8u;
            goto label_e8;
        }
    }
    ctx->pc = 0xB4u;
    // 0xb4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xb8: 0x2406000a  addiu       $a2, $zero, 0xA
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0xbc: 0xc000405  jal         func_001014
    ctx->pc = 0xBCu;
    SET_GPR_U32(ctx, 31, 0xC4u);
    // 0xc0: 0x24840006  addiu       $a0, $a0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6));
    ctx->pc = 0x1014u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1014u, 0xBCu, 0xC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC4u;
label_c4:
    // 0xc4: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xc8: 0x2622fff7  addiu       $v0, $s1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967287));
    // 0xcc: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
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
    // 0xd8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xdc: 0x24841250  addiu       $a0, $a0, 0x1250
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4688));
    // 0xe0: 0xc00040e  jal         func_001038
    ctx->pc = 0xE0u;
    SET_GPR_U32(ctx, 31, 0xE8u);
    // 0xe4: 0x24110068  addiu       $s1, $zero, 0x68 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    ctx->pc = 0x1038u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1038u, 0xE0u, 0xE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE8u;
label_e8:
    // 0xe8: 0x26520001  addiu       $s2, $s2, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0xec: 0x253102a  slt         $v0, $s2, $s3
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0xf0: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0xF0u;
    {
        const bool branch_taken_0xf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xf4: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        if (branch_taken_0xf0) {
            ctx->pc = 0x98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_98;
        }
    }
    ctx->pc = 0xF8u;
label_f8:
    // 0xf8: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xfc: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
    // 0x100: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x104: 0x24021000  addiu       $v0, $zero, 0x1000
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x108: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x10c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x110: 0x24420280  addiu       $v0, $v0, 0x280
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 640));
    // 0x114: 0xafb10020  sw          $s1, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 17));
    // 0x118: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x11c: 0xc00043b  jal         func_0010EC
    ctx->pc = 0x11Cu;
    SET_GPR_U32(ctx, 31, 0x124u);
    // 0x120: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    ctx->pc = 0x10ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10ECu, 0x11Cu, 0x124u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x124u;
label_124:
    // 0x124: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x128: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x12c: 0xac2436d8  sw          $a0, 0x36D8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 14040), GPR_U32(ctx, 4));
    // 0x130: 0xc00043f  jal         func_0010FC
    ctx->pc = 0x130u;
    SET_GPR_U32(ctx, 31, 0x138u);
    // 0x134: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x10FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10FCu, 0x130u, 0x138u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x138u;
label_138:
    // 0x138: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_13c:
    // 0x13c: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x140: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x144: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x14c: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x150: 0x3e00008  jr          $ra
    ctx->pc = 0x150u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x154: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
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
label_158:
    // 0x158: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x15c: 0x8c42373c  lw          $v0, 0x373C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 14140)));
    // 0x160: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x164: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x168: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x168u;
    {
        const bool branch_taken_0x168 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x16c: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x168) {
            ctx->pc = 0x1ECu;
            goto label_1ec;
        }
    }
    ctx->pc = 0x170u;
    // 0x170: 0xc0003f4  jal         func_000FD0
    ctx->pc = 0x170u;
    SET_GPR_U32(ctx, 31, 0x178u);
    // 0x174: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0xFD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD0u, 0x170u, 0x178u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x178u;
label_178:
    // 0x178: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x17c: 0x24840000  addiu       $a0, $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
    // 0x180: 0xc0003eb  jal         func_000FAC
    ctx->pc = 0x180u;
    SET_GPR_U32(ctx, 31, 0x188u);
    ctx->pc = 0xFACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFACu, 0x180u, 0x188u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x188u;
label_188:
    // 0x188: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18c: 0xc0003f6  jal         func_000FD8
    ctx->pc = 0x18Cu;
    SET_GPR_U32(ctx, 31, 0x194u);
    // 0x190: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xFD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD8u, 0x18Cu, 0x194u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x194u;
label_194:
    // 0x194: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194u;
    {
        const bool branch_taken_0x194 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x198: 0x2402ff2b  addiu       $v0, $zero, -0xD5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967083));
        if (branch_taken_0x194) {
            ctx->pc = 0x1A4u;
            goto label_1a4;
        }
    }
    ctx->pc = 0x19Cu;
    // 0x19c: 0x16020014  bne         $s0, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x19Cu;
    {
        const bool branch_taken_0x19c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        // 0x1a0: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x19c) {
            ctx->pc = 0x1F0u;
            goto label_1f0;
        }
    }
    ctx->pc = 0x1A4u;
label_1a4:
    // 0x1a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1a8: 0x8c8436d8  lw          $a0, 0x36D8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 14040)));
    // 0x1ac: 0xc000441  jal         func_001104
    ctx->pc = 0x1ACu;
    SET_GPR_U32(ctx, 31, 0x1B4u);
    ctx->pc = 0x1104u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1104u, 0x1ACu, 0x1B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B4u;
label_1b4:
    // 0x1b4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1b8: 0x8c8436d8  lw          $a0, 0x36D8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 14040)));
    // 0x1bc: 0xc00043d  jal         func_0010F4
    ctx->pc = 0x1BCu;
    SET_GPR_U32(ctx, 31, 0x1C4u);
    ctx->pc = 0x10F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10F4u, 0x1BCu, 0x1C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C4u;
label_1c4:
    // 0x1c4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c8: 0x248436f8  addiu       $a0, $a0, 0x36F8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14072));
    // 0x1cc: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x1d0: 0x261036e0  addiu       $s0, $s0, 0x36E0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 14048));
    // 0x1d4: 0xc000430  jal         func_0010C0
    ctx->pc = 0x1D4u;
    SET_GPR_U32(ctx, 31, 0x1DCu);
    // 0x1d8: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x10C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10C0u, 0x1D4u, 0x1DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DCu;
label_1dc:
    // 0x1dc: 0xc000432  jal         func_0010C8
    ctx->pc = 0x1DCu;
    SET_GPR_U32(ctx, 31, 0x1E4u);
    // 0x1e0: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x10C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10C8u, 0x1DCu, 0x1E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1E4u;
label_1e4:
    // 0x1e4: 0x800007c  j           func_0001F0
    ctx->pc = 0x1E4u;
    // 0x1e8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1F0u;
    goto label_1f0;
    ctx->pc = 0x1ECu;
label_1ec:
    // 0x1ec: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1f0:
    // 0x1f0: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1f4: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
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
    // 0x200: 0x27bdffa0  addiu       $sp, $sp, -0x60
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x204: 0xafb00058  sw          $s0, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
    // 0x208: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x20c: 0x2602fff7  addiu       $v0, $s0, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967287));
    // 0x210: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x214: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x214u;
    {
        const bool branch_taken_0x214 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x218: 0xafbf005c  sw          $ra, 0x5C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 31));
        if (branch_taken_0x214) {
            ctx->pc = 0x224u;
            goto label_224;
        }
    }
    ctx->pc = 0x21Cu;
    // 0x21c: 0x800009c  j           func_000270
    ctx->pc = 0x21Cu;
    // 0x220: 0x2402fe6d  addiu       $v0, $zero, -0x193 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966893));
    ctx->pc = 0x270u;
    goto label_270;
    ctx->pc = 0x224u;
label_224:
    // 0x224: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x228: 0xc000447  jal         func_00111C
    ctx->pc = 0x228u;
    SET_GPR_U32(ctx, 31, 0x230u);
    // 0x22c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x111Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x111Cu, 0x228u, 0x230u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x230u;
label_230:
    // 0x230: 0x2021  addu        $a0, $zero, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x234: 0xc000443  jal         func_00110C
    ctx->pc = 0x234u;
    SET_GPR_U32(ctx, 31, 0x23Cu);
    // 0x238: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x110Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x110Cu, 0x234u, 0x23Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23Cu;
label_23c:
    // 0x23c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x240: 0x8c8436d8  lw          $a0, 0x36D8($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 14040)));
    // 0x244: 0x0  nop
    // NOP
    // 0x248: 0x18800005  blez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x248u;
    {
        const bool branch_taken_0x248 = (GPR_S32(ctx, 4) <= 0);
        if (branch_taken_0x248) {
            ctx->pc = 0x260u;
            goto label_260;
        }
    }
    ctx->pc = 0x250u;
    // 0x250: 0xc000443  jal         func_00110C
    ctx->pc = 0x250u;
    SET_GPR_U32(ctx, 31, 0x258u);
    // 0x254: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x110Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x110Cu, 0x250u, 0x258u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x258u;
label_258:
    // 0x258: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x258u;
    {
        const bool branch_taken_0x258 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x258) {
            ctx->pc = 0x270u;
            goto label_270;
        }
    }
    ctx->pc = 0x260u;
label_260:
    // 0x260: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x264: 0xc000443  jal         func_00110C
    ctx->pc = 0x264u;
    SET_GPR_U32(ctx, 31, 0x26Cu);
    // 0x268: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x110Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x110Cu, 0x264u, 0x26Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26Cu;
label_26c:
    // 0x26c: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_270:
    // 0x270: 0x8fbf005c  lw          $ra, 0x5C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
    // 0x274: 0x8fb00058  lw          $s0, 0x58($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x278: 0x3e00008  jr          $ra
    ctx->pc = 0x278u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x27c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
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
    // 0x280: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x284: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x288: 0x248436c8  addiu       $a0, $a0, 0x36C8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14024));
    // 0x28c: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x290: 0x24060010  addiu       $a2, $zero, 0x10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x294: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x298: 0xc000401  jal         func_001004
    ctx->pc = 0x298u;
    SET_GPR_U32(ctx, 31, 0x2A0u);
    // 0x29c: 0xafb00020  sw          $s0, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
    ctx->pc = 0x1004u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1004u, 0x298u, 0x2A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A0u;
label_2a0:
    // 0x2a0: 0xc00041d  jal         func_001074
    ctx->pc = 0x2A0u;
    SET_GPR_U32(ctx, 31, 0x2A8u);
    ctx->pc = 0x1074u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1074u, 0x2A0u, 0x2A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2A8u;
label_2a8:
    // 0x2a8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2A8u;
    {
        const bool branch_taken_0x2a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2a8) {
            ctx->pc = 0x2B8u;
            goto label_2b8;
        }
    }
    ctx->pc = 0x2B0u;
    // 0x2b0: 0xc000417  jal         func_00105C
    ctx->pc = 0x2B0u;
    SET_GPR_U32(ctx, 31, 0x2B8u);
    ctx->pc = 0x105Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x105Cu, 0x2B0u, 0x2B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B8u;
label_2b8:
    // 0x2b8: 0xc000426  jal         func_001098
    ctx->pc = 0x2B8u;
    SET_GPR_U32(ctx, 31, 0x2C0u);
    // 0x2bc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1098u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1098u, 0x2B8u, 0x2C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C0u;
label_2c0:
    // 0x2c0: 0xc000445  jal         func_001114
    ctx->pc = 0x2C0u;
    SET_GPR_U32(ctx, 31, 0x2C8u);
    ctx->pc = 0x1114u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1114u, 0x2C0u, 0x2C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C8u;
label_2c8:
    // 0x2c8: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x2cc: 0x261036e0  addiu       $s0, $s0, 0x36E0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 14048));
    // 0x2d0: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x2d4: 0xc00042a  jal         func_0010A8
    ctx->pc = 0x2D4u;
    SET_GPR_U32(ctx, 31, 0x2DCu);
    // 0x2d8: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x10A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10A8u, 0x2D4u, 0x2DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DCu;
label_2dc:
    // 0x2dc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2e0: 0x248436f8  addiu       $a0, $a0, 0x36F8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14072));
    // 0x2e4: 0x3c058000  lui         $a1, 0x8000
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x2e8: 0x34a50400  ori         $a1, $a1, 0x400
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1024);
    // 0x2ec: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x2f0: 0x24c60324  addiu       $a2, $a2, 0x324
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 804));
    // 0x2f4: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x2f8: 0x24e732b0  addiu       $a3, $a3, 0x32B0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 12976));
    // 0x2fc: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x300: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x304: 0xc000428  jal         func_0010A0
    ctx->pc = 0x304u;
    SET_GPR_U32(ctx, 31, 0x30Cu);
    // 0x308: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x10A0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10A0u, 0x304u, 0x30Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30Cu;
label_30c:
    // 0x30c: 0xc00042c  jal         func_0010B0
    ctx->pc = 0x30Cu;
    SET_GPR_U32(ctx, 31, 0x314u);
    // 0x310: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x10B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10B0u, 0x30Cu, 0x314u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x314u;
label_314:
    // 0x314: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x318: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x31c: 0x3e00008  jr          $ra
    ctx->pc = 0x31Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x320: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x31Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x324u;
    // 0x324: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x328: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x32c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x330: 0xc000489  jal         func_001224
    ctx->pc = 0x330u;
    SET_GPR_U32(ctx, 31, 0x338u);
    // 0x334: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x1224u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1224u, 0x330u, 0x338u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x338u;
label_338:
    // 0x338: 0xc000454  jal         func_001150
    ctx->pc = 0x338u;
    SET_GPR_U32(ctx, 31, 0x340u);
    // 0x33c: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1150u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1150u, 0x338u, 0x340u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x340u;
label_340:
    // 0x340: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x344: 0x2402000d  addiu       $v0, $zero, 0xD
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x348: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x34c: 0xac23373c  sw          $v1, 0x373C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 14140), GPR_U32(ctx, 3));
    // 0x350: 0x12020063  beq         $s0, $v0, . + 4 + (0x63 << 2)
    ctx->pc = 0x350u;
    {
        const bool branch_taken_0x350 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x354: 0x2e02000e  sltiu       $v0, $s0, 0xE (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)14) ? 1 : 0);
        if (branch_taken_0x350) {
            ctx->pc = 0x4E0u;
            goto label_4e0;
        }
    }
    ctx->pc = 0x358u;
    // 0x358: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x358u;
    {
        const bool branch_taken_0x358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x35c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x358) {
            ctx->pc = 0x3BCu;
            goto label_3bc;
        }
    }
    ctx->pc = 0x360u;
    // 0x360: 0x12020059  beq         $s0, $v0, . + 4 + (0x59 << 2)
    ctx->pc = 0x360u;
    {
        const bool branch_taken_0x360 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x364: 0x2e020005  sltiu       $v0, $s0, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
        if (branch_taken_0x360) {
            ctx->pc = 0x4C8u;
            goto label_4c8;
        }
    }
    ctx->pc = 0x368u;
    // 0x368: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x368u;
    {
        const bool branch_taken_0x368 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x36c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x368) {
            ctx->pc = 0x390u;
            goto label_390;
        }
    }
    ctx->pc = 0x370u;
    // 0x370: 0x1202003d  beq         $s0, $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x370u;
    {
        const bool branch_taken_0x370 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x374: 0x2e020003  sltiu       $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        if (branch_taken_0x370) {
            ctx->pc = 0x468u;
            goto label_468;
        }
    }
    ctx->pc = 0x378u;
    // 0x378: 0x10400041  beqz        $v0, . + 4 + (0x41 << 2)
    ctx->pc = 0x378u;
    {
        const bool branch_taken_0x378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x378) {
            ctx->pc = 0x480u;
            goto label_480;
        }
    }
    ctx->pc = 0x380u;
    // 0x380: 0x12030069  beq         $s0, $v1, . + 4 + (0x69 << 2)
    ctx->pc = 0x380u;
    {
        const bool branch_taken_0x380 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x380) {
            ctx->pc = 0x528u;
            goto label_528;
        }
    }
    ctx->pc = 0x388u;
    // 0x388: 0x8000180  j           func_000600
    ctx->pc = 0x388u;
    ctx->pc = 0x600u;
    goto label_600;
    ctx->pc = 0x390u;
label_390:
    // 0x390: 0x24020006  addiu       $v0, $zero, 0x6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x394: 0x12020046  beq         $s0, $v0, . + 4 + (0x46 << 2)
    ctx->pc = 0x394u;
    {
        const bool branch_taken_0x394 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x398: 0x202102b  sltu        $v0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        if (branch_taken_0x394) {
            ctx->pc = 0x4B0u;
            goto label_4b0;
        }
    }
    ctx->pc = 0x39Cu;
    // 0x39c: 0x1440003e  bnez        $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x39Cu;
    {
        const bool branch_taken_0x39c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3a0: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        if (branch_taken_0x39c) {
            ctx->pc = 0x498u;
            goto label_498;
        }
    }
    ctx->pc = 0x3A4u;
    // 0x3a4: 0x1202006c  beq         $s0, $v0, . + 4 + (0x6C << 2)
    ctx->pc = 0x3A4u;
    {
        const bool branch_taken_0x3a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x3a8: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        if (branch_taken_0x3a4) {
            ctx->pc = 0x558u;
            goto label_558;
        }
    }
    ctx->pc = 0x3ACu;
    // 0x3ac: 0x12020070  beq         $s0, $v0, . + 4 + (0x70 << 2)
    ctx->pc = 0x3ACu;
    {
        const bool branch_taken_0x3ac = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x3ac) {
            ctx->pc = 0x570u;
            goto label_570;
        }
    }
    ctx->pc = 0x3B4u;
    // 0x3b4: 0x8000180  j           func_000600
    ctx->pc = 0x3B4u;
    ctx->pc = 0x600u;
    goto label_600;
    ctx->pc = 0x3BCu;
label_3bc:
    // 0x3bc: 0x24020012  addiu       $v0, $zero, 0x12
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x3c0: 0x12020077  beq         $s0, $v0, . + 4 + (0x77 << 2)
    ctx->pc = 0x3C0u;
    {
        const bool branch_taken_0x3c0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x3c4: 0x2e020013  sltiu       $v0, $s0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)19) ? 1 : 0);
        if (branch_taken_0x3c0) {
            ctx->pc = 0x5A0u;
            goto label_5a0;
        }
    }
    ctx->pc = 0x3C8u;
    // 0x3c8: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x3C8u;
    {
        const bool branch_taken_0x3c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3cc: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        if (branch_taken_0x3c8) {
            ctx->pc = 0x3F8u;
            goto label_3f8;
        }
    }
    ctx->pc = 0x3D0u;
    // 0x3d0: 0x1202005b  beq         $s0, $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x3D0u;
    {
        const bool branch_taken_0x3d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x3d4: 0x202102b  sltu        $v0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        if (branch_taken_0x3d0) {
            ctx->pc = 0x540u;
            goto label_540;
        }
    }
    ctx->pc = 0x3D8u;
    // 0x3d8: 0x1440006b  bnez        $v0, . + 4 + (0x6B << 2)
    ctx->pc = 0x3D8u;
    {
        const bool branch_taken_0x3d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3dc: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        if (branch_taken_0x3d8) {
            ctx->pc = 0x588u;
            goto label_588;
        }
    }
    ctx->pc = 0x3E0u;
    // 0x3e0: 0x12020045  beq         $s0, $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x3E0u;
    {
        const bool branch_taken_0x3e0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x3e4: 0x24020011  addiu       $v0, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        if (branch_taken_0x3e0) {
            ctx->pc = 0x4F8u;
            goto label_4f8;
        }
    }
    ctx->pc = 0x3E8u;
    // 0x3e8: 0x12020049  beq         $s0, $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x3E8u;
    {
        const bool branch_taken_0x3e8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x3e8) {
            ctx->pc = 0x510u;
            goto label_510;
        }
    }
    ctx->pc = 0x3F0u;
    // 0x3f0: 0x8000180  j           func_000600
    ctx->pc = 0x3F0u;
    ctx->pc = 0x600u;
    goto label_600;
    ctx->pc = 0x3F8u;
label_3f8:
    // 0x3f8: 0x24020015  addiu       $v0, $zero, 0x15
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x3fc: 0x1202007a  beq         $s0, $v0, . + 4 + (0x7A << 2)
    ctx->pc = 0x3FCu;
    {
        const bool branch_taken_0x3fc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x400: 0x2e020016  sltiu       $v0, $s0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)22) ? 1 : 0);
        if (branch_taken_0x3fc) {
            ctx->pc = 0x5E8u;
            goto label_5e8;
        }
    }
    ctx->pc = 0x404u;
    // 0x404: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x404u;
    {
        const bool branch_taken_0x404 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x408: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x404) {
            ctx->pc = 0x41Cu;
            goto label_41c;
        }
    }
    ctx->pc = 0x40Cu;
    // 0x40c: 0x12020070  beq         $s0, $v0, . + 4 + (0x70 << 2)
    ctx->pc = 0x40Cu;
    {
        const bool branch_taken_0x40c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x40c) {
            ctx->pc = 0x5D0u;
            goto label_5d0;
        }
    }
    ctx->pc = 0x414u;
    // 0x414: 0x8000180  j           func_000600
    ctx->pc = 0x414u;
    ctx->pc = 0x600u;
    goto label_600;
    ctx->pc = 0x41Cu;
label_41c:
    // 0x41c: 0x24020033  addiu       $v0, $zero, 0x33
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 51));
    // 0x420: 0x12020065  beq         $s0, $v0, . + 4 + (0x65 << 2)
    ctx->pc = 0x420u;
    {
        const bool branch_taken_0x420 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x424: 0x240200fe  addiu       $v0, $zero, 0xFE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
        if (branch_taken_0x420) {
            ctx->pc = 0x5B8u;
            goto label_5b8;
        }
    }
    ctx->pc = 0x428u;
    // 0x428: 0x16020075  bne         $s0, $v0, . + 4 + (0x75 << 2)
    ctx->pc = 0x428u;
    {
        const bool branch_taken_0x428 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x428) {
            ctx->pc = 0x600u;
            goto label_600;
        }
    }
    ctx->pc = 0x430u;
    // 0x430: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x434: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x438: 0xc00018e  jal         func_000638
    ctx->pc = 0x438u;
    SET_GPR_U32(ctx, 31, 0x440u);
    ctx->pc = 0x638u;
    goto label_638;
    ctx->pc = 0x440u;
label_440:
    // 0x440: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x444: 0x94631294  lhu         $v1, 0x1294($v1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 4756)));
    // 0x448: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x44c: 0x261012a0  addiu       $s0, $s0, 0x12A0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4768));
    // 0x450: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x454: 0xc000485  jal         func_001214
    ctx->pc = 0x454u;
    SET_GPR_U32(ctx, 31, 0x45Cu);
    // 0x458: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    ctx->pc = 0x1214u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1214u, 0x454u, 0x45Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x45Cu;
label_45c:
    // 0x45c: 0x94420004  lhu         $v0, 0x4($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x460: 0x8000180  j           func_000600
    ctx->pc = 0x460u;
    // 0x464: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    ctx->pc = 0x600u;
    goto label_600;
    ctx->pc = 0x468u;
label_468:
    // 0x468: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x46c: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x470: 0xc0001af  jal         func_0006BC
    ctx->pc = 0x470u;
    SET_GPR_U32(ctx, 31, 0x478u);
    ctx->pc = 0x6BCu;
    goto label_6bc;
    ctx->pc = 0x478u;
label_478:
    // 0x478: 0x800017e  j           func_0005F8
    ctx->pc = 0x478u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x480u;
label_480:
    // 0x480: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x484: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x488: 0xc0001bb  jal         func_0006EC
    ctx->pc = 0x488u;
    SET_GPR_U32(ctx, 31, 0x490u);
    ctx->pc = 0x6ECu;
    goto label_6ec;
    ctx->pc = 0x490u;
label_490:
    // 0x490: 0x800017e  j           func_0005F8
    ctx->pc = 0x490u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x498u;
label_498:
    // 0x498: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x49c: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x4a0: 0xc0001d0  jal         func_000740
    ctx->pc = 0x4A0u;
    SET_GPR_U32(ctx, 31, 0x4A8u);
    ctx->pc = 0x740u;
    goto label_740;
    ctx->pc = 0x4A8u;
label_4a8:
    // 0x4a8: 0x800017e  j           func_0005F8
    ctx->pc = 0x4A8u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x4B0u;
label_4b0:
    // 0x4b0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4b4: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x4b8: 0xc000271  jal         func_0009C4
    ctx->pc = 0x4B8u;
    SET_GPR_U32(ctx, 31, 0x4C0u);
    ctx->pc = 0x9C4u;
    goto label_9c4;
    ctx->pc = 0x4C0u;
label_4c0:
    // 0x4c0: 0x800017e  j           func_0005F8
    ctx->pc = 0x4C0u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x4C8u;
label_4c8:
    // 0x4c8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4cc: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x4d0: 0xc0001c4  jal         func_000710
    ctx->pc = 0x4D0u;
    SET_GPR_U32(ctx, 31, 0x4D8u);
    ctx->pc = 0x710u;
    goto label_710;
    ctx->pc = 0x4D8u;
label_4d8:
    // 0x4d8: 0x800017e  j           func_0005F8
    ctx->pc = 0x4D8u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x4E0u;
label_4e0:
    // 0x4e0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4e4: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x4e8: 0xc0002b4  jal         func_000AD0
    ctx->pc = 0x4E8u;
    SET_GPR_U32(ctx, 31, 0x4F0u);
    ctx->pc = 0xAD0u;
    goto label_ad0;
    ctx->pc = 0x4F0u;
label_4f0:
    // 0x4f0: 0x800017e  j           func_0005F8
    ctx->pc = 0x4F0u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x4F8u;
label_4f8:
    // 0x4f8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4fc: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x500: 0xc000332  jal         func_000CC8
    ctx->pc = 0x500u;
    SET_GPR_U32(ctx, 31, 0x508u);
    ctx->pc = 0xCC8u;
    goto label_cc8;
    ctx->pc = 0x508u;
label_508:
    // 0x508: 0x800017e  j           func_0005F8
    ctx->pc = 0x508u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x510u;
label_510:
    // 0x510: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x514: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x518: 0xc00033d  jal         func_000CF4
    ctx->pc = 0x518u;
    SET_GPR_U32(ctx, 31, 0x520u);
    ctx->pc = 0xCF4u;
    goto label_cf4;
    ctx->pc = 0x520u;
label_520:
    // 0x520: 0x800017e  j           func_0005F8
    ctx->pc = 0x520u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x528u;
label_528:
    // 0x528: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x52c: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x530: 0xc000348  jal         func_000D20
    ctx->pc = 0x530u;
    SET_GPR_U32(ctx, 31, 0x538u);
    ctx->pc = 0xD20u;
    goto label_d20;
    ctx->pc = 0x538u;
label_538:
    // 0x538: 0x800017e  j           func_0005F8
    ctx->pc = 0x538u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x540u;
label_540:
    // 0x540: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x544: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x548: 0xc0003a9  jal         func_000EA4
    ctx->pc = 0x548u;
    SET_GPR_U32(ctx, 31, 0x550u);
    ctx->pc = 0xEA4u;
    goto label_ea4;
    ctx->pc = 0x550u;
label_550:
    // 0x550: 0x800017e  j           func_0005F8
    ctx->pc = 0x550u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x558u;
label_558:
    // 0x558: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x55c: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x560: 0xc0003b5  jal         func_000ED4
    ctx->pc = 0x560u;
    SET_GPR_U32(ctx, 31, 0x568u);
    ctx->pc = 0xED4u;
    goto label_ed4;
    ctx->pc = 0x568u;
label_568:
    // 0x568: 0x800017e  j           func_0005F8
    ctx->pc = 0x568u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x570u;
label_570:
    // 0x570: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x574: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x578: 0xc00030a  jal         func_000C28
    ctx->pc = 0x578u;
    SET_GPR_U32(ctx, 31, 0x580u);
    ctx->pc = 0xC28u;
    goto label_c28;
    ctx->pc = 0x580u;
label_580:
    // 0x580: 0x800017e  j           func_0005F8
    ctx->pc = 0x580u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x588u;
label_588:
    // 0x588: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x58c: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x590: 0xc0003be  jal         func_000EF8
    ctx->pc = 0x590u;
    SET_GPR_U32(ctx, 31, 0x598u);
    ctx->pc = 0xEF8u;
    goto label_ef8;
    ctx->pc = 0x598u;
label_598:
    // 0x598: 0x800017e  j           func_0005F8
    ctx->pc = 0x598u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x5A0u;
label_5a0:
    // 0x5a0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x5a4: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x5a8: 0xc00039e  jal         func_000E78
    ctx->pc = 0x5A8u;
    SET_GPR_U32(ctx, 31, 0x5B0u);
    ctx->pc = 0xE78u;
    goto label_e78;
    ctx->pc = 0x5B0u;
label_5b0:
    // 0x5b0: 0x800017e  j           func_0005F8
    ctx->pc = 0x5B0u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x5B8u;
label_5b8:
    // 0x5b8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x5bc: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x5c0: 0xc0003d7  jal         func_000F5C
    ctx->pc = 0x5C0u;
    SET_GPR_U32(ctx, 31, 0x5C8u);
    ctx->pc = 0xF5Cu;
    goto label_f5c;
    ctx->pc = 0x5C8u;
label_5c8:
    // 0x5c8: 0x800017e  j           func_0005F8
    ctx->pc = 0x5C8u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x5D0u;
label_5d0:
    // 0x5d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x5d4: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x5d8: 0xc000197  jal         func_00065C
    ctx->pc = 0x5D8u;
    SET_GPR_U32(ctx, 31, 0x5E0u);
    ctx->pc = 0x65Cu;
    goto label_65c;
    ctx->pc = 0x5E0u;
label_5e0:
    // 0x5e0: 0x800017e  j           func_0005F8
    ctx->pc = 0x5E0u;
    ctx->pc = 0x5F8u;
    goto label_5f8;
    ctx->pc = 0x5E8u;
label_5e8:
    // 0x5e8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x5ec: 0x248432b0  addiu       $a0, $a0, 0x32B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12976));
    // 0x5f0: 0xc0001a6  jal         func_000698
    ctx->pc = 0x5F0u;
    SET_GPR_U32(ctx, 31, 0x5F8u);
    ctx->pc = 0x698u;
    goto label_698;
    ctx->pc = 0x5F8u;
label_5f8:
    // 0x5f8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x5fc: 0xac2212a0  sw          $v0, 0x12A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4768), GPR_U32(ctx, 2));
label_600:
    // 0x600: 0xc000479  jal         func_0011E4
    ctx->pc = 0x600u;
    SET_GPR_U32(ctx, 31, 0x608u);
    ctx->pc = 0x11E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11E4u, 0x600u, 0x608u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x608u;
label_608:
    // 0x608: 0xc000489  jal         func_001224
    ctx->pc = 0x608u;
    SET_GPR_U32(ctx, 31, 0x610u);
    ctx->pc = 0x1224u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1224u, 0x608u, 0x610u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x610u;
label_610:
    // 0x610: 0xc000452  jal         func_001148
    ctx->pc = 0x610u;
    SET_GPR_U32(ctx, 31, 0x618u);
    // 0x614: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1148u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1148u, 0x610u, 0x618u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x618u;
label_618:
    // 0x618: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x61c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x620: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x624: 0x244212a0  addiu       $v0, $v0, 0x12A0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4768));
    // 0x628: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x62c: 0xac20373c  sw          $zero, 0x373C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 14140), GPR_U32(ctx, 0));
    // 0x630: 0x3e00008  jr          $ra
    ctx->pc = 0x630u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x634: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x630u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x638u;
label_638:
    // 0x638: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x63c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x640: 0x8c840000  lw          $a0, 0x0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x644: 0xc00047f  jal         func_0011FC
    ctx->pc = 0x644u;
    SET_GPR_U32(ctx, 31, 0x64Cu);
    ctx->pc = 0x11FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11FCu, 0x644u, 0x64Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x64Cu;
label_64c:
    // 0x64c: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x650: 0x0  nop
    // NOP
    // 0x654: 0x3e00008  jr          $ra
    ctx->pc = 0x654u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x658: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x654u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x65Cu;
label_65c:
    // 0x65c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x660: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x664: 0x8c850014  lw          $a1, 0x14($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x668: 0x0  nop
    // NOP
    // 0x66c: 0x24a2fff7  addiu       $v0, $a1, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967287));
    // 0x670: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x674: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x674u;
    {
        const bool branch_taken_0x674 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x678: 0x2402fe6d  addiu       $v0, $zero, -0x193 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966893));
        if (branch_taken_0x674) {
            ctx->pc = 0x688u;
            goto label_688;
        }
    }
    ctx->pc = 0x67Cu;
    // 0x67c: 0xc000443  jal         func_00110C
    ctx->pc = 0x67Cu;
    SET_GPR_U32(ctx, 31, 0x684u);
    // 0x680: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x110Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x110Cu, 0x67Cu, 0x684u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x684u;
label_684:
    // 0x684: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_688:
    // 0x688: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x68c: 0x0  nop
    // NOP
    // 0x690: 0x3e00008  jr          $ra
    ctx->pc = 0x690u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x694: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x690u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x69c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x6a0: 0x8c840004  lw          $a0, 0x4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x6a4: 0xc00047b  jal         func_0011EC
    ctx->pc = 0x6A4u;
    SET_GPR_U32(ctx, 31, 0x6ACu);
    ctx->pc = 0x11ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ECu, 0x6A4u, 0x6ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6ACu;
label_6ac:
    // 0x6ac: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x6b0: 0x0  nop
    // NOP
    // 0x6b4: 0x3e00008  jr          $ra
    ctx->pc = 0x6B4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6b8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x6B4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6BCu;
label_6bc:
    // 0x6bc: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x6c0: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x6c4: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x6c8: 0x8cc40000  lw          $a0, 0x0($a2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x6cc: 0x8cc50004  lw          $a1, 0x4($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x6d0: 0x8cc70008  lw          $a3, 0x8($a2)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x6d4: 0xc00045d  jal         func_001174
    ctx->pc = 0x6D4u;
    SET_GPR_U32(ctx, 31, 0x6DCu);
    // 0x6d8: 0x24c60014  addiu       $a2, $a2, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20));
    ctx->pc = 0x1174u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1174u, 0x6D4u, 0x6DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6DCu;
label_6dc:
    // 0x6dc: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x6e0: 0x0  nop
    // NOP
    // 0x6e4: 0x3e00008  jr          $ra
    ctx->pc = 0x6E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6e8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x6E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6ECu;
label_6ec:
    // 0x6ec: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x6f0: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x6f4: 0x8c840000  lw          $a0, 0x0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x6f8: 0xc00045f  jal         func_00117C
    ctx->pc = 0x6F8u;
    SET_GPR_U32(ctx, 31, 0x700u);
    ctx->pc = 0x117Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x117Cu, 0x6F8u, 0x700u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x700u;
label_700:
    // 0x700: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x704: 0x0  nop
    // NOP
    // 0x708: 0x3e00008  jr          $ra
    ctx->pc = 0x708u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x70c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x708u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x710u;
label_710:
    // 0x710: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x714: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x718: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x71c: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x720: 0x8c450010  lw          $a1, 0x10($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x724: 0x8c460014  lw          $a2, 0x14($v0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x728: 0xc000465  jal         func_001194
    ctx->pc = 0x728u;
    SET_GPR_U32(ctx, 31, 0x730u);
    ctx->pc = 0x1194u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1194u, 0x728u, 0x730u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x730u;
label_730:
    // 0x730: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x734: 0x0  nop
    // NOP
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
label_740:
    // 0x740: 0x27bdfef8  addiu       $sp, $sp, -0x108
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967032));
    // 0x744: 0xafb60100  sw          $s6, 0x100($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 256), GPR_U32(ctx, 22));
    // 0x748: 0x80b021  addu        $s6, $a0, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x74c: 0xafbf0104  sw          $ra, 0x104($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 260), GPR_U32(ctx, 31));
    // 0x750: 0xafb500fc  sw          $s5, 0xFC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 252), GPR_U32(ctx, 21));
    // 0x754: 0xafb400f8  sw          $s4, 0xF8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 248), GPR_U32(ctx, 20));
    // 0x758: 0xafb300f4  sw          $s3, 0xF4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 244), GPR_U32(ctx, 19));
    // 0x75c: 0xafb200f0  sw          $s2, 0xF0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 240), GPR_U32(ctx, 18));
    // 0x760: 0xafb100ec  sw          $s1, 0xEC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 236), GPR_U32(ctx, 17));
    // 0x764: 0xafb000e8  sw          $s0, 0xE8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 232), GPR_U32(ctx, 16));
    // 0x768: 0x8ed20018  lw          $s2, 0x18($s6)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 24)));
    // 0x76c: 0xa021  addu        $s4, $zero, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x770: 0xafa00018  sw          $zero, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x774: 0xafa0001c  sw          $zero, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
    // 0x778: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x77c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x780: 0x8ed1000c  lw          $s1, 0xC($s6)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x784: 0x0  nop
    // NOP
    // 0x788: 0x2a220041  slti        $v0, $s1, 0x41
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)65) ? 1 : 0);
    // 0x78c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x78Cu;
    {
        const bool branch_taken_0x78c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x790: 0x2808021  addu        $s0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0x78c) {
            ctx->pc = 0x79Cu;
            goto label_79c;
        }
    }
    ctx->pc = 0x794u;
    // 0x794: 0x80001ed  j           func_0007B4
    ctx->pc = 0x794u;
    // 0x798: 0xafb10010  sw          $s1, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 17));
    ctx->pc = 0x7B4u;
    goto label_7b4;
    ctx->pc = 0x79Cu;
label_79c:
    // 0x79c: 0x2642ffff  addiu       $v0, $s2, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x7a0: 0x2403ffc0  addiu       $v1, $zero, -0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x7a4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x7a8: 0x2431821  addu        $v1, $s2, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x7ac: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x7b0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_7b4:
    // 0x7b4: 0x8fa60010  lw          $a2, 0x10($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x7b8: 0x0  nop
    // NOP
    // 0x7bc: 0x2268823  subu        $s1, $s1, $a2
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
    // 0x7c0: 0x3222003f  andi        $v0, $s1, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
    // 0x7c4: 0x2228823  subu        $s1, $s1, $v0
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x7c8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x7C8u;
    {
        const bool branch_taken_0x7c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x7cc: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        if (branch_taken_0x7c8) {
            ctx->pc = 0x7DCu;
            goto label_7dc;
        }
    }
    ctx->pc = 0x7D0u;
    // 0x7d0: 0x2461021  addu        $v0, $s2, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 6)));
    // 0x7d4: 0x511021  addu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x7d8: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
label_7dc:
    // 0x7dc: 0x10c00013  beqz        $a2, . + 4 + (0x13 << 2)
    ctx->pc = 0x7DCu;
    {
        const bool branch_taken_0x7dc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x7dc) {
            ctx->pc = 0x82Cu;
            goto label_82c;
        }
    }
    ctx->pc = 0x7E4u;
    // 0x7e4: 0x8ec40000  lw          $a0, 0x0($s6)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x7e8: 0xc000461  jal         func_001184
    ctx->pc = 0x7E8u;
    SET_GPR_U32(ctx, 31, 0x7F0u);
    // 0x7ec: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x1184u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1184u, 0x7E8u, 0x7F0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7F0u;
label_7f0:
    // 0x7f0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x7f4: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x7F4u;
    {
        const bool branch_taken_0x7f4 = (GPR_S32(ctx, 16) >= 0);
        if (branch_taken_0x7f4) {
            ctx->pc = 0x808u;
            goto label_808;
        }
    }
    ctx->pc = 0x7FCu;
    // 0x7fc: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_800:
    // 0x800: 0x800024d  j           func_000934
    ctx->pc = 0x800u;
    // 0x804: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    ctx->pc = 0x934u;
    goto label_934;
    ctx->pc = 0x808u;
label_808:
    // 0x808: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x80c: 0x200a021  addu        $s4, $s0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x810: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
    // 0x814: 0x10540004  beq         $v0, $s4, . + 4 + (0x4 << 2)
    ctx->pc = 0x814u;
    {
        const bool branch_taken_0x814 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        // 0x818: 0x2549021  addu        $s2, $s2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
        if (branch_taken_0x814) {
            ctx->pc = 0x828u;
            goto label_828;
        }
    }
    ctx->pc = 0x81Cu;
    // 0x81c: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x820: 0x8000200  j           func_000800
    ctx->pc = 0x820u;
    // 0x824: 0xafb40010  sw          $s4, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
    ctx->pc = 0x800u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_800;
    ctx->pc = 0x828u;
label_828:
    // 0x828: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_82c:
    // 0x82c: 0x12200034  beqz        $s1, . + 4 + (0x34 << 2)
    ctx->pc = 0x82Cu;
    {
        const bool branch_taken_0x82c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x82c) {
            ctx->pc = 0x900u;
            goto label_900;
        }
    }
    ctx->pc = 0x834u;
    // 0x834: 0x3c150000  lui         $s5, 0x0
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)0 << 16));
    // 0x838: 0x26b512b0  addiu       $s5, $s5, 0x12B0
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4784));
label_83c:
    // 0x83c: 0x2a222001  slti        $v0, $s1, 0x2001
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)8193) ? 1 : 0);
    // 0x840: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x840u;
    {
        const bool branch_taken_0x840 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x844: 0x2209821  addu        $s3, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x840) {
            ctx->pc = 0x84Cu;
            goto label_84c;
        }
    }
    ctx->pc = 0x848u;
    // 0x848: 0x24132000  addiu       $s3, $zero, 0x2000
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
label_84c:
    // 0x84c: 0x8ec40000  lw          $a0, 0x0($s6)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x850: 0x2a02821  addu        $a1, $s5, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    // 0x854: 0xc000461  jal         func_001184
    ctx->pc = 0x854u;
    SET_GPR_U32(ctx, 31, 0x85Cu);
    // 0x858: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x1184u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1184u, 0x854u, 0x85Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x85Cu;
label_85c:
    // 0x85c: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x860: 0x600ffe7  bltz        $s0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x860u;
    {
        const bool branch_taken_0x860 = (GPR_S32(ctx, 16) < 0);
        if (branch_taken_0x860) {
            ctx->pc = 0x800u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_800;
        }
    }
    ctx->pc = 0x868u;
    // 0x868: 0x12130013  beq         $s0, $s3, . + 4 + (0x13 << 2)
    ctx->pc = 0x868u;
    {
        const bool branch_taken_0x868 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 19));
        // 0x86c: 0x3206003f  andi        $a2, $s0, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)63);
        if (branch_taken_0x868) {
            ctx->pc = 0x8B8u;
            goto label_8b8;
        }
    }
    ctx->pc = 0x870u;
    // 0x870: 0x10c00008  beqz        $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x870u;
    {
        const bool branch_taken_0x870 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x874: 0xafa60014  sw          $a2, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 6));
        if (branch_taken_0x870) {
            ctx->pc = 0x894u;
            goto label_894;
        }
    }
    ctx->pc = 0x878u;
    // 0x878: 0x2405ffc0  addiu       $a1, $zero, -0x40
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x87c: 0x2052824  and         $a1, $s0, $a1
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & GPR_U64(ctx, 5));
    // 0x880: 0x2451021  addu        $v0, $s2, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x884: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x888: 0x27a40060  addiu       $a0, $sp, 0x60
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x88c: 0xc0003ff  jal         func_000FFC
    ctx->pc = 0x88Cu;
    SET_GPR_U32(ctx, 31, 0x894u);
    // 0x890: 0xb52821  addu        $a1, $a1, $s5 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 21)));
    ctx->pc = 0xFFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFFCu, 0x88Cu, 0x894u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x894u;
label_894:
    // 0x894: 0x8fa20014  lw          $v0, 0x14($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x898: 0x0  nop
    // NOP
    // 0x89c: 0x12020012  beq         $s0, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x89Cu;
    {
        const bool branch_taken_0x89c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        // 0x8a0: 0x27a400e0  addiu       $a0, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        if (branch_taken_0x89c) {
            ctx->pc = 0x8E8u;
            goto label_8e8;
        }
    }
    ctx->pc = 0x8A4u;
    // 0x8a4: 0x2021023  subu        $v0, $s0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x8a8: 0xafb500d0  sw          $s5, 0xD0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 21));
    // 0x8ac: 0xafb200d4  sw          $s2, 0xD4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 212), GPR_U32(ctx, 18));
    // 0x8b0: 0x8000232  j           func_0008C8
    ctx->pc = 0x8B0u;
    // 0x8b4: 0xafa200d8  sw          $v0, 0xD8($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 216), GPR_U32(ctx, 2));
    ctx->pc = 0x8C8u;
    goto label_8c8;
    ctx->pc = 0x8B8u;
label_8b8:
    // 0x8b8: 0x27a400e0  addiu       $a0, $sp, 0xE0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
    // 0x8bc: 0xafb500d0  sw          $s5, 0xD0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 21));
    // 0x8c0: 0xafb200d4  sw          $s2, 0xD4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 212), GPR_U32(ctx, 18));
    // 0x8c4: 0xafb000d8  sw          $s0, 0xD8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 216), GPR_U32(ctx, 16));
label_8c8:
    // 0x8c8: 0xc0003f4  jal         func_000FD0
    ctx->pc = 0x8C8u;
    SET_GPR_U32(ctx, 31, 0x8D0u);
    // 0x8cc: 0xafa000dc  sw          $zero, 0xDC($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 220), GPR_U32(ctx, 0));
    ctx->pc = 0xFD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD0u, 0x8C8u, 0x8D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8D0u;
label_8d0:
    // 0x8d0: 0x27a400d0  addiu       $a0, $sp, 0xD0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x8d4: 0xc000419  jal         func_001064
    ctx->pc = 0x8D4u;
    SET_GPR_U32(ctx, 31, 0x8DCu);
    // 0x8d8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1064u, 0x8D4u, 0x8DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8DCu;
label_8dc:
    // 0x8dc: 0x8fa400e0  lw          $a0, 0xE0($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x8e0: 0xc0003f6  jal         func_000FD8
    ctx->pc = 0x8E0u;
    SET_GPR_U32(ctx, 31, 0x8E8u);
    ctx->pc = 0xFD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD8u, 0x8E0u, 0x8E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8E8u;
label_8e8:
    // 0x8e8: 0x290a021  addu        $s4, $s4, $s0
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x8ec: 0x2308823  subu        $s1, $s1, $s0
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x8f0: 0x1613000f  bne         $s0, $s3, . + 4 + (0xF << 2)
    ctx->pc = 0x8F0u;
    {
        const bool branch_taken_0x8f0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 19));
        // 0x8f4: 0x2509021  addu        $s2, $s2, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
        if (branch_taken_0x8f0) {
            ctx->pc = 0x930u;
            goto label_930;
        }
    }
    ctx->pc = 0x8F8u;
    // 0x8f8: 0x1620ffd0  bnez        $s1, . + 4 + (-0x30 << 2)
    ctx->pc = 0x8F8u;
    {
        const bool branch_taken_0x8f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x8fc: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x8f8) {
            ctx->pc = 0x83Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_83c;
        }
    }
    ctx->pc = 0x900u;
label_900:
    // 0x900: 0x8fa60014  lw          $a2, 0x14($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x904: 0x0  nop
    // NOP
    // 0x908: 0x10c0000b  beqz        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x908u;
    {
        const bool branch_taken_0x908 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x90c: 0x27a400e0  addiu       $a0, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        if (branch_taken_0x908) {
            ctx->pc = 0x938u;
            goto label_938;
        }
    }
    ctx->pc = 0x910u;
    // 0x910: 0x8ec40000  lw          $a0, 0x0($s6)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x914: 0xc000461  jal         func_001184
    ctx->pc = 0x914u;
    SET_GPR_U32(ctx, 31, 0x91Cu);
    // 0x918: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    ctx->pc = 0x1184u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1184u, 0x914u, 0x91Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x91Cu;
label_91c:
    // 0x91c: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x920: 0x600ffb7  bltz        $s0, . + 4 + (-0x49 << 2)
    ctx->pc = 0x920u;
    {
        const bool branch_taken_0x920 = (GPR_S32(ctx, 16) < 0);
        if (branch_taken_0x920) {
            ctx->pc = 0x800u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_800;
        }
    }
    ctx->pc = 0x928u;
    // 0x928: 0x290a021  addu        $s4, $s4, $s0
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x92c: 0xafb00014  sw          $s0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 16));
label_930:
    // 0x930: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_934:
    // 0x934: 0x27a400e0  addiu       $a0, $sp, 0xE0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
label_938:
    // 0x938: 0x27a20010  addiu       $v0, $sp, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x93c: 0xafa200d0  sw          $v0, 0xD0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 2));
    // 0x940: 0x8ec3001c  lw          $v1, 0x1C($s6)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 28)));
    // 0x944: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x948: 0xafa200d8  sw          $v0, 0xD8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 216), GPR_U32(ctx, 2));
    // 0x94c: 0xafa000dc  sw          $zero, 0xDC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 220), GPR_U32(ctx, 0));
    // 0x950: 0xc0003f4  jal         func_000FD0
    ctx->pc = 0x950u;
    SET_GPR_U32(ctx, 31, 0x958u);
    // 0x954: 0xafa300d4  sw          $v1, 0xD4($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 212), GPR_U32(ctx, 3));
    ctx->pc = 0xFD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD0u, 0x950u, 0x958u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x958u;
label_958:
    // 0x958: 0x27a400d0  addiu       $a0, $sp, 0xD0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x95c: 0xc000419  jal         func_001064
    ctx->pc = 0x95Cu;
    SET_GPR_U32(ctx, 31, 0x964u);
    // 0x960: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1064u, 0x95Cu, 0x964u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x964u;
label_964:
    // 0x964: 0x8fa400e0  lw          $a0, 0xE0($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x968: 0xc0003f6  jal         func_000FD8
    ctx->pc = 0x968u;
    SET_GPR_U32(ctx, 31, 0x970u);
    // 0x96c: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xFD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD8u, 0x968u, 0x970u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x970u;
label_970:
    // 0x970: 0xc00041b  jal         func_00106C
    ctx->pc = 0x970u;
    SET_GPR_U32(ctx, 31, 0x978u);
    // 0x974: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x106Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x106Cu, 0x970u, 0x978u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x978u;
label_978:
    // 0x978: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x978u;
    {
        const bool branch_taken_0x978 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x978) {
            ctx->pc = 0x990u;
            goto label_990;
        }
    }
    ctx->pc = 0x980u;
    // 0x980: 0xc000449  jal         func_001124
    ctx->pc = 0x980u;
    SET_GPR_U32(ctx, 31, 0x988u);
    // 0x984: 0x24040064  addiu       $a0, $zero, 0x64 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    ctx->pc = 0x1124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1124u, 0x980u, 0x988u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x988u;
label_988:
    // 0x988: 0x800025c  j           func_000970
    ctx->pc = 0x988u;
    ctx->pc = 0x970u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_970;
    ctx->pc = 0x990u;
label_990:
    // 0x990: 0x16000002  bnez        $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x990u;
    {
        const bool branch_taken_0x990 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x994: 0x2001021  addu        $v0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x990) {
            ctx->pc = 0x99Cu;
            goto label_99c;
        }
    }
    ctx->pc = 0x998u;
    // 0x998: 0x2801021  addu        $v0, $s4, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_99c:
    // 0x99c: 0x8fbf0104  lw          $ra, 0x104($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 260)));
    // 0x9a0: 0x8fb60100  lw          $s6, 0x100($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x9a4: 0x8fb500fc  lw          $s5, 0xFC($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 252)));
    // 0x9a8: 0x8fb400f8  lw          $s4, 0xF8($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 248)));
    // 0x9ac: 0x8fb300f4  lw          $s3, 0xF4($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 244)));
    // 0x9b0: 0x8fb200f0  lw          $s2, 0xF0($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x9b4: 0x8fb100ec  lw          $s1, 0xEC($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 236)));
    // 0x9b8: 0x8fb000e8  lw          $s0, 0xE8($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 232)));
    // 0x9bc: 0x3e00008  jr          $ra
    ctx->pc = 0x9BCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9c0: 0x27bd0108  addiu       $sp, $sp, 0x108 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 264));
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
label_9c4:
    // 0x9c4: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x9c8: 0xafb1003c  sw          $s1, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 17));
    // 0x9cc: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x9d0: 0xafbf0048  sw          $ra, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 31));
    // 0x9d4: 0xafb30044  sw          $s3, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 19));
    // 0x9d8: 0xafb20040  sw          $s2, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 18));
    // 0x9dc: 0xafb00038  sw          $s0, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 16));
    // 0x9e0: 0x8e260014  lw          $a2, 0x14($s1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x9e4: 0x0  nop
    // NOP
    // 0x9e8: 0x10c0000c  beqz        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x9E8u;
    {
        const bool branch_taken_0x9e8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x9ec: 0x9021  addu        $s2, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x9e8) {
            ctx->pc = 0xA1Cu;
            goto label_a1c;
        }
    }
    ctx->pc = 0x9F0u;
    // 0x9f0: 0x8e240000  lw          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x9f4: 0xc000463  jal         func_00118C
    ctx->pc = 0x9F4u;
    SET_GPR_U32(ctx, 31, 0x9FCu);
    // 0x9f8: 0x26250020  addiu       $a1, $s1, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 32));
    ctx->pc = 0x118Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x118Cu, 0x9F4u, 0x9FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9FCu;
label_9fc:
    // 0x9fc: 0x8e230014  lw          $v1, 0x14($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0xa00: 0x0  nop
    // NOP
    // 0xa04: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0xA04u;
    {
        const bool branch_taken_0xa04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        // 0xa08: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0xa04) {
            ctx->pc = 0xA1Cu;
            goto label_a1c;
        }
    }
    ctx->pc = 0xA0Cu;
    // 0xa0c: 0x80002ad  j           func_000AB4
    ctx->pc = 0xA0Cu;
    ctx->pc = 0xAB4u;
    goto label_ab4;
    ctx->pc = 0xA14u;
label_a14:
    // 0xa14: 0x80002ad  j           func_000AB4
    ctx->pc = 0xA14u;
    // 0xa18: 0x521021  addu        $v0, $v0, $s2 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    ctx->pc = 0xAB4u;
    goto label_ab4;
    ctx->pc = 0xA1Cu;
label_a1c:
    // 0xa1c: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0xa20: 0x0  nop
    // NOP
    // 0xa24: 0x10400023  beqz        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0xA24u;
    {
        const bool branch_taken_0xa24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xa28: 0x2401021  addu        $v0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0xa24) {
            ctx->pc = 0xAB4u;
            goto label_ab4;
        }
    }
    ctx->pc = 0xA2Cu;
    // 0xa2c: 0x3c130000  lui         $s3, 0x0
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)0 << 16));
    // 0xa30: 0x267312b0  addiu       $s3, $s3, 0x12B0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4784));
label_a34:
    // 0xa34: 0x8e23000c  lw          $v1, 0xC($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0xa38: 0x0  nop
    // NOP
    // 0xa3c: 0x28622001  slti        $v0, $v1, 0x2001
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8193) ? 1 : 0);
    // 0xa40: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0xA40u;
    {
        const bool branch_taken_0xa40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xa44: 0x24102000  addiu       $s0, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        if (branch_taken_0xa40) {
            ctx->pc = 0xA4Cu;
            goto label_a4c;
        }
    }
    ctx->pc = 0xA48u;
    // 0xa48: 0x608021  addu        $s0, $v1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_a4c:
    // 0xa4c: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0xa50: 0x2603021  addu        $a2, $s3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xa54: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0xa58: 0x8e250018  lw          $a1, 0x18($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0xa5c: 0xc00042e  jal         func_0010B8
    ctx->pc = 0xA5Cu;
    SET_GPR_U32(ctx, 31, 0xA64u);
    // 0xa60: 0x2003821  addu        $a3, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x10B8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10B8u, 0xA5Cu, 0xA64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA64u;
label_a64:
    // 0xa64: 0x2602821  addu        $a1, $s3, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0xa68: 0x8e240000  lw          $a0, 0x0($s1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0xa6c: 0xc000463  jal         func_00118C
    ctx->pc = 0xA6Cu;
    SET_GPR_U32(ctx, 31, 0xA74u);
    // 0xa70: 0x2003021  addu        $a2, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x118Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x118Cu, 0xA6Cu, 0xA74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA74u;
label_a74:
    // 0xa74: 0x10500005  beq         $v0, $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0xA74u;
    {
        const bool branch_taken_0xa74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        if (branch_taken_0xa74) {
            ctx->pc = 0xA8Cu;
            goto label_a8c;
        }
    }
    ctx->pc = 0xA7Cu;
    // 0xa7c: 0x441ffe5  bgez        $v0, . + 4 + (-0x1B << 2)
    ctx->pc = 0xA7Cu;
    {
        const bool branch_taken_0xa7c = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0xa7c) {
            ctx->pc = 0xA14u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_a14;
        }
    }
    ctx->pc = 0xA84u;
    // 0xa84: 0x80002ad  j           func_000AB4
    ctx->pc = 0xA84u;
    ctx->pc = 0xAB4u;
    goto label_ab4;
    ctx->pc = 0xA8Cu;
label_a8c:
    // 0xa8c: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0xa90: 0x2509021  addu        $s2, $s2, $s0
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0xa94: 0x501023  subu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0xa98: 0xae22000c  sw          $v0, 0xC($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0xa9c: 0x8e220018  lw          $v0, 0x18($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0xaa0: 0x8e23000c  lw          $v1, 0xC($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0xaa4: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0xaa8: 0x1460ffe2  bnez        $v1, . + 4 + (-0x1E << 2)
    ctx->pc = 0xAA8u;
    {
        const bool branch_taken_0xaa8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0xaac: 0xae220018  sw          $v0, 0x18($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
        if (branch_taken_0xaa8) {
            ctx->pc = 0xA34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_a34;
        }
    }
    ctx->pc = 0xAB0u;
    // 0xab0: 0x2401021  addu        $v0, $s2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_ab4:
    // 0xab4: 0x8fbf0048  lw          $ra, 0x48($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xab8: 0x8fb30044  lw          $s3, 0x44($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xabc: 0x8fb20040  lw          $s2, 0x40($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xac0: 0x8fb1003c  lw          $s1, 0x3C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0xac4: 0x8fb00038  lw          $s0, 0x38($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xac8: 0x3e00008  jr          $ra
    ctx->pc = 0xAC8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xacc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xAC8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAD0u;
label_ad0:
    // 0xad0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0xad4: 0xafb00030  sw          $s0, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 16));
    // 0xad8: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xadc: 0xafb20038  sw          $s2, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 18));
    // 0xae0: 0x9021  addu        $s2, $zero, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xae4: 0xafb10034  sw          $s1, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 17));
    // 0xae8: 0xafbf004c  sw          $ra, 0x4C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 31));
    // 0xaec: 0xafb60048  sw          $s6, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 22));
    // 0xaf0: 0xafb50044  sw          $s5, 0x44($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 68), GPR_U32(ctx, 21));
    // 0xaf4: 0xafb40040  sw          $s4, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 20));
    // 0xaf8: 0xafb3003c  sw          $s3, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 19));
    // 0xafc: 0x8e03000c  lw          $v1, 0xC($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0xb00: 0x8e070008  lw          $a3, 0x8($s0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0xb04: 0x461000b  bgez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0xB04u;
    {
        const bool branch_taken_0xb04 = (GPR_S32(ctx, 3) >= 0);
        // 0xb08: 0x2408821  addu        $s1, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0xb04) {
            ctx->pc = 0xB34u;
            goto label_b34;
        }
    }
    ctx->pc = 0xB0Cu;
    // 0xb0c: 0x26060014  addiu       $a2, $s0, 0x14
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0xb10: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xb14: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xb18: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0xb1c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xb20: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xb24: 0xc000469  jal         func_0011A4
    ctx->pc = 0xB24u;
    SET_GPR_U32(ctx, 31, 0xB2Cu);
    // 0xb28: 0x30e7ffff  andi        $a3, $a3, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x11A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11A4u, 0xB24u, 0xB2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB2Cu;
label_b2c:
    // 0xb2c: 0x8000300  j           func_000C00
    ctx->pc = 0xB2Cu;
    ctx->pc = 0xC00u;
    goto label_c00;
    ctx->pc = 0xB34u;
label_b34:
    // 0xb34: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0xb38: 0x2402ffff  addiu       $v0, $zero, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0xb3c: 0x10620026  beq         $v1, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0xB3Cu;
    {
        const bool branch_taken_0xb3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0xb40: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        if (branch_taken_0xb3c) {
            ctx->pc = 0xBD8u;
            goto label_bd8;
        }
    }
    ctx->pc = 0xB44u;
    // 0xb44: 0x24160001  addiu       $s6, $zero, 0x1
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xb48: 0x3c130000  lui         $s3, 0x0
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)0 << 16));
    // 0xb4c: 0x267312b0  addiu       $s3, $s3, 0x12B0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4784));
    // 0xb50: 0x24150040  addiu       $s5, $zero, 0x40
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0xb54: 0x40a021  addu        $s4, $v0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_b58:
    // 0xb58: 0x26060014  addiu       $a2, $s0, 0x14
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0xb5c: 0xafb60010  sw          $s6, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 22));
    // 0xb60: 0xafb30014  sw          $s3, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 19));
    // 0xb64: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xb68: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xb6c: 0xc000469  jal         func_0011A4
    ctx->pc = 0xB6Cu;
    SET_GPR_U32(ctx, 31, 0xB74u);
    // 0xb70: 0x30e7ffff  andi        $a3, $a3, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x11A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11A4u, 0xB6Cu, 0xB74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB74u;
label_b74:
    // 0xb74: 0x4400022  bltz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0xB74u;
    {
        const bool branch_taken_0xb74 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0xb74) {
            ctx->pc = 0xC00u;
            goto label_c00;
        }
    }
    ctx->pc = 0xB7Cu;
    // 0xb7c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0xB7Cu;
    {
        const bool branch_taken_0xb7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xb80: 0x27a40028  addiu       $a0, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        if (branch_taken_0xb7c) {
            ctx->pc = 0xBD8u;
            goto label_bd8;
        }
    }
    ctx->pc = 0xB84u;
    // 0xb84: 0xafb30018  sw          $s3, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 19));
    // 0xb88: 0x8e020010  lw          $v0, 0x10($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0xb8c: 0x26520001  addiu       $s2, $s2, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0xb90: 0xafb50020  sw          $s5, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 21));
    // 0xb94: 0xafa00024  sw          $zero, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0xb98: 0xc0003f4  jal         func_000FD0
    ctx->pc = 0xB98u;
    SET_GPR_U32(ctx, 31, 0xBA0u);
    // 0xb9c: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    ctx->pc = 0xFD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD0u, 0xB98u, 0xBA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBA0u;
label_ba0:
    // 0xba0: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0xba4: 0xc000419  jal         func_001064
    ctx->pc = 0xBA4u;
    SET_GPR_U32(ctx, 31, 0xBACu);
    // 0xba8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1064u, 0xBA4u, 0xBACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBACu;
label_bac:
    // 0xbac: 0x8fa40028  lw          $a0, 0x28($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xbb0: 0xc0003f6  jal         func_000FD8
    ctx->pc = 0xBB0u;
    SET_GPR_U32(ctx, 31, 0xBB8u);
    // 0xbb4: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xFD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD8u, 0xBB0u, 0xBB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBB8u;
label_bb8:
    // 0xbb8: 0x24070001  addiu       $a3, $zero, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xbbc: 0x8e020010  lw          $v0, 0x10($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0xbc0: 0x8e03000c  lw          $v1, 0xC($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0xbc4: 0x24420040  addiu       $v0, $v0, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0xbc8: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0xbcc: 0xae020010  sw          $v0, 0x10($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0xbd0: 0x1474ffe1  bne         $v1, $s4, . + 4 + (-0x1F << 2)
    ctx->pc = 0xBD0u;
    {
        const bool branch_taken_0xbd0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 20));
        // 0xbd4: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        if (branch_taken_0xbd0) {
            ctx->pc = 0xB58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_b58;
        }
    }
    ctx->pc = 0xBD8u;
label_bd8:
    // 0xbd8: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0xBD8u;
    {
        const bool branch_taken_0xbd8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        // 0xbdc: 0x2401021  addu        $v0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0xbd8) {
            ctx->pc = 0xC00u;
            goto label_c00;
        }
    }
    ctx->pc = 0xBE0u;
label_be0:
    // 0xbe0: 0xc00041b  jal         func_00106C
    ctx->pc = 0xBE0u;
    SET_GPR_U32(ctx, 31, 0xBE8u);
    // 0xbe4: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x106Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x106Cu, 0xBE0u, 0xBE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBE8u;
label_be8:
    // 0xbe8: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xBE8u;
    {
        const bool branch_taken_0xbe8 = (GPR_S32(ctx, 2) < 0);
        // 0xbec: 0x2401021  addu        $v0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0xbe8) {
            ctx->pc = 0xC00u;
            goto label_c00;
        }
    }
    ctx->pc = 0xBF0u;
    // 0xbf0: 0xc000449  jal         func_001124
    ctx->pc = 0xBF0u;
    SET_GPR_U32(ctx, 31, 0xBF8u);
    // 0xbf4: 0x24040064  addiu       $a0, $zero, 0x64 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    ctx->pc = 0x1124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1124u, 0xBF0u, 0xBF8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xBF8u;
label_bf8:
    // 0xbf8: 0x80002f8  j           func_000BE0
    ctx->pc = 0xBF8u;
    ctx->pc = 0xBE0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_be0;
    ctx->pc = 0xC00u;
label_c00:
    // 0xc00: 0x8fbf004c  lw          $ra, 0x4C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0xc04: 0x8fb60048  lw          $s6, 0x48($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0xc08: 0x8fb50044  lw          $s5, 0x44($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0xc0c: 0x8fb40040  lw          $s4, 0x40($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xc10: 0x8fb3003c  lw          $s3, 0x3C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0xc14: 0x8fb20038  lw          $s2, 0x38($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xc18: 0x8fb10034  lw          $s1, 0x34($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xc1c: 0x8fb00030  lw          $s0, 0x30($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xc20: 0x3e00008  jr          $ra
    ctx->pc = 0xC20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc24: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC28u;
label_c28:
    // 0xc28: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0xc2c: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0xc30: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xc34: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    // 0xc38: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0xc3c: 0x263112b0  addiu       $s1, $s1, 0x12B0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4784));
    // 0xc40: 0x26060014  addiu       $a2, $s0, 0x14
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0xc44: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
    // 0xc48: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xc4c: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xc50: 0xc00046f  jal         func_0011BC
    ctx->pc = 0xC50u;
    SET_GPR_U32(ctx, 31, 0xC58u);
    // 0xc54: 0x2203821  addu        $a3, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x11BCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11BCu, 0xC50u, 0xC58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC58u;
label_c58:
    // 0xc58: 0x27a40020  addiu       $a0, $sp, 0x20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0xc5c: 0x24030400  addiu       $v1, $zero, 0x400
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0xc60: 0xafb10010  sw          $s1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 17));
    // 0xc64: 0x8e050010  lw          $a1, 0x10($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0xc68: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xc6c: 0xafa30018  sw          $v1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0xc70: 0xafa0001c  sw          $zero, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
    // 0xc74: 0xc0003f4  jal         func_000FD0
    ctx->pc = 0xC74u;
    SET_GPR_U32(ctx, 31, 0xC7Cu);
    // 0xc78: 0xafa50014  sw          $a1, 0x14($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    ctx->pc = 0xFD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD0u, 0xC74u, 0xC7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC7Cu;
label_c7c:
    // 0xc7c: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0xc80: 0xc000419  jal         func_001064
    ctx->pc = 0xC80u;
    SET_GPR_U32(ctx, 31, 0xC88u);
    // 0xc84: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1064u, 0xC80u, 0xC88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC88u;
label_c88:
    // 0xc88: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0xc8c: 0xc0003f6  jal         func_000FD8
    ctx->pc = 0xC8Cu;
    SET_GPR_U32(ctx, 31, 0xC94u);
    // 0xc90: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xFD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD8u, 0xC8Cu, 0xC94u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC94u;
label_c94:
    // 0xc94: 0xc00041b  jal         func_00106C
    ctx->pc = 0xC94u;
    SET_GPR_U32(ctx, 31, 0xC9Cu);
    // 0xc98: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x106Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x106Cu, 0xC94u, 0xC9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC9Cu;
label_c9c:
    // 0xc9c: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xC9Cu;
    {
        const bool branch_taken_0xc9c = (GPR_S32(ctx, 2) < 0);
        // 0xca0: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0xc9c) {
            ctx->pc = 0xCB4u;
            goto label_cb4;
        }
    }
    ctx->pc = 0xCA4u;
    // 0xca4: 0xc000449  jal         func_001124
    ctx->pc = 0xCA4u;
    SET_GPR_U32(ctx, 31, 0xCACu);
    // 0xca8: 0x24040064  addiu       $a0, $zero, 0x64 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    ctx->pc = 0x1124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1124u, 0xCA4u, 0xCACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCACu;
label_cac:
    // 0xcac: 0x8000325  j           func_000C94
    ctx->pc = 0xCACu;
    ctx->pc = 0xC94u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_c94;
    ctx->pc = 0xCB4u;
label_cb4:
    // 0xcb4: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xcb8: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0xcbc: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0xcc0: 0x3e00008  jr          $ra
    ctx->pc = 0xCC0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xcc4: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCC0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCC8u;
label_cc8:
    // 0xcc8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xccc: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xcd0: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xcd4: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0xcd8: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0xcdc: 0xc000467  jal         func_00119C
    ctx->pc = 0xCDCu;
    SET_GPR_U32(ctx, 31, 0xCE4u);
    ctx->pc = 0x119Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x119Cu, 0xCDCu, 0xCE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xCE4u;
label_ce4:
    // 0xce4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xce8: 0x0  nop
    // NOP
    // 0xcec: 0x3e00008  jr          $ra
    ctx->pc = 0xCECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xcf0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xCF4u;
label_cf4:
    // 0xcf4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xcf8: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xcfc: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xd00: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0xd04: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0xd08: 0xc00047d  jal         func_0011F4
    ctx->pc = 0xD08u;
    SET_GPR_U32(ctx, 31, 0xD10u);
    ctx->pc = 0x11F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11F4u, 0xD08u, 0xD10u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD10u;
label_d10:
    // 0xd10: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xd14: 0x0  nop
    // NOP
    // 0xd18: 0x3e00008  jr          $ra
    ctx->pc = 0xD18u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xd1c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD18u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD20u;
label_d20:
    // 0xd20: 0x27bdff08  addiu       $sp, $sp, -0xF8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967048));
    // 0xd24: 0xafb000e8  sw          $s0, 0xE8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 232), GPR_U32(ctx, 16));
    // 0xd28: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xd2c: 0xafbf00f4  sw          $ra, 0xF4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 244), GPR_U32(ctx, 31));
    // 0xd30: 0xafb200f0  sw          $s2, 0xF0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 240), GPR_U32(ctx, 18));
    // 0xd34: 0xafb100ec  sw          $s1, 0xEC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 236), GPR_U32(ctx, 17));
    // 0xd38: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xd3c: 0x8e050008  lw          $a1, 0x8($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0xd40: 0xc000473  jal         func_0011CC
    ctx->pc = 0xD40u;
    SET_GPR_U32(ctx, 31, 0xD48u);
    // 0xd44: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x11CCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11CCu, 0xD40u, 0xD48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD48u;
label_d48:
    // 0xd48: 0x8e030014  lw          $v1, 0x14($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0xd4c: 0x0  nop
    // NOP
    // 0xd50: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0xD50u;
    {
        const bool branch_taken_0xd50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xd54: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0xd50) {
            ctx->pc = 0xD6Cu;
            goto label_d6c;
        }
    }
    ctx->pc = 0xD58u;
    // 0xd58: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xd5c: 0x8e050008  lw          $a1, 0x8($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0xd60: 0xc000483  jal         func_00120C
    ctx->pc = 0xD60u;
    SET_GPR_U32(ctx, 31, 0xD68u);
    ctx->pc = 0x120Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x120Cu, 0xD60u, 0xD68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD68u;
label_d68:
    // 0xd68: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_d6c:
    // 0xd6c: 0x2a42ffff  slti        $v0, $s2, -0x1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0xd70: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0xD70u;
    {
        const bool branch_taken_0xd70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xd70) {
            ctx->pc = 0xD84u;
            goto label_d84;
        }
    }
    ctx->pc = 0xD78u;
    // 0xd78: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0xd7c: 0x800037e  j           func_000DF8
    ctx->pc = 0xD7Cu;
    // 0xd80: 0xafa000a0  sw          $zero, 0xA0($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 0));
    ctx->pc = 0xDF8u;
    goto label_df8;
    ctx->pc = 0xD84u;
label_d84:
    // 0xd84: 0x8e020010  lw          $v0, 0x10($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0xd88: 0x0  nop
    // NOP
    // 0xd8c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0xD8Cu;
    {
        const bool branch_taken_0xd8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xd8c) {
            ctx->pc = 0xDC8u;
            goto label_dc8;
        }
    }
    ctx->pc = 0xD94u;
    // 0xd94: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xd98: 0x8e050008  lw          $a1, 0x8($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0xd9c: 0xc000481  jal         func_001204
    ctx->pc = 0xD9Cu;
    SET_GPR_U32(ctx, 31, 0xDA4u);
    ctx->pc = 0x1204u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1204u, 0xD9Cu, 0xDA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDA4u;
label_da4:
    // 0xda4: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xda8: 0x6210006  bgez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0xDA8u;
    {
        const bool branch_taken_0xda8 = (GPR_S32(ctx, 17) >= 0);
        if (branch_taken_0xda8) {
            ctx->pc = 0xDC4u;
            goto label_dc4;
        }
    }
    ctx->pc = 0xDB0u;
    // 0xdb0: 0x2411fff5  addiu       $s1, $zero, -0xB
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
    // 0xdb4: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0xdb8: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0xdbc: 0x8000372  j           func_000DC8
    ctx->pc = 0xDBCu;
    // 0xdc0: 0xafa000a0  sw          $zero, 0xA0($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 0));
    ctx->pc = 0xDC8u;
    goto label_dc8;
    ctx->pc = 0xDC4u;
label_dc4:
    // 0xdc4: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_dc8:
    // 0xdc8: 0x8e02000c  lw          $v0, 0xC($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0xdcc: 0x0  nop
    // NOP
    // 0xdd0: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0xDD0u;
    {
        const bool branch_taken_0xdd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xdd4: 0x27a400e0  addiu       $a0, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        if (branch_taken_0xdd0) {
            ctx->pc = 0xDFCu;
            goto label_dfc;
        }
    }
    ctx->pc = 0xDD8u;
    // 0xdd8: 0x6200009  bltz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0xDD8u;
    {
        const bool branch_taken_0xdd8 = (GPR_S32(ctx, 17) < 0);
        // 0xddc: 0x27a20010  addiu       $v0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        if (branch_taken_0xdd8) {
            ctx->pc = 0xE00u;
            goto label_e00;
        }
    }
    ctx->pc = 0xDE0u;
    // 0xde0: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xde4: 0x8e050008  lw          $a1, 0x8($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0xde8: 0xc000475  jal         func_0011D4
    ctx->pc = 0xDE8u;
    SET_GPR_U32(ctx, 31, 0xDF0u);
    ctx->pc = 0x11D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11D4u, 0xDE8u, 0xDF0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDF0u;
label_df0:
    // 0xdf0: 0x2102a  slt         $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0xdf4: 0xafa200a0  sw          $v0, 0xA0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 2));
label_df8:
    // 0xdf8: 0x27a400e0  addiu       $a0, $sp, 0xE0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
label_dfc:
    // 0xdfc: 0x27a20010  addiu       $v0, $sp, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_e00:
    // 0xe00: 0xafa200d0  sw          $v0, 0xD0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 208), GPR_U32(ctx, 2));
    // 0xe04: 0x8e03001c  lw          $v1, 0x1C($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0xe08: 0x240200c0  addiu       $v0, $zero, 0xC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0xe0c: 0xafa200d8  sw          $v0, 0xD8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 216), GPR_U32(ctx, 2));
    // 0xe10: 0xafa000dc  sw          $zero, 0xDC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 220), GPR_U32(ctx, 0));
    // 0xe14: 0xc0003f4  jal         func_000FD0
    ctx->pc = 0xE14u;
    SET_GPR_U32(ctx, 31, 0xE1Cu);
    // 0xe18: 0xafa300d4  sw          $v1, 0xD4($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 212), GPR_U32(ctx, 3));
    ctx->pc = 0xFD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD0u, 0xE14u, 0xE1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE1Cu;
label_e1c:
    // 0xe1c: 0x27a400d0  addiu       $a0, $sp, 0xD0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0xe20: 0xc000419  jal         func_001064
    ctx->pc = 0xE20u;
    SET_GPR_U32(ctx, 31, 0xE28u);
    // 0xe24: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1064u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1064u, 0xE20u, 0xE28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE28u;
label_e28:
    // 0xe28: 0x8fa400e0  lw          $a0, 0xE0($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 224)));
    // 0xe2c: 0xc0003f6  jal         func_000FD8
    ctx->pc = 0xE2Cu;
    SET_GPR_U32(ctx, 31, 0xE34u);
    // 0xe30: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xFD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFD8u, 0xE2Cu, 0xE34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE34u;
label_e34:
    // 0xe34: 0xc00041b  jal         func_00106C
    ctx->pc = 0xE34u;
    SET_GPR_U32(ctx, 31, 0xE3Cu);
    // 0xe38: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x106Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x106Cu, 0xE34u, 0xE3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE3Cu;
label_e3c:
    // 0xe3c: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0xE3Cu;
    {
        const bool branch_taken_0xe3c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0xe3c) {
            ctx->pc = 0xE54u;
            goto label_e54;
        }
    }
    ctx->pc = 0xE44u;
    // 0xe44: 0xc000449  jal         func_001124
    ctx->pc = 0xE44u;
    SET_GPR_U32(ctx, 31, 0xE4Cu);
    // 0xe48: 0x24040064  addiu       $a0, $zero, 0x64 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    ctx->pc = 0x1124u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1124u, 0xE44u, 0xE4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE4Cu;
label_e4c:
    // 0xe4c: 0x800038d  j           func_000E34
    ctx->pc = 0xE4Cu;
    ctx->pc = 0xE34u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_e34;
    ctx->pc = 0xE54u;
label_e54:
    // 0xe54: 0x6200002  bltz        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0xE54u;
    {
        const bool branch_taken_0xe54 = (GPR_S32(ctx, 17) < 0);
        // 0xe58: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0xe54) {
            ctx->pc = 0xE60u;
            goto label_e60;
        }
    }
    ctx->pc = 0xE5Cu;
    // 0xe5c: 0x2401021  addu        $v0, $s2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_e60:
    // 0xe60: 0x8fbf00f4  lw          $ra, 0xF4($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 244)));
    // 0xe64: 0x8fb200f0  lw          $s2, 0xF0($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0xe68: 0x8fb100ec  lw          $s1, 0xEC($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 236)));
    // 0xe6c: 0x8fb000e8  lw          $s0, 0xE8($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 232)));
    // 0xe70: 0x3e00008  jr          $ra
    ctx->pc = 0xE70u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe74: 0x27bd00f8  addiu       $sp, $sp, 0xF8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 248));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE70u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE78u;
label_e78:
    // 0xe78: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xe7c: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xe80: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xe84: 0x8cc40000  lw          $a0, 0x0($a2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0xe88: 0x8cc50004  lw          $a1, 0x4($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0xe8c: 0xc000477  jal         func_0011DC
    ctx->pc = 0xE8Cu;
    SET_GPR_U32(ctx, 31, 0xE94u);
    // 0xe90: 0x24c60014  addiu       $a2, $a2, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20));
    ctx->pc = 0x11DCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11DCu, 0xE8Cu, 0xE94u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE94u;
label_e94:
    // 0xe94: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xe98: 0x0  nop
    // NOP
    // 0xe9c: 0x3e00008  jr          $ra
    ctx->pc = 0xE9Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xea0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE9Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xEA4u;
label_ea4:
    // 0xea4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xea8: 0x803021  addu        $a2, $a0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xeac: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xeb0: 0x8cc40000  lw          $a0, 0x0($a2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0xeb4: 0x8cc50004  lw          $a1, 0x4($a2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0xeb8: 0x8cc70008  lw          $a3, 0x8($a2)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0xebc: 0xc00046b  jal         func_0011AC
    ctx->pc = 0xEBCu;
    SET_GPR_U32(ctx, 31, 0xEC4u);
    // 0xec0: 0x24c60014  addiu       $a2, $a2, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20));
    ctx->pc = 0x11ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11ACu, 0xEBCu, 0xEC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEC4u;
label_ec4:
    // 0xec4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xec8: 0x0  nop
    // NOP
    // 0xecc: 0x3e00008  jr          $ra
    ctx->pc = 0xECCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xed0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xECCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xED4u;
label_ed4:
    // 0xed4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xed8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xedc: 0x8c840000  lw          $a0, 0x0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0xee0: 0xc00046d  jal         func_0011B4
    ctx->pc = 0xEE0u;
    SET_GPR_U32(ctx, 31, 0xEE8u);
    ctx->pc = 0x11B4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11B4u, 0xEE0u, 0xEE8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEE8u;
label_ee8:
    // 0xee8: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xeec: 0x0  nop
    // NOP
    // 0xef0: 0x3e00008  jr          $ra
    ctx->pc = 0xEF0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xef4: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xEF0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xEF8u;
label_ef8:
    // 0xef8: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
    // 0xefc: 0xafb00038  sw          $s0, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 16));
    // 0xf00: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xf04: 0x27a40018  addiu       $a0, $sp, 0x18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0xf08: 0xafb1003c  sw          $s1, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 17));
    // 0xf0c: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
    // 0xf10: 0x263112b0  addiu       $s1, $s1, 0x12B0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4784));
    // 0xf14: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    // 0xf18: 0xafbf0040  sw          $ra, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 31));
    // 0xf1c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0xf20: 0x8e050010  lw          $a1, 0x10($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0xf24: 0xc00042e  jal         func_0010B8
    ctx->pc = 0xF24u;
    SET_GPR_U32(ctx, 31, 0xF2Cu);
    // 0xf28: 0x24070040  addiu       $a3, $zero, 0x40 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    ctx->pc = 0x10B8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x10B8u, 0xF24u, 0xF2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF2Cu;
label_f2c:
    // 0xf2c: 0x8e020008  lw          $v0, 0x8($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0xf30: 0x26060014  addiu       $a2, $s0, 0x14
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0xf34: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0xf38: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xf3c: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0xf40: 0xc000471  jal         func_0011C4
    ctx->pc = 0xF40u;
    SET_GPR_U32(ctx, 31, 0xF48u);
    // 0xf44: 0x2203821  addu        $a3, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x11C4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x11C4u, 0xF40u, 0xF48u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF48u;
label_f48:
    // 0xf48: 0x8fbf0040  lw          $ra, 0x40($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0xf4c: 0x8fb1003c  lw          $s1, 0x3C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0xf50: 0x8fb00038  lw          $s0, 0x38($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0xf54: 0x3e00008  jr          $ra
    ctx->pc = 0xF54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf58: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
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
label_f5c:
    // 0xf5c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xf60: 0x801021  addu        $v0, $a0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0xf64: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xf68: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0xf6c: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0xf70: 0x8c460010  lw          $a2, 0x10($v0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0xf74: 0xc000487  jal         func_00121C
    ctx->pc = 0xF74u;
    SET_GPR_U32(ctx, 31, 0xF7Cu);
    ctx->pc = 0x121Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x121Cu, 0xF74u, 0xF7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF7Cu;
label_f7c:
    // 0xf7c: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xf80: 0x0  nop
    // NOP
    // 0xf84: 0x3e00008  jr          $ra
    ctx->pc = 0xF84u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xf88: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF84u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF8Cu;
    // 0xf8c: 0x0  nop
    // NOP
    // 0xf90: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0xF90 raw=0x41E00000");
    // 0xf94: 0x0  nop
    // NOP
    // 0xf98: 0x103  sra         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, SRA32(GPR_S32(ctx, 0), 4));
    // 0xf9c: 0x64616f6c  daddiu      $at, $v1, 0x6F6C
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0xF9C raw=0x64616F6C");
    // 0xfa0: 0x65726f63  daddiu      $s2, $t3, 0x6F63
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0xFA0 raw=0x65726F63");
}


// Function: mcserv_00000fa4
// Address: 0xfa4 - 0xfac
void mcserv_00000fa4_0xfa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00000fa4_0xfa4");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: mcserv_00000fac
// Address: 0xfac - 0xfd0
void mcserv_00000fac_0xfac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00000fac_0xfac");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 7u);
}


// Function: mcserv_00000fd0
// Address: 0xfd0 - 0xfd8
void mcserv_00000fd0_0xfd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00000fd0_0xfd0");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: mcserv_00000fd8
// Address: 0xfd8 - 0xffc
void mcserv_00000fd8_0xfd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00000fd8_0xfd8");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: mcserv_00000ffc
// Address: 0xffc - 0x1004
void mcserv_00000ffc_0xffc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00000ffc_0xffc");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 12u);
}


// Function: mcserv_00001004
// Address: 0x1004 - 0x100c
void mcserv_00001004_0x1004(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001004_0x1004");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 14u);
}


// Function: mcserv_0000100c
// Address: 0x100c - 0x1014
void mcserv_0000100c_0x100c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000100c_0x100c");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


// Function: mcserv_00001014
// Address: 0x1014 - 0x1038
void mcserv_00001014_0x1014(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001014_0x1014");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 36u);
}


// Function: mcserv_00001038
// Address: 0x1038 - 0x105c
void mcserv_00001038_0x1038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001038_0x1038");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: mcserv_0000105c
// Address: 0x105c - 0x1064
void mcserv_0000105c_0x105c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000105c_0x105c");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 5u);
}


// Function: mcserv_00001064
// Address: 0x1064 - 0x106c
void mcserv_00001064_0x1064(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001064_0x1064");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 7u);
}


// Function: mcserv_0000106c
// Address: 0x106c - 0x1074
void mcserv_0000106c_0x106c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000106c_0x106c");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 8u);
}


// Function: mcserv_00001074
// Address: 0x1074 - 0x1098
void mcserv_00001074_0x1074(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001074_0x1074");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 29u);
}


// Function: mcserv_00001098
// Address: 0x1098 - 0x10a0
void mcserv_00001098_0x1098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001098_0x1098");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 14u);
}


// Function: mcserv_000010a0
// Address: 0x10a0 - 0x10a8
void mcserv_000010a0_0x10a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010a0_0x10a0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 17u);
}


// Function: mcserv_000010a8
// Address: 0x10a8 - 0x10b0
void mcserv_000010a8_0x10a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010a8_0x10a8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 19u);
}


// Function: mcserv_000010b0
// Address: 0x10b0 - 0x10b8
void mcserv_000010b0_0x10b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010b0_0x10b0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 22u);
}


// Function: mcserv_000010b8
// Address: 0x10b8 - 0x10c0
void mcserv_000010b8_0x10b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010b8_0x10b8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 23u);
}


// Function: mcserv_000010c0
// Address: 0x10c0 - 0x10c8
void mcserv_000010c0_0x10c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010c0_0x10c0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 24u);
}


// Function: mcserv_000010c8
// Address: 0x10c8 - 0x10ec
void mcserv_000010c8_0x10c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010c8_0x10c8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 25u);
}


// Function: mcserv_000010ec
// Address: 0x10ec - 0x10f4
void mcserv_000010ec_0x10ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010ec_0x10ec");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: mcserv_000010f4
// Address: 0x10f4 - 0x10fc
void mcserv_000010f4_0x10f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010f4_0x10f4");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 5u);
}


// Function: mcserv_000010fc
// Address: 0x10fc - 0x1104
void mcserv_000010fc_0x10fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000010fc_0x10fc");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: mcserv_00001104
// Address: 0x1104 - 0x110c
void mcserv_00001104_0x1104(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001104_0x1104");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 10u);
}


// Function: mcserv_0000110c
// Address: 0x110c - 0x1114
void mcserv_0000110c_0x110c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000110c_0x110c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 14u);
}


// Function: mcserv_00001114
// Address: 0x1114 - 0x111c
void mcserv_00001114_0x1114(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001114_0x1114");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 20u);
}


// Function: mcserv_0000111c
// Address: 0x111c - 0x1124
void mcserv_0000111c_0x111c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000111c_0x111c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 22u);
}


// Function: mcserv_00001124
// Address: 0x1124 - 0x1148
void mcserv_00001124_0x1124(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001124_0x1124");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 33u);
}


// Function: mcserv_00001148
// Address: 0x1148 - 0x1150
void mcserv_00001148_0x1148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001148_0x1148");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 6u);
}


// Function: mcserv_00001150
// Address: 0x1150 - 0x1174
void mcserv_00001150_0x1150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001150_0x1150");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 8u);
}


// Function: mcserv_00001174
// Address: 0x1174 - 0x117c
void mcserv_00001174_0x1174(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001174_0x1174");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 6u);
}


// Function: mcserv_0000117c
// Address: 0x117c - 0x1184
void mcserv_0000117c_0x117c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000117c_0x117c");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 7u);
}


// Function: mcserv_00001184
// Address: 0x1184 - 0x118c
void mcserv_00001184_0x1184(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001184_0x1184");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 8u);
}


// Function: mcserv_0000118c
// Address: 0x118c - 0x1194
void mcserv_0000118c_0x118c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000118c_0x118c");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 9u);
}


// Function: mcserv_00001194
// Address: 0x1194 - 0x119c
void mcserv_00001194_0x1194(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001194_0x1194");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 10u);
}


// Function: mcserv_0000119c
// Address: 0x119c - 0x11a4
void mcserv_0000119c_0x119c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000119c_0x119c");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 11u);
}


// Function: mcserv_000011a4
// Address: 0x11a4 - 0x11ac
void mcserv_000011a4_0x11a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011a4_0x11a4");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 12u);
}


// Function: mcserv_000011ac
// Address: 0x11ac - 0x11b4
void mcserv_000011ac_0x11ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011ac_0x11ac");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 13u);
}


// Function: mcserv_000011b4
// Address: 0x11b4 - 0x11bc
void mcserv_000011b4_0x11b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011b4_0x11b4");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 14u);
}


// Function: mcserv_000011bc
// Address: 0x11bc - 0x11c4
void mcserv_000011bc_0x11bc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011bc_0x11bc");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 15u);
}


// Function: mcserv_000011c4
// Address: 0x11c4 - 0x11cc
void mcserv_000011c4_0x11c4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011c4_0x11c4");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 16u);
}


// Function: mcserv_000011cc
// Address: 0x11cc - 0x11d4
void mcserv_000011cc_0x11cc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011cc_0x11cc");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 21u);
}


// Function: mcserv_000011d4
// Address: 0x11d4 - 0x11dc
void mcserv_000011d4_0x11d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011d4_0x11d4");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 22u);
}


// Function: mcserv_000011dc
// Address: 0x11dc - 0x11e4
void mcserv_000011dc_0x11dc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011dc_0x11dc");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 23u);
}


// Function: mcserv_000011e4
// Address: 0x11e4 - 0x11ec
void mcserv_000011e4_0x11e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011e4_0x11e4");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 24u);
}


// Function: mcserv_000011ec
// Address: 0x11ec - 0x11f4
void mcserv_000011ec_0x11ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011ec_0x11ec");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 26u);
}


// Function: mcserv_000011f4
// Address: 0x11f4 - 0x11fc
void mcserv_000011f4_0x11f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011f4_0x11f4");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 36u);
}


// Function: mcserv_000011fc
// Address: 0x11fc - 0x1204
void mcserv_000011fc_0x11fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_000011fc_0x11fc");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 37u);
}


// Function: mcserv_00001204
// Address: 0x1204 - 0x120c
void mcserv_00001204_0x1204(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001204_0x1204");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 38u);
}


// Function: mcserv_0000120c
// Address: 0x120c - 0x1214
void mcserv_0000120c_0x120c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000120c_0x120c");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 39u);
}


// Function: mcserv_00001214
// Address: 0x1214 - 0x121c
void mcserv_00001214_0x1214(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_00001214_0x1214");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 42u);
}


// Function: mcserv_0000121c
// Address: 0x121c - 0x1224
void mcserv_0000121c_0x121c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("mcserv_0000121c_0x121c");
#endif

    runtime->iopImport(rdram, ctx, "mcman", 45u);
}


