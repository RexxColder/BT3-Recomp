# 2-core / low-core experiments -- hardware, tests and results (DISCARDED)

> **Status: discarded.** The low-core ("2-core mode") work was reverted to the backup point
> (`1d4f45e`, tag `backup-pre-raylib-plan`). This document keeps the record: what was tested, on
> which hardware, and what it measured, so the experiment is not repeated blindly.
> The discarded code itself is preserved in the branch **`wip-2core-experiments`** (tip `3fd8773`),
> not on `main`.

## 1. Hardware

| role | machine | notes |
|---|---|---|
| **target** | **AMD Ryzen 3 3250U** -- 2 cores / 4 threads (Zen+, Vega 3 iGPU), 4 GB target class | the low-end box the whole effort was for |
| **simulation** | AMD Ryzen 5 5500 -- 6c/12t (Zen 3) | pinned to 2 logical CPUs with the Windows **processor affinity mask** to imitate a 2-core host; `hardware_concurrency()` still reports 12, so the pool counts were forced explicitly |

Affinity masks on the 5500 (logical-processor map: core0 = LP0,LP1; core1 = LP2,LP3; ...):

| mask | CPUs | means |
|---|---|---|
| `0x3` | LP0 + LP1 | **1 physical core / 2 threads** (two SMT siblings) -- a *fake* 2-core, and the reason an early run looked terrible |
| `0x5` | LP0 + LP2 | **2 physical cores / 2 threads** (the faithful 2c/2t sim) |
| `0xF` | LP0..LP3 | 2 cores / 4 threads (2c/4t sim) |

## 2. Test setup

- Renderer **OpenGL** (`renderer = "opengl"`), `render_scale = 1`, 1024x768, windowed.
- Diagnostics **all on** during a capture (opt-in env, so a normal run stays quiet):
  `PS2X_FRAMEPROF=1 PS2X_FTSPIKE=1 PS2X_GUESTPROF=1 PS2X_EEPROF=1 PS2X_RAGSTAT=1 PS2X_BARSTAT=1
  PS2X_STATEDBG=1 PS2X_DECPOOLSTAT=1 PS2X_VU1PIPESTAT=1 PS2X_THREADLOG=1`.
- Metric: **fps = 1000 / `loop_ms`** from the `[frameprof]` 1-second windows (**p50** over the run);
  stutter = `[ftspike]` counts of frames over 40/50/80 ms. Same combat scene, a few minutes per run.
- Note: the diagnostics add overhead, so these numbers are a **lower bound**; A and B carry the same
  overhead, so the A-vs-B delta is still meaningful.

Configs compared (engine defaults = "config A"):

| tag | delta from A |
|---|---|
| **A** | none -- engine defaults (decode pool 2, async kick on, two-stage VU1 pipe on) |
| **B** | low-core recommendations: `PS2X_DECPOOL=0 PS2X_ASYNC_KICK=0 PS2X_VU1PIPE=0 PS2X_RASTER_THREADS=0` |
| **A-nolim** | `PS2X_TARGETFPS=0` (raylib frame limiter off) |
| **A-s1gl** | `PS2X_S1FENCE=gl` (stage-1 SyncPath fence for the OpenGL presenter) |
| **A-kick4** | `PS2X_KICKQ_FRAMES=4` (raise the kick-queue frame depth from 2) |

## 3. Results

### Ryzen 3 3250U (2c/4t, real target) -- combat

| config | **fps p50** | fps mean | loop p50 (ms) | frames >50 ms | >80 ms |
|---|---|---|---|---|---|
| **A** (default) | **32.7** | 38.6 | 30.6 | 583 | 114 |
| **B** (all inline) | **48.3** | 50.7 | 20.8 | 104 | 2 |
| A-nolim | 36.6 | -- | 27.3 | 1191 | 66 |
| A-s1gl | 33.8 | 37.7 | 29.8 | 412 | 72 |
| A-kick4 | 33.0 | 38.4 | 30.3 | 665 | 146 |

### Ryzen 5 5500, affinity-pinned (simulation)

| pin | config | fps p50 | loop p50 (ms) |
|---|---|---|---|
| `0x3` (1 core / 2 threads) | A | 19.9 | 50.4 |
| `0x5` (2 cores / 2 threads) | A | 59.2 (at the 60 cap) | 16.9 |

`0x3` vs `0x5` is the reason the first "2-core" readout was worthless: LP0+LP1 are the two SMT
siblings of a single physical core, not two cores.

## 4. What the numbers said

- **B measured fastest (+15.6 fps) but was rejected on feel** -- with every stage inline the
  pipeline is gone, so input-to-display latency goes up; A (pipelined) is the better-playing run.
  **A stays the default.**
- **No lever that keeps A reached the +8 fps target.** A-nolim +3.9 (with 2x the >50 ms stutter),
  A-s1gl +1.1, A-kick4 0.
- `PS2X_S1FENCE=gl` **worked mechanically** -- `fence_syncpath` 345 -> 55, `kick_drain` 346 -> 67,
  `stage2_idle` 223 -> 0 ms/s -- and **cut stutter** (>50 ms 583 -> 412, >80 ms 114 -> 72), but the
  wait simply moved to `kickq_frames` (0 -> 236) / `worker_idle` / `sched_yield`. **The drain was
  not on the critical path.**
- Raising the kick-queue depth did nothing: `kickq_frames` was not the throttle either.
- Overall the frame is ~30 ms of *work* while the process uses only ~1.2 of 4 logical CPUs, and the
  KickWorker sits ~50-60 % idle. The two-stage pipeline **adds latency without giving
  parallelism** on a 2-core host. That is the cost, and it is structural, not a missing tweak.

## 5. Decision

- **2 cores / 4 threads is the supported MINIMUM, and it is NOT recommended.** Real use on such a
  box is about **15-18 fps**, with visible stutter.
- The "2-core mode" (config B, and the low-core auto-profile idea) is **discarded**: on the target
  the pipeline work it removes is what the box actually needs, and it plays worse than the default
  despite the higher fps.
- Default remains the engine default (config A), i.e. the pipelined configuration.
