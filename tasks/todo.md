# Launcher/Overlay pre-release: Post-FX fuera + escala interna por resolución — 2026-09-13

## Contexto
- El launcher y el overlay exponen un toggle "Post-FX" y un combo "Internal Resolution"
  (1x/2x/3x/4x). Para la primera release se eliminan ambos de la UI y el sistema de
  reescalado pasa a ser built-in derivado de la resolución elegida.
- Post-FX estaba OFF por defecto en todos los puntos (Settings=false, SettingsManager=false,
  `GsGpuRenderer::postfxEnabled()` default false, `PS2X_POSTFX` NO baked en main.cpp) →
  es seguro borrar hasta la env var.
- Mapeo aprobado por el usuario: 1x = 720p, 2x = >720p hasta 1080p, 3x = ≥1440p en adelante.
  Se añade preset 4K (3840x2160 → 3x). El 4x queda deshabilitado (nada lo genera) hasta que funcione.

## Elementos verificables
- [x] Header compartido `include/runtime/ps2_render_scale.h` con `ps2xRenderScaleForHeight`.
- [x] Post-FX: 0 refs a `postfx`/`PS2X_POSTFX` en código (solo comentarios descriptivos de draw classes).
- [x] Launcher: sin combo "Internal Resolution"; lista de resolución con 4K; escala derivada
      en cambio de Window Size y al inicializar (re-derivación de INIs viejas).
- [x] Overlay: sin combo "Internal Resolution"; 4K en Window Size; escala derivada en
      resolución/fullscreen (live en paraLLEl-GS).
- [x] `render_scale` INI se sigue persistando (derivado) y preloadSettings lo aplica.
- [x] Build completo del launcher (g++ 16.2 + ccache + mold, -O2): EXIT=0, 0 warnings/errors;
      binario `ps2xRuntime/src/launcher/build/Launcher`. `tab_video.cpp` y `settings_manager.cpp` limpios.
- [ ] Compilación de ps2xRuntime (raylib/imgui por FetchContent; pendiente — el usuario pidió
      build del launcher para validar el cambio de escala/Post-FX).

## Revisión
- Balance de llaves en `ps2_gs_gpu_renderer.cpp`, `ps2_settings_overlay.cpp`, `tab_video.cpp`:
  idéntico al HEAD (el +1 del overlay es un falso positivo del checker pre-existente).
- El bloque runtime de Post-FX quedó como gates incondicionales (comportamiento = default OFF anterior).

## Notas
- El bloque runtime `if (!s_postfx) {…gates…}` se convierte a gates SIEMPRE activos
  (comportamiento visual idéntico al default actual, validado a 30fps).
- `ps2xRenderScaleForHeight(h)`: `h<=720 → 1`; `h<=1080 → 2`; `else → 3`.
---

# Extracción de archivos con nombres reales ("propper names and formats")

## Contexto / Diagnóstico
- La tool de referencia (`AFS-Manager-CLI` = repo `MatrixDJ96/DBZBT3`) y la tabla embebida
  del AFS usan nombres **truncados/ofuscados** (ej. `WorldTou`, `VIC-JP-B-`, `res`).
- El `.db` (`debug_font_PS2_.db`) NO es una lista: es un **font/glifo** (bytes de
  píxeles). La lista de carga real del ISO es `PZS3US.DIR` (solo los 8 archivos tope)
  y los `.ALG` son offsets de alineado. No hay otra fuente de nombres en el ISO.
- Comunidad: los **AFL nuevos** de ViveTheModder (`vitetheModder.github.io`, repo Apache-2.0)
  traen el nombre real + formato de cada archivo, alineados por índice del AFS:
  - PZS3US1: 3399 archivos → `.pak` (2327), `.cdbt` (658), `.dbt` (323), `.gsc` (50), `.cpak` (41)
  - PZS3US2: 65201 archivos → `.adx` (65201, todo sonido/voces)
  - 0 duplicados, 0 nombres vacíos, 0 no-ASCII → formatos reales legibles.

