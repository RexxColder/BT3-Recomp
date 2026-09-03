// [wintimer] Windows only: ask for a 1 ms scheduler tick for the life of the process.
//
// The runtime paces frames and polls for barrier work with short timed waits (a few hundred
// microseconds to a few milliseconds). On Windows every such wait rounds up to the timer tick,
// 15.6 ms by default, so the GL thread presented 3-30 frames a second in fights where Linux
// presents 50-60. timeBeginPeriod(1) is what every game/emulator does; it is process-wide
// and undone at exit. Lives in its own file because <windows.h> collides with raylib's names.
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")

extern "C" void ps2xWinTimerBegin() { timeBeginPeriod(1); }
extern "C" void ps2xWinTimerEnd() { timeEndPeriod(1); }
#endif
