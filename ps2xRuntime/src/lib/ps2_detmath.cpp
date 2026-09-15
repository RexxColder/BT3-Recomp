// [detmath] See include/runtime/ps2_detmath.h.
//
// Every function reduces its argument with exact operations (products of a few-bit constant and
// a small integer, fmod, ldexp, frexp) and evaluates a short power series in double precision,
// whose error is far below a float ulp. Nothing here depends on the host's libm, rounding-mode
// changes are never made, and no operation can be contracted into a fused multiply-add when the
// TU is compiled with -ffp-contract=off (the build sets it; see CMakeLists.txt).
#include "runtime/ps2_detmath.h"

#include <cmath>
#include <cstring>
#include <limits>

namespace
{
    constexpr double kPi      = 3.14159265358979323846;
    constexpr double kPiO2    = 1.57079632679489661923;
    constexpr double kPiO4    = 0.78539816339744830962;
    constexpr double kInvPiO2 = 6.36619772367581382433e-01;    // 2/pi
    // pi/2 split so that n * kPio2Hi is exact for |n| < 2^28 (kPio2Hi carries 25 significant bits)
    constexpr double kPio2Hi  = 1.57079631090164184570e+00;    // 0x3FF921FB50000000
    constexpr double kPio2Lo  = 1.58932547735281966916e-08;
    constexpr double kLn2     = 6.93147180559945309417e-01;
    constexpr double kLn2Hi   = 6.93147180369123816490e-01;    // 0x3FE62E42FEE00000, 32 significant bits
    constexpr double kLn2Lo   = 1.90821492927058770002e-10;
    constexpr double kLog2e   = 1.44269504088896338700e+00;
    constexpr double kLn10    = 2.30258509299404568402e+00;

    inline double truncRound(double v) { return static_cast<double>(static_cast<long long>(v + (v >= 0.0 ? 0.5 : -0.5))); }

    // Reduce x to r in [-pi/4, pi/4] with quadrant n (mod 4). Exact for |x| < 2^28 * pi/2; beyond
    // that (|x| > 4e8, where a float argument carries no usable phase anyway) an exact fmod first
    // brings it into range, deterministically.
    int reducePio2(double x, double &r)
    {
        const double ax = x < 0.0 ? -x : x;
        if (ax <= kPiO4) { r = x; return 0; }
        if (ax >= 4.21657428e8) x = std::fmod(x, 2.0 * kPi);     // exact; the quotient error is the caller's problem
        const double fn = truncRound(x * kInvPiO2);
        r = (x - fn * kPio2Hi) - fn * kPio2Lo;
        return static_cast<int>(static_cast<long long>(fn)) & 3;
    }

    // sin r and cos r on [-pi/4, pi/4], Taylor to r^15 / r^14: error < 1e-16 relative.
    double sinK(double r)
    {
        const double z = r * r;
        double p = 1.0 / 1307674368000.0;                       // 1/15!
        p = p * z - 1.0 / 6227020800.0;                          // 1/13!
        p = p * z + 1.0 / 39916800.0;                            // 1/11!
        p = p * z - 1.0 / 362880.0;                              // 1/9!
        p = p * z + 1.0 / 5040.0;                                // 1/7!
        p = p * z - 1.0 / 120.0;                                 // 1/5!
        p = p * z + 1.0 / 6.0;                                   // 1/3!
        return r - r * z * p;                                    // r - r^3/6 + r^5/120 - ...
    }
    double cosK(double r)
    {
        const double z = r * r;
        double p = 1.0 / 87178291200.0;                          // 1/14!
        p = p * z - 1.0 / 479001600.0;                           // 1/12!
        p = p * z + 1.0 / 3628800.0;                             // 1/10!
        p = p * z - 1.0 / 40320.0;                               // 1/8!
        p = p * z + 1.0 / 720.0;                                 // 1/6!
        p = p * z - 1.0 / 24.0;                                  // 1/4!
        p = p * z + 0.5;                                         // 1/2!
        return 1.0 - z * p;                                      // 1 - r^2/2 + r^4/24 - ...
    }

