# bt3gl — vendored raylib

Verbatim copy of raylib's `src/` tree, so the BT3-Recomp runtime no longer depends on the raylib
library (FetchContent, patch step and library target are gone from CMake).

| | |
|---|---|
| Upstream | https://github.com/raysan5/raylib |
| Version | 5.5 |
| Commit | c1ab645ca298a2801097931d1079b10ff7eb9df8 |
| Licence | zlib (see `LICENSE`) |
| Patched | yes — `ps2xRuntime/patches/raylib-5.5-ps2x.patch` is ALREADY APPLIED to this copy (`rlgl.h`: vbring persistent-mapped vertex ring + the GS shader; `config.h`) |
| Copied | the whole `src/` including `src/external/` (glad, stb, dr_*, miniaudio, …) |

## Naming

The directory, the CMake target and its variable are **`bt3gl`** (`third_party/bt3gl`,
`add_library(bt3gl ...)`, `bt3gl_SOURCE_DIR`): the tree is ours, so it no longer carries the upstream
project name. Upstream mentions stay on purpose — they identify third-party artifacts, not our
module: the patch file `patches/raylib-5.5-ps2x.patch`, the provenance table above, the VitaSDK's own
raylib (`PS2X_VITA_PREFIX`), rlImGui's `Raylib_5_5` tag, and the `PS2X_HOSTPAD=raylib` /
`PS2X_HOSTAUDIO=raylib` runtime switches.

## What is compiled

`src/rcore.c` (it also contains rlgl's implementation, as in upstream 5.5 — `rlgl.c` does not exist
in 5.5), `src/rshapes.c`, `src/rtextures.c`, `src/rtext.c`, `src/raudio.c` and `src/utils.c`.
`rmodels.c` is the only module left out (unused).

## Local changes to this copy

- **None in the code.** It is byte-for-byte upstream + the ps2x patch.

## Pruned (2026-09-17)

Unused by the compiled modules:

- After the SDL2 switch: `src/external/glfw/` (2.86 MB, the window/input/GL context come from SDL2 via
  `PLATFORM_DESKTOP_SDL`), `external/glad_gles2.h`, `external/m3d.h`, `external/par_shapes.h`,
  `external/cgltf.h`, `external/tinyobj_loader_c.h`, `external/vox_loader.h`, `external/RGFW.h`.
- Upstream-only build/asset/other-platform files: `Makefile`, `CMakeLists.txt`, `shell.html`,
  `minshell.html`, `rglfw.c`, the `.rc`/`.ico` resources, `rmodels.c`, the platform backends other
  than SDL (`rcore_android.c`, `rcore_desktop_glfw.c`, `rcore_desktop_rgfw.c`, `rcore_drm.c`,
  `rcore_template.c`, `rcore_web.c`) and `external/win32_clipboard.h`.

`external/stb_perlin.h` was pruned by mistake and restored: `rtextures.c` includes it (noise
textures). The authoritative keep-list is the set of `#include "external/..."` lines in the compiled
`.c` files (plus `glad.h`, which `rlgl.h` needs).


