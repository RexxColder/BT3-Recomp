#pragma once
// [fibers] Cooperative execution contexts for guest threads.
//
// WHY: the runtime currently runs each guest thread as a host std::thread, and the deterministic
// scheduler (PS2X_SCHED) already serialises them -- exactly one holds the token and the rest sit in
// schedAcquire's condition_variable. That is cooperative scheduling built out of OS threads, and it
// costs us two things rollback needs:
//   * The HOST never owns a frame boundary. dispatchLoop calls into the guest and waits; BT3's
//     nested CDVD wait loops never unwind back to it, so there is no advance_frame() to call in a
//     loop. See [[bt3-rollback-prereq]].
//   * Each guest thread's host C++ call frames (and its R5900Context, a local in the worker lambda)
//     live on an OS stack we neither own nor can copy, so they cannot go into a savestate.
// Running guest threads on stacks WE allocate fixes both: a switch becomes an explicit call, and the
// stack is ordinary memory that can be snapshotted and restored.
//
// This header is only the primitive. It changes no behaviour on its own.
#include <cstddef>
#include <cstdint>

// One switchable execution context. The stack is owned by the fiber (and therefore snapshottable);
// the entry fiber for an already-running thread owns none.
struct Ps2xFiber;

// Adopt the CALLING thread as a fiber, so it can switch to others and be switched back to. Returns
// a context that owns no stack. Must be called once per host thread before any switch.
Ps2xFiber *ps2xFiberAdoptCurrent();

// Create a fiber that will run fn(arg) on its own `stackSize` stack. It does not start until it is
// switched to. Returns nullptr if the platform has no fiber support.
Ps2xFiber *ps2xFiberCreate(void (*fn)(void *), void *arg, size_t stackSize);

// Switch execution from `from` to `to`. Returns when something switches back to `from`.
void ps2xFiberSwitch(Ps2xFiber *from, Ps2xFiber *to);

// Free a finished fiber and its stack. Never call it on a fiber that is currently running.
void ps2xFiberDestroy(Ps2xFiber *f);

// The stack bytes actually in use, measured from the high end down to the fiber's current stack
// pointer. This is what a savestate needs to copy -- the allocation is generous (BT3 nests deeply)
// but the live portion is small. Returns 0 for the adopted entry fiber, whose stack we do not own.
size_t ps2xFiberLiveStack(const Ps2xFiber *f, const uint8_t **outBase);

bool ps2xFiberSupported();

// [rollback] Snapshot of a PARKED fiber -- its saved register context plus the live part of its
// stack -- into caller-provided storage, and the restore that puts both back so the fiber resumes
// exactly where the snapshot was taken. Only meaningful while the fiber is parked (the scheduler
// has control), and only when its frames reference nothing on the heap that may since have been
// freed: every park site must keep its state on the stack. Sizes vary per snapshot (the live stack
// does), so ask first. Returns 0 / false for the adopted entry fiber and on platforms without it.
size_t ps2xFiberSnapshotSize(const Ps2xFiber *f);
bool ps2xFiberSnapshot(const Ps2xFiber *f, void *buf, size_t size);
bool ps2xFiberRestore(Ps2xFiber *f, const void *buf, size_t size);

// [statesync] The parked fiber's saved register context (a ucontext_t on the ucontext backend, else
// null), for unwinding its host call chain into a structural signature.
const void *ps2xFiberUContext(const Ps2xFiber *f);

// PS2X_FIBERTEST=1: ping-pong two fibers at startup and report. Proves the primitive works on this
// toolchain before anything depends on it.
void ps2xFiberSelfTest();
