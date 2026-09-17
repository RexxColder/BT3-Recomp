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
in 5.5), `src/rshapes.c`, `src/rtextures.c`, `src/utils.c`. Nothing else — `rmodels.c`, `raudio.c`
and `rtext.c` are unused by the runtime and are compiled out.

The files are kept byte-for-byte identical to upstream: any local special-case would live in our own
code, never in this copy.