    // atan on any u >= 0: three angle halvings (u/(1+sqrt(1+u^2))) bring |u| under 0.1, where the
    // series to u^19 is below 1e-19.
    double atanPos(double u)
    {
        if (u > 1.0) return kPiO2 - atanPos(1.0 / u);
        int halvings = 0;
        while (u > 0.1 && halvings < 4) { u = u / (1.0 + std::sqrt(1.0 + u * u)); ++halvings; }
        const double z = u * u;
        double p = 1.0 / 19.0;
        p = p * z - 1.0 / 17.0;
        p = p * z + 1.0 / 15.0;
        p = p * z - 1.0 / 13.0;
        p = p * z + 1.0 / 11.0;
        p = p * z - 1.0 / 9.0;
        p = p * z + 1.0 / 7.0;
        p = p * z - 1.0 / 5.0;
        p = p * z + 1.0 / 3.0;
        double a = u - u * z * p;
        for (int i = 0; i < halvings; ++i) a *= 2.0;
        return a;
    }

    // exp on any finite double: n = round(x / ln2), r = x - n ln2 (two-part, exact), e^r by Taylor to
    // r^14 (|r| <= 0.35: error < 1e-17), scaled by 2^n exactly.
    double expD(double x)
    {
        if (x != x) return x;
        if (x > 709.7) return std::numeric_limits<double>::infinity();
        if (x < -745.2) return 0.0;
        const double fn = truncRound(x * kLog2e);
        const double r = (x - fn * kLn2Hi) - fn * kLn2Lo;
        double p = 1.0 / 87178291200.0;                          // 1/14!
        p = p * r + 1.0 / 6227020800.0;                          // 1/13!
        p = p * r + 1.0 / 479001600.0;                           // 1/12!
        p = p * r + 1.0 / 39916800.0;                            // 1/11!
        p = p * r + 1.0 / 3628800.0;                             // 1/10!
        p = p * r + 1.0 / 362880.0;                              // 1/9!
        p = p * r + 1.0 / 40320.0;                               // 1/8!
        p = p * r + 1.0 / 5040.0;                                // 1/7!
        p = p * r + 1.0 / 720.0;                                 // 1/6!
        p = p * r + 1.0 / 120.0;                                 // 1/5!
        p = p * r + 1.0 / 24.0;                                  // 1/4!
        p = p * r + 1.0 / 6.0;                                   // 1/3!
        p = p * r + 0.5;                                         // 1/2!
        p = p * r + 1.0;
        p = p * r + 1.0;
        const int n = static_cast<int>(static_cast<long long>(fn));
        // two ldexp steps keep the intermediate normal when n is at the edges of the double range
        return std::ldexp(std::ldexp(p, n / 2), n - n / 2);
    }

    // log on any positive finite double: x = m 2^e with m in [sqrt(1/2), sqrt(2)),
    // log m = 2 atanh((m-1)/(m+1)) by series (|s| <= 0.172: 12 terms are below 1e-19).
    double logD(double x)
    {
        int e = 0;
        double m = std::frexp(x, &e);                            // m in [0.5, 1)
        if (m < 0.70710678118654752440) { m *= 2.0; --e; }
        const double s = (m - 1.0) / (m + 1.0);
        const double z = s * s;
        double p = 1.0 / 25.0;
        p = p * z + 1.0 / 23.0;
        p = p * z + 1.0 / 21.0;
        p = p * z + 1.0 / 19.0;
        p = p * z + 1.0 / 17.0;
        p = p * z + 1.0 / 15.0;
        p = p * z + 1.0 / 13.0;
        p = p * z + 1.0 / 11.0;
        p = p * z + 1.0 / 9.0;
        p = p * z + 1.0 / 7.0;
        p = p * z + 1.0 / 5.0;
        p = p * z + 1.0 / 3.0;
        p = p * z + 1.0;
        return static_cast<double>(e) * kLn2 + 2.0 * s * p;
    }

    inline bool isIntegerValue(double y) { return y == std::floor(y); }
    inline bool isOddInteger(double y) { return isIntegerValue(y) && std::fmod(y, 2.0) != 0.0; }
}

