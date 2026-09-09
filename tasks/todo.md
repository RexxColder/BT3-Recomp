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