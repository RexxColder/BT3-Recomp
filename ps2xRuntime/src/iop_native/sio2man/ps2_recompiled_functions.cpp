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

// Function: sio2man_00000000
// Address: 0x0 - 0x14
void sio2man_00000000_0x0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000000_0x0");
#endif

    ctx->pc = 0x0u;

    // 0x0: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x4: 0x34428268  ori         $v0, $v0, 0x8268
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33384);
    // 0x8: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0xbf808268
    // 0xc: 0x3e00008  jr          $ra
    ctx->pc = 0xCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x14u;
}


// Function: sio2man_00000014
// Address: 0x14 - 0x28
void sio2man_00000014_0x14(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000014_0x14");
#endif

    ctx->pc = 0x14u;

    // 0x14: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x18: 0x34428268  ori         $v0, $v0, 0x8268
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33384);
    // 0x1c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1cu;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf808268
    // 0x20: 0x3e00008  jr          $ra
    ctx->pc = 0x20u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x20u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x28u;
}


// Function: sio2man_00000028
// Address: 0x28 - 0x3c
void sio2man_00000028_0x28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000028_0x28");
#endif

    ctx->pc = 0x28u;

    // 0x28: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x2c: 0x3442826c  ori         $v0, $v0, 0x826C
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33388);
    // 0x30: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x30u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf80826c
    // 0x34: 0x3e00008  jr          $ra
    ctx->pc = 0x34u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x34u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3Cu;
}


// Function: sio2man_0000003c
// Address: 0x3c - 0x54
void sio2man_0000003c_0x3c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000003c_0x3c");
#endif

    ctx->pc = 0x3cu;

    // 0x3c: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x40: 0x3c01bf81  lui         $at, 0xBF81
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49025 << 16));
    // 0x44: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x48: 0xac258240  sw          $a1, -0x7DC0($at)
    ctx->pc = 0x48u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294935104), GPR_U32(ctx, 5)); // MMIO: 0xbf808240
    // 0x4c: 0x3e00008  jr          $ra
    ctx->pc = 0x4Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x54u;
}


// Function: sio2man_00000054
// Address: 0x54 - 0x6c
void sio2man_00000054_0x54(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000054_0x54");
#endif

    ctx->pc = 0x54u;

    // 0x54: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x58: 0x3c02bf81  lui         $v0, 0xBF81
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49025 << 16));
    // 0x5c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x60: 0x8c428240  lw          $v0, -0x7DC0($v0)
    ctx->pc = 0x60u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4294935104))); // MMIO: 0xbf808240
    // 0x64: 0x3e00008  jr          $ra
    ctx->pc = 0x64u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x64u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x6Cu;
}


// Function: sio2man_0000006c
// Address: 0x6c - 0x84
void sio2man_0000006c_0x6c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000006c_0x6c");
#endif

    ctx->pc = 0x6cu;

    // 0x6c: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x70: 0x3c01bf81  lui         $at, 0xBF81
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49025 << 16));
    // 0x74: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0x78: 0xac258244  sw          $a1, -0x7DBC($at)
    ctx->pc = 0x78u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294935108), GPR_U32(ctx, 5)); // MMIO: 0xbf808244
    // 0x7c: 0x3e00008  jr          $ra
    ctx->pc = 0x7Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x7Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x84u;
}


// Function: sio2man_00000084
// Address: 0x84 - 0x9c
void sio2man_00000084_0x84(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000084_0x84");
#endif

    ctx->pc = 0x84u;

    // 0x84: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x88: 0x3c02bf81  lui         $v0, 0xBF81
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49025 << 16));
    // 0x8c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x90: 0x8c428244  lw          $v0, -0x7DBC($v0)
    ctx->pc = 0x90u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4294935108))); // MMIO: 0xbf808244
    // 0x94: 0x3e00008  jr          $ra
    ctx->pc = 0x94u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
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


// Function: sio2man_0000009c
// Address: 0x9c - 0xb0
void sio2man_0000009c_0x9c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000009c_0x9c");
#endif

    ctx->pc = 0x9cu;

    // 0x9c: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0xa0: 0x34428270  ori         $v0, $v0, 0x8270
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33392);
    // 0xa4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0xa4u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf808270
    // 0xa8: 0x3e00008  jr          $ra
    ctx->pc = 0xA8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB0u;
}


// Function: sio2man_000000b0
// Address: 0xb0 - 0xc8
void sio2man_000000b0_0xb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000000b0_0xb0");
#endif

    ctx->pc = 0xb0u;

    // 0xb0: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xb4: 0x3c01bf81  lui         $at, 0xBF81
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49025 << 16));
    // 0xb8: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
    // 0xbc: 0xac258200  sw          $a1, -0x7E00($at)
    ctx->pc = 0xbcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294935040), GPR_U32(ctx, 5)); // MMIO: 0xbf808200
    // 0xc0: 0x3e00008  jr          $ra
    ctx->pc = 0xC0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC8u;
}


// Function: sio2man_000000c8
// Address: 0xc8 - 0xe0
void sio2man_000000c8_0xc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000000c8_0xc8");
#endif

    ctx->pc = 0xc8u;

    // 0xc8: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0xcc: 0x3c02bf81  lui         $v0, 0xBF81
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49025 << 16));
    // 0xd0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0xd4: 0x8c428200  lw          $v0, -0x7E00($v0)
    ctx->pc = 0xd4u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4294935040))); // MMIO: 0xbf808200
    // 0xd8: 0x3e00008  jr          $ra
    ctx->pc = 0xD8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xE0u;
}


// Function: sio2man_000000e0
// Address: 0xe0 - 0xf4
void sio2man_000000e0_0xe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000000e0_0xe0");
#endif

    ctx->pc = 0xe0u;

    // 0xe0: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0xe4: 0x34428274  ori         $v0, $v0, 0x8274
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33396);
    // 0xe8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0xe8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf808274
    // 0xec: 0x3e00008  jr          $ra
    ctx->pc = 0xECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xF4u;
}


// Function: sio2man_000000f4
// Address: 0xf4 - 0x108
void sio2man_000000f4_0xf4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000000f4_0xf4");
#endif

    ctx->pc = 0xf4u;

    // 0xf4: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0xf8: 0x34428278  ori         $v0, $v0, 0x8278
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33400);
    // 0xfc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0xfcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0xbf808278
    // 0x100: 0x3e00008  jr          $ra
    ctx->pc = 0x100u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x100u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x108u;
}


// Function: sio2man_00000108
// Address: 0x108 - 0x11c
void sio2man_00000108_0x108(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000108_0x108");
#endif

    ctx->pc = 0x108u;

    // 0x108: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x10c: 0x34428278  ori         $v0, $v0, 0x8278
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33400);
    // 0x110: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x110u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf808278
    // 0x114: 0x3e00008  jr          $ra
    ctx->pc = 0x114u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x114u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x11Cu;
}


// Function: sio2man_0000011c
// Address: 0x11c - 0x130
void sio2man_0000011c_0x11c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000011c_0x11c");
#endif

    ctx->pc = 0x11cu;

    // 0x11c: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x120: 0x3442827c  ori         $v0, $v0, 0x827C
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33404);
    // 0x124: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x124u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0xbf80827c
    // 0x128: 0x3e00008  jr          $ra
    ctx->pc = 0x128u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x128u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x130u;
}


// Function: sio2man_00000130
// Address: 0x130 - 0x144
void sio2man_00000130_0x130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000130_0x130");
#endif

    ctx->pc = 0x130u;

    // 0x130: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x134: 0x3442827c  ori         $v0, $v0, 0x827C
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33404);
    // 0x138: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x138u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf80827c
    // 0x13c: 0x3e00008  jr          $ra
    ctx->pc = 0x13Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x13Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x144u;
}


// Function: sio2man_00000144
// Address: 0x144 - 0x154
void sio2man_00000144_0x144(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000144_0x144");
#endif

    ctx->pc = 0x144u;

    // 0x144: 0x3c01bf81  lui         $at, 0xBF81
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49025 << 16));
    // 0x148: 0xa0248260  sb          $a0, -0x7DA0($at)
    ctx->pc = 0x148u;
    runtime->Store8(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294935136), (uint8_t)GPR_U32(ctx, 4)); // MMIO: 0xbf808260
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


// Function: sio2man_00000154
// Address: 0x154 - 0x164
void sio2man_00000154_0x154(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000154_0x154");
#endif

    ctx->pc = 0x154u;

    // 0x154: 0x3c02bf81  lui         $v0, 0xBF81
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49025 << 16));
    // 0x158: 0x90428264  lbu         $v0, -0x7D9C($v0)
    ctx->pc = 0x158u;
    SET_GPR_U32(ctx, 2, (uint8_t)runtime->Load8(rdram, ctx, ADD32(GPR_U32(ctx, 2), 4294935140))); // MMIO: 0xbf808264
    // 0x15c: 0x3e00008  jr          $ra
    ctx->pc = 0x15Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x15Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x164u;
}


// Function: sio2man_00000164
// Address: 0x164 - 0x178
void sio2man_00000164_0x164(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000164_0x164");
#endif

    ctx->pc = 0x164u;

    // 0x164: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x168: 0x34428280  ori         $v0, $v0, 0x8280
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33408);
    // 0x16c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x16cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0xbf808280
    // 0x170: 0x3e00008  jr          $ra
    ctx->pc = 0x170u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x170u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x178u;
}


// Function: sio2man_00000178
// Address: 0x178 - 0x18c
void sio2man_00000178_0x178(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000178_0x178");
#endif

    ctx->pc = 0x178u;

    // 0x178: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x17c: 0x34428280  ori         $v0, $v0, 0x8280
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)33408);
    // 0x180: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x180u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0xbf808280
    // 0x184: 0x3e00008  jr          $ra
    ctx->pc = 0x184u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x184u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x18Cu;
}


// Function: sio2man_0000018c
// Address: 0x18c - 0x1ac
void sio2man_0000018c_0x18c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000018c_0x18c");
#endif

    switch (ctx->pc) {
        case 0x19cu: goto label_19c;
        default: break;
    }

    ctx->pc = 0x18cu;

    // 0x18c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x190: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x194: 0xc000000  jal         func_000000
    ctx->pc = 0x194u;
    SET_GPR_U32(ctx, 31, 0x19Cu);
    // 0x198: 0x240403bc  addiu       $a0, $zero, 0x3BC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 956));
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x194u, 0x19Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x19Cu;
label_19c:
    // 0x19c: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a0: 0x0  nop
    // NOP
    // 0x1a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1a8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1A4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1ACu;
}


// Function: sio2man_000001ac
// Address: 0x1ac - 0x1d4
void sio2man_000001ac_0x1ac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000001ac_0x1ac");
#endif

    switch (ctx->pc) {
        case 0x1bcu: goto label_1bc;
        case 0x1c4u: goto label_1c4;
        default: break;
    }

    ctx->pc = 0x1acu;

    // 0x1ac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x1b0: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x1b4: 0xc000005  jal         func_000014
    ctx->pc = 0x1B4u;
    SET_GPR_U32(ctx, 31, 0x1BCu);
    ctx->pc = 0x14u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x14u, 0x1B4u, 0x1BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1BCu;
label_1bc:
    // 0x1bc: 0xc000000  jal         func_000000
    ctx->pc = 0x1BCu;
    SET_GPR_U32(ctx, 31, 0x1C4u);
    // 0x1c0: 0x3444000c  ori         $a0, $v0, 0xC (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x1BCu, 0x1C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1C4u;
label_1c4:
    // 0x1c4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c8: 0x0  nop
    // NOP
    // 0x1cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1d0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1D4u;
}


// Function: sio2man_000001d4
// Address: 0x1d4 - 0x2fc
void sio2man_000001d4_0x1d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000001d4_0x1d4");
#endif

    switch (ctx->pc) {
        case 0x1f4u: goto label_1f4;
        case 0x200u: goto label_200;
        case 0x214u: goto label_214;
        case 0x22cu: goto label_22c;
        case 0x23cu: goto label_23c;
        case 0x258u: goto label_258;
        case 0x270u: goto label_270;
        case 0x2acu: goto label_2ac;
        case 0x2b4u: goto label_2b4;
        case 0x2dcu: goto label_2dc;
        case 0x2e4u: goto label_2e4;
        default: break;
    }

    ctx->pc = 0x1d4u;

    // 0x1d4: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x1d8: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
    // 0x1dc: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x1e0: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1e4: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x1e8: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1ec: 0x2408821  addu        $s1, $s2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x1f0: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_1f4:
    // 0x1f4: 0x8e250004  lw          $a1, 0x4($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1f8: 0xc00000f  jal         func_00003C
    ctx->pc = 0x1F8u;
    SET_GPR_U32(ctx, 31, 0x200u);
    // 0x1fc: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x3Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x3Cu, 0x1F8u, 0x200u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x200u;
