# Native D3D11 video port — status, findings & theories

Branch: `feat/d3d11-native` (fork `RexxColder/BT3-Recomp`).

Goal: replace the raylib/OpenGL video path with **native Direct3D 11** — first the
*present* (device + swap chain + overlay), then the **GS replay itself**. raylib stays
only for the window, input and audio. The native GS replay is **opt-in**.

## How to build / run

Build (Windows, clang-cl + Ninja):

```
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
set PATH=C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\Llvm\x64\bin;%PATH%
cmake --build D:\Proyecto\build --target ps2EntryRunner -j 6
```

Run (PowerShell):

```
$env:PS2X_D3D11="1"        # native D3D11 present (device + swap chain)
$env:PS2X_D3D11_GS="1"     # native GS replay (WIP — see "Broken"); omit for the working path
$env:PS2X_GPU="1"
$env:PS2X_PGS="0"
$env:PS2X_CD_IMAGE="D:\DragonBall Z - Budokai Tenkaichi 3 (USA) (En,Ja).iso"
& D:\Proyecto\build\ps2xRuntime\ps2EntryRunner.exe D:\Proyecto\games\bt3\work\SLUS_216.78
```

Useful env flags added for this work:
`PS2X_D3DDUMP=1` (write the native present RT to PNG every ~600 frames),
`PS2X_TRIDBG=1` (draw-path tracing), `PS2X_FMVDBG=1`, `PS2X_PGS`/`PS2X_GPU`.

## What WORKS (proven)

* D3D11 device + DXGI **flip-model** swap chain bound to raylib's `HWND`; discard fallback.
* ImGui overlay via `imgui_impl_dx11` (kept working while GL owns the window/input).
* **Native D3D present of the game frame with the GL replay** — the DEFAULT with
  `PS2X_D3D11=1` and NO `PS2X_D3D11_GS`. The GS still renders through GL; pixels reach
  the D3D swap chain. **Confirmed by A/B: this renders correctly, including the 3D fight.**
* Native GS replay (`PS2X_D3D11_GS=1`) so far renders: 2D/HUD, menus, character select,
  map select (incl. its 3D stage background), the memory-card screen, and (partially) FMV.
* Front-latch removed the frame flicker; the D3D FBOs are **bind-only** (no per-frame clear),
  mirroring the GL accumulate.

## What is BROKEN

* **Native replay (`PS2X_D3D11_GS=1`): the FIGHT 3D scene is black** (the 2D HUD still shows).
* Native replay: **FMV intro flickers** (partially mitigated, not fixed).

## The A/B result (key)

* `PS2X_D3D11_GS=0` (GL replay + D3D present) → **3D renders fine** ("funciono bien").
* `PS2X_D3D11_GS=1` (native replay) → **3D black**.

=> The fault is in the **native replay**, not in the emulator or the D3D present.

## Why the native replay is black — gaps vs. the GL path

The native replay was built by *mirroring GL state* (`glGet*`) and only implements the
`quadA` sprite and triangle draws. The GL path additionally executes several **command
classes** that build the scene's auxiliary buffers, and the native path does NOT:

1. **View routing** — `d3dGsPrepDest()` keys only on `curRealFbp`. GL routes draws by
   `viewKey(destFbp, destPsm, destFbw)` because BT3 re-views the same address at different
   bit depths (e.g. fbp0 as CT32 *and* as a 512x896 CT16 surface). Native draws can land in
   the wrong RT (immediate suspect for the fight).
2. **Auxiliary command classes** (`ps2_gs_gpu_renderer.cpp`), none implemented in D3D:
   * `isVramBlit` (VRAM page → FBO) — **implemented this session** (`d3dGsBlitVram`).
   * `isTransfer` (VRAM→VRAM replayed as FBO→FBO blit) — NOT done.
   * `isAliasPass` (Z16 rebuild / untextured clear / P8H edge) — NOT done.
   * `isDecode` (deferred texture decode) — NOT done.
   * `depthOnly` (software colour + GPU Z companion) — NOT done.
3. **Software-outline brackets** (`swOutlineBegin/End`): BT3 draws the character cel/outline
   pass as sub-pixel sliver triangles that GL's fill rule drops, so the GL path hands those
   pages to the **software rasterizer** and re-injects via `isVramBlit`. The native path never
   runs those brackets → missing character cel/outline.
4. **Alpha swizzle**: GL forces `GL_TEXTURE_SWIZZLE_A = ONE` for TCC=0 / FBO sources; the D3D
   mirror textures do not carry that swizzle.
5. **Depth is NOT the cause**: `PS2X_GPU_DEPTH` defaults OFF, so the GL path renders the 3D
   *without* depth too. (PCSX2's DX11 uses real depth-stencil, but we do not need it first.)

## Fixes applied this session (uncommitted at the time of writing)

* `PS2X_BARBLOCK` forced OFF in native-video mode (it stalled the guest → stuttering audio /
  half-rate frames), and `GetShaderLocation` results cached (they were a per-draw driver lookup
  doing ~23 string lookups on thousands of draws/frame).
* **Leak fix**: the D3D texture mirror (`g_d3dGsTex`) is now freed when the GL texture is
  evicted (`d3dGsFreeTex`). Before this the process RSS grew ~15 MB/s.
* **GS CLAMP wrap** honored per draw in the D3D sampler (`Texture::SetSamplerUV`, REPEAT vs
  CLAMP per axis). Without it the stage/sky (REPEAT) collapsed to texel(0,0) → flat/black.
* **Indexed-RT CLUT**: the fight samples `fbp0` as a palette-indexed surface (`[idxrt]` →
  `uPal`). The native path now binds the 256x1 CLUT to `t1` (`d3dGsPalFor`, `Renderer::SetTexture1`).
* **`isVramBlit` native blit** (`d3dGsBlitVram`) — uploads the snapshot and composites RGB-only.
* Diagnostics: `gfx::ReadbackRGBA` + `GsGpuRenderer::d3dDumpPresent` (PNG of the native present
  RT) and the `PS2X_D3DDUMP` hook in `ps2_runtime.cpp`.

## Theories to test next (prioritized)

1. **View routing** in `d3dGsPrepDest` (route by `viewKey(destFbp, destPsm, destFbw)`), since
   the fight may be drawing into a view that the present never reads.
2. **`isAliasPass`**: the mask/outline/DoF chain could be emitting a black full-screen overlay
   that covers the arena before the HUD. Implementing it natively is the next likely fix.
3. **`swOutline`** software passes missing → black characters.
4. **FMV flicker**: looks tied to the double-buffered fbp0/fbp112 publish + latch selection.

## Next steps

1. Route native draws by view (`destPsm`/`destFbw`).
2. Implement `isAliasPass` / `isTransfer` / `isDecode` / `depthOnly` in the D3D path.
3. Either run the `swOutline` brackets natively or port the cel/outline passes.
4. FMV flicker after the 3D is fixed.

## Reference

* Existing native files: `ps2xRuntime/src/gfx/d3d11/D3D11Device.*`, `D3D11Gfx.*`,
  `gs_shader_hlsl.h`, `ui_d3d11.*`; `src/gfx/ps2x_ui.*`, `video_state.h`.
* All native GS hooks live in `ps2xRuntime/src/lib/ps2_gs_gpu_renderer.cpp`
  (`d3dGs*` helpers + the `#if defined(_WIN32)` draw branches).
* PCSX2's `GSDevice11` / `GSRendererHW` / `GSTextureCache` are the architectural reference:
  a real device with depth-stencil + blend states, and a texture cache resolving
  render-target↔texture feedback — not a GL state mirror.
