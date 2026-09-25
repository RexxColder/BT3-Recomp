# New Dragon Net Menu — full implementation

How it was built, what was tested, what failed, and how the method works.

This document covers **all** the work around the new menu (beyond the "ghost" and the state-hosting
infrastructure described in `docs/NETMENU.md`): entry routing, pad gating, conditional AFS serving,
audio, the visual layer, and the final 2D menu.

---

## 0. Goal

A **native Dragon Net menu** that:

1. opens from the hidden entry in the main menu ("Dragon Net Battle", row 4);
2. uses **the game's own transitions** (no hard cut);
3. is drawn **without an ImGui overlay** (engine path);
4. has its own looping music, with the game audio silenced;
5. uses buttons with the real icons from the texture pack (PS2 or Xbox);
6. can be **entered and exited** predictably (Triangle never breaks the logic).

---

## 1. Entry routing

Row 4 of the main menu does not change state (see `NETMENU.md` §1: it is a ghost that fires a sound
effect). To get a screen **and** a native transition, that row is redirected to a **real engine
state** through the **common tail** the other rows use.

- Patch `[netmenutest patch: row4-target]` in handler `0x3367A4`: sets `$a3`, `$t2 = 0x0F`,
  `$v1 = menuObj`, `$t0 = 0x300000` (the tail computes `0x300000-0xEF4 = 0x2FF10C`), `$t1 = 0x26`
  (the **Duel** state) and falls through to tail `0x3364F4`.
- The tail writes `stateObj+0x18 = 0x26` and calls `func_10D878`: the engine runs **its own
  transition** (fade/wipes) and then runs the state handler. That is what gives the native feel.
- With the env off, the patch runs the stock code (`goto label_3367a8`).

**States tried as host**

| State | Result |
|---|---|
| `0x47` | Engine fallback → **broken fight** (both at 0 HP and timer ∞) + the red FMV. Discarded. |
| `0x40` (the Dragon Net unit id per the Wii report) | The table has `0x336E08` (generic). Redirecting it to our trampoline **hung** the guest spinning at `0x336D10`. Discarded. |
| `0x26` (Duel) | **Chosen.** Real state, native transition, stable handler. |

> Wii research note: on the Wii, "Dragon Net Battle" is **unit `0x40`** and the gate is
> `[unit_ctx]+0x14 bit 0x2000`. On the PS2 that state was left as generic (the mode was cut).

---

## 2. Pad gating by **origin**

BT3 **does not use libpad**: the only pad the game sees is built in `writeNeutralPadPacket`
(`game_overrides.cpp`). The seams are injected there:

- `ps2xNetMenuPress(mask, frames)` — synthetic pulse (active-low button).
- `ps2xNetMenuFreeze(on)` — neutralizes the whole pad.
- `ps2xNetMenuGate(on, allowMask)` — **denies everything except** the allowed bits (and forces the
  sticks to neutral). Applied after freeze and before press.

The entry marks its **origin** from the row (`ps2xNetMenuMarkNetEntry()`), and the menu tick keeps a
**session latch**: it starts at the row and ends when the main menu returns.

**Locks (in order of appearance)**

| Lock | Duration | Purpose |
|---|---|---|
| Entry lock | **1.4 s** (independent of `PS2X_NETMENU`) | so the Cross that enters does not confirm anything on the first frame |
| "hosted" gate | while the menu owns the screen | so the real state behind does not react |
| "st == 0x04" gate | while the state is still in the main menu | covers the X→Duel transition window |
| Exit lock | 30 ms | so a second Triangle does not bounce during the exit |

The entry lock is applied **also to the menu's own input** (`ps2x_net_menu::isEntryLocked()`),
because the page reads the physical pad on its own and the guest gate does not stop it.

---

## 3. Conditional AFS serving

`ps2xNetServeSwapLoad/Off/Read` (`game_overrides.cpp`) plus a hook in `readFolderRange`
(`Kernel/Stubs/Helpers/Support.h`): while the NET entry is active, a **chosen AFS slot** is served
from an in-memory image instead of the folder file. Outside the entry, original bytes.

- Validated with the **BGM**: slot `64979` (Duel BGM) ← `zs3_08_US.adx`. Heard correctly.
- `ps2xNetServeMuteSlots("a,b,c")` serves the **same image** (valid silence) in other slots: serving
  raw zeros made the decoder emit **noise**.
- The serve is armed **at the row** (`ps2xNetMenuArmSwap()`), not in the tick: arming it one frame
  later left the BGM stream already open with the original bytes.

