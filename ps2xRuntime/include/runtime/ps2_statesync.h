// [statesync] Portable serialisation of the rollback snapshots, for the netplay state sync.
//
// The in-process rollback snapshot (Ps2xRollback in ps2_runtime.cpp) copies fiber stacks verbatim,
// which only means something inside the process that made them. The state sync sends the OTHER
// half -- guest memory, emulated devices, kernel records, every guest thread's R5900 context and
// the scheduler's bookkeeping -- to a peer that is parked at a structurally identical point (every
// guest fiber inside the same host call chain), which then adopts it in place. Each snapshot owner
// (game_overrides.cpp, Thread.cpp, SIF.cpp, ps2_memory.cpp) serialises its own opaque struct with
// these two helpers; the byte layout is only ever read by the same binary (the blob carries the
// executable's build id), so PODs go through raw.
#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>

struct Ps2xByteW
{
    std::vector<uint8_t> &b;
    explicit Ps2xByteW(std::vector<uint8_t> &out) : b(out) {}
    void raw(const void *p, size_t n) { if (n) { const size_t o = b.size(); b.resize(o + n); std::memcpy(b.data() + o, p, n); } }
    template <typename T> void pod(const T &v) { raw(&v, sizeof v); }
    void u8(uint8_t v) { pod(v); }
    void u32(uint32_t v) { pod(v); }
    void u64(uint64_t v) { pod(v); }
    void i64(int64_t v) { pod(v); }
    void bytes(const std::vector<uint8_t> &v) { u64(v.size()); raw(v.data(), v.size()); }
    template <typename T> void podVec(const std::vector<T> &v) { u64(v.size()); raw(v.data(), v.size() * sizeof(T)); }
    template <typename K, typename V> void podUMap(const std::unordered_map<K, V> &m) { u64(m.size()); for (const auto &kv : m) { pod(kv.first); pod(kv.second); } }
    template <typename K, typename V> void podMap(const std::map<K, V> &m) { u64(m.size()); for (const auto &kv : m) { pod(kv.first); pod(kv.second); } }
    void tp(std::chrono::steady_clock::time_point t) { i64((int64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(t.time_since_epoch()).count()); }
    void str(const std::string &s) { u64(s.size()); raw(s.data(), s.size()); }
};

struct Ps2xByteR
{
    const uint8_t *p, *e; bool ok = true;
    Ps2xByteR(const uint8_t *data, size_t n) : p(data), e(data + n) {}
    bool raw(void *dst, size_t n) { if (!ok || (size_t)(e - p) < n) { ok = false; return false; } if (n) std::memcpy(dst, p, n); p += n; return true; }
    template <typename T> T pod() { T v{}; raw(&v, sizeof v); return v; }
    uint8_t u8() { return pod<uint8_t>(); }
    uint32_t u32() { return pod<uint32_t>(); }
    uint64_t u64() { return pod<uint64_t>(); }
    int64_t i64() { return pod<int64_t>(); }
    size_t count(size_t elemSize) { const uint64_t n = u64(); if (!ok || n > (uint64_t)(e - p) / (elemSize ? elemSize : 1)) { ok = false; return 0; } return (size_t)n; }
    void bytes(std::vector<uint8_t> &v) { const size_t n = count(1); v.resize(ok ? n : 0); raw(v.data(), v.size()); }
    template <typename T> void podVec(std::vector<T> &v) { const size_t n = count(sizeof(T)); v.resize(ok ? n : 0); raw(v.data(), v.size() * sizeof(T)); }
    template <typename K, typename V> void podUMap(std::unordered_map<K, V> &m) { m.clear(); const size_t n = count(sizeof(K) + sizeof(V)); for (size_t i = 0; i < n && ok; ++i) { K k = pod<K>(); V v = pod<V>(); m[k] = v; } }
    template <typename K, typename V> void podMap(std::map<K, V> &m) { m.clear(); const size_t n = count(sizeof(K) + sizeof(V)); for (size_t i = 0; i < n && ok; ++i) { K k = pod<K>(); V v = pod<V>(); m[k] = v; } }
    std::chrono::steady_clock::time_point tp() { return std::chrono::steady_clock::time_point(std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::nanoseconds(i64()))); }
    std::string str() { const size_t n = count(1); std::string s(ok ? n : 0, '\0'); raw(s.data(), s.size()); return s; }
    size_t left() const { return (size_t)(e - p); }
};

// The snapshot owners' portable forms. Each Serialize appends to `out`; each Deserialize returns a
// fresh snapshot object (the same opaque type the Capture/Restore/Free trio uses) or nullptr.
extern "C" bool  ps2xSimSnapSerialize(const void *snap, std::vector<uint8_t> &out);        // game_overrides.cpp
extern "C" void *ps2xSimSnapDeserialize(const uint8_t *data, size_t n, size_t *used);
extern "C" bool  ps2xKernelStateSerialize(const void *snap, std::vector<uint8_t> &out);    // Kernel/Syscalls/Thread.cpp
extern "C" void *ps2xKernelStateDeserialize(const uint8_t *data, size_t n, size_t *used);
extern "C" bool  ps2xSifStateSerialize(const void *snap, std::vector<uint8_t> &out);       // Kernel/Stubs/SIF.cpp
extern "C" void *ps2xSifStateDeserialize(const uint8_t *data, size_t n, size_t *used);
extern "C" bool  ps2xMemDeviceSerialize(const void *snap, std::vector<uint8_t> &out);      // ps2_memory.cpp
extern "C" void *ps2xMemDeviceDeserialize(const uint8_t *data, size_t n, size_t *used);
