#pragma once
// [coverage] Runtime "what still runs interpreted" capture for the recompilation orchestrator.
//
// When PS2X_COVERAGE=<file> is set, the runtime records every code unit that falls back to an
// interpreter instead of recompiled native code, as machine-readable TSV lines. The orchestrator
// reads the file, recompiles the listed units AOT, and repeats until nothing is logged.
//
//   ee_overlay <pc>            a MIPS pc interpreted by ps2_interp (no recompiled function)
//   vu1 <hash> <extent>        a VU1 microprogram whose MPG hash is not in vujit::kPrograms
//   vu0 <hash> <extent>        same for VU0
//
// Deduplicated and bounded; flushed at exit.

#include <cstdint>

namespace ps2cov
{
    void init();                                   // read PS2X_COVERAGE; no-op without it
    bool enabled();

    void noteEeOverlay(uint32_t pc);
    void noteVuProgram(int unit, uint64_t hash, uint32_t extent);   // unit: 0 = VU0, 1 = VU1
}
