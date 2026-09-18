#include "gfx/gl/GlApi.h"

#include <cstdio>
#include <cstring>

#if defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#else
#  include <dlfcn.h>
#endif

namespace ps2xgl
{
#define PS2XGL_DEF(ret, name, args) ret (*gl##name) args = nullptr;
    PS2XGL_FUNCS(PS2XGL_DEF)
#undef PS2XGL_DEF

    namespace
    {
        bool s_ready = false;

        void *clientProc(const char *name)
        {
#if defined(_WIN32)
            // GL 1.1 lives in opengl32.dll; wglGetProcAddress only resolves 1.2+.
            static HMODULE gl = ::GetModuleHandleA("opengl32.dll");
            if (!gl) gl = ::LoadLibraryA("opengl32.dll");
            return gl ? reinterpret_cast<void *>(::GetProcAddress(gl, name)) : nullptr;
#else
            return dlsym(RTLD_DEFAULT, name);
#endif
        }
    }

    bool LoadGl(void *(*getProc)(const char *))
    {
        if (!getProc) return false;
        int missing = 0;
        auto load = [&](const char *name) -> void *
        {
            void *p = getProc(name);
            if (!p) p = clientProc(name);
            if (!p) ++missing;
            return p;
        };
#define PS2XGL_LOAD(ret, name, args) gl##name = reinterpret_cast<ret (*) args>(load("gl" #name));
        PS2XGL_FUNCS(PS2XGL_LOAD)
#undef PS2XGL_LOAD

        // glBindFragDataLocationIndexed is optional (dual-source blending); the layer disables
        // the dual-source path when it is absent.
        if (!glBindFragDataLocationIndexed) ++missing;   // tolerated below via Ready()-time check

        const GLubyte *ver = glGetString ? glGetString(GL_VERSION) : nullptr;
        std::fprintf(stderr, "[altGL] loader: GL_VERSION=%s missing=%d\n",
                     ver ? reinterpret_cast<const char *>(ver) : "(null)", missing);

        // Essentials for the altGL layer (2D quads/triangles, textures, FBOs, shaders).
        s_ready = glClear && glViewport && glScissor && glEnable && glDisable && glGenTextures &&
                  glBindTexture && glTexImage2D && glGenBuffers && glBindBuffer && glBufferData &&
                  glGenVertexArrays && glBindVertexArray && glVertexAttribPointer &&
                  glEnableVertexAttribArray && glDrawArrays && glGenFramebuffers &&
                  glBindFramebuffer && glFramebufferTexture2D && glCheckFramebufferStatus &&
                  glCreateShader && glShaderSource && glCompileShader && glCreateProgram &&
                  glAttachShader && glLinkProgram && glUseProgram && glGetUniformLocation &&
                  glUniform4f && glUniformMatrix4fv;
        return s_ready;
    }

    bool Ready() { return s_ready; }
}
