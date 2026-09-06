# BT3 Main Menu — Máquina de Estados Completa

## Arquitectura General

```
┌─────────────────────────────────────────────────────────────────────┐
│                    ESTADO GLOBAL (bt3state)                         │
│  Pointer chain: *(*(0x2FF10C) + 0x18)                              │
│  Function: FUN_00336a90 (overlay 0x336a90)                         │
│  Switch: (state - 1) < 0x46 → jump table at 0x3B1130               │
└─────────────────────────────────────────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────────────────────────────────────────┐
│                    ESTADO DEL MENÚ (menu->0x40)                     │
│  Pointer: *(0x3B38D8) -> *(+0x9A4) -> +0x40                        │
│  Valores: 9 = DISPLAYED, 10 = TRANSITIONING                        │
└─────────────────────────────────────────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────────────────────────────────────────┐
│              ITEM STATE (item->0x13C) — Jump Table                  │
│  Table: 0x3B4290 (9 entries, bounds < 10)                          │
│  Dispatcher: f_34D468 (overlay 0x18868)                             │
└─────────────────────────────────────────────────────────────────────┘
```

---

## 1. ESTADOS GLOBALES DEL JUEGO (bt3state)

Leídos de `*(*(0x2FF10C) + 0x18)`.

| Valor | Nombre | Descripción | Transiciones |
|-------|--------|-------------|--------------|
| **0x01** | INTRO | Pantalla de título. Timer auto-advance en `*(0x3B0EB8)+0xC4` cuenta a 0x708 (1800). Fade activo. | → 0x04 |
| **0x04** | MENU_SETUP | Post-intro. Carga overlay del menú. Llama `func_255508`. | → 0x06 |
| **0x06** | LOADING | Fase de carga de assets. Llama `func_124D70(2)`. | → 0x26 |
| **0x26** | PREFIGHT_SETUP | Preparación pre-carga de pelea. Rango 0x26-0x29. | → 0x27, 0x28, 0x06 |
| **0x27** | FIGHT_LOAD | Streaming de personajes/escenarios/sonidos desde disco. Barriers deshabilitables. | → 0x2D |
| **0x28** | FIGHT_LOAD_ALT | Variante de fight-load (cuando `base+0x624 != 0`). | → 0x2D |
| **0x2D** | IN_FIGHT | Pelea activa. Estado más gated: EEROUND2, VUDAZ, BARLOADGATE. | → 0x38, 0x06 |
| **0x38** | POST_FIGHT | Transición especial post-pelea. `base+0x68C |= 1`. | → 0x06, 0x01 |

**Transiciones:**
```
0x01 → 0x04 → 0x06 → 0x26 → 0x27 → 0x2D → 0x38 → 0x06 →循环
```

---

## 2. ESTADO DEL MENÚ PRINCIPAL (menu->0x40)

Pointer: `*(0x3B38D8) → *(+0x9A4) → +0x40`

| Valor | Nombre | Descripción | Dónde se escribe |
|-------|--------|-------------|------------------|
| **9** | DISPLAYED | Menú visible, listo para interacción. Setup completo de placas. | 0x34D904, 0x34DC8C, 0x351428 |
| **10** | TRANSITIONING | Procesando transición. Check `0x190 & 0x8`. | 0x34D904 (ruta alternativa) |

**Check en el dispatcher (line 100705-100775):**
```
lw   $v0, 0x3BC($a2)      ; Load flags
andi $v0, $v0, 0x4        ; Test bit 2 (sub-menu active?)
beqz $v0, .set_state_9    ; If not set → state=9

lw   $a1, 0x9A4($a2)      ; Load sub-struct
lw   $v1, 0x40($a1)       ; Load current state
beq  $v1, $s1, .is_9      ; If state == 9 → full plate setup
beq  $v1, $v0, .is_10     ; If state == 10 → interaction processing
b    .exit                 ; Neither → exit
```

---

## 3. FLAGS GLOBALES (0x3BC)

Offset 956 en el struct principal (`*(0x3B38D8)`).