label_200:
    // 0x200: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    // 0x204: 0x8e250014  lw          $a1, 0x14($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x208: 0x26310004  addiu       $s1, $s1, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x20c: 0xc00001b  jal         func_00006C
    ctx->pc = 0x20Cu;
    SET_GPR_U32(ctx, 31, 0x214u);
    // 0x210: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0x6Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x6Cu, 0x20Cu, 0x214u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x214u;
label_214:
    // 0x214: 0x2a020004  slti        $v0, $s0, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x218: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x218u;
    {
        const bool branch_taken_0x218 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x218) {
            ctx->pc = 0x1F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f4;
        }
    }
    ctx->pc = 0x220u;
    // 0x220: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x224: 0x2408821  addu        $s1, $s2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    // 0x228: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_22c:
    // 0x22c: 0x8e250028  lw          $a1, 0x28($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x230: 0x26310004  addiu       $s1, $s1, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x234: 0xc00002c  jal         func_0000B0
    ctx->pc = 0x234u;
    SET_GPR_U32(ctx, 31, 0x23Cu);
    // 0x238: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0xB0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xB0u, 0x234u, 0x23Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x23Cu;
label_23c:
    // 0x23c: 0x2a020010  slti        $v0, $s0, 0x10
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x240: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x240u;
    {
        const bool branch_taken_0x240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x244: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        if (branch_taken_0x240) {
            ctx->pc = 0x22Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_22c;
        }
    }
    ctx->pc = 0x248u;
    // 0x248: 0x8e42006c  lw          $v0, 0x6C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 108)));
    // 0x24c: 0x0  nop
    // NOP
    // 0x250: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x250u;
    {
        const bool branch_taken_0x250 = (GPR_S32(ctx, 2) <= 0);
        // 0x254: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x250) {
            ctx->pc = 0x284u;
            goto label_284;
        }
    }
    ctx->pc = 0x258u;
label_258:
    // 0x258: 0x8e420074  lw          $v0, 0x74($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 116)));
    // 0x25c: 0x0  nop
    // NOP
    // 0x260: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x264: 0x90440000  lbu         $a0, 0x0($v0)
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x268: 0xc000051  jal         func_000144
    ctx->pc = 0x268u;
    SET_GPR_U32(ctx, 31, 0x270u);
    // 0x26c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    ctx->pc = 0x144u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x144u, 0x268u, 0x270u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x270u;
label_270:
    // 0x270: 0x8e42006c  lw          $v0, 0x6C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 108)));
    // 0x274: 0x0  nop
    // NOP
    // 0x278: 0x202102a  slt         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x27c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x27Cu;
    {
        const bool branch_taken_0x27c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
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
    // 0x284: 0x8e42007c  lw          $v0, 0x7C($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 124)));
    // 0x288: 0x0  nop
    // NOP
    // 0x28c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x28Cu;
    {
        const bool branch_taken_0x28c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x290: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x28c) {
            ctx->pc = 0x2B4u;
            goto label_2b4;
        }
    }
    ctx->pc = 0x294u;
    // 0x294: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x298: 0x8e45007c  lw          $a1, 0x7C($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 124)));
    // 0x29c: 0x8e460080  lw          $a2, 0x80($s2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 128)));
    // 0x2a0: 0x8e470084  lw          $a3, 0x84($s2)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 132)));
    // 0x2a4: 0xc00038a  jal         func_000E28
    ctx->pc = 0x2A4u;
    SET_GPR_U32(ctx, 31, 0x2ACu);
    // 0x2a8: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    ctx->pc = 0xE28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE28u, 0x2A4u, 0x2ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2ACu;
label_2ac:
    // 0x2ac: 0xc00038c  jal         func_000E30
    ctx->pc = 0x2ACu;
    SET_GPR_U32(ctx, 31, 0x2B4u);
    // 0x2b0: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    ctx->pc = 0xE30u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE30u, 0x2ACu, 0x2B4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B4u;
label_2b4:
    // 0x2b4: 0x8e420088  lw          $v0, 0x88($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 136)));
    // 0x2b8: 0x0  nop
    // NOP
    // 0x2bc: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x2BCu;
    {
        const bool branch_taken_0x2bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2bc) {
            ctx->pc = 0x2E4u;
            goto label_2e4;
        }
    }
    ctx->pc = 0x2C4u;
    // 0x2c4: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x2c8: 0x8e450088  lw          $a1, 0x88($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 136)));
    // 0x2cc: 0x8e46008c  lw          $a2, 0x8C($s2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 140)));
    // 0x2d0: 0x8e470090  lw          $a3, 0x90($s2)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 144)));
    // 0x2d4: 0xc00038a  jal         func_000E28
    ctx->pc = 0x2D4u;
    SET_GPR_U32(ctx, 31, 0x2DCu);
    // 0x2d8: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    ctx->pc = 0xE28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE28u, 0x2D4u, 0x2DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2DCu;
label_2dc:
    // 0x2dc: 0xc00038c  jal         func_000E30
    ctx->pc = 0x2DCu;
    SET_GPR_U32(ctx, 31, 0x2E4u);
    // 0x2e0: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    ctx->pc = 0xE30u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE30u, 0x2DCu, 0x2E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2E4u;
label_2e4:
    // 0x2e4: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x2e8: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x2ec: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x2f0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x2f4: 0x3e00008  jr          $ra
    ctx->pc = 0x2F4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2f8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2F4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2FCu;
}


// Function: sio2man_000002fc
// Address: 0x2fc - 0x324
void sio2man_000002fc_0x2fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000002fc_0x2fc");
#endif

    switch (ctx->pc) {
        case 0x30cu: goto label_30c;
        case 0x314u: goto label_314;
        default: break;
    }

    ctx->pc = 0x2fcu;

    // 0x2fc: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x300: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x304: 0xc000005  jal         func_000014
    ctx->pc = 0x304u;
    SET_GPR_U32(ctx, 31, 0x30Cu);
    ctx->pc = 0x14u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x14u, 0x304u, 0x30Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30Cu;
label_30c:
    // 0x30c: 0xc000000  jal         func_000000
    ctx->pc = 0x30Cu;
    SET_GPR_U32(ctx, 31, 0x314u);
    // 0x310: 0x34440001  ori         $a0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    ctx->pc = 0x0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x0u, 0x30Cu, 0x314u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x314u;
label_314:
    // 0x314: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x318: 0x0  nop
    // NOP
    // 0x31c: 0x3e00008  jr          $ra
    ctx->pc = 0x31Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x320: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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
}


// Function: sio2man_00000324
// Address: 0x324 - 0x39c
void sio2man_00000324_0x324(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000324_0x324");
#endif

    switch (ctx->pc) {
        case 0x33cu: goto label_33c;
        case 0x344u: goto label_344;
        case 0x34cu: goto label_34c;
        case 0x35cu: goto label_35c;
        case 0x364u: goto label_364;
        default: break;
    }

    ctx->pc = 0x324u;

    // 0x324: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x328: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
    // 0x32c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x330: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x334: 0xc00000a  jal         func_000028
    ctx->pc = 0x334u;
    SET_GPR_U32(ctx, 31, 0x33Cu);
    // 0x338: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x28u, 0x334u, 0x33Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x33Cu;
label_33c:
    // 0x33c: 0xc000027  jal         func_00009C
    ctx->pc = 0x33Cu;
    SET_GPR_U32(ctx, 31, 0x344u);
    // 0x340: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x9Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x9Cu, 0x33Cu, 0x344u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x344u;
label_344:
    // 0x344: 0xc000038  jal         func_0000E0
    ctx->pc = 0x344u;
    SET_GPR_U32(ctx, 31, 0x34Cu);
    // 0x348: 0xae220024  sw          $v0, 0x24($s1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 2));
    ctx->pc = 0xE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE0u, 0x344u, 0x34Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x34Cu;
label_34c:
    // 0x34c: 0x8e230070  lw          $v1, 0x70($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 112)));
    // 0x350: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x354: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x354u;
    {
        const bool branch_taken_0x354 = (GPR_S32(ctx, 3) <= 0);
        // 0x358: 0xae220068  sw          $v0, 0x68($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 104), GPR_U32(ctx, 2));
        if (branch_taken_0x354) {
            ctx->pc = 0x388u;
            goto label_388;
        }
    }
    ctx->pc = 0x35Cu;
label_35c:
    // 0x35c: 0xc000055  jal         func_000154
    ctx->pc = 0x35Cu;
    SET_GPR_U32(ctx, 31, 0x364u);
    ctx->pc = 0x154u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x154u, 0x35Cu, 0x364u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x364u;
label_364:
    // 0x364: 0x8e230078  lw          $v1, 0x78($s1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 120)));
    // 0x368: 0x0  nop
    // NOP
    // 0x36c: 0x701821  addu        $v1, $v1, $s0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x370: 0xa0620000  sb          $v0, 0x0($v1)
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x374: 0x8e220070  lw          $v0, 0x70($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 112)));
    // 0x378: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x37c: 0x202102a  slt         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x380: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x380u;
    {
        const bool branch_taken_0x380 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x380) {
            ctx->pc = 0x35Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_35c;
        }
    }
    ctx->pc = 0x388u;
label_388:
    // 0x388: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x38c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x390: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x394: 0x3e00008  jr          $ra
    ctx->pc = 0x394u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x398: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x394u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x39Cu;
}


// Function: sio2man_0000039c
// Address: 0x39c - 0x584
void sio2man_0000039c_0x39c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000039c_0x39c");
#endif

    switch (ctx->pc) {
        case 0x3b4u: goto label_3b4;
        case 0x3c4u: goto label_3c4;
        case 0x3e8u: goto label_3e8;
        case 0x404u: goto label_404;
        case 0x414u: goto label_414;
        case 0x41cu: goto label_41c;
        case 0x428u: goto label_428;
        case 0x444u: goto label_444;
        case 0x464u: goto label_464;
        case 0x484u: goto label_484;
        case 0x4a4u: goto label_4a4;
        case 0x4c8u: goto label_4c8;
        case 0x4dcu: goto label_4dc;
        case 0x4e4u: goto label_4e4;
        case 0x4ecu: goto label_4ec;
        case 0x500u: goto label_500;
        case 0x520u: goto label_520;
        case 0x528u: goto label_528;
        case 0x534u: goto label_534;
        case 0x53cu: goto label_53c;
        case 0x550u: goto label_550;
        case 0x55cu: goto label_55c;
        case 0x568u: goto label_568;
        default: break;
    }

    ctx->pc = 0x39cu;

    // 0x39c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x3a0: 0xafb00038  sw          $s0, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 16));
    // 0x3a4: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x3a8: 0x26100fcc  addiu       $s0, $s0, 0xFCC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4044));
    // 0x3ac: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
    // 0x3b0: 0x24054155  addiu       $a1, $zero, 0x4155
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16725));
label_3b4:
    // 0x3b4: 0x24060001  addiu       $a2, $zero, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x3b8: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x3bc: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0x3BCu;
    SET_GPR_U32(ctx, 31, 0x3C4u);
    // 0x3c0: 0x27a70030  addiu       $a3, $sp, 0x30 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0x3BCu, 0x3C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C4u;
label_3c4:
    // 0x3c4: 0x8fa50030  lw          $a1, 0x30($sp)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x3c8: 0x0  nop
    // NOP
    // 0x3cc: 0x30a24000  andi        $v0, $a1, 0x4000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16384);
    // 0x3d0: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x3D0u;
    {
        const bool branch_taken_0x3d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3d4: 0x30a20001  andi        $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
        if (branch_taken_0x3d0) {
            ctx->pc = 0x430u;
            goto label_430;
        }
    }
    ctx->pc = 0x3D8u;
    // 0x3d8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x3dc: 0x8c840fc0  lw          $a0, 0xFC0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4032)));
    // 0x3e0: 0xc0003bf  jal         func_000EFC
    ctx->pc = 0x3E0u;
    SET_GPR_U32(ctx, 31, 0x3E8u);
    // 0x3e4: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0xEFCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEFCu, 0x3E0u, 0x3E8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3E8u;
