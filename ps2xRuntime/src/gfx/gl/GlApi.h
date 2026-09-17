#pragma once

// [altGL] Minimal, self-contained OpenGL 3.3 core entry-point table. No raylib/rlgl and no
// generated loader (glad) at build time: every function is resolved through the platform's
// GetProcAddress at Init (SDL_GL_GetProcAddress / glfwGetProcAddress). This mirrors the
// hand-rolled loader the GS renderer already used (ps2xGlProc / wingl), but complete, typed and
// kept free of <windows.h>/GL headers so it can sit next to raylib in the same TU if needed.

#include <cstdint>
#include <cstddef>

namespace ps2xgl
{
    // -------- GL scalar types (values match the OpenGL ABI) --------
    typedef unsigned int   GLenum;
    typedef unsigned char  GLboolean;
    typedef unsigned int   GLbitfield;
    typedef void           GLvoid;
    typedef signed char    GLbyte;
    typedef short          GLshort;
    typedef int            GLint;
    typedef unsigned char  GLubyte;
    typedef unsigned short GLushort;
    typedef unsigned int   GLuint;
    typedef int            GLsizei;
    typedef float          GLfloat;
    typedef float          GLclampf;
    typedef double         GLdouble;
    typedef char           GLchar;
    typedef std::ptrdiff_t GLintptr;
    typedef std::ptrdiff_t GLsizeiptr;

    // -------- tokens used by the altGL layer --------
    enum : unsigned
    {
        GL_FALSE = 0, GL_TRUE = 1,
        GL_NO_ERROR = 0,

        GL_TRIANGLES = 0x0004, GL_QUADS = 0x0007,
        GL_UNSIGNED_BYTE = 0x1401, GL_UNSIGNED_SHORT = 0x1403, GL_UNSIGNED_INT = 0x1405,
        GL_FLOAT = 0x1406,

        GL_TEXTURE_2D = 0x0DE1, GL_TEXTURE0 = 0x84C0,
        GL_TEXTURE_MIN_FILTER = 0x2801, GL_TEXTURE_MAG_FILTER = 0x2800,
        GL_TEXTURE_WRAP_S = 0x2802, GL_TEXTURE_WRAP_T = 0x2803,
        GL_NEAREST = 0x2600, GL_LINEAR = 0x2601, GL_CLAMP_TO_EDGE = 0x812F, GL_REPEAT = 0x2901,
        GL_RGBA = 0x1908, GL_RGBA8 = 0x8058, GL_R8 = 0x8229, GL_RED = 0x1903,
        GL_UNPACK_ALIGNMENT = 0x0CF5, GL_PACK_ALIGNMENT = 0x0D05,

        GL_ARRAY_BUFFER = 0x8892, GL_ELEMENT_ARRAY_BUFFER = 0x8893, GL_STREAM_DRAW = 0x88E0,
        GL_DYNAMIC_DRAW = 0x88E8, GL_STATIC_DRAW = 0x88E4,

        GL_FRAMEBUFFER = 0x8D40, GL_READ_FRAMEBUFFER = 0x8CA8, GL_DRAW_FRAMEBUFFER = 0x8CA9,
        GL_COLOR_ATTACHMENT0 = 0x8CE0, GL_DEPTH_ATTACHMENT = 0x8D00, GL_DEPTH_STENCIL_ATTACHMENT = 0x821A,
        GL_RENDERBUFFER = 0x8D41, GL_DEPTH_COMPONENT24 = 0x81A6, GL_DEPTH24_STENCIL8 = 0x88F0,
        GL_FRAMEBUFFER_COMPLETE = 0x8CD5, GL_DEPTH_COMPONENT = 0x1902,

        GL_BLEND = 0x0BE2, GL_ZERO = 0, GL_ONE = 1, GL_SRC_ALPHA = 0x0302,
        GL_ONE_MINUS_SRC_ALPHA = 0x0303, GL_DST_ALPHA = 0x0304, GL_ONE_MINUS_DST_ALPHA = 0x0305,
        GL_SRC_COLOR = 0x0300, GL_ONE_MINUS_SRC_COLOR = 0x0301, GL_DST_COLOR = 0x0306,
        GL_ONE_MINUS_DST_COLOR = 0x0307, GL_SRC1_ALPHA = 0x8589, GL_ONE_MINUS_SRC1_ALPHA = 0x88FB,
        GL_CONSTANT_COLOR = 0x8001, GL_ONE_MINUS_CONSTANT_COLOR = 0x8002,
        GL_CONSTANT_ALPHA = 0x8003, GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004,
        GL_FUNC_ADD = 0x8006, GL_FUNC_SUBTRACT = 0x800A, GL_FUNC_REVERSE_SUBTRACT = 0x800B,
        GL_MIN = 0x8007, GL_MAX = 0x8008, GL_BLEND_COLOR = 0x8005,

