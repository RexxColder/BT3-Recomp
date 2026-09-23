# BT3 main menu / estados — mapa completo

Estado: **mecanismo verificado**, nombres de pantalla en su mayoría **hipótesis por verificar**
(detonando cada estado con `PS2X_MENU_JUMP`). Última actualización: 2026-09.

Todo lo de aquí es para el overlay `DBZP.BIN` (USA, `SLUS_216.78`). Conversión de dirección:

```
file offset en DBZP.BIN = RAM - 0x334C00        (el overlay carga en RAM 0x334C00)
```

## 1. Mecanismo del menú principal

Al confirmar una fila del menú principal:

1. El motor lee el índice de la fila activa y salta por la **jump table**:

   ```
   0x33643C  lw   $a1, 0xE80($s1)        ; $a1 = menuObj = [0x3B0E80]
   0x336440  lw   $v0, 0x10C($a1)
   0x336444  lw   $v1, 0x148($a1)
   0x336448  lw   $a0, 0x144($a1)
   0x33644C  addu $v1, $v1, $v0
   0x336450  addiu $v1, $v1, 1
   0x33645C  div  $v1, $a0              ; row = (cursor + 0x148 + 1) % 0x144
   0x33646C  lw   $v0, 0x118($v0)        ; menuObj->0x118[row] = índice 0..10
   0x336470  sltiu $v1, $v0, 0xB         ; 11 filas
   0x336488  lw   $v1, 0x1100($v1)       ; jump table en RAM 0x3B1100
   0x33648C  jr   $v1
   ```

2. El **handler de la fila** carga `$t1` = **estado destino** y salta al tail común.

3. **Tail común `0x3364F4`** (equivalente a `bt3MenuGoto` en el runtime):

   ```
   0x3364F4  lui   $a1, 0x3B
   0x3364F8  lw    $v0, 0x108($v1)
   0x336504  ori   $v0, $v0, 1
   0x336508  sw    $v0, 0x108($v1)       ; menuObj->0x108 |= 1
   0x336510  lw    $v0, 0x108($a0)
   0x336514  ori   $v0, $v0, 2
   0x336518  sw    $v0, 0x108($a0)       ; |= 2
   0x336520  sw    $t2, 0x110($v1)       ; $t2 = 0x0F
   0x336524  lw    $v0, 0xF10C($t0)      ; $t0 = 0x2F0000 -> *(0x2FF10C) = stateObj
   0x336528  sw    $t1, 0x18($v0)        ; stateObj+0x18 = estado destino
   0x336530  jal   func_10D878           ; "ir a la pantalla N"
   ```

`func_10D878` (RAM `0x0010D878`) es un **"go to screen N" genérico** (lo usan casi todas las
pantallas del overlay: hay ~260 call sites). El objeto de menú `[0x3B0E80]` **sólo existe mientras
el menú principal (0x04) está en pantalla**: el juego lo libera al salir.

## 2. Tabla de filas del menú principal

| row | jump-table (RAM) | handler (RAM) | estado destino |
|----|------------------|---------------|----------------|
| 0 | `0x3B1100` | `0x336498` | `0x06` |
| 1 | `0x3B1104` | `0x3364B0` | `0x0D` |
| 2 | `0x3B1108` | `0x3364C8` | `0x21` |
| 3 | `0x3B110C` | `0x3364E0` | `0x26` (Duel) |
| 4 | `0x3B1110` | `0x3367A4` | — **especial** (oculta) |
| 5 | `0x3B1114` | `0x336570` | `0x30` |
| 6 | `0x3B1118` | `0x3365B8` | `0x2C` |
| 7 | `0x3B111C` | `0x336600` | `0x35` |
| 8 | `0x3B1120` | `0x336648` | `0x3C` |
| 9 | `0x3B1124` | `0x336690` | `0x3E` |
| 10 | `0x3B1128` | `0x336720` | `0x46` |

Los `$t1` de los handlers 0..3 están en `0x3364AC` (0x06), `0x3364C4` (0x0D), `0x3364DC` (0x21),
`0x3364F0` (0x26). Los de las filas 5..10: `0x3365B0` (0x30), `0x3365F8` (0x2C), `0x336640` (0x35),
`0x336688` (0x3C), `0x3366CC` (0x3E), `0x33675C` (0x46).