label_3e8:
    // 0x3e8: 0x8fa20020  lw          $v0, 0x20($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x3ec: 0x0  nop
    // NOP
    // 0x3f0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x3F0u;
    {
        const bool branch_taken_0x3f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3f0) {
            ctx->pc = 0x404u;
            goto label_404;
        }
    }
    ctx->pc = 0x3F8u;
    // 0x3f8: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x3fc: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x3FCu;
    SET_GPR_U32(ctx, 31, 0x404u);
    // 0x400: 0x2405bfff  addiu       $a1, $zero, -0x4001 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294950911));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x3FCu, 0x404u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x404u;
label_404:
    // 0x404: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x408: 0x8c840fc0  lw          $a0, 0xFC0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4032)));
    // 0x40c: 0xc0003bb  jal         func_000EEC
    ctx->pc = 0x40Cu;
    SET_GPR_U32(ctx, 31, 0x414u);
    ctx->pc = 0xEECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEECu, 0x40Cu, 0x414u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x414u;
label_414:
    // 0x414: 0x800013c  j           func_0004F0
    ctx->pc = 0x414u;
    // 0x418: 0x24051400  addiu       $a1, $zero, 0x1400 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5120));
    ctx->pc = 0x4F0u;
    goto label_4f0;
    ctx->pc = 0x41Cu;
label_41c:
    // 0x41c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x420: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x420u;
    SET_GPR_U32(ctx, 31, 0x428u);
    // 0x424: 0x2405efff  addiu       $a1, $zero, -0x1001 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294963199));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x420u, 0x428u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x428u;
label_428:
    // 0x428: 0x80000ed  j           func_0003B4
    ctx->pc = 0x428u;
    // 0x42c: 0x24054155  addiu       $a1, $zero, 0x4155 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16725));
    ctx->pc = 0x3B4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_3b4;
    ctx->pc = 0x430u;
label_430:
    // 0x430: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x430u;
    {
        const bool branch_taken_0x430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x434: 0x30a20040  andi        $v0, $a1, 0x40 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)64);
        if (branch_taken_0x430) {
            ctx->pc = 0x450u;
            goto label_450;
        }
    }
    ctx->pc = 0x438u;
    // 0x438: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x43c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x43Cu;
    SET_GPR_U32(ctx, 31, 0x444u);
    // 0x440: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x43Cu, 0x444u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x444u;
label_444:
    // 0x444: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x448: 0x8000139  j           func_0004E4
    ctx->pc = 0x448u;
    // 0x44c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x4E4u;
    goto label_4e4;
    ctx->pc = 0x450u;
label_450:
    // 0x450: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x450u;
    {
        const bool branch_taken_0x450 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x454: 0x30a20100  andi        $v0, $a1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)256);
        if (branch_taken_0x450) {
            ctx->pc = 0x470u;
            goto label_470;
        }
    }
    ctx->pc = 0x458u;
    // 0x458: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x45c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x45Cu;
    SET_GPR_U32(ctx, 31, 0x464u);
    // 0x460: 0x2405ffbf  addiu       $a1, $zero, -0x41 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x45Cu, 0x464u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x464u;
label_464:
    // 0x464: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x468: 0x8000139  j           func_0004E4
    ctx->pc = 0x468u;
    // 0x46c: 0x24050080  addiu       $a1, $zero, 0x80 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    ctx->pc = 0x4E4u;
    goto label_4e4;
    ctx->pc = 0x470u;
label_470:
    // 0x470: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x470u;
    {
        const bool branch_taken_0x470 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x474: 0x30a20004  andi        $v0, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
        if (branch_taken_0x470) {
            ctx->pc = 0x490u;
            goto label_490;
        }
    }
    ctx->pc = 0x478u;
    // 0x478: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x47c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x47Cu;
    SET_GPR_U32(ctx, 31, 0x484u);
    // 0x480: 0x2405feff  addiu       $a1, $zero, -0x101 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967039));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x47Cu, 0x484u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x484u;
label_484:
    // 0x484: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x488: 0x8000139  j           func_0004E4
    ctx->pc = 0x488u;
    // 0x48c: 0x24050200  addiu       $a1, $zero, 0x200 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    ctx->pc = 0x4E4u;
    goto label_4e4;
    ctx->pc = 0x490u;
label_490:
    // 0x490: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x490u;
    {
        const bool branch_taken_0x490 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x494: 0x30a20010  andi        $v0, $a1, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)16);
        if (branch_taken_0x490) {
            ctx->pc = 0x4B0u;
            goto label_4b0;
        }
    }
    ctx->pc = 0x498u;
    // 0x498: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x49c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x49Cu;
    SET_GPR_U32(ctx, 31, 0x4A4u);
    // 0x4a0: 0x2405fffb  addiu       $a1, $zero, -0x5 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x49Cu, 0x4A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4A4u;
label_4a4:
    // 0x4a4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x4a8: 0x8000139  j           func_0004E4
    ctx->pc = 0x4A8u;
    // 0x4ac: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x4E4u;
    goto label_4e4;
    ctx->pc = 0x4B0u;
label_4b0:
    // 0x4b0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x4B0u;
    {
        const bool branch_taken_0x4b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4b0) {
            ctx->pc = 0x4D0u;
            goto label_4d0;
        }
    }
    ctx->pc = 0x4B8u;
    // 0x4b8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x4bc: 0x24840f48  addiu       $a0, $a0, 0xF48
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3912));
    // 0x4c0: 0xc000381  jal         func_000E04
    ctx->pc = 0x4C0u;
    SET_GPR_U32(ctx, 31, 0x4C8u);
    ctx->pc = 0xE04u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE04u, 0x4C0u, 0x4C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4C8u;
label_4c8:
    // 0x4c8: 0x800015d  j           func_000574
    ctx->pc = 0x4C8u;
    ctx->pc = 0x574u;
    goto label_574;
    ctx->pc = 0x4D0u;
label_4d0:
    // 0x4d0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x4d4: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x4D4u;
    SET_GPR_U32(ctx, 31, 0x4DCu);
    // 0x4d8: 0x2405ffef  addiu       $a1, $zero, -0x11 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967279));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x4D4u, 0x4DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4DCu;
label_4dc:
    // 0x4dc: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x4e0: 0x24050020  addiu       $a1, $zero, 0x20
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_4e4:
    // 0x4e4: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0x4E4u;
    SET_GPR_U32(ctx, 31, 0x4ECu);
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0x4E4u, 0x4ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4ECu;
label_4ec:
    // 0x4ec: 0x24051400  addiu       $a1, $zero, 0x1400
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5120));
label_4f0:
    // 0x4f0: 0x24060001  addiu       $a2, $zero, 0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x4f4: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x4f8: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0x4F8u;
    SET_GPR_U32(ctx, 31, 0x500u);
    // 0x4fc: 0x27a70030  addiu       $a3, $sp, 0x30 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0x4F8u, 0x500u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x500u;
label_500:
    // 0x500: 0x8fa20030  lw          $v0, 0x30($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x504: 0x0  nop
    // NOP
    // 0x508: 0x30421000  andi        $v0, $v0, 0x1000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4096);
    // 0x50c: 0x1440ffc3  bnez        $v0, . + 4 + (-0x3D << 2)
    ctx->pc = 0x50Cu;
    {
        const bool branch_taken_0x50c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x50c) {
            ctx->pc = 0x41Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_41c;
        }
    }
    ctx->pc = 0x514u;
    // 0x514: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x518: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x518u;
    SET_GPR_U32(ctx, 31, 0x520u);
    // 0x51c: 0x2405fbff  addiu       $a1, $zero, -0x401 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966271));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x518u, 0x520u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x520u;
label_520:
    // 0x520: 0xc00006b  jal         func_0001AC
    ctx->pc = 0x520u;
    SET_GPR_U32(ctx, 31, 0x528u);
    ctx->pc = 0x1ACu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1ACu, 0x520u, 0x528u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x528u;
label_528:
    // 0x528: 0x8e04000c  lw          $a0, 0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x52c: 0xc000075  jal         func_0001D4
    ctx->pc = 0x52Cu;
    SET_GPR_U32(ctx, 31, 0x534u);
    ctx->pc = 0x1D4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x1D4u, 0x52Cu, 0x534u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x534u;
label_534:
    // 0x534: 0xc0000bf  jal         func_0002FC
    ctx->pc = 0x534u;
    SET_GPR_U32(ctx, 31, 0x53Cu);
    ctx->pc = 0x2FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x2FCu, 0x534u, 0x53Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x53Cu;
label_53c:
    // 0x53c: 0x24052000  addiu       $a1, $zero, 0x2000
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x540: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x544: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x548: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0x548u;
    SET_GPR_U32(ctx, 31, 0x550u);
    // 0x54c: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0x548u, 0x550u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x550u;
label_550:
    // 0x550: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x554: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x554u;
    SET_GPR_U32(ctx, 31, 0x55Cu);
    // 0x558: 0x2405dfff  addiu       $a1, $zero, -0x2001 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959103));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x554u, 0x55Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x55Cu;
label_55c:
    // 0x55c: 0x8e04000c  lw          $a0, 0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x560: 0xc0000c9  jal         func_000324
    ctx->pc = 0x560u;
    SET_GPR_U32(ctx, 31, 0x568u);
    ctx->pc = 0x324u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x324u, 0x560u, 0x568u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x568u;
label_568:
    // 0x568: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x56c: 0x8000139  j           func_0004E4
    ctx->pc = 0x56Cu;
    // 0x570: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    ctx->pc = 0x4E4u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_4e4;
    ctx->pc = 0x574u;
label_574:
    // 0x574: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x578: 0x8fb00038  lw          $s0, 0x38($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x57c: 0x3e00008  jr          $ra
    ctx->pc = 0x57Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x580: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x57Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x584u;
}


// Function: sio2man_00000584
// Address: 0x584 - 0x5c0
void sio2man_00000584_0x584(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000584_0x584");
#endif

    switch (ctx->pc) {
        case 0x598u: goto label_598;
        case 0x5a0u: goto label_5a0;
        case 0x5acu: goto label_5ac;
        default: break;
    }

    ctx->pc = 0x584u;

    // 0x584: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x588: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x58c: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x590: 0xc00005e  jal         func_000178
    ctx->pc = 0x590u;
    SET_GPR_U32(ctx, 31, 0x598u);
    // 0x594: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    ctx->pc = 0x178u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x178u, 0x590u, 0x598u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x598u;
label_598:
    // 0x598: 0xc000059  jal         func_000164
    ctx->pc = 0x598u;
    SET_GPR_U32(ctx, 31, 0x5A0u);
    // 0x59c: 0x402021  addu        $a0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x164u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x164u, 0x598u, 0x5A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5A0u;
label_5a0:
    // 0x5a0: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x5a4: 0xc0003ac  jal         func_000EB0
    ctx->pc = 0x5A4u;
    SET_GPR_U32(ctx, 31, 0x5ACu);
    // 0x5a8: 0x24052000  addiu       $a1, $zero, 0x2000 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    ctx->pc = 0xEB0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB0u, 0x5A4u, 0x5ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5ACu;
label_5ac:
    // 0x5ac: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x5b0: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x5b4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x5b8: 0x3e00008  jr          $ra
    ctx->pc = 0x5B8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x5bc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x5B8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x5C0u;
}


// Function: sio2man_000005c0
// Address: 0x5c0 - 0x5ec
void sio2man_000005c0_0x5c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000005c0_0x5c0");
#endif

    switch (ctx->pc) {
        case 0x5dcu: goto label_5dc;
        default: break;
    }

    ctx->pc = 0x5c0u;

    // 0x5c0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
    // 0x5c4: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x5c8: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x5cc: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
    // 0x5d0: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x5d4: 0xc0003a8  jal         func_000EA0
    ctx->pc = 0x5D4u;
    SET_GPR_U32(ctx, 31, 0x5DCu);
    // 0x5d8: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    ctx->pc = 0xEA0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA0u, 0x5D4u, 0x5DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x5DCu;
label_5dc:
    // 0x5dc: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x5e0: 0x0  nop
    // NOP
    // 0x5e4: 0x3e00008  jr          $ra
    ctx->pc = 0x5E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x5e8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x5E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x5ECu;
}


