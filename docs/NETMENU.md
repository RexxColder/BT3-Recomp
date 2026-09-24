# NetMenu — el Dragon Net cortado y su reconstrucción

Objetivo: un **menú Dragon Net nativo** (sin overlay host), que se abra desde la entry oculta
del menú principal, muestre un placeholder mientras se reconstruye, y permita **entrar y salir
normalmente** por la lógica del propio juego.

## 1. El ghost: qué hacía la fila 4 en el retail

La entry oculta ("Dragon Net Battle", fila 4 del menú principal) usa el handler `0x3367A4`, que
**no cambia de estado**: carga el recurso `fl_ok` (`func_336018(0, "fl_ok")`) y llama
`func_124F68(1,1)` → `func_124F88(1,1,0x40,0,0)` → `func_1245F0()` + `func_1252D8(1)` y con el id
resultante indexa una **tabla de records de 76 bytes** (`19*id*4`) más un global por `$gp`.
O sea: **un efecto/SE, sin pantalla**. La pantalla del Dragon Net fue **cortada**.

Evidencia adicional de que fue cortada:
- `data/DATA/PZS3US1/DragonNet_UP.pak` y `DragonNet_US.pak` existen pero son **stubs de 64 B**
  (header `.pak` vacío: `03 00 00 00` + cuatro `0x40` + ceros).
- La entry se **oculta** en el builder del menú (loop que saltea `$s1 == $t0`, con `$t0 = 4`
  hardcodeado en `0x335568`) — ver el patch `[bt3 patch: reveal-hidden-entry]`.
- No hay código de red en el binario (0 referencias a netcnfif/smap/eenet/dev9/libnet).

## 2. Infraestructura de hosting de estado (de `netmenutest`)

Para meter una pantalla propia sin overlay:

1. **Tabla de estados relocalizada**: el dispatch de estados (`f_336a90`, `0x336c58`) lee
   `stateObj+0x18`, hace `(state-1)`, `sltiu <0x46` y `jr` por la tabla en RAM **`0x3B1130`**.
   Los parches `[netmenutest patch: state-limit]` (`0x46 → 0x60`) y `state-table-hi/lo`
   (base `0x3B0000 → 0x01F80000`, offset `0x1130 → 0`) la **relocalizan al tope de RAM**
   (verificado libre: `0x01F1032D..0x01FAFFC2`). El runtime **construye siempre** esa tabla
   (copia las 70 entradas stock) aunque el experimento esté apagado, y tiene **self-heal** si
   algo la pisa (la primera versión en `0x00D00000` la pisaba el heap).
2. **Funciones inyectadas** (`runtime/ps2x_injected.h`): un mapa `addr → cuerpo C++` consultado
   en `lookupFunction()` **antes** de las tablas generadas (las tablas son densas: una dirección
   sin código real puede tener un placeholder que gane el lookup).
3. **Redirect de la fila 4** (`[netmenutest patch: row4-target]`): el handler `0x3367A4` carga
   `$t2 = 0x0F`, `$t0 = 0x300000` (tail: `0x300000-0xEF4 = 0x2FF10C`), `$t1 = <estado>` y cae al
   tail común `0x3364F4` (escribe `stateObj+0x18` y llama `func_10D878`). Con el env apagado corre
   el código stock (`goto label_3367a8`).
4. **Seam del pad**: BT3 **no usa libpad** — el pad que el juego ve se arma en
   `writeNeutralPadPacket` (game_overrides). Ahí se inyecta Cross/Circle
   (`ps2xNetMenuPress(mask, frames)`) y se congela el input del guest (`ps2xNetMenuFreeze`).
5. **Campos del Duel** (`ps2x_duelfields`): `duelObj = *(0x3B38E8)` → `+0x110` vs mode,
   `+0x114` battle type, `+0x118` DP, `+0x13C` Duel Time; copias comprometidas
   `stateObj+0x620/624/628/630`; tabla de tiempos en RAM `0x2C3480` = `[INF,60,90,180,240]`.

### Lecciones (caras, ya pagadas)
- Un **estado desconocido** (`0x47`, fuera de `0x46`) hace que el engine caiga a su *fallback*
  (flujo Dragon Net → **pelea rota**, ambos con vida 0) y durante el FMV el overlay no se dibuja
  (el present de movies no pasa por el callback de UI). **Por eso se hostea en un estado que el
  engine ya conoce.**
- El `jr` del dispatch tiene **`case` inline** para los handlers stock: hookear la tabla del
  overlay **no** aplica al dispatch (por eso la entry apunta a una dirección inyectada).
- La máquina de estados **loopea mientras `$s2 == 0`** (`0x336E08: beqz $s2, 0x336C58`): el
  handler debe setear **`$s2 = 1`** para salir (si no: freeze / black screen).
- El body debe terminar el dispatch con **`ctx->pc = $ra`** (como el `jr $ra` del handler stock).
- En `dispatchGuestBranch` hay **dos** `if (!hasFunction(targetPc))`: las inyectadas deben contar
  como “función presente” en **ambos** (el de `kind == Return` y el de la *missing-function policy*).

## 3. Estado host: candidatos sin uso

Los que hoy mapean al handler genérico `0x336E08` y **no** aparecen como target en las tablas de
menú (`0x3B1100`, `0x3B4510/30/40`) ni en los sitios `$t1` conocidos:

`0x45` (elegido), `0x44`, `0x43`, `0x39…0x42`, `0x34`, `0x33`, `0x2F`, `0x2E`, `0x2B`, `0x2A`,
`0x25`, `0x24`, `0x1F`, `0x0C`, `0x05`.

**Verificación definitiva** (pendiente, probe `[statewrite]` gated): loguear cada escritura a
`stateObj+0x18` con el `pc` del llamador durante un playthrough → confirmar que el estado elegido
nunca se entra; si se entra, pasar al siguiente candidato.

## 4. Env

`PS2X_NET_MENU=1` es **el único** switch: reemplaza y unifica `PS2X_REVEAL_HIDDEN_MENU_ENTRY`
(el reveal de la fila pasa a leer `ps2x_netmenutest_enabled()`), `PS2X_NETMENUTEST`,
`PS2X_MENU_JUMP`/`PS2X_MENU_AUTO` y `PS2X_ENABLE_DRAGONNET`.

## 5. Fases

- **F1 (actual)**: estado host `0x45` + **placeholder nativo** (texto mínimo del host, sin overlay
  de página): `New Dragon Net Menu / By RexxColder / Work in progress` + `(O) volver` (Circle →
  transición propia del juego al main menu).
- **F2**: pulido (entrada/salida repetida, sin freeze), y volver a cablear subtipos/timing sobre
  la base nativa.
- **F3 (último)**: extraer `DragonNet_UP/US.pak` de la **versión Wii** (`WZS3US1.AFS`) y rellenar
  los stubs de 64 B (drop-in por el AFS folder-backed — ver `docs/AFS.md`), con el caveat de
  compatibilidad de formato PS2↔Wii.

## 6. Referencias
- `docs/MAIN-MENU.md` (tablas de entries, estados, campos del Duel).
- `docs/AFS.md` (pipeline AFS y mejoras).
- `docs/BT3-MODDING-RESEARCH.md` (funciones sin uso + método J→USA, formatos, modos).