extern "C" float ps2xDetSinf(float x)
{
    if (x != x || x == std::numeric_limits<float>::infinity() || x == -std::numeric_limits<float>::infinity()) return std::numeric_limits<float>::quiet_NaN();
    double r; const int n = reducePio2(static_cast<double>(x), r);
    switch (n) { case 0: return static_cast<float>(sinK(r)); case 1: return static_cast<float>(cosK(r)); case 2: return static_cast<float>(-sinK(r)); default: return static_cast<float>(-cosK(r)); }
}

extern "C" float ps2xDetCosf(float x)
{
    if (x != x || x == std::numeric_limits<float>::infinity() || x == -std::numeric_limits<float>::infinity()) return std::numeric_limits<float>::quiet_NaN();
    double r; const int n = reducePio2(static_cast<double>(x), r);
    switch (n) { case 0: return static_cast<float>(cosK(r)); case 1: return static_cast<float>(-sinK(r)); case 2: return static_cast<float>(-cosK(r)); default: return static_cast<float>(sinK(r)); }
}

extern "C" float ps2xDetTanf(float x)
{
    if (x != x || x == std::numeric_limits<float>::infinity() || x == -std::numeric_limits<float>::infinity()) return std::numeric_limits<float>::quiet_NaN();
    double r; const int n = reducePio2(static_cast<double>(x), r);
    const double s = sinK(r), c = cosK(r);
    return static_cast<float>((n & 1) ? -c / s : s / c);
}

extern "C" float ps2xDetAtanf(float x)
{
    if (x != x) return x;
    const double a = atanPos(x < 0.0f ? -static_cast<double>(x) : static_cast<double>(x));
    return static_cast<float>(x < 0.0f ? -a : a);
}

extern "C" float ps2xDetAtan2f(float y, float x)
{
    if (x != x || y != y) return std::numeric_limits<float>::quiet_NaN();
    const bool xinf = std::isinf(x), yinf = std::isinf(y);
    const bool xneg = std::signbit(x), yneg = std::signbit(y);
    if (yinf && xinf) { const double a = xneg ? 3.0 * kPiO4 : kPiO4; return static_cast<float>(yneg ? -a : a); }
    if (yinf) return static_cast<float>(yneg ? -kPiO2 : kPiO2);
    if (xinf) { const double a = xneg ? kPi : 0.0; return static_cast<float>(yneg ? -a : a); }
    if (y == 0.0f) { const double a = xneg ? kPi : 0.0; return static_cast<float>(yneg ? -a : a); }
    if (x == 0.0f) return static_cast<float>(yneg ? -kPiO2 : kPiO2);
    const double ay = y < 0.0f ? -static_cast<double>(y) : static_cast<double>(y);
    const double ax = x < 0.0f ? -static_cast<double>(x) : static_cast<double>(x);
    double a = atanPos(ay / ax);
    if (xneg) a = kPi - a;
    return static_cast<float>(yneg ? -a : a);
}

extern "C" float ps2xDetAsinf(float x)
{
    if (x != x || x > 1.0f || x < -1.0f) return std::numeric_limits<float>::quiet_NaN();
    if (x == 1.0f) return static_cast<float>(kPiO2);
    if (x == -1.0f) return static_cast<float>(-kPiO2);
    const double d = x;
    const double a = atanPos((d < 0.0 ? -d : d) / std::sqrt((1.0 - d) * (1.0 + d)));
    return static_cast<float>(d < 0.0 ? -a : a);
}

extern "C" float ps2xDetAcosf(float x)
{
    if (x != x || x > 1.0f || x < -1.0f) return std::numeric_limits<float>::quiet_NaN();
    if (x == 1.0f) return 0.0f;
    if (x == -1.0f) return static_cast<float>(kPi);
    const double d = x;
    return static_cast<float>(2.0 * atanPos(std::sqrt((1.0 - d) / (1.0 + d))));
}

extern "C" float ps2xDetExpf(float x)
{
    if (x != x) return x;
    if (x > 88.8f) return std::numeric_limits<float>::infinity();
    if (x < -104.0f) return 0.0f;
    return static_cast<float>(expD(static_cast<double>(x)));
}