// Function: sio2man_000005ec
// Address: 0x5ec - 0x634
void sio2man_000005ec_0x5ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000005ec_0x5ec");
#endif

    switch (ctx->pc) {
        case 0x624u: goto label_624;
        default: break;
    }

    ctx->pc = 0x5ecu;

    // 0x5ec: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x5f0: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
    // 0x5f4: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x5f8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x5fc: 0x2442039c  addiu       $v0, $v0, 0x39C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 924));
    // 0x600: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x604: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x608: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
    // 0x60c: 0x8c630fd4  lw          $v1, 0xFD4($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4052)));
    // 0x610: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x614: 0xafbf0028  sw          $ra, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 31));
    // 0x618: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x61c: 0xc00039b  jal         func_000E6C
    ctx->pc = 0x61Cu;
    SET_GPR_U32(ctx, 31, 0x624u);
    // 0x620: 0xafa30020  sw          $v1, 0x20($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    ctx->pc = 0xE6Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE6Cu, 0x61Cu, 0x624u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x624u;
label_624:
    // 0x624: 0x8fbf0028  lw          $ra, 0x28($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x628: 0x0  nop
    // NOP
    // 0x62c: 0x3e00008  jr          $ra
    ctx->pc = 0x62Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x630: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x62Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x634u;
}


// Function: sio2man_00000634
// Address: 0x634 - 0x81c
void sio2man_00000634_0x634(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000634_0x634");
#endif

    switch (ctx->pc) {
        case 0x664u: goto label_664;
        case 0x688u: goto label_688;
        case 0x698u: goto label_698;
        case 0x6c8u: goto label_6c8;
        case 0x6dcu: goto label_6dc;
        case 0x6f8u: goto label_6f8;
        case 0x710u: goto label_710;
        case 0x758u: goto label_758;
        case 0x760u: goto label_760;
        case 0x768u: goto label_768;
        case 0x774u: goto label_774;
        case 0x78cu: goto label_78c;
        case 0x794u: goto label_794;
        case 0x7a0u: goto label_7a0;
        case 0x7acu: goto label_7ac;
        case 0x7b8u: goto label_7b8;
        case 0x7c0u: goto label_7c0;
        case 0x7c8u: goto label_7c8;
        case 0x7e4u: goto label_7e4;
        case 0x7f8u: goto label_7f8;
        default: break;
    }

    ctx->pc = 0x634u;

    // 0x634: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x638: 0xafb40038  sw          $s4, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 20));
    // 0x63c: 0x80a021  addu        $s4, $a0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
    // 0x640: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
    // 0x644: 0xa08021  addu        $s0, $a1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
    // 0x648: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x64c: 0x24840c60  addiu       $a0, $a0, 0xC60
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3168));
    // 0x650: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
    // 0x654: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
    // 0x658: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    // 0x65c: 0xc000365  jal         func_000D94
    ctx->pc = 0x65Cu;
    SET_GPR_U32(ctx, 31, 0x664u);
    // 0x660: 0xafb1002c  sw          $s1, 0x2C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
    ctx->pc = 0xD94u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xD94u, 0x65Cu, 0x664u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x664u;
label_664:
    // 0x664: 0x14400065  bnez        $v0, . + 4 + (0x65 << 2)
    ctx->pc = 0x664u;
    {
        const bool branch_taken_0x664 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x668: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x664) {
            ctx->pc = 0x7FCu;
            goto label_7fc;
        }
    }
    ctx->pc = 0x66Cu;
    // 0x66c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
    // 0x670: 0x8c420fb8  lw          $v0, 0xFB8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4024)));
    // 0x674: 0x0  nop
    // NOP
    // 0x678: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x678u;
    {
        const bool branch_taken_0x678 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x67c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x678) {
            ctx->pc = 0x6A0u;
            goto label_6a0;
        }
    }
    ctx->pc = 0x680u;
    // 0x680: 0x80001ff  j           func_0007FC
    ctx->pc = 0x680u;
    ctx->pc = 0x7FCu;
    goto label_7fc;
    ctx->pc = 0x688u;
label_688:
    // 0x688: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x68c: 0x24840f7c  addiu       $a0, $a0, 0xF7C
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3964));
    // 0x690: 0xc000381  jal         func_000E04
    ctx->pc = 0x690u;
    SET_GPR_U32(ctx, 31, 0x698u);
    // 0x694: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0xE04u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE04u, 0x690u, 0x698u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x80001ff  j           func_0007FC
    ctx->pc = 0x698u;
    // 0x69c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x7FCu;
    goto label_7fc;
    ctx->pc = 0x6A0u;
label_6a0:
    // 0x6a0: 0x24130001  addiu       $s3, $zero, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x6a4: 0x2601021  addu        $v0, $s3, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    // 0x6a8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6ac: 0xac220fb8  sw          $v0, 0xFB8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4024), GPR_U32(ctx, 2));
    // 0x6b0: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x6b4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x6b8: 0xac220fd4  sw          $v0, 0xFD4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4052), GPR_U32(ctx, 2));
    // 0x6bc: 0x274102a  slt         $v0, $s3, $s4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x6c0: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x6C0u;
    {
        const bool branch_taken_0x6c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x6c4: 0x26120004  addiu       $s2, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        if (branch_taken_0x6c0) {
            ctx->pc = 0x73Cu;
            goto label_73c;
        }
    }
    ctx->pc = 0x6C8u;
label_6c8:
    // 0x6c8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x6cc: 0x24840f74  addiu       $a0, $a0, 0xF74
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3956));
    // 0x6d0: 0x8e450000  lw          $a1, 0x0($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x6d4: 0xc0003ca  jal         func_000F28
    ctx->pc = 0x6D4u;
    SET_GPR_U32(ctx, 31, 0x6DCu);
    // 0x6d8: 0x24060006  addiu       $a2, $zero, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    ctx->pc = 0xF28u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF28u, 0x6D4u, 0x6DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6DCu;
label_6dc:
    // 0x6dc: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x6DCu;
    {
        const bool branch_taken_0x6dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x6e0: 0x2410ffff  addiu       $s0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x6dc) {
            ctx->pc = 0x72Cu;
            goto label_72c;
        }
    }
    ctx->pc = 0x6E4u;
    // 0x6e4: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x6e8: 0x0  nop
    // NOP
    // 0x6ec: 0x80440006  lb          $a0, 0x6($v0)
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x6f0: 0xc0003c8  jal         func_000F20
    ctx->pc = 0x6F0u;
    SET_GPR_U32(ctx, 31, 0x6F8u);
    // 0x6f4: 0x24510006  addiu       $s1, $v0, 0x6 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    ctx->pc = 0xF20u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF20u, 0x6F0u, 0x6F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6F8u;
label_6f8:
    // 0x6f8: 0x30420004  andi        $v0, $v0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x6fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x6FCu;
    {
        const bool branch_taken_0x6fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x700: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x6fc) {
            ctx->pc = 0x714u;
            goto label_714;
        }
    }
    ctx->pc = 0x704u;
    // 0x704: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x708: 0xc0003cc  jal         func_000F30
    ctx->pc = 0x708u;
    SET_GPR_U32(ctx, 31, 0x710u);
    // 0x70c: 0x2406000a  addiu       $a2, $zero, 0xA (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    ctx->pc = 0xF30u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xF30u, 0x708u, 0x710u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x710u;
label_710:
    // 0x710: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_714:
    // 0x714: 0x2602fff7  addiu       $v0, $s0, -0x9
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967287));
    // 0x718: 0x2c420073  sltiu       $v0, $v0, 0x73
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)115) ? 1 : 0);
    // 0x71c: 0x1040ffda  beqz        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x71Cu;
    {
        const bool branch_taken_0x71c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x71c) {
            ctx->pc = 0x688u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_688;
        }
    }
    ctx->pc = 0x724u;
    // 0x724: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x728: 0xac300fd4  sw          $s0, 0xFD4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4052), GPR_U32(ctx, 16));
label_72c:
    // 0x72c: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x730: 0x274102a  slt         $v0, $s3, $s4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x734: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x734u;
    {
        const bool branch_taken_0x734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x738: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        if (branch_taken_0x734) {
            ctx->pc = 0x6C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_6c8;
        }
    }
    ctx->pc = 0x73Cu;
label_73c:
    // 0x73c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x740: 0x26100fdc  addiu       $s0, $s0, 0xFDC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4060));
    // 0x744: 0xae000000  sw          $zero, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x748: 0xae000004  sw          $zero, 0x4($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x74c: 0xae000008  sw          $zero, 0x8($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x750: 0xc000063  jal         func_00018C
    ctx->pc = 0x750u;
    SET_GPR_U32(ctx, 31, 0x758u);
    // 0x754: 0xae00000c  sw          $zero, 0xC($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    ctx->pc = 0x18Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x18Cu, 0x750u, 0x758u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x758u;
label_758:
    // 0x758: 0xc000170  jal         func_0005C0
    ctx->pc = 0x758u;
    SET_GPR_U32(ctx, 31, 0x760u);
    ctx->pc = 0x5C0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5C0u, 0x758u, 0x760u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x760u;
label_760:
    // 0x760: 0xc00017b  jal         func_0005EC
    ctx->pc = 0x760u;
    SET_GPR_U32(ctx, 31, 0x768u);
    // 0x764: 0xae02fff0  sw          $v0, -0x10($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967280), GPR_U32(ctx, 2));
    ctx->pc = 0x5ECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x5ECu, 0x760u, 0x768u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x768u;
label_768:
    // 0x768: 0x27a40020  addiu       $a0, $sp, 0x20
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x76c: 0xc000376  jal         func_000DD8
    ctx->pc = 0x76Cu;
    SET_GPR_U32(ctx, 31, 0x774u);
    // 0x770: 0xae02fff4  sw          $v0, -0xC($s0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967284), GPR_U32(ctx, 2));
    ctx->pc = 0xDD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDD8u, 0x76Cu, 0x774u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x774u;
label_774:
    // 0x774: 0x24040011  addiu       $a0, $zero, 0x11
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x778: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x77c: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
    // 0x780: 0x24c60584  addiu       $a2, $a2, 0x584
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1412));
    // 0x784: 0xc00036e  jal         func_000DB8
    ctx->pc = 0x784u;
    SET_GPR_U32(ctx, 31, 0x78Cu);
    // 0x788: 0x2607ffec  addiu       $a3, $s0, -0x14 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967276));
    ctx->pc = 0xDB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDB8u, 0x784u, 0x78Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x78Cu;
label_78c:
    // 0x78c: 0xc000372  jal         func_000DC8
    ctx->pc = 0x78Cu;
    SET_GPR_U32(ctx, 31, 0x794u);
    // 0x790: 0x24040011  addiu       $a0, $zero, 0x11 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    ctx->pc = 0xDC8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDC8u, 0x78Cu, 0x794u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x794u;
label_794:
    // 0x794: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x798: 0xc000378  jal         func_000DE0
    ctx->pc = 0x798u;
    SET_GPR_U32(ctx, 31, 0x7A0u);
    ctx->pc = 0xDE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDE0u, 0x798u, 0x7A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7A0u;
label_7a0:
    // 0x7a0: 0x2404000b  addiu       $a0, $zero, 0xB
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x7a4: 0xc00038e  jal         func_000E38
    ctx->pc = 0x7A4u;
    SET_GPR_U32(ctx, 31, 0x7ACu);
    // 0x7a8: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0xE38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE38u, 0x7A4u, 0x7ACu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7ACu;
label_7ac:
    // 0x7ac: 0x2404000c  addiu       $a0, $zero, 0xC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x7b0: 0xc00038e  jal         func_000E38
    ctx->pc = 0x7B0u;
    SET_GPR_U32(ctx, 31, 0x7B8u);
    // 0x7b4: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0xE38u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE38u, 0x7B0u, 0x7B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7B8u;
label_7b8:
    // 0x7b8: 0xc000390  jal         func_000E40
    ctx->pc = 0x7B8u;
    SET_GPR_U32(ctx, 31, 0x7C0u);
    // 0x7bc: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    ctx->pc = 0xE40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE40u, 0x7B8u, 0x7C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7C0u;
label_7c0:
    // 0x7c0: 0xc000390  jal         func_000E40
    ctx->pc = 0x7C0u;
    SET_GPR_U32(ctx, 31, 0x7C8u);
    // 0x7c4: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    ctx->pc = 0xE40u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE40u, 0x7C0u, 0x7C8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7C8u;
label_7c8:
    // 0x7c8: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x7cc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x7d0: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x7d4: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x7d8: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x7dc: 0xc0003b9  jal         func_000EE4
    ctx->pc = 0x7DCu;
    SET_GPR_U32(ctx, 31, 0x7E4u);
    // 0x7e0: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    ctx->pc = 0xEE4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEE4u, 0x7DCu, 0x7E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7E4u;
