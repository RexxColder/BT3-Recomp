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

// Function: sounds_00000000
// Address: 0x0 - 0x374
void sounds_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000000_0x0");
#endif

    switch (ctx->pc) {
        case 0x0u: goto label_0;
        case 0x4u: goto label_4;
        case 0x8u: goto label_8;
        case 0xcu: goto label_c;
        case 0x10u: goto label_10;
        case 0x14u: goto label_14;
        case 0x18u: goto label_18;
        case 0x1cu: goto label_1c;
        case 0x20u: goto label_20;
        case 0x24u: goto label_24;
        case 0x28u: goto label_28;
        case 0x2cu: goto label_2c;
        case 0x30u: goto label_30;
        case 0x34u: goto label_34;
        case 0x38u: goto label_38;
        case 0x3cu: goto label_3c;
        case 0x40u: goto label_40;
        case 0x44u: goto label_44;
        case 0x48u: goto label_48;
        case 0x4cu: goto label_4c;
        case 0x50u: goto label_50;
        case 0x54u: goto label_54;
        case 0x58u: goto label_58;
        case 0x5cu: goto label_5c;
        case 0x60u: goto label_60;
        case 0x64u: goto label_64;
        case 0x68u: goto label_68;
        case 0x6cu: goto label_6c;
        case 0x70u: goto label_70;
        case 0x74u: goto label_74;
        case 0x78u: goto label_78;
        case 0x7cu: goto label_7c;
        case 0x80u: goto label_80;
        case 0x84u: goto label_84;
        case 0x88u: goto label_88;
        case 0x8cu: goto label_8c;
        case 0x90u: goto label_90;
        case 0x94u: goto label_94;
        case 0x98u: goto label_98;
        case 0x9cu: goto label_9c;
        case 0xa0u: goto label_a0;
        case 0xa4u: goto label_a4;
        case 0xa8u: goto label_a8;
        case 0xacu: goto label_ac;
        case 0xb0u: goto label_b0;
        case 0xb4u: goto label_b4;
        case 0xb8u: goto label_b8;
        case 0xbcu: goto label_bc;
        case 0xc0u: goto label_c0;
        case 0xc4u: goto label_c4;
        case 0xc8u: goto label_c8;
        case 0xccu: goto label_cc;
        case 0xd0u: goto label_d0;
        case 0xd4u: goto label_d4;
        case 0xd8u: goto label_d8;
        case 0xdcu: goto label_dc;
        case 0xe0u: goto label_e0;
        case 0xe4u: goto label_e4;
        case 0xe8u: goto label_e8;
        case 0xecu: goto label_ec;
        case 0xf0u: goto label_f0;
        case 0xf4u: goto label_f4;
        case 0xf8u: goto label_f8;
        case 0xfcu: goto label_fc;
        case 0x100u: goto label_100;
        case 0x104u: goto label_104;
        case 0x108u: goto label_108;
        case 0x10cu: goto label_10c;
        case 0x110u: goto label_110;
        case 0x114u: goto label_114;
        case 0x118u: goto label_118;
        case 0x11cu: goto label_11c;
        case 0x120u: goto label_120;
        case 0x124u: goto label_124;
        case 0x128u: goto label_128;
        case 0x12cu: goto label_12c;
        case 0x130u: goto label_130;
        case 0x134u: goto label_134;
        case 0x138u: goto label_138;
        case 0x13cu: goto label_13c;
        case 0x140u: goto label_140;
        case 0x144u: goto label_144;
        case 0x148u: goto label_148;
        case 0x14cu: goto label_14c;
        case 0x150u: goto label_150;
        case 0x154u: goto label_154;
        case 0x158u: goto label_158;
        case 0x15cu: goto label_15c;
        case 0x160u: goto label_160;
        case 0x164u: goto label_164;
        case 0x168u: goto label_168;
        case 0x16cu: goto label_16c;
        case 0x170u: goto label_170;
        case 0x174u: goto label_174;
        case 0x178u: goto label_178;
        case 0x17cu: goto label_17c;
        case 0x180u: goto label_180;
        case 0x184u: goto label_184;
        case 0x188u: goto label_188;
        case 0x18cu: goto label_18c;
        case 0x190u: goto label_190;
        case 0x194u: goto label_194;
        case 0x198u: goto label_198;
        case 0x19cu: goto label_19c;
        case 0x1a0u: goto label_1a0;
        case 0x1a4u: goto label_1a4;
        case 0x1a8u: goto label_1a8;
        case 0x1acu: goto label_1ac;
        case 0x1b0u: goto label_1b0;
        case 0x1b4u: goto label_1b4;
        case 0x1b8u: goto label_1b8;
        case 0x1bcu: goto label_1bc;
        case 0x1c0u: goto label_1c0;
        case 0x1c4u: goto label_1c4;
        case 0x1c8u: goto label_1c8;
        case 0x1ccu: goto label_1cc;
        case 0x1d0u: goto label_1d0;
        case 0x1d4u: goto label_1d4;
        case 0x1d8u: goto label_1d8;
        case 0x1dcu: goto label_1dc;
        case 0x1e0u: goto label_1e0;
        case 0x1e4u: goto label_1e4;
        case 0x1e8u: goto label_1e8;
        case 0x1ecu: goto label_1ec;
        case 0x1f0u: goto label_1f0;
        case 0x1f4u: goto label_1f4;
        case 0x1f8u: goto label_1f8;
        case 0x1fcu: goto label_1fc;
        case 0x200u: goto label_200;
        case 0x204u: goto label_204;
        case 0x208u: goto label_208;
        case 0x20cu: goto label_20c;
        case 0x210u: goto label_210;
        case 0x214u: goto label_214;
        case 0x218u: goto label_218;
        case 0x21cu: goto label_21c;
        case 0x220u: goto label_220;
        case 0x224u: goto label_224;
        case 0x228u: goto label_228;
        case 0x22cu: goto label_22c;
        case 0x230u: goto label_230;
        case 0x234u: goto label_234;
        case 0x238u: goto label_238;
        case 0x23cu: goto label_23c;
        case 0x240u: goto label_240;
        case 0x244u: goto label_244;
        case 0x248u: goto label_248;
        case 0x24cu: goto label_24c;
        case 0x250u: goto label_250;
        case 0x254u: goto label_254;
        case 0x258u: goto label_258;
        case 0x25cu: goto label_25c;
        case 0x260u: goto label_260;
        case 0x264u: goto label_264;
        case 0x268u: goto label_268;
        case 0x26cu: goto label_26c;
        case 0x270u: goto label_270;
        case 0x274u: goto label_274;
        case 0x278u: goto label_278;
        case 0x27cu: goto label_27c;
        case 0x280u: goto label_280;
        case 0x284u: goto label_284;
        case 0x288u: goto label_288;
        case 0x28cu: goto label_28c;
        case 0x290u: goto label_290;
        case 0x294u: goto label_294;
        case 0x298u: goto label_298;
        case 0x29cu: goto label_29c;
        case 0x2a0u: goto label_2a0;
        case 0x2a4u: goto label_2a4;
        case 0x2a8u: goto label_2a8;
        case 0x2acu: goto label_2ac;
        case 0x2b0u: goto label_2b0;
        case 0x2b4u: goto label_2b4;
        case 0x2b8u: goto label_2b8;
        case 0x2bcu: goto label_2bc;
        case 0x2c0u: goto label_2c0;
        case 0x2c4u: goto label_2c4;
        case 0x2c8u: goto label_2c8;
        case 0x2ccu: goto label_2cc;
        case 0x2d0u: goto label_2d0;
        case 0x2d4u: goto label_2d4;
        case 0x2d8u: goto label_2d8;
        case 0x2dcu: goto label_2dc;
        case 0x2e0u: goto label_2e0;
        case 0x2e4u: goto label_2e4;
        case 0x2e8u: goto label_2e8;
        case 0x2ecu: goto label_2ec;
        case 0x2f0u: goto label_2f0;
        case 0x2f4u: goto label_2f4;
        case 0x2f8u: goto label_2f8;
        case 0x2fcu: goto label_2fc;
        case 0x300u: goto label_300;
        case 0x304u: goto label_304;
        case 0x308u: goto label_308;
        case 0x30cu: goto label_30c;
        case 0x310u: goto label_310;
        case 0x314u: goto label_314;
        case 0x318u: goto label_318;
        case 0x31cu: goto label_31c;
        case 0x320u: goto label_320;
        case 0x324u: goto label_324;
        case 0x328u: goto label_328;
        case 0x32cu: goto label_32c;
        case 0x330u: goto label_330;
        case 0x334u: goto label_334;
        case 0x338u: goto label_338;
        case 0x33cu: goto label_33c;
        case 0x340u: goto label_340;
        case 0x344u: goto label_344;
        case 0x348u: goto label_348;
        case 0x34cu: goto label_34c;
        case 0x350u: goto label_350;
        case 0x354u: goto label_354;
        case 0x358u: goto label_358;
        case 0x35cu: goto label_35c;
        case 0x360u: goto label_360;
        case 0x364u: goto label_364;
        case 0x368u: goto label_368;
        case 0x36cu: goto label_36c;
        case 0x370u: goto label_370;
        default: break;
    }

    ctx->pc = 0x0u;

label_0:
    // 0x0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
label_4:
    // 0x4: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
label_8:
    // 0x8: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
label_c:
    // 0xc: 0xc000a05  jal         func_002814
label_10:
    if (ctx->pc == 0x10u) {
        // 0x10: 0x3a0f021  addu        $fp, $sp, $zero (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
        ctx->pc = 0x14u;
        goto label_14;
    }
    ctx->pc = 0xCu;
    SET_GPR_U32(ctx, 31, 0x14u);
    // 0x10: 0x3a0f021  addu        $fp, $sp, $zero (Delay Slot)
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    ctx->pc = 0x2814u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2814u, 0xCu, 0x14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14u;
label_14:
    // 0x14: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_18:
    if (ctx->pc == 0x18u) {
        ctx->pc = 0x1Cu;
        goto label_1c;
    }
    ctx->pc = 0x14u;
    {
        const bool branch_taken_0x14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x14) {
            ctx->pc = 0x24u;
            goto label_24;
        }
    }
    ctx->pc = 0x1Cu;
label_1c:
    // 0x1c: 0xc000a03  jal         func_00280C
label_20:
    if (ctx->pc == 0x20u) {
        ctx->pc = 0x24u;
        goto label_24;
    }
    ctx->pc = 0x1Cu;
    SET_GPR_U32(ctx, 31, 0x24u);
    ctx->pc = 0x280Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x280Cu, 0x1Cu, 0x24u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24u;
label_24:
    // 0x24: 0xc0009f4  jal         func_0027D0
label_28:
    if (ctx->pc == 0x28u) {
        // 0x28: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2Cu;
        goto label_2c;
    }
    ctx->pc = 0x24u;
    SET_GPR_U32(ctx, 31, 0x2Cu);
    // 0x28: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x27D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27D0u, 0x24u, 0x2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2Cu;
label_2c:
    // 0x2c: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
label_30:
    // 0x30: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_34:
    // 0x34: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_38:
    // 0x38: 0x24420374  addiu       $v0, $v0, 0x374
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 884));
label_3c:
    // 0x3c: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
label_40:
    // 0x40: 0x2402001d  addiu       $v0, $zero, 0x1D
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
label_44:
    // 0x44: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_48:
    // 0x48: 0x24021000  addiu       $v0, $zero, 0x1000
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
label_4c:
    // 0x4c: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
label_50:
    // 0x50: 0xafc00014  sw          $zero, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
label_54:
    // 0x54: 0xc000a17  jal         func_00285C
label_58:
    if (ctx->pc == 0x58u) {
        // 0x58: 0x27c40010  addiu       $a0, $fp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
        ctx->pc = 0x5Cu;
        goto label_5c;
    }
    ctx->pc = 0x54u;
    SET_GPR_U32(ctx, 31, 0x5Cu);
    // 0x58: 0x27c40010  addiu       $a0, $fp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    ctx->pc = 0x285Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x285Cu, 0x54u, 0x5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5Cu;
label_5c:
    // 0x5c: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
label_60:
    // 0x60: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
label_64:
    // 0x64: 0x0  nop
    // NOP
label_68:
    // 0x68: 0x18400008  blez        $v0, . + 4 + (0x8 << 2)
label_6c:
    if (ctx->pc == 0x6Cu) {
        ctx->pc = 0x70u;
        goto label_70;
    }
    ctx->pc = 0x68u;
    {
        const bool branch_taken_0x68 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x68) {
            ctx->pc = 0x8Cu;
            goto label_8c;
        }
    }
    ctx->pc = 0x70u;
label_70:
    // 0x70: 0x8fc40028  lw          $a0, 0x28($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
label_74:
    // 0x74: 0xc000a19  jal         func_002864
label_78:
    if (ctx->pc == 0x78u) {
        // 0x78: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x7Cu;
        goto label_7c;
    }
    ctx->pc = 0x74u;
    SET_GPR_U32(ctx, 31, 0x7Cu);
    // 0x78: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2864u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2864u, 0x74u, 0x7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7Cu;
label_7c:
    // 0x7c: 0x8000025  j           func_000094
label_80:
    if (ctx->pc == 0x80u) {
        // 0x80: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x84u;
        goto label_84;
    }
    ctx->pc = 0x7Cu;
    // 0x80: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x94u;
    goto label_94;
    ctx->pc = 0x84u;
label_84:
    // 0x84: 0x8000025  j           func_000094
label_88:
    if (ctx->pc == 0x88u) {
        ctx->pc = 0x8Cu;
        goto label_8c;
    }
    ctx->pc = 0x84u;
    ctx->pc = 0x94u;
    goto label_94;
    ctx->pc = 0x8Cu;
label_8c:
    // 0x8c: 0x8000025  j           func_000094
label_90:
    if (ctx->pc == 0x90u) {
        // 0x90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x94u;
        goto label_94;
    }
    ctx->pc = 0x8Cu;
    // 0x90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x94u;
    goto label_94;
    ctx->pc = 0x94u;
label_94:
    // 0x94: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
label_98:
    // 0x98: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_9c:
    // 0x9c: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_a0:
    // 0xa0: 0x3e00008  jr          $ra
label_a4:
    if (ctx->pc == 0xA4u) {
        // 0xa4: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = 0xA8u;
        goto label_a8;
    }
    ctx->pc = 0xA0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa4: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA8u;
label_a8:
    // 0xa8: 0x0  nop
    // NOP
label_ac:
    // 0xac: 0x0  nop
    // NOP
label_b0:
    // 0xb0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_b4:
    // 0xb4: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_b8:
    // 0xb8: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
label_bc:
    // 0xbc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
label_c0:
    // 0xc0: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
label_c4:
    // 0xc4: 0xafc5002c  sw          $a1, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 5));
label_c8:
    // 0xc8: 0xafc60030  sw          $a2, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 6));
label_cc:
    // 0xcc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
label_d0:
    // 0xd0: 0x0  nop
    // NOP
label_d4:
    // 0xd4: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_d8:
    // 0xd8: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
label_dc:
    // 0xdc: 0x0  nop
    // NOP
label_e0:
    // 0xe0: 0x2c430010  sltiu       $v1, $v0, 0x10
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
label_e4:
    // 0xe4: 0x10600094  beqz        $v1, . + 4 + (0x94 << 2)
label_e8:
    if (ctx->pc == 0xE8u) {
        ctx->pc = 0xECu;
        goto label_ec;
    }
    ctx->pc = 0xE4u;
    {
        const bool branch_taken_0xe4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0xe4) {
            ctx->pc = 0x338u;
            goto label_338;
        }
    }
    ctx->pc = 0xECu;
label_ec:
    // 0xec: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
label_f0:
    // 0xf0: 0x0  nop
    // NOP
label_f4:
    // 0xf4: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_f8:
    // 0xf8: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_fc:
    // 0xfc: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_100:
    // 0x100: 0x24632920  addiu       $v1, $v1, 0x2920
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 10528));
label_104:
    // 0x104: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_108:
    // 0x108: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_10c:
    // 0x10c: 0x0  nop
    // NOP
label_110:
    // 0x110: 0x600008  jr          $v1
label_114:
    if (ctx->pc == 0x114u) {
        ctx->pc = 0x118u;
        goto label_118;
    }
    ctx->pc = 0x110u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x110u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x118u;
label_118:
    // 0x118: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_11c:
    // 0x11c: 0xc000266  jal         func_000998
label_120:
    if (ctx->pc == 0x120u) {
        ctx->pc = 0x124u;
        goto label_124;
    }
    ctx->pc = 0x11Cu;
    SET_GPR_U32(ctx, 31, 0x124u);
    ctx->pc = 0x998u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x998u, 0x11Cu, 0x124u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x124u;
label_124:
    // 0x124: 0x80000d5  j           func_000354
label_128:
    if (ctx->pc == 0x128u) {
        ctx->pc = 0x12Cu;
        goto label_12c;
    }
    ctx->pc = 0x124u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x12Cu;
label_12c:
    // 0x12c: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_130:
    // 0x130: 0xc0003a8  jal         func_000EA0
label_134:
    if (ctx->pc == 0x134u) {
        ctx->pc = 0x138u;
        goto label_138;
    }
    ctx->pc = 0x130u;
    SET_GPR_U32(ctx, 31, 0x138u);
    ctx->pc = 0xEA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA0u, 0x130u, 0x138u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x138u;
label_138:
    // 0x138: 0x80000d5  j           func_000354
label_13c:
    if (ctx->pc == 0x13Cu) {
        ctx->pc = 0x140u;
        goto label_140;
    }
    ctx->pc = 0x138u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x140u;
label_140:
    // 0x140: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_144:
    // 0x144: 0xc0003b9  jal         func_000EE4
label_148:
    if (ctx->pc == 0x148u) {
        ctx->pc = 0x14Cu;
        goto label_14c;
    }
    ctx->pc = 0x144u;
    SET_GPR_U32(ctx, 31, 0x14Cu);
    ctx->pc = 0xEE4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEE4u, 0x144u, 0x14Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14Cu;
label_14c:
    // 0x14c: 0x80000d5  j           func_000354
label_150:
    if (ctx->pc == 0x150u) {
        ctx->pc = 0x154u;
        goto label_154;
    }
    ctx->pc = 0x14Cu;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x154u;
label_154:
    // 0x154: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_158:
    // 0x158: 0xc0003e9  jal         func_000FA4
label_15c:
    if (ctx->pc == 0x15Cu) {
        ctx->pc = 0x160u;
        goto label_160;
    }
    ctx->pc = 0x158u;
    SET_GPR_U32(ctx, 31, 0x160u);
    ctx->pc = 0xFA4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xFA4u, 0x158u, 0x160u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x160u;
label_160:
    // 0x160: 0x80000d5  j           func_000354
label_164:
    if (ctx->pc == 0x164u) {
        ctx->pc = 0x168u;
        goto label_168;
    }
    ctx->pc = 0x160u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x168u;
label_168:
    // 0x168: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_16c:
    // 0x16c: 0xc00051c  jal         func_001470
label_170:
    if (ctx->pc == 0x170u) {
        ctx->pc = 0x174u;
        goto label_174;
    }
    ctx->pc = 0x16Cu;
    SET_GPR_U32(ctx, 31, 0x174u);
    ctx->pc = 0x1470u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1470u, 0x16Cu, 0x174u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x174u;
label_174:
    // 0x174: 0x80000d5  j           func_000354
label_178:
    if (ctx->pc == 0x178u) {
        ctx->pc = 0x17Cu;
        goto label_17c;
    }
    ctx->pc = 0x174u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x17Cu;
label_17c:
    // 0x17c: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_180:
    // 0x180: 0xc000839  jal         func_0020E4
label_184:
    if (ctx->pc == 0x184u) {
        ctx->pc = 0x188u;
        goto label_188;
    }
    ctx->pc = 0x180u;
    SET_GPR_U32(ctx, 31, 0x188u);
    ctx->pc = 0x20E4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x20E4u, 0x180u, 0x188u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x188u;
label_188:
    // 0x188: 0x80000d5  j           func_000354
label_18c:
    if (ctx->pc == 0x18Cu) {
        ctx->pc = 0x190u;
        goto label_190;
    }
    ctx->pc = 0x188u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x190u;
label_190:
    // 0x190: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_194:
    // 0x194: 0xc0007f5  jal         func_001FD4
label_198:
    if (ctx->pc == 0x198u) {
        ctx->pc = 0x19Cu;
        goto label_19c;
    }
    ctx->pc = 0x194u;
    SET_GPR_U32(ctx, 31, 0x19Cu);
    ctx->pc = 0x1FD4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1FD4u, 0x194u, 0x19Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19Cu;
label_19c:
    // 0x19c: 0x80000d5  j           func_000354
label_1a0:
    if (ctx->pc == 0x1A0u) {
        ctx->pc = 0x1A4u;
        goto label_1a4;
    }
    ctx->pc = 0x19Cu;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x1A4u;
label_1a4:
    // 0x1a4: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1a8:
    // 0x1a8: 0xc000883  jal         func_00220C
label_1ac:
    if (ctx->pc == 0x1ACu) {
        ctx->pc = 0x1B0u;
        goto label_1b0;
    }
    ctx->pc = 0x1A8u;
    SET_GPR_U32(ctx, 31, 0x1B0u);
    ctx->pc = 0x220Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x220Cu, 0x1A8u, 0x1B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B0u;
label_1b0:
    // 0x1b0: 0x80000d5  j           func_000354
label_1b4:
    if (ctx->pc == 0x1B4u) {
        ctx->pc = 0x1B8u;
        goto label_1b8;
    }
    ctx->pc = 0x1B0u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x1B8u;
label_1b8:
    // 0x1b8: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1bc:
    // 0x1bc: 0xc000855  jal         func_002154
label_1c0:
    if (ctx->pc == 0x1C0u) {
        ctx->pc = 0x1C4u;
        goto label_1c4;
    }
    ctx->pc = 0x1BCu;
    SET_GPR_U32(ctx, 31, 0x1C4u);
    ctx->pc = 0x2154u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2154u, 0x1BCu, 0x1C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C4u;
label_1c4:
    // 0x1c4: 0x80000d5  j           func_000354
label_1c8:
    if (ctx->pc == 0x1C8u) {
        ctx->pc = 0x1CCu;
        goto label_1cc;
    }
    ctx->pc = 0x1C4u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x1CCu;
label_1cc:
    // 0x1cc: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1d0:
    // 0x1d0: 0xc000552  jal         func_001548
label_1d4:
    if (ctx->pc == 0x1D4u) {
        ctx->pc = 0x1D8u;
        goto label_1d8;
    }
    ctx->pc = 0x1D0u;
    SET_GPR_U32(ctx, 31, 0x1D8u);
    ctx->pc = 0x1548u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1548u, 0x1D0u, 0x1D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D8u;
label_1d8:
    // 0x1d8: 0x80000d5  j           func_000354
