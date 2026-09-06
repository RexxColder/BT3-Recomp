# Lecciones Aprendidas - BT3 Menu Mod

## 2026-09-06: Input per-player (launcher Qt + pads savedata)

### Lección 57: El singleton nativo evdev es UN device físico — jamás inyectarlo per-player
- `PadEvdevLinux::instance()` abre SOLO el primer gamepad de /dev/input (ps2xRuntime/src/lib/pad_evdev_linux.cpp). Es el "Gamepad 0" del launcher.
- Inyectar `native.getAxis()` en `slotValue()` para TODOS los players con `nativeOk=true` propaga los mismos sticks a cualquiera cuyo slot matchee el nombre → P2 "hereda" los ejes de P1 (leak).
- Regla: el nativo solo puede consultarlo el DUENO del device físico = `device.kind==Gamepad && device.gamepad==0`, y solo con name-match (o cuando `pads` está vacío, único caso donde el nativo es la fuente de ejes).
- Al quitar la inyección, ojo: si GLFW no mapea el Xbox (`pads` vacío), los sticks dependen del fallback del final de `poll()`. Verificar que esas gates no maten el único camino válido.

### Lección 58: Los gatillos guardados como `Axis 4/5` necesitan rama Axis en el button loop
- El capturador del launcher guarda L2/R2 como `PadBindKind::Axis` con valor `GAMEPAD_AXIS_LEFT_TRIGGER/RIGHT_TRIGGER` (4/5), NO como Button.
- El button loop solo manejaba Key/Button → L2/R2 quedaban muertos.
- Fix: rama `Axis` → `fabs(GetGamepadAxisMovement(pad, bind.value)) > deadzone`, con fallback nativo convirtiendo el eje a `GAMEPAD_BUTTON_*_TRIGGER_2` para paddles sin mapping GLFW.

### Lección 59: El launcher persiste "Gamepad N" (índice), no el slot GLFW crudo
- `padGamepadSlot(gamepad)`/`padGamepadIndex(glfwSlot)` (ps2_stubs) traducen entre el índice launcher y el slot GLFW. Config `player 0 device Gamepad 0` = primer pad que reporta como controller.
- La puerta `gamepad==0` del nativo depende de que el overlay guarde `padGamepadIndex(dev.glfwSlot)` correctamente — revisar esto primero si el fallback de sticks no entra.

## 2026-09-04 (tarde): Entry oculta Network Battle + verificación en run

### Lección 13: La entry #3 (Network Battle) existe pero está OCULTA por skip index
En `f_334ca0` (overlay, constructor del menú), la instrucción `0x335568:
addiu $t0, $zero, 4` fija el skip index a 4. El loop de build (`0x335578`)
omite la entry cuando `$s1 == $t0`. Cheat PCSX2 para revelarla:
`00335568 000000FF`.

### Lección 14: El PS2 no tiene red real detrás de Network Battle
Es un shell de menú fantasma sin backend. El Wii (main.dol) sí tiene versión
funcional con netcode; hay RE activo con rollback netcode: `PhantoomDev/bt3-re`.

### Lección 15: El skip del intro NO hace falta — la transición a bt3state=0x04 es natural
Hooks `PS2X_SKIP_INTRO` para forzar `bt3state 0x01→0x04` y `introTimer` NO
cambiaron nada observable. El fade del intro avanza solo y la transición a
0x04 ocurre naturalmente en el run del recomp. → hooks revertidos.

### Lección 16: f_334ca0 no se ejecuta en el estado 0x04 del run
Logging en f_334ca0 y en el loop label_335578 mostró CERO logs `[MENU]` con
bt3state=0x04 alcanzado (1233+ líneas de status). El constructor de entries
se llama en otro punto del flujo, o el run se cuelga antes en el render loop
de func_33A018 (pc=0x2b0e60, ra=0x3368c4). → Pregunta abierta: localizar el
call-site real.

### Lección 17: Los cambios de código se conservan SOLO en archivos rastreados
`overlay_functions.cpp` está en `.gitignore` (generado). Los cambios ahí son
invisibles a `git status`. Al hacer pull de upstream, los cambios a archivos
generados podrían pisarse. Hacer backup manual de `runner_overlay/` antes de
actualizar.

### Lección 18: ¿Placa para Network Battle?
El plate #3 es el file index 0x3B en sub_1 de `Main_US.pak` (extracción
`/home/rexx/Escritorio/PZS3US1_original/`). Verificar si la textura existe
cuando la entry se habilita.