label_7e4:
    // 0x7e4: 0x8e04fff4  lw          $a0, -0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967284)));
    // 0x7e8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0x7ec: 0xac220fc0  sw          $v0, 0xFC0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4032), GPR_U32(ctx, 2));
    // 0x7f0: 0xc00039d  jal         func_000E74
    ctx->pc = 0x7F0u;
    SET_GPR_U32(ctx, 31, 0x7F8u);
    // 0x7f4: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xE74u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE74u, 0x7F0u, 0x7F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x7F8u;
label_7f8:
    // 0x7f8: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_7fc:
    // 0x7fc: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x800: 0x8fb40038  lw          $s4, 0x38($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x804: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x808: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x80c: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x810: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x814: 0x3e00008  jr          $ra
    ctx->pc = 0x814u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x818: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x814u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x81Cu;
}


// Function: sio2man_0000081c
// Address: 0x81c - 0x874
void sio2man_0000081c_0x81c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_0000081c_0x81c");
#endif

    switch (ctx->pc) {
        case 0x82cu: goto label_82c;
        case 0x834u: goto label_834;
        case 0x840u: goto label_840;
        case 0x848u: goto label_848;
        case 0x854u: goto label_854;
        case 0x85cu: goto label_85c;
        case 0x864u: goto label_864;
        default: break;
    }

    ctx->pc = 0x81cu;

    // 0x81c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x820: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
    // 0x824: 0xc00039f  jal         func_000E7C
    ctx->pc = 0x824u;
    SET_GPR_U32(ctx, 31, 0x82Cu);
    ctx->pc = 0xE7Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE7Cu, 0x824u, 0x82Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x82Cu;
label_82c:
    // 0x82c: 0xc000376  jal         func_000DD8
    ctx->pc = 0x82Cu;
    SET_GPR_U32(ctx, 31, 0x834u);
    // 0x830: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0xDD8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDD8u, 0x82Cu, 0x834u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x834u;
label_834:
    // 0x834: 0x24040011  addiu       $a0, $zero, 0x11
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x838: 0xc000374  jal         func_000DD0
    ctx->pc = 0x838u;
    SET_GPR_U32(ctx, 31, 0x840u);
    // 0x83c: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xDD0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDD0u, 0x838u, 0x840u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x840u;
label_840:
    // 0x840: 0xc000370  jal         func_000DC0
    ctx->pc = 0x840u;
    SET_GPR_U32(ctx, 31, 0x848u);
    // 0x844: 0x24040011  addiu       $a0, $zero, 0x11 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    ctx->pc = 0xDC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDC0u, 0x840u, 0x848u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x848u;
label_848:
    // 0x848: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x84c: 0xc000378  jal         func_000DE0
    ctx->pc = 0x84Cu;
    SET_GPR_U32(ctx, 31, 0x854u);
    ctx->pc = 0xDE0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xDE0u, 0x84Cu, 0x854u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x854u;
label_854:
    // 0x854: 0xc000392  jal         func_000E48
    ctx->pc = 0x854u;
    SET_GPR_U32(ctx, 31, 0x85Cu);
    // 0x858: 0x2404000b  addiu       $a0, $zero, 0xB (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    ctx->pc = 0xE48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE48u, 0x854u, 0x85Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x85Cu;
label_85c:
    // 0x85c: 0xc000392  jal         func_000E48
    ctx->pc = 0x85Cu;
    SET_GPR_U32(ctx, 31, 0x864u);
    // 0x860: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    ctx->pc = 0xE48u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xE48u, 0x85Cu, 0x864u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x864u;
label_864:
    // 0x864: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x868: 0x0  nop
    // NOP
    // 0x86c: 0x3e00008  jr          $ra
    ctx->pc = 0x86Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x870: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x86Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x874u;
}


// Function: sio2man_00000874
// Address: 0x874 - 0x8a4
void sio2man_00000874_0x874(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000874_0x874");
#endif

    switch (ctx->pc) {
        case 0x88cu: goto label_88c;
        case 0x894u: goto label_894;
        default: break;
    }

    ctx->pc = 0x874u;

    // 0x874: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x878: 0x8c840fc0  lw          $a0, 0xFC0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4032)));
    // 0x87c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x880: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x884: 0xc0003bd  jal         func_000EF4
    ctx->pc = 0x884u;
    SET_GPR_U32(ctx, 31, 0x88Cu);
    ctx->pc = 0xEF4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEF4u, 0x884u, 0x88Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x88Cu;
label_88c:
    // 0x88c: 0xc000241  jal         func_000904
    ctx->pc = 0x88Cu;
    SET_GPR_U32(ctx, 31, 0x894u);
    ctx->pc = 0x904u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x904u, 0x88Cu, 0x894u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x894u;
label_894:
    // 0x894: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x898: 0x0  nop
    // NOP
    // 0x89c: 0x3e00008  jr          $ra
    ctx->pc = 0x89Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8a0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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


// Function: sio2man_000008a4
// Address: 0x8a4 - 0x8d4
void sio2man_000008a4_0x8a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000008a4_0x8a4");
#endif

    switch (ctx->pc) {
        case 0x8bcu: goto label_8bc;
        case 0x8c4u: goto label_8c4;
        default: break;
    }

    ctx->pc = 0x8a4u;

    // 0x8a4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x8a8: 0x8c840fc0  lw          $a0, 0xFC0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4032)));
    // 0x8ac: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x8b0: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x8b4: 0xc0003bd  jal         func_000EF4
    ctx->pc = 0x8B4u;
    SET_GPR_U32(ctx, 31, 0x8BCu);
    ctx->pc = 0xEF4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEF4u, 0x8B4u, 0x8BCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8BCu;
label_8bc:
    // 0x8bc: 0xc000255  jal         func_000954
    ctx->pc = 0x8BCu;
    SET_GPR_U32(ctx, 31, 0x8C4u);
    ctx->pc = 0x954u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x954u, 0x8BCu, 0x8C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8C4u;
label_8c4:
    // 0x8c4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x8c8: 0x0  nop
    // NOP
    // 0x8cc: 0x3e00008  jr          $ra
    ctx->pc = 0x8CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x8d0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x8D4u;
}


// Function: sio2man_000008d4
// Address: 0x8d4 - 0x904
void sio2man_000008d4_0x8d4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000008d4_0x8d4");
#endif

    switch (ctx->pc) {
        case 0x8e4u: goto label_8e4;
        case 0x8f4u: goto label_8f4;
        default: break;
    }

    ctx->pc = 0x8d4u;

    // 0x8d4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x8d8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0x8dc: 0xc0002bb  jal         func_000AEC
    ctx->pc = 0x8DCu;
    SET_GPR_U32(ctx, 31, 0x8E4u);
    ctx->pc = 0xAECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xAECu, 0x8DCu, 0x8E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8E4u;
label_8e4:
    // 0x8e4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0x8e8: 0x8c840fc0  lw          $a0, 0xFC0($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4032)));
    // 0x8ec: 0xc0003bb  jal         func_000EEC
    ctx->pc = 0x8ECu;
    SET_GPR_U32(ctx, 31, 0x8F4u);
    ctx->pc = 0xEECu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEECu, 0x8ECu, 0x8F4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x8F4u;
label_8f4:
    // 0x8f4: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x8f8: 0x0  nop
    // NOP
    // 0x8fc: 0x3e00008  jr          $ra
    ctx->pc = 0x8FCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x900: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x8FCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x904u;
}


// Function: sio2man_00000904
// Address: 0x904 - 0x954
void sio2man_00000904_0x904(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000904_0x904");
#endif

    switch (ctx->pc) {
        case 0x924u: goto label_924;
        case 0x938u: goto label_938;
        case 0x944u: goto label_944;
        default: break;
    }

    ctx->pc = 0x904u;

    // 0x904: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x908: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x90c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x910: 0x26100fcc  addiu       $s0, $s0, 0xFCC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4044));
    // 0x914: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x918: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x91c: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0x91Cu;
    SET_GPR_U32(ctx, 31, 0x924u);
    // 0x920: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0x91Cu, 0x924u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x924u;
label_924:
    // 0x924: 0x24050002  addiu       $a1, $zero, 0x2
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x928: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x92c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x930: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0x930u;
    SET_GPR_U32(ctx, 31, 0x938u);
    // 0x934: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0x930u, 0x938u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x938u;
label_938:
    // 0x938: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x93c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x93Cu;
    SET_GPR_U32(ctx, 31, 0x944u);
    // 0x940: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x93Cu, 0x944u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x944u;
label_944:
    // 0x944: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x948: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x94c: 0x3e00008  jr          $ra
    ctx->pc = 0x94Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x950: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x94Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x954u;
}


// Function: sio2man_00000954
// Address: 0x954 - 0x9a4
void sio2man_00000954_0x954(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000954_0x954");
#endif

    switch (ctx->pc) {
        case 0x974u: goto label_974;
        case 0x988u: goto label_988;
        case 0x994u: goto label_994;
        default: break;
    }

    ctx->pc = 0x954u;

    // 0x954: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x958: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x95c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x960: 0x26100fcc  addiu       $s0, $s0, 0xFCC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4044));
    // 0x964: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x968: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x96c: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0x96Cu;
    SET_GPR_U32(ctx, 31, 0x974u);
    // 0x970: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0x96Cu, 0x974u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x974u;
label_974:
    // 0x974: 0x24050008  addiu       $a1, $zero, 0x8
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x978: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x97c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x980: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0x980u;
    SET_GPR_U32(ctx, 31, 0x988u);
    // 0x984: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0x980u, 0x988u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x988u;
label_988:
    // 0x988: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x98c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x98Cu;
    SET_GPR_U32(ctx, 31, 0x994u);
    // 0x990: 0x2405fff7  addiu       $a1, $zero, -0x9 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x98Cu, 0x994u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x994u;
label_994:
    // 0x994: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x998: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x99c: 0x3e00008  jr          $ra
    ctx->pc = 0x99Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9a0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x99Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x9A4u;
}


// Function: sio2man_000009a4
// Address: 0x9a4 - 0x9f4
void sio2man_000009a4_0x9a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000009a4_0x9a4");
#endif

    switch (ctx->pc) {
        case 0x9c4u: goto label_9c4;
        case 0x9d8u: goto label_9d8;
        case 0x9e4u: goto label_9e4;
        default: break;
    }

    ctx->pc = 0x9a4u;

    // 0x9a4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x9a8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x9ac: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0x9b0: 0x26100fcc  addiu       $s0, $s0, 0xFCC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4044));
    // 0x9b4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0x9b8: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x9bc: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0x9BCu;
    SET_GPR_U32(ctx, 31, 0x9C4u);
    // 0x9c0: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0x9BCu, 0x9C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9C4u;
label_9c4:
    // 0x9c4: 0x24050020  addiu       $a1, $zero, 0x20
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x9c8: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0x9cc: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x9d0: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0x9D0u;
    SET_GPR_U32(ctx, 31, 0x9D8u);
    // 0x9d4: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0x9D0u, 0x9D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9D8u;
label_9d8:
    // 0x9d8: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x9dc: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0x9DCu;
    SET_GPR_U32(ctx, 31, 0x9E4u);
    // 0x9e0: 0x2405ffdf  addiu       $a1, $zero, -0x21 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967263));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0x9DCu, 0x9E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x9E4u;
label_9e4:
    // 0x9e4: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x9e8: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x9ec: 0x3e00008  jr          $ra
    ctx->pc = 0x9ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x9f0: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
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
}


// Function: sio2man_000009f4
// Address: 0x9f4 - 0xa44
void sio2man_000009f4_0x9f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_000009f4_0x9f4");
#endif

    switch (ctx->pc) {
        case 0xa14u: goto label_a14;
        case 0xa28u: goto label_a28;
        case 0xa34u: goto label_a34;
        default: break;
    }

    ctx->pc = 0x9f4u;

    // 0x9f4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0x9f8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0x9fc: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xa00: 0x26100fcc  addiu       $s0, $s0, 0xFCC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4044));
    // 0xa04: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xa08: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa0c: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0xA0Cu;
    SET_GPR_U32(ctx, 31, 0xA14u);
    // 0xa10: 0x24050040  addiu       $a1, $zero, 0x40 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0xA0Cu, 0xA14u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA14u;
label_a14:
    // 0xa14: 0x24050080  addiu       $a1, $zero, 0x80
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0xa18: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xa1c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa20: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0xA20u;
    SET_GPR_U32(ctx, 31, 0xA28u);
    // 0xa24: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0xA20u, 0xA28u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA28u;