---

## 4. Audio

The net entry owns the whole audio picture: it silences the game, plays its own music, and plays the
game's **own** UI sound effects (no extracted WAVs).

### 4.1 Silencing the game

- `freezeAudio()` lowers `music` **and** `sfx` (the backend groups voices under SFX) to 0; master is
  untouched. `thawAudio()` is called **at release** (when the main menu is already back), not at the
  end of the fade-out: doing it earlier produced a **BGM blip**.

### 4.2 Own background music

- `ps2x_net_music.cpp` uses **raylib** audio (`InitAudioDevice` + `LoadMusicStream`,
  `Music.looping = true`, `UpdateMusicStream` per frame). It loops while the entry is active and stops
  when it ends.
  - `PS2X_NETMENU_MUSIC=<path>` (default `assets/DragonNet/music/netmenu.mp3`)
  - `PS2X_NETMENU_MUSIC_VOL=<0..1>` (default 0.5)

### 4.3 UI sound effects — the game's own SE engine (no WAVs)

The menu plays the **same SEs the retail menus use**, straight from the game's own sound engine.

- **Where they come from**: the system effects live in `data/DATA/PZS3US1/SE_System.pak`, a Sony
  **SCEI SGB** bank (chunks `Vers`/`Head`/`Vagi`/`Setb`, byte-swapped) whose samples are PS2
  **SPU-ADPCM**. During research they were decoded (SGB -> VAG -> WAV) and identified by ear; the WAVs
  are **not shipped** — the game decodes and mixes them at runtime.
- **How they are played**: `ps2x_net_sfx.cpp` calls `ps2xMenuSePlay(bank=1, idx)`
  (`game_overrides.cpp`), which drives the runtime's existing `sePlay()`: it decodes the bank the game
  already uploaded to RAM and hands it to the SE voice mixer, mixed into the reserved SE stream
  (`kSeStreamId = 0xF0`) and out through the **same audio backend the game uses**
  (`ps2x_audio`). Because `sePlay` needs `rdram` + `runtime`, `bt3FrameKick()` stashes both every
  frame.
- **Index map** (system bank A, matching the retail usage in `seName()`):

  | Event | SE idx | | Event | SE idx |
  |---|---|---|---|---|
  | Cursor move | 0 | | Popup open | 4 |
  | Confirm | 1 | | Popup close | 5 |
  | Netplay exit (Triangle at base) | 5 | | Error | 7 |

- **Audible while frozen**: `freezeAudio()` sets `sfx` volume to 0, which would also silence the SE
  stream. So a bypass flag (`ps2xSeMenuBypass`) makes `PS2AudioBackend::serviceStreams()` keep stream
  `0xF0` at a fixed menu level (~0.6 * master) while the entry is up — the menu's effects are heard
  without unmuting the game's own voices.
- **Env**: `PS2X_NETMENU_SFX=0` disables the menu SE. If the bank was not captured it logs
  `[netsfx] game SE bank not captured`.
- **Why not raylib's own sounds**: opening raylib's audio device plays the effects on a **separate**
  device at full scale (oversaturated, not ducked with the game). Everything must go through
  `ps2x_audio` / the game backend.

---

## 5. Visual layer: the road to the GS

The ImGui overlay was discarded and we went to draw through the **engine path**. The journey:

1. **Black-all via textures** (`ps2_texreplace` with black PNGs): it worked, but was a huge amount
   of work and **leaked** outside the entry (the GPU cache). Gated with `ps2xNetEntryActive()` and
   with flush on enter/exit. Discarded for maintenance cost.
2. **Black via GS** (`ps2x_net_gs.cpp`): a full-screen black quad with **rlgl immediate**
   (`rlBegin/rlTexCoord2f/rlColor4ub/rlVertex2f/rlEnd`). Simple and sufficient.
3. **Layering** (what the user asked for): the **new menu goes on top of the original menu**, and the
   **fade/black goes on top of both**:
   - entry: black goes **1 → 0** (reveals the menu);
   - exit: cuts to **1** (full black, no fade) — `blackLevel()`.
4. **Menu's own fade** (`menuFade()`, ~250 ms) for smooth enter and exit.

