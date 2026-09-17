#pragma once

// [R1] Include this AFTER raylib's rlgl.h (and any other raylib header) in the TUs that emit the GS
// replay: every rl* call below the include is redirected to the vendored rlgl copy (gsrl), so the
// replay's geometry is submitted by code that IS rlgl instead of a lookalike. Calls that manage
// raylib-owned objects are deliberately NOT redirected and keep hitting raylib:
//   rlLoadTexture, rlLoadTextureDepth, rlUnloadTexture, rlLoadFramebuffer, rlUnloadFramebuffer,
//   rlFramebufferAttach, rlFramebufferComplete, rlActiveDrawBuffers, rlReadTexturePixels,
//   rlClearColor, rlClearScreenBuffers, rlGetShaderIdDefault, rlGetShaderLocsDefault, rlSetShader.

#include "gfx/gl/gsrl.h"

// [R1] DORMANT by default: with raylib vendored 1:1 the replay submits through the vendored rlgl with
// its original names, which is one single GL state owner (no mirroring, no dual batches). Build with
// -DPS2X_USE_GSRL=1 (CMake option PS2X_USE_GSRL) to route it through the renamed copy instead, for A/B.
#if defined(PS2X_USE_GSRL)

#define rlBegin                  gsrlBegin
#define rlEnd                    gsrlEnd
#define rlVertex2f               gsrlVertex2f
#define rlVertex3f               gsrlVertex3f
#define rlTexCoord2f             gsrlTexCoord2f
#define rlColor4ub               gsrlColor4ub
#define rlNormal3f               gsrlNormal3f
#define rlCheckRenderBatchLimit  gsrlCheckRenderBatchLimit

#define rlDrawRenderBatchActive  ps2x::gfx::gsrl::DrawRenderBatchActive
#define rlSetTexture             ps2x::gfx::gsrl::SetTexture
#define rlColorMask              ps2x::gfx::gsrl::ColorMask
#define rlSetBlendMode           ps2x::gfx::gsrl::SetBlendMode
#define rlSetBlendFactors        ps2x::gfx::gsrl::SetBlendFactors
#define rlSetBlendFactorsSeparate ps2x::gfx::gsrl::SetBlendFactorsSeparate
#define rlEnableColorBlend       ps2x::gfx::gsrl::EnableColorBlend
#define rlDisableColorBlend      ps2x::gfx::gsrl::DisableColorBlend
#define rlEnableScissorTest      ps2x::gfx::gsrl::EnableScissorTest
#define rlDisableScissorTest     ps2x::gfx::gsrl::DisableScissorTest
#define rlScissor                ps2x::gfx::gsrl::Scissor
#define rlEnableDepthTest        ps2x::gfx::gsrl::EnableDepthTest
#define rlDisableDepthTest       ps2x::gfx::gsrl::DisableDepthTest
#define rlEnableDepthMask        ps2x::gfx::gsrl::EnableDepthMask
#define rlDisableDepthMask       ps2x::gfx::gsrl::DisableDepthMask
#define rlEnableBackfaceCulling  ps2x::gfx::gsrl::EnableBackfaceCulling
#define rlDisableBackfaceCulling ps2x::gfx::gsrl::DisableBackfaceCulling
#define rlTextureParameters      ps2x::gfx::gsrl::TextureParameters
#define rlScalef                 ps2x::gfx::gsrl::Scalef
#define rlTranslatef             ps2x::gfx::gsrl::Translatef
#define rlOrtho                  ps2x::gfx::gsrl::Ortho
#define rlMatrixMode             ps2x::gfx::gsrl::MatrixMode
#define rlLoadIdentity           ps2x::gfx::gsrl::LoadIdentity
#define rlViewport               ps2x::gfx::gsrl::Viewport
#define rlSetFramebufferWidth    ps2x::gfx::gsrl::SetFramebufferWidth
#define rlSetFramebufferHeight   ps2x::gfx::gsrl::SetFramebufferHeight
#define rlEnableFramebuffer      ps2x::gfx::gsrl::EnableFramebuffer
#define rlDisableFramebuffer     ps2x::gfx::gsrl::DisableFramebuffer

#endif   // PS2X_USE_GSRL