label_a28:
    // 0xa28: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa2c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0xA2Cu;
    SET_GPR_U32(ctx, 31, 0xA34u);
    // 0xa30: 0x2405ff7f  addiu       $a1, $zero, -0x81 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0xA2Cu, 0xA34u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA34u;
label_a34:
    // 0xa34: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xa38: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xa3c: 0x3e00008  jr          $ra
    ctx->pc = 0xA3Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa40: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA3Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA44u;
}


// Function: sio2man_00000a44
// Address: 0xa44 - 0xa94
void sio2man_00000a44_0xa44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000a44_0xa44");
#endif

    switch (ctx->pc) {
        case 0xa64u: goto label_a64;
        case 0xa78u: goto label_a78;
        case 0xa84u: goto label_a84;
        default: break;
    }

    ctx->pc = 0xa44u;

    // 0xa44: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xa48: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0xa4c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xa50: 0x26100fcc  addiu       $s0, $s0, 0xFCC
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4044));
    // 0xa54: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xa58: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa5c: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0xA5Cu;
    SET_GPR_U32(ctx, 31, 0xA64u);
    // 0xa60: 0x24050100  addiu       $a1, $zero, 0x100 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0xA5Cu, 0xA64u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA64u;
label_a64:
    // 0xa64: 0x24050200  addiu       $a1, $zero, 0x200
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0xa68: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xa6c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa70: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0xA70u;
    SET_GPR_U32(ctx, 31, 0xA78u);
    // 0xa74: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0xA70u, 0xA78u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA78u;
label_a78:
    // 0xa78: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0xa7c: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0xA7Cu;
    SET_GPR_U32(ctx, 31, 0xA84u);
    // 0xa80: 0x2405fdff  addiu       $a1, $zero, -0x201 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966783));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0xA7Cu, 0xA84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xA84u;
label_a84:
    // 0xa84: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xa88: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xa8c: 0x3e00008  jr          $ra
    ctx->pc = 0xA8Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xa90: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xA8Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xA94u;
}


// Function: sio2man_00000a94
// Address: 0xa94 - 0xaec
void sio2man_00000a94_0xa94(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000a94_0xa94");
#endif

    switch (ctx->pc) {
        case 0xab8u: goto label_ab8;
        case 0xaccu: goto label_acc;
        case 0xad8u: goto label_ad8;
        default: break;
    }

    ctx->pc = 0xa94u;

    // 0xa94: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xa98: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    // 0xa9c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
    // 0xaa0: 0x26100fd8  addiu       $s0, $s0, 0xFD8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4056));
    // 0xaa4: 0xafbf0014  sw          $ra, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 31));
    // 0xaa8: 0xae040000  sw          $a0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
    // 0xaac: 0x8e04fff4  lw          $a0, -0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967284)));
    // 0xab0: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0xAB0u;
    SET_GPR_U32(ctx, 31, 0xAB8u);
    // 0xab4: 0x24050400  addiu       $a1, $zero, 0x400 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0xAB0u, 0xAB8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xAB8u;
label_ab8:
    // 0xab8: 0x24050800  addiu       $a1, $zero, 0x800
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0xabc: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    // 0xac0: 0x8e04fff4  lw          $a0, -0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967284)));
    // 0xac4: 0xc0003b0  jal         func_000EC0
    ctx->pc = 0xAC4u;
    SET_GPR_U32(ctx, 31, 0xACCu);
    // 0xac8: 0xc03821  addu        $a3, $a2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
    ctx->pc = 0xEC0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEC0u, 0xAC4u, 0xACCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xACCu;
label_acc:
    // 0xacc: 0x8e04fff4  lw          $a0, -0xC($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967284)));
    // 0xad0: 0xc0003ae  jal         func_000EB8
    ctx->pc = 0xAD0u;
    SET_GPR_U32(ctx, 31, 0xAD8u);
    // 0xad4: 0x2405f7ff  addiu       $a1, $zero, -0x801 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294965247));
    ctx->pc = 0xEB8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEB8u, 0xAD0u, 0xAD8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xAD8u;
label_ad8:
    // 0xad8: 0x8fbf0014  lw          $ra, 0x14($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0xadc: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xae0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0xae4: 0x3e00008  jr          $ra
    ctx->pc = 0xAE4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xae8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xAE4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xAECu;
}


// Function: sio2man_00000aec
// Address: 0xaec - 0xb14
void sio2man_00000aec_0xaec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000aec_0xaec");
#endif

    switch (ctx->pc) {
        case 0xb04u: goto label_b04;
        default: break;
    }

    ctx->pc = 0xaecu;

    // 0xaec: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
    // 0xaf0: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
    // 0xaf4: 0x8c840fcc  lw          $a0, 0xFCC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4044)));
    // 0xaf8: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
    // 0xafc: 0xc0003aa  jal         func_000EA8
    ctx->pc = 0xAFCu;
    SET_GPR_U32(ctx, 31, 0xB04u);
    // 0xb00: 0x24051000  addiu       $a1, $zero, 0x1000 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    ctx->pc = 0xEA8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0xEA8u, 0xAFCu, 0xB04u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xB04u;
label_b04:
    // 0xb04: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0xb08: 0x0  nop
    // NOP
    // 0xb0c: 0x3e00008  jr          $ra
    ctx->pc = 0xB0Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xb10: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB0Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB14u;
}


// Function: sio2man_00000b14
// Address: 0xb14 - 0xb24
void sio2man_00000b14_0xb14(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000b14_0xb14");
#endif

    ctx->pc = 0xb14u;

    // 0xb14: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb18: 0xac240fdc  sw          $a0, 0xFDC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4060), GPR_U32(ctx, 4));
    // 0xb1c: 0x3e00008  jr          $ra
    ctx->pc = 0xB1Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB1Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB24u;
}


// Function: sio2man_00000b24
// Address: 0xb24 - 0xb34
void sio2man_00000b24_0xb24(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000b24_0xb24");
#endif

    ctx->pc = 0xb24u;

    // 0xb24: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb28: 0xac240fe0  sw          $a0, 0xFE0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4064), GPR_U32(ctx, 4));
    // 0xb2c: 0x3e00008  jr          $ra
    ctx->pc = 0xB2Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB2Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB34u;
}


// Function: sio2man_00000b34
// Address: 0xb34 - 0xb44
void sio2man_00000b34_0xb34(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000b34_0xb34");
#endif

    ctx->pc = 0xb34u;

    // 0xb34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb38: 0xac240fe4  sw          $a0, 0xFE4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4068), GPR_U32(ctx, 4));
    // 0xb3c: 0x3e00008  jr          $ra
    ctx->pc = 0xB3Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB3Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB44u;
}


// Function: sio2man_00000b44
// Address: 0xb44 - 0xb54
void sio2man_00000b44_0xb44(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000b44_0xb44");
#endif

    ctx->pc = 0xb44u;

    // 0xb44: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
    // 0xb48: 0xac240fe8  sw          $a0, 0xFE8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 4072), GPR_U32(ctx, 4));
    // 0xb4c: 0x3e00008  jr          $ra
    ctx->pc = 0xB4Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB4Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB54u;
}


// Function: sio2man_00000b54
// Address: 0xb54 - 0xbcc
void sio2man_00000b54_0xb54(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000b54_0xb54");
#endif

    switch (ctx->pc) {
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
        case 0xbb0u: goto label_bb0;
        case 0xbb4u: goto label_bb4;
        case 0xbb8u: goto label_bb8;
        case 0xbbcu: goto label_bbc;
        case 0xbc0u: goto label_bc0;
        case 0xbc4u: goto label_bc4;
        case 0xbc8u: goto label_bc8;
        default: break;
    }

    ctx->pc = 0xb54u;

label_b54:
    // 0xb54: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_b58:
    // 0xb58: 0x8c630fdc  lw          $v1, 0xFDC($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4060)));
label_b5c:
    // 0xb5c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_b60:
    // 0xb60: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
label_b64:
    if (ctx->pc == 0xB64u) {
        // 0xb64: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        ctx->pc = 0xB68u;
        goto label_b68;
    }
    ctx->pc = 0xB60u;
    {
        const bool branch_taken_0xb60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0xb64: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0xb60) {
            ctx->pc = 0xB78u;
            goto label_b78;
        }
    }
    ctx->pc = 0xB68u;
label_b68:
    // 0xb68: 0x60f809  jalr        $v1
label_b6c:
    if (ctx->pc == 0xB6Cu) {
        ctx->pc = 0xB70u;
        goto label_b70;
    }
    ctx->pc = 0xB68u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0xB70u);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xB68u, 0xB70u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xB70u;
label_b70:
    // 0xb70: 0x80002ef  j           func_000BBC
label_b74:
    if (ctx->pc == 0xB74u) {
        // 0xb74: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0xB78u;
        goto label_b78;
    }
    ctx->pc = 0xB70u;
    // 0xb74: 0x402821  addu        $a1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0xBBCu;
    goto label_bbc;
    ctx->pc = 0xB78u;
label_b78:
    // 0xb78: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_b7c:
    // 0xb7c: 0x1821  addu        $v1, $zero, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_b80:
    // 0xb80: 0xa03021  addu        $a2, $a1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_b84:
    // 0xb84: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_b88:
    // 0xb88: 0x0  nop
    // NOP
label_b8c:
    // 0xb8c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_b90:
    // 0xb90: 0x2c420002  sltiu       $v0, $v0, 0x2
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
label_b94:
    // 0xb94: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_b98:
    if (ctx->pc == 0xB98u) {
        ctx->pc = 0xB9Cu;
        goto label_b9c;
    }
    ctx->pc = 0xB94u;
    {
        const bool branch_taken_0xb94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xb94) {
            ctx->pc = 0xBA4u;
            goto label_ba4;
        }
    }
    ctx->pc = 0xB9Cu;
label_b9c:
    // 0xb9c: 0x80002eb  j           func_000BAC
label_ba0:
    if (ctx->pc == 0xBA0u) {
        // 0xba0: 0xac860010  sw          $a2, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 6));
        ctx->pc = 0xBA4u;
        goto label_ba4;
    }
    ctx->pc = 0xB9Cu;
    // 0xba0: 0xac860010  sw          $a2, 0x10($a0) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 6));
    ctx->pc = 0xBACu;
    goto label_bac;
    ctx->pc = 0xBA4u;
label_ba4:
    // 0xba4: 0xac800010  sw          $zero, 0x10($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
label_ba8:
    // 0xba8: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_bac:
    // 0xbac: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_bb0:
    // 0xbb0: 0x28620004  slti        $v0, $v1, 0x4
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
label_bb4:
    // 0xbb4: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
label_bb8:
    if (ctx->pc == 0xBB8u) {
        // 0xbb8: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->pc = 0xBBCu;
        goto label_bbc;
    }
    ctx->pc = 0xBB4u;
    {
        const bool branch_taken_0xbb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xbb8: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0xbb4) {
            ctx->pc = 0xB84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_b84;
        }
    }
    ctx->pc = 0xBBCu;
label_bbc:
    // 0xbbc: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_bc0:
    // 0xbc0: 0xa01021  addu        $v0, $a1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_bc4:
    // 0xbc4: 0x3e00008  jr          $ra
label_bc8:
    if (ctx->pc == 0xBC8u) {
        // 0xbc8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0xBCCu;
        goto label_fallthrough_0xbc4;
    }
    ctx->pc = 0xBC4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xbc8: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xBC4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0xbc4:
    ctx->pc = 0xBCCu;
}


// Function: sio2man_00000bcc
// Address: 0xbcc - 0xc00
void sio2man_00000bcc_0xbcc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000bcc_0xbcc");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0xbccu;

label_bcc:
    // 0xbcc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_bd0:
    // 0xbd0: 0x8c420fe0  lw          $v0, 0xFE0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4064)));
label_bd4:
    // 0xbd4: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_bd8:
    // 0xbd8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_bdc:
    if (ctx->pc == 0xBDCu) {
        // 0xbdc: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        ctx->pc = 0xBE0u;
        goto label_be0;
    }
    ctx->pc = 0xBD8u;
    {
        const bool branch_taken_0xbd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xbdc: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0xbd8) {
            ctx->pc = 0xBE8u;
            goto label_be8;
        }
    }
    ctx->pc = 0xBE0u;
label_be0:
    // 0xbe0: 0x80002fc  j           func_000BF0