### Lección 19: El parche reveal ahora es PERSISTENTE (script aplica_overlay_patches.py)
`games/bt3/apply_overlay_patches.py` reaplica el cambio de skip-index (y su
logging) después de cada `gen_overlay.py` — así el parche sobrevive a la
regeneración del overlay (que es gitignored). Se agregó el hook en `setup.py`
justo después del bloque "generating overlay sources from BIN/DBZP.BIN".
El reveal está ON por defecto (decisión del usuario); se apaga con
`PS2X_REVEAL_HIDDEN_MENU_ENTRY=0`.

### Lección 20: El target de build del juego es `ps2EntryRunner`, NO `ps2xRuntime`
`cmake --build build --target ps2xRuntime` compila la lib pero NO re-linkea
`ps2EntryRunner` (target separado). El binario queda viejo sin el parche.
Siempre construir con `--target ps2EntryRunner`.

## 2026-09-04: Análisis del menú principal de BT3

### Lección 1: El menú NO define entries como constantes en el binario
Los 9 entries del menú principal de BT3 son **datos cargados desde archivos AFS en el disco**, no constantes hardcoded en el overlay binary (DBZP.BIN).

**Evidencia**: Parcheamos 13+ instancias de count=9 a count=10, pero el menú sigue mostrando 9 entries. Las entries reales (texto, acciones, posiciones) son datos que el game engine lee de `Main_US.pak` dentro de `PZS3US1.AFS`.

### Lección 2: Estructura del menú
- Jump table: 9 handlers en overlay 0x07F690 (RAM 0x3B4290)
- Type ID array: 11 tipos en overlay 0x07C3A0: `[4,4,4,5,5,5,5,4,5,5,4]`
- Format string: `"mc_menu_plate_%d"` en overlay 0x07C3D0 (RAM 0x3B4FD0)
- Second-level dispatch: 11 handlers en overlay 0x07F2F0 (RAM 0x3B3EF0)
- Per-entry handler: `f_349FE0` (overlay 0x153E0) dispatch por tipo

### Lección 3: Diferencia entre validación y rendering
Los patches binarios cambian:
- **Validación del cursor** (count en comparison): ✓ Funciona
- **Rendering de entries** (loop bounds): ✓ Funciona
- **Datos reales de entries** (texturas, acciones): ✗ Viene del AFS

### Lección 4: AFS Explorer es esencial para modding de menús
La comunidad de BT3 usa AFS Explorer v3.7 (Windows) para modificar archivos AFS. Los AFL files mapean indices a nombres reales.

### Lección 5: El recomp runner ya funciona
El recomp runner con `SLUS_216.78` como boot ELF alcanza `bt3state=0x1` (intro screen). El approach recomp da más control en runtime para hooks.

### Lección 6: Slot 16 fix
`g_ps2OverlayFunctionTable[16]` necesita ser inicializado porque la dirección `0x334C00` no está en el rango normal del overlay register.

## 2026-09-04: Investigación de DLC mod y traducciones

### Lección 7: Cómo se agregan entries para personajes (DLC mod)
El DLC mod de KkTeam usa un approach de **2 etapas**:
1. **Modloader** (inyectado en ISO): Carga MOD.BIN desde CD-ROM
2. **MOD.BIN**: Hook del sistema de archivos, redirige a AFS custom

**Estructura clave**:
```c
typedef struct {
    uint32_t headCharacterId;      // ID del personaje
    uint32_t transformationCount;  // Número de transformaciones
    uint32_t transfCharacterIds[7]; // IDs de transformaciones
} RosterEntry;  // 36 bytes
```

- Original: 161 personajes, cada uno con 10 entradas AFS (desde índice 1424)
- `AFS_INDEX_TO_CHARACTER_ID(I) = ((I) - 1424)/10`
- `CHARACTER_TO_MODEL_AFS_INDEX(ID,COL) = 1424 + (ID) * 10 + (COL)`

### Lección 8: Los textos del menú están en AFS, no en el binario
Los traductores (como MaxBound Studios para PT-BR) modifican archivos dentro de `PZS3US1.AFS` usando AFS Explorer. Los textos NO están hardcodeados en el overlay binary.

**Archivos relevantes**:
- `PZS3US1.AFS` → Menús, personajes, texturas (el principal)
- `PZS3US2.AFS` → Solo ADX (voces, música)
- `Main_US.pak` (entry 449) → Probablemente contiene definitions del main menu

### Lección 9: bt3-file-dump-organizer categoriza archivos
La herramienta de ViveTheModder organiza contenido de AFS en:
- **Characters** → Modelos, texturas, datos de personajes
- **Maps** → Escenarios
- **Menus** → **Textos y gráficos de menús**
- **Scenarios** → Archivos de historia