label_1dc:
    if (ctx->pc == 0x1DCu) {
        ctx->pc = 0x1E0u;
        goto label_1e0;
    }
    ctx->pc = 0x1D8u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x1E0u;
label_1e0:
    // 0x1e0: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1e4:
    // 0x1e4: 0xc000768  jal         func_001DA0
label_1e8:
    if (ctx->pc == 0x1E8u) {
        ctx->pc = 0x1ECu;
        goto label_1ec;
    }
    ctx->pc = 0x1E4u;
    SET_GPR_U32(ctx, 31, 0x1ECu);
    ctx->pc = 0x1DA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1DA0u, 0x1E4u, 0x1ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1ECu;
label_1ec:
    // 0x1ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1f0:
    // 0x1f0: 0x80000d5  j           func_000354
label_1f4:
    if (ctx->pc == 0x1F4u) {
        // 0x1f4: 0xac223140  sw          $v0, 0x3140($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 12608), GPR_U32(ctx, 2));
        ctx->pc = 0x1F8u;
        goto label_1f8;
    }
    ctx->pc = 0x1F0u;
    // 0x1f4: 0xac223140  sw          $v0, 0x3140($at) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12608), GPR_U32(ctx, 2));
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x1F8u;
label_1f8:
    // 0x1f8: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1fc:
    // 0x1fc: 0xc0007b9  jal         func_001EE4
label_200:
    if (ctx->pc == 0x200u) {
        ctx->pc = 0x204u;
        goto label_204;
    }
    ctx->pc = 0x1FCu;
    SET_GPR_U32(ctx, 31, 0x204u);
    ctx->pc = 0x1EE4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1EE4u, 0x1FCu, 0x204u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x204u;
label_204:
    // 0x204: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_208:
    // 0x208: 0x80000d5  j           func_000354
label_20c:
    if (ctx->pc == 0x20Cu) {
        // 0x20c: 0xac223140  sw          $v0, 0x3140($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 12608), GPR_U32(ctx, 2));
        ctx->pc = 0x210u;
        goto label_210;
    }
    ctx->pc = 0x208u;
    // 0x20c: 0xac223140  sw          $v0, 0x3140($at) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12608), GPR_U32(ctx, 2));
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x210u;
label_210:
    // 0x210: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_214:
    // 0x214: 0xc0008c0  jal         func_002300
label_218:
    if (ctx->pc == 0x218u) {
        ctx->pc = 0x21Cu;
        goto label_21c;
    }
    ctx->pc = 0x214u;
    SET_GPR_U32(ctx, 31, 0x21Cu);
    ctx->pc = 0x2300u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2300u, 0x214u, 0x21Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x21Cu;
label_21c:
    // 0x21c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_220:
    // 0x220: 0x80000d5  j           func_000354
label_224:
    if (ctx->pc == 0x224u) {
        // 0x224: 0xac223140  sw          $v0, 0x3140($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 12608), GPR_U32(ctx, 2));
        ctx->pc = 0x228u;
        goto label_228;
    }
    ctx->pc = 0x220u;
    // 0x224: 0xac223140  sw          $v0, 0x3140($at) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12608), GPR_U32(ctx, 2));
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x228u;
label_228:
    // 0x228: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_22c:
    // 0x22c: 0x0  nop
    // NOP
label_230:
    // 0x230: 0x24430004  addiu       $v1, $v0, 0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
label_234:
    // 0x234: 0xafc30014  sw          $v1, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
label_238:
    // 0x238: 0xafc00018  sw          $zero, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
label_23c:
    // 0x23c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_240:
    // 0x240: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_244:
    // 0x244: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_248:
    // 0x248: 0x0  nop
    // NOP
label_24c:
    // 0x24c: 0x62182b  sltu        $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_250:
    // 0x250: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
label_254:
    if (ctx->pc == 0x254u) {
        ctx->pc = 0x258u;
        goto label_258;
    }
    ctx->pc = 0x250u;
    {
        const bool branch_taken_0x250 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x250) {
            ctx->pc = 0x260u;
            goto label_260;
        }
    }
    ctx->pc = 0x258u;
label_258:
    // 0x258: 0x80000c2  j           func_000308
label_25c:
    if (ctx->pc == 0x25Cu) {
        ctx->pc = 0x260u;
        goto label_260;
    }
    ctx->pc = 0x258u;
    ctx->pc = 0x308u;
    goto label_308;
    ctx->pc = 0x260u;
label_260:
    // 0x260: 0x8fc30014  lw          $v1, 0x14($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_264:
    // 0x264: 0x0  nop
    // NOP
label_268:
    // 0x268: 0x90620000  lbu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
label_26c:
    // 0x26c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_270:
    // 0x270: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
label_274:
    if (ctx->pc == 0x274u) {
        ctx->pc = 0x278u;
        goto label_278;
    }
    ctx->pc = 0x270u;
    {
        const bool branch_taken_0x270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x270) {
            ctx->pc = 0x2BCu;
            goto label_2bc;
        }
    }
    ctx->pc = 0x278u;
label_278:
    // 0x278: 0x28430002  slti        $v1, $v0, 0x2
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
label_27c:
    // 0x27c: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
label_280:
    if (ctx->pc == 0x280u) {
        ctx->pc = 0x284u;
        goto label_284;
    }
    ctx->pc = 0x27Cu;
    {
        const bool branch_taken_0x27c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x27c) {
            ctx->pc = 0x294u;
            goto label_294;
        }
    }
    ctx->pc = 0x284u;
label_284:
    // 0x284: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_288:
    if (ctx->pc == 0x288u) {
        ctx->pc = 0x28Cu;
        goto label_28c;
    }
    ctx->pc = 0x284u;
    {
        const bool branch_taken_0x284 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x284) {
            ctx->pc = 0x2A8u;
            goto label_2a8;
        }
    }
    ctx->pc = 0x28Cu;
label_28c:
    // 0x28c: 0x80000b9  j           func_0002E4
label_290:
    if (ctx->pc == 0x290u) {
        ctx->pc = 0x294u;
        goto label_294;
    }
    ctx->pc = 0x28Cu;
    ctx->pc = 0x2E4u;
    goto label_2e4;
    ctx->pc = 0x294u;
label_294:
    // 0x294: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_298:
    // 0x298: 0x1043000d  beq         $v0, $v1, . + 4 + (0xD << 2)
label_29c:
    if (ctx->pc == 0x29Cu) {
        ctx->pc = 0x2A0u;
        goto label_2a0;
    }
    ctx->pc = 0x298u;
    {
        const bool branch_taken_0x298 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x298) {
            ctx->pc = 0x2D0u;
            goto label_2d0;
        }
    }
    ctx->pc = 0x2A0u;
label_2a0:
    // 0x2a0: 0x80000b9  j           func_0002E4
label_2a4:
    if (ctx->pc == 0x2A4u) {
        ctx->pc = 0x2A8u;
        goto label_2a8;
    }
    ctx->pc = 0x2A0u;
    ctx->pc = 0x2E4u;
    goto label_2e4;
    ctx->pc = 0x2A8u;
label_2a8:
    // 0x2a8: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_2ac:
    // 0x2ac: 0xc000613  jal         func_00184C
label_2b0:
    if (ctx->pc == 0x2B0u) {
        ctx->pc = 0x2B4u;
        goto label_2b4;
    }
    ctx->pc = 0x2ACu;
    SET_GPR_U32(ctx, 31, 0x2B4u);
    ctx->pc = 0x184Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x184Cu, 0x2ACu, 0x2B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B4u;
label_2b4:
    // 0x2b4: 0x80000b9  j           func_0002E4
label_2b8:
    if (ctx->pc == 0x2B8u) {
        ctx->pc = 0x2BCu;
        goto label_2bc;
    }
    ctx->pc = 0x2B4u;
    ctx->pc = 0x2E4u;
    goto label_2e4;
    ctx->pc = 0x2BCu;
label_2bc:
    // 0x2bc: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_2c0:
    // 0x2c0: 0xc0006ac  jal         func_001AB0
label_2c4:
    if (ctx->pc == 0x2C4u) {
        ctx->pc = 0x2C8u;
        goto label_2c8;
    }
    ctx->pc = 0x2C0u;
    SET_GPR_U32(ctx, 31, 0x2C8u);
    ctx->pc = 0x1AB0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1AB0u, 0x2C0u, 0x2C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2C8u;
label_2c8:
    // 0x2c8: 0x80000b9  j           func_0002E4
label_2cc:
    if (ctx->pc == 0x2CCu) {
        ctx->pc = 0x2D0u;
        goto label_2d0;
    }
    ctx->pc = 0x2C8u;
    ctx->pc = 0x2E4u;
    goto label_2e4;
    ctx->pc = 0x2D0u;
label_2d0:
    // 0x2d0: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_2d4:
    // 0x2d4: 0xc000717  jal         func_001C5C
label_2d8:
    if (ctx->pc == 0x2D8u) {
        ctx->pc = 0x2DCu;
        goto label_2dc;
    }
    ctx->pc = 0x2D4u;
    SET_GPR_U32(ctx, 31, 0x2DCu);
    ctx->pc = 0x1C5Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1C5Cu, 0x2D4u, 0x2DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DCu;
label_2dc:
    // 0x2dc: 0x80000b9  j           func_0002E4
label_2e0:
    if (ctx->pc == 0x2E0u) {
        ctx->pc = 0x2E4u;
        goto label_2e4;
    }
    ctx->pc = 0x2DCu;
    ctx->pc = 0x2E4u;
    goto label_2e4;
    ctx->pc = 0x2E4u;
label_2e4:
    // 0x2e4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
label_2e8:
    // 0x2e8: 0x0  nop
    // NOP
label_2ec:
    // 0x2ec: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_2f0:
    // 0x2f0: 0xafc30018  sw          $v1, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
label_2f4:
    // 0x2f4: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_2f8:
    // 0x2f8: 0x0  nop
    // NOP
label_2fc:
    // 0x2fc: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_300:
    // 0x300: 0x800008f  j           func_00023C
label_304:
    if (ctx->pc == 0x304u) {
        // 0x304: 0xafc30014  sw          $v1, 0x14($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
        ctx->pc = 0x308u;
        goto label_308;
    }
    ctx->pc = 0x300u;
    // 0x304: 0xafc30014  sw          $v1, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
    ctx->pc = 0x23Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_23c;
    ctx->pc = 0x308u;
label_308:
    // 0x308: 0x80000d5  j           func_000354
label_30c:
    if (ctx->pc == 0x30Cu) {
        ctx->pc = 0x310u;
        goto label_310;
    }
    ctx->pc = 0x308u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x310u;
label_310:
    // 0x310: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_314:
    // 0x314: 0xc0008f8  jal         func_0023E0
label_318:
    if (ctx->pc == 0x318u) {
        ctx->pc = 0x31Cu;
        goto label_31c;
    }
    ctx->pc = 0x314u;
    SET_GPR_U32(ctx, 31, 0x31Cu);
    ctx->pc = 0x23E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x23E0u, 0x314u, 0x31Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x31Cu;
label_31c:
    // 0x31c: 0x80000d5  j           func_000354
label_320:
    if (ctx->pc == 0x320u) {
        ctx->pc = 0x324u;
        goto label_324;
    }
    ctx->pc = 0x31Cu;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x324u;
label_324:
    // 0x324: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_328:
    // 0x328: 0xc000944  jal         func_002510
label_32c:
    if (ctx->pc == 0x32Cu) {
        ctx->pc = 0x330u;
        goto label_330;
    }
    ctx->pc = 0x328u;
    SET_GPR_U32(ctx, 31, 0x330u);
    ctx->pc = 0x2510u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2510u, 0x328u, 0x330u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x330u;
label_330:
    // 0x330: 0x80000d5  j           func_000354
label_334:
    if (ctx->pc == 0x334u) {
        ctx->pc = 0x338u;
        goto label_338;
    }
    ctx->pc = 0x330u;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x338u;
label_338:
    // 0x338: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_33c:
    // 0x33c: 0x248428f0  addiu       $a0, $a0, 0x28F0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10480));
label_340:
    // 0x340: 0x8fc50028  lw          $a1, 0x28($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
label_344:
    // 0x344: 0xc0009eb  jal         func_0027AC
label_348:
    if (ctx->pc == 0x348u) {
        ctx->pc = 0x34Cu;
        goto label_34c;
    }
    ctx->pc = 0x344u;
    SET_GPR_U32(ctx, 31, 0x34Cu);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x344u, 0x34Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34Cu;
label_34c:
    // 0x34c: 0x80000d5  j           func_000354
label_350:
    if (ctx->pc == 0x350u) {
        ctx->pc = 0x354u;
        goto label_354;
    }
    ctx->pc = 0x34Cu;
    ctx->pc = 0x354u;
    goto label_354;
    ctx->pc = 0x354u;
label_354:
    // 0x354: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_358:
    // 0x358: 0x80000d8  j           func_000360
label_35c:
    if (ctx->pc == 0x35Cu) {
        // 0x35c: 0x24423140  addiu       $v0, $v0, 0x3140 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12608));
        ctx->pc = 0x360u;
        goto label_360;
    }
    ctx->pc = 0x358u;
    // 0x35c: 0x24423140  addiu       $v0, $v0, 0x3140 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12608));
    ctx->pc = 0x360u;
    goto label_360;
    ctx->pc = 0x360u;
label_360:
    // 0x360: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
label_364:
    // 0x364: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_368:
    // 0x368: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_36c:
    // 0x36c: 0x3e00008  jr          $ra
label_370:
    if (ctx->pc == 0x370u) {
        // 0x370: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x374u;
        goto label_fallthrough_0x36c;
    }
    ctx->pc = 0x36Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x370: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x36Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0x36c:
    ctx->pc = 0x374u;
}


// Function: sounds_00000374
// Address: 0x374 - 0x400
void sounds_00000374_0x374(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000374_0x374");
#endif

    switch (ctx->pc) {
        case 0x38cu: goto label_38c;
        case 0x394u: goto label_394;
        case 0x3a0u: goto label_3a0;
        case 0x3d8u: goto label_3d8;
        case 0x3e0u: goto label_3e0;
        default: break;
    }

    ctx->pc = 0x374u;

    // 0x374: 0x27bdff78  addiu       $sp, $sp, -0x88
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967160));
    // 0x378: 0xafbf0084  sw          $ra, 0x84($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 132), GPR_U32(ctx, 31));
    // 0x37c: 0xafbe0080  sw          $fp, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 30));
    // 0x380: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x384: 0xc0009f4  jal         func_0027D0
    ctx->pc = 0x384u;
    SET_GPR_U32(ctx, 31, 0x38Cu);
    // 0x388: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x27D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27D0u, 0x384u, 0x38Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x38Cu;
label_38c:
    // 0x38c: 0xc000a1b  jal         func_00286C
    ctx->pc = 0x38Cu;
    SET_GPR_U32(ctx, 31, 0x394u);
    ctx->pc = 0x286Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x286Cu, 0x38Cu, 0x394u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x394u;
label_394:
    // 0x394: 0x27c40020  addiu       $a0, $fp, 0x20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x398: 0xc0009f8  jal         func_0027E0
    ctx->pc = 0x398u;
    SET_GPR_U32(ctx, 31, 0x3A0u);
    // 0x39c: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x27E0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27E0u, 0x398u, 0x3A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3A0u;
label_3a0:
    // 0x3a0: 0x27c20038  addiu       $v0, $fp, 0x38
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 56));
    // 0x3a4: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x3a8: 0xafa00014  sw          $zero, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x3ac: 0x27c30020  addiu       $v1, $fp, 0x20
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x3b0: 0xafa30018  sw          $v1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x3b4: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x3b8: 0x3c050200  lui         $a1, 0x200
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)512 << 16));
    // 0x3bc: 0x34a50004  ori         $a1, $a1, 0x4
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4);
    // 0x3c0: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x3c4: 0x24c600b0  addiu       $a2, $a2, 0xB0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 176));
    // 0x3c8: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
    // 0x3cc: 0x24e73160  addiu       $a3, $a3, 0x3160
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 12640));
    // 0x3d0: 0xc0009f6  jal         func_0027D8
    ctx->pc = 0x3D0u;
    SET_GPR_U32(ctx, 31, 0x3D8u);
    ctx->pc = 0x27D8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27D8u, 0x3D0u, 0x3D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D8u;
label_3d8:
    // 0x3d8: 0xc0009fa  jal         func_0027E8
    ctx->pc = 0x3D8u;
    SET_GPR_U32(ctx, 31, 0x3E0u);
    // 0x3dc: 0x27c40020  addiu       $a0, $fp, 0x20 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    ctx->pc = 0x27E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27E8u, 0x3D8u, 0x3E0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E0u;
label_3e0:
    // 0x3e0: 0x80000fa  j           func_0003E8
    ctx->pc = 0x3E0u;
    // 0x3e4: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x3E8u;
    goto label_3e8;
    ctx->pc = 0x3E8u;
label_3e8:
    // 0x3e8: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x3ec: 0x8fbf0084  lw          $ra, 0x84($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 132)));
    // 0x3f0: 0x8fbe0080  lw          $fp, 0x80($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x3f4: 0x3e00008  jr          $ra
    ctx->pc = 0x3F4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3f8: 0x27bd0088  addiu       $sp, $sp, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 136));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3F4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3FCu;
    // 0x3fc: 0x0  nop
    // NOP
}


// Function: sounds_00000400
// Address: 0x400 - 0x49c
void sounds_00000400_0x400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000400_0x400");
#endif

    switch (ctx->pc) {
        case 0x418u: goto label_418;
        default: break;
    }

    ctx->pc = 0x400u;

    // 0x400: 0x27bdfff0  addiu       $sp, $sp, -0x10
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x404: 0xafbe0008  sw          $fp, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x408: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x40c: 0xafc40010  sw          $a0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 4));
    // 0x410: 0xafc00000  sw          $zero, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x414: 0xafc00004  sw          $zero, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_418:
    // 0x418: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x41c: 0x0  nop
    // NOP
    // 0x420: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x424: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x424u;
    {
        const bool branch_taken_0x424 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x424) {
            ctx->pc = 0x434u;
            goto label_434;
        }
    }
    ctx->pc = 0x42Cu;
    // 0x42c: 0x800011f  j           func_00047C
    ctx->pc = 0x42Cu;
    ctx->pc = 0x47Cu;
    goto label_47c;
    ctx->pc = 0x434u;
label_434:
    // 0x434: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x438: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x43c: 0x0  nop
    // NOP
    // 0x440: 0x621004  sllv        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
    // 0x444: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x448: 0x0  nop
    // NOP
    // 0x44c: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x450: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x450u;
    {
        const bool branch_taken_0x450 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x450) {
            ctx->pc = 0x468u;
            goto label_468;
        }
    }
    ctx->pc = 0x458u;
    // 0x458: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x45c: 0x0  nop
    // NOP
    // 0x460: 0x800011f  j           func_00047C
    ctx->pc = 0x460u;
    // 0x464: 0xafc20000  sw          $v0, 0x0($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x47Cu;
    goto label_47c;
    ctx->pc = 0x468u;
label_468:
    // 0x468: 0x8fc20004  lw          $v0, 0x4($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x46c: 0x0  nop
    // NOP
    // 0x470: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x474: 0x8000106  j           func_000418
    ctx->pc = 0x474u;
    // 0x478: 0xafc30004  sw          $v1, 0x4($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 3));
    ctx->pc = 0x418u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_418;
    ctx->pc = 0x47Cu;
label_47c:
    // 0x47c: 0x8fc30000  lw          $v1, 0x0($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x480: 0x0  nop
    // NOP
    // 0x484: 0x8000123  j           func_00048C
    ctx->pc = 0x484u;
    // 0x488: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x48Cu;
    goto label_48c;
    ctx->pc = 0x48Cu;
label_48c:
    // 0x48c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x490: 0x8fbe0008  lw          $fp, 0x8($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x494: 0x3e00008  jr          $ra
    ctx->pc = 0x494u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x498: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x494u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x49Cu;
}


// Function: sounds_0000049c
// Address: 0x49c - 0x500
void sounds_0000049c_0x49c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000049c_0x49c");
#endif

    switch (ctx->pc) {
        case 0x4e4u: goto label_4e4;
        default: break;
    }

    ctx->pc = 0x49cu;

    // 0x49c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x4a0: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x4a4: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x4a8: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x4ac: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x4b0: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x4b4: 0x0  nop
    // NOP
    // 0x4b8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x4B8u;
    {
        const bool branch_taken_0x4b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4b8) {
            ctx->pc = 0x4D0u;
            goto label_4d0;
        }
    }
    ctx->pc = 0x4C0u;
    // 0x4c0: 0x800013b  j           func_0004EC
    ctx->pc = 0x4C0u;
    // 0x4c4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4ECu;
    goto label_4ec;
    ctx->pc = 0x4C8u;
    // 0x4c8: 0x800013b  j           func_0004EC
    ctx->pc = 0x4C8u;
    ctx->pc = 0x4ECu;
    goto label_4ec;
    ctx->pc = 0x4D0u;
label_4d0:
    // 0x4d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4d4: 0x24842960  addiu       $a0, $a0, 0x2960
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10592));
    // 0x4d8: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x4dc: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x4DCu;
    SET_GPR_U32(ctx, 31, 0x4E4u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x4DCu, 0x4E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4E4u;
label_4e4:
    // 0x4e4: 0x800013b  j           func_0004EC
    ctx->pc = 0x4E4u;
    // 0x4e8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x4ECu;
    goto label_4ec;
    ctx->pc = 0x4ECu;
label_4ec:
    // 0x4ec: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x4f0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x4f4: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x4f8: 0x3e00008  jr          $ra
    ctx->pc = 0x4F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4fc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x500u;
}


// Function: sounds_00000500
// Address: 0x500 - 0x564
void sounds_00000500_0x500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000500_0x500");
#endif

    switch (ctx->pc) {
        case 0x548u: goto label_548;
        default: break;
    }

    ctx->pc = 0x500u;

    // 0x500: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x504: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x508: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x50c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x510: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x514: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x518: 0x0  nop
    // NOP
    // 0x51c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x51Cu;
    {
        const bool branch_taken_0x51c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x51c) {
            ctx->pc = 0x534u;
            goto label_534;
        }
    }
    ctx->pc = 0x524u;
    // 0x524: 0x8000154  j           func_000550
    ctx->pc = 0x524u;
    // 0x528: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x550u;
    goto label_550;
    ctx->pc = 0x52Cu;
    // 0x52c: 0x8000154  j           func_000550
    ctx->pc = 0x52Cu;
    ctx->pc = 0x550u;
    goto label_550;
    ctx->pc = 0x534u;
