# Performance metrics (user reports)

Reported measurements per renderer / per upscale, kept so the performance work has real targets and
baselines. The wording is the users'; "good" / "fluid" are theirs.

---

## Linux — Ryzen 3 3200G (Vega 8, 2 GB VRAM) + 8 GB RAM — Kubuntu 24.04 LTS

Monitor maximum resolution.

| renderer | window x1 | fullscreen x1 | window x2 | fullscreen x2 | window x3 | fullscreen x3 |
|---|---|---|---|---|---|---|
| **Vulkan** | good, fluid (30/60) | good, slightly less fluid | bad in combat | worse | menus slower, <=10 fps or freeze | menus slower, <=10 fps or freeze |
| **OpenGL** | better than Vulkan at every upscale (only slightly worse at x3 in splitscreen) | | | | | |
| **Software** | very slow | | | | | |

- With the **HD 2D textures**: a bit slower on Vulkan; no change on OpenGL.
- **OpenGL**'s only problem here: frames momentarily freeze (one could say it pauses) and then it
  comes back.
- **Software**: very slow, and it shows a weird purple screen before starting.

## Windows — 1080p @ 2x vs 720p @ 1x
> Performance was AWFUL on 1080p 2x res. It works amazingly good on 720p 1x res.

---

## To measure locally

Target machine for a new performance pass:

| part | model |
|---|---|
| CPU | Intel **Core i5-4440S** (4c/4t, Haswell) |
| RAM | **2 x 8 GB DDR3-1600** (16 GB) |
| GPU | **ASUS GeForce GT 1030 2 GB GDDR5** |

Record: fps at 1x and 2x, whether the bottleneck is CPU or GPU, the `[frameprof]` / `[ftspike]`
picture, and the thread/contention numbers on a real 4c/4t box.

---

## Windows - Ryzen 5 5500 + Radeon RX 580 8 GB (2026-09)

Measured with the shipped front-end-less boot (`<exe> data/SLUS_216.78`), reading the
`[fps]` counters the runtime prints. 1360x768 borderless.

| renderer | render_scale | fps60 | GAME fps | note |
|---|---|---|---|---|
| OpenGL (New) | 3 | on | **4.9 - 8.8** | `glhoist/sec=0`, `vu1pairs/sec=0`, `swaps/sec=0` |
| OpenGL (New) | 3 | on | 4.9 - 10.8 | same numbers with `data/` flattened |

Observations, so the next pass does not re-derive them:

- `wall_ms` is 15-50x `guest_ms` per frame while `gpu_ms` stays at ~1.7 ms: the GPU is
  not the bottleneck, the host-side pipeline is. `glhoist/sec=0` together with
  `glcalls/sec=54` says the GS draw list is not reaching the GL layer at all, and
  `vu1pairs/sec=0` says the VU1 stage is idle while the guest waits.
- The `RECOMMENDADO` tier writes `render_scale = 3` and `fps60 = true` for this CPU
  (bench R ~1.0 -> "Balanced"). On the OpenGL path that combination is well past what the
  host can drive; it is a tiering problem, not a regression.
- Flattening `data/` was measured and ruled out as the cause: 6.8-8.8 fps on the disc
  layout versus 4.9-10.8 flattened, same binary family, same ballpark. See DEPLOY.md.
- `PS2X_FE_*` aside, the useful knobs for a quick win are `render_scale` (1 before 3) and
  `video.fps60` (off before on), plus trying `renderer = "parallel-gs"`.