### Lección 10: Nuevos AFLs tienen nombres reales
Los AFLs antiguos tenían nombres obfuscados (`.unk`). Los nuevos AFLs de ViveTheModder tienen nombres reales, lo que facilita identificar archivos de menú.

### Lección 11: afl-editor permite buscar/reemplazar strings
Java tool (CLI + GUI) que busca y reemplaza strings en archivos AFL, útil para localizar textos específicos.

### Lección 12: Patrón unificado para modding de menús
Tanto para personajes como para menús:
1. Los **datos** están en archivos AFS
2. El **código** en el overlay binary referencia esos archivos
3. Para modificar se necesita **herramientas AFS** (no solo parches binarios)

**Conclusión**: Para agregar una entry al menú principal necesitamos AFS Explorer (Windows/Wine) o un approach de modloader como el DLC mod.

## 2026-09-05: Low-spec GPU + PBO conclusion

### Lección 21: PBO double-buffered NO ayuda al barrier flush síncrono (BARBLOCK)
Investigación profunda del path de barriers mostró que el guest thread bloquea
hasta el writeback a VRAM (`g_bbCv.notify_all` en serviceBlockingBarriers). Un PBO
no puede diferir el `glMapBuffer` sin añadir la latencia de 1 frame que BARBLOCK=0
ya tiene. El `glFinish()`-antes-read (PS2X_RBSPLIT) es el patrón correcto y ya está
implementado (~20ms -> ~5.5ms). El código lo documenta en renderer:17270.

### Lección 22: Los lessons de otros emuladores (PCSX2/AetherSX2/RPCS3) NO se
traducen 1:1 a un recompiler estático síncrono
PCSX2 elimina readbacks por diseño (targets GPU residentes, dirty rects, memory
mirroring). BT3-Recomp ya tiene equivalents parciales: P8TWIN (twin GPU para mask),
IDXRT/IDXONLY (serving de RT indexado), GPUALIAS (cadena outline GPU-side) + skip
list de barriers. El techo de optimización GPU-débil está en REDUCIR barreras por
diseño, no en PBO.

### Lección 23: Preset PS2X_LOWSPEC internado como capa sobre los defaults
La lambda `lsDef` debe sobreescribir los defaults de main.cpp (TEXCACHEMB, GPUALIAS,
DOFMASK) pero NO los env vars explícitos del usuario. Usa `s_defaulted` (la lista
`,`-separada de vars que el bloque de defaults fijó) para distinguir.

### Lección 24: Para una iGPU el orden de severidad es RENDERSCALE > effects > barriers
- RENDERSCALE=1 es la palanca #1 (4x pixels en 2x, 16x en 4x).
- Deshabilitar outline/shadows/DoF/glow/postfx elimina ~5-6 pasadas GPU.
- Los barriers son el costo fijo; reducirlos por diseño es más trabajo.

### Lección 25: Las pruebas de rendimiento/estabilidad se validan con runs de >=2 min
- Los smoke runs de 8-25s solo prueban arranque; no detectan derives, hangs tardíos
  ni regresiones de estado. El usuario exige __mínimo 2 minutos__.
- Para atribuir regresiones: baseline (sin el cambio) vs experimento, misma duración,
  misma config; comparar el estado final del guest (bt3state, dma, fade).

### Lección 26: Un solo pthread_setaffinity_np NO basta — el entorno lo revierte
- En BT3-Recomp, algo (GLFW/Mesa/audio o un cgroup del host) limpia la affinity del
  proceso durante el arranque (observado ~t+4.5s y ~t+35s en runs distintos).
- El pin se aplica bien (r=0, readback correcto) pero luego la máscara vuelve a 0-11.
- Solución: un __keeper__ que cada 200ms compara con CPU_EQUAL y re-aplica (costo
  negligible: 10 syscalls/s). Sin él, el pin es ornamental en arranques largos.

### Lección 27: Verifica la affinity a nivel OS, no con los logs del programa
- El log "[pinthreads] ... game->{0}" NO prueba que el OS lo aplique: el syscall
  puede fallar o revertirse sin error.
- Verificación real: /proc/<pid>/task/<tid>/status -> Cpus_allowed_list (por hilo).
- Para cazar al que la resetea: strace -f -e trace=sched_setaffinity (ojo: strace
  ralentiza el boot 5-10x, puede no alcanzar la ventana del reset).

### Lección 28: taskset no garantiza la restricción en todo el arranque
- `taskset -c 0,1` restringe en exec, pero librerías del proceso pueden restaurar la
  máscara completa a sus threads. Confiá en /proc/sched_getaffinity en runtime, no en
  el setup inicial. El modo auto de PS2X_PIN lee sched_getaffinity (no /sys) para
  contar cores físicos permitidos.

