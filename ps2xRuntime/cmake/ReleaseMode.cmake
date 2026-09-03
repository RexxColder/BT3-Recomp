include(CheckIPOSupported)

check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT IPO_ERROR)

function(EnableFastReleaseMode TargetName)
    message("> Enabling optimization for: ${TargetName}")
    # clang-cl (the toolset the Windows build uses, see games/bt3/setup.py) reports MSVC=TRUE but does not
    # accept MSVC's /Qspectre- and /GL (whole-program LTCG), and its LTO objects need lld-link: give it the
    # plain optimization subset and no LTO, like the GCC/Clang builds on Linux.
    if(MSVC AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(${TargetName} PRIVATE
            $<$<CONFIG:Release>:/O2 /Ob2 /Oi /Gy /Gw /GF /fp:fast /DNDEBUG /arch:AVX2 /GS->)
        return()
    endif()
    if(MSVC)
        target_compile_options(${TargetName} PRIVATE
            $<$<CONFIG:Release>:
                /O2 # speed
                /Ob2 # inline aggressively
                /Oi # intrinsics
                /GL # whole program opt
                /Gy # function-level linking
                /Gw # global data in COMDAT
                /GF # string pooling
                /Zc:inline # remove unreferenced inline
                /fp:fast # fast math (graphics friendly)
                /DNDEBUG
                /arch:AVX2 # Advanced Vector Extensions 2
                /GS- # Disable Buffer Security Check (faster)
                /Qspectre- # Disable Spectre mitigations (faster)
            >
        )

        if(TARGET ${TargetName})
            target_link_options(${TargetName} PRIVATE
                $<$<CONFIG:Release>:
                    /LTCG # link-time code generation
                    /OPT:REF # remove unreferenced
                    /OPT:ICF # fold identical COMDATs
                >
            )
        endif()
    endif()

    # GCC LTO is disabled: with 97 Unity TUs the linker spawns hundreds of
    # lto1 processes that exhaust system RAM (observed OOM on 16GB box).
    # -O3 already provides most of the speed; the real perf wins come from
    # disabling PS2X_TEXWATCH (32MB per-frame scan) and using ccache.
    if(MSVC AND IPO_SUPPORTED)
        set_property(TARGET ${TargetName} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    endif()
endfunction()