label_be4:
    if (ctx->pc == 0xBE4u) {
        // 0xbe4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xBE8u;
        goto label_be8;
    }
    ctx->pc = 0xBE0u;
    // 0xbe4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xBF0u;
    goto label_bf0;
    ctx->pc = 0xBE8u;
label_be8:
    // 0xbe8: 0x40f809  jalr        $v0
label_bec:
    if (ctx->pc == 0xBECu) {
        ctx->pc = 0xBF0u;
        goto label_bf0;
    }
    ctx->pc = 0xBE8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0xBF0u);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xBE8u, 0xBF0u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xBF0u;
label_bf0:
    // 0xbf0: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_bf4:
    // 0xbf4: 0x0  nop
    // NOP
label_bf8:
    // 0xbf8: 0x3e00008  jr          $ra
label_bfc:
    if (ctx->pc == 0xBFCu) {
        // 0xbfc: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0xC00u;
        goto label_fallthrough_0xbf8;
    }
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
label_fallthrough_0xbf8:
    ctx->pc = 0xC00u;
}


// Function: sio2man_00000c00
// Address: 0xc00 - 0xc34
void sio2man_00000c00_0xc00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000c00_0xc00");
#endif

    switch (ctx->pc) {
        case 0xc00u: goto label_c00;
        case 0xc04u: goto label_c04;
        case 0xc08u: goto label_c08;
        case 0xc0cu: goto label_c0c;
        case 0xc10u: goto label_c10;
        case 0xc14u: goto label_c14;
        case 0xc18u: goto label_c18;
        case 0xc1cu: goto label_c1c;
        case 0xc20u: goto label_c20;
        case 0xc24u: goto label_c24;
        case 0xc28u: goto label_c28;
        case 0xc2cu: goto label_c2c;
        case 0xc30u: goto label_c30;
        default: break;
    }

    ctx->pc = 0xc00u;

label_c00:
    // 0xc00: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_c04:
    // 0xc04: 0x8c420fe4  lw          $v0, 0xFE4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4068)));
label_c08:
    // 0xc08: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_c0c:
    // 0xc0c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_c10:
    if (ctx->pc == 0xC10u) {
        // 0xc10: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        ctx->pc = 0xC14u;
        goto label_c14;
    }
    ctx->pc = 0xC0Cu;
    {
        const bool branch_taken_0xc0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xc10: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0xc0c) {
            ctx->pc = 0xC1Cu;
            goto label_c1c;
        }
    }
    ctx->pc = 0xC14u;
label_c14:
    // 0xc14: 0x8000309  j           func_000C24
label_c18:
    if (ctx->pc == 0xC18u) {
        // 0xc18: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xC1Cu;
        goto label_c1c;
    }
    ctx->pc = 0xC14u;
    // 0xc18: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0xC24u;
    goto label_c24;
    ctx->pc = 0xC1Cu;
label_c1c:
    // 0xc1c: 0x40f809  jalr        $v0
label_c20:
    if (ctx->pc == 0xC20u) {
        ctx->pc = 0xC24u;
        goto label_c24;
    }
    ctx->pc = 0xC1Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0xC24u);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xC1Cu, 0xC24u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xC24u;
label_c24:
    // 0xc24: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_c28:
    // 0xc28: 0x0  nop
    // NOP
label_c2c:
    // 0xc2c: 0x3e00008  jr          $ra
label_c30:
    if (ctx->pc == 0xC30u) {
        // 0xc30: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0xC34u;
        goto label_fallthrough_0xc2c;
    }
    ctx->pc = 0xC2Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc30: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC2Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
label_fallthrough_0xc2c:
    ctx->pc = 0xC34u;
}


// Function: sio2man_00000c34
// Address: 0xc34 - 0xd94
void sio2man_00000c34_0xc34(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000c34_0xc34");
#endif

    switch (ctx->pc) {
        case 0xc34u: goto label_c34;
        case 0xc38u: goto label_c38;
        case 0xc3cu: goto label_c3c;
        case 0xc40u: goto label_c40;
        case 0xc44u: goto label_c44;
        case 0xc48u: goto label_c48;
        case 0xc4cu: goto label_c4c;
        case 0xc50u: goto label_c50;
        case 0xc54u: goto label_c54;
        case 0xc58u: goto label_c58;
        case 0xc5cu: goto label_c5c;
        case 0xc60u: goto label_c60;
        case 0xc64u: goto label_c64;
        case 0xc68u: goto label_c68;
        case 0xc6cu: goto label_c6c;
        case 0xc70u: goto label_c70;
        case 0xc74u: goto label_c74;
        case 0xc78u: goto label_c78;
        case 0xc7cu: goto label_c7c;
        case 0xc80u: goto label_c80;
        case 0xc84u: goto label_c84;
        case 0xc88u: goto label_c88;
        case 0xc8cu: goto label_c8c;
        case 0xc90u: goto label_c90;
        case 0xc94u: goto label_c94;
        case 0xc98u: goto label_c98;
        case 0xc9cu: goto label_c9c;
        case 0xca0u: goto label_ca0;
        case 0xca4u: goto label_ca4;
        case 0xca8u: goto label_ca8;
        case 0xcacu: goto label_cac;
        case 0xcb0u: goto label_cb0;
        case 0xcb4u: goto label_cb4;
        case 0xcb8u: goto label_cb8;
        case 0xcbcu: goto label_cbc;
        case 0xcc0u: goto label_cc0;
        case 0xcc4u: goto label_cc4;
        case 0xcc8u: goto label_cc8;
        case 0xcccu: goto label_ccc;
        case 0xcd0u: goto label_cd0;
        case 0xcd4u: goto label_cd4;
        case 0xcd8u: goto label_cd8;
        case 0xcdcu: goto label_cdc;
        case 0xce0u: goto label_ce0;
        case 0xce4u: goto label_ce4;
        case 0xce8u: goto label_ce8;
        case 0xcecu: goto label_cec;
        case 0xcf0u: goto label_cf0;
        case 0xcf4u: goto label_cf4;
        case 0xcf8u: goto label_cf8;
        case 0xcfcu: goto label_cfc;
        case 0xd00u: goto label_d00;
        case 0xd04u: goto label_d04;
        case 0xd08u: goto label_d08;
        case 0xd0cu: goto label_d0c;
        case 0xd10u: goto label_d10;
        case 0xd14u: goto label_d14;
        case 0xd18u: goto label_d18;
        case 0xd1cu: goto label_d1c;
        case 0xd20u: goto label_d20;
        case 0xd24u: goto label_d24;
        case 0xd28u: goto label_d28;
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
        default: break;
    }

    ctx->pc = 0xc34u;

label_c34:
    // 0xc34: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_c38:
    // 0xc38: 0x8c420fe8  lw          $v0, 0xFE8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4072)));
label_c3c:
    // 0xc3c: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_c40:
    // 0xc40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_c44:
    if (ctx->pc == 0xC44u) {
        // 0xc44: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        ctx->pc = 0xC48u;
        goto label_c48;
    }
    ctx->pc = 0xC40u;
    {
        const bool branch_taken_0xc40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc44: 0xafbf0010  sw          $ra, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
        if (branch_taken_0xc40) {
            ctx->pc = 0xC50u;
            goto label_c50;
        }
    }
    ctx->pc = 0xC48u;
label_c48:
    // 0xc48: 0x40f809  jalr        $v0
label_c4c:
    if (ctx->pc == 0xC4Cu) {
        ctx->pc = 0xC50u;
        goto label_c50;
    }
    ctx->pc = 0xC48u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0xC50u);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xC48u, 0xC50u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0xC50u;
label_c50:
    // 0xc50: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_c54:
    // 0xc54: 0x0  nop
    // NOP
label_c58:
    // 0xc58: 0x3e00008  jr          $ra
label_c5c:
    if (ctx->pc == 0xC5Cu) {
        // 0xc5c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0xC60u;
        goto label_c60;
    }
    ctx->pc = 0xC58u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc5c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC58u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC60u;
label_c60:
    // 0xc60: 0x41c00000  .word       0x41C00000                   # INVALID     $t6, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xE at 0xC60 raw=0x41C00000");
label_c64:
    // 0xc64: 0x0  nop
    // NOP
label_c68:
    // 0xc68: 0x204  .word       0x00000204                   # sllv        $zero, $zero, $zero # 00000200 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_c6c:
    // 0xc6c: 0x326f6973  andi        $t7, $s3, 0x6973
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)26995);
label_c70:
    // 0xc70: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
label_c74:
    // 0xc74: 0x634  teq         $zero, $zero, 24
    ctx->pc = 0xc74u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_c78:
    // 0xc78: 0xd78  dsll        $at, $zero, 21
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << 21);
label_c7c:
    // 0xc7c: 0x81c  .word       0x0000081C                   # dmult       $zero, $zero # 00000800 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xC7C raw=0x0000081C");
label_c80:
    // 0xc80: 0xd78  dsll        $at, $zero, 21
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << 21);
label_c84:
    // 0xc84: 0x0  nop
    // NOP
label_c88:
    // 0xc88: 0x14  dsllv       $zero, $zero, $zero
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_c8c:
    // 0xc8c: 0x28  mfsa        $zero
    SET_GPR_U32(ctx, 0, ctx->sa);
label_c90:
    // 0xc90: 0x3c  dsll32      $zero, $zero, 0
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (32 + 0));
label_c94:
    // 0xc94: 0x54  .word       0x00000054                   # dsllv       $zero, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_c98:
    // 0xc98: 0x6c  .word       0x0000006C                   # dadd        $zero, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0xc98u;
    { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 0, r); }
label_c9c:
    // 0xc9c: 0x84  .word       0x00000084                   # sllv        $zero, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_ca0:
    // 0xca0: 0x9c  .word       0x0000009C                   # dmult       $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xCA0 raw=0x0000009C");
label_ca4:
    // 0xca4: 0xb0  tge         $zero, $zero, 2
    ctx->pc = 0xca4u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_ca8:
    // 0xca8: 0xc8  .word       0x000000C8                   # jr          $zero # 000000C0 <InstrIdType: CPU_SPECIAL>
label_cac:
    if (ctx->pc == 0xCACu) {
        ctx->pc = 0xCACu;
        ctx->in_delay_slot = true;
        ctx->branch_pc = 0xCA8u;
        // 0xcac: 0xe0  .word       0x000000E0                   # add         $zero, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 0, (int32_t)result);     } }
        ctx->in_delay_slot = false;
        ctx->pc = 0xCB0u;
        goto label_cb0;
    }
    ctx->pc = 0xCA8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        ctx->pc = 0xCACu;
        ctx->in_delay_slot = true;
        ctx->branch_pc = 0xCA8u;
        // 0xcac: 0xe0  .word       0x000000E0                   # add         $zero, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 0, (int32_t)result);     } }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xCA8u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0xCB0u;
label_cb0:
    // 0xcb0: 0xf4  teq         $zero, $zero, 3
    ctx->pc = 0xcb0u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_cb4:
    // 0xcb4: 0x108  .word       0x00000108                   # jr          $zero # 00000100 <InstrIdType: CPU_SPECIAL>
label_cb8:
    if (ctx->pc == 0xCB8u) {
        // 0xcb8: 0x11c  .word       0x0000011C                   # dmult       $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xCB8 raw=0x0000011C");
        ctx->pc = 0xCBCu;
        goto label_cbc;
    }
    ctx->pc = 0xCB4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        // 0xcb8: 0x11c  .word       0x0000011C                   # dmult       $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xCB8 raw=0x0000011C");
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xCB4u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0xCBCu;
label_cbc:
    // 0xcbc: 0x130  tge         $zero, $zero, 4
    ctx->pc = 0xcbcu;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_cc0:
    // 0xcc0: 0x144  .word       0x00000144                   # sllv        $zero, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_cc4:
    // 0xcc4: 0x154  .word       0x00000154                   # dsllv       $zero, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_cc8:
    // 0xcc8: 0x164  .word       0x00000164                   # and         $zero, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_ccc:
    // 0xccc: 0x178  dsll        $zero, $zero, 5
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << 5);
label_cd0:
    // 0xcd0: 0x904  .word       0x00000904                   # sllv        $at, $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 1, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_cd4:
    // 0xcd4: 0x954  .word       0x00000954                   # dsllv       $at, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_cd8:
    // 0xcd8: 0xa94  .word       0x00000A94                   # dsllv       $at, $zero, $zero # 00000280 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_cdc:
    // 0xcdc: 0xaec  .word       0x00000AEC                   # dadd        $at, $zero, $zero # 000002C0 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0xcdcu;
    { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 1, r); }