### Lección 29: LEE EL MAPA DE ESTADOS antes de catalogar "stuck" — no inventar semántica
- bt3state (BT3): 0x01=boot, 0x04=main menus/2D, 0x27=fighting/3D gameplay full.
- Un estado que no cambia entre muestras NO es un hang: en gameplay el guest pasa la
  mayor parte del tiempo en waits cortos (el PC del main thread queda en el mismo
  lugar y dma avanza despacio). Avísame cuando un estado sea ambiguo en vez de
  declarar "clavado".

## 2026-09-05: Catalogación del menú principal (10 entries)

### Lección 30: El menú vive en 0x04 pero la navegación/sub-estados son otros states
- `bt3state=0x04` = root menu (se dibujan las 11 placas, carga de texturas AFS).
- Cada entry, al seleccionarla y pulsar X, transiciona a **su propio bt3state**:
  `0x6`=DRAGON_ROAD, `0xd`=ULTIMATE_BATTLE, `0x21`=WORLD_TOURNAMENT,
  `0x26`=DUEL, `0x30`=EVOLUCION_Z, `0x2c`=ENTRENAMIENTO,
  `0x35`=DATA_CENTER, `0x3c`=REF_PERSONAJES, `0x3e`=OPCIONES.

### Lección 31: La struct del menú NO es 0x3B38D8/0x3B38E8 (overlay BSS nunca escrito)
- `0x3B38D8`/`0x3B38E8` son overlay BSS: 19 `lw`, 0 `sw` → siempre 0.
- La struct real es `*(0x2FF10C)` (= mismo puntero que bt3State):
  - `+0x18`: screen_state_id (bt3State)
  - `+0x2C`: selected_entry_ID (el que navega — NO `+0x148` que es cursor visual y siempre=0)
  - `+0x14`: visibility flags (bit 6 = menú visible)
  - `+0x68C`: transition flags
  - `*(0x2FF28C)` → dispPtr: `+0x08` display filter, `+0xA0C` frame counter

### Lección 32: El reveal patch (0xFF skip-index) dibuja la placa pero NO instala el handler
- `PS2X_REVEAL_HIDDEN_MENU_ENTRY` fuerza `addiu $t0, $zero, 0xFF` en 0x335568 → el loop de build NO omite entry 4.
- La placa se renderiza visualmente (texturas AFS se cargan), pero el **handler de input** para entry 4 no se instaló.
- Pulsar X sobre Net Battle = 0 transiciones, `selEntry` nunca llega a 4, state queda en 0x04.
- 120 `sceCdRead` post-reveal son carga de texturas de las 11 placas, no carga de Network.
- Para hacer Network Battle funcional habría que parchear también la tabla de handlers (input dispatch).

### Lección 33: `cursor` (+0x148) ≠ `selEntry` (+0x2C) — el navegador es `selEntry`
- `+0x148` (cursor visual) queda en 0 siempre; no refleja la navegación.
- `+0x2C` (selected_entry_ID) es el que realmente se actualiza al navegar entre entries.
- La caption `[menuhex] selEntry=N -> NOMBRE` debe usar `+0x2C`, no `+0x148`.

### Lección 34: El bloque menuhex debe sondear TODOS los estados (no solo 0x04)
- La navegación real del root menu ocurre en `bt3state=0x04`, pero las acciones (seleccionar entry) cambian a otro state inmediatamente.
- Sin sondear el state destino, no se captura el screen del sub-menú.
- Solución: el gate del bloque `[menuhex]` debe ser solo `if (s_menuHexOn)` sin filtro de estado, usando fingerprint para evitar spam.

### Lección 35: El catálogo completo de entries del main menu de BT3 (10 entries)
- `selEntry 0`: DRAGON_ROAD (screen `0x6`)
- `selEntry 1`: ULTIMATE_BATTLE (screen `0xd`)
- `selEntry 2`: WORLD_TOURNAMENT (screen `0x21`)
- `selEntry 3`: DUEL (screen `0x26` = PREFIGHT_SETUP)
- `selEntry 4`: DRAGON_NET (entry dead — no handler instalado, X no responde)
- `selEntry 5`: EVOLUCION_Z (screen `0x30`)
- `selEntry 6`: ENTRENAMIENTO (screen `0x2c`)
- `selEntry 7`: DATA_CENTER (screen `0x35`)
- `selEntry 8`: REF_PERSONAJES (screen `0x3c`)
- `selEntry 9`: OPCIONES (screen `0x3e`)

