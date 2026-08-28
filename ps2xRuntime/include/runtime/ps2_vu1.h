#ifndef PS2_VU1_H
#define PS2_VU1_H

#include <cstdint>

class GS;
class PS2Memory;

struct VU1State
{
    float vf[32][4];
    int32_t vi[16];
    float acc[4];
    float q;
    float p;
    float i;
    uint32_t pc;
    uint32_t mac;
    uint32_t clip;
    uint32_t status;
    bool ebit;
    uint32_t top;   // VIF1 TOP visible to VU1 XTOP
    uint32_t itop;  // VIF1 ITOP visible to VU1 XITOP

    bool branchPending;
    uint32_t branchTarget;
    uint32_t branchDelay;

    // Q pipeline (PS2X_QPIPE, default ON): on real VU1, DIV/SQRT take 7 cycles and RSQRT 13;
    // the Q register only updates when the unit FINISHES — instructions in the divide's
    // shadow read the OLD Q (games pipeline vertex N's texture math over vertex N+1's DIV).
    // Instant-Q execution mismatched s,t (scaled with old Q) against the stored new Q,
    // producing the fight map's mixed-sign STQ (blue/smeared terrain).
    float pendingQ;
    uint32_t qWait; // cycles until pendingQ commits to q (0 = idle)
};

class VU1Interpreter
{
public:
    VU1Interpreter();

    void reset();

    void execute(uint8_t *vuCode, uint32_t codeSize,
                 uint8_t *vuData, uint32_t dataSize,
                 GS &gs, PS2Memory *memory = nullptr,
                 uint32_t startPC = 0, uint32_t top = 0, uint32_t itop = 0,
                 uint32_t maxCycles = 65536);

    void resume(uint8_t *vuCode, uint32_t codeSize,
                uint8_t *vuData, uint32_t dataSize,
                GS &gs, PS2Memory *memory = nullptr,
                uint32_t top = 0, uint32_t itop = 0, uint32_t maxCycles = 65536);

    VU1State &state() { return m_state; }
    // [vu1jit] the static recompiler's fallbacks and the verify-mode reference run
    void jitSlowUpper(uint32_t instr) { ++m_jitSlowUp; execUpper(instr); }   // [jitstat]
    void jitSlowLower(uint32_t instr, uint8_t *vuData, uint32_t dataSize, GS &gs, PS2Memory *memory, uint32_t upperInstr) { ++m_jitSlowLo; ++m_jitSlowLoHist[(instr >> 25) & 0x7Fu]; if (((instr >> 25) & 0x7Fu) == 0x40u) ++m_jitSlowLoSpec[((instr & 0x3Fu) | ((instr >> 4) & 0x7C0u)) & 0x7FFu]; execLower(instr, vuData, dataSize, gs, memory, upperInstr); }
    uint64_t m_jitSlowUp = 0, m_jitSlowLo = 0;
    void jitStatPrint();   // [jitstat]
    uint64_t m_jitSlowLoHist[128]{}; uint64_t m_jitSlowLoSpec[2048]{};   // [jitstat] lower fallback histogram: op (bits 25-31) / special-group funct   // [jitstat] interpreter fallbacks taken by the recompiled programs
    bool m_dryKick = false;   // verify mode: the reference interpreter run must not emit GS packets
    const VU1State &state() const { return m_state; }

private:
    VU1State m_state;

    void run(uint8_t *vuCode, uint32_t codeSize,
             uint8_t *vuData, uint32_t dataSize,
             GS &gs, PS2Memory *memory, uint32_t maxCycles);

    void execUpper(uint32_t instr);
    void execLower(uint32_t instr, uint8_t *vuData, uint32_t dataSize, GS &gs, PS2Memory *memory, uint32_t upperInstr);

    void applyDest(float *dst, const float *result, uint8_t dest);
    // applyDest + PS2 no-NaN/Inf saturation; for ARITHMETIC results only (see ps2_vu1.cpp).
    void applyDestClamped(float *dst, const float *result, uint8_t dest);
    void applyDestAcc(const float *result, uint8_t dest);
    float broadcast(const float *vf, uint8_t bc);
};

#endif
