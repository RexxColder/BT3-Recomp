# BT3-Recomp - TODO

## 2026-09-06: Input per-player (launcher Qt + savedata/pad_pN.conf)

### Completo
- [x] Runtime: numeración gamepad unificada launcher<->runtime (`padGamepadSlot`/`padGamepadIndex`).
- [x] Launcher Qt tabs Bindings/Controllers; guardado por jugador en `savedata/pad_p1.conf` y `pad_p2.conf`.
- [x] Layout por defecto por teclado para P1/P2 al elegir Keyboard (`applyDefaultKeyboardBinds`), binds de pad al elegir Gamepad; `onDeviceChanged`/`onLoadDefaults` consistentes, crash de tab ordering corregido.
- [x] L2/R2 guardados como `Axis 4/5` por el capturador: ruta `PadBindKind::Axis` en el button loop + fallback nativo a `GAMEPAD_BUTTON_LEFT/RIGHT_TRIGGER_2` → **gatillos funcionan** (verificado por usuario).
- [x] Leak sticks P1→P2: rediseñado el acceso al singleton `PadEvdevLinux` (native = "Gamepad 0" del launcher, name-match y `pads.empty()`); `slotValue()` ya NO inyecta el nativo → cada player lee SU slot GLFW. Commit `HEAD`.

### BUG PENDIENTE (próximo a resolver): **sticks ya no leen nada**
- Síntoma (validado en run por el usuario): con P1=Gamepad 0, P2=Keyboard, **RT/LT (gatillos) funcionan pero los 4 sticks dan 0** (P1 no mueve el personaje).
- Regresión parcial introducida al quitar la inyección nativa de `slotValue()`.
- Datos de diagnóstico disponibles:
  - Triggers funcionan por el branch `Axis` del button loop (fallback nativo `native.isButtonDown(4/5→10/12)`), lo que sugiere que **GLFW no expone el Xbox como gamepad** (`IsGamepadAvailable` false → `padGamepadSlot` → -1 → `pads` está vacío para P1).
  - Con `pads` vacío, los sticks dependen del fallback del final de `poll()`:
    `if (kind==Gamepad && gamepad==0 && pads.empty() && native.isAvailable())` → `native.getAxis(0..3)`.
- Hipótesis por verificar (en orden):
  1. Que `cfg.device.gamepad` persistido por el launcher sea realmente `0` (si persiste índice GLFW crudo o -1, la gate `gamepad==0` no entra).
  2. Que `native.isAvailable()` siga siendo true en el `poll()` del guest (triggers lo sugieren, pero hay que confirmarlo en la misma ruta).
  3. Si (1)(2) OK: revisar que `native.getAxis(GAMEPAD_AXIS_LEFT_X..RIGHT_Y)` (0..3) devuelva valores (m_absCode ABS_X..ABS_RY) — antes este path le daba a P2 los sticks de P1, es decir SÍ producía valores.
- Próximo diagnóstico: relanzar con `PS2X_PADLOG=1` + `PS2X_PAD_EVDEV=/dev/input/event38` e instrumentar `poll()` (cuál rama llena lx/ly/rx/ry). No cerrar hasta que sticks de P1 lean del nativo/GLFW sin filtrar a P2.

---

## Estado: Pausado (2026-09-04), retomado el 2026-09-04 tarde

### Completado
- [x] Fresh clone from upstream 329ef38
- [x] Recomp runner funciona con SLUS_216.78 (bt3state=0x1)
- [x] Slot 16 fix aplicado
- [x] 13+ patches binarios en DBZP.BIN (todos verificados)
- [x] ISO parcheada (BT3_patched.iso)
- [x] Análisis completo del menú principal
- [x] AFL file descargado (PZS3US1.AFL)
- [x] PCSX2 instalado y funcionando
- [x] Actualización del repo a upstream f47c19d (35 commits) + merge de logging local
- [x] Verificado en run: transición 0x01→0x04 es natural (skip INTRO innecesario, revertido)
- [x] Identificada la entry oculta Network Battle (skip index 0x335568, cheat 00335568 000000FF)
- [x] Verificado: f_334ca0 no se ejecuta en estado 0x04 del run (pregunta abierta)
- [x] Parche persistente aplicado: reveal de Network Battle ON por defecto (apply_overlay_patches.py + hook en setup.py)

### Pendiente
- [ ] **PROBAR EN RUNNER**: correr `ps2EntryRunner` y verificar si la entry "Network Battle" aparece y su textura carga o no (lewY `entry idx=4 reached plate-build` + `[sceCdRead] unresolved request` en el log)
- [ ] Modificar PZS3US1.AFS con AFS Explorer (requiere Windows/Wine)
- [ ] Reconstruir ISO y probar
- [ ] Localizar el call-site real de f_334ca0 (constructor de entries)
- [ ] Probar habilitar la entry oculta (patch 0xFF) en PCSX2 con cheat 00335568 000000FF

### Decisiones pendientes
- ¿Approach A (AFS Explorer) o Approach B (recomp runner)?
- ¿Agregar 10ma entry nueva o habilitar la oculta (Network Battle)?
- ¿Qué contenido tiene la entry?