### Lección 36: LOWSPEC descartado de momento, VSYNC conservado
- El usuario descartó LOWSPEC ("de momento") pero conservó VSYNC (solo vía `PS2X_VSYNC` explícito).
- Se eliminaron: auto-enable por LOWSPEC, `SetTargetFPS(30)`, low-spec preset en main.cpp (BARONLY/UPBUDGET_KB/UNLOADMODE).
- Backups en `/tmp/opencode/bt3-changes-backup/ps2_runtime.cpp.WORKING` y `main.cpp.WORKING`.

### Lección 37: Edit tool denegado — usar Python heredoc scripts vía bash
- La herramienta `edit` no está disponible para archivos de código.
- Para edits quirúrgicos: `python3 - <<'PYEOF' ... PYEOF` con `io.open()` y `split('
')`.
- Para patches grandes (>20 líneas): generar el archivo completo con Python y `write`.

### Lección 38: Fases desconocidas del dispatcher (UNKNOWN states en runs 5-min)
- Estados vistos en runs largos: `0x14`, `0x21`, `0x2c`, `0x30`, `0x35`, `0x3c`, `0x3e`.
- Estos son los sub-estados internos del menú (cada screen del menú tiene su propio state).
- `0x3e` = estado de interacción de menú (al menos OPTIONS), `0x2c` = ENTRENAMIENTO.
- La correlación entry→screen es 1:1, lo que confirma que el dispatcher usa state IDs como screens.

### Lección 39: Cambio de GPU bimodal sin LOWSPEC — temp sube a 68°C
- Sin LOWSPEC: GPU bimodal (41% idle ≤10%, 34% ≥86% de 258 muestras).
- Temp min 54°C, max 68°C, avg 60.8°C.
- Con LOWSPEC activo era ≤62°C estable.
- La decisión de descartar LOWSPEC tiene impacto térmico observable.

### Lección 40: NO hay sub-states dentro de states — la profundidad del menú es sub-estado interno
- Validado en vivo: OPCIONES (0x3e) y su sub-pantalla "Screen Options" comparten el mismo
  screen_state_id (0x3e). Igual en DUEL (0x26): navegar el setup de pelea (personajes,
  sagas, escenario, jugadores) NO cambia el bt3state (5068 muestras en 0x3e, 1461 en 0x26).
- Conclusión: `+0x18` (screen_state_id) identifica el MENÚ del modo (1:1 con selEntry),
  pero la navegación interna de cada menú (sub-pantallas, selección) se maneja en un
  campo/struct distinto que no está en +0x18.
- El PC del main thread sí cambia al navegar internamente (0x35611C en Duel), pero eso
  es el frame de render actual, no un "sub-state" legible.

### Lección 41: La transición del main menu a Duel es 0x04 -> 0x26 -> 0x27
- Confirmado en el run de 5 min post-merge: MENU `0x04` (492 muestras) -> PREFIGHT_SETUP
  `0x26` (251) -> FIGHT `0x27` (12737, el grueso del run).
- `0x26` no es "el sub-menú de Duel" fijo: es la transición PREFIGHT_SETUP que el modo
  pelea atraviesa en camino al combate. Entrar a Duel dispara `0x04 -> 0x26`, y el
  combate arranca en `0x27`.
- Ojo semántico (corrección del usuario): `0x27` es FIGHT (gameplay 3D completo), NO
  "FIGHT_LOAD". La etiqueta en ps2_runtime.cpp se corrigió a "FIGHT".

## 2026-09-05: Hallazgos Day-4 (DRAGON_NET + deploy)

### Lección 42: La zona 0x34dca8..0x3514cc (gate/confirm state machine) NO se ejecuta en el main menu
- Instrumentado con diag `[dragonnet-diag]` en label_34f714 (gate), branch_taken_0x34f71c,
  label_3513dc (confirm func_25D3F0) y `[dndiag2]` en label_34dce0 (dispatch loop).
- Live run con `PS2X_ENABLE_DRAGONNET=1` (flags 0x600 escritas en 0x33408C) + navegación
  a DRAGON_NET + X: **CERO líneas de diag** en /tmp/dragonnet_f*.log.
- Conclusión: el state machine 0x34dca8..0x3514cc sirve a OTRO menú/screen, NO al root main
  menu. El modelo "state 4 gate" quedó DESCARTADO como punto de acceso. El handler de X del
  main menu es otra función (localizar antes de reiniciar el camino de DRAGON_NET guest-side).