        GL_CULL_FACE = 0x0B44,
        GL_DEPTH_TEST = 0x0B71, GL_DEPTH_FUNC = 0x0B74, GL_DEPTH_WRITEMASK = 0x0B72,
        GL_SCISSOR_TEST = 0x0C11, GL_SCISSOR_BOX = 0x0C10, GL_COLOR_WRITEMASK = 0x0C23,
        GL_NEVER = 0x0200, GL_LESS = 0x0201, GL_EQUAL = 0x0202, GL_LEQUAL = 0x0203,
        GL_GREATER = 0x0204, GL_NOTEQUAL = 0x0205, GL_GEQUAL = 0x0206, GL_ALWAYS = 0x0207,
        GL_COLOR_BUFFER_BIT = 0x4000, GL_DEPTH_BUFFER_BIT = 0x0100, GL_STENCIL_BUFFER_BIT = 0x0400,

        GL_VERTEX_SHADER = 0x8B31, GL_FRAGMENT_SHADER = 0x8B30,
        GL_COMPILE_STATUS = 0x8B81, GL_LINK_STATUS = 0x8B82,

        GL_VENDOR = 0x1F00, GL_RENDERER = 0x1F01, GL_VERSION = 0x1F02,
        GL_TEXTURE_WIDTH = 0x1000, GL_TEXTURE_HEIGHT = 0x1001,
    };