extern "C" float ps2xDetLogf(float x)
{
    if (x != x) return x;
    if (x < 0.0f) return std::numeric_limits<float>::quiet_NaN();
    if (x == 0.0f) return -std::numeric_limits<float>::infinity();
    if (std::isinf(x)) return x;
    return static_cast<float>(logD(static_cast<double>(x)));
}

extern "C" float ps2xDetLog10f(float x)
{
    if (x != x) return x;
    if (x < 0.0f) return std::numeric_limits<float>::quiet_NaN();
    if (x == 0.0f) return -std::numeric_limits<float>::infinity();
    if (std::isinf(x)) return x;
    return static_cast<float>(logD(static_cast<double>(x)) / kLn10);
}

extern "C" float ps2xDetPowf(float x, float y)
{
    // C99 Annex F special cases, then exp(y log|x|) in double (|y log x| < 90 for a finite float result,
    // so the double error stays ~1e-14 absolute in the exponent).
    if (y == 0.0f) return 1.0f;
    if (x == 1.0f) return 1.0f;
    if (x != x || y != y) return std::numeric_limits<float>::quiet_NaN();
    const double dx = x, dy = y;
    const bool yOdd = isOddInteger(dy);
    if (x == 0.0f)
    {
        if (y < 0.0f) return (yOdd && std::signbit(x)) ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
        return (yOdd && std::signbit(x)) ? -0.0f : 0.0f;
    }
    if (std::isinf(y))
    {
        const double ax = dx < 0.0 ? -dx : dx;
        if (ax == 1.0) return 1.0f;
        if ((ax < 1.0) == (y < 0.0f)) return std::numeric_limits<float>::infinity();
        return 0.0f;
    }
    if (std::isinf(x))
    {
        if (x < 0.0f)
        {
            if (y < 0.0f) return yOdd ? -0.0f : 0.0f;
            return yOdd ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
        }
        return y < 0.0f ? 0.0f : std::numeric_limits<float>::infinity();
    }
    double ax = dx; bool neg = false;
    if (dx < 0.0)
    {
        if (!isIntegerValue(dy)) return std::numeric_limits<float>::quiet_NaN();
        ax = -dx; neg = yOdd;
    }
    const double t = dy * logD(ax);
    if (t > 89.0) return neg ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
    if (t < -104.0) return neg ? -0.0f : 0.0f;
    const double r = expD(t);
    return static_cast<float>(neg ? -r : r);
}

extern "C" uint64_t ps2xDetMathFingerprint()
{
    // A fixed pseudo-random sweep through the interesting ranges of every function. Two machines
    // that print the same value compute identical bits.
    uint64_t h = 1469598103934665603ull;
    auto mix = [&](float v) { uint32_t b; std::memcpy(&b, &v, 4); h ^= b; h *= 1099511628211ull; };
    uint32_t s = 0x12345678u;
    auto next = [&]() { s ^= s << 13; s ^= s >> 17; s ^= s << 5; return s; };
    for (int i = 0; i < 20000; ++i)
    {
        const float a = (static_cast<float>(next() & 0xFFFFFFu) / 16777216.0f) * 2000.0f - 1000.0f;   // [-1000, 1000)
        const float u = static_cast<float>(next() & 0xFFFFFFu) / 16777216.0f;                          // [0, 1)
        const float big = a * 1.0e6f;
        mix(ps2xDetSinf(a)); mix(ps2xDetCosf(a)); mix(ps2xDetTanf(a)); mix(ps2xDetSinf(big)); mix(ps2xDetCosf(u * 6.3f));
        mix(ps2xDetAtanf(a)); mix(ps2xDetAtan2f(a, u * 3.0f - 1.5f)); mix(ps2xDetAsinf(u * 2.0f - 1.0f)); mix(ps2xDetAcosf(u * 2.0f - 1.0f));
        mix(ps2xDetExpf(a * 0.09f)); mix(ps2xDetLogf(u * 1000.0f + 1e-6f)); mix(ps2xDetLog10f(u * 1000.0f + 1e-6f));
        mix(ps2xDetPowf(u * 10.0f, a * 0.02f)); mix(ps2xDetPowf(-3.5f, static_cast<float>(static_cast<int>(a) % 9)));
    }
    return h;
}