| Bit | Valor | Nombre | Descripción | Dónde se setea |
|-----|-------|--------|-------------|----------------|
| 0 | 0x01 | INPUT_ENABLED | Input habilitado (check en `0x3C` del struct outer) | — |
| 1 | 0x02 | MENU_INITIALIZED | Menú inicializado y procesando | Line 100692: `ori $v0, $v0, 0x2` |
| 2 | 0x04 | NEEDS_REFRESH | Necesita refresh/redraw. Se TOGGLEA con `xori` | Line 101974, 116989 |
| 3 | 0x08 | SUBMENU_ENTERED | Sub-menú activo | Line 101870: `ori $v0, $v0, 0x8` |
| 4 | 0x10 | TIMER_ACTIVE | Timer/animación activa | Line 101882: `ori $v0, $v0, 0x10` |

---

## 4. FLAGS POR ITEM (0x128)

Offset 296 en el item struct (via `0x8E0` o `0x8E8`).

| Bit | Valor | Nombre | Descripción |
|-----|-------|--------|-------------|
| 0 | 0x001 | NEEDS_REDRAW | Item necesita re-dibujarse |
| 1 | 0x002 | ACTIVE_TOGGLE | Toggle de estado activo |
| 2 | 0x004 | ? | No identificado |
| 3 | 0x008 | GATE | Bloquea transiciones |
| 6 | 0x040 | VISIBLE | Item visible/habilitado |
| 7 | 0x080 | SELECTED | Item seleccionado/activo |
| 9 | 0x200 | ANIM_FLAG | Flag de animación |
| 10 | 0x400 | ANIM_FLAG2 | Flag de animación 2 |
| 11 | 0x800 | HIDDEN | Item oculto — **skip completo en el loop** |

**Referencias encontradas:** 23 en el rango de f_34D468.

---

## 5. FLAGS DE CONFIGURACIÓN POR ITEM (0x190)

Offset 400 en el item struct.

| Bit | Valor | Nombre | Descripción |
|-----|-------|--------|-------------|
| 0 | 0x001 | HAS_PLATE | Item tiene textura de placa para cargar |
| 1 | 0x002 | HAS_SECONDARY | Tiene placa secundaria |
| 2 | 0x004 | HAS_TERTIARY | Tiene elemento terciario |
| 3 | 0x008 | HAS_COMBO | Tiene elemento combo/doble |

**Referencias:** 9 en el rango.

---

## 6. FLAGS DE INPUT (0x190 del struct de input)

| Bit | Valor | Nombre | Descripción |
|-----|-------|--------|-------------|
| 0 | 0x001 | BUTTON_PRESSED | Botón presionado |
| 2 | 0x004 | NAVIGATE | Navegación up/down detectada |
| 3 | 0x008 | CONFIRM | Botón OK presionado |

---

## 7. SEGUNDA TABLA DE DISPATCH (Tipos de Menú)

Table en RAM 0x3B42C0 (overlay 0x07F6C0), 5 entries.

Input: `*(0x2FF28C) → +0xC34` (menu type ID, 0-4).

| Index | Handler | `$s1` | Nombre |
|-------|---------|-------|--------|
| 0 | 0x351970 | 1 | Tipo A |
| 1 | 0x351978 | 2 | Tipo B |
| 2 | 0x351980 | 3 | Tipo C |
| 3 | 0x351988 | 4 | Tipo D |
| 4 | 0x351990 | 0 | Tipo E (default) |

---

## 8. ITEM STATE MACHINE (0x13C) — Los 9 Estados

### State 0: PLATE_LOAD (label_34dd08, line 103046)
**Propósito:** Inicialización de texturas de placa (primera carga)