---

## 2026-09-05: Deploy single-ELF self-extracting (Dragon Ball Budokai Tenkaichi 3)

### Completado
- [x] Copiado el formato del deploy previo (/home/rexx/Escritorio/Dragon Ball Budokai Tenkaichi 3/)
- [x] Restaurado `getExecutableDirectory()`/`setConfigDirectory()` en main.cpp (savedata/assets portables)
- [x] libzstd.a estático compilado (zstd-1.5.7 source)
- [x] Stub C self-extracting (stub.c) + footer BT3SELFX: extrae payload.zst a ~/.cache/bt3-recomp/<seed>
- [x] Payload: ps2EntryRunner (126 MiB) + lib/ (124 .so, 175 MiB) -> tar.zst 82 MiB -> ELF final 83 MiB
- [x] Estructura final junto al ELF: data/ (2.8 GiB, idéntica al deploy previo), savedata/, assets/fonts/
- [x] Fix bug zstd (contador doble -> truncamiento) y mkdirs recursivo
- [x] Probado: extracción 2ª corrida (cache hit), arranque completo del juego desde CWD ajeno
      (IRX + AFS resueltos desde data/), Windows title/"PS2X_EXEDIR" correctos
- [x] Verificación usuario: "te confirmo yo todo OK"
- [x] Reorganizado: saves movidos de data/mc0/BASLUS-21678DBZT3 a savedata/ (mcRoot parcheado
      en ps2_runtime.cpp a elfDirectory.parent_path()/savedata); data/mc0 y data/mc1 eliminados.
      Rebuild + re-empaquetado (seed 03ff4431a24375f7), deploy del Escritorio actualizado.

### Pendiente
- [ ] Colocar el deploy final en el Escritorio (ELF + data/ 2.8G + assets/fonts + savedata)
- [ ] (Opcional) Limpiar diag `[dragonnet-*]`/`[dndiag2]` del árbol cuando se cierre DRAGON_NET

### DRAGON_NET - Estado actualizado (el camino guest-side cambió)
- Modelo "state-4 gate" DESCARTADO: la zona 0x34dca8..0x3514cc NO corre en el main menu
  (0 diag con PS2X_ENABLE_DRAGONNET=1). Falta localizar el handler real de X del root menu
  antes de re-planificar.
- Setup host ready: `[dragonnet]` escribe flags 0x600 en 0x33408C cada heartbeat (PS2X_ENABLE_DRAGONNET).
- `0x336a90` = dispatcher bt3state en OVERLAY (f_336a90_0x336a90, overlay_functions.cpp ~6629).

---

## 2026-09-05: Optimización GPU-débil (Ryzen 3250U / Vega 3)

### Completado
- [x] Investigado cómo manejan GPUs débiles PCSX2/AetherSX2/Play!/RPCS3 (research web)
- [x] Análisis profundo del pipeline GPU de BT3-Recomp (70+ glReadPixels, barriers, uploads)
- [x] Conclusión PBO: RECHAZADO para barrier flush síncrono (ver lessons #21)
- [x] Preset `PS2X_LOWSPEC` implementado en main.cpp (level 1/2)
- [x] Script `launch_bt3_lowspec.sh`
- [x] Draft guardado en tasks/low-spec-config.md

### Pendiente
- [ ] Verificar build con LOWSPEC + smoke run
- [ ] (Opcional) Probar en hardware real 3250U y medir fps

## PS2X_PIN (affinity dual-core) — COMPLETADO 2026-09-05
- [x] Implementado PS2X_PIN en ps2_runtime.cpp: valores unset(auto)/0|none|off/A,B
- [x] Auto lee sched_getaffinity y detecta <=2 cores físicos (funciona bajo taskset/container)
- [x] Pin de Game thread -> core A y GL/present -> core B via pthread_setaffinity_np (linux-only)
- [x] Warning si A,B comparten core físico (trampa SMT {0,2})
- [x] Keeper de sesión completa re-aplica si GLFW/Mesa/cgroup limpia la máscara
- [x] Build EXIT=0; prueba de 2 min (PS2X_PIN=0,1): r1=r2=0, máscaras main={1} game={0}
     en 25/25 muestras; 3 re-pines del keeper; sin crash (EXIT=124)
- [x] Baseline 2 min sin pin: estado final idéntico (bt3state=0x27) -> sin regresión
- [ ] Probar en hardware real 3250U y medir fps (auto debería pinear {0,1} o {0,2}+{1,3})

### Revisión (2026-09-05)
- El pin funciona a nivel OS (verificado via /proc y strace), no solo en logs.
- La deriva de affinity es externa (no hay otro codigo de affinity en el repo).
- Mapa de estados bt3state (corregido por el usuario): 0x01=boot, 0x04=main menus
  /2D menus, 0x27=fighting / gameplay 3D completo.
- Ambos runs de 2 min (pin y baseline) alcanzaron bt3state=0x27 = gameplay 3D real:
  el juego completa boot y llega a combate con y sin pin -> sin regresión y con
  arranque completo. El estado que yo llame "clavado" era gameplay activo.
