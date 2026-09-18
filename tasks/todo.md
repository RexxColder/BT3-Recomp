# Launcher/Overlay pre-release: Post-FX fuera + escala interna por resoluciÃƒÂ³n Ã¢â‚¬â€ 2026-09-13

## Contexto
- El launcher y el overlay exponen un toggle "Post-FX" y un combo "Internal Resolution"
  (1x/2x/3x/4x). Para la primera release se eliminan ambos de la UI y el sistema de
  reescalado pasa a ser built-in derivado de la resoluciÃƒÂ³n elegida.
- Post-FX estaba OFF por defecto en todos los puntos (Settings=false, SettingsManager=false,
  `GsGpuRenderer::postfxEnabled()` default false, `PS2X_POSTFX` NO baked en main.cpp) Ã¢â€ â€™
  es seguro borrar hasta la env var.
- Mapeo aprobado por el usuario: 1x = 720p, 2x = >720p hasta 1080p, 3x = Ã¢â€°Â¥1440p en adelante.
  Se aÃƒÂ±ade preset 4K (3840x2160 Ã¢â€ â€™ 3x). El 4x queda deshabilitado (nada lo genera) hasta que funcione.

## Elementos verificables
- [x] Header compartido `include/runtime/ps2_render_scale.h` con `ps2xRenderScaleForHeight`.
- [x] Post-FX: 0 refs a `postfx`/`PS2X_POSTFX` en cÃƒÂ³digo (solo comentarios descriptivos de draw classes).
- [x] Launcher: sin combo "Internal Resolution"; lista de resoluciÃƒÂ³n con 4K; escala derivada
      en cambio de Window Size y al inicializar (re-derivaciÃƒÂ³n de INIs viejas).
- [x] Overlay: sin combo "Internal Resolution"; 4K en Window Size; escala derivada en
      resoluciÃƒÂ³n/fullscreen (live en paraLLEl-GS).
- [x] `render_scale` INI se sigue persistando (derivado) y preloadSettings lo aplica.
- [x] Build completo del launcher (g++ 16.2 + ccache + mold, -O2): EXIT=0, 0 warnings/errors;
      binario `ps2xRuntime/src/launcher/build/Launcher`. `tab_video.cpp` y `settings_manager.cpp` limpios.
- [ ] CompilaciÃƒÂ³n de ps2xRuntime (raylib/imgui por FetchContent; pendiente Ã¢â‚¬â€ el usuario pidiÃƒÂ³
      build del launcher para validar el cambio de escala/Post-FX).

## RevisiÃƒÂ³n
- Balance de llaves en `ps2_gs_gpu_renderer.cpp`, `ps2_settings_overlay.cpp`, `tab_video.cpp`:
  idÃƒÂ©ntico al HEAD (el +1 del overlay es un falso positivo del checker pre-existente).
- El bloque runtime de Post-FX quedÃƒÂ³ como gates incondicionales (comportamiento = default OFF anterior).

## Notas
- El bloque runtime `if (!s_postfx) {Ã¢â‚¬Â¦gatesÃ¢â‚¬Â¦}` se convierte a gates SIEMPRE activos
  (comportamiento visual idÃƒÂ©ntico al default actual, validado a 30fps).
- `ps2xRenderScaleForHeight(h)`: `h<=720 Ã¢â€ â€™ 1`; `h<=1080 Ã¢â€ â€™ 2`; `else Ã¢â€ â€™ 3`.
---

# ExtracciÃƒÂ³n de archivos con nombres reales ("propper names and formats")

## Contexto / DiagnÃƒÂ³stico
- La tool de referencia (`AFS-Manager-CLI` = repo `MatrixDJ96/DBZBT3`) y la tabla embebida
  del AFS usan nombres **truncados/ofuscados** (ej. `WorldTou`, `VIC-JP-B-`, `res`).
- El `.db` (`debug_font_PS2_.db`) NO es una lista: es un **font/glifo** (bytes de
  pÃƒÂ­xeles). La lista de carga real del ISO es `PZS3US.DIR` (solo los 8 archivos tope)
  y los `.ALG` son offsets de alineado. No hay otra fuente de nombres en el ISO.