```
Entry: state == 0
  │
  ├── Check 0x190 bit 0 (HAS_PLATE)
  │   ├── SET: func_349FE0(0x3B4198, a2=0) → func_25F048 → func_349FE0(0x3B4188, a2=0)
  │   │        → label_350b28 → func_349D48 → func_124F68(2,0)
  │   └── NOT SET: → label_34df0
  │
  ├── Check 0x190 bit 1 (HAS_SECONDARY)
  │   └── SET: func_349FE0(secundarias)
  │
  ├── Check 0x190 bit 3 (HAS_COMBO)
  │   └── SET: Check 0x3C20 >= 2 → func_10D878 → sw 1 a 0x140 → func_349FE0
  │
  ├── Check 0x190 bit 2 (HAS_TERTIARY)
  │   └── SET: func_10D878 → sw 1 a 0x140 → func_349FE0
  │
  ├── Check 0x18C bit 0x200 (CHARACTER_SELECT)
  │   └── SET: func_2A9ACC → compare vs 0xA1/0xA3 → func_260D88
  │            → write 0x3C28, 0x3C30
  │
  └── Exit: label_350b28 → func_349D48 → func_124F68 → label_3514cc
```

**State writes:** 0x138 via label_350b28, 0x140 = 1 (combo)

---

### State 1: SECOND_PASS (label_34ea70, line 106383)
**Propósito:** Segunda pasada de texturas (modo highlighted)

```
Entry: state == 1
  │
  ├── Check 0x190 bit 0 (HAS_PLATE)
  │   └── SET: func_349FE0(0x3B4198, a2=1) ← a2=1 es key difference
  │            → func_25F298 (NO func_25F048)
  │            → func_349FE0(0x3B4188, a2=1)
  │
  ├── Check 0x190 bit 1 (HAS_SECONDARY)
  │   └── SET: func_349FE0(secundarias, a2=1)
  │
  └── Exit: label_350b28 → func_349D48 → func_124F68(2,0) → label_3514cc
```

**State writes:** 0x138 via label_350b28
**Diferencia con State 0:** a2=1 (segundo modo), usa func_25F298 en vez de func_25F048

---

### State 2: REFERENCE_COUNTER (label_34f040, line 107856)
**Propósito:** Contador de referencia / validación de conteo

```
Entry: state == 2
  │
  ├── Check 0x190 bit 3 (HAS_COMBO)
  │   └── SET:
  │       ├── Check 0x3C28 < 2 → if true, skip item (s4++)
  │       ├── func_349FE0(0x3B4198, a2=2) ← a2=2
  │       ├── DECREMENT 0x14 counter (counter--)
  │       ├── Check neighbor 0x14 → if < 0, adjust 0x3C20
  │       └── func_349FE0(0x3B4188, a2=2)
  │
  └── Exit: label_3514cc
```

**State writes:** 0x14 (counter--), 0x3C20 (sub-item count)
**NO cambia 0x13C** — permanece en state 2

---

### State 3: ANIMATION (label_34f630, line 109400)
**Propósito:** Manejo de frames de animación / limpieza de flags

```
Entry: state == 3
  │
  ├── func_3528C8 → get frame count ($s0)
  │
  ├── if frames > 0:
  │   ├── func_399730 (tick)
  │   ├── Decrement: frames-1 → store at 0x3D4
  │   └── → label_34f6e4 → state = 2
  │
  ├── if frames == 0:
  │   └── skip → s4++
  │
  └── if frames < 0:
      ├── func_352C60 (cleanup)
      ├── CLEAR 0x128 bit 0x800 (make item visible!)
      ├── func_349FE0(0x3B4188)
      └── → label_34f6e4 → state = 2
```

**State writes:** 0x3D4 (frame count), 0x128 &= ~0x800, 0x13C → 2

---

### State 4: CONFIRM_ACCEPT (label_34f700, line 109623)
**Propósito:** Confirmar / aceptar item (decrementa contadores)

```
Entry: state == 4
  │
  ├── Check input flags 0x398C bits 0x600 (L1/R1 shoulder?)
  │   ├── NOT SET → skip (s4++)
  │   └── SET:
  │       ├── func_399760 (acceptance handler)
  │       └── → label_34f738 (state 5 path)
  │
  └── Exit: func_124F68(1) → label_3514cc
```

**State writes:** Modifica contadores internos
**Diferencia con State 5:** Solo procesa si L1/R1 están presionados

---

### State 5: NAVIGATION (label_34f738, line 109689)
**Propósito:** Navegación / selección de items

