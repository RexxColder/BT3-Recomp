# Lecciones aprendidas

## 2026-09-09 — Port launcher multiplataforma (GLFW + QKeyEvent)

- **`find | head -40` bajo `set -o pipefail` = SIGPIPE (rc=141)**: el pipeline
  muere si `head` cierra el pipe antes de que `find` termine. En scripts con
  `pipefail` hay que tolerarlo (`|| true`) o no truncar con `head`. El clone
  local tenía este bug desde PR #6 sin mergear.
- **GLFW via FetchContent en ubuntu:22.04 falla si falta `wayland-scanner`**:
  GLFW intenta compilar tanto backend X11 como Wayland. En el contenedor base
  hay que forzar `GLFW_BUILD_WAYLAND=OFF` (y `GLFW_BUILD_X11=ON`) en Linux;
  Windows/macOS usan su backend nativo sin ambiente `WAYLAND/X11`.
- **`std::rename` no sobrescribe en Windows**: falla si el destino existe.
  Para reemplazo atómico de `pad_p*.conf` hay que usar `MoveFileEx` con
  `MOVEFILE_REPLACE_EXISTING` bajo `_WIN32`.
- **El tarball release se armaba sin `data/`**: `package.sh` solo volcaba
  Launcher+bt3-runner+lib+assets y creaba `savedata`; el juego extraído quedaba
  en `games/bt3/work/`. `entrypoint.sh` (docker) debía copiar `data/` del work
  al stage. Regla: cada stage/artefacto debe validar su contenido (el tarball
  actualizado pasó de 94 MB a 1.9 GB con la data correcta).
- **El teclado Qt no es un dispositivo**: no se puede abrir como node evdev.
  Captura vía `eventFilter` en el tab + traducción `Qt::Key -> raylib code`,
  inyectado al reader con `captureKey`/`takeLastKey`.
- **Mantener la API `evin::` estable al portar**: así los tabs (bind capture +
  live test) solo cambian el include y el nombre del translate, no su lógica.

## 2026-09-09 (tarde) — Rebase con dev + render paraLLEl-GS default

- **`rsync --delete --exclude 'savedata/'` == pelea con el --delete**: rsync
  **borra el `savedata/` del destino** aunque lo excluyas, porque `--delete`
  elimina todo lo que no existe en el origen; el `--exclude` no protege contra
  el delete. Para preservar `savedata/` hay que usar
  `--exclude 'savedata/' --exclude 'savedata/**'` o mejor operar solo sobre los
  items (Launcher, bt3-runner, lib, assets, data) sin `--delete`. El deploy
  borró el savedata de la carpeta portable (dir vacío en el stage).
- **el dev force-pusheó main (rebase)**: `origin/main` se movió 813b6a6 →
  e9e2910 con nuestra PR#5 squash-incluida (`0f48721`). Para integrar nuestro
  trabajo de la sesión sobre los commits nuevos del dev **NO rebasear la rama
  local**: clonar el fork en limpio (`/tmp`), crear la rama desde
  `upstream/main` y aplicar el `git diff` local con `git apply --3way`
  (aplica limpio / deja conflicto puntual). `/tmp` es tmpfs 16G y el submodule
  de parallel-gs + data pesan ~7G → quedó corto de espacio; mover a `/home`.
- **El renderer paraLLEl-GS solo es default si está "built in"**: CMake define
  `PS2X_HAVE_PGS=1` solo cuando existe `ps2xRuntime/third_party/parallel-gs`
  (submodule `z3xox/parallel-gs` @ 42c6701, fork de Arntzen-Software con
  Granite + sus third_party vendored: glslang/spirv/shaderc/volk). Sin el
  checkout el default cae a OpenGL (kRendererDefault=0).
- **Clave `renderer=` vs legacy `gpu_renderer`**: el launcher (`settings_manager`)
  solo manejaba `gpu_renderer` (bool) y por defecto escribía `0` = software.
  El overlay nuevo lee `renderer=` (0 OpenGL / 1 software / 2 paraLLEl-GS).
  Alinear el launcher: `m_renderer` default = kRendererParallelGS, escribir
  `renderer=` explícito, `gpu_renderer` derivado, y no dejar que gpu_renderer
  pise a renderer si ya viene la clave explícita (flag m_sawRenderer).
- **`strings` no ve `QStringLiteral`** (decimal="UTF-16LE") ni textos de
  `SetWindowIcon`; usar `grep -P`/byte counts de la codificación real para
  verificar que el cambio entró al binario del stage.
- **raylib `SetWindowIcon` con arte grande (7459x5178) rompe X11**:
  `_NET_WM_ICON` envía todos los píxeles en una sola propiedad → `BadLength`.
  Redimensionar antes con `ImageResize` (128px) previo a `SetWindowIcon`.
- **`nm -D` no prueba símbolos de raylib**: está linkeado estáticamente en el
  runner; los símbolos no aparecen en la tabla dinámica. Leer el código o
  strings.