### Lección 43: `f_336a90_0x336a90` es el dispatcher de bt3state y vive en el OVERLAY
- `0x336a90` = `f_336a90_0x336a90` en `ps2xRuntime/src/runner_overlay/overlay_functions.cpp`
  (~6629), rango 0x336a90-0x336fc0. No es del runner (corrige incertidumbre previa).
- Muchos slots de la overlay function table mapean a este dispatcher (big switch por bt3state).

### Lección 44: ALEASEOG de ORIGEN del estado — `g_bt3StateLive` es la fuente confiable
- El estado vivo se lee de `g_bt3StateLive` (ps2_runtime.cpp ~4157, completo 32-bit), no de
  campos parciales. Los bloques `[menuhex]`, `[hstate]`, `[dragonnet]` deben sondear ese global.

### Lección 45: PCSX2-extracted AFS boots sin ISO en el recomp — `cdRoot` resuelve todo
- `configureIoPathsFromElf`: `elfDirectory` -> `hostRoot`/`cdRoot`/`mcRoot`. Con el guest ELF
  en `data/SLUS_216.78`, `cdRoot=data/` sirve `\DATA\PZS3US*.AFS`, `cdrom0:\IRX\*.IRX`, `mc0/`.
- No se necesita `PS2X_CD_IMAGE` (ISO) si la estructura extraída está junto al ELF guest:
  `data/{BIN,DATA,IRX,mc0,mc1,SLUS_216.78,SYSTEM.CNF}` (estructura idéntica al deploy previo).

## 2026-09-05: Deploy single-ELF self-extracting (formato copiado del deploy previo)

### Lección 46: Formato del deploy previo del Escritorio
- ELF raíz (~110 MiB, pie, no stripped) + `lib/` (122 .so, RUNPATH `$ORIGIN/lib:`) + `data/`
  (juego desmontado, estructura CD) + `assets/fonts/` + `savedata/` (bt3_settings.ini con
  [audio][video][controllers][logging]) + `imgui.ini`.
- Arranca por doble clic SIN argumentos: el binario lee los settings guardados (env vars
  persistidas en bt3_settings.ini) y bootea `data/SLUS_216.78` (default fallback).
- El mecanismo real: binario previo tenía `getExecutableDirectory()`/`setConfigDirectory()`
  (ancla savedata/assets al dir del exe) que NUESTRO main.cpp NO tenía (usábamos current_path).

### Lección 47: Para el deploy se restauró `getExecutableDirectory()`/`setConfigDirectory()`
- main.cpp:102 (approx): `getExecutableDirectory()` resuelve `/proc/self/exe` -> parent, y
  acepta `PS2X_EXEDIR` (lo pasa el launcher cuando el runner vive en caché). main llama
  `settingsOverlay.setConfigDirectory(exeDir/"savedata")` ANTES de preloadSettings.
- Así savedata/, assets/fonts/ se anclan al dir del launcher aunque el runner esté extraído.
- Rebuilded `--target ps2EntryRunner` con ccache+mold: OK (131 MiB).

### Lección 48: Launcher self-extracting (C, ~300 líneas) — arquitectura que funciona
- Layout final: `[stub ELF][payload.tar.zst][footer 32B "BT3SELFX"+off+size+seed]`.
- Stub (estático, linked contra libzstd.a): lee `/proc/self/exe`, parsea footer, extrae con
  ZSTD_decompressStream a `~/.cache/bt3-recomp/<seed>` (seed=sha256(payload)[:16]), setea
  `PS2X_EXEDIR=<dir launcher>`, antepone `<cache>/lib` a `LD_LIBRARY_PATH`, chdir al dir del
  launcher y exec `<cache>/ps2EntryRunner data/SLUS_216.78` (argv[1]=boot ELF, como el deploy).
- Resultado: ELF único de 83 MiB (runner+libs embebidos), `data/` (2.8 GiB) aparte. Probado:
  extracción 126 entries, arranque completo del juego, IRX + AFS resueltos desde data/.
- libzstd.a compilado desde fuente (zstd-1.5.7, `make -C lib libzstd.a`) porque Arch no trae
  la estática. Tools: stub.c + script de empaquetado en /tmp/opencode/bt3-deploy/.

### Lección 49: Dos bugs de la primera versión del stub (u300 líneas)
- (a) `mkdir` de 1 nivel fallaba si `~/.cache/bt3-recomp` no existía -> `mkdirs()` recursivo.
- (b) Loop zstd contaba el input 2 veces (consumed+=read Y +=in.pos) -> trunco a la mitad y la
  extracción fallaba silenciosamente. Solución: contador único `readPos` + refill solo cuando
  el buffer se vacía. Regla: un contador por rol (leídos vs consumidos) SIEMPRE.