- Comunidad: los **AFL nuevos** de ViveTheModder (`vitetheModder.github.io`, repo Apache-2.0)
  traen el nombre real + formato de cada archivo, alineados por ÃƒÂ­ndice del AFS:
  - PZS3US1: 3399 archivos Ã¢â€ â€™ `.pak` (2327), `.cdbt` (658), `.dbt` (323), `.gsc` (50), `.cpak` (41)
  - PZS3US2: 65201 archivos Ã¢â€ â€™ `.adx` (65201, todo sonido/voces)
  - 0 duplicados, 0 nombres vacÃƒÂ­os, 0 no-ASCII Ã¢â€ â€™ formatos reales legibles.

## Elementos verificables
- [x] Descargar AFL nuevos y confirmar formato binario (`AFL\0` + u32s + count@12 + names 32B@16).
- [x] `loadNameTable` parsea binario AFL (valida count == entries) + legacy texto (`idx\tname`);
      prioridad: `.afl` real Ã¢â€ â€™ tabla embebida Ã¢â€ â€™ fallback.
- [x] Reemplazar `assets/PZS3US1.afl`, `assets/PZS3US2.afl` con los AFL nuevos.
- [x] NOTICE Apache-2.0 + crÃƒÂ©dito ViveTheModder en README.
- [x] CMake POST_BUILD copia `PZS3US1.afl`, `PZS3US2.afl`, `NOTICE` a `assets/` del build.
- [x] Launcher Qt compila localmente con los assets nuevos (build/assets verificado).
- [x] Re-extracciÃƒÂ³n: PZS3US1 (3399) + PZS3US2 (65201) byte-idÃƒÂ©nticos vs AFS (0 mismatches).
- [x] Regenerar `portable/data/DATA` (idx v3 + nombres reales): PZS3US0/1/2 OK.
- [x] ValidaciÃƒÂ³n contrato runtime: idx v3 resuelve cada slot a `folder/<name>` byte-idÃƒÂ©ntico (python).
- [ ] Rebuild docker + package + redeploy al Escritorio (aÃƒÂºn con runner build v2 en portable).
- [ ] Commit + push del fix AFS (PR #5).

## Notas
- PZS3US0.AFS (14336B) recuperado del ISO: 1 entrada `boot_texture_PS2_.d` (12888B).
- Los AFL nuevos quedan embebidos en `src/launcher/assets/` para que el usuario final
  los tenga (no accede a internet/repo).
---

# Port launcher Ã¢â€ â€™ Windows/macOS (input multiplataforma) Ã¢â‚¬â€ 2026-09-09

## Tarea
Reemplazar el backend de input Linux del launcher (evdev, linux/input.h) por uno
multiplataforma, y portabilizar los puntos POSIX del launcher. GitHub Actions
quedÃƒÂ³ abandonado por decisiÃƒÂ³n del usuario; la validaciÃƒÂ³n Windows es dual-boot.

## Elementos verificables
- [x] `input_reader.{h,cpp}` GLFW 3.4 (FetchContent) joystick + QKeyEvent teclado; API `evin::` estable.
- [x] Borrar `evdev_reader.{h,cpp}`; tabs usan `input_reader.h`; sin `linux/input.h`.
- [x] `tab_bindings`: `evKeyToRaylib` Ã¢â€ â€™ `qtKeyToRaylib` + eventFilter Qt (captura teclado).
- [x] Launcher CMake: GLFW FetchContent 3.4, `if(NOT MSVC)` en `-Wall -Wextra`, POST_BUILD copia `background.png`/`icon.png`.
- [x] `_WIN32`: `bt3-runner.exe`, LD_LIBRARY_PATH solo POSIX, `MoveFileEx` para rename atÃƒÂ³mico en `pad_config_reader.cpp`, setPermissions no-op en Windows (`extract_worker.cpp`).
- [x] Build launcher local (Arch): CONFIG/BUILD OK, smoke offscreen rc=124 (sin crash).
- [x] Fix GLFW Wayland en el contenedor: `GLFW_BUILD_WAYLAND OFF` (falta wayland-scanner en ubuntu:22.04).
- [x] Fix `entrypoint.sh` SIGPIPE (`find | head -40` + pipefail) Ã¢â‚¬â€ el clone local aÃƒÂºn no tenÃƒÂ­a el fix de PR #6.
- [x] `entrypoint.sh` + `package.sh` ahora incluyen `data/` en stage/tarball (faltaba; el tarball salÃƒÂ­a sin el juego).
- [x] Flujo docker de 0: runner+launcher compilan (glibc floor 2.35), tarball 1.9G con `data/` + `install game.sh` + `.sha256`.
- [x] descomprimir Ã¢â€ â€™ `install game.sh` (HOME temporal) Ã¢â€ â€™ .desktop vÃƒÂ¡lido Ã¢â€ â€™ Launcher corre Ã¢â€ â€™ savedata preservado en re-install.
- [x] Docs: `docs/DEPLOY.md` y `README.md` reescritos (sin SELFX/stub; portable tripla).

## Notas
- Tarball release nuevo en `~/Escritorio/` (BT3-Recomp-x86_64.tar.gz 1.9G + .sha256), regenerado del flujo docker.
- Portal del Escritorio ahora con launcher contenedor (glibc 2.35) reemplazado.
- Queda como tarea futura: build Windows real via dual-boot del usuario, y PR con todo esto.


---

# setup.py multi-stage rewrite Ã¢â‚¬â€ 2026-09-18

## Contexto
- Un solo `games/bt3/setup.py` multi-stage: 1 detect, 2 deps (interactivo, prompts en ingles),
  3 pipeline original, 4 deploy + packaging por plataforma. Reutiliza los helpers existentes.
- Scripts de root movidos a `scripts/` como wrappers finos; `Launcher.bat` eliminado (layout plano con
  `qt.conf` + DLLs junto a los exes) y unificado para el flujo nativo y el contenedor.

## Elementos verificables
- [x] Stage 1 detecta OS/arch/distro/pkg-manager/contenedor y el toolchain real (CMake>=3.21, MSVC fuera
      del dev prompt, kit Qt, Mesa lavapipe); `--report json`.
- [x] Stage 2 lista deps por plataforma con el comando exacto y las instala (winget/pip/aqt/download en
      Windows; apt/dnf/pacman/zypper en Linux; brew/xcode-select en macOS) con `-y`/`--non-interactive`.
- [x] Stage 3 = pipeline historico sin cambios; `--skip-setup`/`--gen-only`/`--jobs` compatibles.
- [x] Stage 4 Windows: ejecutado completo (launcher Qt + bundling + gate PE + zip 97.9 MB + sha256).
- [x] Stage 4 Linux: `ldd` closure + plugins Qt + tar.gz + gate glibc (dry-run validado en WSL; falta
      corrida completa en el contenedor).
- [x] `Launcher.bat` fuera: entrypoint escribe `qt.conf` + aplana DLLs; `package.sh` y el gate PE piden
      `qt.conf`.
- [ ] Corrida completa Linux en `bt3-release:jammy` + diff del tarball contra el actual.
- [ ] macOS: `--dry-run` solamente (lo pule otro dev).
- [ ] Commit de docs + wrappers.

---

# Build de 0 con setup.py (verificacion end-to-end) â€” 2026-09-18

## Contexto
- Se borro `build/` completo (Qt, Mesa, _deps, caches) y `games/bt3/work/`: nada reutilizado.
- ISO: `D:\DragonBall Z - Budokai Tenkaichi 3 (USA) (En,Ja).iso`.
- Se agrego logging real: volcado completo a `build/setup-<ts>.log` + niveles de consola
  (0 silencioso, 1 errores, 2 errores+warnings, 3 info, 4 verbose). Fallo = `FAILED at stage N... Full log: <path>`.

## Elementos verificables
- [x] Stage 1-2 desde cero: 8/8 deps OK (Qt 6.5.3 msvc2019_64 via aqt, Mesa lavapipe descargado).
- [x] Stage 3 desde el ISO: extraccion, VU1, recompilador, 7.808 fuentes, patches, overlay, runner compilado.
- [x] Stage 4: launcher Qt, bundling, gate PE "release-ready", `BT3-Recomp-x86_64.zip` 97.9 MB + sha256.
- [x] Bugs reales encontrados y arreglados por el build de 0:
      1. `--stages 3` (numero solo) rechazado.
      2. Qt 6.5.3 no tiene kit `win64_msvc2022_64` -> seleccion dinamica del kit.
      3. Re-chequeo post-install usaba el snapshot -> checks en vivo (Qt/Mesa).
      4. `ps2xRuntime/CMakeLists.txt`: `option(PS2X_HOST_SDL2)` declarada despues de usarse ->
         configure fresco omitia `imgui_impl_sdl2.cpp` (undefined `ImGui_ImplSDL2_*`).
      5. Faltaba `-DPS2X_SHOW_WINDOWS_CONSOLE=OFF` en el configure -> runner con consola (el gate lo
         rechaza); y `configured()` no reconfiguraba al cambiar ese valor.
- [ ] Verificacion de los mismos fixes del lado Linux (configure fresco sin cache) en el contenedor.
- [ ] macOS: dry-run.
---

# Corrida Linux de 0 en Arch (WSL) — 2026-09-18

## Contexto
- Se borro Ubuntu y se instalo `archlinux` en WSL (entorno limpio: sin python, keyring sin inicializar).
- Bootstrap minimo manual: `pacman-key --init/--populate` + `pacman -Syu` + `pacman -S python`.
- El resto lo hizo `setup.py` (stage 2 con pacman), y luego stage 3/4 completos desde el ISO.

## Elementos verificables
- [x] Stage 2 en Arch: detecta `pacman`, instala toolchain/ffmpeg/qt6-base/ccache+mold (añadido prepare con
      keyring reset + `pacman -Syu` cuando el keyring falla).
- [x] Stage 3 desde el ISO: extraccion, VU1, recompilador, 7.808 fuentes, patches, overlay, runner Linux.
- [x] Stage 4 Linux: launcher Qt6, closure ldd (170 libs), plugins `libqxcb`/`libqoffscreen`, layout
      canonico (`bt3-runner` + `Launcher` + `install game.sh`), `BT3-Recomp-x86_64.tar.gz` 126 MB + sha256.
- [x] Regresion Windows tras los fixes: rebuild incremental + gate PE "release-ready" + zip 97.9 MB.

## Bugs reales encontrados por la corrida Linux (todos ocultos por el build cacheado de Windows)
1. `ps2xRuntime/CMakeLists.txt`: el `if(PS2X_HOST_SDL2)` que agrega `imgui_impl_sdl2.cpp` estaba
   ANIDADO dentro de `if(WIN32)` -> en Linux no se compilaba el backend (undefined `ImGui_ImplSDL2_*`).
2. Linux no pasaba `-G Ninja` (main tree ni launcher) -> CMake elegia Unix Makefiles, ausente en Arch.
3. `ps2_gs_gpu_renderer.cpp`: los shims A4 (`GsReadImage`/`gsReadImageFromTexture`/`gsExportImage`/
   `gsFlipVertical`/`ps2xGfxDumpTexPng`) y `gsGlMirrorUniforms` estaban dentro de `#if defined(_WIN32)`.
4. `ps2_runtime.cpp`: `ps2xExeDirC()` declarado dentro del guard; `texmegaHotkey()` llamado fuera;
   `GetVideoStatus()` usaba simbolos altGL/D3D11 solo-Windows.
5. `ps2x_ui.cpp`: llamaba a `UiD3D11*` sin guard (`ui_d3d11.cpp` solo se compila en Windows).
6. `image_io.cpp`: `stb_image(_write)` duplicados con rtextures.c en GNU ld (Windows lo tapaba
   `/FORCE:MULTIPLE`) -> `STB_IMAGE(_WRITE)_STATIC` + includes `external/...`.
7. `<dirent.h>` del vendor sombreaba el del sistema (`src/external` en el include path) -> el include
   se quito y stb se incluye como `external/...`; `gsrl_vendor.h` idem para `glad.h`.
8. `ps2_fmv_override.cpp`: falta `<cstring>` (`std::strstr`).
9. `setup.py`: `SameFileError` al bundlear una dep de plugin que resolvia al mismo archivo por `..`;
   y el arbol Linux conservaba el binario crudo `ps2EntryRunner` (ahora solo `bt3-runner`).