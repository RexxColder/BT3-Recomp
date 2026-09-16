# Removing raylib from the video path

Branch: `OpenGL-Test`. Goal: the game's video path (window/context, GS replay, overlay, FMV) runs
on our own layers -- `ps2x::gfx::gl` for OpenGL and `ps2x::gfx::d3d11` for D3D11 -- with **no
raylib/rlgl**. `docs/ALTGL-PRESENT-STATUS.md` covers the present (already migrated).

## Why the first attempt was dropped

A `rg*` indirection layer that renamed rlgl calls without changing their bodies was tried and
rejected: it removed **no** dependency, only churned 315 call sites. Renaming is not migration.

## The constraint that sets the order

raylib's drawing helpers are welded to `InitWindow`: `BeginTextureMode`/`EndTextureMode`/
`BeginDrawing`/`ClearBackground`/`scissor` read and write `CORE.Window` (`rcore.c:1104-1127`,
`1164-1178`), which is zero without `InitWindow`. `rlgl` itself **is** standalone
(`rlglInit(w,h)` + `rlLoadExtensions(getProc)`), and `LoadShader`/`SetShaderValue*`/
`LoadTextureFromImage`/`DrawTexturePro` only need rlgl/CPU.

So the platform cannot be swapped first while raylib still draws; the drawing must move first.
Chosen order is therefore **replay first, platform last**.

## Target platform

**SDL2** (already linked into `ps2_runtime` for the host audio/pad layers) so the same GL path
works on Windows and Linux. raylib's `LoadImage` stays until stage A4, where it is implemented
and disconnected.

## Stages (each keeps the game rendering and is A/B-able)

Flag: `PS2X_GSBACKEND=gl` selects the gfx::gl replay backend; default stays rlgl until a stage is
verified.

| Stage | Scope | Status |
|-------|-------|--------|
| A1 base | shared `gfx::gl` context (`gl_context`) + `GsTexture`/`GsRenderTarget` resources | done (`2b5b565`, `5a3c4dd`) |
| A1.1 | convert the replay's render-target/texture call sites (`LoadRenderTexture` 24, `Begin/EndTextureMode` 22/21, `UpdateTexture` 11, `SetTextureFilter` 18, `DrawTexturePro` 12) to `GsRenderTarget`/`GsTexture` | in progress |
| A2 | shaders: `LoadShader` / `BeginShaderMode` / `SetShaderValue*` (81) → `gfx::gl::Shader` by name | pending |
| A3 | immediate-mode submit: `rlBegin/End` (13) + `rlVertex*` (58) + `rlTexCoord2f` (49) + `rlColor4ub` (16) + `rlSetTexture` (25) → `gfx::gl::Renderer` **with own batching** (the rlgl `vbring` patch is a perf feature; batching is not optional) | pending |
| A4 | CPU/text: `LoadImageFromTexture`/`ExportImage`/`LoadImage` → own loader; `DrawText`/font | pending |
| B | platform: SDL2 window + GL 3.3 core + swap + input + timing; delete `InitWindow` and every `CORE.Window`-dependent call | pending |
| C | overlay: `imgui_impl_opengl3` + `imgui_impl_sdl2` (drop rlImGui) | pending |
| D | FMV / utilities → `gfx::gl` + own file IO | pending |
| E | remove `raylib` from `CMakeLists.txt` (and the `vbring` patch) | pending |

## Guardrails learned this session

- **Never touch GL with raw calls while rlgl is alive** without re-asserting rlgl's cached state
  through rlgl's own APIs. rlgl only re-applies what it thinks changed, so a raw
  `glDisable(GL_BLEND)` left the rlImGui overlay drawing with blending off (every glyph an opaque
  block). This is exactly why the replay must eventually stop sharing the context with rlgl.
- The **altGL present is the reference implementation** of how to use `gfx::gl` (context, shader
  compile with dual-source outputs, texture adopt/sampler, orthogonal mapping, restoring raylib's
  state afterwards).
- Uniform setters must run with their program bound (`gfx::gl::Shader::Set*` auto-binds).

## Verification per stage

1. `ps2xGlProbe` still passes.
2. Deploy: boot screen → overlay (legible text) → a 3D fight, compared against the previous build.
3. `[fps]` not worse than the current baseline (~60 fps menus, ~24-30 fps fights).
4. A/B screenshots via `PS2X_SHOT_DIR`.

## How the deploy is launched (for verification)

```powershell
$env:PS2X_D3D11="0"; $env:PS2X_ALTGL="1"; $env:PS2X_GPU="1"
$env:PS2X_EXEDIR="D:\Dragon Ball Budokai Tenkaichi 3 Recompiled"
$env:PS2X_ASSETDIR="$env:PS2X_EXEDIR\assets"
& "$env:PS2X_EXEDIR\bt3-runner.exe" "$env:PS2X_EXEDIR\data\SLUS_216.78"
```

Success line: `[altgl] present init ok (GL 3.3.0 Core ...)`.