label_534:
    // 0x534: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x538: 0x24842994  addiu       $a0, $a0, 0x2994
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10644));
    // 0x53c: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x540: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x540u;
    SET_GPR_U32(ctx, 31, 0x548u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x540u, 0x548u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x548u;
label_548:
    // 0x548: 0x8000154  j           func_000550
    ctx->pc = 0x548u;
    // 0x54c: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x550u;
    goto label_550;
    ctx->pc = 0x550u;
label_550:
    // 0x550: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x554: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x558: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x55c: 0x3e00008  jr          $ra
    ctx->pc = 0x55Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x560: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x55Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x564u;
}


// Function: sounds_00000564
// Address: 0x564 - 0x5d4
void sounds_00000564_0x564(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000564_0x564");
#endif

    switch (ctx->pc) {
        case 0x5b8u: goto label_5b8;
        default: break;
    }

    ctx->pc = 0x564u;

    // 0x564: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x568: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x56c: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x570: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x574: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x578: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x57c: 0x0  nop
    // NOP
    // 0x580: 0x31603  sra         $v0, $v1, 24
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 24));
    // 0x584: 0x304300f8  andi        $v1, $v0, 0xF8
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)248);
    // 0x588: 0x240200f8  addiu       $v0, $zero, 0xF8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x58c: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x58Cu;
    {
        const bool branch_taken_0x58c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x58c) {
            ctx->pc = 0x5A4u;
            goto label_5a4;
        }
    }
    ctx->pc = 0x594u;
    // 0x594: 0x8000170  j           func_0005C0
    ctx->pc = 0x594u;
    // 0x598: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x5C0u;
    goto label_5c0;
    ctx->pc = 0x59Cu;
    // 0x59c: 0x8000170  j           func_0005C0
    ctx->pc = 0x59Cu;
    ctx->pc = 0x5C0u;
    goto label_5c0;
    ctx->pc = 0x5A4u;
label_5a4:
    // 0x5a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x5a8: 0x248429c8  addiu       $a0, $a0, 0x29C8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10696));
    // 0x5ac: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x5b0: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x5B0u;
    SET_GPR_U32(ctx, 31, 0x5B8u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x5B0u, 0x5B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5B8u;
label_5b8:
    // 0x5b8: 0x8000170  j           func_0005C0
    ctx->pc = 0x5B8u;
    // 0x5bc: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x5C0u;
    goto label_5c0;
    ctx->pc = 0x5C0u;
label_5c0:
    // 0x5c0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x5c4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x5c8: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x5cc: 0x3e00008  jr          $ra
    ctx->pc = 0x5CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x5d0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x5CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x5D4u;
}


// Function: sounds_000005d4
// Address: 0x5d4 - 0x660
void sounds_000005d4_0x5d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000005d4_0x5d4");
#endif

    switch (ctx->pc) {
        case 0x644u: goto label_644;
        default: break;
    }

    ctx->pc = 0x5d4u;

    // 0x5d4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x5d8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x5dc: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x5e0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x5e4: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x5e8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x5ec: 0x0  nop
    // NOP
    // 0x5f0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x5F0u;
    {
        const bool branch_taken_0x5f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x5f0) {
            ctx->pc = 0x608u;
            goto label_608;
        }
    }
    ctx->pc = 0x5F8u;
    // 0x5f8: 0x8000193  j           func_00064C
    ctx->pc = 0x5F8u;
    // 0x5fc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x64Cu;
    goto label_64c;
    ctx->pc = 0x600u;
    // 0x600: 0x8000193  j           func_00064C
    ctx->pc = 0x600u;
    ctx->pc = 0x64Cu;
    goto label_64c;
    ctx->pc = 0x608u;
label_608:
    // 0x608: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x60c: 0x0  nop
    // NOP
    // 0x610: 0x3062ffff  andi        $v0, $v1, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x614: 0x3403903e  ori         $v1, $zero, 0x903E
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)36926);
    // 0x618: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x618u;
    {
        const bool branch_taken_0x618 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x618) {
            ctx->pc = 0x630u;
            goto label_630;
        }
    }
    ctx->pc = 0x620u;
    // 0x620: 0x8000193  j           func_00064C
    ctx->pc = 0x620u;
    // 0x624: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x64Cu;
    goto label_64c;
    ctx->pc = 0x628u;
    // 0x628: 0x8000193  j           func_00064C
    ctx->pc = 0x628u;
    ctx->pc = 0x64Cu;
    goto label_64c;
    ctx->pc = 0x630u;
label_630:
    // 0x630: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x634: 0x248429fc  addiu       $a0, $a0, 0x29FC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10748));
    // 0x638: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x63c: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x63Cu;
    SET_GPR_U32(ctx, 31, 0x644u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x63Cu, 0x644u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x644u;
label_644:
    // 0x644: 0x8000193  j           func_00064C
    ctx->pc = 0x644u;
    // 0x648: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x64Cu;
    goto label_64c;
    ctx->pc = 0x64Cu;
label_64c:
    // 0x64c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x650: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x654: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x658: 0x3e00008  jr          $ra
    ctx->pc = 0x658u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x65c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x658u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x660u;
}


// Function: sounds_00000660
// Address: 0x660 - 0x6d0
void sounds_00000660_0x660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000660_0x660");
#endif

    switch (ctx->pc) {
        case 0x674u: goto label_674;
        case 0x68cu: goto label_68c;
        case 0x69cu: goto label_69c;
        case 0x6acu: goto label_6ac;
        default: break;
    }

    ctx->pc = 0x660u;

    // 0x660: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x664: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x668: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x66c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x670: 0x0  nop
    // NOP
label_674:
    // 0x674: 0x80001a1  j           func_000684
    ctx->pc = 0x674u;
    ctx->pc = 0x684u;
    goto label_684;
    ctx->pc = 0x67Cu;
    // 0x67c: 0x80001ad  j           func_0006B4
    ctx->pc = 0x67Cu;
    ctx->pc = 0x6B4u;
    goto label_6b4;
    ctx->pc = 0x684u;
label_684:
    // 0x684: 0xc000a1d  jal         func_002874
    ctx->pc = 0x684u;
    SET_GPR_U32(ctx, 31, 0x68Cu);
    ctx->pc = 0x2874u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2874u, 0x684u, 0x68Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x68Cu;
label_68c:
    // 0x68c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x690: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x694: 0xc0009bf  jal         func_0026FC
    ctx->pc = 0x694u;
    SET_GPR_U32(ctx, 31, 0x69Cu);
    ctx->pc = 0x26FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x26FCu, 0x694u, 0x69Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x69Cu;
label_69c:
    // 0x69c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x6a0: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x6a4: 0xc0009d8  jal         func_002760
    ctx->pc = 0x6A4u;
    SET_GPR_U32(ctx, 31, 0x6ACu);
    ctx->pc = 0x2760u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2760u, 0x6A4u, 0x6ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6ACu;
label_6ac:
    // 0x6ac: 0x800019d  j           func_000674
    ctx->pc = 0x6ACu;
    ctx->pc = 0x674u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_674;
    ctx->pc = 0x6B4u;
label_6b4:
    // 0x6b4: 0x80001af  j           func_0006BC
    ctx->pc = 0x6B4u;
    // 0x6b8: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x6BCu;
    goto label_6bc;
    ctx->pc = 0x6BCu;
label_6bc:
    // 0x6bc: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x6c0: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x6c4: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x6c8: 0x3e00008  jr          $ra
    ctx->pc = 0x6C8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x6cc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x6C8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6D0u;
}


// Function: sounds_000006d0
// Address: 0x6d0 - 0x730
void sounds_000006d0_0x6d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000006d0_0x6d0");
#endif

    switch (ctx->pc) {
        case 0x710u: goto label_710;
        default: break;
    }

    ctx->pc = 0x6d0u;

    // 0x6d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x6d4: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x6d8: 0xafbe0028  sw          $fp, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 30));
    // 0x6dc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x6e0: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
    // 0x6e4: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x6e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x6ec: 0x24420660  addiu       $v0, $v0, 0x660
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1632));
    // 0x6f0: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x6f4: 0x2402001c  addiu       $v0, $zero, 0x1C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x6f8: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x6fc: 0x24021000  addiu       $v0, $zero, 0x1000
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x700: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x704: 0xafc00014  sw          $zero, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x708: 0xc000a17  jal         func_00285C
    ctx->pc = 0x708u;
    SET_GPR_U32(ctx, 31, 0x710u);
    // 0x70c: 0x27c40010  addiu       $a0, $fp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    ctx->pc = 0x285Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x285Cu, 0x708u, 0x710u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x710u;
label_710:
    // 0x710: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x714: 0x80001c7  j           func_00071C
    ctx->pc = 0x714u;
    // 0x718: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x71Cu;
    goto label_71c;
    ctx->pc = 0x71Cu;
label_71c:
    // 0x71c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x720: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x724: 0x8fbe0028  lw          $fp, 0x28($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x728: 0x3e00008  jr          $ra
    ctx->pc = 0x728u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x72c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
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


// Function: sounds_00000730
// Address: 0x730 - 0x790
void sounds_00000730_0x730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000730_0x730");
#endif

    switch (ctx->pc) {
        case 0x764u: goto label_764;
        default: break;
    }

    ctx->pc = 0x730u;

    // 0x730: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x734: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x738: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x73c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x740: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x744: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x748: 0x0  nop
    // NOP
    // 0x74c: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x750: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x754: 0x0  nop
    // NOP
    // 0x758: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x75c: 0xc000a1f  jal         func_00287C
    ctx->pc = 0x75Cu;
    SET_GPR_U32(ctx, 31, 0x764u);
    ctx->pc = 0x287Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x287Cu, 0x75Cu, 0x764u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x764u;
label_764:
    // 0x764: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x768: 0x0  nop
    // NOP
    // 0x76c: 0x8c430008  lw          $v1, 0x8($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x770: 0x0  nop
    // NOP
    // 0x774: 0x80001df  j           func_00077C
    ctx->pc = 0x774u;
    // 0x778: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x77Cu;
    goto label_77c;
    ctx->pc = 0x77Cu;
label_77c:
    // 0x77c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x780: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x784: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x788: 0x3e00008  jr          $ra
    ctx->pc = 0x788u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x78c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x788u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x790u;
}


// Function: sounds_00000790
// Address: 0x790 - 0x8e8
void sounds_00000790_0x790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000790_0x790");
#endif

    switch (ctx->pc) {
        case 0x7b0u: goto label_7b0;
        case 0x7d0u: goto label_7d0;
        case 0x808u: goto label_808;
        case 0x82cu: goto label_82c;
        case 0x854u: goto label_854;
        case 0x870u: goto label_870;
        case 0x898u: goto label_898;
        case 0x8acu: goto label_8ac;
        case 0x8d4u: goto label_8d4;
        default: break;
    }

    ctx->pc = 0x790u;

    // 0x790: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x794: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x798: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0x79c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x7a0: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
    // 0x7a4: 0x24041047  addiu       $a0, $zero, 0x1047
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4167));
    // 0x7a8: 0xc000a21  jal         func_002884
    ctx->pc = 0x7A8u;
    SET_GPR_U32(ctx, 31, 0x7B0u);
    // 0x7ac: 0x27c50010  addiu       $a1, $fp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    ctx->pc = 0x2884u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2884u, 0x7A8u, 0x7B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7B0u;
label_7b0:
    // 0x7b0: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x7b4: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x7b8: 0x0  nop
    // NOP
    // 0x7bc: 0xac430008  sw          $v1, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x7c0: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x7c4: 0x24050020  addiu       $a1, $zero, 0x20
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x7c8: 0xc000a2a  jal         func_0028A8
    ctx->pc = 0x7C8u;
    SET_GPR_U32(ctx, 31, 0x7D0u);
    // 0x7cc: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x28A8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28A8u, 0x7C8u, 0x7D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7D0u;
label_7d0:
    // 0x7d0: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x7d4: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x7d8: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x7dc: 0x0  nop
    // NOP
    // 0x7e0: 0xac430004  sw          $v1, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
    // 0x7e4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x7e8: 0x0  nop
    // NOP
    // 0x7ec: 0x1c400006  bgtz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x7ECu;
    {
        const bool branch_taken_0x7ec = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x7ec) {
            ctx->pc = 0x808u;
            goto label_808;
        }
    }
    ctx->pc = 0x7F4u;
    // 0x7f4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x7f8: 0x24842a30  addiu       $a0, $a0, 0x2A30
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10800));
    // 0x7fc: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x800: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x800u;
    SET_GPR_U32(ctx, 31, 0x808u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x800u, 0x808u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x808u;
label_808:
    // 0x808: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x80c: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x810: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x814: 0x8c650008  lw          $a1, 0x8($v1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x818: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x81c: 0x24c60730  addiu       $a2, $a2, 0x730
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1840));
    // 0x820: 0x8fc70028  lw          $a3, 0x28($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x824: 0xc000a2e  jal         func_0028B8
    ctx->pc = 0x824u;
    SET_GPR_U32(ctx, 31, 0x82Cu);
    ctx->pc = 0x28B8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28B8u, 0x824u, 0x82Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x82Cu;
label_82c:
    // 0x82c: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x830: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x834: 0x0  nop
    // NOP
    // 0x838: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x838u;
    {
        const bool branch_taken_0x838 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x838) {
            ctx->pc = 0x854u;
            goto label_854;
        }
    }
    ctx->pc = 0x840u;
    // 0x840: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x844: 0x24842a64  addiu       $a0, $a0, 0x2A64
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10852));
    // 0x848: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x84c: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x84Cu;
    SET_GPR_U32(ctx, 31, 0x854u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x84Cu, 0x854u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x854u;
label_854:
    // 0x854: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x858: 0x0  nop
    // NOP
    // 0x85c: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x860: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x864: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x868: 0xc000a30  jal         func_0028C0
    ctx->pc = 0x868u;
    SET_GPR_U32(ctx, 31, 0x870u);
    // 0x86c: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x28C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28C0u, 0x868u, 0x870u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x870u;
label_870:
    // 0x870: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x874: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x878: 0x0  nop
    // NOP
    // 0x87c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x87Cu;
    {
        const bool branch_taken_0x87c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x87c) {
            ctx->pc = 0x898u;
            goto label_898;
        }
    }
    ctx->pc = 0x884u;
    // 0x884: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x888: 0x24842a98  addiu       $a0, $a0, 0x2A98
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10904));
    // 0x88c: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x890: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x890u;
    SET_GPR_U32(ctx, 31, 0x898u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x890u, 0x898u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x898u;
label_898:
    // 0x898: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x89c: 0x0  nop
    // NOP
    // 0x8a0: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x8a4: 0xc000a32  jal         func_0028C8
    ctx->pc = 0x8A4u;
    SET_GPR_U32(ctx, 31, 0x8ACu);
    ctx->pc = 0x28C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28C8u, 0x8A4u, 0x8ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8ACu;
label_8ac:
    // 0x8ac: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x8b0: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x8b4: 0x0  nop
    // NOP
    // 0x8b8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x8B8u;
    {
        const bool branch_taken_0x8b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x8b8) {
            ctx->pc = 0x8D4u;
            goto label_8d4;
        }
    }
    ctx->pc = 0x8C0u;
    // 0x8c0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x8c4: 0x24842acc  addiu       $a0, $a0, 0x2ACC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10956));
    // 0x8c8: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x8cc: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x8CCu;
    SET_GPR_U32(ctx, 31, 0x8D4u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x8CCu, 0x8D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8D4u;
label_8d4:
    // 0x8d4: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x8d8: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x8dc: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x8e0: 0x3e00008  jr          $ra
    ctx->pc = 0x8E0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8e4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8E0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8E8u;
}


// Function: sounds_000008e8
// Address: 0x8e8 - 0x998
void sounds_000008e8_0x8e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000008e8_0x8e8");
#endif

    switch (ctx->pc) {
        case 0x910u: goto label_910;
        case 0x948u: goto label_948;
        case 0x95cu: goto label_95c;
        case 0x984u: goto label_984;
        default: break;
    }

    ctx->pc = 0x8e8u;

    // 0x8e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x8ec: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x8f0: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x8f4: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x8f8: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x8fc: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x900: 0x0  nop
    // NOP
    // 0x904: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x908: 0xc000a34  jal         func_0028D0
    ctx->pc = 0x908u;
    SET_GPR_U32(ctx, 31, 0x910u);
    ctx->pc = 0x28D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28D0u, 0x908u, 0x910u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x910u;
label_910:
    // 0x910: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x914: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x918: 0x0  nop
    // NOP
    // 0x91c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x91Cu;
    {
        const bool branch_taken_0x91c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x91c) {
            ctx->pc = 0x948u;
            goto label_948;
        }
    }
    ctx->pc = 0x924u;
    // 0x924: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x928: 0x2403ff64  addiu       $v1, $zero, -0x9C
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967140));
    // 0x92c: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x92Cu;
    {
        const bool branch_taken_0x92c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x92c) {
            ctx->pc = 0x948u;
            goto label_948;
        }
    }
    ctx->pc = 0x934u;
    // 0x934: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x938: 0x24842b00  addiu       $a0, $a0, 0x2B00
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11008));
    // 0x93c: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x940: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x940u;
    SET_GPR_U32(ctx, 31, 0x948u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x940u, 0x948u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x948u;
label_948:
    // 0x948: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x94c: 0x0  nop
    // NOP
    // 0x950: 0x8c440004  lw          $a0, 0x4($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x954: 0xc000a2c  jal         func_0028B0
    ctx->pc = 0x954u;
    SET_GPR_U32(ctx, 31, 0x95Cu);
    ctx->pc = 0x28B0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28B0u, 0x954u, 0x95Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x95Cu;
label_95c:
    // 0x95c: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x960: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x964: 0x0  nop
    // NOP
    // 0x968: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x968u;
    {
        const bool branch_taken_0x968 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x968) {
            ctx->pc = 0x984u;
            goto label_984;
        }
    }
    ctx->pc = 0x970u;
    // 0x970: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x974: 0x24842b34  addiu       $a0, $a0, 0x2B34
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11060));
    // 0x978: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x97c: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x97Cu;
    SET_GPR_U32(ctx, 31, 0x984u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x97Cu, 0x984u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x984u;
label_984:
    // 0x984: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x988: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x98c: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x990: 0x3e00008  jr          $ra
    ctx->pc = 0x990u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x994: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x990u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x998u;
}


// Function: sounds_00000998
// Address: 0x998 - 0xea0
void sounds_00000998_0x998(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000998_0x998");
#endif

    switch (ctx->pc) {
        case 0x9b8u: goto label_9b8;
        case 0x9ccu: goto label_9cc;
        case 0x9d4u: goto label_9d4;
        case 0xa44u: goto label_a44;
        case 0xb50u: goto label_b50;
        case 0xc30u: goto label_c30;
        case 0xd48u: goto label_d48;
        case 0xde4u: goto label_de4;
        case 0xdf4u: goto label_df4;
        case 0xe04u: goto label_e04;
        case 0xe14u: goto label_e14;
        case 0xe3cu: goto label_e3c;
        case 0xe4cu: goto label_e4c;
        case 0xe5cu: goto label_e5c;
        case 0xe6cu: goto label_e6c;
        case 0xe7cu: goto label_e7c;
        case 0xe8cu: goto label_e8c;
        default: break;
    }

    ctx->pc = 0x998u;

    // 0x998: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x99c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x9a0: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x9a4: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x9a8: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x9ac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x9b0: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x9B0u;
    SET_GPR_U32(ctx, 31, 0x9B8u);
    // 0x9b4: 0x24842b68  addiu       $a0, $a0, 0x2B68 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11112));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x9B0u, 0x9B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9B8u;
label_9b8:
    // 0x9b8: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x9bc: 0x24845620  addiu       $a0, $a0, 0x5620
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22048));
    // 0x9c0: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x9c4: 0xc000a0e  jal         func_002838
    ctx->pc = 0x9C4u;
    SET_GPR_U32(ctx, 31, 0x9CCu);
    // 0x9c8: 0x24060480  addiu       $a2, $zero, 0x480 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1152));
    ctx->pc = 0x2838u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2838u, 0x9C4u, 0x9CCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9CCu;
label_9cc:
    // 0x9cc: 0xc0001b4  jal         func_0006D0
    ctx->pc = 0x9CCu;
    SET_GPR_U32(ctx, 31, 0x9D4u);
    ctx->pc = 0x6D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x6D0u, 0x9CCu, 0x9D4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9D4u;
label_9d4:
    // 0x9d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9d8: 0xac223150  sw          $v0, 0x3150($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 12624), GPR_U32(ctx, 2));
    // 0x9dc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x9e0: 0x8c423150  lw          $v0, 0x3150($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12624)));
    // 0x9e4: 0x0  nop
    // NOP
    // 0x9e8: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x9ec: 0xac2254b0  sw          $v0, 0x54B0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21680), GPR_U32(ctx, 2));
    // 0x9f0: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x9f4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x9f8: 0xac226160  sw          $v0, 0x6160($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24928), GPR_U32(ctx, 2));
    // 0x9fc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa00: 0x24426190  addiu       $v0, $v0, 0x6190
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24976));
    // 0xa04: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa08: 0xac226164  sw          $v0, 0x6164($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24932), GPR_U32(ctx, 2));
    // 0xa0c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa10: 0xac206168  sw          $zero, 0x6168($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24936), GPR_U32(ctx, 0));
    // 0xa14: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa18: 0xac206170  sw          $zero, 0x6170($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24944), GPR_U32(ctx, 0));
    // 0xa1c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa20: 0xac20616c  sw          $zero, 0x616C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24940), GPR_U32(ctx, 0));
    // 0xa24: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0xa28: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa2c: 0xac226190  sw          $v0, 0x6190($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24976), GPR_U32(ctx, 2));
    // 0xa30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xa34: 0x244261a8  addiu       $v0, $v0, 0x61A8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25000));
    // 0xa38: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa3c: 0xac226194  sw          $v0, 0x6194($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24980), GPR_U32(ctx, 2));
    // 0xa40: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_a44:
    // 0xa44: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xa48: 0x0  nop
    // NOP
    // 0xa4c: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0xa50: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xA50u;
    {
        const bool branch_taken_0xa50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xa50) {
            ctx->pc = 0xA60u;
            goto label_a60;
        }
    }
    ctx->pc = 0xA58u;
    // 0xa58: 0x80002cc  j           func_000B30
    ctx->pc = 0xA58u;
    ctx->pc = 0xB30u;
    goto label_b30;
    ctx->pc = 0xA60u;