```
Entry: state == 5
  │
  ├── Check 0x190 bit 0 (HAS_PLATE)
  │   └── SET: func_349FE0 → decrement counter → func_349FE0 → func_124F68(1)
  │
  ├── Check 0x190 bit 1 (secondary action)
  │   └── SET:
  │       ├── func_349FE0
  │       ├── INCREMENT 0x12C counter (counter++)
  │       ├── Check upper bound: 0x3C30 → if >= max, WRAP to 0
  │       └── func_124F68(1)
  │
  ├── Check 0x18C bit 0x200 (action needed)
  │   └── SET:
  │       ├── sw 0 a 0x140 (clear animation)
  │       ├── func_10D878 (visual update) × 2
  │       └── func_349FE0
  │
  └── Exit: func_124F68(1) → label_3514cc
```

**State writes:** 0x12C (cursor position), 0x140 = 0 (animation clear)

---

### State 6: CHARACTER_SELECT (label_350168, line 112215)
**Propósito:** Selección de personaje con 6 slots

```
Entry: state == 6
  │
  ├── Check 0x190 bit 0 (enabled)
  │   └── SET:
  │       ├── func_349FE0(a2=6) ← 6-slot mode
  │       ├── DECREMENT 0x12C (cursor--)
  │       ├── CLAMP: if cursor < 0 → set to 5
  │       ├── CLAMP: if cursor >= 0x134 → set to 0x134
  │       ├── func_349FE0(a2=6) (second call)
  │       ├── COPY 0x12C → 0x138 (selection value)
  │       └── func_349D48
  │
  ├── Check 0x190 bit 1 (secondary)
  │   └── SET:
  │       ├── func_349FE0(a2=6)
  │       ├── INCREMENT 0x12C (cursor++)
  │       ├── CLAMP: if cursor >= 6 → WRAP to 0
  │       ├── COPY 0x12C → 0x138
  │       └── func_349D48
  │
  └── Exit: func_124F68(1) → label_3514cc
```

**State writes:** 0x12C (cursor 0-5), 0x138 (selection), func_349D48
**Slots:** 6 posibles selecciones (0-5)

---

### State 7: VISUAL_RENDER (label_3509b0, line 114377)
**Propósito:** Render visual de personajes

```
Entry: state == 7
  │
  ├── Check 0x190 bit 0 (enabled)
  │   └── SET:
  │       ├── func_349FE0(a2=7) ← 7-slot mode
  │       ├── Compute: 0x12C * 48 + base → index into 0x3830 table
  │       ├── func_25F048 (character render type A)
  │       └── func_124F68(2)
  │
  ├── Check 0x190 bit 1 (secondary)
  │   └── SET:
  │       ├── func_349FE0(a2=7)
  │       └── func_25EFC8 (character render type B)
  │
  ├── Check 0x190 bit 3 (combo)
  │   └── SET:
  │       ├── func_10D878 (visual update)
  │       ├── sw 1 a 0x140 (animation flag)
  │       ├── func_349FE0(a2=7)
  │       └── func_349D48
  │
  └── Exit: func_124F68(2) → label_3514cc
```

**State writes:** 0x140 = 1 (animation), render data
**Diferencia con State 6:** State 7 renderiza, State 6 selecciona

---

### State 8: FINAL_CONFIRM (label_351388, line 116839)
**Propósito:** Confirmación final — activa sub-menú

```
Entry: state == 8
  │
  ├── Check 0x3BC bit 2 (sub-menu already active?)
  │   └── SET → skip (s4++)
  │
  ├── Check 0x13C == 8 (verify state)
  │   ├── YES:
  │   │   ├── func_10D878 (visual setup)
  │   │   ├── func_25D3F0 (CONFIRMATION HANDLER)
  │   │   ├── func_349FE0(a2=9) ← state 9 setup!
  │   │   ├── SET 0x3BC |= 0x04 (needs refresh)
  │   │   ├── SET 0x3C6C = 1 (transition target)
  │   │   └── SET menu->0x40 = 9 (state → DISPLAYED)
  │   │
  │   └── NO:
  │       ├── Check 0x400 flag
  │       │   ├── SET: func_10D878 → func_349FE0(a2=6)
  │       │   └── NOT SET: skip
  │       └── func_124F68(1)
  │
  └── Exit: label_3514cc
```