La fila **4 no salta a ningún estado**: llama `func_336018(0, "fl_ok"@0x3B10E8)` y
`func_124F68(1,1)`. Es la entrada oculta (Network Battle / Dragon Net) — ver
`PS2X_REVEAL_HIDDEN_MENU_ENTRY` y `PS2X_ENABLE_DRAGONNET`. Es la que no hace nada al confirmar
(le falta el backend de red, que el juego no trae).

Recursos/anims de fila: `fl_on_start` (`0x3B10A0`), `fl_off_start` (`0x3B10B0`), `up` (`0x3B10D8`),
`fl_ok` (`0x3B10E8`).

## 3. Estados de pantalla (`*(*(0x2FF10C)+0x18)`)

Estado vivo: `mainPtr = [0x2FF10C]`; el estado es `mainPtr+0x18`.

| estado | nombre (hipótesis) | quién lo setea | notas |
|--------|--------------------|----------------|-------|
| `0x01` | BOOT | — | FMV + título + splash logos |
| `0x04` | MAIN_MENU | — | menú principal; `[0x3B0E80]` vive aquí |
| `0x06` | LOADING | `0x3364AC` | row 0 (Dragon History) |
| `0x07` | ? | `0x340A08`, `0x3990D4` | |
| `0x0B` | ? | `0x35D45C` | |
| `0x0D` | ULTIMATE_BATTLE | `0x3364C4`, `0x35D450` | row 1 |
| `0x0E` | ? | `0x35D46C` | |
| `0x10` | ? | `0x369084` | |
| `0x11` | ? | `0x3690E0`, `0x3A2AA4` | |
| `0x1A` | ? | `0x3690E8` | |
| `0x1D` | ? | `0x3691B4` | |
| `0x20` | ? | `0x3691D8` | |
| `0x21` | DRAGON_WORLD_TOUR | `0x3364DC` | row 2 |
| `0x26` | DUEL_MENU | `0x3364F0` | row 3 — **verificado** |
| `0x27` | CHARACTER_SELECT | (módulo duel) | |
| `0x28` | PREFIGHT_SETUP | — | |
| `0x29` | PREFIGHT_SETUP | — | |
| `0x2C` | ULTIMATE_TRAINING | `0x3365F8` | row 6 |
| `0x2D` | IN_FIGHT | — | |
| `0x30` | EVOLUTION_Z | `0x3365B0` | row 5 |
| `0x35` | DATA_CENTER | `0x336640` | row 7 |
| `0x38` | POST_FIGHT | — | |
| `0x3C` | CHARACTER_REFERENCE | `0x336688` | row 8 |
| `0x3E` | OPTIONS | `0x3366CC` | row 9 |
| `0x46` | EXTRA? | `0x33675C` | row 10 |
| `0xA4` | ? | `0x34248C`, `0x3494C4` | |

El **mapeo row→nombre** sale de cruzar el orden real del menú principal de BT3 con el índice de
fila. Sólo la fila 3 (`0x26` = Duel) está verificada en ejecución; el resto es hipótesis a confirmar
detonando cada estado.

Orden real del menú principal (retail): Dragon History → Ultimate Battle → Dragon World Tour →
Duel → *(Network Battle, oculta)* → Evolution Z → Ultimate Training → Data Center →
Character Reference → Options.

## 4. Duel (row 3, estado `0x26`)

Estructura real del menú Duel (2 niveles):

- **Nivel 1** (opciones del menú Duel): `1P VS COM` · `1P VS 2P` · `COM VS COM` · `Battle Settings`.
- **Nivel 2** (sólo en las 3 primeras): `Single Battle` (1v1) · `Team Battle` (equipos ≤ 5) ·
  `DP Battle` (equipo ≤ 10 / 15 / 20 Destruction Points).
- **Battle Settings**: Duel Time (60/90/120/180/240/∞) · COM Level (Very Weak→Very Strong) ·
  Referee (Ox King / Videl / Supreme Kai / Shenron / Announcer 1-3) · Transformations (1P·2P ON|OFF) ·
  Map Setting (ON/OFF) · Default.

Campos ya conocidos (objeto duel `duelObj = [0x3B38E8]`):