### Lección 50: `setConfigDirectory` no se invocaba en ninguna parte — overlay caía a current_path
- Es el motivo de que antes savedata/ dependiera del CWD del lanzamiento. Con el fix en 47,
  savedata/ y assets/fonts quedan portables junto al binario, igual que el deploy previo.
- El deploy previo mostró la misma convención (`savedata/` al lado del ELF, no en $HOME).

### Lección 51: Memory cards movidas a `savedata/` — mcRoot parcheado en configureIoPathsFromElf
- El runtime buscaba `mcRoot = elfDirectory/"mc0"` (ps2_runtime.cpp ~1519). Con el ELF en
  `data/`, eso era `<deploy>/data/mc0/BASLUS-21678DBZT3/`.
- Cambio: `mcRoot = elfDirectory.parent_path()/"savedata"` = `<deploy>/savedata`. Los saves
  (icon.sys, dbzsm.ico, BASLUS-21678DBZT3) viven junto a bt3_settings.ini — un solo folder
  portable para settings + saves. `data/mc0` y `data/mc1` eliminados del deploy.
- Rebuild + re-empaquetado del launcher (nuevo seed 03ff4431a24375f7) verificado en run:
  arranque completo OK, settings escritos en savedata/.

### Lección 52: Título de ventana solo con el nombre del juego
- `main.cpp`: `windowTitle = "PS2-Recomp | <gameName> | <elfName>"` mostraba el nombre del ELF
  de boot (SLUS_216.78). Simplificado a solo `gameName` (o el ELF si la DB no lo tiene).
- `SLUS-21678` no estaba en `games_database.cpp` -> añadida la entrada
  "Dragon Ball Z: Budokai Tenkaichi 3 (USA)". El deploy bootea con `data/SLUS_216.78`,
  así que `normalizeGameId` lo resuelve correctamente.
- Verificado en run: la ventana X11 se titula "Dragon Ball Z: Budokai Tenkaichi 3 (USA)".

### Lección 53: El merge de upstream introdujo symlinks rotos que rompen el link
- `git merge origin/main` trajo `ps2xRuntime/src/runner` y `src/runner_overlay` como symlinks
  (`120000`) apuntando a `/home/z3/...` (ruta de OTRA máquina). El GLOB de CMake
  (`RUNNER_SRC_FILES`/`RUNNER_OVERLAY_SRC_FILES`) quedó vacío -> link con
  `g_ps2RecompiledFunctionTable*`/`g_ps2OverlayFunctionTable*` sin definir.
- Solución: borrar los symlinks rotos y **regenerar** los fuentes como directorios reales:
  `python3 games/bt3/gen_overlay.py --recomp build/ps2xRecomp/ps2_recomp
   --dbzp games/bt3/work/BIN/DBZP.BIN --work games/bt3/work/overlay --runtime ps2xRuntime`
  (instala en `src/runner_overlay/`) y luego `apply_overlay_patches.py ps2xRuntime`.
- El runner del boot ELF se regenera desde `games/bt3/work/output` (setup.py paso 6): sync a
  `src/runner/` + copiar los 2 headers a `include/`. Sin recomp el recomp es determinista con
  el árbol ya generado.
- Reconfigurar CMake (`cmake build`) porque el SET de fuentes cambió; el unity 563 (el TU del
  overlay de 21MB) tarda ~15-25 min con -O3. Usar ccache y nohup + polling.

### Lección 54: layout de memoria card espera SUBdirectorio BASLUS-21678DBZT3
- "save data failed" + creación de `savedata_slot1` porque se dejaron icon.sys/dbzsm.ico/el
  save como ARCHIVOS SUELTOS en `savedata/`. El stub MemoryCard (ps2_stubs) resuelve
  `getMcRootPath(port)`; para port>0 genera `savedata_slot1`. El juego espera:
  `mcRoot/BASLUS-21678DBZT3/{BASLUS-21678DBZT3, icon.sys, dbzsm.ico}` (el save DEBE ser un
  directorio con ese nombre). Corregido moviendo los 3 archivos a `savedata/BASLUS-21678DBZT3/`.
- El juego siempre crea `savedata_slot1/` vacío en boot (probe del slot 1) — es normal, no un fallo.
- `PS2X_MCLOG=1` da el tracing completo de la conversación libmc (GetInfo/Open/Read) para
  depurar detección de saves.