label_a60:
    // 0xa60: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xa64: 0x0  nop
    // NOP
    // 0xa68: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xa6c: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0xa70: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa74: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xa78: 0xac2061a8  sw          $zero, 0x61A8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25000), GPR_U32(ctx, 0));
    // 0xa7c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xa80: 0x0  nop
    // NOP
    // 0xa84: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xa88: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0xa8c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xa90: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xa94: 0xac2061ac  sw          $zero, 0x61AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25004), GPR_U32(ctx, 0));
    // 0xa98: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xa9c: 0x0  nop
    // NOP
    // 0xaa0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xaa4: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0xaa8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xaac: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xab0: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xab4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xab8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xabc: 0xac2061a8  sw          $zero, 0x61A8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25000), GPR_U32(ctx, 0));
    // 0xac0: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xac4: 0x0  nop
    // NOP
    // 0xac8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xacc: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0xad0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xad4: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xad8: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xadc: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xae0: 0x0  nop
    // NOP
    // 0xae4: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xae8: 0x52100  sll         $a0, $a1, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0xaec: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xaf0: 0x42880  sll         $a1, $a0, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xaf4: 0xa32823  subu        $a1, $a1, $v1
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0xaf8: 0x520c0  sll         $a0, $a1, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0xafc: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xb00: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xb04: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xb08: 0x24846268  addiu       $a0, $a0, 0x6268
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 25192));
    // 0xb0c: 0x831821  addu        $v1, $a0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xb10: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb14: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xb18: 0xac2361ac  sw          $v1, 0x61AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25004), GPR_U32(ctx, 3));
    // 0xb1c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xb20: 0x0  nop
    // NOP
    // 0xb24: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xb28: 0x8000291  j           func_000A44
    ctx->pc = 0xB28u;
    // 0xb2c: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0xA44u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_a44;
    ctx->pc = 0xB30u;
label_b30:
    // 0xb30: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0xb34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb38: 0xac226198  sw          $v0, 0x6198($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24984), GPR_U32(ctx, 2));
    // 0xb3c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xb40: 0x24426228  addiu       $v0, $v0, 0x6228
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 25128));
    // 0xb44: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb48: 0xac22619c  sw          $v0, 0x619C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24988), GPR_U32(ctx, 2));
    // 0xb4c: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_b50:
    // 0xb50: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xb54: 0x0  nop
    // NOP
    // 0xb58: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0xb5c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xB5Cu;
    {
        const bool branch_taken_0xb5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xb5c) {
            ctx->pc = 0xB6Cu;
            goto label_b6c;
        }
    }
    ctx->pc = 0xB64u;
    // 0xb64: 0x80002f7  j           func_000BDC
    ctx->pc = 0xB64u;
    ctx->pc = 0xBDCu;
    goto label_bdc;
    ctx->pc = 0xB6Cu;
label_b6c:
    // 0xb6c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xb70: 0x0  nop
    // NOP
    // 0xb74: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb78: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0xb7c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb80: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xb84: 0xac206228  sw          $zero, 0x6228($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25128), GPR_U32(ctx, 0));
    // 0xb88: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xb8c: 0x0  nop
    // NOP
    // 0xb90: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xb94: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0xb98: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xb9c: 0x0  nop
    // NOP
    // 0xba0: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xba4: 0x52200  sll         $a0, $a1, 8
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0xba8: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xbac: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xbb0: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xbb4: 0x248413e8  addiu       $a0, $a0, 0x13E8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5096));
    // 0xbb8: 0x831821  addu        $v1, $a0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xbbc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbc0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xbc4: 0xac23622c  sw          $v1, 0x622C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25132), GPR_U32(ctx, 3));
    // 0xbc8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xbcc: 0x0  nop
    // NOP
    // 0xbd0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xbd4: 0x80002d4  j           func_000B50
    ctx->pc = 0xBD4u;
    // 0xbd8: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0xB50u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_b50;
    ctx->pc = 0xBDCu;
label_bdc:
    // 0xbdc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xbe0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbe4: 0xac226178  sw          $v0, 0x6178($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24952), GPR_U32(ctx, 2));
    // 0xbe8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0xbec: 0x244261a0  addiu       $v0, $v0, 0x61A0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24992));
    // 0xbf0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbf4: 0xac22617c  sw          $v0, 0x617C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24956), GPR_U32(ctx, 2));
    // 0xbf8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xbfc: 0xac206180  sw          $zero, 0x6180($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24960), GPR_U32(ctx, 0));
    // 0xc00: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xc04: 0xac206188  sw          $zero, 0x6188($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24968), GPR_U32(ctx, 0));
    // 0xc08: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xc0c: 0xac206184  sw          $zero, 0x6184($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24964), GPR_U32(ctx, 0));
    // 0xc10: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0xc14: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xc18: 0xac2261a0  sw          $v0, 0x61A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24992), GPR_U32(ctx, 2));
    // 0xc1c: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0xc20: 0x2442e8a8  addiu       $v0, $v0, -0x1758
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294961320));
    // 0xc24: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xc28: 0xac2261a4  sw          $v0, 0x61A4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 24996), GPR_U32(ctx, 2));
    // 0xc2c: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_c30:
    // 0xc30: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xc34: 0x0  nop
    // NOP
    // 0xc38: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0xc3c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xC3Cu;
    {
        const bool branch_taken_0xc3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xc3c) {
            ctx->pc = 0xC4Cu;
            goto label_c4c;
        }
    }
    ctx->pc = 0xC44u;
    // 0xc44: 0x8000350  j           func_000D40
    ctx->pc = 0xC44u;
    ctx->pc = 0xD40u;
    goto label_d40;
    ctx->pc = 0xC4Cu;
label_c4c:
    // 0xc4c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xc50: 0x0  nop
    // NOP
    // 0xc54: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xc58: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0xc5c: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0xc60: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xc64: 0xac20e8a8  sw          $zero, -0x1758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961320), GPR_U32(ctx, 0));
    // 0xc68: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xc6c: 0x0  nop
    // NOP
    // 0xc70: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xc74: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0xc78: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xc7c: 0x0  nop
    // NOP
    // 0xc80: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xc84: 0x52200  sll         $a0, $a1, 8
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0xc88: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc8c: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xc90: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xc94: 0x248413e8  addiu       $a0, $a0, 0x13E8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5096));
    // 0xc98: 0x831821  addu        $v1, $a0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xc9c: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0xca0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xca4: 0xac23e8ac  sw          $v1, -0x1754($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961324), GPR_U32(ctx, 3));
    // 0xca8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xcac: 0x0  nop
    // NOP
    // 0xcb0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xcb4: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0xcb8: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xcbc: 0x601021  addu        $v0, $v1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xcc0: 0x218c0  sll         $v1, $v0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0xcc4: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0xcc8: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0xccc: 0xac20e8a8  sw          $zero, -0x1758($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961320), GPR_U32(ctx, 0));
    // 0xcd0: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xcd4: 0x0  nop
    // NOP
    // 0xcd8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xcdc: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0xce0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xce4: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xce8: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xcec: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xcf0: 0x0  nop
    // NOP
    // 0xcf4: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0xcf8: 0x42880  sll         $a1, $a0, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xcfc: 0xa32821  addu        $a1, $a1, $v1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0xd00: 0x52080  sll         $a0, $a1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0xd04: 0x832023  subu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xd08: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xd0c: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xd10: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0xd14: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xd18: 0x2484e928  addiu       $a0, $a0, -0x16D8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961448));
    // 0xd1c: 0x831821  addu        $v1, $a0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0xd20: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0xd24: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0xd28: 0xac23e8ac  sw          $v1, -0x1754($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961324), GPR_U32(ctx, 3));
    // 0xd2c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xd30: 0x0  nop
    // NOP
    // 0xd34: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xd38: 0x800030c  j           func_000C30
    ctx->pc = 0xD38u;
    // 0xd3c: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0xC30u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_c30;
    ctx->pc = 0xD40u;
label_d40:
    // 0xd40: 0x0  nop
    // NOP
    // 0xd44: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_d48:
    // 0xd48: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xd4c: 0x0  nop
    // NOP
    // 0xd50: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0xd54: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xD54u;
    {
        const bool branch_taken_0xd54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xd54) {
            ctx->pc = 0xD64u;
            goto label_d64;
        }
    }
    ctx->pc = 0xD5Cu;
    // 0xd5c: 0x8000373  j           func_000DCC
    ctx->pc = 0xD5Cu;
    ctx->pc = 0xDCCu;
    goto label_dcc;
    ctx->pc = 0xD64u;
label_d64:
    // 0xd64: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xd68: 0x0  nop
    // NOP
    // 0xd6c: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xd70: 0x41a00  sll         $v1, $a0, 8
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0xd74: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xd78: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0xd7c: 0x3c030001  lui         $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0xd80: 0x246313e8  addiu       $v1, $v1, 0x13E8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5096));
    // 0xd84: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xd88: 0x24030808  addiu       $v1, $zero, 0x808
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2056));
    // 0xd8c: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0xd90: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xd94: 0x0  nop
    // NOP
    // 0xd98: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xd9c: 0x41a00  sll         $v1, $a0, 8
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0xda0: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0xda4: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0xda8: 0x3c030001  lui         $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0xdac: 0x246313e8  addiu       $v1, $v1, 0x13E8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5096));
    // 0xdb0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0xdb4: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0xdb8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xdbc: 0x0  nop
    // NOP
    // 0xdc0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xdc4: 0x8000352  j           func_000D48
    ctx->pc = 0xDC4u;
    // 0xdc8: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0xD48u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_d48;
    ctx->pc = 0xDCCu;
label_dcc:
    // 0xdcc: 0xafc00018  sw          $zero, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0xdd0: 0x24020100  addiu       $v0, $zero, 0x100
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0xdd4: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0xdd8: 0x27c20018  addiu       $v0, $fp, 0x18
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 24));
    // 0xddc: 0xc0009c3  jal         func_00270C
    ctx->pc = 0xDDCu;
    SET_GPR_U32(ctx, 31, 0xDE4u);
    // 0xde0: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x270Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x270Cu, 0xDDCu, 0xDE4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDE4u;
label_de4:
    // 0xde4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xde8: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0xdec: 0xc0009d6  jal         func_002758
    ctx->pc = 0xDECu;
    SET_GPR_U32(ctx, 31, 0xDF4u);
    // 0xdf0: 0x24051047  addiu       $a1, $zero, 0x1047 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4167));
    ctx->pc = 0x2758u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2758u, 0xDECu, 0xDF4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xDF4u;
label_df4:
    // 0xdf4: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0xdf8: 0x8fc40014  lw          $a0, 0x14($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xdfc: 0xc000127  jal         func_00049C
    ctx->pc = 0xDFCu;
    SET_GPR_U32(ctx, 31, 0xE04u);
    ctx->pc = 0x49Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x49Cu, 0xDFCu, 0xE04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE04u;
label_e04:
    // 0xe04: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe08: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0xe0c: 0xc0009bd  jal         func_0026F4
    ctx->pc = 0xE0Cu;
    SET_GPR_U32(ctx, 31, 0xE14u);
    // 0xe10: 0x24051047  addiu       $a1, $zero, 0x1047 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4167));
    ctx->pc = 0x26F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x26F4u, 0xE0Cu, 0xE14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE14u;
label_e14:
    // 0xe14: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0xe18: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xe1c: 0x0  nop
    // NOP
    // 0xe20: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0xE20u;
    {
        const bool branch_taken_0xe20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xe20) {
            ctx->pc = 0xE3Cu;
            goto label_e3c;
        }
    }
    ctx->pc = 0xE28u;
    // 0xe28: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe2c: 0x24842b88  addiu       $a0, $a0, 0x2B88
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11144));
    // 0xe30: 0x8fc50014  lw          $a1, 0x14($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0xe34: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0xE34u;
    SET_GPR_U32(ctx, 31, 0xE3Cu);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0xE34u, 0xE3Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE3Cu;
label_e3c:
    // 0xe3c: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xe40: 0x248454c0  addiu       $a0, $a0, 0x54C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21696));
    // 0xe44: 0xc0009c7  jal         func_00271C
    ctx->pc = 0xE44u;
    SET_GPR_U32(ctx, 31, 0xE4Cu);
    ctx->pc = 0x271Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x271Cu, 0xE44u, 0xE4Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE4Cu;
label_e4c:
    // 0xe4c: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xe50: 0x24845560  addiu       $a0, $a0, 0x5560
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21856));
    // 0xe54: 0xc0009cd  jal         func_002734
    ctx->pc = 0xE54u;
    SET_GPR_U32(ctx, 31, 0xE5Cu);
    ctx->pc = 0x2734u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2734u, 0xE54u, 0xE5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE5Cu;
label_e5c:
    // 0xe5c: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xe60: 0x24845560  addiu       $a0, $a0, 0x5560
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21856));
    // 0xe64: 0xc0009de  jal         func_002778
    ctx->pc = 0xE64u;
    SET_GPR_U32(ctx, 31, 0xE6Cu);
    ctx->pc = 0x2778u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2778u, 0xE64u, 0xE6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE6Cu;
label_e6c:
    // 0xe6c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xe70: 0x8c843150  lw          $a0, 0x3150($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12624)));
    // 0xe74: 0xc000a19  jal         func_002864
    ctx->pc = 0xE74u;
    SET_GPR_U32(ctx, 31, 0xE7Cu);
    // 0xe78: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2864u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2864u, 0xE74u, 0xE7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE7Cu;
label_e7c:
    // 0xe7c: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xe80: 0x248454b0  addiu       $a0, $a0, 0x54B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21680));
    // 0xe84: 0xc0001e4  jal         func_000790
    ctx->pc = 0xE84u;
    SET_GPR_U32(ctx, 31, 0xE8Cu);
    ctx->pc = 0x790u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x790u, 0xE84u, 0xE8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE8Cu;
label_e8c:
    // 0xe8c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xe90: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0xe94: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0xe98: 0x3e00008  jr          $ra
    ctx->pc = 0xE98u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xe9c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xE98u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xEA0u;
}


// Function: sounds_00000ea0
// Address: 0xea0 - 0xee4
void sounds_00000ea0_0xea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000ea0_0xea0");
#endif

    switch (ctx->pc) {
        case 0xec0u: goto label_ec0;
        case 0xed0u: goto label_ed0;
        default: break;
    }

    ctx->pc = 0xea0u;

    // 0xea0: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xea4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xea8: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0xeac: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xeb0: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0xeb4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xeb8: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0xEB8u;
    SET_GPR_U32(ctx, 31, 0xEC0u);
    // 0xebc: 0x24842bbc  addiu       $a0, $a0, 0x2BBC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11196));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0xEB8u, 0xEC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xEC0u;
label_ec0:
    // 0xec0: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xec4: 0x248454b0  addiu       $a0, $a0, 0x54B0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21680));
    // 0xec8: 0xc00023a  jal         func_0008E8
    ctx->pc = 0xEC8u;
    SET_GPR_U32(ctx, 31, 0xED0u);
    ctx->pc = 0x8E8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x8E8u, 0xEC8u, 0xED0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xED0u;
label_ed0:
    // 0xed0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xed4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xed8: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xedc: 0x3e00008  jr          $ra
    ctx->pc = 0xEDCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xee0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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


// Function: sounds_00000ee4
// Address: 0xee4 - 0xfa4
void sounds_00000ee4_0xee4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000ee4_0xee4");
#endif

    switch (ctx->pc) {
        case 0xf04u: goto label_f04;
        case 0xf08u: goto label_f08;
        case 0xf38u: goto label_f38;
        case 0xf68u: goto label_f68;
        case 0xf90u: goto label_f90;
        default: break;
    }

    ctx->pc = 0xee4u;

    // 0xee4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0xee8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0xeec: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0xef0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xef4: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0xef8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xefc: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0xEFCu;
    SET_GPR_U32(ctx, 31, 0xF04u);
    // 0xf00: 0x24842bdc  addiu       $a0, $a0, 0x2BDC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11228));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0xEFCu, 0xF04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF04u;
label_f04:
    // 0xf04: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_f08:
    // 0xf08: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf0c: 0x0  nop
    // NOP
    // 0xf10: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0xf14: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0xF14u;
    {
        const bool branch_taken_0xf14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0xf14) {
            ctx->pc = 0xF24u;
            goto label_f24;
        }
    }
    ctx->pc = 0xF1Cu;
    // 0xf1c: 0x80003df  j           func_000F7C
    ctx->pc = 0xF1Cu;
    ctx->pc = 0xF7Cu;
    goto label_f7c;
    ctx->pc = 0xF24u;
label_f24:
    // 0xf24: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf28: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0xf2c: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf30: 0xc0009cb  jal         func_00272C
    ctx->pc = 0xF30u;
    SET_GPR_U32(ctx, 31, 0xF38u);
    ctx->pc = 0x272Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x272Cu, 0xF30u, 0xF38u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF38u;
label_f38:
    // 0xf38: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf3c: 0x0  nop
    // NOP
    // 0xf40: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xf44: 0x32100  sll         $a0, $v1, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0xf48: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0xf4c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xf50: 0x9442543c  lhu         $v0, 0x543C($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 21564)));
    // 0xf54: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xf58: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0xf5c: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf60: 0xc0009c5  jal         func_002714
    ctx->pc = 0xF60u;
    SET_GPR_U32(ctx, 31, 0xF68u);
    // 0xf64: 0x403021  addu        $a2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2714u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2714u, 0xF60u, 0xF68u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF68u;
label_f68:
    // 0xf68: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0xf6c: 0x0  nop
    // NOP
    // 0xf70: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0xf74: 0x80003c2  j           func_000F08
    ctx->pc = 0xF74u;
    // 0xf78: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0xF08u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_f08;
    ctx->pc = 0xF7Cu;
label_f7c:
    // 0xf7c: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0xf80: 0x24845620  addiu       $a0, $a0, 0x5620
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 22048));
    // 0xf84: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xf88: 0xc000a0e  jal         func_002838
    ctx->pc = 0xF88u;
    SET_GPR_U32(ctx, 31, 0xF90u);
    // 0xf8c: 0x24060480  addiu       $a2, $zero, 0x480 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1152));
    ctx->pc = 0x2838u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2838u, 0xF88u, 0xF90u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF90u;
label_f90:
    // 0xf90: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0xf94: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0xf98: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0xf9c: 0x3e00008  jr          $ra
    ctx->pc = 0xF9Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xfa0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xF9Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xFA4u;
}


// Function: sounds_00000fa4
// Address: 0xfa4 - 0x1470
void sounds_00000fa4_0xfa4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00000fa4_0xfa4");
#endif

    switch (ctx->pc) {
        case 0xfccu: goto label_fcc;
        case 0x1004u: goto label_1004;
        case 0x1018u: goto label_1018;
        case 0x10d8u: goto label_10d8;
        case 0x10e8u: goto label_10e8;
        case 0x12c0u: goto label_12c0;
        case 0x12e8u: goto label_12e8;
        default: break;
    }

    ctx->pc = 0xfa4u;

    // 0xfa4: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0xfa8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0xfac: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0xfb0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0xfb4: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
    // 0xfb8: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0xfbc: 0x0  nop
    // NOP
    // 0xfc0: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0xfc4: 0xc000100  jal         func_000400
    ctx->pc = 0xFC4u;
    SET_GPR_U32(ctx, 31, 0xFCCu);
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0xFC4u, 0xFCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFCCu;
label_fcc:
    // 0xfcc: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0xfd0: 0x8fc70028  lw          $a3, 0x28($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0xfd4: 0x8fc40028  lw          $a0, 0x28($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0xfd8: 0x0  nop
    // NOP
    // 0xfdc: 0x8c85000c  lw          $a1, 0xC($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0xfe0: 0x0  nop
    // NOP
    // 0xfe4: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0xfe8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xfec: 0x24842bfc  addiu       $a0, $a0, 0x2BFC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11260));
    // 0xff0: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0xff4: 0x8c660004  lw          $a2, 0x4($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0xff8: 0x8ce70008  lw          $a3, 0x8($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0xffc: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0xFFCu;
    SET_GPR_U32(ctx, 31, 0x1004u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0xFFCu, 0x1004u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1004u;
label_1004:
    // 0x1004: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1008: 0x0  nop
    // NOP
    // 0x100c: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1010: 0xc000100  jal         func_000400
    ctx->pc = 0x1010u;
    SET_GPR_U32(ctx, 31, 0x1018u);
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1010u, 0x1018u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1018u;
label_1018:
    // 0x1018: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x101c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1020: 0x0  nop
    // NOP
    // 0x1024: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1028: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x102c: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1030: 0x0  nop
    // NOP
    // 0x1034: 0x8c640008  lw          $a0, 0x8($v1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1038: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x103c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1040: 0xac245434  sw          $a0, 0x5434($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21556), GPR_U32(ctx, 4));
    // 0x1044: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1048: 0x0  nop
    // NOP
    // 0x104c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1050: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1054: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1058: 0x0  nop
    // NOP
    // 0x105c: 0x8c64000c  lw          $a0, 0xC($v1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1060: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1064: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1068: 0xac245438  sw          $a0, 0x5438($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21560), GPR_U32(ctx, 4));
    // 0x106c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1070: 0x0  nop
    // NOP
    // 0x1074: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1078: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x107c: 0x2403007f  addiu       $v1, $zero, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1080: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1084: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1088: 0xac23543c  sw          $v1, 0x543C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21564), GPR_U32(ctx, 3));
    // 0x108c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1090: 0x0  nop
    // NOP
    // 0x1094: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1098: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x109c: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x10a0: 0x0  nop
    // NOP
    // 0x10a4: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x10a8: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x10ac: 0x3c040001  lui         $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x10b0: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x10b4: 0x8c845438  lw          $a0, 0x5438($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21560)));
    // 0x10b8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x10bc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x10c0: 0xac2461ac  sw          $a0, 0x61AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25004), GPR_U32(ctx, 4));
    // 0x10c4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x10c8: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x10cc: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x10d0: 0xc0009da  jal         func_002768
    ctx->pc = 0x10D0u;
    SET_GPR_U32(ctx, 31, 0x10D8u);
    ctx->pc = 0x2768u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2768u, 0x10D0u, 0x10D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10D8u;
label_10d8:
    // 0x10d8: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x10dc: 0x8fc4001c  lw          $a0, 0x1C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x10e0: 0xc000140  jal         func_000500
    ctx->pc = 0x10E0u;
    SET_GPR_U32(ctx, 31, 0x10E8u);
    ctx->pc = 0x500u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x500u, 0x10E0u, 0x10E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10E8u;
label_10e8:
    // 0x10e8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x10ec: 0x0  nop
    // NOP
    // 0x10f0: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x10f4: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x10f8: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10fc: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1100: 0x822023  subu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1104: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1108: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x110c: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1110: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1114: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1118: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x111c: 0xac236274  sw          $v1, 0x6274($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25204), GPR_U32(ctx, 3));
    // 0x1120: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1124: 0x0  nop
    // NOP
    // 0x1128: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x112c: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1130: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1134: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1138: 0x822023  subu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x113c: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1140: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1144: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1148: 0x240300ff  addiu       $v1, $zero, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x114c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1150: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1154: 0xa0236279  sb          $v1, 0x6279($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 25209), (uint8_t)GPR_U32(ctx, 3));
    // 0x1158: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x115c: 0x24030002  addiu       $v1, $zero, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1160: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1160u;
    {
        const bool branch_taken_0x1160 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1160) {
            ctx->pc = 0x1194u;
            goto label_1194;
        }
    }
    ctx->pc = 0x1168u;
    // 0x1168: 0x28430002  slti        $v1, $v0, 0x2
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x116c: 0x14600019  bnez        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x116Cu;
    {
        const bool branch_taken_0x116c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x116c) {
            ctx->pc = 0x11D4u;
            goto label_11d4;
        }
    }
    ctx->pc = 0x1174u;
    // 0x1174: 0x28430006  slti        $v1, $v0, 0x6
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1178: 0x10600016  beqz        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1178u;
    {
        const bool branch_taken_0x1178 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1178) {
            ctx->pc = 0x11D4u;
            goto label_11d4;
        }
    }
    ctx->pc = 0x1180u;
    // 0x1180: 0x28420004  slti        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1184: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1184u;
    {
        const bool branch_taken_0x1184 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1184) {
            ctx->pc = 0x11D4u;
            goto label_11d4;
        }
    }
    ctx->pc = 0x118Cu;
    // 0x118c: 0x8000465  j           func_001194
    ctx->pc = 0x118Cu;
    ctx->pc = 0x1194u;
    goto label_1194;
    ctx->pc = 0x1194u;
