# Config Low-Spec BT3-Recomp (draft 2026-09-05)

## Objetivo
30fps sostenidos en iGPU débil: Ryzen 3250U (Vega 3, 3 CUs), Intel UHD, Adreno/Mali.

## Preset implementado: PS2X_LOWSPEC (main.cpp)
Aplicado DESPUÉS del bloque de defaults. Respeta env vars explícitas del usuario.

### Level 1 (seguro, recomendado) — efectos opcionales OFF
| Var | Valor | Efecto |
|-----|-------|--------|
| PS2X_RENDERSCALE | 1 | Resolución nativa PS2 512x448 (la palanca VRAM/GPU #1) |
| PS2X_TEXCACHEMB | 32 | Cache de texturas decodificadas 32MB (vs 64 default) |
| PS2X_NODEPTH_RT | 1 | FBOs solo color (sin depth renderbuffer) |
| PS2X_OUTLINE | 0 | Sin cel outline |
| PS2X_SHADOWS | 0 | Sin sombras de personaje |
| PS2X_DOFMASK | 0 | Sin DoF blur |
| PS2X_POSTFX | 0 | Sin post-FX |
| PS2X_GLOWFIX | 0 | Sin bloom/aura Kaioken |
| PS2X_GPUALIAS | 0 | Sin cadena outline GPU-side |

### Level 2 (=2) — más agresivo, costo en corrección
| Var | Valor | Efecto |
|-----|-------|--------|
| PS2X_GPU_DEPTH | 0 | Z-test OFF (proven 2D path) — rompe orden por profundidad |

### Correctness-critical (se mantienen ON)
PS2X_BARRIER=1, PS2X_BARBLOCK=1, PS2X_SCHED=1, PS2X_DRAWBATCH=1,
PS2X_BARSKIP="502,504,368" (default), PS2X_RBSPLIT=1 (glFinish-antes-read).

## Uso
```bash
PS2X_LOWSPEC=1 ./build/ps2xRuntime/ps2EntryRunner games/bt3/work/SLUS_216.78
# o el script:
./launch_bt3_lowspec.sh
```

## Investigación PBO — CONCLUSIÓN (2026-09-05)
PBO double-buffered readback fue investigado y RECHAZADO para el path de barriers
bloqueantes (BARBLOCK=1, default):
- El guest thread BLOQUEA hasta que el writeback a VRAM termina (g_bbCv.notify_all).
- No se puede diferir el glMapBuffer sin agregar latencia de 1 frame (= BARBLOCK=0).
- El código ya evalúa y documenta esto en ps2_gs_gpu_renderer.cpp:17270
  ("the one-frame latency a PBO path would have anyway").
- El glFinish()-antes-glReadPixels (PS2X_RBSPLIT) ya es el patrón óptimo para este path
  (redujo ~20ms -> ~5.5ms por readback).
- El solape DMA_A-over-render_B dentro del drenaje empeora el pickup del guest.

Los 70+ glReadPixels restantes son: diagnósticos, probes 1px, y paths opcionales
(WRITEBACK, ZWB, replay). No son el hot path del combate.

## Próximos levers REALES (si LOWSPEC no alcanza 30fps)
1. PS2X_BARSKIP extendido (agregar 224 = máscara; riesgo: pierde ink del outline)
2. PS2X_GPU=0 (software renderer multihilo)
3. Reducir barriers por diseño: servir más lecturas GPU->GPU (P8TWIN/IDXRT ya hacen parte)