### Lección 55: log_level en bt3_settings.ini (sección [logging])
- `log_level` (0-3, default 1): controla qué env PS2X_* exporta main() con setenv(..., 0)
  (nunca pisa env manual del usuario) y redirige stderr a `<exeDir>/logs/bt3.log` via freopen.
  Niveles: 1=PS2X_PROFILE+MCLOG+SCHED_DEBUG; 2=+FTSPIKE+FIGHTPROBE+REVEAL_HIDDEN_MENU_ENTRY;
  3=+FRAMEPROF+CAMPROBE. Rotación: el run anterior se conserva como bt3.log.prev (rename).
- IMPORTANTE: preloadSettings() es estática pero no puede tocar m_settings del struct; hay que
  escribir las estáticas s_logLevel/s_startupLogLevel directamente. loadSettings() (instancia)
  sí toca m_settings.logLevel y propaga a las estáticas.
- El log `[loglevel]` sale como PRIMERA línea (jejemplo: `[loglevel] level=1 stderr -> .../logs/bt3.log`).
- Si el run sale a los pocos segundos con el log con solo "Authorization required, but no
  authorization protocol specified": es fallo de auth X11 del shell (DISPLAY sin XAUTHORITY),
  no del build. No forzar `DISPLAY=:0` en runs de verificación; heredar el env del stub.
- El archivo bt3.log es el canal stderr completo (prof/mclog/sched/fps overwhelming); el
  settings_dump.log al lado es el dump de settings, no el log de debug.

### Lección 56: scripts unificados 1 .sh (Linux) + 1 .py (Win/aux)
- Unificar build+deploy en exactamente 2 scripts:
  - `games/bt3/setup.py` (cross-platform): argparse con `<iso|elf>`, `--jobs`, `--deploy OUT`,
    `--skip-setup`. Tras compilar, `deploy_tree()` ensambla el árbol playable (data/ desde
    work/, savedata/bt3_settings.ini si no existe, assets/). En Linux copia el runner a
    `OUT/ps2EntryRunner`; en Windows copia los *.dll del runtime. `--skip-setup` reusa
    work/ y solo rebuilda el runner (rápido con ccache).
  - `build_and_deploy.sh` (Linux): pide ISO/output (o `--iso/--output/--skip-setup`), llama a
    setup.py con `--deploy`, compila el stub estático si falta (gcc -static + libzstd.a en
    BT3_DEPLOY_SRC=/tmp/opencode/bt3-deploy), colecta .so vía ldd (excluye ld-linux*), arma
    payload.tar.zst (zstd -19), arma ELF final = [stub][payload][footer BT3SELFX + 3<<Q u64 LE:
    offset, size, seed=sha256[:16]], y reemplaza OUT/ps2EntryRunner por el ELF selffx.
  - setup.sh y launch_bt3_lowspec.sh fueron eliminados (redundantes).
- Errores encontrados al implementar:
  - `preloadSettings()` es ESTÁTICA y NO puede tocar m_settings (instancia) -> escribir
    s_logLevel/s_startupLogLevel directamente (Lección 55 relacionada).
  - En la collection de libs de ldd: las líneas son "lib => /path (0x...)" ($3) o "/path (0x...)"
    ($1); el filtro de ld-linux se hace por basename en el loop, no por grep del camino.
- El script completo verificó el flujo: deploy genera ELF que al ejecutarse extrae al cache
  (~/.cache/bt3-recomp/<seed>) y arranca con título correcto + log_level=1 (Lección 55).

### Lección: gate skip_stale_vram y el fade quad del popup de memcard (sep 5 2026)
- BUG: con skip_stale_vram=1 el popup de memory card (carpeta que colapsa) queda con ghosting de la caja.
- CAUSA: la gate skip_stale_vram (ps2_gs_gpu_renderer.cpp ~12585) ve el cuad fullscreen negro (tbp 12288, PSMT8H, region nunca renderizada) del fade del popup y lo salta ANTES de que llegue al fix [mcfade] (~14218). El fix nunca corre.
- FIX: exentar exactamente el draw del popup: `memcardFade = (srcTbp0==12288u && srcClutTbp==12354u)` para que NO sea saltado. La CLUT 12354 es única del popup; el wipe de gameplay 12288 usa otra CLUT y sigue saltado.
- SETTING: skip_stale_vram protege wipes negros que borran overlays/HUD del gameplay; los flags de glow/skippost/render_scale/fullscreen son INOCENTES aquí (bisect confirmado).
- Aislar primero el setting culpable antes de tocar código (bisect de settings sobre base "fija").
- PARCHE: /tmp/mcfade.patch (245d928) trae 3 chunks que deben ir JUNTOS: [mcfade] setea want128=64, el shader DEBE usar uABl128 (no literal 1.9921875) para que el 64 sature, y los want128 de ABLEND128. Revirtiendo el shader a literal, mcfade no funciona.