**State writes (CRÍTICOS):**
- `0x3BC |= 0x04` (needs refresh)
- `0x3C6C = 1` (transition target)
- `menu->0x40 = 9` (back to DISPLAYED)

---

## 9. CICLO DE VIDA DE UN ITEM

```
                    ┌──────────────┐
                    │  Item Creado │
                    └──────┬───────┘
                           │
                    ┌──────▼───────┐
                    │  State 0     │  PLATE_LOAD
                    │  Carga texturas
                    └──────┬───────┘
                           │
                    ┌──────▼───────┐
                    │  State 1     │  SECOND_PASS
                    │  2da pasada
                    └──────┬───────┘
                           │
                    ┌──────▼───────┐
                    │  State 2     │  REFERENCE_COUNTER
                    │  Valida count
                    └──────┬───────┘
                           │
              ┌────────────┼────────────┐
              │            │            │
       ┌──────▼──────┐ ┌──▼───────┐ ┌──▼──────────┐
       │  State 3    │ │ State 4  │ │  State 5    │
       │  ANIMATION  │ │ CONFIRM  │ │  NAVIGATION │
       │  frames>0:  │ │ L1/R1?   │ │  cursor++/--│
       │  tick       │ │          │ │  wrap 0-5   │
       └──────┬──────┘ └──┬───────┘ └──┬──────────┘
              │            │            │
              └────────────┼────────────┘
                           │
                    ┌──────▼───────┐
                    │  State 6     │  CHARACTER_SELECT
                    │  6 slots     │
                    │  cursor 0-5  │
                    └──────┬───────┘
                           │
                    ┌──────▼───────┐
                    │  State 7     │  VISUAL_RENDER
                    │  Renderiza   │
                    │  personaje   │
                    └──────┬───────┘
                           │
                    ┌──────▼───────┐
                    │  State 8     │  FINAL_CONFIRM
                    │  Confirmación│
                    │  → menu=9    │
                    └──────────────┘
```

---

## 10. ESTRUCTURA DE MEMORIA

### Main Struct (via `*(0x3B38D8)`)
| Offset | Tamaño | Nombre | Descripción |
|--------|--------|--------|-------------|
| 0x08 | ptr | item_array | Base del array de items |
| 0x3C | u32 | outer_flags | Bit 0 = input enabled |
| 0x190 | u32 | item_config | Bit 0=plate, 1=secondary, 2=tertiary, 3=combo |
| 0x3BC | u32 | global_flags | Bits 0-4 (ver sección 4) |
| 0x3C0 | u32 | anim_state | Set to 5 on mismatch |
| 0x3C8 | u32 | expected_val | Expected value for validation |
| 0x3D0 | u32 | timer_init | Initialized to 0x3C (60) |
| 0x3D4 | u32 | timer_count | Remaining animation frames |
| 0x3C20 | u32 | sub_item_count | Number of sub-items |
| 0x3C28 | u32 | double_count | Must be >= 2 for double items |
| 0x3C30 | u32 | max_value | Upper bound for cursor |
| 0x3C38 | u32 | layout_mode | 0=1col, 1=2col, 2=1col |
| 0x3C3C | u32 | validation | == 2 triggers special checks |
| 0x3C58 | u32 | data_offset | Menu data base offset |
| 0x3C6C | u32 | transition | Transition target (0 or 1) |
| 0x38D8 | ptr | menu_ctx | Menu context pointer |
| 0x9A4 | ptr | sub_struct | → +0x40 = menu state |