label_1194:
    // 0x1194: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1198: 0x0  nop
    // NOP
    // 0x119c: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x11a0: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x11a4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11a8: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x11ac: 0x822023  subu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x11b0: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x11b4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11b8: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x11bc: 0x240300ff  addiu       $v1, $zero, 0xFF
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x11c0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x11c4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x11c8: 0xa023626c  sb          $v1, 0x626C($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 25196), (uint8_t)GPR_U32(ctx, 3));
    // 0x11cc: 0x8000485  j           func_001214
    ctx->pc = 0x11CCu;
    ctx->pc = 0x1214u;
    goto label_1214;
    ctx->pc = 0x11D4u;
label_11d4:
    // 0x11d4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x11d8: 0x0  nop
    // NOP
    // 0x11dc: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x11e0: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x11e4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11e8: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x11ec: 0x822023  subu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x11f0: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x11f4: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11f8: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x11fc: 0x2403007f  addiu       $v1, $zero, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1200: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1204: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1208: 0xa023626c  sb          $v1, 0x626C($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 25196), (uint8_t)GPR_U32(ctx, 3));
    // 0x120c: 0x8000485  j           func_001214
    ctx->pc = 0x120Cu;
    ctx->pc = 0x1214u;
    goto label_1214;
    ctx->pc = 0x1214u;
label_1214:
    // 0x1214: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1218: 0x0  nop
    // NOP
    // 0x121c: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1220: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1224: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1228: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x122c: 0x822023  subu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1230: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1234: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1238: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x123c: 0x24030040  addiu       $v1, $zero, 0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1240: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x1244: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1248: 0xa023626d  sb          $v1, 0x626D($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 25197), (uint8_t)GPR_U32(ctx, 3));
    // 0x124c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1250: 0x0  nop
    // NOP
    // 0x1254: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1258: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x125c: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1260: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1264: 0x822023  subu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1268: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x126c: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1270: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1274: 0x240303e8  addiu       $v1, $zero, 0x3E8
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1278: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x127c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1280: 0xa423626e  sh          $v1, 0x626E($at)
    WRITE16(ADD32(GPR_U32(ctx, 1), 25198), (uint16_t)GPR_U32(ctx, 3));
    // 0x1284: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1288: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x128c: 0x0  nop
    // NOP
    // 0x1290: 0x602021  addu        $a0, $v1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x1294: 0x41900  sll         $v1, $a0, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1298: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x129c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x12a0: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x12a4: 0x8fc50018  lw          $a1, 0x18($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x12a8: 0x8c460004  lw          $a2, 0x4($v0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x12ac: 0x3c070001  lui         $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)1 << 16));
    // 0x12b0: 0xe33821  addu        $a3, $a3, $v1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x12b4: 0x8ce75434  lw          $a3, 0x5434($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 21556)));
    // 0x12b8: 0xc0009c1  jal         func_002704
    ctx->pc = 0x12B8u;
    SET_GPR_U32(ctx, 31, 0x12C0u);
    ctx->pc = 0x2704u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2704u, 0x12B8u, 0x12C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12C0u;
label_12c0:
    // 0x12c0: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x12c4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x12c8: 0x0  nop
    // NOP
    // 0x12cc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x12CCu;
    {
        const bool branch_taken_0x12cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12cc) {
            ctx->pc = 0x12E8u;
            goto label_12e8;
        }
    }
    ctx->pc = 0x12D4u;
    // 0x12d4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x12d8: 0x24842c4c  addiu       $a0, $a0, 0x2C4C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11340));
    // 0x12dc: 0x8fc5001c  lw          $a1, 0x1C($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x12e0: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x12E0u;
    SET_GPR_U32(ctx, 31, 0x12E8u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x12E0u, 0x12E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x12E8u;
label_12e8:
    // 0x12e8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x12ec: 0x0  nop
    // NOP
    // 0x12f0: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x12f4: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x12f8: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x12fc: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1300: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1304: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1308: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x130c: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1310: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1314: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1318: 0xa020e928  sb          $zero, -0x16D8($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961448), (uint8_t)GPR_U32(ctx, 0));
    // 0x131c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1320: 0x0  nop
    // NOP
    // 0x1324: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1328: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x132c: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1330: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1334: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1338: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x133c: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1340: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1344: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1348: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x134c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1350: 0xa023e92a  sb          $v1, -0x16D6($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961450), (uint8_t)GPR_U32(ctx, 3));
    // 0x1354: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1358: 0x0  nop
    // NOP
    // 0x135c: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1360: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1364: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1368: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x136c: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1370: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1374: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1378: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x137c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1380: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1384: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1388: 0xa023e92b  sb          $v1, -0x16D5($at)
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961451), (uint8_t)GPR_U32(ctx, 3));
    // 0x138c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1390: 0x0  nop
    // NOP
    // 0x1394: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1398: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x139c: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13a0: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x13a4: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13a8: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x13ac: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13b0: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x13b4: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x13b8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x13bc: 0xac20e92c  sw          $zero, -0x16D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961452), GPR_U32(ctx, 0));
    // 0x13c0: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x13c4: 0x0  nop
    // NOP
    // 0x13c8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x13cc: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x13d0: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13d4: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x13d8: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13dc: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x13e0: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13e4: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x13e8: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x13ec: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x13f0: 0xac20e930  sw          $zero, -0x16D0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961456), GPR_U32(ctx, 0));
    // 0x13f4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x13f8: 0x0  nop
    // NOP
    // 0x13fc: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1400: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1404: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1408: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x140c: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1410: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1414: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1418: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x141c: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1420: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1424: 0xac20e934  sw          $zero, -0x16CC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961460), GPR_U32(ctx, 0));
    // 0x1428: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x142c: 0x0  nop
    // NOP
    // 0x1430: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1434: 0x32080  sll         $a0, $v1, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1438: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x143c: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1440: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1444: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1448: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x144c: 0x310c0  sll         $v0, $v1, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1450: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1454: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1458: 0xac20e938  sw          $zero, -0x16C8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961464), GPR_U32(ctx, 0));
    // 0x145c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1460: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1464: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1468: 0x3e00008  jr          $ra
    ctx->pc = 0x1468u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x146c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1468u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1470u;
}


// Function: sounds_00001470
// Address: 0x1470 - 0x1548
void sounds_00001470_0x1470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001470_0x1470");
#endif

    switch (ctx->pc) {
        case 0x1498u: goto label_1498;
        case 0x14a8u: goto label_14a8;
        case 0x14bcu: goto label_14bc;
        default: break;
    }

    ctx->pc = 0x1470u;

    // 0x1470: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1474: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1478: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x147c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1480: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x1484: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1488: 0x0  nop
    // NOP
    // 0x148c: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1490: 0xc000100  jal         func_000400
    ctx->pc = 0x1490u;
    SET_GPR_U32(ctx, 31, 0x1498u);
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1490u, 0x1498u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1498u;
label_1498:
    // 0x1498: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x149c: 0x24842c80  addiu       $a0, $a0, 0x2C80
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11392));
    // 0x14a0: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x14A0u;
    SET_GPR_U32(ctx, 31, 0x14A8u);
    // 0x14a4: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x14A0u, 0x14A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14A8u;
label_14a8:
    // 0x14a8: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x14ac: 0x0  nop
    // NOP
    // 0x14b0: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14b4: 0xc000100  jal         func_000400
    ctx->pc = 0x14B4u;
    SET_GPR_U32(ctx, 31, 0x14BCu);
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x14B4u, 0x14BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x14BCu;
label_14bc:
    // 0x14bc: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x14c0: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x14c4: 0x0  nop
    // NOP
    // 0x14c8: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x14cc: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x14d0: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x14d4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x14d8: 0xac205434  sw          $zero, 0x5434($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21556), GPR_U32(ctx, 0));
    // 0x14dc: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x14e0: 0x0  nop
    // NOP
    // 0x14e4: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x14e8: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x14ec: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x14f0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x14f4: 0xac205438  sw          $zero, 0x5438($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21560), GPR_U32(ctx, 0));
    // 0x14f8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x14fc: 0x0  nop
    // NOP
    // 0x1500: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1504: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1508: 0x2403007f  addiu       $v1, $zero, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x150c: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1510: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1514: 0xac23543c  sw          $v1, 0x543C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21564), GPR_U32(ctx, 3));
    // 0x1518: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x151c: 0x0  nop
    // NOP
    // 0x1520: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1524: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1528: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x152c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x1530: 0xac2061ac  sw          $zero, 0x61AC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 25004), GPR_U32(ctx, 0));
    // 0x1534: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1538: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x153c: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1540: 0x3e00008  jr          $ra
    ctx->pc = 0x1540u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1544: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1540u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1548u;
}


// Function: sounds_00001548
// Address: 0x1548 - 0x184c
void sounds_00001548_0x1548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001548_0x1548");
#endif

    switch (ctx->pc) {
        case 0x156cu: goto label_156c;
        case 0x15d0u: goto label_15d0;
        case 0x1624u: goto label_1624;
        case 0x163cu: goto label_163c;
        case 0x1680u: goto label_1680;
        case 0x171cu: goto label_171c;
        case 0x173cu: goto label_173c;
        case 0x17f8u: goto label_17f8;
        case 0x1808u: goto label_1808;
        default: break;
    }

    ctx->pc = 0x1548u;

    // 0x1548: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x154c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x1550: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x1554: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1558: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x155c: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1560: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1564: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1568: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
label_156c:
    // 0x156c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1570: 0x0  nop
    // NOP
    // 0x1574: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x1578: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1578u;
    {
        const bool branch_taken_0x1578 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1578) {
            ctx->pc = 0x1588u;
            goto label_1588;
        }
    }
    ctx->pc = 0x1580u;
    // 0x1580: 0x800059b  j           func_00166C
    ctx->pc = 0x1580u;
    ctx->pc = 0x166Cu;
    goto label_166c;
    ctx->pc = 0x1588u;
label_1588:
    // 0x1588: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x158c: 0x0  nop
    // NOP
    // 0x1590: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1594: 0x0  nop
    // NOP
    // 0x1598: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1598u;
    {
        const bool branch_taken_0x1598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1598) {
            ctx->pc = 0x15A8u;
            goto label_15a8;
        }
    }
    ctx->pc = 0x15A0u;
    // 0x15a0: 0x8000592  j           func_001648
    ctx->pc = 0x15A0u;
    ctx->pc = 0x1648u;
    goto label_1648;
    ctx->pc = 0x15A8u;
label_15a8:
    // 0x15a8: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x15ac: 0x0  nop
    // NOP
    // 0x15b0: 0x90620001  lbu         $v0, 0x1($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x15b4: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x15b8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x15bc: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x15c0: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x15c4: 0x8c660008  lw          $a2, 0x8($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x15c8: 0xc0009dc  jal         func_002770
    ctx->pc = 0x15C8u;
    SET_GPR_U32(ctx, 31, 0x15D0u);
    ctx->pc = 0x2770u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2770u, 0x15C8u, 0x15D0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15D0u;
label_15d0:
    // 0x15d0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x15D0u;
    {
        const bool branch_taken_0x15d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15d0) {
            ctx->pc = 0x1648u;
            goto label_1648;
        }
    }
    ctx->pc = 0x15D8u;
    // 0x15d8: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x15dc: 0x0  nop
    // NOP
    // 0x15e0: 0x90620001  lbu         $v0, 0x1($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x15e4: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x15e8: 0x0  nop
    // NOP
    // 0x15ec: 0x90830002  lbu         $v1, 0x2($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x15f0: 0x8fc70018  lw          $a3, 0x18($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x15f4: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x15f8: 0x0  nop
    // NOP
    // 0x15fc: 0x8c850008  lw          $a1, 0x8($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1600: 0x0  nop
    // NOP
    // 0x1604: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x1608: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x160c: 0x24842cac  addiu       $a0, $a0, 0x2CAC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11436));
    // 0x1610: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1614: 0x603021  addu        $a2, $v1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x1618: 0x8ce70004  lw          $a3, 0x4($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x161c: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x161Cu;
    SET_GPR_U32(ctx, 31, 0x1624u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x161Cu, 0x1624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1624u;
label_1624:
    // 0x1624: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1628: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x162c: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x1630: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1634: 0xc0009e2  jal         func_002788
    ctx->pc = 0x1634u;
    SET_GPR_U32(ctx, 31, 0x163Cu);
    ctx->pc = 0x2788u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2788u, 0x1634u, 0x163Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x163Cu;
label_163c:
    // 0x163c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1640: 0x0  nop
    // NOP
    // 0x1644: 0xa0400000  sb          $zero, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_1648:
    // 0x1648: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x164c: 0x0  nop
    // NOP
    // 0x1650: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1654: 0xafc3001c  sw          $v1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    // 0x1658: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x165c: 0x0  nop
    // NOP
    // 0x1660: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1664: 0x800055b  j           func_00156C
    ctx->pc = 0x1664u;
    // 0x1668: 0xafc30018  sw          $v1, 0x18($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x156Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_156c;
    ctx->pc = 0x166Cu;
label_166c:
    // 0x166c: 0xafc00024  sw          $zero, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1670: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1674: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1678: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x167c: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
label_1680:
    // 0x1680: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1684: 0x0  nop
    // NOP
    // 0x1688: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x168c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x168Cu;
    {
        const bool branch_taken_0x168c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x168c) {
            ctx->pc = 0x169Cu;
            goto label_169c;
        }
    }
    ctx->pc = 0x1694u;
    // 0x1694: 0x80005bf  j           func_0016FC
    ctx->pc = 0x1694u;
    ctx->pc = 0x16FCu;
    goto label_16fc;
    ctx->pc = 0x169Cu;
label_169c:
    // 0x169c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16a0: 0x0  nop
    // NOP
    // 0x16a4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16a8: 0x0  nop
    // NOP
    // 0x16ac: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x16ACu;
    {
        const bool branch_taken_0x16ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x16ac) {
            ctx->pc = 0x16D8u;
            goto label_16d8;
        }
    }
    ctx->pc = 0x16B4u;
    // 0x16b4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16b8: 0x0  nop
    // NOP
    // 0x16bc: 0x90430001  lbu         $v1, 0x1($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x16c0: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16c4: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16C4u;
    {
        const bool branch_taken_0x16c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x16c4) {
            ctx->pc = 0x16D8u;
            goto label_16d8;
        }
    }
    ctx->pc = 0x16CCu;
    // 0x16cc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16d0: 0x80005bf  j           func_0016FC
    ctx->pc = 0x16D0u;
    // 0x16d4: 0xafc20024  sw          $v0, 0x24($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    ctx->pc = 0x16FCu;
    goto label_16fc;
    ctx->pc = 0x16D8u;
label_16d8:
    // 0x16d8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x16dc: 0x0  nop
    // NOP
    // 0x16e0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16e4: 0xafc3001c  sw          $v1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    // 0x16e8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x16ec: 0x0  nop
    // NOP
    // 0x16f0: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x16f4: 0x80005a0  j           func_001680
    ctx->pc = 0x16F4u;
    // 0x16f8: 0xafc30018  sw          $v1, 0x18($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x1680u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1680;
    ctx->pc = 0x16FCu;
label_16fc:
    // 0x16fc: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1700: 0x0  nop
    // NOP
    // 0x1704: 0x1440004c  bnez        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x1704u;
    {
        const bool branch_taken_0x1704 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1704) {
            ctx->pc = 0x1838u;
            goto label_1838;
        }
    }
    ctx->pc = 0x170Cu;
    // 0x170c: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1710: 0x244254c0  addiu       $v0, $v0, 0x54C0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21696));
    // 0x1714: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1718: 0xafc00028  sw          $zero, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
label_171c:
    // 0x171c: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1720: 0x0  nop
    // NOP
    // 0x1724: 0x28430002  slti        $v1, $v0, 0x2
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1728: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1728u;
    {
        const bool branch_taken_0x1728 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1728) {
            ctx->pc = 0x1738u;
            goto label_1738;
        }
    }
    ctx->pc = 0x1730u;
    // 0x1730: 0x800060e  j           func_001838
    ctx->pc = 0x1730u;
    ctx->pc = 0x1838u;
    goto label_1838;
    ctx->pc = 0x1738u;
label_1738:
    // 0x1738: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
label_173c:
    // 0x173c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1740: 0x0  nop
    // NOP
    // 0x1744: 0x28430018  slti        $v1, $v0, 0x18
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x1748: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1748u;
    {
        const bool branch_taken_0x1748 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1748) {
            ctx->pc = 0x1758u;
            goto label_1758;
        }
    }
    ctx->pc = 0x1750u;
    // 0x1750: 0x8000609  j           func_001824
    ctx->pc = 0x1750u;
    ctx->pc = 0x1824u;
    goto label_1824;
    ctx->pc = 0x1758u;
label_1758:
    // 0x1758: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x175c: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1760: 0x0  nop
    // NOP
    // 0x1764: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x1768: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x176c: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1770: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1774: 0x8fc4001c  lw          $a0, 0x1C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1778: 0x0  nop
    // NOP
    // 0x177c: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1780: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1784: 0x90430008  lbu         $v1, 0x8($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1788: 0x0  nop
    // NOP
    // 0x178c: 0x30620020  andi        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32);
    // 0x1790: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1794: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1794u;
    {
        const bool branch_taken_0x1794 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1794) {
            ctx->pc = 0x17A4u;
            goto label_17a4;
        }
    }
    ctx->pc = 0x179Cu;
    // 0x179c: 0x8000604  j           func_001810
    ctx->pc = 0x179Cu;
    ctx->pc = 0x1810u;
    goto label_1810;
    ctx->pc = 0x17A4u;
label_17a4:
    // 0x17a4: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x17a8: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x17ac: 0x0  nop
    // NOP
    // 0x17b0: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x17b4: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x17b8: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x17bc: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x17c0: 0x8fc4001c  lw          $a0, 0x1C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x17c4: 0x0  nop
    // NOP
    // 0x17c8: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x17cc: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17d0: 0x90430008  lbu         $v1, 0x8($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x17d4: 0x0  nop
    // NOP
    // 0x17d8: 0x3062000f  andi        $v0, $v1, 0xF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x17dc: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x17e0: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17e4: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x17E4u;
    {
        const bool branch_taken_0x17e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x17e4) {
            ctx->pc = 0x1810u;
            goto label_1810;
        }
    }
    ctx->pc = 0x17ECu;
    // 0x17ec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x17f0: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x17F0u;
    SET_GPR_U32(ctx, 31, 0x17F8u);
    // 0x17f4: 0x24842d00  addiu       $a0, $a0, 0x2D00 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11520));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x17F0u, 0x17F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x17F8u;
label_17f8:
    // 0x17f8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x17fc: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x1800: 0xc0009cb  jal         func_00272C
    ctx->pc = 0x1800u;
    SET_GPR_U32(ctx, 31, 0x1808u);
    // 0x1804: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x272Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x272Cu, 0x1800u, 0x1808u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1808u;
label_1808:
    // 0x1808: 0x8000609  j           func_001824
    ctx->pc = 0x1808u;
    ctx->pc = 0x1824u;
    goto label_1824;
    ctx->pc = 0x1810u;
label_1810:
    // 0x1810: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1814: 0x0  nop
    // NOP
    // 0x1818: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x181c: 0x80005cf  j           func_00173C
    ctx->pc = 0x181Cu;
    // 0x1820: 0xafc3001c  sw          $v1, 0x1C($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    ctx->pc = 0x173Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_173c;
    ctx->pc = 0x1824u;
label_1824:
    // 0x1824: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1828: 0x0  nop
    // NOP
    // 0x182c: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1830: 0x80005c7  j           func_00171C
    ctx->pc = 0x1830u;
    // 0x1834: 0xafc30028  sw          $v1, 0x28($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 3));
    ctx->pc = 0x171Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_171c;
    ctx->pc = 0x1838u;
label_1838:
    // 0x1838: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x183c: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x1840: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1844: 0x3e00008  jr          $ra
    ctx->pc = 0x1844u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1848: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1844u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x184Cu;
}


// Function: sounds_0000184c
// Address: 0x184c - 0x1ab0
void sounds_0000184c_0x184c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000184c_0x184c");
#endif

    switch (ctx->pc) {
        case 0x187cu: goto label_187c;
        case 0x18f8u: goto label_18f8;
        case 0x1910u: goto label_1910;
        case 0x1974u: goto label_1974;
        case 0x1984u: goto label_1984;
        case 0x199cu: goto label_199c;
        case 0x1a9cu: goto label_1a9c;
        default: break;
    }

    ctx->pc = 0x184cu;

    // 0x184c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1850: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
    // 0x1854: 0xafbe0038  sw          $fp, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 30));
    // 0x1858: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x185c: 0xafc40040  sw          $a0, 0x40($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 4));
    // 0x1860: 0xafc00020  sw          $zero, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x1864: 0x8fc20040  lw          $v0, 0x40($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1868: 0x0  nop
    // NOP
    // 0x186c: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1870: 0x0  nop
    // NOP
    // 0x1874: 0xc000100  jal         func_000400
    ctx->pc = 0x1874u;
    SET_GPR_U32(ctx, 31, 0x187Cu);
    // 0x1878: 0x602021  addu        $a0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1874u, 0x187Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x187Cu;
