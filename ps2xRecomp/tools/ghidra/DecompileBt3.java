// @category PS2Recomp
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
public class DecompileBt3 extends GhidraScript {
    @Override public void run() throws Exception {
        long[] addrs={0x264d70L,0x264b18L,0x264bd0L,0x264bf0L};
        java.io.PrintWriter w=new java.io.PrintWriter(getScriptArgs()[0]);
        DecompInterface dec=new DecompInterface(); dec.openProgram(currentProgram);
        java.util.Set<Long> done=new java.util.HashSet<>();
        for(long a:addrs){
            Address ad=currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(a);
            Function fn=getFunctionContaining(ad);
            if(fn==null){ try{ disassemble(ad); }catch(Exception e){} fn=createFunction(ad,"sub_"+Long.toHexString(a)); }
            if(fn==null||!done.add(fn.getEntryPoint().getOffset())) continue;
            w.println("// ===== "+fn.getName()+" @0x"+Long.toHexString(fn.getEntryPoint().getOffset())+" =====");
            DecompileResults r=dec.decompileFunction(fn,90,monitor);
            w.println(r!=null&&r.decompileCompleted()?r.getDecompiledFunction().getC():"//fail");
        }
        w.close(); println("done");
    }
}
