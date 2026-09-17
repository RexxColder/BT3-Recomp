# Vendored raylib

Verbatim copy of raylib's `src/` tree, so the BT3-Recomp runtime no longer depends on the raylib
library (FetchContent, patch step and library target are gone from CMake).

| | |
|---|---|
| Upstream | https://github.com/raysan5/raylib |
| Version | 5.5 |
| Commit | c1ab645ca298a2801097931d1079b10ff7eb9df8 |
| Licence | zlib (see `LICENSE`) |
| Patched | yes — `ps2xRuntime/patches/raylib-5.5-ps2x.patch` is ALREADY APPLIED to this copy (`rlgl.h`: vbring persistent-mapped vertex ring + the GS shader; `config.h`) |
| Copied | the whole `src/` including `src/external/` (glad, stb, glfw, dr_*, miniaudio, …) |

## What is compiled

`src/rcore.c` (it also contains rlgl's implementation, as in upstream 5.5 — `rlgl.c` does not exist
in 5.5), `src/rshapes.c`, `src/rtextures.c`, `src/rtext.c`, `src/raudio.c` and `src/utils.c`.
`rmodels.c` is the only module left out (unused).

## Local changes to this copy

- **None in the code.** It is byte-for-byte upstream + the ps2x patch.

## Pruned after the SDL2 switch (2026-09-17)

The window/input/GL-context now come from SDL2 (`PLATFORM_DESKTOP_SDL`), so GLFW is not built and
`src/external/glfw/` was deleted (2.86 MB). Also deleted, all unused by the compiled modules:
`external/glad_gles2.h`, `external/m3d.h`, `external/par_shapes.h`, `external/cgltf.h`,
`external/tinyobj_loader_c.h`, `external/vox_loader.h`, `external/RGFW.h`.

`external/stb_perlin.h` was pruned by mistake and restored: `rtextures.c` includes it (noise
textures). The authoritative keep-list is the set of `#include "external/..."` lines in the five
compiled `.c` files.