label_187c:
    // 0x187c: 0x8fc40040  lw          $a0, 0x40($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1880: 0x0  nop
    // NOP
    // 0x1884: 0x90830005  lbu         $v1, 0x5($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1888: 0x8fc40040  lw          $a0, 0x40($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x188c: 0x0  nop
    // NOP
    // 0x1890: 0x90870001  lbu         $a3, 0x1($a0)
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1894: 0x8fc40040  lw          $a0, 0x40($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1898: 0x0  nop
    // NOP
    // 0x189c: 0x90850006  lbu         $a1, 0x6($a0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x18a0: 0x0  nop
    // NOP
    // 0x18a4: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x18a8: 0x8fc40040  lw          $a0, 0x40($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x18ac: 0x0  nop
    // NOP
    // 0x18b0: 0x90850007  lbu         $a1, 0x7($a0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x18b4: 0x0  nop
    // NOP
    // 0x18b8: 0xafa50014  sw          $a1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x18bc: 0x8fc40040  lw          $a0, 0x40($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x18c0: 0x0  nop
    // NOP
    // 0x18c4: 0x8c850008  lw          $a1, 0x8($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x18c8: 0x0  nop
    // NOP
    // 0x18cc: 0xafa50018  sw          $a1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 5));
    // 0x18d0: 0x8fc40040  lw          $a0, 0x40($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x18d4: 0x0  nop
    // NOP
    // 0x18d8: 0x94850002  lhu         $a1, 0x2($a0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18dc: 0x0  nop
    // NOP
    // 0x18e0: 0xafa5001c  sw          $a1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 5));
    // 0x18e4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x18e8: 0x24842d40  addiu       $a0, $a0, 0x2D40
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11584));
    // 0x18ec: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x18f0: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x18F0u;
    SET_GPR_U32(ctx, 31, 0x18F8u);
    // 0x18f4: 0x603021  addu        $a2, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x18F0u, 0x18F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x18F8u;
label_18f8:
    // 0x18f8: 0x8fc20040  lw          $v0, 0x40($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x18fc: 0x0  nop
    // NOP
    // 0x1900: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1904: 0x0  nop
    // NOP
    // 0x1908: 0xc000100  jal         func_000400
    ctx->pc = 0x1908u;
    SET_GPR_U32(ctx, 31, 0x1910u);
    // 0x190c: 0x602021  addu        $a0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1908u, 0x1910u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1910u;
label_1910:
    // 0x1910: 0xafc20028  sw          $v0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1914: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1918: 0x0  nop
    // NOP
    // 0x191c: 0x90620005  lbu         $v0, 0x5($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 5)));
    // 0x1920: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1924: 0x0  nop
    // NOP
    // 0x1928: 0x90640006  lbu         $a0, 0x6($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 6)));
    // 0x192c: 0x0  nop
    // NOP
    // 0x1930: 0xafa40010  sw          $a0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 4));
    // 0x1934: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1938: 0x0  nop
    // NOP
    // 0x193c: 0x90640007  lbu         $a0, 0x7($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 7)));
    // 0x1940: 0x0  nop
    // NOP
    // 0x1944: 0xafa40014  sw          $a0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 4));
    // 0x1948: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x194c: 0x0  nop
    // NOP
    // 0x1950: 0x84640008  lh          $a0, 0x8($v1)
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1954: 0x0  nop
    // NOP
    // 0x1958: 0xafa40018  sw          $a0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 4));
    // 0x195c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1960: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x1964: 0x8fc50028  lw          $a1, 0x28($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1968: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x196c: 0xc0009e0  jal         func_002780
    ctx->pc = 0x196Cu;
    SET_GPR_U32(ctx, 31, 0x1974u);
    // 0x1970: 0x403821  addu        $a3, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2780u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2780u, 0x196Cu, 0x1974u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1974u;
label_1974:
    // 0x1974: 0xafc2002c  sw          $v0, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1978: 0x8fc4002c  lw          $a0, 0x2C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x197c: 0xc000159  jal         func_000564
    ctx->pc = 0x197Cu;
    SET_GPR_U32(ctx, 31, 0x1984u);
    ctx->pc = 0x564u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x564u, 0x197Cu, 0x1984u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1984u;
label_1984:
    // 0x1984: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1984u;
    {
        const bool branch_taken_0x1984 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1984) {
            ctx->pc = 0x1A9Cu;
            goto label_1a9c;
        }
    }
    ctx->pc = 0x198Cu;
    // 0x198c: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1990: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1994: 0xafc20024  sw          $v0, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1998: 0xafc00030  sw          $zero, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 0));
label_199c:
    // 0x199c: 0x8fc20030  lw          $v0, 0x30($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x19a0: 0x0  nop
    // NOP
    // 0x19a4: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x19a8: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19A8u;
    {
        const bool branch_taken_0x19a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19a8) {
            ctx->pc = 0x19B8u;
            goto label_19b8;
        }
    }
    ctx->pc = 0x19B0u;
    // 0x19b0: 0x80006a0  j           func_001A80
    ctx->pc = 0x19B0u;
    ctx->pc = 0x1A80u;
    goto label_1a80;
    ctx->pc = 0x19B8u;
label_19b8:
    // 0x19b8: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x19bc: 0x0  nop
    // NOP
    // 0x19c0: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x19c4: 0x0  nop
    // NOP
    // 0x19c8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19C8u;
    {
        const bool branch_taken_0x19c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x19c8) {
            ctx->pc = 0x19D8u;
            goto label_19d8;
        }
    }
    ctx->pc = 0x19D0u;
    // 0x19d0: 0x8000697  j           func_001A5C
    ctx->pc = 0x19D0u;
    ctx->pc = 0x1A5Cu;
    goto label_1a5c;
    ctx->pc = 0x19D8u;
label_19d8:
    // 0x19d8: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x19dc: 0x0  nop
    // NOP
    // 0x19e0: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x19e4: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x19e8: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ec: 0xa0430000  sb          $v1, 0x0($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x19f0: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x19f4: 0x93c30028  lbu         $v1, 0x28($fp)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x19f8: 0x0  nop
    // NOP
    // 0x19fc: 0xa0430001  sb          $v1, 0x1($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a00: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1a04: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1a08: 0x0  nop
    // NOP
    // 0x1a0c: 0x90640001  lbu         $a0, 0x1($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x1a10: 0x0  nop
    // NOP
    // 0x1a14: 0xa0440003  sb          $a0, 0x3($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a18: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1a1c: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1a20: 0x0  nop
    // NOP
    // 0x1a24: 0x90640005  lbu         $a0, 0x5($v1)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 5)));
    // 0x1a28: 0x0  nop
    // NOP
    // 0x1a2c: 0xa0440002  sb          $a0, 0x2($v0)
    WRITE8(ADD32(GPR_U32(ctx, 2), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1a30: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1a34: 0x8fc30040  lw          $v1, 0x40($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1a38: 0x0  nop
    // NOP
    // 0x1a3c: 0x94640002  lhu         $a0, 0x2($v1)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1a40: 0x0  nop
    // NOP
    // 0x1a44: 0xac440004  sw          $a0, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 4));
    // 0x1a48: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1a4c: 0x8fc3002c  lw          $v1, 0x2C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1a50: 0x0  nop
    // NOP
    // 0x1a54: 0x80006a0  j           func_001A80
    ctx->pc = 0x1A54u;
    // 0x1a58: 0xac430008  sw          $v1, 0x8($v0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    ctx->pc = 0x1A80u;
    goto label_1a80;
    ctx->pc = 0x1A5Cu;
label_1a5c:
    // 0x1a5c: 0x8fc20030  lw          $v0, 0x30($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1a60: 0x0  nop
    // NOP
    // 0x1a64: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a68: 0xafc30030  sw          $v1, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 3));
    // 0x1a6c: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1a70: 0x0  nop
    // NOP
    // 0x1a74: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1a78: 0x8000667  j           func_00199C
    ctx->pc = 0x1A78u;
    // 0x1a7c: 0xafc30024  sw          $v1, 0x24($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 3));
    ctx->pc = 0x199Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_199c;
    ctx->pc = 0x1A80u;
label_1a80:
    // 0x1a80: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1a84: 0x0  nop
    // NOP
    // 0x1a88: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A88u;
    {
        const bool branch_taken_0x1a88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a88) {
            ctx->pc = 0x1A9Cu;
            goto label_1a9c;
        }
    }
    ctx->pc = 0x1A90u;
    // 0x1a90: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1a94: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1A94u;
    SET_GPR_U32(ctx, 31, 0x1A9Cu);
    // 0x1a98: 0x24842da8  addiu       $a0, $a0, 0x2DA8 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11688));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1A94u, 0x1A9Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A9Cu;
label_1a9c:
    // 0x1a9c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1aa0: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1aa4: 0x8fbe0038  lw          $fp, 0x38($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1aa8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AA8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1aac: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AA8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AB0u;
}


// Function: sounds_00001ab0
// Address: 0x1ab0 - 0x1c5c
void sounds_00001ab0_0x1ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001ab0_0x1ab0");
#endif

    switch (ctx->pc) {
        case 0x1ae0u: goto label_1ae0;
        case 0x1b00u: goto label_1b00;
        case 0x1b18u: goto label_1b18;
        case 0x1b2cu: goto label_1b2c;
        case 0x1bc4u: goto label_1bc4;
        case 0x1bd4u: goto label_1bd4;
        case 0x1c20u: goto label_1c20;
        case 0x1c40u: goto label_1c40;
        default: break;
    }

    ctx->pc = 0x1ab0u;

    // 0x1ab0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ab4: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
    // 0x1ab8: 0xafbe0028  sw          $fp, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 30));
    // 0x1abc: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1ac0: 0xafc40030  sw          $a0, 0x30($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 4));
    // 0x1ac4: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1ac8: 0x8fc20030  lw          $v0, 0x30($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1acc: 0x0  nop
    // NOP
    // 0x1ad0: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1ad4: 0x0  nop
    // NOP
    // 0x1ad8: 0xc000100  jal         func_000400
    ctx->pc = 0x1AD8u;
    SET_GPR_U32(ctx, 31, 0x1AE0u);
    // 0x1adc: 0x602021  addu        $a0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1AD8u, 0x1AE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1AE0u;
label_1ae0:
    // 0x1ae0: 0x8fc40030  lw          $a0, 0x30($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1ae4: 0x0  nop
    // NOP
    // 0x1ae8: 0x90830005  lbu         $v1, 0x5($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1aec: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1af0: 0x24842dd8  addiu       $a0, $a0, 0x2DD8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11736));
    // 0x1af4: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1af8: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1AF8u;
    SET_GPR_U32(ctx, 31, 0x1B00u);
    // 0x1afc: 0x603021  addu        $a2, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1AF8u, 0x1B00u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B00u;
label_1b00:
    // 0x1b00: 0x8fc20030  lw          $v0, 0x30($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1b04: 0x0  nop
    // NOP
    // 0x1b08: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1b0c: 0x0  nop
    // NOP
    // 0x1b10: 0xc000100  jal         func_000400
    ctx->pc = 0x1B10u;
    SET_GPR_U32(ctx, 31, 0x1B18u);
    // 0x1b14: 0x602021  addu        $a0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1B10u, 0x1B18u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B18u;
label_1b18:
    // 0x1b18: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1b1c: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1b20: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1b24: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1b28: 0xafc00020  sw          $zero, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
label_1b2c:
    // 0x1b2c: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1b30: 0x0  nop
    // NOP
    // 0x1b34: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x1b38: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B38u;
    {
        const bool branch_taken_0x1b38 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b38) {
            ctx->pc = 0x1B48u;
            goto label_1b48;
        }
    }
    ctx->pc = 0x1B40u;
    // 0x1b40: 0x80006fe  j           func_001BF8
    ctx->pc = 0x1B40u;
    ctx->pc = 0x1BF8u;
    goto label_1bf8;
    ctx->pc = 0x1B48u;
label_1b48:
    // 0x1b48: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1b4c: 0x0  nop
    // NOP
    // 0x1b50: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b54: 0x0  nop
    // NOP
    // 0x1b58: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B58u;
    {
        const bool branch_taken_0x1b58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b58) {
            ctx->pc = 0x1B68u;
            goto label_1b68;
        }
    }
    ctx->pc = 0x1B60u;
    // 0x1b60: 0x80006f5  j           func_001BD4
    ctx->pc = 0x1B60u;
    ctx->pc = 0x1BD4u;
    goto label_1bd4;
    ctx->pc = 0x1B68u;
label_1b68:
    // 0x1b68: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1b6c: 0x0  nop
    // NOP
    // 0x1b70: 0x90430001  lbu         $v1, 0x1($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x1b74: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1b78: 0x0  nop
    // NOP
    // 0x1b7c: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B7Cu;
    {
        const bool branch_taken_0x1b7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b7c) {
            ctx->pc = 0x1BD4u;
            goto label_1bd4;
        }
    }
    ctx->pc = 0x1B84u;
    // 0x1b84: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1b88: 0x8fc30030  lw          $v1, 0x30($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1b8c: 0x90420002  lbu         $v0, 0x2($v0)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1b90: 0x90630005  lbu         $v1, 0x5($v1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 5)));
    // 0x1b94: 0x0  nop
    // NOP
    // 0x1b98: 0x1443000e  bne         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1B98u;
    {
        const bool branch_taken_0x1b98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b98) {
            ctx->pc = 0x1BD4u;
            goto label_1bd4;
        }
    }
    ctx->pc = 0x1BA0u;
    // 0x1ba0: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1ba4: 0x0  nop
    // NOP
    // 0x1ba8: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1bac: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1bb0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1bb4: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x1bb8: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1bbc: 0xc0009e2  jal         func_002788
    ctx->pc = 0x1BBCu;
    SET_GPR_U32(ctx, 31, 0x1BC4u);
    ctx->pc = 0x2788u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2788u, 0x1BBCu, 0x1BC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BC4u;
label_1bc4:
    // 0x1bc4: 0xafc2001c  sw          $v0, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1bc8: 0x8fc4001c  lw          $a0, 0x1C($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1bcc: 0xc000175  jal         func_0005D4
    ctx->pc = 0x1BCCu;
    SET_GPR_U32(ctx, 31, 0x1BD4u);
    ctx->pc = 0x5D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5D4u, 0x1BCCu, 0x1BD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BD4u;
label_1bd4:
    // 0x1bd4: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1bd8: 0x0  nop
    // NOP
    // 0x1bdc: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1be0: 0xafc30020  sw          $v1, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 3));
    // 0x1be4: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1be8: 0x0  nop
    // NOP
    // 0x1bec: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1bf0: 0x80006cb  j           func_001B2C
    ctx->pc = 0x1BF0u;
    // 0x1bf4: 0xafc30014  sw          $v1, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
    ctx->pc = 0x1B2Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1b2c;
    ctx->pc = 0x1BF8u;
label_1bf8:
    // 0x1bf8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1bfc: 0x0  nop
    // NOP
    // 0x1c00: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C00u;
    {
        const bool branch_taken_0x1c00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c00) {
            ctx->pc = 0x1C48u;
            goto label_1c48;
        }
    }
    ctx->pc = 0x1C08u;
    // 0x1c08: 0x8fc20030  lw          $v0, 0x30($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1c0c: 0x0  nop
    // NOP
    // 0x1c10: 0x90430004  lbu         $v1, 0x4($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1c14: 0x0  nop
    // NOP
    // 0x1c18: 0xc000100  jal         func_000400
    ctx->pc = 0x1C18u;
    SET_GPR_U32(ctx, 31, 0x1C20u);
    // 0x1c1c: 0x602021  addu        $a0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1C18u, 0x1C20u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C20u;
label_1c20:
    // 0x1c20: 0x8fc40030  lw          $a0, 0x30($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1c24: 0x0  nop
    // NOP
    // 0x1c28: 0x90830005  lbu         $v1, 0x5($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1c2c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c30: 0x24842e0c  addiu       $a0, $a0, 0x2E0C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11788));
    // 0x1c34: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1c38: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1C38u;
    SET_GPR_U32(ctx, 31, 0x1C40u);
    // 0x1c3c: 0x603021  addu        $a2, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1C38u, 0x1C40u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C40u;
label_1c40:
    // 0x1c40: 0x8000712  j           func_001C48
    ctx->pc = 0x1C40u;
    ctx->pc = 0x1C48u;
    goto label_1c48;
    ctx->pc = 0x1C48u;
label_1c48:
    // 0x1c48: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1c4c: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1c50: 0x8fbe0028  lw          $fp, 0x28($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1c54: 0x3e00008  jr          $ra
    ctx->pc = 0x1C54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c58: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
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


// Function: sounds_00001c5c
// Address: 0x1c5c - 0x1da0
void sounds_00001c5c_0x1c5c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001c5c_0x1c5c");
#endif

    switch (ctx->pc) {
        case 0x1c90u: goto label_1c90;
        case 0x1ca0u: goto label_1ca0;
        case 0x1d5cu: goto label_1d5c;
        case 0x1d7cu: goto label_1d7c;
        case 0x1d8cu: goto label_1d8c;
        default: break;
    }

    ctx->pc = 0x1c5cu;

    // 0x1c5c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1c60: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1c64: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0x1c68: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1c6c: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
    // 0x1c70: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1c74: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1c78: 0x0  nop
    // NOP
    // 0x1c7c: 0x94430002  lhu         $v1, 0x2($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1c80: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1c84: 0x24842e48  addiu       $a0, $a0, 0x2E48
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11848));
    // 0x1c88: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1C88u;
    SET_GPR_U32(ctx, 31, 0x1C90u);
    // 0x1c8c: 0x602821  addu        $a1, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1C88u, 0x1C90u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C90u;
label_1c90:
    // 0x1c90: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1c94: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1c98: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1c9c: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
label_1ca0:
    // 0x1ca0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1ca4: 0x0  nop
    // NOP
    // 0x1ca8: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x1cac: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CACu;
    {
        const bool branch_taken_0x1cac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cac) {
            ctx->pc = 0x1CBCu;
            goto label_1cbc;
        }
    }
    ctx->pc = 0x1CB4u;
    // 0x1cb4: 0x800074c  j           func_001D30
    ctx->pc = 0x1CB4u;
    ctx->pc = 0x1D30u;
    goto label_1d30;
    ctx->pc = 0x1CBCu;
label_1cbc:
    // 0x1cbc: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1cc0: 0x0  nop
    // NOP
    // 0x1cc4: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cc8: 0x0  nop
    // NOP
    // 0x1ccc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CCCu;
    {
        const bool branch_taken_0x1ccc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ccc) {
            ctx->pc = 0x1CDCu;
            goto label_1cdc;
        }
    }
    ctx->pc = 0x1CD4u;
    // 0x1cd4: 0x8000743  j           func_001D0C
    ctx->pc = 0x1CD4u;
    ctx->pc = 0x1D0Cu;
    goto label_1d0c;
    ctx->pc = 0x1CDCu;
label_1cdc:
    // 0x1cdc: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1ce0: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ce4: 0x0  nop
    // NOP
    // 0x1ce8: 0x94640002  lhu         $a0, 0x2($v1)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1cec: 0x8c420004  lw          $v0, 0x4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1cf0: 0x0  nop
    // NOP
    // 0x1cf4: 0x14440005  bne         $v0, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CF4u;
    {
        const bool branch_taken_0x1cf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cf4) {
            ctx->pc = 0x1D0Cu;
            goto label_1d0c;
        }
    }
    ctx->pc = 0x1CFCu;
    // 0x1cfc: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1d00: 0x0  nop
    // NOP
    // 0x1d04: 0x800074c  j           func_001D30
    ctx->pc = 0x1D04u;
    // 0x1d08: 0xafc20010  sw          $v0, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    ctx->pc = 0x1D30u;
    goto label_1d30;
    ctx->pc = 0x1D0Cu;
label_1d0c:
    // 0x1d0c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1d10: 0x0  nop
    // NOP
    // 0x1d14: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d18: 0xafc3001c  sw          $v1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    // 0x1d1c: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1d20: 0x0  nop
    // NOP
    // 0x1d24: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1d28: 0x8000728  j           func_001CA0
    ctx->pc = 0x1D28u;
    // 0x1d2c: 0xafc30014  sw          $v1, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 3));
    ctx->pc = 0x1CA0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1ca0;
    ctx->pc = 0x1D30u;
label_1d30:
    // 0x1d30: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1d34: 0x0  nop
    // NOP
    // 0x1d38: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D38u;
    {
        const bool branch_taken_0x1d38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d38) {
            ctx->pc = 0x1D64u;
            goto label_1d64;
        }
    }
    ctx->pc = 0x1D40u;
    // 0x1d40: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1d44: 0x0  nop
    // NOP
    // 0x1d48: 0x94430002  lhu         $v1, 0x2($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1d4c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1d50: 0x24842e74  addiu       $a0, $a0, 0x2E74
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11892));
    // 0x1d54: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1D54u;
    SET_GPR_U32(ctx, 31, 0x1D5Cu);
    // 0x1d58: 0x602821  addu        $a1, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1D54u, 0x1D5Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D5Cu;
label_1d5c:
    // 0x1d5c: 0x8000763  j           func_001D8C
    ctx->pc = 0x1D5Cu;
    ctx->pc = 0x1D8Cu;
    goto label_1d8c;
    ctx->pc = 0x1D64u;
label_1d64:
    // 0x1d64: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1d68: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1d6c: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x1d70: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1d74: 0xc0009e2  jal         func_002788
    ctx->pc = 0x1D74u;
    SET_GPR_U32(ctx, 31, 0x1D7Cu);
    ctx->pc = 0x2788u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2788u, 0x1D74u, 0x1D7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D7Cu;
label_1d7c:
    // 0x1d7c: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1d80: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1d84: 0xc000175  jal         func_0005D4
    ctx->pc = 0x1D84u;
    SET_GPR_U32(ctx, 31, 0x1D8Cu);
    ctx->pc = 0x5D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5D4u, 0x1D84u, 0x1D8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1D8Cu;
label_1d8c:
    // 0x1d8c: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1d90: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1d94: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d98: 0x3e00008  jr          $ra
    ctx->pc = 0x1D98u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d9c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1D98u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1DA0u;
}


// Function: sounds_00001da0
// Address: 0x1da0 - 0x1ee4
void sounds_00001da0_0x1da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001da0_0x1da0");
#endif

    switch (ctx->pc) {
        case 0x1dccu: goto label_1dcc;
        case 0x1de0u: goto label_1de0;
        case 0x1ea0u: goto label_1ea0;
        case 0x1ec0u: goto label_1ec0;
        default: break;
    }

    ctx->pc = 0x1da0u;

    // 0x1da0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1da4: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1da8: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0x1dac: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1db0: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
    // 0x1db4: 0xafc00018  sw          $zero, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
    // 0x1db8: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1dbc: 0x0  nop
    // NOP
    // 0x1dc0: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc4: 0xc000100  jal         func_000400
    ctx->pc = 0x1DC4u;
    SET_GPR_U32(ctx, 31, 0x1DCCu);
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1DC4u, 0x1DCCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1DCCu;
label_1dcc:
    // 0x1dcc: 0xafc20014  sw          $v0, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dd0: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1dd4: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1dd8: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1ddc: 0xafc0001c  sw          $zero, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
