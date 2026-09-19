# Native IOP (R3000) — estado

Subsistema para correr los módulos IOP (`data/IRX/*.IRX`) **recompilados a nativo** en vez de
emularlos/HLEarlos. Todo esto está en la rama de desarrollo (`texpack-pak-texcache`), **no** en
el PR de producto.

## Pipeline

1. **Recompilar**: `ps2xRecomp` con `arch="r3000"` (backend MIPS I; rechaza MMI/VU/FPU/COP1-2/64-bit).
   - Mapa de funciones: `tools/iop/irx_functions.py` (entradas = export fptrs, JAL, punteros
     `lui+ori/addiu` alineados ≥0x100, y stubs de import).
   - Imports del IRX → `runtime->iopImport(rdram, ctx, "<mod>", <ordinal>)` (HLE del kernel).
   - Llamadas internas → `runtime->dispatchIopBranch(...)`; registro vía
     `extern "C" void ps2x_register_<mod>()`.
2. **Integrar**: los generados van a `ps2xRuntime/src/iop_native/<mod>/` y se listan en
   `ps2xRuntime/CMakeLists.txt` (`target_sources(ps2EntryRunner ...)`).
3. **Correr**: `SifLoadModule` mapea el IRX en la **RAM IOP** (misma sparse mapping con
   `rdram` desplazado por base) y llama a su `entry` nativo.

## Runtime (ps2_runtime.cpp)

- **RAM IOP**: mapeo sparse (`mmap MAP_NORESERVE`, Linux) que cubre RAM + registros
  `0x1F80xxxx`/`0xBF80xxxx`; cada módulo recibe una **base propia** (tamaño real del módulo).
- **Scheduler IOP** cooperativo: hilos con `yield` por excepción (`IopYield`); retoma por
  `ctx->pc` (resume labels del recompilador). `WaitSema`/`WaitEventFlag`/`Sleep/DelayThread`
  estacionan; `SignalSema`/`SetEventFlag`/`WakeupThread` despiertan.
- **Kernel HLE** (`iopImport`): `loadcore`, `stdio`, `sysclib`, `dmacman`, `thbase`, `thevent`,
  `thsemap`, `intrman`, `sysmem`, `sifman`, `sifcmd` con estado real (hilos/semáforos/eventos).
- **SIF RPC**: `sifcmd` registra servidores (`sceSifRegisterRpc`); `ps2xInvokeIopRpc` entrega
  RPCs del EE al handler nativo (copia cross-space + ABI `(command,data,size)`).
- **Loader**: `loadAndRunIopModule` — guard: header `text==0` inválido → HLE.

## Flags

| env | efecto |
|---|---|
| `PS2X_IOP_DIR` | carpeta de IRX (default `data/IRX/`) |
| `PS2X_IOP_MODULES` | lista de stems a correr nativo, o `all` (default: set validado) |
| `PS2X_IOP_SCHED=0` | desactiva el scheduler |
| `PS2X_IOP_NATIVE_DBCMAN=0` | desactiva el routing RPC de pad a DBCMAN nativo |
| `PS2X_IOP_NOENTRY=<substr>` | carga el módulo sin ejecutar su `entry` (diagnóstico) |
| `PS2X_IOP_WATCHDOG=<seg>` | SIGALRM + backtrace si un entry se cuelga (diagnóstico) |
| `PS2X_IOP_XCALL_RESOLVE_ONLY=1` | resuelve llamadas cruzadas sin ejecutar el callee |

Set validado (default): `SIO2MAN,SIO2D,DBCMAN,LIBSD,SDRDRV,CDVDSTM,MCMAN`. **Pad nativo por
defecto** vía DBCMAN.

## Módulos

### Nativos OK (corren en el juego, sin romper boot)
| módulo | notas |
|---|---|
| `SIO2MAN` | entry 0x634; su hilo espera la int. SIO2 (event flag) |
| `DBCMAN` | **pad nativo** (registra 4 servidores RPC; RPCs del juego → handlers nativos) |
| `SIO2D` | entry 0xe14 |
| `LIBSD` | librería (no registra RPC) |
| `SDRDRV` | entry 0x3a0 |
| `CDVDSTM` | entry 0x15dc |
| `MCMAN` | memory card manager (entry 0x178) |
| `MCSERV` | servidor de memory card (entry 0x40) |
| `DS2U_D` | driver DualShock 2 (entry 0x0) |
| `SOUNDS` | driver de sonido |
| `MODHSYN` | síntesis |
| `MODSESQ2` | secuenciador |

Default: `SIO2MAN,SIO2D,DBCMAN,LIBSD,SDRDRV,CDVDSTM,MCMAN,MCSERV,SOUNDS,MODHSYN,MODSESQ2,DS2U_D`.

### Rotos / bloqueados
Los 17 IRX integrados corren nativos. El bug del **deadlock por re-entrada** (`iopImport`
mantenía un mutex no recursivo y re-entraba por la llamada cruzada) era la causa de los stalls
de `MCMAN`/`MCSERV`/`DS2U_D`/`CRI_ADXI`. Corregido con `std::recursive_mutex`.

`DS2O_D`, `MODMIDI`, `MODSEIN`, `MODSESQ` integrados y habilitados, pero el juego **no los carga
en el boot** (se cargan después o vía `IOPRP300.IMG`).

Probablemente funcionales (retornan y bootean): `SOUNDS`, `MODHSYN`, `MODSESQ2` — falta validar
visualmente que el juego progrese a FIGHT.

## Bugs ya corregidos
- **Header IOP**: leer 34 bytes desde `p_offset` (varios declaran `p_filesz` < 34, p.ej. MCMAN → 32).
- **Bases de módulos**: reservar el tamaño real (text+data+bss); 64 KB fijos hacían que MCMAN
  (~74 KB) pisara al módulo siguiente.
- **Start en 0** válido para IRX (código en vaddr 0).
- **Exports con slots 0 interiores**: no truncar en el primer 0.

## Próximos pasos
1. **CRI_ADXI**: aislar qué escritura corrompe (watchpoints / bounds de región).
2. **DS2*/MOD***: modelar **SIO2 hardware/IRQ** (registros + interrupción) para que los waits
   de los drivers de pad/secuenciador resuelvan.
3. **MC (MCMAN+MCSERV)**: atacarlos juntos; necesitan SIF real (EE↔IOP) y/o SIO2 + la cadena
   `ioman`/`secrman`/`cdvdman`.
4. `IOPRP300.IMG`: módulos del kernel IOP aún sin tocar.