**Bug found and fixed**: mixing immediate `rlBegin/rlEnd` with raylib **batched** geometry (the
menu's `Draw*` calls) left the previous texture (the **font atlas**) bound, and the fade quad sampled
the atlas (the glyph grid across the whole screen). Fix: `rlDrawRenderBatchActive()` (batch flush)
**before** the quad.

---

## 6. The 2D menu (`ps2x_net_menu2d.cpp`)

### Rendering
**raylib** 2D API (same engine, no ImGui): `DrawRectangle*`, `DrawTexturePro`, `DrawTextEx`,
`DrawRectangleGradientV`, `DrawRectangleRounded`, `DrawCircleV`, `DrawLineEx`, `BeginScissorMode`.
The aliases live in `gfx/bt3gl_api.h` (section `[netmenu2d]`).

### Coordinates
Design canvas **1000×562** (from `PLAN-menu-dragon-net.md`) mapped to the game's **display rect**.
**Widescreen is forced ON for the whole game** (`PS2SettingsOverlay::isWidescreen()` returns `true`),
so the menu **fills the window with no black bars**.

### Layout (Phase 1)
Namek background in `cover`, cloud strip with drift (~60 s), glass panel with gradient + border +
corner brackets, title + badge, 3 entries with a pulsing orange cursor and gold gradient on the
selected one, status ticker (a single sliding message, news-portal style), static ship, Frieza with
idle bob (~3.4 s), and a navy bottom bar.

### Popups (Phase 2)
Centered card (640×380) with a dark backdrop and an animated entrance (fade + slide ~180 ms):

| Screen | Content | Actions |
|---|---|---|
| **Browse Game** | `ROOM / TYPE / PLAYERS / PING` table with 5 mock rooms and ping colors | □ Filters · ✕ Join · △ Back · ←/→ page |
| **Filters** (nested) | 3 dropdowns (`< value >`) | ✕ Apply · △ Cancel |
| **Host Game** | name, type, time, password toggle | ✕ Create room · △ Cancel |
| **Settings** | profile (user/region) + default battle (timer) | ✕ Save · △ Cancel |

The data is **mock** (there is no backend): the line "Backend in development" is kept.

### Input and popup exit
- **↑/↓** navigate rows; **←/→** change a dropdown's value.
- **○ = confirm** (Apply/Create/Save).
- **△ = close/hierarchical back**: popup → base; Filters → Browse.
- **△ with a popup open does NOT exit the net entry**: the netmenu only exits if
  `ps2x_net_menu2d::atBase()`.
- **Bug fixed**: when closing the popup with △, the netmenu saw `atBase()` already in Main **on the
  same press** and fired the exit. `s_tConsumed` (20 frames, atomic) was added: the menu marks that
  it consumed that △ and the netmenu ignores it (`!triangleConsumed()`).

### Button icons
From the pack **`D:\4K 2D Textures Lite.7z`** → `Original Buttons\Buttons\*.dds` (PS2) and
`Xbox Layout\Buttons\*.dds` (Xbox), converted to PNG with ffmpeg and copied to
`assets/DragonNet/buttons/{ps,xbox}/`. The layout is read with `ps2tex::packButtonLayout()`
(0 = PS2, 1 = Xbox) from `savedata/settings.toml [video] button_layout`.

**Mapping applied**: `✕ = A`, `○ = B`, `□ = X`, `△ = Y` (+ L1/LB, L2/LT, R2/RT available).

### Assets

All menu runtime files live under **`assets/DragonNet/`** (plus the font already in `assets/fonts/`).
They are opened **relative to the working directory** (the front-end runs with `-WorkingDirectory
<deploy>`); the build stages the repo's `assets/` next to the executable.

| Path | Used for |
|---|---|
| `assets/fonts/RussoOne-Regular.ttf` | menu font |
| `assets/DragonNet/menu/*.png` | background (Namek), clouds, ship, Frieza, badge |
| `assets/DragonNet/buttons/{ps,xbox}/*.png` | button icons (layout from `savedata/settings.toml`) |
| `assets/DragonNet/music/netmenu.mp3` | looping BGM |
| `assets/DragonNet/*.ps2.pak`, `silence.adx` | optional AFS serve-swap data (`PS2X_NETMENU_SWAP_FILE`) |
| `assets/DragonNet/textures/*.png`, `sfx/` | F3 / experiments (not used by the menu itself) |

The **UI sound effects are not an asset**: they come from the game's own data
(`data/DATA/PZS3US1/SE_System.pak`) decoded at runtime (see §4.3).

---

## 7. File map

| File | Role |
|---|---|
| `ps2x_net_menu.{h,cpp}` | Page/session logic: entry, gate, locks, fade, black, release |
| `ps2x_net_menu2d.cpp` | The 2D menu (raylib): layout, popups, input, icons, its own fade |
| `ps2x_net_gs.cpp` | Black/fade quad via rlgl immediate (on top of everything) |
| `ps2x_net_music.cpp` | Host music loop (raylib audio) |
| `ps2x_netmenutest.cpp` | Relocated state table + injected trampoline |
| `ps2x_injected.{h,cpp}` | `addr → C++ body` registry consulted in `lookupFunction()` |
| `game_overrides.cpp` | Pad seam (`Press/Freeze/Gate`), AFS serve, per-frame hooks |
| `Support.h` | Conditional-serve hook in `readFolderRange` |
| `ps2_texreplace.{h,cpp}` | `packButtonLayout()` (+ the black-all, currently off) |
| `bt3gl_api.h` | Bridge to raylib; `[netmenu2d]` aliases |
| `apply_overlay_patches.py` | Overlay patches (reveal, state table, row4-target) |

### Env vars

| Var | Effect |
|---|---|
| `PS2X_NET_MENU=1` | enables the ENTIRE new menu (entry, gate, serve, audio, 2D) |
| `PS2X_NETMENU_MUSIC` / `_VOL` | track and volume |
| `PS2X_NETMENU_SWAP_SLOT` / `_FILE` | AFS slot and image to serve |
| `PS2X_NETMENU_MUTE_SLOTS` | extra slots to silence (same image) |
| `PS2X_NETMENU_GATE_MASK` | gate mask (only when the page is not up) |
| `PS2X_BUTTONS` | `ps2`/`xbox` (override the icon layout) |

---

## 8. What was tested and how it turned out

- **Entry**: X on the hidden row → native transition → the menu appears at base. ✔
- **Exit**: △ at base → returns to the main menu with the game's transition. ✔
- **Popups**: X opens; △ closes (without exiting); ○ confirms; ←/→ change dropdowns. ✔
- **Audio**: only the menu's own music, no blip on exit, no game SFX/BGM. ✔
- **Visual**: full-screen menu (no bars), fade on top of the menu. ✔
- **Icons**: the pack icons show (Xbox with `button_layout = 1`). ✔

### What failed (documented so it is not repeated)
- ImGui overlay: not "native" and input/state stayed coupled.
- State `0x40`/`0x47` as host: fallback/broken fight/freeze.
- Black-all via textures: leaked and was high-maintenance.
- Immediate rlgl without a batch flush: the fade sampled the font atlas.
- `packButtonLayout` inside an anonymous namespace: link error; exposed with `extern "C"`.
- State table at `0x00D00000`: clobbered by the heap; moved to `0x01F80000`.

---

## 9. Pending

- **The entry lock and the black are timed, not state-driven** (open, 2026-09-25). On the row press
  `markNetEntry()` arms `s_enterLockMs = now + 1400` and the pad gate stays denied while
  `s_hosted || exitLocked() || enterLocked() || st == kMainMenuState`; `ps2xNetMenuFreeze()` also
  holds for as long as the page is hosted. So how long the player stares at a black screen with a
  dead pad depends on a wall-clock guess, not on how far the game actually got: a slow load lifts it
  mid-transition, and a fast one leaves it up over a live screen. **Wanted: hold both until the
  guest reaches character selection, then hand the image and the pad back to the player.**
  - The flow is `0x04 → 0x26` (Duel) and the engine "commits and switches to `0x27`"
    (`ps2x_net_menu.cpp:159-161`), so `0x27` is the likely release point — but that is read off a
    comment, not measured.
  - `PS2X_NETMENU_TRACE=1` now logs every state change while the entry is latched
    (`[netmenu-trace] state 0x.. (pad denied|live, black .., hosted ..)`). Run the Duel once with
    it, confirm which state is character select, and key the release to that.
  - Keep the timer as a failsafe ceiling so a state that never arrives cannot strand the player on a
    black screen with a dead pad — that is the failure mode worth guarding.
- **Phase 3 — sounds**: reuse the game's SE (hover/confirm/cancel) or extract them from the pack.
- Popup polish (transitions, more options, validations).
- **F3 — Wii assets**: the real Dragon Net paks (`DragonNet_UP/US.pak`) exist on the Wii and use the
  **same container** as the PS2 (BE→LE) with the **same LZ** as the `.cpak` files; the PS2 engine
  decompresses them (validated). Still missing: the texture↔palette mapping and replacing the menu
  assets.