label_1de0:
    // 0x1de0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1de4: 0x0  nop
    // NOP
    // 0x1de8: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x1dec: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DECu;
    {
        const bool branch_taken_0x1dec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dec) {
            ctx->pc = 0x1DFCu;
            goto label_1dfc;
        }
    }
    ctx->pc = 0x1DF4u;
    // 0x1df4: 0x80007a3  j           func_001E8C
    ctx->pc = 0x1DF4u;
    ctx->pc = 0x1E8Cu;
    goto label_1e8c;
    ctx->pc = 0x1DFCu;
label_1dfc:
    // 0x1dfc: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e00: 0x0  nop
    // NOP
    // 0x1e04: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e08: 0x0  nop
    // NOP
    // 0x1e0c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E0Cu;
    {
        const bool branch_taken_0x1e0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e0c) {
            ctx->pc = 0x1E1Cu;
            goto label_1e1c;
        }
    }
    ctx->pc = 0x1E14u;
    // 0x1e14: 0x800079a  j           func_001E68
    ctx->pc = 0x1E14u;
    ctx->pc = 0x1E68u;
    goto label_1e68;
    ctx->pc = 0x1E1Cu;
label_1e1c:
    // 0x1e1c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e20: 0x0  nop
    // NOP
    // 0x1e24: 0x90430001  lbu         $v1, 0x1($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x1e28: 0x8fc20014  lw          $v0, 0x14($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e2c: 0x0  nop
    // NOP
    // 0x1e30: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1E30u;
    {
        const bool branch_taken_0x1e30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e30) {
            ctx->pc = 0x1E68u;
            goto label_1e68;
        }
    }
    ctx->pc = 0x1E38u;
    // 0x1e38: 0x8fc30010  lw          $v1, 0x10($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e3c: 0x0  nop
    // NOP
    // 0x1e40: 0x90620002  lbu         $v0, 0x2($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x1e44: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e48: 0x0  nop
    // NOP
    // 0x1e4c: 0x8c640004  lw          $a0, 0x4($v1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1e50: 0x0  nop
    // NOP
    // 0x1e54: 0x14440004  bne         $v0, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E54u;
    {
        const bool branch_taken_0x1e54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x1e54) {
            ctx->pc = 0x1E68u;
            goto label_1e68;
        }
    }
    ctx->pc = 0x1E5Cu;
    // 0x1e5c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e60: 0x80007a3  j           func_001E8C
    ctx->pc = 0x1E60u;
    // 0x1e64: 0xafc20018  sw          $v0, 0x18($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    ctx->pc = 0x1E8Cu;
    goto label_1e8c;
    ctx->pc = 0x1E68u;
label_1e68:
    // 0x1e68: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e6c: 0x0  nop
    // NOP
    // 0x1e70: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e74: 0xafc3001c  sw          $v1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    // 0x1e78: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7c: 0x0  nop
    // NOP
    // 0x1e80: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1e84: 0x8000778  j           func_001DE0
    ctx->pc = 0x1E84u;
    // 0x1e88: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x1DE0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1de0;
    ctx->pc = 0x1E8Cu;
label_1e8c:
    // 0x1e8c: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1e90: 0x0  nop
    // NOP
    // 0x1e94: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e98: 0xc000100  jal         func_000400
    ctx->pc = 0x1E98u;
    SET_GPR_U32(ctx, 31, 0x1EA0u);
    ctx->pc = 0x400u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x400u, 0x1E98u, 0x1EA0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EA0u;
label_1ea0:
    // 0x1ea0: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1ea4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1ea8: 0x24842ea8  addiu       $a0, $a0, 0x2EA8
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11944));
    // 0x1eac: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x1eb0: 0x8c660004  lw          $a2, 0x4($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1eb4: 0x8fc70018  lw          $a3, 0x18($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eb8: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1EB8u;
    SET_GPR_U32(ctx, 31, 0x1EC0u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1EB8u, 0x1EC0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1EC0u;
label_1ec0:
    // 0x1ec0: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1ec4: 0x0  nop
    // NOP
    // 0x1ec8: 0x80007b4  j           func_001ED0
    ctx->pc = 0x1EC8u;
    // 0x1ecc: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1ED0u;
    goto label_1ed0;
    ctx->pc = 0x1ED0u;
label_1ed0:
    // 0x1ed0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1ed4: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1ed8: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1edc: 0x3e00008  jr          $ra
    ctx->pc = 0x1EDCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ee0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1EDCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1EE4u;
}


// Function: sounds_00001ee4
// Address: 0x1ee4 - 0x1fd4
void sounds_00001ee4_0x1ee4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001ee4_0x1ee4");
#endif

    switch (ctx->pc) {
        case 0x1f0cu: goto label_1f0c;
        case 0x1fb0u: goto label_1fb0;
        default: break;
    }

    ctx->pc = 0x1ee4u;

    // 0x1ee4: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1ee8: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
    // 0x1eec: 0xafbe0020  sw          $fp, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0x1ef0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1ef4: 0xafc40028  sw          $a0, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 4));
    // 0x1ef8: 0xafc00014  sw          $zero, 0x14($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1efc: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1f00: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x1f04: 0xafc20010  sw          $v0, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f08: 0xafc00018  sw          $zero, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
label_1f0c:
    // 0x1f0c: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f10: 0x0  nop
    // NOP
    // 0x1f14: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x1f18: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F18u;
    {
        const bool branch_taken_0x1f18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f18) {
            ctx->pc = 0x1F28u;
            goto label_1f28;
        }
    }
    ctx->pc = 0x1F20u;
    // 0x1f20: 0x80007e5  j           func_001F94
    ctx->pc = 0x1F20u;
    ctx->pc = 0x1F94u;
    goto label_1f94;
    ctx->pc = 0x1F28u;
label_1f28:
    // 0x1f28: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f2c: 0x0  nop
    // NOP
    // 0x1f30: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f34: 0x0  nop
    // NOP
    // 0x1f38: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F38u;
    {
        const bool branch_taken_0x1f38 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f38) {
            ctx->pc = 0x1F48u;
            goto label_1f48;
        }
    }
    ctx->pc = 0x1F40u;
    // 0x1f40: 0x80007dc  j           func_001F70
    ctx->pc = 0x1F40u;
    ctx->pc = 0x1F70u;
    goto label_1f70;
    ctx->pc = 0x1F48u;
label_1f48:
    // 0x1f48: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f4c: 0x8fc30028  lw          $v1, 0x28($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f50: 0x8c420004  lw          $v0, 0x4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f54: 0x8c630000  lw          $v1, 0x0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f58: 0x0  nop
    // NOP
    // 0x1f5c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F5Cu;
    {
        const bool branch_taken_0x1f5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f5c) {
            ctx->pc = 0x1F70u;
            goto label_1f70;
        }
    }
    ctx->pc = 0x1F64u;
    // 0x1f64: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f68: 0x80007e5  j           func_001F94
    ctx->pc = 0x1F68u;
    // 0x1f6c: 0xafc20014  sw          $v0, 0x14($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    ctx->pc = 0x1F94u;
    goto label_1f94;
    ctx->pc = 0x1F70u;
label_1f70:
    // 0x1f70: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1f74: 0x0  nop
    // NOP
    // 0x1f78: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f7c: 0xafc30018  sw          $v1, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
    // 0x1f80: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f84: 0x0  nop
    // NOP
    // 0x1f88: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1f8c: 0x80007c3  j           func_001F0C
    ctx->pc = 0x1F8Cu;
    // 0x1f90: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x1F0Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1f0c;
    ctx->pc = 0x1F94u;
label_1f94:
    // 0x1f94: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1f98: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1f9c: 0x24842ee4  addiu       $a0, $a0, 0x2EE4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12004));
    // 0x1fa0: 0x8c450000  lw          $a1, 0x0($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1fa4: 0x8fc60014  lw          $a2, 0x14($fp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1fa8: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x1FA8u;
    SET_GPR_U32(ctx, 31, 0x1FB0u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x1FA8u, 0x1FB0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1FB0u;
label_1fb0:
    // 0x1fb0: 0x8fc30014  lw          $v1, 0x14($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1fb4: 0x0  nop
    // NOP
    // 0x1fb8: 0x80007f0  j           func_001FC0
    ctx->pc = 0x1FB8u;
    // 0x1fbc: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x1FC0u;
    goto label_1fc0;
    ctx->pc = 0x1FC0u;
label_1fc0:
    // 0x1fc0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x1fc4: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1fc8: 0x8fbe0020  lw          $fp, 0x20($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1fcc: 0x3e00008  jr          $ra
    ctx->pc = 0x1FCCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1fd0: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1FCCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1FD4u;
}


// Function: sounds_00001fd4
// Address: 0x1fd4 - 0x20e4
void sounds_00001fd4_0x1fd4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00001fd4_0x1fd4");
#endif

    switch (ctx->pc) {
        case 0x2008u: goto label_2008;
        case 0x200cu: goto label_200c;
        case 0x2084u: goto label_2084;
        case 0x20bcu: goto label_20bc;
        default: break;
    }

    ctx->pc = 0x1fd4u;

    // 0x1fd4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1fd8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x1fdc: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x1fe0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x1fe4: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x1fe8: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1fec: 0x8fc30020  lw          $v1, 0x20($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1ff0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x1ff4: 0x24842f18  addiu       $a0, $a0, 0x2F18
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12056));
    // 0x1ff8: 0x8c450000  lw          $a1, 0x0($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ffc: 0x8c660004  lw          $a2, 0x4($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x2000: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x2000u;
    SET_GPR_U32(ctx, 31, 0x2008u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x2000u, 0x2008u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2008u;
label_2008:
    // 0x2008: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_200c:
    // 0x200c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x2010: 0x0  nop
    // NOP
    // 0x2014: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x2018: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2018u;
    {
        const bool branch_taken_0x2018 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2018) {
            ctx->pc = 0x2028u;
            goto label_2028;
        }
    }
    ctx->pc = 0x2020u;
    // 0x2020: 0x8000834  j           func_0020D0
    ctx->pc = 0x2020u;
    ctx->pc = 0x20D0u;
    goto label_20d0;
    ctx->pc = 0x2028u;
label_2028:
    // 0x2028: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x202c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2030: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x2034: 0x0  nop
    // NOP
    // 0x2038: 0x831804  sllv        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x203c: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2040: 0x0  nop
    // NOP
    // 0x2044: 0x641024  and         $v0, $v1, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x2048: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2048u;
    {
        const bool branch_taken_0x2048 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2048) {
            ctx->pc = 0x2058u;
            goto label_2058;
        }
    }
    ctx->pc = 0x2050u;
    // 0x2050: 0x800082f  j           func_0020BC
    ctx->pc = 0x2050u;
    ctx->pc = 0x20BCu;
    goto label_20bc;
    ctx->pc = 0x2058u;
label_2058:
    // 0x2058: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x205c: 0x0  nop
    // NOP
    // 0x2060: 0x8c430004  lw          $v1, 0x4($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x2064: 0x0  nop
    // NOP
    // 0x2068: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x2068u;
    {
        const bool branch_taken_0x2068 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x2068) {
            ctx->pc = 0x208Cu;
            goto label_208c;
        }
    }
    ctx->pc = 0x2070u;
    // 0x2070: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2074: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x2078: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x207c: 0xc0009c5  jal         func_002714
    ctx->pc = 0x207Cu;
    SET_GPR_U32(ctx, 31, 0x2084u);
    // 0x2080: 0x3021  addu        $a2, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2714u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2714u, 0x207Cu, 0x2084u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2084u;
label_2084:
    // 0x2084: 0x800082f  j           func_0020BC
    ctx->pc = 0x2084u;
    ctx->pc = 0x20BCu;
    goto label_20bc;
    ctx->pc = 0x208Cu;
label_208c:
    // 0x208c: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x2090: 0x0  nop
    // NOP
    // 0x2094: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2098: 0x32100  sll         $a0, $v1, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x209c: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x20a0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x20a4: 0x9442543c  lhu         $v0, 0x543C($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 21564)));
    // 0x20a8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x20ac: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x20b0: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x20b4: 0xc0009c5  jal         func_002714
    ctx->pc = 0x20B4u;
    SET_GPR_U32(ctx, 31, 0x20BCu);
    // 0x20b8: 0x403021  addu        $a2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2714u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2714u, 0x20B4u, 0x20BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x20BCu;
label_20bc:
    // 0x20bc: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x20c0: 0x0  nop
    // NOP
    // 0x20c4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x20c8: 0x8000803  j           func_00200C
    ctx->pc = 0x20C8u;
    // 0x20cc: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x200Cu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_200c;
    ctx->pc = 0x20D0u;
label_20d0:
    // 0x20d0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x20d4: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x20d8: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x20dc: 0x3e00008  jr          $ra
    ctx->pc = 0x20DCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x20e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x20DCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x20E4u;
}


// Function: sounds_000020e4
// Address: 0x20e4 - 0x2154
void sounds_000020e4_0x20e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000020e4_0x20e4");
#endif

    switch (ctx->pc) {
        case 0x2110u: goto label_2110;
        case 0x2130u: goto label_2130;
        case 0x2140u: goto label_2140;
        default: break;
    }

    ctx->pc = 0x20e4u;

    // 0x20e4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x20e8: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x20ec: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x20f0: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x20f4: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x20f8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x20fc: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2100: 0x24842f4c  addiu       $a0, $a0, 0x2F4C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12108));
    // 0x2104: 0x8c450000  lw          $a1, 0x0($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2108: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x2108u;
    SET_GPR_U32(ctx, 31, 0x2110u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x2108u, 0x2110u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2110u;
label_2110:
    // 0x2110: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2114: 0x0  nop
    // NOP
    // 0x2118: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x211c: 0x0  nop
    // NOP
    // 0x2120: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x2120u;
    {
        const bool branch_taken_0x2120 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x2120) {
            ctx->pc = 0x2138u;
            goto label_2138;
        }
    }
    ctx->pc = 0x2128u;
    // 0x2128: 0xc0009c9  jal         func_002724
    ctx->pc = 0x2128u;
    SET_GPR_U32(ctx, 31, 0x2130u);
    // 0x212c: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x2724u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2724u, 0x2128u, 0x2130u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2130u;
label_2130:
    // 0x2130: 0x8000850  j           func_002140
    ctx->pc = 0x2130u;
    ctx->pc = 0x2140u;
    goto label_2140;
    ctx->pc = 0x2138u;
label_2138:
    // 0x2138: 0xc0009c9  jal         func_002724
    ctx->pc = 0x2138u;
    SET_GPR_U32(ctx, 31, 0x2140u);
    // 0x213c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2724u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2724u, 0x2138u, 0x2140u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2140u;
label_2140:
    // 0x2140: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x2144: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x2148: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x214c: 0x3e00008  jr          $ra
    ctx->pc = 0x214Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2150: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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


// Function: sounds_00002154
// Address: 0x2154 - 0x220c
void sounds_00002154_0x2154(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002154_0x2154");
#endif

    switch (ctx->pc) {
        case 0x2180u: goto label_2180;
        case 0x2184u: goto label_2184;
        case 0x21e4u: goto label_21e4;
        default: break;
    }

    ctx->pc = 0x2154u;

    // 0x2154: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2158: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x215c: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x2160: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x2164: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x2168: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x216c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2170: 0x24842f74  addiu       $a0, $a0, 0x2F74
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12148));
    // 0x2174: 0x8c450000  lw          $a1, 0x0($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2178: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x2178u;
    SET_GPR_U32(ctx, 31, 0x2180u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x2178u, 0x2180u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2180u;
label_2180:
    // 0x2180: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_2184:
    // 0x2184: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x2188: 0x0  nop
    // NOP
    // 0x218c: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x2190: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2190u;
    {
        const bool branch_taken_0x2190 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2190) {
            ctx->pc = 0x21A0u;
            goto label_21a0;
        }
    }
    ctx->pc = 0x2198u;
    // 0x2198: 0x800087e  j           func_0021F8
    ctx->pc = 0x2198u;
    ctx->pc = 0x21F8u;
    goto label_21f8;
    ctx->pc = 0x21A0u;
label_21a0:
    // 0x21a0: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x21a4: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x21a8: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x21ac: 0x0  nop
    // NOP
    // 0x21b0: 0x831804  sllv        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x21b4: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x21b8: 0x0  nop
    // NOP
    // 0x21bc: 0x641024  and         $v0, $v1, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x21c0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x21C0u;
    {
        const bool branch_taken_0x21c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x21c0) {
            ctx->pc = 0x21D0u;
            goto label_21d0;
        }
    }
    ctx->pc = 0x21C8u;
    // 0x21c8: 0x8000879  j           func_0021E4
    ctx->pc = 0x21C8u;
    ctx->pc = 0x21E4u;
    goto label_21e4;
    ctx->pc = 0x21D0u;
label_21d0:
    // 0x21d0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x21d4: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x21d8: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x21dc: 0xc0009cb  jal         func_00272C
    ctx->pc = 0x21DCu;
    SET_GPR_U32(ctx, 31, 0x21E4u);
    ctx->pc = 0x272Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x272Cu, 0x21DCu, 0x21E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x21E4u;
label_21e4:
    // 0x21e4: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x21e8: 0x0  nop
    // NOP
    // 0x21ec: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x21f0: 0x8000861  j           func_002184
    ctx->pc = 0x21F0u;
    // 0x21f4: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x2184u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2184;
    ctx->pc = 0x21F8u;
label_21f8:
    // 0x21f8: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x21fc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2200: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2204: 0x3e00008  jr          $ra
    ctx->pc = 0x2204u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2208: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2204u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x220Cu;
}


// Function: sounds_0000220c
// Address: 0x220c - 0x2300
void sounds_0000220c_0x220c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000220c_0x220c");
#endif

    switch (ctx->pc) {
        case 0x2240u: goto label_2240;
        case 0x2244u: goto label_2244;
        case 0x22d8u: goto label_22d8;
        default: break;
    }

    ctx->pc = 0x220cu;

    // 0x220c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x2210: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
    // 0x2214: 0xafbe0018  sw          $fp, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 30));
    // 0x2218: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x221c: 0xafc40020  sw          $a0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 4));
    // 0x2220: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2224: 0x8fc30020  lw          $v1, 0x20($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2228: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x222c: 0x24842fa0  addiu       $a0, $a0, 0x2FA0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12192));
    // 0x2230: 0x8c450000  lw          $a1, 0x0($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2234: 0x8c660004  lw          $a2, 0x4($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x2238: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x2238u;
    SET_GPR_U32(ctx, 31, 0x2240u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x2238u, 0x2240u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2240u;
label_2240:
    // 0x2240: 0xafc00010  sw          $zero, 0x10($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
label_2244:
    // 0x2244: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x2248: 0x0  nop
    // NOP
    // 0x224c: 0x28430008  slti        $v1, $v0, 0x8
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x2250: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2250u;
    {
        const bool branch_taken_0x2250 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2250) {
            ctx->pc = 0x2260u;
            goto label_2260;
        }
    }
    ctx->pc = 0x2258u;
    // 0x2258: 0x80008bb  j           func_0022EC
    ctx->pc = 0x2258u;
    ctx->pc = 0x22ECu;
    goto label_22ec;
    ctx->pc = 0x2260u;
label_2260:
    // 0x2260: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2264: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2268: 0x8fc40010  lw          $a0, 0x10($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x226c: 0x0  nop
    // NOP
    // 0x2270: 0x831804  sllv        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x2274: 0x8c440000  lw          $a0, 0x0($v0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2278: 0x0  nop
    // NOP
    // 0x227c: 0x641024  and         $v0, $v1, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x2280: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x2280u;
    {
        const bool branch_taken_0x2280 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2280) {
            ctx->pc = 0x2290u;
            goto label_2290;
        }
    }
    ctx->pc = 0x2288u;
    // 0x2288: 0x80008b6  j           func_0022D8
    ctx->pc = 0x2288u;
    ctx->pc = 0x22D8u;
    goto label_22d8;
    ctx->pc = 0x2290u;
label_2290:
    // 0x2290: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x2294: 0x0  nop
    // NOP
    // 0x2298: 0x401821  addu        $v1, $v0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x229c: 0x31100  sll         $v0, $v1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x22a0: 0x8fc30020  lw          $v1, 0x20($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x22a4: 0x0  nop
    // NOP
    // 0x22a8: 0x8c640004  lw          $a0, 0x4($v1)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x22ac: 0x3c010001  lui         $at, 0x1
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x22b0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x22b4: 0xac24543c  sw          $a0, 0x543C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21564), GPR_U32(ctx, 4));
    // 0x22b8: 0x8fc30020  lw          $v1, 0x20($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x22bc: 0x0  nop
    // NOP
    // 0x22c0: 0x94620004  lhu         $v0, 0x4($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x22c4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x22c8: 0x24846178  addiu       $a0, $a0, 0x6178
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24952));
    // 0x22cc: 0x8fc50010  lw          $a1, 0x10($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x22d0: 0xc0009c5  jal         func_002714
    ctx->pc = 0x22D0u;
    SET_GPR_U32(ctx, 31, 0x22D8u);
    // 0x22d4: 0x403021  addu        $a2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x2714u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2714u, 0x22D0u, 0x22D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22D8u;
label_22d8:
    // 0x22d8: 0x8fc20010  lw          $v0, 0x10($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x22dc: 0x0  nop
    // NOP
    // 0x22e0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x22e4: 0x8000891  j           func_002244
    ctx->pc = 0x22E4u;
    // 0x22e8: 0xafc30010  sw          $v1, 0x10($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 3));
    ctx->pc = 0x2244u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2244;
    ctx->pc = 0x22ECu;
label_22ec:
    // 0x22ec: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x22f0: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x22f4: 0x8fbe0018  lw          $fp, 0x18($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x22f8: 0x3e00008  jr          $ra
    ctx->pc = 0x22F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x22fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x22F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2300u;
}


// Function: sounds_00002300
// Address: 0x2300 - 0x23e0
void sounds_00002300_0x2300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002300_0x2300");
#endif

    switch (ctx->pc) {
        case 0x2324u: goto label_2324;
        default: break;
    }

    ctx->pc = 0x2300u;

    // 0x2300: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x2304: 0xafbe0010  sw          $fp, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 30));
    // 0x2308: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x230c: 0xafc40018  sw          $a0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 4));
    // 0x2310: 0xafc00004  sw          $zero, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x2314: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x2318: 0x244254c0  addiu       $v0, $v0, 0x54C0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21696));
    // 0x231c: 0xafc20000  sw          $v0, 0x0($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x2320: 0xafc00008  sw          $zero, 0x8($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
label_2324:
    // 0x2324: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x2328: 0x0  nop
    // NOP
    // 0x232c: 0x28430018  slti        $v1, $v0, 0x18
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x2330: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2330u;
    {
        const bool branch_taken_0x2330 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2330) {
            ctx->pc = 0x2340u;
            goto label_2340;
        }
    }
    ctx->pc = 0x2338u;
    // 0x2338: 0x80008f0  j           func_0023C0
    ctx->pc = 0x2338u;
    ctx->pc = 0x23C0u;
    goto label_23c0;
    ctx->pc = 0x2340u;