    // -------- function pointers (defined in GlApi.cpp) --------
#define PS2XGL_FUNCS(X) \
    X(void,   Clear, (GLbitfield)) \
    X(void,   ClearColor, (GLfloat,GLfloat,GLfloat,GLfloat)) \
    X(void,   ClearDepth, (GLdouble)) \
    X(void,   Viewport, (GLint,GLint,GLsizei,GLsizei)) \
    X(void,   Scissor, (GLint,GLint,GLsizei,GLsizei)) \
    X(void,   Enable, (GLenum)) \
    X(void,   Disable, (GLenum)) \
    X(void,   DepthFunc, (GLenum)) \
    X(void,   DepthMask, (GLboolean)) \
    X(void,   ColorMask, (GLboolean,GLboolean,GLboolean,GLboolean)) \
    X(void,   BlendFuncSeparate, (GLenum,GLenum,GLenum,GLenum)) \
    X(void,   BlendEquationSeparate, (GLenum,GLenum)) \
    X(void,   BlendColor, (GLfloat,GLfloat,GLfloat,GLfloat)) \
    X(GLenum, GetError, (void)) \
    X(const GLubyte*, GetString, (GLenum)) \
    X(void,   GetIntegerv, (GLenum,GLint*)) \
    X(void,   GetBooleanv, (GLenum,GLboolean*)) \
    X(void,   PixelStorei, (GLenum,GLint)) \
    X(void,   ReadPixels, (GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,void*)) \
    X(void,   Finish, (void)) \
    /* textures */ \
    X(void,   GenTextures, (GLsizei,GLuint*)) \
    X(void,   DeleteTextures, (GLsizei,const GLuint*)) \
    X(void,   BindTexture, (GLenum,GLuint)) \
    X(void,   ActiveTexture, (GLenum)) \
    X(void,   TexImage2D, (GLenum,GLint,GLint,GLsizei,GLsizei,GLint,GLenum,GLenum,const void*)) \
    X(void,   TexSubImage2D, (GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,const void*)) \
    X(void,   TexParameteri, (GLenum,GLenum,GLint)) \
    X(void,   GetTexLevelParameteriv, (GLenum,GLint,GLenum,GLint*)) \
    /* buffers + vao */ \
    X(void,   GenBuffers, (GLsizei,GLuint*)) \
    X(void,   DeleteBuffers, (GLsizei,const GLuint*)) \
    X(void,   BindBuffer, (GLenum,GLuint)) \
    X(void,   BufferData, (GLenum,GLsizeiptr,const void*,GLenum)) \
    X(void,   GenVertexArrays, (GLsizei,GLuint*)) \
    X(void,   DeleteVertexArrays, (GLsizei,const GLuint*)) \
    X(void,   BindVertexArray, (GLuint)) \
    X(void,   EnableVertexAttribArray, (GLuint)) \
    X(void,   VertexAttribPointer, (GLuint,GLint,GLenum,GLboolean,GLsizei,const void*)) \
    X(void,   DrawArrays, (GLenum,GLint,GLsizei)) \
    X(void,   DrawElements, (GLenum,GLsizei,GLenum,const void*)) \
    /* fbo */ \
    X(void,   GenFramebuffers, (GLsizei,GLuint*)) \
    X(void,   DeleteFramebuffers, (GLsizei,const GLuint*)) \
    X(void,   BindFramebuffer, (GLenum,GLuint)) \
    X(void,   FramebufferTexture2D, (GLenum,GLenum,GLenum,GLuint,GLint)) \
    X(GLenum, CheckFramebufferStatus, (GLenum)) \
    X(void,   GenRenderbuffers, (GLsizei,GLuint*)) \
    X(void,   DeleteRenderbuffers, (GLsizei,const GLuint*)) \
    X(void,   BindRenderbuffer, (GLenum,GLuint)) \
    X(void,   RenderbufferStorage, (GLenum,GLenum,GLsizei,GLsizei)) \
    X(void,   FramebufferRenderbuffer, (GLenum,GLenum,GLenum,GLuint)) \
    X(void,   BlitFramebuffer, (GLint,GLint,GLint,GLint,GLint,GLint,GLint,GLint,GLbitfield,GLenum)) \
    X(void,   ReadBuffer, (GLenum)) \
    /* shaders */ \
    X(GLuint, CreateShader, (GLenum)) \
    X(void,   ShaderSource, (GLuint,GLsizei,const GLchar* const*,const GLint*)) \
    X(void,   CompileShader, (GLuint)) \
    X(void,   GetShaderiv, (GLuint,GLenum,GLint*)) \
    X(void,   GetShaderInfoLog, (GLuint,GLsizei,GLsizei*,GLchar*)) \
    X(void,   DeleteShader, (GLuint)) \
    X(GLuint, CreateProgram, (void)) \
    X(void,   AttachShader, (GLuint,GLuint)) \
    X(void,   LinkProgram, (GLuint)) \
    X(void,   GetProgramiv, (GLuint,GLenum,GLint*)) \
    X(void,   GetProgramInfoLog, (GLuint,GLsizei,GLsizei*,GLchar*)) \
    X(void,   DeleteProgram, (GLuint)) \
    X(void,   UseProgram, (GLuint)) \
    X(GLint,  GetUniformLocation, (GLuint,const GLchar*)) \
    X(void,   Uniform1i, (GLint,GLint)) \
    X(void,   Uniform1f, (GLint,GLfloat)) \
    X(void,   Uniform2f, (GLint,GLfloat,GLfloat)) \
    X(void,   Uniform3f, (GLint,GLfloat,GLfloat,GLfloat)) \
    X(void,   Uniform4f, (GLint,GLfloat,GLfloat,GLfloat,GLfloat)) \
    X(void,   Uniform4iv, (GLint,GLsizei,const GLint*)) \
    X(void,   UniformMatrix4fv, (GLint,GLsizei,GLboolean,const GLfloat*)) \
    X(void,   BindFragDataLocationIndexed, (GLuint,GLuint,GLuint,const GLchar*))

#define PS2XGL_DECL(ret, name, args) extern ret (*gl##name) args;
    PS2XGL_FUNCS(PS2XGL_DECL)
#undef PS2XGL_DECL

    // Resolve every entry point. getProc is the platform loader
    // (SDL_GL_GetProcAddress / glfwGetProcAddress); a fallback to the client GL library is used
    // for GL 1.1 (opengl32/libGL), which those loaders do not always return.
    bool LoadGl(void *(*getProc)(const char *));

    // True when LoadGl() has succeeded.
    bool Ready();
}
