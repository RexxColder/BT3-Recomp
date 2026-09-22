# Bug fixes TODO

Source: user reports (Discord). Their wording is kept close to verbatim so nothing gets lost;
`->` lines are our notes / where to look.

Performance measurements (renderer x upscale, hardware) live in
[`docs/PERFORMANCE-METRICS.md`](PERFORMANCE-METRICS.md).

---

## 1. Big audio delay (overlapping sounds)
There is a big audio delay, specially noticeable if you try to play one audio while another is
already playing. You can see so in the **character select**.
> -> audio scheduling/latency: the character-select screen fires many short SFX; check the SPU2
> mixing/queue depth and how a new voice is started while one is still playing.

## 2. Graphical corruption at the start and end of fights
Seen at the start and at the end of fights.
> -> already known/reported. Re-check with the OpenGL path; likely the transition frames
> (fade/wipe) around the fight intro/outro.

## 3. **Characters leak between fights** (the big one)
After playing one duel and then playing again with the **same characters**, some of the player's
characters were mixed with the enemy ones: got Android 17 and 18 doing Gohan attacks and having his
voicelines. Some attacks did connect (same type), others did not. For example
`L2 + Up + Triangle` is a projectile burst for both Gohan and Android 18, so that did hit. Sometimes
it was also impossible to charge Ki. The bug also results in **very wrong replay data**.
> -> character/side state is not reset (or is stale) between matches: the player slot ends up
> driving the enemy's move set / voice bank. Check per-character state and the player vs enemy slot
> assignment at match (re)start, plus anything cached per character id (game_overrides tables,
> voice/move lookups).

## 4. Aspect ratio differs between renderers
It used **4:3 by default on OpenGL**, but with Vulkan (which also switches to OpenGL) it uses
something close to **16:9 which doesn't cover the whole screen**.
> -> the reported Vulkan path falls back to OpenGL, so two different initial display setups end up
> with different aspect/scanout coverage. Check the default display setup and the letterbox/scanout
> region on both entry paths.

## 5. Enabling Glow (Kaioken aura) disables the music
For some reason enabling Glow seems to disable the music.
> -> looks like the glow effect's resource/pass setup is stepping on the audio (or on the frame the
> BGM stream is served on). Check the glow chain against the audio update path.

## 6. Micro freezes (frames pause and resume)
Windows builds (also reported on another build), and on Linux/OpenGL: "frames momentarily freeze
(one could say it pauses) and then it comes back".
> -> the known transient stalls: `[frameprof]`/`[ftspike]` with the diagnostics opt-in, plus the
> upload/readback paths (`[zpagewb]`, the upload budget) and the async-kick races.

## 7. Software renderer: weird purple screen before starting
The software renderer is very slow and shows a weird purple screen before it starts.
> -> looks like an uninitialised framebuffer / clear colour before the first frame.
