#pragma once
// [detmath] Deterministic transcendental functions for the guest.
//
// The guest's libm (sinf, cosf, atan2f, powf, ...) is emulated by calling the HOST libm, and every
// libm rounds these differently: glibc changed its sinf/cosf in 2.28, the Microsoft CRT differs
// from both, and even two Linux machines on different distributions disagree in the last bit.
// One differing bit in a rotation matrix is a desync in netplay. These versions compute in double
// precision with nothing but IEEE-754 basic operations (+ - * / sqrt, and the exact fmod/ldexp/
// frexp), so their results are bit-identical on every IEEE platform compiled without contraction
// (-ffp-contract=off, which the runtime sets on every toolchain). They are accurate to about one
// float ulp, not correctly rounded -- same class as the PS2's own libm.
#include <cstdint>

extern "C" {
float ps2xDetSinf(float x);
float ps2xDetCosf(float x);
float ps2xDetTanf(float x);
float ps2xDetAtanf(float x);
float ps2xDetAtan2f(float y, float x);
float ps2xDetAsinf(float x);
float ps2xDetAcosf(float x);
float ps2xDetExpf(float x);
float ps2xDetLogf(float x);
float ps2xDetLog10f(float x);
float ps2xDetPowf(float x, float y);
// A digest of the results over a fixed input set: equal on two machines = bit-identical math.
uint64_t ps2xDetMathFingerprint();
}
