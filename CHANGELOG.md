# BT3-Recomp — Changelog de Cambios

## Resumen

Recompilador estático de Dragon Ball Z: Budokai Tenkaichi 3 para PC, basado en PS2Recomp. Este documento lista los cambios del overlay de configuración, mixer de audio y mejoras del runtime.

---

## 1. Settings Overlay (reemplaza Debug Panel)

**Archivos creados:**
- `ps2xRuntime/src/lib/ps2_settings_overlay.cpp`
- `ps2xRuntime/include/ps2_settings_overlay.h`

**Archivos eliminados (legacy debug panel):**
- `ps2xRuntime/src/lib/ps2_debug_panel.cpp`
- `ps2xRuntime/include/ps2_debug_panel.h`

**Funcionalidad:**
- Overlay ImGui con tema Dragon Ball Z (naranja/dorado), invocado con **Shift+Tab** (teclado) o **Select+Start** (mando)
- Ventana de 960px con title bar custom, centrada, alto automático con scroll
- 4 tabs: **Audio**, **Video**, **Controllers**, **Logging**
- Toggle **F11** para alternar fullscreen/windowed
- **Close** button libera la suspensión de input (fix: antes el gamepad quedaba bloqueado)

---

## 2. Audio Mixer (por categorías)

**Archivos modificados:**
- `ps2xRuntime/src/lib/ps2_audio.cpp`
- `ps2xRuntime/include/runtime/ps2_audio.h`

**Cambios:**
- 3 sliders independientes: **Master**, **Music**, **SFX** (0-100%)
- **Music** = streams BGM estéreo (pares 0+1)
- **SFX** = streams mono (voces, efectos) + one-shots VAG
- Fórmula: `effective = masterVolume * categoryVolume`
- Aplicado en `serviceStreams()` (stereo y mono) y `playDecodedSample()`
- **Fix**: el slider ya no se vuelve binario (0/1) — se añadió `ImGuiSliderFlags_NoRoundToFormat`

---

## 3. Tab Video — Toggles de runtime

**Archivos modificados:**
- `ps2xRuntime/src/lib/ps2_gs_gpu_renderer.cpp`
- `ps2xRuntime/include/runtime/ps2_gs_gpu_renderer.h`

**Cambios:**
- 4 knobs ahora son toggleables en runtime desde el overlay (antes solo env vars):
  - **Bilinear Filter** (`PS2X_BILINEAR`)
  - **Half-Texel Correction** (`PS2X_HALFTEXEL`)
  - **Skip Post-Processing** (`PS2X_SKIPPOST`)
  - **Skip Stale VRAM** (`PS2X_SKIP_STALE_VRAM`)
- Las env vars siguen funcionando como defaults iniciales
- `glow` ahora es ON por defecto
- `fullscreen` ahora es ON por defecto

---

## 4. Tab Controllers

**Archivos modificados:**
- `ps2xRuntime/src/lib/ps2_settings_overlay.cpp`

**Cambios:**
- Secciones: **DEVICE**, **BINDINGS**, **GAMEPAD TEST**
- **Button Bindings** abre un popup modal con 2 tabs:
  - **Bindings**: tabla de 24 acciones con captura por teclado/botón/eje
  - **Overlay Settings**: configuración del combo de lanzamiento
- **Gamepad Test**: visualización en tiempo real — círculos de sticks, barras de triggers, grid de botones
- **Combo capture**: binding de 3 segundos — mantén el/los botón(es) o tecla(s) que quieras
  - Antes: 4 slots fijos (2 botones + 2 teclas)
  - Ahora: 2 slots flexibles (Gamepad Launch + Alt Launch), cada uno acepta 1+ inputs

---

## 5. Runtime — Ventana y Frame Pacing

**Archivos modificados:**
- `ps2xRuntime/src/lib/ps2_runtime.cpp`
- `ps2xRuntime/src/lib/Kernel/Syscalls/Interrupt.cpp`
- `ps2xRuntime/src/lib/Kernel/Syscalls/Interrupt.h`
- `ps2xRuntime/include/ps2_syscalls.h`

**Cambios:**
- Ventana del host: **1280x720** (antes 640x448) — overlay escala correctamente
- **Frame pacing**: presentar exactamente 1 vez por frame real del juego
  - GPU mode: `WaitForNewFrame` (condition variable sobre publishGen)
  - Software mode: `HostWaitForVsyncAdvance` (sobre el tick de vblank del guest)
- `FLAG_VSYNC_HINT` habilitado

---

## 6. Bugs corregidos

- **ImGui style stack crash**: `DbzThemeScope` push/pop 40 colores (antes push 40/pop 36, corrompía el stack)
- **Slider binario (0/1)**: `ImGuiSliderFlags_NoRoundToFormat` preserva la precisión float
- **Gamepad movía sliders**: `NavEnableGamepad` deshabilitado (raylib alimentaba ejes a ImGui)
- **Ghost window (A+X)**: `feedGamepadNav` eliminado — el gamepad ya no manipula la UI
- **Close button no liberaba input**: detección de transición `wasVisible -> !m_visible` + `setInputSuspended(false)`
- **ON/OFF ID conflict**: `PushID(label)` en `toggleSwitch`

---

## 7. Logging / Dump

**Archivos creados/modificados:**
- `ps2xRuntime/src/lib/ps2_settings_overlay.cpp`

**Cambios:**
- Tab **Logging** con checkboxes por área (Audio, Video, Controllers, Runtime, Gamepad Live)
- Botón **Dump Now** + dump automático en Apply/Save
- Escribe a `savedata/bt3_settings_dump.log` con timestamp

---

## 8. Performance Medido

| Escena | FPS (antes) | FPS (después) |
|--------|------------|---------------|
| Menús | 60 | 87-248 |
| Gameplay ligero | 18-21 | 38-52 |
| Gameplay pesado | 15-17 | 15-22 |
| Loading | 0 | 0-4 |

**Variables de entorno activas por defecto:**
```
PS2X_SKIPPOST=1
PS2X_SKIP_STALE_VRAM=1
PS2X_TEXCACHEMB=256
PS2X_TIMERMULT=8
```

---

## 9. Archivos de Configuración

- `bt3_settings.ini` — Generado en el directorio de trabajo del juego
  ```ini
  [audio]
  master_volume=1.0
  music_volume=1.0
  sfx_volume=1.0

  [video]
  gpu_renderer=1
  glow=1
  postfx=0
  bilinear=1
  halftexel=1
  skippost=1
  skip_stale_vram=1
  fullscreen=1
  widescreen=0

  [controllers]
  deadzone=0.15
  device=0
  overlay_pad_btns=13,15
  overlay_keys=340,258

  [logging]
  dump_audio=1
  dump_video=1
  dump_controllers=1
  dump_runtime=1
  dump_gamepad=0
  ```

---

## 10. Dependencias del Proyecto

- **raylib 5.5** — Rendering, ventana, audio, input
- **imgui** (docking branch) — UI del overlay
- **rlImGui** (Raylib_5.5) — Puente raylib↔imgui
- **FFmpeg** — avcodec, avformat, avutil, swresample, swscale
- **xone** driver (kernel) — Xbox One/Series X|S via USB/dongle