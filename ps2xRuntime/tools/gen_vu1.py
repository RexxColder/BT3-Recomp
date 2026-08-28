#!/usr/bin/env python3
"""gen_vu1.py -- [vu1jit] static VU1 recompiler generator.

Input : the 16 KB microcode images dumped by PS2X_VUMICRO=1 (work/vumicro_<hash>.bin) plus their program extents.
Output: src/lib/vu1_jit_gen.inc -- one C++ function per distinct program body, a label per instruction pair,
        each pair = calls of the compile-time specialised helpers in vu1_jit_ops.inc (jitUpper<W>/jitLower<W>),
        branches = gotos with the delay-slot pair emitted before the jump, JR/JALR = computed goto, E-bit =
        delay-slot pair then return. Anything a helper does not implement falls back to the interpreter via
        vu.jitSlowUpper()/jitSlowLower(), followed by the interpreter's vf0/vi0 reset.
Usage : gen_vu1.py <out.inc> <image.bin:extent_hex> [...]
"""
import sys, struct, hashlib

BRANCH_OPS = {0x20: 'B', 0x21: 'BAL', 0x24: 'JR', 0x25: 'JALR', 0x28: 'IBEQ', 0x29: 'IBNE', 0x2C: 'IBLTZ', 0x2D: 'IBGTZ', 0x2E: 'IBLEZ', 0x2F: 'IBGEZ'}

def upper_is_nop(up):
    funct = up & 0x3F
    if funct < 0x3C: return False
    sub = (up & 3) | ((up >> 4) & 0x7C)
    return sub in (0x2F, 0x30)

def imm11(w):
    v = w & 0x7FF
    return v - 0x800 if v & 0x400 else v

def fnv(data):
    h = 1469598103934665603
    for b in data:
        h = ((h ^ b) * 1099511628211) & 0xFFFFFFFFFFFFFFFF
    return h

def emit_pair_body(out, k, lo, up, pairs, inline_mode):
    """Emit the per-pair code (no label). inline_mode: this pair is emitted as a delay slot -> its own control
    flow (branch/E-bit) is ignored (matches the interpreter: a branch in a delay slot is lost)."""
    pc = 8 * k
    out.append(f'        // pc 0x{pc:x}  lo=0x{lo:08x} up=0x{up:08x}')
    out.append('        ++cyc;')   # [leanpair] the limit is checked at control-flow points only (see gen_program)
    out.append('        if ((st.qWait | g_clipWait) != 0u) { if (st.qWait > 0u && --st.qWait == 0u) st.q = st.pendingQ; if (g_clipWait > 0u && --g_clipWait == 0u) st.clip = g_pendingClip; }   // [pipeidle] one test per pair when both pipelines are idle')
    out.append('        {')
    loi = (up >> 31) & 1
    ebit = (up >> 30) & 1
    op_hi = (lo >> 25) & 0x7F
    is_branch = (not loi) and op_hi in BRANCH_OPS
    up_code = '' if upper_is_nop(up) else f'if (!vujit::jitUpper<0x{up:08x}u>(st)) {{ st.pc = 0x{pc:x}u; vu.jitSlowUpper(0x{up:08x}u); JIT_FB_RESET(); }}'
    if is_branch:
        name = BRANCH_OPS[op_hi]
        vit, vis = (lo >> 16) & 0xF, (lo >> 11) & 0xF
        tgt = ((pc + 8 + imm11(lo) * 8) & 0x3FFF)
        cond = {'B': 'true', 'BAL': 'true',
                'IBEQ': f'((int16_t)st.vi[{vis}] == (int16_t)st.vi[{vit}])', 'IBNE': f'((int16_t)st.vi[{vis}] != (int16_t)st.vi[{vit}])',
                'IBLTZ': f'((int16_t)st.vi[{vis}] < 0)', 'IBGTZ': f'((int16_t)st.vi[{vis}] > 0)',
                'IBLEZ': f'((int16_t)st.vi[{vis}] <= 0)', 'IBGEZ': f'((int16_t)st.vi[{vis}] >= 0)',
                'JR': 'true', 'JALR': 'true'}[name]
        lo_code = []
        if name in ('JR', 'JALR'):
            lo_code.append(f'jtgt = ((uint32_t)(uint16_t)st.vi[{vis}] * 8u) & 0x3FFFu;')
        if name in ('BAL', 'JALR') and vit != 0:
            lo_code.append(f'st.vi[{vit}] = {k + 2};')
        lo_code.append(f'br = {cond};')
        lo_code = ' '.join(lo_code)
    else:
        lo_code = f'if (!vujit::jitLower<0x{lo:08x}u>(st, vuData, dataSize)) {{ st.pc = 0x{pc:x}u; vu.jitSlowLower(0x{lo:08x}u, vuData, dataSize, gs, memory, 0x{up:08x}u); JIT_FB_RESET(); }}'
    if loi:
        out.append(f'            {up_code}')
        out.append(f'            {{ const uint32_t w = 0x{lo:08x}u; std::memcpy(&st.i, &w, 4); }}')
    else:
        out.append(f'            if constexpr (vuLowerShouldRunBeforeUpper(0x{up:08x}u, 0x{lo:08x}u)) {{ {lo_code} {up_code} }}')
        out.append(f'            else {{ {up_code} {lo_code} }}')
    out.append('        }')
    return is_branch, bool(ebit), (BRANCH_OPS[op_hi] if is_branch else None), (((pc + 8 + imm11(lo) * 8) & 0x3FFF) if is_branch else None)

