#ifndef PS2_ARMED_ATOMIC_H
#define PS2_ARMED_ATOMIC_H

#include <atomic>

// [tracearm] One flag for all the guest-store diagnostics. ps2TraceGuestWrite is inlined into every
// recompiled store (millions/s); it used to read three separate atomics per store to find out that
// nothing was armed. Every diagnostic control now goes through this wrapper: a non-zero store() also
// raises g_ps2TraceArmed, so the hook can leave on ONE load. The flag is sticky (never lowered): a
// probe that disarms itself just falls back to the old three-load path, which is what it paid before.
extern std::atomic<uint32_t> g_ps2TraceArmed;

template <class T>
struct Ps2ArmedAtomic
{
    std::atomic<T> v;
    constexpr Ps2ArmedAtomic(T init = T{}) : v(init) {}
    T load(std::memory_order o = std::memory_order_seq_cst) const { return v.load(o); }
    void store(T x, std::memory_order o = std::memory_order_seq_cst)
    {
        if (x != T{}) g_ps2TraceArmed.store(1u, std::memory_order_relaxed);
        v.store(x, o);
    }
};

#endif