label_ce0:
    // 0xce0: 0x0  nop
    // NOP
label_ce4:
    // 0xce4: 0x14  dsllv       $zero, $zero, $zero
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_ce8:
    // 0xce8: 0x28  mfsa        $zero
    SET_GPR_U32(ctx, 0, ctx->sa);
label_cec:
    // 0xcec: 0x3c  dsll32      $zero, $zero, 0
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (32 + 0));
label_cf0:
    // 0xcf0: 0x54  .word       0x00000054                   # dsllv       $zero, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_cf4:
    // 0xcf4: 0x6c  .word       0x0000006C                   # dadd        $zero, $zero, $zero # 00000040 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0xcf4u;
    { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 0, r); }
label_cf8:
    // 0xcf8: 0x84  .word       0x00000084                   # sllv        $zero, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_cfc:
    // 0xcfc: 0x9c  .word       0x0000009C                   # dmult       $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xCFC raw=0x0000009C");
label_d00:
    // 0xd00: 0xb0  tge         $zero, $zero, 2
    ctx->pc = 0xd00u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d04:
    // 0xd04: 0xc8  .word       0x000000C8                   # jr          $zero # 000000C0 <InstrIdType: CPU_SPECIAL>
label_d08:
    if (ctx->pc == 0xD08u) {
        ctx->pc = 0xD08u;
        ctx->in_delay_slot = true;
        ctx->branch_pc = 0xD04u;
        // 0xd08: 0xe0  .word       0x000000E0                   # add         $zero, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 0, (int32_t)result);     } }
        ctx->in_delay_slot = false;
        ctx->pc = 0xD0Cu;
        goto label_d0c;
    }
    ctx->pc = 0xD04u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        ctx->pc = 0xD08u;
        ctx->in_delay_slot = true;
        ctx->branch_pc = 0xD04u;
        // 0xd08: 0xe0  .word       0x000000E0                   # add         $zero, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        {     int32_t rs_val = GPR_S32(ctx, 0);     int32_t rt_val = GPR_S32(ctx, 0);     int64_t result = (int64_t)rs_val + (int64_t)rt_val;     if (result > INT32_MAX || result < INT32_MIN) {         runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW);     } else {         SET_GPR_S32(ctx, 0, (int32_t)result);     } }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xD04u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0xD0Cu;
label_d0c:
    // 0xd0c: 0xf4  teq         $zero, $zero, 3
    ctx->pc = 0xd0cu;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d10:
    // 0xd10: 0x108  .word       0x00000108                   # jr          $zero # 00000100 <InstrIdType: CPU_SPECIAL>
label_d14:
    if (ctx->pc == 0xD14u) {
        // 0xd14: 0x11c  .word       0x0000011C                   # dmult       $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xD14 raw=0x0000011C");
        ctx->pc = 0xD18u;
        goto label_d18;
    }
    ctx->pc = 0xD10u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 0);
        // 0xd14: 0x11c  .word       0x0000011C                   # dmult       $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL> (Delay Slot)
        throw std::runtime_error("Unhandled SPECIAL instruction: 0x1C at 0xD14 raw=0x0000011C");
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0xD10u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0xD18u;
label_d18:
    // 0xd18: 0x130  tge         $zero, $zero, 4
    ctx->pc = 0xd18u;
    if (GPR_S64(ctx, 0) >= GPR_S64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d1c:
    // 0xd1c: 0x144  .word       0x00000144                   # sllv        $zero, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 0, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_d20:
    // 0xd20: 0x154  .word       0x00000154                   # dsllv       $zero, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_d24:
    // 0xd24: 0x164  .word       0x00000164                   # and         $zero, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_d28:
    // 0xd28: 0x178  dsll        $zero, $zero, 5
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) << 5);
label_d2c:
    // 0xd2c: 0x904  .word       0x00000904                   # sllv        $at, $zero, $zero # 00000100 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 1, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_d30:
    // 0xd30: 0x954  .word       0x00000954                   # dsllv       $at, $zero, $zero # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_d34:
    // 0xd34: 0x9a4  .word       0x000009A4                   # and         $at, $zero, $zero # 00000180 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_d38:
    // 0xd38: 0x9f4  teq         $zero, $zero, 39
    ctx->pc = 0xd38u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d3c:
    // 0xd3c: 0xa44  .word       0x00000A44                   # sllv        $at, $zero, $zero # 00000240 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 1, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_d40:
    // 0xd40: 0xa94  .word       0x00000A94                   # dsllv       $at, $zero, $zero # 00000280 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_d44:
    // 0xd44: 0xaec  .word       0x00000AEC                   # dadd        $at, $zero, $zero # 000002C0 <InstrIdType: CPU_SPECIAL>
    ctx->pc = 0xd44u;
    { int64_t a = (int64_t)GPR_S64(ctx, 0); int64_t b = (int64_t)GPR_S64(ctx, 0); int64_t r = a + b; if (((a ^ b) >= 0) && ((a ^ r) < 0)) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 1, r); }
label_d48:
    // 0xd48: 0xb14  .word       0x00000B14                   # dsllv       $at, $zero, $zero # 00000300 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_d4c:
    // 0xd4c: 0xb24  .word       0x00000B24                   # and         $at, $zero, $zero # 00000300 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_d50:
    // 0xd50: 0xb34  teq         $zero, $zero, 44
    ctx->pc = 0xd50u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d54:
    // 0xd54: 0xb44  .word       0x00000B44                   # sllv        $at, $zero, $zero # 00000340 <InstrIdType: CPU_SPECIAL>
    SET_GPR_S32(ctx, 1, (int32_t)SLL32(GPR_U32(ctx, 0), GPR_U32(ctx, 0) & 0x1F));
label_d58:
    // 0xd58: 0xb54  .word       0x00000B54                   # dsllv       $at, $zero, $zero # 00000340 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_d5c:
    // 0xd5c: 0xbcc  syscall     47
    ctx->pc = 0xd5cu;
    runtime->handleSyscall(rdram, ctx, 0x2Fu);
label_d60:
    // 0xd60: 0xc00  sll         $at, $zero, 16
    SET_GPR_S32(ctx, 1, (int32_t)SLL32(GPR_U32(ctx, 0), 16));
label_d64:
    // 0xd64: 0xc34  teq         $zero, $zero, 48
    ctx->pc = 0xd64u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d68:
    // 0xd68: 0x874  teq         $zero, $zero, 33
    ctx->pc = 0xd68u;
    if (GPR_U64(ctx, 0) == GPR_U64(ctx, 0)) { runtime->handleTrap(rdram, ctx); }
label_d6c:
    // 0xd6c: 0x8d4  .word       0x000008D4                   # dsllv       $at, $zero, $zero # 000000C0 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) << (GPR_U32(ctx, 0) & 0x3F));
label_d70:
    // 0xd70: 0x8a4  .word       0x000008A4                   # and         $at, $zero, $zero # 00000080 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) & GPR_U64(ctx, 0));
label_d74:
    // 0xd74: 0x0  nop
    // NOP
label_d78:
    // 0xd78: 0x3e00008  jr          $ra
label_d7c:
    if (ctx->pc == 0xD7Cu) {
        ctx->pc = 0xD80u;
        goto label_d80;
    }
    ctx->pc = 0xD78u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xD78u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xD80u;
label_d80:
    // 0xd80: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0xD80 raw=0x41E00000");
label_d84:
    // 0xd84: 0x0  nop
    // NOP
label_d88:
    // 0xd88: 0x103  sra         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, SRA32(GPR_S32(ctx, 0), 4));
label_d8c:
    // 0xd8c: 0x64616f6c  daddiu      $at, $v1, 0x6F6C
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0xD8C raw=0x64616F6C");
label_d90:
    // 0xd90: 0x65726f63  daddiu      $s2, $t3, 0x6F63
    throw std::runtime_error("R5900-only instruction in an R3000 build at 0xD90 raw=0x65726F63");
}


// Function: sio2man_00000d94
// Address: 0xd94 - 0xdb8
void sio2man_00000d94_0xd94(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000d94_0xd94");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: sio2man_00000db8
// Address: 0xdb8 - 0xdc0
void sio2man_00000db8_0xdb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000db8_0xdb8");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 4u);
}


// Function: sio2man_00000dc0
// Address: 0xdc0 - 0xdc8
void sio2man_00000dc0_0xdc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000dc0_0xdc0");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 5u);
}


// Function: sio2man_00000dc8
// Address: 0xdc8 - 0xdd0
void sio2man_00000dc8_0xdc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000dc8_0xdc8");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 6u);
}


// Function: sio2man_00000dd0
// Address: 0xdd0 - 0xdd8
void sio2man_00000dd0_0xdd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000dd0_0xdd0");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 7u);
}


// Function: sio2man_00000dd8
// Address: 0xdd8 - 0xde0
void sio2man_00000dd8_0xdd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000dd8_0xdd8");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: sio2man_00000de0
// Address: 0xde0 - 0xe04
void sio2man_00000de0_0xde0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000de0_0xde0");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: sio2man_00000e04
// Address: 0xe04 - 0xe28
void sio2man_00000e04_0xe04(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e04_0xe04");
#endif

    runtime->iopImport(rdram, ctx, "stdio", 4u);
}


// Function: sio2man_00000e28
// Address: 0xe28 - 0xe30
void sio2man_00000e28_0xe28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e28_0xe28");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 28u);
}


// Function: sio2man_00000e30
// Address: 0xe30 - 0xe38
void sio2man_00000e30_0xe30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e30_0xe30");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 32u);
}


// Function: sio2man_00000e38
// Address: 0xe38 - 0xe40
void sio2man_00000e38_0xe38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e38_0xe38");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 33u);
}


// Function: sio2man_00000e40
// Address: 0xe40 - 0xe48
void sio2man_00000e40_0xe40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e40_0xe40");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 34u);
}


// Function: sio2man_00000e48
// Address: 0xe48 - 0xe6c
void sio2man_00000e48_0xe48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e48_0xe48");
#endif

    runtime->iopImport(rdram, ctx, "dmacman", 35u);
}


// Function: sio2man_00000e6c
// Address: 0xe6c - 0xe74
void sio2man_00000e6c_0xe6c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e6c_0xe6c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 4u);
}


// Function: sio2man_00000e74
// Address: 0xe74 - 0xe7c
void sio2man_00000e74_0xe74(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e74_0xe74");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 6u);
}


// Function: sio2man_00000e7c
// Address: 0xe7c - 0xea0
void sio2man_00000e7c_0xe7c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000e7c_0xe7c");
#endif

    runtime->iopImport(rdram, ctx, "thbase", 20u);
}


// Function: sio2man_00000ea0
// Address: 0xea0 - 0xea8
void sio2man_00000ea0_0xea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000ea0_0xea0");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 4u);
}


// Function: sio2man_00000ea8
// Address: 0xea8 - 0xeb0
void sio2man_00000ea8_0xea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000ea8_0xea8");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 6u);
}


// Function: sio2man_00000eb0
// Address: 0xeb0 - 0xeb8
void sio2man_00000eb0_0xeb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000eb0_0xeb0");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 7u);
}


// Function: sio2man_00000eb8
// Address: 0xeb8 - 0xec0
void sio2man_00000eb8_0xeb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000eb8_0xeb8");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 8u);
}


// Function: sio2man_00000ec0
// Address: 0xec0 - 0xee4
void sio2man_00000ec0_0xec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000ec0_0xec0");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 10u);
}


// Function: sio2man_00000ee4
// Address: 0xee4 - 0xeec
void sio2man_00000ee4_0xee4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000ee4_0xee4");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 4u);
}


// Function: sio2man_00000eec
// Address: 0xeec - 0xef4
void sio2man_00000eec_0xeec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000eec_0xeec");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 6u);
}


// Function: sio2man_00000ef4
// Address: 0xef4 - 0xefc
void sio2man_00000ef4_0xef4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000ef4_0xef4");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 8u);
}


// Function: sio2man_00000efc
// Address: 0xefc - 0xf20
void sio2man_00000efc_0xefc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000efc_0xefc");
#endif

    runtime->iopImport(rdram, ctx, "thsemap", 11u);
}


// Function: sio2man_00000f20
// Address: 0xf20 - 0xf28
void sio2man_00000f20_0xf20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000f20_0xf20");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 8u);
}


// Function: sio2man_00000f28
// Address: 0xf28 - 0xf30
void sio2man_00000f28_0xf28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sio2man_00000f28_0xf28");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 29u);
}