| offset | significado |
|--------|-------------|
| `+0x110` | modo oponente: 0 = 1P vs CPU, 1 = 1P vs 2P, 2 = CPU vs CPU |
| `+0x114` | tipo de combate: 0 = Single, 1 = Team, 2 = DP (provisional) |
| `+0x118` | DP limit (10 / 15 / 20) |
| `+0x13C` | límite de tiempo |
| `stateObj+0x620` | copia del modo oponente (commit en confirm) |
| `stateObj+0x624` | copia del tipo de combate |
| `stateObj+0x630` | copia del DP limit |

## 5. Otros modos (árbol del menú)

- **Dragon History**: Select Scenario → Select Difficulty (Easy/Normal/Hard).
- **Ultimate Battle**: Sim Dragon (Start / Battle Record / Explanation) · Mission 100 ·
  Survival (Bardock War / Dragon Classic / All-Star) · Disc Fusion (BT1 / BT2).
- **Dragon World Tour**: World Tour (World Tournament / World Martial Arts Big Tournament /
  Cell Games / Otherworld Tournament / Yamcha Game) y Free (los mismos 5), niveles 1-2-3.
- **Evolution Z**: Character Customize (Custom 1/2/3, Equip Item, Password, Distribute Z Points) ·
  Item Shop (Item Exchange, Item List) · Evolution Z Explanation.
- **Ultimate Training**: Training · Battle Training (Basic/Intermediate/Advanced).
- **Data Center**: Password Input Screen · Fighter Catalog · Replay.
- **Character Reference** · **Options** (Save/Load, Screen, Sound, Controller, Exit).

## 6. Cómo verificar / usar

Runtime (`ps2_runtime.cpp`, bloque `[bt3state]`):

- `PS2X_STATE_NAMES` (default ON, `=0` lo apaga) → reporta cada transición:
  `[bt3state] 0x3e OPTIONS (was 0x04 MAIN_MENU)`.
  En estados de Duel añade el subtipo leído en vivo:
  `[bt3state] 0x26 DUEL_MENU vs=1P_VS_CPU type=SINGLE dp=0xffffffff`.
- Dentro del menú principal (`0x04`), el mismo switch reporta a qué entrada apunta el cursor, con
  la dirección exacta que el juego usaría al confirmar (fórmula propia del juego, `0x33643C..0x33648C`):

  ```
  [bt3cursor] row=3 idx=3 entry=0x3B110C handler=0x3364E0 target=0x26 Duel (verified) sel=0x3
  ```

  donde `row = (menuObj+0x10C + menuObj+0x148 + 1) % menuObj+0x144`,
  `idx = *(menuObj + 0x118 + 4*row)`, `entry = 0x3B1100 + 4*idx`, `handler = *(entry)`,
  `sel = *(mainPtr+0x2C)`. Sólo imprime cuando cambia la fila.
- `PS2X_MENU_JUMP=<estado decimal>` + `PS2X_MENU_AUTO=1` → desde el menú principal ejecuta
  `bt3MenuGoto(estado)` (activa la transición real). Validado: `38` (0x26) entra a Duel.
  También se puede disparar con el combo de teclado **P+L** o **click izq+der**.
- `PS2X_REVEAL_HIDDEN_MENU_ENTRY=1` → revela la fila 4. `PS2X_ENABLE_DRAGONNET=1` → estampa
  `0x600` en `0x33408C` para que pase el gate de confirm (sin backend de red sigue sin hacer nada).

Pendiente: detonar `0x06 / 0x0D / 0x21 / 0x30 / 0x2C / 0x35 / 0x3C / 0x3E / 0x46` uno por uno y
anotar la pantalla que sale → mapeo definitivo. Después, extender `[bt3state]` con el subtipo de
cada estado (no sólo Duel).

## 7. Otros datos

- `dispPtr = [0x2FF28C]`: `+0x08` display_filter, `+0xA0C` frame_counter.
- `mainStruct = [0x3B38D8]`: `+0x3BC` globalFlags (bit 3 = submenú), `+0x9A4` subStruct,
  `subStruct+0x40` menuState (9 = DISPLAYED, 10 = TRANSITIONING).
- `itemBase = [0x3B38E8]`: `+0x12C` cursor, `+0x138` selection, `+0x13C` itemState.
  itemState 0..8 = PLATE_LOAD, SECOND_PASS, REFERENCE_COUNTER, ANIMATION, CONFIRM_ACCEPT,
  NAVIGATION, CHARACTER_SELECT, VISUAL_RENDER, FINAL_CONFIRM.