label_2340:
    // 0x2340: 0x8fc20000  lw          $v0, 0x0($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x2344: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2348: 0x0  nop
    // NOP
    // 0x234c: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x2350: 0x0  nop
    // NOP
    // 0x2354: 0x602821  addu        $a1, $v1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x2358: 0x52040  sll         $a0, $a1, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x235c: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x2360: 0x418c0  sll         $v1, $a0, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x2364: 0x8fc40008  lw          $a0, 0x8($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x2368: 0x0  nop
    // NOP
    // 0x236c: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x2370: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x2374: 0x90430008  lbu         $v1, 0x8($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x2378: 0x0  nop
    // NOP
    // 0x237c: 0x30620020  andi        $v0, $v1, 0x20
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32);
    // 0x2380: 0x304300ff  andi        $v1, $v0, 0xFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x2384: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x2384u;
    {
        const bool branch_taken_0x2384 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x2384) {
            ctx->pc = 0x23ACu;
            goto label_23ac;
        }
    }
    ctx->pc = 0x238Cu;
    // 0x238c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x2390: 0x8fc30008  lw          $v1, 0x8($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x2394: 0x0  nop
    // NOP
    // 0x2398: 0x621004  sllv        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
    // 0x239c: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x23a0: 0x0  nop
    // NOP
    // 0x23a4: 0x621025  or          $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x23a8: 0xafc20004  sw          $v0, 0x4($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_23ac:
    // 0x23ac: 0x8fc20008  lw          $v0, 0x8($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x23b0: 0x0  nop
    // NOP
    // 0x23b4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x23b8: 0x80008c9  j           func_002324
    ctx->pc = 0x23B8u;
    // 0x23bc: 0xafc30008  sw          $v1, 0x8($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 3));
    ctx->pc = 0x2324u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2324;
    ctx->pc = 0x23C0u;
label_23c0:
    // 0x23c0: 0x8fc30004  lw          $v1, 0x4($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x23c4: 0x0  nop
    // NOP
    // 0x23c8: 0x80008f4  j           func_0023D0
    ctx->pc = 0x23C8u;
    // 0x23cc: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x23D0u;
    goto label_23d0;
    ctx->pc = 0x23D0u;
label_23d0:
    // 0x23d0: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x23d4: 0x8fbe0010  lw          $fp, 0x10($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x23d8: 0x3e00008  jr          $ra
    ctx->pc = 0x23D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x23dc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x23D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x23E0u;
}


// Function: sounds_000023e0
// Address: 0x23e0 - 0x2510
void sounds_000023e0_0x23e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000023e0_0x23e0");
#endif

    switch (ctx->pc) {
        case 0x2400u: goto label_2400;
        case 0x2414u: goto label_2414;
        case 0x24bcu: goto label_24bc;
        case 0x24fcu: goto label_24fc;
        default: break;
    }

    ctx->pc = 0x23e0u;

    // 0x23e0: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x23e4: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x23e8: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x23ec: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x23f0: 0xafc40038  sw          $a0, 0x38($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    // 0x23f4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x23f8: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x23F8u;
    SET_GPR_U32(ctx, 31, 0x2400u);
    // 0x23fc: 0x24842fd4  addiu       $a0, $a0, 0x2FD4 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12244));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x23F8u, 0x2400u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2400u;
label_2400:
    // 0x2400: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x2404: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x2408: 0xafc20020  sw          $v0, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x240c: 0xafc00028  sw          $zero, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
    // 0x2410: 0xafc00024  sw          $zero, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
label_2414:
    // 0x2414: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x2418: 0x0  nop
    // NOP
    // 0x241c: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x2420: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2420u;
    {
        const bool branch_taken_0x2420 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2420) {
            ctx->pc = 0x2430u;
            goto label_2430;
        }
    }
    ctx->pc = 0x2428u;
    // 0x2428: 0x800093c  j           func_0024F0
    ctx->pc = 0x2428u;
    ctx->pc = 0x24F0u;
    goto label_24f0;
    ctx->pc = 0x2430u;
label_2430:
    // 0x2430: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2434: 0x0  nop
    // NOP
    // 0x2438: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x243c: 0x0  nop
    // NOP
    // 0x2440: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2440u;
    {
        const bool branch_taken_0x2440 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2440) {
            ctx->pc = 0x2450u;
            goto label_2450;
        }
    }
    ctx->pc = 0x2448u;
    // 0x2448: 0x8000933  j           func_0024CC
    ctx->pc = 0x2448u;
    ctx->pc = 0x24CCu;
    goto label_24cc;
    ctx->pc = 0x2450u;
label_2450:
    // 0x2450: 0x8fc30020  lw          $v1, 0x20($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2454: 0x0  nop
    // NOP
    // 0x2458: 0x90620003  lbu         $v0, 0x3($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3)));
    // 0x245c: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2460: 0x0  nop
    // NOP
    // 0x2464: 0x90830001  lbu         $v1, 0x1($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x2468: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x246c: 0x0  nop
    // NOP
    // 0x2470: 0x90850002  lbu         $a1, 0x2($a0)
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x2474: 0x0  nop
    // NOP
    // 0x2478: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x247c: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2480: 0x0  nop
    // NOP
    // 0x2484: 0x8c850004  lw          $a1, 0x4($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x2488: 0x0  nop
    // NOP
    // 0x248c: 0xafa50014  sw          $a1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x2490: 0x8fc40020  lw          $a0, 0x20($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2494: 0x0  nop
    // NOP
    // 0x2498: 0x8c850008  lw          $a1, 0x8($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x249c: 0x0  nop
    // NOP
    // 0x24a0: 0xafa50018  sw          $a1, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 5));
    // 0x24a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x24a8: 0x2484302c  addiu       $a0, $a0, 0x302C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12332));
    // 0x24ac: 0x8fc50028  lw          $a1, 0x28($fp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x24b0: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x24b4: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x24B4u;
    SET_GPR_U32(ctx, 31, 0x24BCu);
    // 0x24b8: 0x603821  addu        $a3, $v1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x24B4u, 0x24BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24BCu;
label_24bc:
    // 0x24bc: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x24c0: 0x0  nop
    // NOP
    // 0x24c4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x24c8: 0xafc30028  sw          $v1, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 3));
label_24cc:
    // 0x24cc: 0x8fc20024  lw          $v0, 0x24($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x24d0: 0x0  nop
    // NOP
    // 0x24d4: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x24d8: 0xafc30024  sw          $v1, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 3));
    // 0x24dc: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x24e0: 0x0  nop
    // NOP
    // 0x24e4: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x24e8: 0x8000905  j           func_002414
    ctx->pc = 0x24E8u;
    // 0x24ec: 0xafc30020  sw          $v1, 0x20($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 3));
    ctx->pc = 0x2414u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2414;
    ctx->pc = 0x24F0u;
label_24f0:
    // 0x24f0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x24f4: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x24F4u;
    SET_GPR_U32(ctx, 31, 0x24FCu);
    // 0x24f8: 0x24843068  addiu       $a0, $a0, 0x3068 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12392));
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x24F4u, 0x24FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x24FCu;
label_24fc:
    // 0x24fc: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x2500: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x2504: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x2508: 0x3e00008  jr          $ra
    ctx->pc = 0x2508u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x250c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2508u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2510u;
}


// Function: sounds_00002510
// Address: 0x2510 - 0x26f4
void sounds_00002510_0x2510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002510_0x2510");
#endif

    switch (ctx->pc) {
        case 0x2538u: goto label_2538;
        case 0x25acu: goto label_25ac;
        case 0x2680u: goto label_2680;
        case 0x2698u: goto label_2698;
        case 0x26a8u: goto label_26a8;
        default: break;
    }

    ctx->pc = 0x2510u;

    // 0x2510: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
    // 0x2514: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
    // 0x2518: 0xafbe0030  sw          $fp, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 30));
    // 0x251c: 0x3a0f021  addu        $fp, $sp, $zero
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 0)));
    // 0x2520: 0x80009b3  j           func_0026CC
    ctx->pc = 0x2520u;
    // 0x2524: 0xafc40038  sw          $a0, 0x38($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 4));
    ctx->pc = 0x26CCu;
    goto label_26cc;
    ctx->pc = 0x2528u;
    // 0x2528: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x252c: 0x24425620  addiu       $v0, $v0, 0x5620
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22048));
    // 0x2530: 0xafc20018  sw          $v0, 0x18($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x2534: 0xafc00028  sw          $zero, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 0));
label_2538:
    // 0x2538: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x253c: 0x0  nop
    // NOP
    // 0x2540: 0x28430060  slti        $v1, $v0, 0x60
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x2544: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2544u;
    {
        const bool branch_taken_0x2544 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2544) {
            ctx->pc = 0x2554u;
            goto label_2554;
        }
    }
    ctx->pc = 0x254Cu;
    // 0x254c: 0x80009b3  j           func_0026CC
    ctx->pc = 0x254Cu;
    ctx->pc = 0x26CCu;
    goto label_26cc;
    ctx->pc = 0x2554u;
label_2554:
    // 0x2554: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2558: 0x0  nop
    // NOP
    // 0x255c: 0x90430000  lbu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x2560: 0x0  nop
    // NOP
    // 0x2564: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2564u;
    {
        const bool branch_taken_0x2564 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2564) {
            ctx->pc = 0x2574u;
            goto label_2574;
        }
    }
    ctx->pc = 0x256Cu;
    // 0x256c: 0x80009aa  j           func_0026A8
    ctx->pc = 0x256Cu;
    ctx->pc = 0x26A8u;
    goto label_26a8;
    ctx->pc = 0x2574u;
label_2574:
    // 0x2574: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2578: 0x0  nop
    // NOP
    // 0x257c: 0x90430003  lbu         $v1, 0x3($v0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x2580: 0x0  nop
    // NOP
    // 0x2584: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x2584u;
    {
        const bool branch_taken_0x2584 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x2584) {
            ctx->pc = 0x2594u;
            goto label_2594;
        }
    }
    ctx->pc = 0x258Cu;
    // 0x258c: 0x80009aa  j           func_0026A8
    ctx->pc = 0x258Cu;
    ctx->pc = 0x26A8u;
    goto label_26a8;
    ctx->pc = 0x2594u;
label_2594:
    // 0x2594: 0x8fc20038  lw          $v0, 0x38($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x2598: 0x0  nop
    // NOP
    // 0x259c: 0x24430002  addiu       $v1, $v0, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x25a0: 0xafc3001c  sw          $v1, 0x1C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    // 0x25a4: 0xafc00020  sw          $zero, 0x20($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x25a8: 0xafc0002c  sw          $zero, 0x2C($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
label_25ac:
    // 0x25ac: 0x8fc20038  lw          $v0, 0x38($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x25b0: 0x0  nop
    // NOP
    // 0x25b4: 0x94430000  lhu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x25b8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x25bc: 0x0  nop
    // NOP
    // 0x25c0: 0x43182a  slt         $v1, $v0, $v1
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x25c4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x25C4u;
    {
        const bool branch_taken_0x25c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x25c4) {
            ctx->pc = 0x25D4u;
            goto label_25d4;
        }
    }
    ctx->pc = 0x25CCu;
    // 0x25cc: 0x8000989  j           func_002624
    ctx->pc = 0x25CCu;
    ctx->pc = 0x2624u;
    goto label_2624;
    ctx->pc = 0x25D4u;
label_25d4:
    // 0x25d4: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x25d8: 0x8fc3001c  lw          $v1, 0x1C($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x25dc: 0x0  nop
    // NOP
    // 0x25e0: 0x94640000  lhu         $a0, 0x0($v1)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x25e4: 0x8c420004  lw          $v0, 0x4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x25e8: 0x0  nop
    // NOP
    // 0x25ec: 0x14440004  bne         $v0, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x25ECu;
    {
        const bool branch_taken_0x25ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x25ec) {
            ctx->pc = 0x2600u;
            goto label_2600;
        }
    }
    ctx->pc = 0x25F4u;
    // 0x25f4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x25f8: 0x8000989  j           func_002624
    ctx->pc = 0x25F8u;
    // 0x25fc: 0xafc20020  sw          $v0, 0x20($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x2624u;
    goto label_2624;
    ctx->pc = 0x2600u;
label_2600:
    // 0x2600: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x2604: 0x0  nop
    // NOP
    // 0x2608: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x260c: 0xafc30028  sw          $v1, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 3));
    // 0x2610: 0x8fc2001c  lw          $v0, 0x1C($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x2614: 0x0  nop
    // NOP
    // 0x2618: 0x24430002  addiu       $v1, $v0, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x261c: 0x800096b  j           func_0025AC
    ctx->pc = 0x261Cu;
    // 0x2620: 0xafc3001c  sw          $v1, 0x1C($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 3));
    ctx->pc = 0x25ACu;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_25ac;
    ctx->pc = 0x2624u;
label_2624:
    // 0x2624: 0x8fc20020  lw          $v0, 0x20($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x2628: 0x0  nop
    // NOP
    // 0x262c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x262Cu;
    {
        const bool branch_taken_0x262c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x262c) {
            ctx->pc = 0x26A8u;
            goto label_26a8;
        }
    }
    ctx->pc = 0x2634u;
    // 0x2634: 0x8fc30018  lw          $v1, 0x18($fp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2638: 0x0  nop
    // NOP
    // 0x263c: 0x90620001  lbu         $v0, 0x1($v1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 1)));
    // 0x2640: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2644: 0x0  nop
    // NOP
    // 0x2648: 0x90830002  lbu         $v1, 0x2($a0)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x264c: 0x8fc70018  lw          $a3, 0x18($fp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2650: 0x8fc40018  lw          $a0, 0x18($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2654: 0x0  nop
    // NOP
    // 0x2658: 0x8c850008  lw          $a1, 0x8($a0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x265c: 0x0  nop
    // NOP
    // 0x2660: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x2664: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2668: 0x248430c0  addiu       $a0, $a0, 0x30C0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12480));
    // 0x266c: 0x402821  addu        $a1, $v0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    // 0x2670: 0x603021  addu        $a2, $v1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
    // 0x2674: 0x8ce70004  lw          $a3, 0x4($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x2678: 0xc0009eb  jal         func_0027AC
    ctx->pc = 0x2678u;
    SET_GPR_U32(ctx, 31, 0x2680u);
    ctx->pc = 0x27ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x27ACu, 0x2678u, 0x2680u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2680u;
label_2680:
    // 0x2680: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x2684: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x2688: 0x24846160  addiu       $a0, $a0, 0x6160
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24928));
    // 0x268c: 0x8c450008  lw          $a1, 0x8($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x2690: 0xc0009e2  jal         func_002788
    ctx->pc = 0x2690u;
    SET_GPR_U32(ctx, 31, 0x2698u);
    ctx->pc = 0x2788u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2788u, 0x2690u, 0x2698u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2698u;
label_2698:
    // 0x2698: 0xafc20024  sw          $v0, 0x24($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x269c: 0x8fc40024  lw          $a0, 0x24($fp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x26a0: 0xc000175  jal         func_0005D4
    ctx->pc = 0x26A0u;
    SET_GPR_U32(ctx, 31, 0x26A8u);
    ctx->pc = 0x5D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5D4u, 0x26A0u, 0x26A8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26A8u;
label_26a8:
    // 0x26a8: 0x8fc20028  lw          $v0, 0x28($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x26ac: 0x0  nop
    // NOP
    // 0x26b0: 0x24430001  addiu       $v1, $v0, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x26b4: 0xafc30028  sw          $v1, 0x28($fp)
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 3));
    // 0x26b8: 0x8fc20018  lw          $v0, 0x18($fp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x26bc: 0x0  nop
    // NOP
    // 0x26c0: 0x2443000c  addiu       $v1, $v0, 0xC
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x26c4: 0x800094e  j           func_002538
    ctx->pc = 0x26C4u;
    // 0x26c8: 0xafc30018  sw          $v1, 0x18($fp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 3));
    ctx->pc = 0x2538u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_2538;
    ctx->pc = 0x26CCu;
label_26cc:
    // 0x26cc: 0x3c0e821  addu        $sp, $fp, $zero
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 0)));
    // 0x26d0: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x26d4: 0x8fbe0030  lw          $fp, 0x30($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x26d8: 0x3e00008  jr          $ra
    ctx->pc = 0x26D8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x26dc: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x26D8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x26E0u;
    // 0x26e0: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x26E0 raw=0x41E00000");
    // 0x26e4: 0x0  nop
    // NOP
    // 0x26e8: 0x104  .word       0x00000104                   # sllv        $zero, $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
    // 0x26ec: 0x68646f6d  ldl         $a0, 0x6F6D($v1)
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0x26EC raw=0x68646F6D");
    // 0x26f0: 0x6e7973  tltu        $v1, $t6, 485
    ctx->pc = 0x26f0u;
    if (GPR_U64(ctx, 3) < GPR_U64(ctx, 14)) { runtime->handleTrap(rdram, ctx); }
}


// Function: sounds_000026f4
// Address: 0x26f4 - 0x26fc
void sounds_000026f4_0x26f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000026f4_0x26f4");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 4u);
}


// Function: sounds_000026fc
// Address: 0x26fc - 0x2704
void sounds_000026fc_0x26fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000026fc_0x26fc");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 5u);
}


// Function: sounds_00002704
// Address: 0x2704 - 0x270c
void sounds_00002704_0x2704(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002704_0x2704");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 6u);
}


// Function: sounds_0000270c
// Address: 0x270c - 0x2714
void sounds_0000270c_0x270c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000270c_0x270c");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 9u);
}


// Function: sounds_00002714
// Address: 0x2714 - 0x271c
void sounds_00002714_0x2714(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002714_0x2714");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 10u);
}


// Function: sounds_0000271c
// Address: 0x271c - 0x2724
void sounds_0000271c_0x271c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000271c_0x271c");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 15u);
}


// Function: sounds_00002724
// Address: 0x2724 - 0x272c
void sounds_00002724_0x2724(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002724_0x2724");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 18u);
}


// Function: sounds_0000272c
// Address: 0x272c - 0x2734
void sounds_0000272c_0x272c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000272c_0x272c");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 20u);
}


// Function: sounds_00002734
// Address: 0x2734 - 0x2758
void sounds_00002734_0x2734(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002734_0x2734");
#endif

    runtime->iopImport(rdram, ctx, "modhsyn", 29u);
}


// Function: sounds_00002758
// Address: 0x2758 - 0x2760
void sounds_00002758_0x2758(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002758_0x2758");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 4u);
}


// Function: sounds_00002760
// Address: 0x2760 - 0x2768
void sounds_00002760_0x2760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002760_0x2760");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 5u);
}


// Function: sounds_00002768
// Address: 0x2768 - 0x2770
void sounds_00002768_0x2768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002768_0x2768");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 6u);
}


// Function: sounds_00002770
// Address: 0x2770 - 0x2778
void sounds_00002770_0x2770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002770_0x2770");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 8u);
}


// Function: sounds_00002778
// Address: 0x2778 - 0x2780
void sounds_00002778_0x2778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002778_0x2778");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 10u);
}


// Function: sounds_00002780
// Address: 0x2780 - 0x2788
void sounds_00002780_0x2780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002780_0x2780");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 11u);
}


// Function: sounds_00002788
// Address: 0x2788 - 0x27ac
void sounds_00002788_0x2788(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002788_0x2788");
#endif

    runtime->iopImport(rdram, ctx, "modsesq2", 12u);
}


// Function: sounds_000027ac
// Address: 0x27ac - 0x27d0
void sounds_000027ac_0x27ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000027ac_0x27ac");
#endif

    runtime->iopImport(rdram, ctx, "sysmem", 14u);
}


// Function: sounds_000027d0
// Address: 0x27d0 - 0x27d8
void sounds_000027d0_0x27d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000027d0_0x27d0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 14u);
}


// Function: sounds_000027d8
// Address: 0x27d8 - 0x27e0
void sounds_000027d8_0x27d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000027d8_0x27d8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 17u);
}


// Function: sounds_000027e0
// Address: 0x27e0 - 0x27e8
void sounds_000027e0_0x27e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000027e0_0x27e0");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 19u);
}


// Function: sounds_000027e8
// Address: 0x27e8 - 0x280c
void sounds_000027e8_0x27e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000027e8_0x27e8");
#endif

    runtime->iopImport(rdram, ctx, "sifcmd", 22u);
}


// Function: sounds_0000280c
// Address: 0x280c - 0x2814
void sounds_0000280c_0x280c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000280c_0x280c");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 5u);
}


// Function: sounds_00002814
// Address: 0x2814 - 0x2838
void sounds_00002814_0x2814(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002814_0x2814");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 29u);
}


// Function: sounds_00002838
// Address: 0x2838 - 0x285c
void sounds_00002838_0x2838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002838_0x2838");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 14u);
}


// Function: sounds_0000285c
// Address: 0x285c - 0x2864
void sounds_0000285c_0x285c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000285c_0x285c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: sounds_00002864
// Address: 0x2864 - 0x286c
void sounds_00002864_0x2864(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002864_0x2864");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: sounds_0000286c
// Address: 0x286c - 0x2874
void sounds_0000286c_0x286c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000286c_0x286c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 20u);
}


// Function: sounds_00002874
// Address: 0x2874 - 0x287c
void sounds_00002874_0x2874(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002874_0x2874");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 24u);
}


// Function: sounds_0000287c
// Address: 0x287c - 0x2884
void sounds_0000287c_0x287c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_0000287c_0x287c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 26u);
}


// Function: sounds_00002884
// Address: 0x2884 - 0x28a8
void sounds_00002884_0x2884(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_00002884_0x2884");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 39u);
}


// Function: sounds_000028a8
// Address: 0x28a8 - 0x28b0
void sounds_000028a8_0x28a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000028a8_0x28a8");
#endif

    runtime->iopImport(rdram, ctx, "timrman", 4u);
}


// Function: sounds_000028b0
// Address: 0x28b0 - 0x28b8
void sounds_000028b0_0x28b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000028b0_0x28b0");
#endif

    runtime->iopImport(rdram, ctx, "timrman", 6u);
}


// Function: sounds_000028b8
// Address: 0x28b8 - 0x28c0
void sounds_000028b8_0x28b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000028b8_0x28b8");
#endif

    runtime->iopImport(rdram, ctx, "timrman", 20u);
}


// Function: sounds_000028c0
// Address: 0x28c0 - 0x28c8
void sounds_000028c0_0x28c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000028c0_0x28c0");
#endif

    runtime->iopImport(rdram, ctx, "timrman", 22u);
}


// Function: sounds_000028c8
// Address: 0x28c8 - 0x28d0
void sounds_000028c8_0x28c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sounds_000028c8_0x28c8");
#endif

    runtime->iopImport(rdram, ctx, "timrman", 23u);
}


