// Small portability shims for the Windows (clang-cl / MSVC CRT) build. Include after the C headers.
#pragma once
#include <cstddef>
#include <cstring>
#include <algorithm>

#if defined(_WIN32)
// access()/F_OK live in <io.h> as _access on the MSVC CRT.
#include <io.h>
#ifndef F_OK
#define F_OK 0
#endif
static inline int access(const char *path, int mode) { return _access(path, mode); }
// setenv(name, value, overwrite): _putenv_s always overwrites, so honour the flag by hand.
#include <cstdlib>
static inline int setenv(const char *name, const char *value, int overwrite)
{
    if (!overwrite && std::getenv(name)) return 0;
    return _putenv_s(name, value);
}
// memmem is a GNU extension; the MSVC CRT does not have it.
static inline const void *memmem(const void *hay, size_t hn, const void *needle, size_t nn)
{
    if (nn == 0) return hay;
    if (hn < nn) return nullptr;
    const unsigned char *h = static_cast<const unsigned char *>(hay), *n = static_cast<const unsigned char *>(needle);
    const unsigned char *r = std::search(h, h + hn, n, n + nn);
    return r == h + hn ? nullptr : static_cast<const void *>(r);
}
#endif