### Item Struct (via 0x8E8)
| Offset | Tamaño | Nombre | Descripción |
|--------|--------|--------|-------------|
| 0x128 | u32 | flags | Bit 0=redraw, 1=toggle, 6=visible, 7=selected, 11=hidden |
| 0x12C | u32 | cursor | Cursor position / selection index |
| 0x130 | u32 | max_items | Max items for bounds check |
| 0x134 | u32 | upper_bound | Upper bound reference |
| 0x138 | u32 | selection | Copied selection value |
| 0x13C | u32 | **state** | **Item state (0-8, dispatched)** |
| 0x140 | u32 | anim_flag | 0=clear, 1=animation active |
| 0x18C | u32 | action_flags | Bit 9 = character select |
| 0x190 | u32 | config | Bit 0=plate, 1=secondary, 2=tertiary, 3=combo |
| 0x8E0 | ptr | flag_struct | Alternate data pointer |
| 0x8E8 | ptr | state_struct | State/config pointer |
| 0x9B0 | ptr | extra_data | Additional data pointer |

### Render Array (via item + 0xF0, stride 48 bytes)
| Offset | Descripción |
|--------|-------------|
| 0x00 | Render param 1 |
| 0x04 | Render param 2 |
| 0x0C | Some value |
| 0x10 | Width/data |

---

## 11. FUNCIONES HELPER CLAVE

| Función | Dirección | Descripción |
|---------|-----------|-------------|
| `func_349FE0` | 0x349FE0 | **Plate texture loader** — dispatch por modo (0-10). Carga texturas de placa. |
| `func_348F58` | 0x348F58 | **Validation** — check 0x3C3C, bounds check |
| `func_3495D8` | 0x3495D8 | **Item setup** — copia template de 24 bytes, itera 7 veces |
| `func_349D48` | 0x349D48 | **Post-processing** — togglea 0x128 bits, setea bit 0x1 |
| `func_25F048` | 0x25F048 | **Render type A** (normal state) |
| `func_25F298` | 0x25F298 | **Render type B** (highlighted, state 1) |
| `func_25EFC8` | 0x25EFC8 | **Render type C** (secondary) |
| `func_25D3F0` | 0x25D3F0 | **Cursor/navigation** handler |
| `func_10D878` | 0x10D878 | **memcpy/data copy** |
| `func_124F68` | 0x124F68 | **Sound/display sync** (a0=1 general, a0=2 render) |
| `func_3528C8` | 0x3528C8 | **Timer value reader** |
| `func_352C60` | 0x352C60 | **Timer completion** handler |
| `func_399730` | 0x399730 | **Timer tick** |
| `func_399760` | 0x399760 | **Timer tick (variant)** / acceptance |

---

## 12. POSIBILIDADES DE BYPASS

### Bypass 1: Saltar intro (forzar bt3state=0x04)
```cpp
// En game_overrides.cpp, detectar bt3state==0x01 y forzar 0x04
if (bt3State == 0x01u) {
    // Forzar transición a menú
    uint32_t new_state = 0x04u;
    memcpy(rd + (bt3StatePtr + 0x18), &new_state, 4);
}
```

### Bypass 2: Forzar menú displayed (menu->0x40=9)
```cpp
// Detectar menu->0x40 != 9 y forzarlo
if (menuState != 9u) {
    uint32_t displayed = 9u;
    memcpy(rd + (subStruct + 0x40), &displayed, 4);
}
```

### Bypass 3: Forzar item state a 8 (final confirm)
```cpp
// Para cada item, forzar state=8
item->0x13C = 8;
```

### Bypass 4: Manipular cursor
```cpp
// Forzar cursor a posición específica
item->0x12C = desired_position;  // 0-5 para 6 slots
```

### Bypass 5: Limpiar flag hidden
```cpp
// Hacer visible un item oculto
item->0x128 &= ~0x800;  // Clear HIDDEN bit
```

---

## 13. REFERENCIAS

- Dispatcher: `f_34D468` (overlay 0x18868, line 100158)
- Jump table: RAM 0x3B4290 (overlay 0x07F690)
- Second dispatch: RAM 0x3B42C0 (overlay 0x07F6C0)
- Plate loader: `func_349FE0` (overlay 0x153E0)
- Menu struct: `*(0x3B38D8)`
- bt3state: `*(*(0x2FF10C) + 0x18)`
- Status probe: `ps2_runtime.cpp:3896`
