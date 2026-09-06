# ESTATUS — Proyecto TEST ENTRY (BT3-Recomp)

> Última actualización: 2026-09-03 12:42

## Contexto
Objetivo: añadir una entrada "TEST ENTRY" al menú principal del port nativo PC de
Dragon Ball Z Budokai Tenkaichi 3 (BT3-Recomp, basado en PS2Recomp).

## Estado actual

### ✅ Completado
- [x] Investigación del modding de BT3 (menú + settings) — reporte completo.
- [x] TEST ENTRY en Settings (overlay ImGui) — implementado y compilado.
- [x] Identificación del estado del menú principal = 0x4.
- [x] Decodificación del menú (jump table 0x3B4290, 9 entries; cursor *(0x3b38e8)+0x128).
- [x] Hook del cursor del menú (`bt3MenuEntryHook` en f_3549f8 → g_bt3MenuCursorLive).
- [x] Análisis de la ROM Wii — jump table del menú Wii localizada (18 slots vs 9 PS2).
- [x] Inventario completo de netplay Wii (no portable a PS2).
- [x] Assets de menú extraídos: `wzs3eu0.afs` → 10 archivos (3 formatos Spike).
- [x] **Entry nativa implementada**: validación 9→10, nuevo case en switch, handler stub, jump table runtime patch.
- [x] **BUILD EXITOSO**: `ps2EntryRunner` (131MB, ELF x86-64), sin errores de compilación.

### 🔄 En progreso / Pendiente
- [ ] **Test runtime**: ejecutar con `PS2X_TESTENTRY=1` y verificar log `[netplay] Menu entry 9 selected!`.
- [ ] Interactividad del handler (detectar botón X → acción).
- [ ] Placa visual de la entry (raylib overlay con posición dinámica).
- [ ] Pack de texturas HD (option B: usuario descarga de anibalturek).
- [ ] Análisis DOL Wii con Ghidra.

## Cambios de código realizados

### overlay_functions.cpp (dispatcher f_34d468)
1. **L102992**: `9` → `10` en comparación `sltiu` (validación de cursor).
2. **L103036**: `case 0x351500u: goto label_351500;` en switch de dispatch.
3. **L103043-103048**: `label_351500:` handler stub + `goto label_3514cc`.

### game_overrides.cpp (hook bt3MenuEntryHook)
1. **L3116-3128**: one-shot escribe `0x351500` a PS2 RAM `0x3B42B4` (jump table slot 9).

## Build
- **Fecha**: 2026-09-03 12:42
- **Binario**: `build/ps2xRuntime/ps2EntryRunner` (131MB, ELF x86-64, debug_info)
- **Configuración**: `-j$(nproc)` sin unity build, mold linker, ccache
- **Resultado**: ✅ OK (0 errores compilación)
- **Para ejecutar**: `PS2X_TESTENTRY=1 ./build/ps2xRuntime/ps2EntryRunner`

## Siguiente paso
1. Ejecutar el binario y verificar que la 10ª entrada aparece y el handler responde.
2. Añadir interactividad al handler (abrir settings, cambiar estado, etc.).
3. Dibujar placa visual para la entry.

## Referencias
- Reporte completo: `BT3-modding-menu-y-settings.md` (Escritorio).
- Repo: `/home/rexx/Escritorio/BT3-Recomp/`
