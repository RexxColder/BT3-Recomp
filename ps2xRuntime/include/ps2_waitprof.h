// [waitprof] Where does a guest thread spend its blocked time? Every blocking wait in the runtime is
// bracketed with a Ps2xWaitScope naming its site; ps2_eeprof.cpp reports ms/s per site every 10 s under
// PS2X_EEPROF (the sampler shows the game thread of a 12400 waiting 83% of a splitscreen frame, and the
// guestprof phase timers charge that wait to "game"). Zero cost when PS2X_EEPROF is unset.
#pragma once
#include <atomic>
#include <chrono>
#include <cstdint>

enum Ps2xWaitSite : int
{
    WP_FRAMEGATE = 0,   // game_overrides [framegate]: waiting for the second vsync tick
    WP_KICKQ_FRAMES,    // enqueueKickJob: two frames already queued for the kick worker
    WP_KICKQ_FULL,      // enqueueKickJob: 8192 jobs queued
    WP_KICK_DRAIN,      // drainKickQueue: waiting for the worker to finish everything
    WP_SCHED_YIELD,     // cooperative scheduler: parked until it is this thread's turn
    WP_SCHED_SLOT,      // cooperative scheduler: slot wait (250 ms bounded)
    WP_HANDOFF,         // guest-execution handoff wait (2 ms bounded)
    WP_SEMA,            // WaitSema
    WP_SYNC_OTHER,      // other kernel sync waits
    WP_THREAD_SLEEP,    // SleepThread / wakeup wait
    WP_WORKER_IDLE,     // kick worker: queue empty
    WP_FENCE_SYNCPATH,  // sceGsSyncPath: drain the worker (the game asked for an idle path)
    WP_FENCE_STOREIMG,  // sceGsExecStoreImage: drain before consuming the VRAM readback
    WP_BARRIER_POST,    // guest side: posted a blocking barrier, waiting for the GL thread to serve it
    WP_BARRIER_UPLOAD,  // guest side: waiting for a pending page flush before a texture upload
    WP_DECPOOL,         // guest side: draining the decode pool at a publish / barrier post [decpool]
    WP_COUNT
};
extern std::atomic<uint64_t> g_ps2xWaitNs[WP_COUNT];
extern std::atomic<uint64_t> g_ps2xWaitN[WP_COUNT];
extern bool g_ps2xWaitProfOn;

struct Ps2xWaitScope
{
    int site; bool on; std::chrono::steady_clock::time_point t0;
    explicit Ps2xWaitScope(int s) : site(s), on(g_ps2xWaitProfOn) { if (on) t0 = std::chrono::steady_clock::now(); }
    ~Ps2xWaitScope()
    {
        if (!on) return;
        const auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - t0).count();
        g_ps2xWaitNs[site].fetch_add((uint64_t)ns, std::memory_order_relaxed);
        g_ps2xWaitN[site].fetch_add(1u, std::memory_order_relaxed);
    }
};
