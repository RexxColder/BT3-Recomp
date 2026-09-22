# Backup point — before the raylib-removal plan

This commit is the **backup point** taken BEFORE the raylib-removal plan (Claude's S1–S8). It is
kept so the plan can be reverted to a known-good state in one step.

## State at this point

- `main` on top of `787cf65`:
  - `138bf8f` — PR #23 merged (launcher/audio/boot work).
  - `b041b86` — `.gitattributes`: shell scripts stay **LF** (WSL / Docker / Linux).
  - `787cf65` — CMake guard: **skip an incomplete paraLLEl-GS checkout** instead of failing the
    configure (a half-initialised submodule, missing `Granite/third_party/volk/volk.c`, used to
    hard-fail the generate step).
- Rendering: **OpenGL path** (`renderer = "opengl"`) is the working default. The game runs and the
  in-game settings overlay opens. paraLLEl-GS is built but its shipped default
  (`scripts/settings.toml.default` → `renderer = "parallel-gs"`) initialises Vulkan and crashes
  inside `amdvlk64.dll` on this machine.

## What was reverted from here

The raylib-removal work — S1/S2/S7 (`gsrl` routing, `AltGlPresent` default ON, elapsed-time),
the overlay-crash fix (`UiEnd` flushed a null rlgl batch), the `[ovldbg]` tracing and the session
log — was **discarded**: the branch that held it (`raylib-plan-wip`) has been deleted.

Reason for reverting: **S1 (`gsrl` dual-rlgl-stack routing) is not viable** — with the vendored
`gsrl` initialised it still crashes (`memcpy` from a null vertex buffer inside the vendored rlgl)
and shows a black screen, matching the dual-stack hazard documented in
`docs/ALTGL-RAYLIB-REMOVAL.md`.

## Restoring

No longer possible: the branch `raylib-plan-wip` was deleted, so that work is gone. The tag
`backup-pre-raylib-plan` on `1d4f45e` still marks this point, so `main` can be reset back to it.