- Handlers de entry del menú (tabla en RAM `0x3B4290`, file `0x07F690`):
  `0x34DD08, 0x34EA70, 0x34F040, 0x34F630, 0x34F700, 0x34F738, 0x350168, 0x3509B0, 0x351388`.
- Tipos (RAM `0x3B0FA0`): `[4,4,4,5,5,5,5,4,5,5,4]`.
- Dispatch por tipo (RAM `0x3B3EF0`): `0x34A040, 0x34A088, 0x34A0D0, 0x34A258, 0x34A230,
  0x34A110, 0x34A158, 0x34A1A0, 0x34A230, 0x34A1E8, 0x34A258`.
- Strings de placa: `mc_menu_plate_%d`, `mc_menu_text_on/off`, `mc_icon_off/play`,
  `mc_menu_plate_7`, `mc_menu_yajirusi_up/down`, `mc_dragonball`, `mc_bg_cloud`.

### Cómo se generó esto

- La jump table y los handlers salen de volcar `DBZP.BIN` (ver §dir. base) y del código generado en
  `ps2xRuntime/src/runner_overlay/overlay_functions.cpp` (que lleva la desarmada en comentarios).
- El arbol del menu real sale de la traduccion del menu retail de BT3 y de las wikis del juego
  (Duel: 3 modos de oponente x 3 tipos de combate + Battle Settings).

## 8. Duel setup fields — `ps2x_duelfields` (fuente unica)

Modulo `ps2xRuntime/{include/runtime,src/lib}/ps2x_duel_fields.{h,cpp}`: todas las direcciones,
los valores, las combinaciones y el **write completo** (lo usara el wire del backend).

### Direcciones (guest RAM)
| campo | address | valores |
|-------|---------|---------|
| `duelObj` | `*(0x3B38E8)` | objeto del modulo Duel (vive solo en `0x26`) |
| vs mode | `duelObj+0x110` | 0 = 1P vs CPU, 1 = 1P vs 2P, 2 = CPU vs CPU, 3 = Battle Settings |
| battle type | `duelObj+0x114` | 0 = Single, 1 = Team, 2 = DP |
| DP variant | `duelObj+0x118` | 0 = 10, 1 = 15, 2 = 20 |
| time limit / fila de Settings | `duelObj+0x13C` | time limit; 0..6 como cursor en Settings |
| vs copy | `stateObj+0x620` | `*(0x2FF10C)+0x620` (commit `0x356234 -> 0x356238`) |
| type copy | `stateObj+0x624` | la lee char-select en `0x352DA8` |
| extra | `stateObj+0x628` | (tambien lo trackea el netjump) |
| DP copy | `stateObj+0x630` | commit en `0x35625C` |

### Combinaciones
Los **5 subtipos** de combate (para cualquier modo): `SINGLE`, `TEAM`, `DP10`, `DP15`, `DP20`
= `(type, dp)` en `{Single/Team/DP} x {10/15/20}` (el dp solo aplica con `type=DP`).
Los **3 modos** de oponente + Settings: `1P_VS_CPU`, `1P_VS_2P`, `CPU_VS_CPU`, `BATTLE_SETTINGS`.
`Battle Settings` tiene 6 filas: DUEL_TIME, COM_LEVEL, REFEREE, TRANSFORMATIONS, MAP_SETTING, DEFAULT
(el **valor** de cada fila todavia no esta mapeado; el cursor es `duelObj+0x13C`).

### API
```cpp
ps2x_duelfields::Fields f = ps2x_duelfields::subtype(VsMode::P1VsP2, BattleType::DP, DpVariant::DP15);
ps2x_duelfields::writeDuelObject(rdram, f);   // cada frame hasta el confirm (el menu pisa el cursor)
ps2x_duelfields::writeCommitted (rdram, f);   // re-afirmar en 0x27/0x28
ps2x_duelfields::apply         (rdram, f);    // las dos mitades (el "write completo")
ps2x_duelfields::read(rdram); ps2x_duelfields::format(f, buf, n);
```

### Como se usa hoy
El `start` del netmenu (`Jump -> Stamp -> Advance -> Hold`) usa estos metodos: `Stamp`/`Advance`
escriben el duel object, `Hold` re-afirma las copias en `0x27/0x28` y suelta al salir.
El confirm se inyecta por el unico seam que el juego lee: `writeNeutralPadPacket` (game_overrides),
via `ps2xNetMenuPressCross()` (BT3 no llama libpad).