def gen_program(name, image, npairs):
    pairs = [(struct.unpack_from('<I', image, 8 * k)[0], struct.unpack_from('<I', image, 8 * k + 4)[0]) for k in range(npairs)]
    out = []
    out.append(f'static void {name}(VU1Interpreter &vu, VU1State &st, uint8_t *vuData, uint32_t dataSize, GS &gs, PS2Memory *memory, uint32_t maxCycles)')
    out.append('{')
    out.append('    (void)gs; (void)memory;')
    out.append('    uint32_t cyc = 0; bool br = false; uint32_t jtgt = 0; (void)br; (void)jtgt;')
    out.append('    static void *const jt[' + str(npairs) + '] = { ' + ', '.join(f'&&L_{k}' for k in range(npairs)) + ' };')
    out.append(f'    goto *jt[(st.pc >> 3) & {npairs - 1}u];')
    warn = 0
    for k in range(npairs):
        lo, up = pairs[k]
        out.append(f'L_{k}:')
        out.append('    {')
        is_branch, ebit, bname, tgt = emit_pair_body(out, k, lo, up, pairs, False)
        nxt = k + 1
        if ebit:
            # delay slot pair, then stop
            if nxt < npairs:
                nlo, nup = pairs[nxt]
                if ((nlo >> 25) & 0x7F) in BRANCH_OPS or ((nup >> 30) & 1):
                    warn += 1
                emit_pair_body(out, nxt, nlo, nup, pairs, True)
            out.append(f'        st.ebit = true; st.pc = 0x{8 * (k + 2):x}u; return;')   # E-bit ends the run regardless of the limit
        elif is_branch:
            out.append('        if (br) {')
            if nxt < npairs:
                nlo, nup = pairs[nxt]
                if ((nlo >> 25) & 0x7F) in BRANCH_OPS or ((nup >> 30) & 1):
                    warn += 1
                emit_pair_body(out, nxt, nlo, nup, pairs, True)
            if bname in ('JR', 'JALR'):
                out.append(f'            if (cyc >= maxCycles) {{ st.pc = jtgt; return; }}')
                out.append(f'            goto *jt[(jtgt >> 3) & {npairs - 1}u];')
            else:
                out.append(f'            if (cyc >= maxCycles) {{ st.pc = 0x{tgt:x}u; return; }}')
                out.append(f'            goto L_{tgt // 8};')
            out.append('        }')
        out.append('    }')
    out.append(f'    st.pc = 0x{8 * npairs:x}u & 0x3FFFu; return;')
    out.append('}')
    return '\n'.join(out), warn

def main():
    outp = sys.argv[1]
    progs = []
    seen = {}
    for spec in sys.argv[2:]:
        path, ext = spec.split(':')
        image = open(path, 'rb').read()
        extent = int(ext, 16)
        body = image[:extent]
        bh = hashlib.md5(body).hexdigest()[:8]
        if bh in seen:
            continue
        seen[bh] = True
        progs.append((bh, image, extent))
    parts = ['// GENERATED by tools/gen_vu1.py -- do not edit. [vu1jit] static VU1 recompiler output.', '#define JIT_FB_RESET() do { _mm_storeu_ps(st.vf[0], _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f)); st.vi[0] = 0; } while (0)', '']
    total_warn = 0
    for bh, image, extent in progs:
        code, warn = gen_program(f'vu1jit_{bh}', image, len(image) // 8)
        total_warn += warn
        parts.append(code)
        parts.append('')
    parts.append('namespace vujit {')
    parts.append('const Prog kPrograms[] = {')
    for bh, image, extent in progs:
        parts.append(f'    {{ 0x{extent:x}u, 0x{fnv(image[:extent]):016x}ull, &vu1jit_{bh} }},   // body md5 {bh}')
    parts.append('};')
    parts.append(f'const int kProgramCount = {len(progs)};')
    parts.append('}')
    open(outp, 'w').write('\n'.join(parts) + '\n')
    print(f'wrote {outp}: {len(progs)} programs, {sum(len(i)//8 for _, i, _ in progs)} pairs, {total_warn} delay-slot control-flow warnings')

if __name__ == '__main__':
    main()