## Elementos verificables
- [x] Descargar AFL nuevos y confirmar formato binario (`AFL\0` + u32s + count@12 + names 32B@16).
- [x] `loadNameTable` parsea binario AFL (valida count == entries) + legacy texto (`idx\tname`);
      prioridad: `.afl` real → tabla embebida → fallback.
- [x] Reemplazar `assets/PZS3US1.afl`, `assets/PZS3US2.afl` con los AFL nuevos.
- [x] NOTICE Apache-2.0 + crédito ViveTheModder en README.
- [x] CMake POST_BUILD copia `PZS3US1.afl`, `PZS3US2.afl`, `NOTICE` a `assets/` del build.
- [x] Launcher Qt compila localmente con los assets nuevos (build/assets verificado).
- [x] Re-extracción: PZS3US1 (3399) + PZS3US2 (65201) byte-idénticos vs AFS (0 mismatches).
- [x] Regenerar `portable/data/DATA` (idx v3 + nombres reales): PZS3US0/1/2 OK.
- [x] Validación contrato runtime: idx v3 resuelve cada slot a `folder/<name>` byte-idéntico (python).
- [ ] Rebuild docker + package + redeploy al Escritorio (aún con runner build v2 en portable).
- [ ] Commit + push del fix AFS (PR #5).

## Notas
- PZS3US0.AFS (14336B) recuperado del ISO: 1 entrada `boot_texture_PS2_.d` (12888B).
- Los AFL nuevos quedan embebidos en `src/launcher/assets/` para que el usuario final
  los tenga (no accede a internet/repo).
---

# Port launcher → Windows/macOS (input multiplataforma) — 2026-09-09

## Tarea
Reemplazar el backend de input Linux del launcher (evdev, linux/input.h) por uno
multiplataforma, y portabilizar los puntos POSIX del launcher. GitHub Actions
quedó abandonado por decisión del usuario; la validación Windows es dual-boot.

## Elementos verificables
- [x] `input_reader.{h,cpp}` GLFW 3.4 (FetchContent) joystick + QKeyEvent teclado; API `evin::` estable.
- [x] Borrar `evdev_reader.{h,cpp}`; tabs usan `input_reader.h`; sin `linux/input.h`.
- [x] `tab_bindings`: `evKeyToRaylib` → `qtKeyToRaylib` + eventFilter Qt (captura teclado).
- [x] Launcher CMake: GLFW FetchContent 3.4, `if(NOT MSVC)` en `-Wall -Wextra`, POST_BUILD copia `background.png`/`icon.png`.
- [x] `_WIN32`: `bt3-runner.exe`, LD_LIBRARY_PATH solo POSIX, `MoveFileEx` para rename atómico en `pad_config_reader.cpp`, setPermissions no-op en Windows (`extract_worker.cpp`).
- [x] Build launcher local (Arch): CONFIG/BUILD OK, smoke offscreen rc=124 (sin crash).
- [x] Fix GLFW Wayland en el contenedor: `GLFW_BUILD_WAYLAND OFF` (falta wayland-scanner en ubuntu:22.04).
- [x] Fix `entrypoint.sh` SIGPIPE (`find | head -40` + pipefail) — el clone local aún no tenía el fix de PR #6.
- [x] `entrypoint.sh` + `package.sh` ahora incluyen `data/` en stage/tarball (faltaba; el tarball salía sin el juego).
- [x] Flujo docker de 0: runner+launcher compilan (glibc floor 2.35), tarball 1.9G con `data/` + `install game.sh` + `.sha256`.
- [x] descomprimir → `install game.sh` (HOME temporal) → .desktop válido → Launcher corre → savedata preservado en re-install.
- [x] Docs: `docs/DEPLOY.md` y `README.md` reescritos (sin SELFX/stub; portable tripla).

## Notas
- Tarball release nuevo en `~/Escritorio/` (BT3-Recomp-x86_64.tar.gz 1.9G + .sha256), regenerado del flujo docker.
- Portal del Escritorio ahora con launcher contenedor (glibc 2.35) reemplazado.
- Queda como tarea futura: build Windows real via dual-boot del usuario, y PR con todo esto.


---

# setup.py multi-stage rewrite — 2026-09-18

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
