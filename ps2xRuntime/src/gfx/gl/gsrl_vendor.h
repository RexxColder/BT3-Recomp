// [R1] VENDORED from raylib's rlgl.h (zlib licence, (c) Ramon Santamaria / raylib contributors).
// Renamed rl*->gsrl*, RL_*->GSRL_*, RLGL->GSRL so it can coexist with raylib's own copy in the
// same binary while giving the GS replay its OWN state cache + batching semantics -- byte-identical
// behaviour to rlgl by construction instead of a hand-rolled re-implementation.
// Do NOT include glad's implementation here: it links against the glad already in the binary.

/**********************************************************************************************
*
*   gsrl v5.0 - A multi-OpenGL abstraction layer with an immediate-mode style API
*
*   DESCRIPTION:
*       An abstraction layer for multiple OpenGL versions (1.1, 2.1, 3.3 Core, 4.3 Core, ES 2.0)
*       that provides a pseudo-OpenGL 1.1 immediate-mode style API (gsrlVertex, gsrlTranslate, gsrlRotate...)
*
*   ADDITIONAL NOTES:
*       When choosing an OpenGL backend different than OpenGL 1.1, some internal buffer are
*       initialized on gsrlInit() to accumulate vertex data
*
*       When an internal state change is required all the stored vertex data is renderer in batch,
*       additionally, gsrlDrawRenderBatchActive() could be called to force flushing of the batch
*
*       Some resources are also loaded for convenience, here the complete list:
*          - Default batch (gsrl.defaultBatch): RenderBatch system to accumulate vertex data
*          - Default texture (gsrl.defaultTextureId): 1x1 white pixel R8G8B8A8
*          - Default shader (gsrl.State.defaultShaderId, gsrl.State.defaultShaderLocs)
*
*       Internal buffer (and resources) must be manually unloaded calling gsrlClose()
*
*   CONFIGURATION:
*       #define GRAPHICS_API_OPENGL_11
*       #define GRAPHICS_API_OPENGL_21
*       #define GRAPHICS_API_OPENGL_33
*       #define GRAPHICS_API_OPENGL_43
*       #define GRAPHICS_API_OPENGL_ES2
*       #define GRAPHICS_API_OPENGL_ES3
*           Use selected OpenGL graphics backend, should be supported by platform
*           Those preprocessor defines are only used on gsrl module, if OpenGL version is
*           required by any other module, use gsrlGetVersion() to check it
*
*       #define GSRL_IMPLEMENTATION
*           Generates the implementation of the library into the included file
*           If not defined, the library is in header only mode and can be included in other headers
*           or source files without problems. But only ONE file should hold the implementation
*
*       #define gsrl_RENDER_TEXTURES_HINT
*           Enable framebuffer objects (fbo) support (enabled by default)
*           Some GPUs could not support them despite the OpenGL version
*
*       #define gsrl_SHOW_GL_DETAILS_INFO
*           Show OpenGL extensions and capabilities detailed logs on init
*
*       #define gsrl_ENABLE_OPENGL_DEBUG_CONTEXT
*           Enable debug context (only available on OpenGL 4.3)
*
*       gsrl capabilities could be customized just defining some internal
*       values before library inclusion (default values listed):
*
*       #define GSRL_DEFAULT_BATCH_BUFFER_ELEMENTS   8192    // Default internal render batch elements limits
*       #define GSRL_DEFAULT_BATCH_BUFFERS              1    // Default number of batch buffers (multi-buffering)
*       #define GSRL_DEFAULT_BATCH_DRAWCALLS          256    // Default number of batch draw calls (by state changes: mode, texture)
*       #define GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS    4    // Maximum number of textures units that can be activated on batch drawing (SetShaderValueTexture())
*
*       #define GSRL_MAX_MATRIX_STACK_SIZE             32    // Maximum size of internal Matrix stack
*       #define GSRL_MAX_SHADER_LOCATIONS              32    // Maximum number of shader locations supported
*       #define GSRL_CULL_DISTANCE_NEAR              0.01    // Default projection matrix near cull distance
*       #define GSRL_CULL_DISTANCE_FAR             1000.0    // Default projection matrix far cull distance
*
*       When loading a shader, the following vertex attributes and uniform
*       location names are tried to be set automatically:
*
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_POSITION     "vertexPosition"    // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD     "vertexTexCoord"    // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_NORMAL       "vertexNormal"      // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_COLOR        "vertexColor"       // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_COLOR
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_TANGENT      "vertexTangent"     // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TANGENT
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD2    "vertexTexCoord2"   // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD2
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEIDS      "vertexBoneIds"     // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEIDS
*       #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEWEIGHTS  "vertexBoneWeights" // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEWEIGHTS
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_MVP         "mvp"               // model-view-projection matrix
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_VIEW        "matView"           // view matrix
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_PROJECTION  "matProjection"     // projection matrix
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_MODEL       "matModel"          // model matrix
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_NORMAL      "matNormal"         // normal matrix (transpose(inverse(matModelView)))
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_COLOR       "colDiffuse"        // color diffuse (base tint color, multiplied by texture color)
*       #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_BONE_MATRICES  "boneMatrices"   // bone matrices
*       #define GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE0  "texture0"          // texture0 (texture slot active 0)
*       #define GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE1  "texture1"          // texture1 (texture slot active 1)
*       #define GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE2  "texture2"          // texture2 (texture slot active 2)
*
*   DEPENDENCIES:
*      - OpenGL libraries (depending on platform and OpenGL version selected)
*      - GLAD OpenGL extensions loading library (only for OpenGL 3.3 Core, 4.3 Core)
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#ifndef gsrl_H
#define gsrl_H

#define gsrl_VERSION  "5.0"

// Function specifiers in case library is build/used as a shared library
// NOTE: Microsoft specifiers to tell compiler that symbols are imported/exported from a .dll
// NOTE: visibility(default) attribute makes symbols "visible" when compiled with -fvisibility=hidden
#if defined(_WIN32) && defined(BUILD_LIBTYPE_SHARED)
    #define gsrlAPI __declspec(dllexport)     // We are building the library as a Win32 shared library (.dll)
#elif defined(BUILD_LIBTYPE_SHARED)
    #define gsrlAPI __attribute__((visibility("default"))) // We are building the library as a Unix shared library (.so/.dylib)
#elif defined(_WIN32) && defined(USE_LIBTYPE_SHARED)
    #define gsrlAPI __declspec(dllimport)     // We are using the library as a Win32 shared library (.dll)
#endif

// Function specifiers definition
#ifndef gsrlAPI
    #define gsrlAPI       // Functions defined as 'extern' by default (implicit specifiers)
#endif

// Support TRACELOG macros
#ifndef TRACELOG
    #define TRACELOG(level, ...) (void)0
    #define TRACELOGD(...) (void)0
#endif

// Allow custom memory allocators
#ifndef GSRL_MALLOC
    #define GSRL_MALLOC(sz)     malloc(sz)
#endif
#ifndef GSRL_CALLOC
    #define GSRL_CALLOC(n,sz)   calloc(n,sz)
#endif
#ifndef GSRL_REALLOC
    #define GSRL_REALLOC(n,sz)  realloc(n,sz)
#endif
#ifndef GSRL_FREE
    #define GSRL_FREE(p)        free(p)
#endif

// Security check in case no GRAPHICS_API_OPENGL_* defined
#if !defined(GRAPHICS_API_OPENGL_11) && \
    !defined(GRAPHICS_API_OPENGL_21) && \
    !defined(GRAPHICS_API_OPENGL_33) && \
    !defined(GRAPHICS_API_OPENGL_43) && \
    !defined(GRAPHICS_API_OPENGL_ES2) && \
    !defined(GRAPHICS_API_OPENGL_ES3)
        #define GRAPHICS_API_OPENGL_33
#endif

// Security check in case multiple GRAPHICS_API_OPENGL_* defined
#if defined(GRAPHICS_API_OPENGL_11)
    #if defined(GRAPHICS_API_OPENGL_21)
        #undef GRAPHICS_API_OPENGL_21
    #endif
    #if defined(GRAPHICS_API_OPENGL_33)
        #undef GRAPHICS_API_OPENGL_33
    #endif
    #if defined(GRAPHICS_API_OPENGL_43)
        #undef GRAPHICS_API_OPENGL_43
    #endif
    #if defined(GRAPHICS_API_OPENGL_ES2)
        #undef GRAPHICS_API_OPENGL_ES2
    #endif
#endif

// OpenGL 2.1 uses most of OpenGL 3.3 Core functionality
// WARNING: Specific parts are checked with #if defines
#if defined(GRAPHICS_API_OPENGL_21)
    #define GRAPHICS_API_OPENGL_33
#endif

// OpenGL 4.3 uses OpenGL 3.3 Core functionality
#if defined(GRAPHICS_API_OPENGL_43)
    #define GRAPHICS_API_OPENGL_33
#endif

// OpenGL ES 3.0 uses OpenGL ES 2.0 functionality (and more)
#if defined(GRAPHICS_API_OPENGL_ES3)
    #define GRAPHICS_API_OPENGL_ES2
#endif

// Support framebuffer objects by default
// NOTE: Some driver implementation do not support it, despite they should
#define gsrl_RENDER_TEXTURES_HINT

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------

// Default internal render batch elements limits
#ifndef GSRL_DEFAULT_BATCH_BUFFER_ELEMENTS
    #if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_33)
        // This is the maximum amount of elements (quads) per batch
        // NOTE: Be careful with text, every letter maps to a quad
        #define GSRL_DEFAULT_BATCH_BUFFER_ELEMENTS  8192
    #endif
    #if defined(GRAPHICS_API_OPENGL_ES2)
        // We reduce memory sizes for embedded systems (RPI and HTML5)
        // NOTE: On HTML5 (emscripten) this is allocated on heap,
        // by default it's only 16MB!...just take care...
        #define GSRL_DEFAULT_BATCH_BUFFER_ELEMENTS  2048
    #endif
#endif
#ifndef GSRL_DEFAULT_BATCH_BUFFERS
    #define GSRL_DEFAULT_BATCH_BUFFERS                 4      // Default number of batch buffers (multi-buffering)
#endif
#ifndef GSRL_DEFAULT_BATCH_DRAWCALLS
    #define GSRL_DEFAULT_BATCH_DRAWCALLS             256      // Default number of batch draw calls (by state changes: mode, texture)
#endif
#ifndef GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS
    #define GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS       4      // Maximum number of textures units that can be activated on batch drawing (SetShaderValueTexture())
#endif

// Internal Matrix stack
#ifndef GSRL_MAX_MATRIX_STACK_SIZE
    #define GSRL_MAX_MATRIX_STACK_SIZE                32      // Maximum size of Matrix stack
#endif

// Shader limits
#ifndef GSRL_MAX_SHADER_LOCATIONS
    #define GSRL_MAX_SHADER_LOCATIONS                 32      // Maximum number of shader locations supported
#endif

// Projection matrix culling
#ifndef GSRL_CULL_DISTANCE_NEAR
    #define GSRL_CULL_DISTANCE_NEAR                 0.01      // Default near cull distance
#endif
#ifndef GSRL_CULL_DISTANCE_FAR
    #define GSRL_CULL_DISTANCE_FAR                1000.0      // Default far cull distance
#endif

// Texture parameters (equivalent to OpenGL defines)
#define GSRL_TEXTURE_WRAP_S                       0x2802      // GL_TEXTURE_WRAP_S
#define GSRL_TEXTURE_WRAP_T                       0x2803      // GL_TEXTURE_WRAP_T
#define GSRL_TEXTURE_MAG_FILTER                   0x2800      // GL_TEXTURE_MAG_FILTER
#define GSRL_TEXTURE_MIN_FILTER                   0x2801      // GL_TEXTURE_MIN_FILTER

#define GSRL_TEXTURE_FILTER_NEAREST               0x2600      // GL_NEAREST
#define GSRL_TEXTURE_FILTER_LINEAR                0x2601      // GL_LINEAR
#define GSRL_TEXTURE_FILTER_MIP_NEAREST           0x2700      // GL_NEAREST_MIPMAP_NEAREST
#define GSRL_TEXTURE_FILTER_NEAREST_MIP_LINEAR    0x2702      // GL_NEAREST_MIPMAP_LINEAR
#define GSRL_TEXTURE_FILTER_LINEAR_MIP_NEAREST    0x2701      // GL_LINEAR_MIPMAP_NEAREST
#define GSRL_TEXTURE_FILTER_MIP_LINEAR            0x2703      // GL_LINEAR_MIPMAP_LINEAR
#define GSRL_TEXTURE_FILTER_ANISOTROPIC           0x3000      // Anisotropic filter (custom identifier)
#define GSRL_TEXTURE_MIPMAP_BIAS_RATIO            0x4000      // Texture mipmap bias, percentage ratio (custom identifier)

#define GSRL_TEXTURE_WRAP_REPEAT                  0x2901      // GL_REPEAT
#define GSRL_TEXTURE_WRAP_CLAMP                   0x812F      // GL_CLAMP_TO_EDGE
#define GSRL_TEXTURE_WRAP_MIRROR_REPEAT           0x8370      // GL_MIRRORED_REPEAT
#define GSRL_TEXTURE_WRAP_MIRROR_CLAMP            0x8742      // GL_MIRROR_CLAMP_EXT

// Matrix modes (equivalent to OpenGL)
#define GSRL_MODELVIEW                            0x1700      // GL_MODELVIEW
#define GSRL_PROJECTION                           0x1701      // GL_PROJECTION
#define GSRL_TEXTURE                              0x1702      // GL_TEXTURE

// Primitive assembly draw modes
#define GSRL_LINES                                0x0001      // GL_LINES
#define GSRL_TRIANGLES                            0x0004      // GL_TRIANGLES
#define GSRL_QUADS                                0x0007      // GL_QUADS

// GL equivalent data types
#define GSRL_UNSIGNED_BYTE                        0x1401      // GL_UNSIGNED_BYTE
#define GSRL_FLOAT                                0x1406      // GL_FLOAT

// GL buffer usage hint
#define GSRL_STREAM_DRAW                          0x88E0      // GL_STREAM_DRAW
#define GSRL_STREAM_READ                          0x88E1      // GL_STREAM_READ
#define GSRL_STREAM_COPY                          0x88E2      // GL_STREAM_COPY
#define GSRL_STATIC_DRAW                          0x88E4      // GL_STATIC_DRAW
#define GSRL_STATIC_READ                          0x88E5      // GL_STATIC_READ
#define GSRL_STATIC_COPY                          0x88E6      // GL_STATIC_COPY
#define GSRL_DYNAMIC_DRAW                         0x88E8      // GL_DYNAMIC_DRAW
#define GSRL_DYNAMIC_READ                         0x88E9      // GL_DYNAMIC_READ
#define GSRL_DYNAMIC_COPY                         0x88EA      // GL_DYNAMIC_COPY

// GL Shader type
#define GSRL_FRAGMENT_SHADER                      0x8B30      // GL_FRAGMENT_SHADER
#define GSRL_VERTEX_SHADER                        0x8B31      // GL_VERTEX_SHADER
#define GSRL_COMPUTE_SHADER                       0x91B9      // GL_COMPUTE_SHADER

// GL blending factors
#define GSRL_ZERO                                 0           // GL_ZERO
#define GSRL_ONE                                  1           // GL_ONE
#define GSRL_SRC_COLOR                            0x0300      // GL_SRC_COLOR
#define GSRL_ONE_MINUS_SRC_COLOR                  0x0301      // GL_ONE_MINUS_SRC_COLOR
#define GSRL_SRC_ALPHA                            0x0302      // GL_SRC_ALPHA
#define GSRL_ONE_MINUS_SRC_ALPHA                  0x0303      // GL_ONE_MINUS_SRC_ALPHA
#define GSRL_DST_ALPHA                            0x0304      // GL_DST_ALPHA
#define GSRL_ONE_MINUS_DST_ALPHA                  0x0305      // GL_ONE_MINUS_DST_ALPHA
#define GSRL_DST_COLOR                            0x0306      // GL_DST_COLOR
#define GSRL_ONE_MINUS_DST_COLOR                  0x0307      // GL_ONE_MINUS_DST_COLOR
#define GSRL_SRC_ALPHA_SATURATE                   0x0308      // GL_SRC_ALPHA_SATURATE
#define GSRL_CONSTANT_COLOR                       0x8001      // GL_CONSTANT_COLOR
#define GSRL_ONE_MINUS_CONSTANT_COLOR             0x8002      // GL_ONE_MINUS_CONSTANT_COLOR
#define GSRL_CONSTANT_ALPHA                       0x8003      // GL_CONSTANT_ALPHA
#define GSRL_ONE_MINUS_CONSTANT_ALPHA             0x8004      // GL_ONE_MINUS_CONSTANT_ALPHA

// GL blending functions/equations
#define GSRL_FUNC_ADD                             0x8006      // GL_FUNC_ADD
#define GSRL_MIN                                  0x8007      // GL_MIN
#define GSRL_MAX                                  0x8008      // GL_MAX
#define GSRL_FUNC_SUBTRACT                        0x800A      // GL_FUNC_SUBTRACT
#define GSRL_FUNC_REVERSE_SUBTRACT                0x800B      // GL_FUNC_REVERSE_SUBTRACT
#define GSRL_BLEND_EQUATION                       0x8009      // GL_BLEND_EQUATION
#define GSRL_BLEND_EQUATION_RGB                   0x8009      // GL_BLEND_EQUATION_RGB   // (Same as BLEND_EQUATION)
#define GSRL_BLEND_EQUATION_ALPHA                 0x883D      // GL_BLEND_EQUATION_ALPHA
#define GSRL_BLEND_DST_RGB                        0x80C8      // GL_BLEND_DST_RGB
#define GSRL_BLEND_SRC_RGB                        0x80C9      // GL_BLEND_SRC_RGB
#define GSRL_BLEND_DST_ALPHA                      0x80CA      // GL_BLEND_DST_ALPHA
#define GSRL_BLEND_SRC_ALPHA                      0x80CB      // GL_BLEND_SRC_ALPHA
#define GSRL_BLEND_COLOR                          0x8005      // GL_BLEND_COLOR

#define GSRL_READ_FRAMEBUFFER                     0x8CA8      // GL_READ_FRAMEBUFFER
#define GSRL_DRAW_FRAMEBUFFER                     0x8CA9      // GL_DRAW_FRAMEBUFFER

// Default shader vertex attribute locations
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION    0
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD    1
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL      2
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_COLOR
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_COLOR       3
#endif
    #ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TANGENT
#define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TANGENT         4
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD2
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD2   5
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_INDICES
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_INDICES     6
#endif
#ifdef GSRL_SUPPORT_MESH_GPU_SKINNING
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEIDS
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEIDS     7
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEWEIGHTS
    #define GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEWEIGHTS 8
#endif
#endif

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
#if (defined(__STDC__) && __STDC_VERSION__ >= 199901L) || (defined(_MSC_VER) && _MSC_VER >= 1800)
    #include <stdbool.h>
#elif !defined(__cplusplus) && !defined(bool) && !defined(GSRL_BOOL_TYPE)
    // Boolean type
typedef enum bool { false = 0, true = !false } bool;
#endif

#if !defined(GSRL_MATRIX_TYPE)
// Matrix, 4x4 components, column major, OpenGL style, right handed
typedef struct Matrix {
    float m0, m4, m8, m12;      // Matrix first row (4 components)
    float m1, m5, m9, m13;      // Matrix second row (4 components)
    float m2, m6, m10, m14;     // Matrix third row (4 components)
    float m3, m7, m11, m15;     // Matrix fourth row (4 components)
} Matrix;
#define GSRL_MATRIX_TYPE
#endif

// Dynamic vertex buffers (position + texcoords + colors + indices arrays)
typedef struct gsrlVertexBuffer {
    int elementCount;           // Number of elements in the buffer (QUADS)

    float *vertices;            // Vertex position (XYZ - 3 components per vertex) (shader-location = 0)
    float *texcoords;           // Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1)
    float *normals;             // Vertex normal (XYZ - 3 components per vertex) (shader-location = 2)
    unsigned char *colors;      // Vertex colors (RGBA - 4 components per vertex) (shader-location = 3)
#if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_33)
    unsigned int *indices;      // Vertex indices (in case vertex data comes indexed) (6 indices per quad)
#endif
#if defined(GRAPHICS_API_OPENGL_ES2)
    unsigned short *indices;    // Vertex indices (in case vertex data comes indexed) (6 indices per quad)
#endif
    unsigned int vaoId;         // OpenGL Vertex Array Object id
    unsigned int vboId[5];      // OpenGL Vertex Buffer Objects id (5 types of vertex data)
} gsrlVertexBuffer;

// Draw call type
// NOTE: Only texture changes register a new draw, other state-change-related elements are not
// used at this moment (vaoId, shaderId, matrices), raylib just forces a batch draw call if any
// of those state-change happens (this is done in core module)
typedef struct gsrlDrawCall {
    int mode;                   // Drawing mode: LINES, TRIANGLES, QUADS
    int vertexCount;            // Number of vertex of the draw
    int vertexAlignment;        // Number of vertex required for index alignment (LINES, TRIANGLES)
    //unsigned int vaoId;       // Vertex array id to be used on the draw -> Using gsrl.currentBatch->vertexBuffer.vaoId
    //unsigned int shaderId;    // Shader id to be used on the draw -> Using gsrl.currentShaderId
    unsigned int textureId;     // Texture id to be used on the draw -> Use to create new draw call if changes

    //Matrix projection;        // Projection matrix for this draw -> Using gsrl.projection by default
    //Matrix modelview;         // Modelview matrix for this draw -> Using gsrl.modelview by default
} gsrlDrawCall;

// gsrlRenderBatch type
typedef struct gsrlRenderBatch {
    int bufferCount;            // Number of vertex buffers (multi-buffering support)
    int currentBuffer;          // Current buffer tracking in case of multi-buffering
    gsrlVertexBuffer *vertexBuffer; // Dynamic buffer(s) for vertex data

    gsrlDrawCall *draws;          // Draw calls array, depends on textureId
    int drawCounter;            // Draw calls counter
    float currentDepth;         // Current depth value for next draw
} gsrlRenderBatch;

// OpenGL version
typedef enum {
    GSRL_OPENGL_11 = 1,           // OpenGL 1.1
    GSRL_OPENGL_21,               // OpenGL 2.1 (GLSL 120)
    GSRL_OPENGL_33,               // OpenGL 3.3 (GLSL 330)
    GSRL_OPENGL_43,               // OpenGL 4.3 (using GLSL 330)
    GSRL_OPENGL_ES_20,            // OpenGL ES 2.0 (GLSL 100)
    GSRL_OPENGL_ES_30             // OpenGL ES 3.0 (GLSL 300 es)
} gsrlVersion;

// Trace log level
// NOTE: Organized by priority level
typedef enum {
    GSRL_LOG_ALL = 0,             // Display all logs
    GSRL_LOG_TRACE,               // Trace logging, intended for internal use only
    GSRL_LOG_DEBUG,               // Debug logging, used for internal debugging, it should be disabled on release builds
    GSRL_LOG_INFO,                // Info logging, used for program execution info
    GSRL_LOG_WARNING,             // Warning logging, used on recoverable failures
    GSRL_LOG_ERROR,               // Error logging, used on unrecoverable failures
    GSRL_LOG_FATAL,               // Fatal logging, used to abort program: exit(EXIT_FAILURE)
    GSRL_LOG_NONE                 // Disable logging
} gsrlTraceLogLevel;

// Texture pixel formats
// NOTE: Support depends on OpenGL version
typedef enum {
    GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE = 1,     // 8 bit per pixel (no alpha)
    GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA,        // 8*2 bpp (2 channels)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R5G6B5,            // 16 bpp
    GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8,            // 24 bpp
    GSRL_PIXELFORMAT_UNCOMPRESSED_R5G5B5A1,          // 16 bpp (1 bit alpha)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R4G4B4A4,          // 16 bpp (4 bit alpha)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,          // 32 bpp
    GSRL_PIXELFORMAT_UNCOMPRESSED_R32,               // 32 bpp (1 channel - float)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32,         // 32*3 bpp (3 channels - float)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32,      // 32*4 bpp (4 channels - float)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R16,               // 16 bpp (1 channel - half float)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16,         // 16*3 bpp (3 channels - half float)
    GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16,      // 16*4 bpp (4 channels - half float)
    GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB,            // 4 bpp (no alpha)
    GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGBA,           // 4 bpp (1 bit alpha)
    GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA,           // 8 bpp
    GSRL_PIXELFORMAT_COMPRESSED_DXT5_RGBA,           // 8 bpp
    GSRL_PIXELFORMAT_COMPRESSED_ETC1_RGB,            // 4 bpp
    GSRL_PIXELFORMAT_COMPRESSED_ETC2_RGB,            // 4 bpp
    GSRL_PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA,       // 8 bpp
    GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGB,            // 4 bpp
    GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGBA,           // 4 bpp
    GSRL_PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA,       // 8 bpp
    GSRL_PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA        // 2 bpp
} gsrlPixelFormat;

// Texture parameters: filter mode
// NOTE 1: Filtering considers mipmaps if available in the texture
// NOTE 2: Filter is accordingly set for minification and magnification
typedef enum {
    GSRL_TEXTURE_FILTER_POINT = 0,        // No filter, just pixel approximation
    GSRL_TEXTURE_FILTER_BILINEAR,         // Linear filtering
    GSRL_TEXTURE_FILTER_TRILINEAR,        // Trilinear filtering (linear with mipmaps)
    GSRL_TEXTURE_FILTER_ANISOTROPIC_4X,   // Anisotropic filtering 4x
    GSRL_TEXTURE_FILTER_ANISOTROPIC_8X,   // Anisotropic filtering 8x
    GSRL_TEXTURE_FILTER_ANISOTROPIC_16X,  // Anisotropic filtering 16x
} gsrlTextureFilter;

// Color blending modes (pre-defined)
typedef enum {
    GSRL_BLEND_ALPHA = 0,                 // Blend textures considering alpha (default)
    GSRL_BLEND_ADDITIVE,                  // Blend textures adding colors
    GSRL_BLEND_MULTIPLIED,                // Blend textures multiplying colors
    GSRL_BLEND_ADD_COLORS,                // Blend textures adding colors (alternative)
    GSRL_BLEND_SUBTRACT_COLORS,           // Blend textures subtracting colors (alternative)
    GSRL_BLEND_ALPHA_PREMULTIPLY,         // Blend premultiplied textures considering alpha
    GSRL_BLEND_CUSTOM,                    // Blend textures using custom src/dst factors (use gsrlSetBlendFactors())
    GSRL_BLEND_CUSTOM_SEPARATE            // Blend textures using custom src/dst factors (use gsrlSetBlendFactorsSeparate())
} gsrlBlendMode;

// Shader location point type
typedef enum {
    GSRL_SHADER_LOC_VERTEX_POSITION = 0,  // Shader location: vertex attribute: position
    GSRL_SHADER_LOC_VERTEX_TEXCOORD01,    // Shader location: vertex attribute: texcoord01
    GSRL_SHADER_LOC_VERTEX_TEXCOORD02,    // Shader location: vertex attribute: texcoord02
    GSRL_SHADER_LOC_VERTEX_NORMAL,        // Shader location: vertex attribute: normal
    GSRL_SHADER_LOC_VERTEX_TANGENT,       // Shader location: vertex attribute: tangent
    GSRL_SHADER_LOC_VERTEX_COLOR,         // Shader location: vertex attribute: color
    GSRL_SHADER_LOC_MATRIX_MVP,           // Shader location: matrix uniform: model-view-projection
    GSRL_SHADER_LOC_MATRIX_VIEW,          // Shader location: matrix uniform: view (camera transform)
    GSRL_SHADER_LOC_MATRIX_PROJECTION,    // Shader location: matrix uniform: projection
    GSRL_SHADER_LOC_MATRIX_MODEL,         // Shader location: matrix uniform: model (transform)
    GSRL_SHADER_LOC_MATRIX_NORMAL,        // Shader location: matrix uniform: normal
    GSRL_SHADER_LOC_VECTOR_VIEW,          // Shader location: vector uniform: view
    GSRL_SHADER_LOC_COLOR_DIFFUSE,        // Shader location: vector uniform: diffuse color
    GSRL_SHADER_LOC_COLOR_SPECULAR,       // Shader location: vector uniform: specular color
    GSRL_SHADER_LOC_COLOR_AMBIENT,        // Shader location: vector uniform: ambient color
    GSRL_SHADER_LOC_MAP_ALBEDO,           // Shader location: sampler2d texture: albedo (same as: GSRL_SHADER_LOC_MAP_DIFFUSE)
    GSRL_SHADER_LOC_MAP_METALNESS,        // Shader location: sampler2d texture: metalness (same as: GSRL_SHADER_LOC_MAP_SPECULAR)
    GSRL_SHADER_LOC_MAP_NORMAL,           // Shader location: sampler2d texture: normal
    GSRL_SHADER_LOC_MAP_ROUGHNESS,        // Shader location: sampler2d texture: roughness
    GSRL_SHADER_LOC_MAP_OCCLUSION,        // Shader location: sampler2d texture: occlusion
    GSRL_SHADER_LOC_MAP_EMISSION,         // Shader location: sampler2d texture: emission
    GSRL_SHADER_LOC_MAP_HEIGHT,           // Shader location: sampler2d texture: height
    GSRL_SHADER_LOC_MAP_CUBEMAP,          // Shader location: samplerCube texture: cubemap
    GSRL_SHADER_LOC_MAP_IRRADIANCE,       // Shader location: samplerCube texture: irradiance
    GSRL_SHADER_LOC_MAP_PREFILTER,        // Shader location: samplerCube texture: prefilter
    GSRL_SHADER_LOC_MAP_BRDF              // Shader location: sampler2d texture: brdf
} gsrlShaderLocationIndex;

#define GSRL_SHADER_LOC_MAP_DIFFUSE       GSRL_SHADER_LOC_MAP_ALBEDO
#define GSRL_SHADER_LOC_MAP_SPECULAR      GSRL_SHADER_LOC_MAP_METALNESS

// Shader uniform data type
typedef enum {
    GSRL_SHADER_UNIFORM_FLOAT = 0,        // Shader uniform type: float
    GSRL_SHADER_UNIFORM_VEC2,             // Shader uniform type: vec2 (2 float)
    GSRL_SHADER_UNIFORM_VEC3,             // Shader uniform type: vec3 (3 float)
    GSRL_SHADER_UNIFORM_VEC4,             // Shader uniform type: vec4 (4 float)
    GSRL_SHADER_UNIFORM_INT,              // Shader uniform type: int
    GSRL_SHADER_UNIFORM_IVEC2,            // Shader uniform type: ivec2 (2 int)
    GSRL_SHADER_UNIFORM_IVEC3,            // Shader uniform type: ivec3 (3 int)
    GSRL_SHADER_UNIFORM_IVEC4,            // Shader uniform type: ivec4 (4 int)
    GSRL_SHADER_UNIFORM_UINT,             // Shader uniform type: unsigned int
    GSRL_SHADER_UNIFORM_UIVEC2,           // Shader uniform type: uivec2 (2 unsigned int)
    GSRL_SHADER_UNIFORM_UIVEC3,           // Shader uniform type: uivec3 (3 unsigned int)
    GSRL_SHADER_UNIFORM_UIVEC4,           // Shader uniform type: uivec4 (4 unsigned int)
    GSRL_SHADER_UNIFORM_SAMPLER2D         // Shader uniform type: sampler2d
} gsrlShaderUniformDataType;

// Shader attribute data types
typedef enum {
    GSRL_SHADER_ATTRIB_FLOAT = 0,         // Shader attribute type: float
    GSRL_SHADER_ATTRIB_VEC2,              // Shader attribute type: vec2 (2 float)
    GSRL_SHADER_ATTRIB_VEC3,              // Shader attribute type: vec3 (3 float)
    GSRL_SHADER_ATTRIB_VEC4               // Shader attribute type: vec4 (4 float)
} gsrlShaderAttributeDataType;

// Framebuffer attachment type
// NOTE: By default up to 8 color channels defined, but it can be more
typedef enum {
    GSRL_ATTACHMENT_COLOR_CHANNEL0 = 0,       // Framebuffer attachment type: color 0
    GSRL_ATTACHMENT_COLOR_CHANNEL1 = 1,       // Framebuffer attachment type: color 1
    GSRL_ATTACHMENT_COLOR_CHANNEL2 = 2,       // Framebuffer attachment type: color 2
    GSRL_ATTACHMENT_COLOR_CHANNEL3 = 3,       // Framebuffer attachment type: color 3
    GSRL_ATTACHMENT_COLOR_CHANNEL4 = 4,       // Framebuffer attachment type: color 4
    GSRL_ATTACHMENT_COLOR_CHANNEL5 = 5,       // Framebuffer attachment type: color 5
    GSRL_ATTACHMENT_COLOR_CHANNEL6 = 6,       // Framebuffer attachment type: color 6
    GSRL_ATTACHMENT_COLOR_CHANNEL7 = 7,       // Framebuffer attachment type: color 7
    GSRL_ATTACHMENT_DEPTH = 100,              // Framebuffer attachment type: depth
    GSRL_ATTACHMENT_STENCIL = 200,            // Framebuffer attachment type: stencil
} gsrlFramebufferAttachType;

// Framebuffer texture attachment type
typedef enum {
    GSRL_ATTACHMENT_CUBEMAP_POSITIVE_X = 0,   // Framebuffer texture attachment type: cubemap, +X side
    GSRL_ATTACHMENT_CUBEMAP_NEGATIVE_X = 1,   // Framebuffer texture attachment type: cubemap, -X side
    GSRL_ATTACHMENT_CUBEMAP_POSITIVE_Y = 2,   // Framebuffer texture attachment type: cubemap, +Y side
    GSRL_ATTACHMENT_CUBEMAP_NEGATIVE_Y = 3,   // Framebuffer texture attachment type: cubemap, -Y side
    GSRL_ATTACHMENT_CUBEMAP_POSITIVE_Z = 4,   // Framebuffer texture attachment type: cubemap, +Z side
    GSRL_ATTACHMENT_CUBEMAP_NEGATIVE_Z = 5,   // Framebuffer texture attachment type: cubemap, -Z side
    GSRL_ATTACHMENT_TEXTURE2D = 100,          // Framebuffer texture attachment type: texture2d
    GSRL_ATTACHMENT_RENDERBUFFER = 200,       // Framebuffer texture attachment type: renderbuffer
} gsrlFramebufferAttachTextureType;

// Face culling mode
typedef enum {
    GSRL_CULL_FACE_FRONT = 0,
    GSRL_CULL_FACE_BACK
} gsrlCullMode;

//------------------------------------------------------------------------------------
// Functions Declaration - Matrix operations
//------------------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C" {            // Prevents name mangling of functions
#endif

gsrlAPI void gsrlMatrixMode(int mode);                      // Choose the current matrix to be transformed
gsrlAPI void gsrlPushMatrix(void);                          // Push the current matrix to stack
gsrlAPI void gsrlPopMatrix(void);                           // Pop latest inserted matrix from stack
gsrlAPI void gsrlLoadIdentity(void);                        // Reset current matrix to identity matrix
gsrlAPI void gsrlTranslatef(float x, float y, float z);     // Multiply the current matrix by a translation matrix
gsrlAPI void gsrlRotatef(float angle, float x, float y, float z); // Multiply the current matrix by a rotation matrix
gsrlAPI void gsrlScalef(float x, float y, float z);         // Multiply the current matrix by a scaling matrix
gsrlAPI void gsrlMultMatrixf(const float *matf);            // Multiply the current matrix by another matrix
gsrlAPI void gsrlFrustum(double left, double right, double bottom, double top, double znear, double zfar);
gsrlAPI void gsrlOrtho(double left, double right, double bottom, double top, double znear, double zfar);
gsrlAPI void gsrlViewport(int x, int y, int width, int height); // Set the viewport area
gsrlAPI void gsrlSetClipPlanes(double nearPlane, double farPlane);    // Set clip planes distances
gsrlAPI double gsrlGetCullDistanceNear(void);               // Get cull plane distance near
gsrlAPI double gsrlGetCullDistanceFar(void);                // Get cull plane distance far

//------------------------------------------------------------------------------------
// Functions Declaration - Vertex level operations
//------------------------------------------------------------------------------------
gsrlAPI void gsrlBegin(int mode);                           // Initialize drawing mode (how to organize vertex)
gsrlAPI void gsrlEnd(void);                                 // Finish vertex providing
gsrlAPI void gsrlVertex2i(int x, int y);                    // Define one vertex (position) - 2 int
gsrlAPI void gsrlVertex2f(float x, float y);                // Define one vertex (position) - 2 float
gsrlAPI void gsrlVertex3f(float x, float y, float z);       // Define one vertex (position) - 3 float
gsrlAPI void gsrlTexCoord2f(float x, float y);              // Define one vertex (texture coordinate) - 2 float
gsrlAPI void gsrlNormal3f(float x, float y, float z);       // Define one vertex (normal) - 3 float
gsrlAPI void gsrlColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a); // Define one vertex (color) - 4 byte
gsrlAPI void gsrlColor3f(float x, float y, float z);        // Define one vertex (color) - 3 float
gsrlAPI void gsrlColor4f(float x, float y, float z, float w); // Define one vertex (color) - 4 float

//------------------------------------------------------------------------------------
// Functions Declaration - OpenGL style functions (common to 1.1, 3.3+, ES2)
// NOTE: This functions are used to completely abstract raylib code from OpenGL layer,
// some of them are direct wrappers over OpenGL calls, some others are custom
//------------------------------------------------------------------------------------

// Vertex buffers state
gsrlAPI bool gsrlEnableVertexArray(unsigned int vaoId);     // Enable vertex array (VAO, if supported)
gsrlAPI void gsrlDisableVertexArray(void);                  // Disable vertex array (VAO, if supported)
gsrlAPI void gsrlEnableVertexBuffer(unsigned int id);       // Enable vertex buffer (VBO)
gsrlAPI void gsrlDisableVertexBuffer(void);                 // Disable vertex buffer (VBO)
gsrlAPI void gsrlEnableVertexBufferElement(unsigned int id); // Enable vertex buffer element (VBO element)
gsrlAPI void gsrlDisableVertexBufferElement(void);          // Disable vertex buffer element (VBO element)
gsrlAPI void gsrlEnableVertexAttribute(unsigned int index); // Enable vertex attribute index
gsrlAPI void gsrlDisableVertexAttribute(unsigned int index); // Disable vertex attribute index
#if defined(GRAPHICS_API_OPENGL_11)
gsrlAPI void gsrlEnableStatePointer(int vertexAttribType, void *buffer); // Enable attribute state pointer
gsrlAPI void gsrlDisableStatePointer(int vertexAttribType); // Disable attribute state pointer
#endif

// Textures state
gsrlAPI void gsrlActiveTextureSlot(int slot);               // Select and active a texture slot
gsrlAPI void gsrlEnableTexture(unsigned int id);            // Enable texture
gsrlAPI void gsrlDisableTexture(void);                      // Disable texture
gsrlAPI void gsrlEnableTextureCubemap(unsigned int id);     // Enable texture cubemap
gsrlAPI void gsrlDisableTextureCubemap(void);               // Disable texture cubemap
gsrlAPI void gsrlTextureParameters(unsigned int id, int param, int value); // Set texture parameters (filter, wrap)
gsrlAPI void gsrlCubemapParameters(unsigned int id, int param, int value); // Set cubemap parameters (filter, wrap)

// Shader state
gsrlAPI void gsrlEnableShader(unsigned int id);             // Enable shader program
gsrlAPI void gsrlDisableShader(void);                       // Disable shader program

// Framebuffer state
gsrlAPI void gsrlEnableFramebuffer(unsigned int id);        // Enable render texture (fbo)
gsrlAPI void gsrlDisableFramebuffer(void);                  // Disable render texture (fbo), return to default framebuffer
gsrlAPI unsigned int gsrlGetActiveFramebuffer(void);        // Get the currently active render texture (fbo), 0 for default framebuffer
gsrlAPI void gsrlActiveDrawBuffers(int count);              // Activate multiple draw color buffers
gsrlAPI void gsrlBlitFramebuffer(int srcX, int srcY, int srcWidth, int srcHeight, int dstX, int dstY, int dstWidth, int dstHeight, int bufferMask); // Blit active framebuffer to main framebuffer
gsrlAPI void gsrlBindFramebuffer(unsigned int target, unsigned int framebuffer); // Bind framebuffer (FBO)

// General render state
gsrlAPI void gsrlEnableColorBlend(void);                    // Enable color blending
gsrlAPI void gsrlDisableColorBlend(void);                   // Disable color blending
gsrlAPI void gsrlEnableDepthTest(void);                     // Enable depth test
gsrlAPI void gsrlDisableDepthTest(void);                    // Disable depth test
gsrlAPI void gsrlEnableDepthMask(void);                     // Enable depth write
gsrlAPI void gsrlDisableDepthMask(void);                    // Disable depth write
gsrlAPI void gsrlEnableBackfaceCulling(void);               // Enable backface culling
gsrlAPI void gsrlDisableBackfaceCulling(void);              // Disable backface culling
gsrlAPI void gsrlColorMask(bool r, bool g, bool b, bool a); // Color mask control
gsrlAPI void gsrlSetCullFace(int mode);                     // Set face culling mode
gsrlAPI void gsrlEnableScissorTest(void);                   // Enable scissor test
gsrlAPI void gsrlDisableScissorTest(void);                  // Disable scissor test
gsrlAPI void gsrlScissor(int x, int y, int width, int height); // Scissor test
gsrlAPI void gsrlEnableWireMode(void);                      // Enable wire mode
gsrlAPI void gsrlEnablePointMode(void);                     // Enable point mode
gsrlAPI void gsrlDisableWireMode(void);                     // Disable wire (and point) mode
gsrlAPI void gsrlSetLineWidth(float width);                 // Set the line drawing width
gsrlAPI float gsrlGetLineWidth(void);                       // Get the line drawing width
gsrlAPI void gsrlEnableSmoothLines(void);                   // Enable line aliasing
gsrlAPI void gsrlDisableSmoothLines(void);                  // Disable line aliasing
gsrlAPI void gsrlEnableStereoRender(void);                  // Enable stereo rendering
gsrlAPI void gsrlDisableStereoRender(void);                 // Disable stereo rendering
gsrlAPI bool gsrlIsStereoRenderEnabled(void);               // Check if stereo render is enabled

gsrlAPI void gsrlClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a); // Clear color buffer with color
gsrlAPI void gsrlClearScreenBuffers(void);                  // Clear used screen buffers (color and depth)
gsrlAPI void gsrlCheckErrors(void);                         // Check and log OpenGL error codes
gsrlAPI void gsrlSetBlendMode(int mode);                    // Set blending mode
gsrlAPI void gsrlSetBlendFactors(int glSrcFactor, int glDstFactor, int glEquation); // Set blending mode factor and equation (using OpenGL factors)
gsrlAPI void gsrlSetBlendFactorsSeparate(int glSrcRGB, int glDstRGB, int glSrcAlpha, int glDstAlpha, int glEqRGB, int glEqAlpha); // Set blending mode factors and equations separately (using OpenGL factors)

//------------------------------------------------------------------------------------
// Functions Declaration - gsrl functionality
//------------------------------------------------------------------------------------
// gsrl initialization functions
gsrlAPI void gsrlInit(int width, int height);             // Initialize gsrl (buffers, shaders, textures, states)
gsrlAPI void gsrlClose(void);                             // De-initialize gsrl (buffers, shaders, textures)
gsrlAPI void gsrlLoadExtensions(void *loader);              // Load OpenGL extensions (loader function required)
gsrlAPI int gsrlGetVersion(void);                           // Get current OpenGL version
gsrlAPI void gsrlSetFramebufferWidth(int width);            // Set current framebuffer width
gsrlAPI int gsrlGetFramebufferWidth(void);                  // Get default framebuffer width
gsrlAPI void gsrlSetFramebufferHeight(int height);          // Set current framebuffer height
gsrlAPI int gsrlGetFramebufferHeight(void);                 // Get default framebuffer height

gsrlAPI unsigned int gsrlGetTextureIdDefault(void);         // Get default texture id
gsrlAPI unsigned int gsrlGetShaderIdDefault(void);          // Get default shader id
gsrlAPI int *gsrlGetShaderLocsDefault(void);                // Get default shader locations

// Render batch management
// NOTE: gsrl provides a default render batch to behave like OpenGL 1.1 immediate mode
// but this render batch API is exposed in case of custom batches are required
gsrlAPI gsrlRenderBatch gsrlLoadRenderBatch(int numBuffers, int bufferElements); // Load a render batch system
gsrlAPI void gsrlUnloadRenderBatch(gsrlRenderBatch batch);    // Unload render batch system
gsrlAPI void gsrlDrawRenderBatch(gsrlRenderBatch *batch);     // Draw render batch data (Update->Draw->Reset)
gsrlAPI void gsrlSetRenderBatchActive(gsrlRenderBatch *batch); // Set the active render batch for gsrl (NULL for default internal)
gsrlAPI void gsrlDrawRenderBatchActive(void);               // Update and draw internal render batch
gsrlAPI bool gsrlCheckRenderBatchLimit(int vCount);         // Check internal buffer overflow for a given number of vertex

gsrlAPI void gsrlSetTexture(unsigned int id);               // Set current texture for render batch and check buffers limits

//------------------------------------------------------------------------------------------------------------------------

// Vertex buffers management
gsrlAPI unsigned int gsrlLoadVertexArray(void);             // Load vertex array (vao) if supported
gsrlAPI unsigned int gsrlLoadVertexBuffer(const void *buffer, int size, bool dynamic); // Load a vertex buffer object
gsrlAPI unsigned int gsrlLoadVertexBufferElement(const void *buffer, int size, bool dynamic); // Load vertex buffer elements object
gsrlAPI void gsrlUpdateVertexBuffer(unsigned int bufferId, const void *data, int dataSize, int offset); // Update vertex buffer object data on GPU buffer
gsrlAPI void gsrlUpdateVertexBufferElements(unsigned int id, const void *data, int dataSize, int offset); // Update vertex buffer elements data on GPU buffer
gsrlAPI void gsrlUnloadVertexArray(unsigned int vaoId);     // Unload vertex array (vao)
gsrlAPI void gsrlUnloadVertexBuffer(unsigned int vboId);    // Unload vertex buffer object
gsrlAPI void gsrlSetVertexAttribute(unsigned int index, int compSize, int type, bool normalized, int stride, int offset); // Set vertex attribute data configuration
gsrlAPI void gsrlSetVertexAttributeDivisor(unsigned int index, int divisor); // Set vertex attribute data divisor
gsrlAPI void gsrlSetVertexAttributeDefault(int locIndex, const void *value, int attribType, int count); // Set vertex attribute default value, when attribute to provided
gsrlAPI void gsrlDrawVertexArray(int offset, int count);    // Draw vertex array (currently active vao)
gsrlAPI void gsrlDrawVertexArrayElements(int offset, int count, const void *buffer); // Draw vertex array elements
gsrlAPI void gsrlDrawVertexArrayInstanced(int offset, int count, int instances); // Draw vertex array (currently active vao) with instancing
gsrlAPI void gsrlDrawVertexArrayElementsInstanced(int offset, int count, const void *buffer, int instances); // Draw vertex array elements with instancing

// Textures management
gsrlAPI unsigned int gsrlLoadTexture(const void *data, int width, int height, int format, int mipmapCount); // Load texture data
gsrlAPI unsigned int gsrlLoadTextureDepth(int width, int height, bool useRenderBuffer); // Load depth texture/renderbuffer (to be attached to fbo)
gsrlAPI unsigned int gsrlLoadTextureCubemap(const void *data, int size, int format, int mipmapCount); // Load texture cubemap data
gsrlAPI void gsrlUpdateTexture(unsigned int id, int offsetX, int offsetY, int width, int height, int format, const void *data); // Update texture with new data on GPU
gsrlAPI void gsrlGetGlTextureFormats(int format, unsigned int *glInternalFormat, unsigned int *glFormat, unsigned int *glType); // Get OpenGL internal formats
gsrlAPI const char *gsrlGetPixelFormatName(unsigned int format);              // Get name string for pixel format
gsrlAPI void gsrlUnloadTexture(unsigned int id);                              // Unload texture from GPU memory
gsrlAPI void gsrlGenTextureMipmaps(unsigned int id, int width, int height, int format, int *mipmaps); // Generate mipmap data for selected texture
gsrlAPI void *gsrlReadTexturePixels(unsigned int id, int width, int height, int format); // Read texture pixel data
gsrlAPI unsigned char *gsrlReadScreenPixels(int width, int height);           // Read screen pixel data (color buffer)

// Framebuffer management (fbo)
gsrlAPI unsigned int gsrlLoadFramebuffer(void);                               // Load an empty framebuffer
gsrlAPI void gsrlFramebufferAttach(unsigned int fboId, unsigned int texId, int attachType, int texType, int mipLevel); // Attach texture/renderbuffer to a framebuffer
gsrlAPI bool gsrlFramebufferComplete(unsigned int id);                        // Verify framebuffer is complete
gsrlAPI void gsrlUnloadFramebuffer(unsigned int id);                          // Delete framebuffer from GPU

// Shaders management
gsrlAPI unsigned int gsrlLoadShaderCode(const char *vsCode, const char *fsCode);    // Load shader from code strings
gsrlAPI unsigned int gsrlCompileShader(const char *shaderCode, int type);           // Compile custom shader and return shader id (type: GSRL_VERTEX_SHADER, GSRL_FRAGMENT_SHADER, GSRL_COMPUTE_SHADER)
gsrlAPI unsigned int gsrlLoadShaderProgram(unsigned int vShaderId, unsigned int fShaderId); // Load custom shader program
gsrlAPI void gsrlUnloadShaderProgram(unsigned int id);                              // Unload shader program
gsrlAPI int gsrlGetLocationUniform(unsigned int shaderId, const char *uniformName); // Get shader location uniform
gsrlAPI int gsrlGetLocationAttrib(unsigned int shaderId, const char *attribName);   // Get shader location attribute
gsrlAPI void gsrlSetUniform(int locIndex, const void *value, int uniformType, int count); // Set shader value uniform
gsrlAPI void gsrlSetUniformMatrix(int locIndex, Matrix mat);                        // Set shader value matrix
gsrlAPI void gsrlSetUniformMatrices(int locIndex, const Matrix *mat, int count);    // Set shader value matrices
gsrlAPI void gsrlSetUniformSampler(int locIndex, unsigned int textureId);           // Set shader value sampler
gsrlAPI void gsrlSetShader(unsigned int id, int *locs);                             // Set shader currently active (id and locations)

// Compute shader management
gsrlAPI unsigned int gsrlLoadComputeShaderProgram(unsigned int shaderId);           // Load compute shader program
gsrlAPI void gsrlComputeShaderDispatch(unsigned int groupX, unsigned int groupY, unsigned int groupZ); // Dispatch compute shader (equivalent to *draw* for graphics pipeline)

// Shader buffer storage object management (ssbo)
gsrlAPI unsigned int gsrlLoadShaderBuffer(unsigned int size, const void *data, int usageHint); // Load shader storage buffer object (SSBO)
gsrlAPI void gsrlUnloadShaderBuffer(unsigned int ssboId);                           // Unload shader storage buffer object (SSBO)
gsrlAPI void gsrlUpdateShaderBuffer(unsigned int id, const void *data, unsigned int dataSize, unsigned int offset); // Update SSBO buffer data
gsrlAPI void gsrlBindShaderBuffer(unsigned int id, unsigned int index);             // Bind SSBO buffer
gsrlAPI void gsrlReadShaderBuffer(unsigned int id, void *dest, unsigned int count, unsigned int offset); // Read SSBO buffer data (GPU->CPU)
gsrlAPI void gsrlCopyShaderBuffer(unsigned int destId, unsigned int srcId, unsigned int destOffset, unsigned int srcOffset, unsigned int count); // Copy SSBO data between buffers
gsrlAPI unsigned int gsrlGetShaderBufferSize(unsigned int id);                      // Get SSBO buffer size

// Buffer management
gsrlAPI void gsrlBindImageTexture(unsigned int id, unsigned int index, int format, bool readonly);  // Bind image texture

// Matrix state management
gsrlAPI Matrix gsrlGetMatrixModelview(void);                                  // Get internal modelview matrix
gsrlAPI Matrix gsrlGetMatrixProjection(void);                                 // Get internal projection matrix
gsrlAPI Matrix gsrlGetMatrixTransform(void);                                  // Get internal accumulated transform matrix
gsrlAPI Matrix gsrlGetMatrixProjectionStereo(int eye);                        // Get internal projection matrix for stereo render (selected eye)
gsrlAPI Matrix gsrlGetMatrixViewOffsetStereo(int eye);                        // Get internal view offset matrix for stereo render (selected eye)
gsrlAPI void gsrlSetMatrixProjection(Matrix proj);                            // Set a custom projection matrix (replaces internal projection matrix)
gsrlAPI void gsrlSetMatrixModelview(Matrix view);                             // Set a custom modelview matrix (replaces internal modelview matrix)
gsrlAPI void gsrlSetMatrixProjectionStereo(Matrix right, Matrix left);        // Set eyes projection matrices for stereo rendering
gsrlAPI void gsrlSetMatrixViewOffsetStereo(Matrix right, Matrix left);        // Set eyes view offsets matrices for stereo rendering

// Quick and dirty cube/quad buffers load->draw->unload
gsrlAPI void gsrlLoadDrawCube(void);     // Load and draw a cube
gsrlAPI void gsrlLoadDrawQuad(void);     // Load and draw a quad

#if defined(__cplusplus)
}
#endif

#endif // gsrl_H

/***********************************************************************************
*
*   gsrl IMPLEMENTATION
*
************************************************************************************/

#if defined(GSRL_IMPLEMENTATION)

// Expose OpenGL functions from glad in raylib
#if defined(BUILD_LIBTYPE_SHARED)
    #define GLAD_API_CALL_EXPORT
    #define GLAD_API_CALL_EXPORT_BUILD
#endif

#if defined(GRAPHICS_API_OPENGL_11)
    #if defined(__APPLE__)
        #include <OpenGL/gl.h>          // OpenGL 1.1 library for OSX
        #include <OpenGL/glext.h>       // OpenGL extensions library
    #else
        // APIENTRY for OpenGL function pointer declarations is required
        #if !defined(APIENTRY)
            #if defined(_WIN32)
                #define APIENTRY __stdcall
            #else
                #define APIENTRY
            #endif
        #endif
        // WINGDIAPI definition. Some Windows OpenGL headers need it
        #if !defined(WINGDIAPI) && defined(_WIN32)
            #define WINGDIAPI __declspec(dllimport)
        #endif

        #include <GL/gl.h>              // OpenGL 1.1 library
    #endif
#endif

#if defined(GRAPHICS_API_OPENGL_33)
    #define GLAD_MALLOC GSRL_MALLOC
    #define GLAD_FREE GSRL_FREE

    // [R1] glad is compiled once by the raylib build: link to those symbols, do not recompile the implementation here.
    #include "glad.h"          // GLAD extensions loading library, includes OpenGL headers
#endif

#if defined(GRAPHICS_API_OPENGL_ES3)
    #include <GLES3/gl3.h>              // OpenGL ES 3.0 library
    #define GL_GLEXT_PROTOTYPES
    #include <GLES2/gl2ext.h>           // OpenGL ES 2.0 extensions library
#elif defined(GRAPHICS_API_OPENGL_ES2)
    // NOTE: OpenGL ES 2.0 can be enabled on Desktop platforms,
    // in that case, functions are loaded from a custom glad for OpenGL ES 2.0
    #if defined(PLATFORM_DESKTOP_GLFW) || defined(PLATFORM_DESKTOP_SDL)
        #define GLAD_GLES2_IMPLEMENTATION
        #include "external/glad_gles2.h"
    #else
        #define GL_GLEXT_PROTOTYPES
        //#include <EGL/egl.h>          // EGL library -> not required, platform layer
        #include <GLES2/gl2.h>          // OpenGL ES 2.0 library
        #include <GLES2/gl2ext.h>       // OpenGL ES 2.0 extensions library
    #endif

    // It seems OpenGL ES 2.0 instancing entry points are not defined on Raspberry Pi
    // provided headers (despite being defined in official Khronos GLES2 headers)
    #if defined(PLATFORM_DRM)
    typedef void (GL_APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
    typedef void (GL_APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
    typedef void (GL_APIENTRYP PFNGLVERTEXATTRIBDIVISOREXTPROC) (GLuint index, GLuint divisor);
    #endif
#endif

#include <stdlib.h>                     // Required for: malloc(), free()
#include <string.h>                     // Required for: strcmp(), strlen() [Used in gsrlInit(), on extensions loading]
#include <math.h>                       // Required for: sqrtf(), sinf(), cosf(), floor(), log()

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
#ifndef PI
    #define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
    #define DEG2RAD (PI/180.0f)
#endif
#ifndef RAD2DEG
    #define RAD2DEG (180.0f/PI)
#endif

#ifndef GL_SHADING_LANGUAGE_VERSION
    #define GL_SHADING_LANGUAGE_VERSION         0x8B8C
#endif

#ifndef GL_COMPRESSED_RGB_S3TC_DXT1_EXT
    #define GL_COMPRESSED_RGB_S3TC_DXT1_EXT     0x83F0
#endif
#ifndef GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
    #define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT    0x83F1
#endif
#ifndef GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
    #define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT    0x83F2
#endif
#ifndef GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
    #define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT    0x83F3
#endif
#ifndef GL_ETC1_RGB8_OES
    #define GL_ETC1_RGB8_OES                    0x8D64
#endif
#ifndef GL_COMPRESSED_RGB8_ETC2
    #define GL_COMPRESSED_RGB8_ETC2             0x9274
#endif
#ifndef GL_COMPRESSED_RGBA8_ETC2_EAC
    #define GL_COMPRESSED_RGBA8_ETC2_EAC        0x9278
#endif
#ifndef GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG
    #define GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG  0x8C00
#endif
#ifndef GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG
    #define GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG 0x8C02
#endif
#ifndef GL_COMPRESSED_RGBA_ASTC_4x4_KHR
    #define GL_COMPRESSED_RGBA_ASTC_4x4_KHR     0x93b0
#endif
#ifndef GL_COMPRESSED_RGBA_ASTC_8x8_KHR
    #define GL_COMPRESSED_RGBA_ASTC_8x8_KHR     0x93b7
#endif

#ifndef GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
    #define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT   0x84FF
#endif
#ifndef GL_TEXTURE_MAX_ANISOTROPY_EXT
    #define GL_TEXTURE_MAX_ANISOTROPY_EXT       0x84FE
#endif

#ifndef GL_PROGRAM_POINT_SIZE
    #define GL_PROGRAM_POINT_SIZE               0x8642
#endif

#ifndef GL_LINE_WIDTH
    #define GL_LINE_WIDTH                       0x0B21
#endif

#if defined(GRAPHICS_API_OPENGL_11)
    #define GL_UNSIGNED_SHORT_5_6_5             0x8363
    #define GL_UNSIGNED_SHORT_5_5_5_1           0x8034
    #define GL_UNSIGNED_SHORT_4_4_4_4           0x8033
#endif

#if defined(GRAPHICS_API_OPENGL_21)
    #define GL_LUMINANCE                        0x1909
    #define GL_LUMINANCE_ALPHA                  0x190A
#endif

#if defined(GRAPHICS_API_OPENGL_ES2)
    #define glClearDepth                 glClearDepthf
    #if !defined(GRAPHICS_API_OPENGL_ES3)
        #define GL_READ_FRAMEBUFFER         GL_FRAMEBUFFER
        #define GL_DRAW_FRAMEBUFFER         GL_FRAMEBUFFER
    #endif
#endif

// Default shader vertex attribute names to set location points
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_POSITION
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_POSITION     "vertexPosition"    // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_POSITION
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD     "vertexTexCoord"    // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_NORMAL
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_NORMAL       "vertexNormal"      // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_NORMAL
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_COLOR
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_COLOR        "vertexColor"       // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_COLOR
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_TANGENT
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_TANGENT      "vertexTangent"     // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_TANGENT
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD2
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD2    "vertexTexCoord2"   // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD2
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEIDS
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEIDS      "vertexBoneIds"     // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEIDS
#endif
#ifndef GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEWEIGHTS
    #define GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEWEIGHTS  "vertexBoneWeights" // Bound by default to shader location: GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEWEIGHTS
#endif

#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_MVP
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_MVP         "mvp"               // model-view-projection matrix
#endif
#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_VIEW
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_VIEW        "matView"           // view matrix
#endif
#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_PROJECTION
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_PROJECTION  "matProjection"     // projection matrix
#endif
#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_MODEL
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_MODEL       "matModel"          // model matrix
#endif
#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_NORMAL
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_NORMAL      "matNormal"         // normal matrix (transpose(inverse(matModelView))
#endif
#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_COLOR
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_COLOR       "colDiffuse"        // color diffuse (base tint color, multiplied by texture color)
#endif
#ifndef GSRL_DEFAULT_SHADER_UNIFORM_NAME_BONE_MATRICES
    #define GSRL_DEFAULT_SHADER_UNIFORM_NAME_BONE_MATRICES  "boneMatrices"   // bone matrices
#endif
#ifndef GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE0
    #define GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE0  "texture0"          // texture0 (texture slot active 0)
#endif
#ifndef GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE1
    #define GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE1  "texture1"          // texture1 (texture slot active 1)
#endif
#ifndef GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE2
    #define GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE2  "texture2"          // texture2 (texture slot active 2)
#endif

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
typedef struct gsrlData {
    gsrlRenderBatch *currentBatch;            // Current render batch
    gsrlRenderBatch defaultBatch;             // Default internal render batch

    struct {
        int vertexCounter;                  // Current active render batch vertex counter (generic, used for all batches)
        float texcoordx, texcoordy;         // Current active texture coordinate (added on glVertex*())
        float normalx, normaly, normalz;    // Current active normal (added on glVertex*())
        unsigned char colorr, colorg, colorb, colora;   // Current active color (added on glVertex*())

        int currentMatrixMode;              // Current matrix mode
        Matrix *currentMatrix;              // Current matrix pointer
        Matrix modelview;                   // Default modelview matrix
        Matrix projection;                  // Default projection matrix
        Matrix transform;                   // Transform matrix to be used with gsrlTranslate, gsrlRotate, gsrlScale
        bool transformRequired;             // Require transform matrix application to current draw-call vertex (if required)
        Matrix stack[GSRL_MAX_MATRIX_STACK_SIZE];// Matrix stack for push/pop
        int stackCounter;                   // Matrix stack counter

        unsigned int defaultTextureId;      // Default texture used on shapes/poly drawing (required by shader)
        unsigned int activeTextureId[GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS];    // Active texture ids to be enabled on batch drawing (0 active by default)
        unsigned int defaultVShaderId;      // Default vertex shader id (used by default shader program)
        unsigned int defaultFShaderId;      // Default fragment shader id (used by default shader program)
        unsigned int defaultShaderId;       // Default shader program id, supports vertex color and diffuse texture
        int *defaultShaderLocs;             // Default shader locations pointer to be used on rendering
        unsigned int currentShaderId;       // Current shader id to be used on rendering (by default, defaultShaderId)
        int *currentShaderLocs;             // Current shader locations pointer to be used on rendering (by default, defaultShaderLocs)

        bool stereoRender;                  // Stereo rendering flag
        Matrix projectionStereo[2];         // VR stereo rendering eyes projection matrices
        Matrix viewOffsetStereo[2];         // VR stereo rendering eyes view offset matrices

        // Blending variables
        int currentBlendMode;               // Blending mode active
        int glBlendSrcFactor;               // Blending source factor
        int glBlendDstFactor;               // Blending destination factor
        int glBlendEquation;                // Blending equation
        int glBlendSrcFactorRGB;            // Blending source RGB factor
        int glBlendDestFactorRGB;           // Blending destination RGB factor
        int glBlendSrcFactorAlpha;          // Blending source alpha factor
        int glBlendDestFactorAlpha;         // Blending destination alpha factor
        int glBlendEquationRGB;             // Blending equation for RGB
        int glBlendEquationAlpha;           // Blending equation for alpha
        bool glCustomBlendModeModified;     // Custom blending factor and equation modification status

        int framebufferWidth;               // Current framebuffer width
        int framebufferHeight;              // Current framebuffer height

    } State;            // Renderer state
    struct {
        bool vao;                           // VAO support (OpenGL ES2 could not support VAO extension) (GL_ARB_vertex_array_object)
        bool instancing;                    // Instancing supported (GL_ANGLE_instanced_arrays, GL_EXT_draw_instanced + GL_EXT_instanced_arrays)
        bool texNPOT;                       // NPOT textures full support (GL_ARB_texture_non_power_of_two, GL_OES_texture_npot)
        bool texDepth;                      // Depth textures supported (GL_ARB_depth_texture, GL_OES_depth_texture)
        bool texDepthWebGL;                 // Depth textures supported WebGL specific (GL_WEBGL_depth_texture)
        bool texFloat32;                    // float textures support (32 bit per channel) (GL_OES_texture_float)
        bool texFloat16;                    // half float textures support (16 bit per channel) (GL_OES_texture_half_float)
        bool texCompDXT;                    // DDS texture compression support (GL_EXT_texture_compression_s3tc, GL_WEBGL_compressed_texture_s3tc, GL_WEBKIT_WEBGL_compressed_texture_s3tc)
        bool texCompETC1;                   // ETC1 texture compression support (GL_OES_compressed_ETC1_RGB8_texture, GL_WEBGL_compressed_texture_etc1)
        bool texCompETC2;                   // ETC2/EAC texture compression support (GL_ARB_ES3_compatibility)
        bool texCompPVRT;                   // PVR texture compression support (GL_IMG_texture_compression_pvrtc)
        bool texCompASTC;                   // ASTC texture compression support (GL_KHR_texture_compression_astc_hdr, GL_KHR_texture_compression_astc_ldr)
        bool texMirrorClamp;                // Clamp mirror wrap mode supported (GL_EXT_texture_mirror_clamp)
        bool texAnisoFilter;                // Anisotropic texture filtering support (GL_EXT_texture_filter_anisotropic)
        bool computeShader;                 // Compute shaders support (GL_ARB_compute_shader)
        bool ssbo;                          // Shader storage buffer object support (GL_ARB_shader_storage_buffer_object)

        float maxAnisotropyLevel;           // Maximum anisotropy level supported (minimum is 2.0f)
        int maxDepthBits;                   // Maximum bits for depth component

    } ExtSupported;     // Extensions supported flags
} gsrlData;

typedef void *(*gsrlLoadProc)(const char *name);   // OpenGL extension functions loader signature (same as GLADloadproc)

#endif  // GRAPHICS_API_OPENGL_33 || GRAPHICS_API_OPENGL_ES2

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
static double gsrlCullDistanceNear = GSRL_CULL_DISTANCE_NEAR;
static double gsrlCullDistanceFar = GSRL_CULL_DISTANCE_FAR;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
static gsrlData gsrl = { 0 };
#endif  // GRAPHICS_API_OPENGL_33 || GRAPHICS_API_OPENGL_ES2

#if defined(GRAPHICS_API_OPENGL_ES2) && !defined(GRAPHICS_API_OPENGL_ES3)
// NOTE: VAO functionality is exposed through extensions (OES)
static PFNGLGENVERTEXARRAYSOESPROC glGenVertexArrays = NULL;
static PFNGLBINDVERTEXARRAYOESPROC glBindVertexArray = NULL;
static PFNGLDELETEVERTEXARRAYSOESPROC glDeleteVertexArrays = NULL;

// NOTE: Instancing functionality could also be available through extension
static PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstanced = NULL;
static PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstanced = NULL;
static PFNGLVERTEXATTRIBDIVISOREXTPROC glVertexAttribDivisor = NULL;
#endif

//----------------------------------------------------------------------------------
// Module specific Functions Declaration
//----------------------------------------------------------------------------------
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
static void gsrlLoadShaderDefault(void);      // Load default shader
static void gsrlUnloadShaderDefault(void);    // Unload default shader
#if defined(gsrl_SHOW_GL_DETAILS_INFO)
static const char *gsrlGetCompressedFormatName(int format); // Get compressed format official GL identifier name
#endif  // gsrl_SHOW_GL_DETAILS_INFO
#endif  // GRAPHICS_API_OPENGL_33 || GRAPHICS_API_OPENGL_ES2

static int gsrlGetPixelDataSize(int width, int height, int format);   // Get pixel data size in bytes (image or texture)

// Auxiliar matrix math functions
typedef struct GSRL_float16 {
    float v[16];
} GSRL_float16;
static GSRL_float16 gsrlMatrixToFloatV(Matrix mat);             // Get float array of matrix data
#define gsrlMatrixToFloat(mat) (gsrlMatrixToFloatV(mat).v)      // Get float vector for Matrix
static Matrix gsrlMatrixIdentity(void);                       // Get identity matrix
static Matrix gsrlMatrixMultiply(Matrix left, Matrix right);  // Multiply two matrices
static Matrix gsrlMatrixTranspose(Matrix mat);                // Transposes provided matrix
static Matrix gsrlMatrixInvert(Matrix mat);                   // Invert provided matrix

//----------------------------------------------------------------------------------
// Module Functions Definition - Matrix operations
//----------------------------------------------------------------------------------

#if defined(GRAPHICS_API_OPENGL_11)
// Fallback to OpenGL 1.1 function calls
//---------------------------------------
void gsrlMatrixMode(int mode)
{
    switch (mode)
    {
        case GSRL_PROJECTION: glMatrixMode(GL_PROJECTION); break;
        case GSRL_MODELVIEW: glMatrixMode(GL_MODELVIEW); break;
        case GSRL_TEXTURE: glMatrixMode(GL_TEXTURE); break;
        default: break;
    }
}

void gsrlFrustum(double left, double right, double bottom, double top, double znear, double zfar)
{
    glFrustum(left, right, bottom, top, znear, zfar);
}

void gsrlOrtho(double left, double right, double bottom, double top, double znear, double zfar)
{
    glOrtho(left, right, bottom, top, znear, zfar);
}

void gsrlPushMatrix(void) { glPushMatrix(); }
void gsrlPopMatrix(void) { glPopMatrix(); }
void gsrlLoadIdentity(void) { glLoadIdentity(); }
void gsrlTranslatef(float x, float y, float z) { glTranslatef(x, y, z); }
void gsrlRotatef(float angle, float x, float y, float z) { glRotatef(angle, x, y, z); }
void gsrlScalef(float x, float y, float z) { glScalef(x, y, z); }
void gsrlMultMatrixf(const float *matf) { glMultMatrixf(matf); }
#endif
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
// Choose the current matrix to be transformed
void gsrlMatrixMode(int mode)
{
    if (mode == GSRL_PROJECTION) gsrl.State.currentMatrix = &gsrl.State.projection;
    else if (mode == GSRL_MODELVIEW) gsrl.State.currentMatrix = &gsrl.State.modelview;
    //else if (mode == GSRL_TEXTURE) // Not supported

    gsrl.State.currentMatrixMode = mode;
}

// Push the current matrix into gsrl.State.stack
void gsrlPushMatrix(void)
{
    if (gsrl.State.stackCounter >= GSRL_MAX_MATRIX_STACK_SIZE) TRACELOG(GSRL_LOG_ERROR, "gsrl: Matrix stack overflow (GSRL_MAX_MATRIX_STACK_SIZE)");

    if (gsrl.State.currentMatrixMode == GSRL_MODELVIEW)
    {
        gsrl.State.transformRequired = true;
        gsrl.State.currentMatrix = &gsrl.State.transform;
    }

    gsrl.State.stack[gsrl.State.stackCounter] = *gsrl.State.currentMatrix;
    gsrl.State.stackCounter++;
}

// Pop lattest inserted matrix from gsrl.State.stack
void gsrlPopMatrix(void)
{
    if (gsrl.State.stackCounter > 0)
    {
        Matrix mat = gsrl.State.stack[gsrl.State.stackCounter - 1];
        *gsrl.State.currentMatrix = mat;
        gsrl.State.stackCounter--;
    }

    if ((gsrl.State.stackCounter == 0) && (gsrl.State.currentMatrixMode == GSRL_MODELVIEW))
    {
        gsrl.State.currentMatrix = &gsrl.State.modelview;
        gsrl.State.transformRequired = false;
    }
}

// Reset current matrix to identity matrix
void gsrlLoadIdentity(void)
{
    *gsrl.State.currentMatrix = gsrlMatrixIdentity();
}

// Multiply the current matrix by a translation matrix
void gsrlTranslatef(float x, float y, float z)
{
    Matrix matTranslation = {
        1.0f, 0.0f, 0.0f, x,
        0.0f, 1.0f, 0.0f, y,
        0.0f, 0.0f, 1.0f, z,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // NOTE: We transpose matrix with multiplication order
    *gsrl.State.currentMatrix = gsrlMatrixMultiply(matTranslation, *gsrl.State.currentMatrix);
}

// Multiply the current matrix by a rotation matrix
// NOTE: The provided angle must be in degrees
void gsrlRotatef(float angle, float x, float y, float z)
{
    Matrix matRotation = gsrlMatrixIdentity();

    // Axis vector (x, y, z) normalization
    float lengthSquared = x*x + y*y + z*z;
    if ((lengthSquared != 1.0f) && (lengthSquared != 0.0f))
    {
        float inverseLength = 1.0f/sqrtf(lengthSquared);
        x *= inverseLength;
        y *= inverseLength;
        z *= inverseLength;
    }

    // Rotation matrix generation
    float sinres = sinf(DEG2RAD*angle);
    float cosres = cosf(DEG2RAD*angle);
    float t = 1.0f - cosres;

    matRotation.m0 = x*x*t + cosres;
    matRotation.m1 = y*x*t + z*sinres;
    matRotation.m2 = z*x*t - y*sinres;
    matRotation.m3 = 0.0f;

    matRotation.m4 = x*y*t - z*sinres;
    matRotation.m5 = y*y*t + cosres;
    matRotation.m6 = z*y*t + x*sinres;
    matRotation.m7 = 0.0f;

    matRotation.m8 = x*z*t + y*sinres;
    matRotation.m9 = y*z*t - x*sinres;
    matRotation.m10 = z*z*t + cosres;
    matRotation.m11 = 0.0f;

    matRotation.m12 = 0.0f;
    matRotation.m13 = 0.0f;
    matRotation.m14 = 0.0f;
    matRotation.m15 = 1.0f;

    // NOTE: We transpose matrix with multiplication order
    *gsrl.State.currentMatrix = gsrlMatrixMultiply(matRotation, *gsrl.State.currentMatrix);
}

// Multiply the current matrix by a scaling matrix
void gsrlScalef(float x, float y, float z)
{
    Matrix matScale = {
        x, 0.0f, 0.0f, 0.0f,
        0.0f, y, 0.0f, 0.0f,
        0.0f, 0.0f, z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // NOTE: We transpose matrix with multiplication order
    *gsrl.State.currentMatrix = gsrlMatrixMultiply(matScale, *gsrl.State.currentMatrix);
}

// Multiply the current matrix by another matrix
void gsrlMultMatrixf(const float *matf)
{
    // Matrix creation from array
    Matrix mat = { matf[0], matf[4], matf[8], matf[12],
                   matf[1], matf[5], matf[9], matf[13],
                   matf[2], matf[6], matf[10], matf[14],
                   matf[3], matf[7], matf[11], matf[15] };

    *gsrl.State.currentMatrix = gsrlMatrixMultiply(mat, *gsrl.State.currentMatrix);
}

// Multiply the current matrix by a perspective matrix generated by parameters
void gsrlFrustum(double left, double right, double bottom, double top, double znear, double zfar)
{
    Matrix matFrustum = { 0 };

    float rl = (float)(right - left);
    float tb = (float)(top - bottom);
    float fn = (float)(zfar - znear);

    matFrustum.m0 = ((float) znear*2.0f)/rl;
    matFrustum.m1 = 0.0f;
    matFrustum.m2 = 0.0f;
    matFrustum.m3 = 0.0f;

    matFrustum.m4 = 0.0f;
    matFrustum.m5 = ((float) znear*2.0f)/tb;
    matFrustum.m6 = 0.0f;
    matFrustum.m7 = 0.0f;

    matFrustum.m8 = ((float)right + (float)left)/rl;
    matFrustum.m9 = ((float)top + (float)bottom)/tb;
    matFrustum.m10 = -((float)zfar + (float)znear)/fn;
    matFrustum.m11 = -1.0f;

    matFrustum.m12 = 0.0f;
    matFrustum.m13 = 0.0f;
    matFrustum.m14 = -((float)zfar*(float)znear*2.0f)/fn;
    matFrustum.m15 = 0.0f;

    *gsrl.State.currentMatrix = gsrlMatrixMultiply(*gsrl.State.currentMatrix, matFrustum);
}

// Multiply the current matrix by an orthographic matrix generated by parameters
void gsrlOrtho(double left, double right, double bottom, double top, double znear, double zfar)
{
    // NOTE: If left-right and top-botton values are equal it could create a division by zero,
    // response to it is platform/compiler dependant
    Matrix matOrtho = { 0 };

    float rl = (float)(right - left);
    float tb = (float)(top - bottom);
    float fn = (float)(zfar - znear);

    matOrtho.m0 = 2.0f/rl;
    matOrtho.m1 = 0.0f;
    matOrtho.m2 = 0.0f;
    matOrtho.m3 = 0.0f;
    matOrtho.m4 = 0.0f;
    matOrtho.m5 = 2.0f/tb;
    matOrtho.m6 = 0.0f;
    matOrtho.m7 = 0.0f;
    matOrtho.m8 = 0.0f;
    matOrtho.m9 = 0.0f;
    matOrtho.m10 = -2.0f/fn;
    matOrtho.m11 = 0.0f;
    matOrtho.m12 = -((float)left + (float)right)/rl;
    matOrtho.m13 = -((float)top + (float)bottom)/tb;
    matOrtho.m14 = -((float)zfar + (float)znear)/fn;
    matOrtho.m15 = 1.0f;

    *gsrl.State.currentMatrix = gsrlMatrixMultiply(*gsrl.State.currentMatrix, matOrtho);
}
#endif

// Set the viewport area (transformation from normalized device coordinates to window coordinates)
// NOTE: We store current viewport dimensions
void gsrlViewport(int x, int y, int width, int height)
{
    glViewport(x, y, width, height);
}

// Set clip planes distances
void gsrlSetClipPlanes(double nearPlane, double farPlane)
{
    gsrlCullDistanceNear = nearPlane;
    gsrlCullDistanceFar = farPlane;
}

// Get cull plane distance near
double gsrlGetCullDistanceNear(void)
{
    return gsrlCullDistanceNear;
}

// Get cull plane distance far
double gsrlGetCullDistanceFar(void)
{
    return gsrlCullDistanceFar;
}

//----------------------------------------------------------------------------------
// Module Functions Definition - Vertex level operations
//----------------------------------------------------------------------------------
#if defined(GRAPHICS_API_OPENGL_11)
// Fallback to OpenGL 1.1 function calls
//---------------------------------------
void gsrlBegin(int mode)
{
    switch (mode)
    {
        case GSRL_LINES: glBegin(GL_LINES); break;
        case GSRL_TRIANGLES: glBegin(GL_TRIANGLES); break;
        case GSRL_QUADS: glBegin(GL_QUADS); break;
        default: break;
    }
}

void gsrlEnd(void) { glEnd(); }
void gsrlVertex2i(int x, int y) { glVertex2i(x, y); }
void gsrlVertex2f(float x, float y) { glVertex2f(x, y); }
void gsrlVertex3f(float x, float y, float z) { glVertex3f(x, y, z); }
void gsrlTexCoord2f(float x, float y) { glTexCoord2f(x, y); }
void gsrlNormal3f(float x, float y, float z) { glNormal3f(x, y, z); }
void gsrlColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a) { glColor4ub(r, g, b, a); }
void gsrlColor3f(float x, float y, float z) { glColor3f(x, y, z); }
void gsrlColor4f(float x, float y, float z, float w) { glColor4f(x, y, z, w); }
#endif
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
// Initialize drawing mode (how to organize vertex)
void gsrlBegin(int mode)
{
    // Draw mode can be GSRL_LINES, GSRL_TRIANGLES and GSRL_QUADS
    // NOTE: In all three cases, vertex are accumulated over default internal vertex buffer
    if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode != mode)
    {
        if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount > 0)
        {
            // Make sure current gsrl.currentBatch->draws[i].vertexCount is aligned a multiple of 4,
            // that way, following QUADS drawing will keep aligned with index processing
            // It implies adding some extra alignment vertex at the end of the draw,
            // those vertex are not processed but they are considered as an additional offset
            // for the next set of vertex to be drawn
            if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_LINES) gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment = ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount < 4)? gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount : gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%4);
            else if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_TRIANGLES) gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment = ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount < 4)? 1 : (4 - (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%4)));
            else gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment = 0;

            if (!gsrlCheckRenderBatchLimit(gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment))
            {
                gsrl.State.vertexCounter += gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment;
                gsrl.currentBatch->drawCounter++;
            }
        }

        if (gsrl.currentBatch->drawCounter >= GSRL_DEFAULT_BATCH_DRAWCALLS) gsrlDrawRenderBatch(gsrl.currentBatch);

        gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode = mode;
        gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount = 0;
        gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].textureId = gsrl.State.defaultTextureId;
    }
}

// Finish vertex providing
void gsrlEnd(void)
{
    // NOTE: Depth increment is dependant on gsrlOrtho(): z-near and z-far values,
    // as well as depth buffer bit-depth (16bit or 24bit or 32bit)
    // Correct increment formula would be: depthInc = (zfar - znear)/pow(2, bits)
    gsrl.currentBatch->currentDepth += (1.0f/20000.0f);
}

// Define one vertex (position)
// NOTE: Vertex position data is the basic information required for drawing
void gsrlVertex3f(float x, float y, float z)
{
    float tx = x;
    float ty = y;
    float tz = z;

    // Transform provided vector if required
    if (gsrl.State.transformRequired)
    {
        tx = gsrl.State.transform.m0*x + gsrl.State.transform.m4*y + gsrl.State.transform.m8*z + gsrl.State.transform.m12;
        ty = gsrl.State.transform.m1*x + gsrl.State.transform.m5*y + gsrl.State.transform.m9*z + gsrl.State.transform.m13;
        tz = gsrl.State.transform.m2*x + gsrl.State.transform.m6*y + gsrl.State.transform.m10*z + gsrl.State.transform.m14;
    }

    // WARNING: We can't break primitives when launching a new batch
    // GSRL_LINES comes in pairs, GSRL_TRIANGLES come in groups of 3 vertices and GSRL_QUADS come in groups of 4 vertices
    // We must check current draw.mode when a new vertex is required and finish the batch only if the draw.mode draw.vertexCount is %2, %3 or %4
    if (gsrl.State.vertexCounter > (gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].elementCount*4 - 4))
    {
        if ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_LINES) &&
            (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%2 == 0))
        {
            // Reached the maximum number of vertices for GSRL_LINES drawing
            // Launch a draw call but keep current state for next vertices comming
            // NOTE: We add +1 vertex to the check for security
            gsrlCheckRenderBatchLimit(2 + 1);
        }
        else if ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_TRIANGLES) &&
            (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%3 == 0))
        {
            gsrlCheckRenderBatchLimit(3 + 1);
        }
        else if ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_QUADS) &&
            (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%4 == 0))
        {
            gsrlCheckRenderBatchLimit(4 + 1);
        }
    }

    // Add vertices
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].vertices[3*gsrl.State.vertexCounter] = tx;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].vertices[3*gsrl.State.vertexCounter + 1] = ty;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].vertices[3*gsrl.State.vertexCounter + 2] = tz;

    // Add current texcoord
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].texcoords[2*gsrl.State.vertexCounter] = gsrl.State.texcoordx;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].texcoords[2*gsrl.State.vertexCounter + 1] = gsrl.State.texcoordy;

    // Add current normal
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].normals[3*gsrl.State.vertexCounter] = gsrl.State.normalx;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].normals[3*gsrl.State.vertexCounter + 1] = gsrl.State.normaly;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].normals[3*gsrl.State.vertexCounter + 2] = gsrl.State.normalz;

    // Add current color
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].colors[4*gsrl.State.vertexCounter] = gsrl.State.colorr;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].colors[4*gsrl.State.vertexCounter + 1] = gsrl.State.colorg;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].colors[4*gsrl.State.vertexCounter + 2] = gsrl.State.colorb;
    gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].colors[4*gsrl.State.vertexCounter + 3] = gsrl.State.colora;

    gsrl.State.vertexCounter++;
    gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount++;
}

// Define one vertex (position)
void gsrlVertex2f(float x, float y)
{
    gsrlVertex3f(x, y, gsrl.currentBatch->currentDepth);
}

// Define one vertex (position)
void gsrlVertex2i(int x, int y)
{
    gsrlVertex3f((float)x, (float)y, gsrl.currentBatch->currentDepth);
}

// Define one vertex (texture coordinate)
// NOTE: Texture coordinates are limited to QUADS only
void gsrlTexCoord2f(float x, float y)
{
    gsrl.State.texcoordx = x;
    gsrl.State.texcoordy = y;
}

// Define one vertex (normal)
// NOTE: Normals limited to TRIANGLES only?
void gsrlNormal3f(float x, float y, float z)
{
    float normalx = x;
    float normaly = y;
    float normalz = z;
    if (gsrl.State.transformRequired)
    {
        normalx = gsrl.State.transform.m0*x + gsrl.State.transform.m4*y + gsrl.State.transform.m8*z;
        normaly = gsrl.State.transform.m1*x + gsrl.State.transform.m5*y + gsrl.State.transform.m9*z;
        normalz = gsrl.State.transform.m2*x + gsrl.State.transform.m6*y + gsrl.State.transform.m10*z;
    }
    float length = sqrtf(normalx*normalx + normaly*normaly + normalz*normalz);
    if (length != 0.0f)
    {
        float ilength = 1.0f/length;
        normalx *= ilength;
        normaly *= ilength;
        normalz *= ilength;
    }
    gsrl.State.normalx = normalx;
    gsrl.State.normaly = normaly;
    gsrl.State.normalz = normalz;
}

// Define one vertex (color)
void gsrlColor4ub(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
{
    gsrl.State.colorr = x;
    gsrl.State.colorg = y;
    gsrl.State.colorb = z;
    gsrl.State.colora = w;
}

// Define one vertex (color)
void gsrlColor4f(float r, float g, float b, float a)
{
    gsrlColor4ub((unsigned char)(r*255), (unsigned char)(g*255), (unsigned char)(b*255), (unsigned char)(a*255));
}

// Define one vertex (color)
void gsrlColor3f(float x, float y, float z)
{
    gsrlColor4ub((unsigned char)(x*255), (unsigned char)(y*255), (unsigned char)(z*255), 255);
}

#endif

//--------------------------------------------------------------------------------------
// Module Functions Definition - OpenGL style functions (common to 1.1, 3.3+, ES2)
//--------------------------------------------------------------------------------------

// Set current texture to use
void gsrlSetTexture(unsigned int id)
{
    if (id == 0)
    {
#if defined(GRAPHICS_API_OPENGL_11)
        gsrlDisableTexture();
#else
        // NOTE: If quads batch limit is reached, we force a draw call and next batch starts
        if (gsrl.State.vertexCounter >=
            gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].elementCount*4)
        {
            gsrlDrawRenderBatch(gsrl.currentBatch);
        }
#endif
    }
    else
    {
#if defined(GRAPHICS_API_OPENGL_11)
        gsrlEnableTexture(id);
#else
        if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].textureId != id)
        {
            if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount > 0)
            {
                // Make sure current gsrl.currentBatch->draws[i].vertexCount is aligned a multiple of 4,
                // that way, following QUADS drawing will keep aligned with index processing
                // It implies adding some extra alignment vertex at the end of the draw,
                // those vertex are not processed but they are considered as an additional offset
                // for the next set of vertex to be drawn
                if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_LINES) gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment = ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount < 4)? gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount : gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%4);
                else if (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode == GSRL_TRIANGLES) gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment = ((gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount < 4)? 1 : (4 - (gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount%4)));
                else gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment = 0;

                if (!gsrlCheckRenderBatchLimit(gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment))
                {
                    gsrl.State.vertexCounter += gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexAlignment;

                    gsrl.currentBatch->drawCounter++;
                }
            }

            if (gsrl.currentBatch->drawCounter >= GSRL_DEFAULT_BATCH_DRAWCALLS) gsrlDrawRenderBatch(gsrl.currentBatch);

            gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].textureId = id;
            gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].vertexCount = 0;
        }
#endif
    }
}

// Select and active a texture slot
void gsrlActiveTextureSlot(int slot)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glActiveTexture(GL_TEXTURE0 + slot);
#endif
}

// Enable texture
void gsrlEnableTexture(unsigned int id)
{
#if defined(GRAPHICS_API_OPENGL_11)
    glEnable(GL_TEXTURE_2D);
#endif
    glBindTexture(GL_TEXTURE_2D, id);
}

// Disable texture
void gsrlDisableTexture(void)
{
#if defined(GRAPHICS_API_OPENGL_11)
    glDisable(GL_TEXTURE_2D);
#endif
    glBindTexture(GL_TEXTURE_2D, 0);
}

// Enable texture cubemap
void gsrlEnableTextureCubemap(unsigned int id)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);
#endif
}

// Disable texture cubemap
void gsrlDisableTextureCubemap(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
#endif
}

// Set texture parameters (wrap mode/filter mode)
void gsrlTextureParameters(unsigned int id, int param, int value)
{
    glBindTexture(GL_TEXTURE_2D, id);

#if !defined(GRAPHICS_API_OPENGL_11)
    // Reset anisotropy filter, in case it was set
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1.0f);
#endif

    switch (param)
    {
        case GSRL_TEXTURE_WRAP_S:
        case GSRL_TEXTURE_WRAP_T:
        {
            if (value == GSRL_TEXTURE_WRAP_MIRROR_CLAMP)
            {
#if !defined(GRAPHICS_API_OPENGL_11)
                if (gsrl.ExtSupported.texMirrorClamp) glTexParameteri(GL_TEXTURE_2D, param, value);
                else TRACELOG(GSRL_LOG_WARNING, "GL: Clamp mirror wrap mode not supported (GL_MIRROR_CLAMP_EXT)");
#endif
            }
            else glTexParameteri(GL_TEXTURE_2D, param, value);

        } break;
        case GSRL_TEXTURE_MAG_FILTER:
        case GSRL_TEXTURE_MIN_FILTER: glTexParameteri(GL_TEXTURE_2D, param, value); break;
        case GSRL_TEXTURE_FILTER_ANISOTROPIC:
        {
#if !defined(GRAPHICS_API_OPENGL_11)
            if (value <= gsrl.ExtSupported.maxAnisotropyLevel) glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, (float)value);
            else if (gsrl.ExtSupported.maxAnisotropyLevel > 0.0f)
            {
                TRACELOG(GSRL_LOG_WARNING, "GL: Maximum anisotropic filter level supported is %iX", id, (int)gsrl.ExtSupported.maxAnisotropyLevel);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, (float)value);
            }
            else TRACELOG(GSRL_LOG_WARNING, "GL: Anisotropic filtering not supported");
#endif
        } break;
#if defined(GRAPHICS_API_OPENGL_33)
        case GSRL_TEXTURE_MIPMAP_BIAS_RATIO: glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, value/100.0f);
#endif
        default: break;
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}

// Set cubemap parameters (wrap mode/filter mode)
void gsrlCubemapParameters(unsigned int id, int param, int value)
{
#if !defined(GRAPHICS_API_OPENGL_11)
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);

    // Reset anisotropy filter, in case it was set
    glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, 1.0f);

    switch (param)
    {
        case GSRL_TEXTURE_WRAP_S:
        case GSRL_TEXTURE_WRAP_T:
        {
            if (value == GSRL_TEXTURE_WRAP_MIRROR_CLAMP)
            {
                if (gsrl.ExtSupported.texMirrorClamp) glTexParameteri(GL_TEXTURE_CUBE_MAP, param, value);
                else TRACELOG(GSRL_LOG_WARNING, "GL: Clamp mirror wrap mode not supported (GL_MIRROR_CLAMP_EXT)");
            }
            else glTexParameteri(GL_TEXTURE_CUBE_MAP, param, value);

        } break;
        case GSRL_TEXTURE_MAG_FILTER:
        case GSRL_TEXTURE_MIN_FILTER: glTexParameteri(GL_TEXTURE_CUBE_MAP, param, value); break;
        case GSRL_TEXTURE_FILTER_ANISOTROPIC:
        {
            if (value <= gsrl.ExtSupported.maxAnisotropyLevel) glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, (float)value);
            else if (gsrl.ExtSupported.maxAnisotropyLevel > 0.0f)
            {
                TRACELOG(GSRL_LOG_WARNING, "GL: Maximum anisotropic filter level supported is %iX", id, (int)gsrl.ExtSupported.maxAnisotropyLevel);
                glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, (float)value);
            }
            else TRACELOG(GSRL_LOG_WARNING, "GL: Anisotropic filtering not supported");
        } break;
#if defined(GRAPHICS_API_OPENGL_33)
        case GSRL_TEXTURE_MIPMAP_BIAS_RATIO: glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_LOD_BIAS, value/100.0f);
#endif
        default: break;
    }

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
#endif
}

// Enable shader program
void gsrlEnableShader(unsigned int id)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2))
    glUseProgram(id);
#endif
}

// Disable shader program
void gsrlDisableShader(void)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2))
    glUseProgram(0);
#endif
}

// Enable rendering to texture (fbo)
void gsrlEnableFramebuffer(unsigned int id)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glBindFramebuffer(GL_FRAMEBUFFER, id);
#endif
}

// return the active render texture (fbo)
unsigned int gsrlGetActiveFramebuffer(void)
{
    GLint fboId = 0;
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES3)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &fboId);
#endif
    return fboId;
}

// Disable rendering to texture
void gsrlDisableFramebuffer(void)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
}

// Blit active framebuffer to main framebuffer
void gsrlBlitFramebuffer(int srcX, int srcY, int srcWidth, int srcHeight, int dstX, int dstY, int dstWidth, int dstHeight, int bufferMask)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES3)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glBlitFramebuffer(srcX, srcY, srcWidth, srcHeight, dstX, dstY, dstWidth, dstHeight, bufferMask, GL_NEAREST);
#endif
}

// Bind framebuffer object (fbo)
void gsrlBindFramebuffer(unsigned int target, unsigned int framebuffer)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glBindFramebuffer(target, framebuffer);
#endif
}

// Activate multiple draw color buffers
// NOTE: One color buffer is always active by default
void gsrlActiveDrawBuffers(int count)
{
#if ((defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES3)) && defined(gsrl_RENDER_TEXTURES_HINT))
    // NOTE: Maximum number of draw buffers supported is implementation dependant,
    // it can be queried with glGet*() but it must be at least 8
    //GLint maxDrawBuffers = 0;
    //glGetIntegerv(GL_MAX_DRAW_BUFFERS, &maxDrawBuffers);

    if (count > 0)
    {
        if (count > 8) TRACELOG(LOG_WARNING, "GL: Max color buffers limited to 8");
        else
        {
            unsigned int buffers[8] = {
#if defined(GRAPHICS_API_OPENGL_ES3)
                GL_COLOR_ATTACHMENT0_EXT,
                GL_COLOR_ATTACHMENT1_EXT,
                GL_COLOR_ATTACHMENT2_EXT,
                GL_COLOR_ATTACHMENT3_EXT,
                GL_COLOR_ATTACHMENT4_EXT,
                GL_COLOR_ATTACHMENT5_EXT,
                GL_COLOR_ATTACHMENT6_EXT,
                GL_COLOR_ATTACHMENT7_EXT,
#else
                GL_COLOR_ATTACHMENT0,
                GL_COLOR_ATTACHMENT1,
                GL_COLOR_ATTACHMENT2,
                GL_COLOR_ATTACHMENT3,
                GL_COLOR_ATTACHMENT4,
                GL_COLOR_ATTACHMENT5,
                GL_COLOR_ATTACHMENT6,
                GL_COLOR_ATTACHMENT7,
#endif
            };

#if defined(GRAPHICS_API_OPENGL_ES3)
            glDrawBuffersEXT(count, buffers);
#else
            glDrawBuffers(count, buffers);
#endif
        }
    }
    else TRACELOG(LOG_WARNING, "GL: One color buffer active by default");
#endif
}

//----------------------------------------------------------------------------------
// General render state configuration
//----------------------------------------------------------------------------------

// Enable color blending
void gsrlEnableColorBlend(void) { glEnable(GL_BLEND); }

// Disable color blending
void gsrlDisableColorBlend(void) { glDisable(GL_BLEND); }

// Enable depth test
void gsrlEnableDepthTest(void) { glEnable(GL_DEPTH_TEST); }

// Disable depth test
void gsrlDisableDepthTest(void) { glDisable(GL_DEPTH_TEST); }

// Enable depth write
void gsrlEnableDepthMask(void) { glDepthMask(GL_TRUE); }

// Disable depth write
void gsrlDisableDepthMask(void) { glDepthMask(GL_FALSE); }

// Enable backface culling
void gsrlEnableBackfaceCulling(void) { glEnable(GL_CULL_FACE); }

// Disable backface culling
void gsrlDisableBackfaceCulling(void) { glDisable(GL_CULL_FACE); }

// Set color mask active for screen read/draw
void gsrlColorMask(bool r, bool g, bool b, bool a) { glColorMask(r, g, b, a); }

// Set face culling mode
void gsrlSetCullFace(int mode)
{
    switch (mode)
    {
        case GSRL_CULL_FACE_BACK: glCullFace(GL_BACK); break;
        case GSRL_CULL_FACE_FRONT: glCullFace(GL_FRONT); break;
        default: break;
    }
}

// Enable scissor test
void gsrlEnableScissorTest(void) { glEnable(GL_SCISSOR_TEST); }

// Disable scissor test
void gsrlDisableScissorTest(void) { glDisable(GL_SCISSOR_TEST); }

// Scissor test
void gsrlScissor(int x, int y, int width, int height) { glScissor(x, y, width, height); }

// Enable wire mode
void gsrlEnableWireMode(void)
{
#if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_33)
    // NOTE: glPolygonMode() not available on OpenGL ES
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
}

// Enable point mode
void gsrlEnablePointMode(void)
{
#if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_33)
    // NOTE: glPolygonMode() not available on OpenGL ES
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glEnable(GL_PROGRAM_POINT_SIZE);
#endif
}

// Disable wire mode
void gsrlDisableWireMode(void)
{
#if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_33)
    // NOTE: glPolygonMode() not available on OpenGL ES
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
#endif
}

// Set the line drawing width
void gsrlSetLineWidth(float width) { glLineWidth(width); }

// Get the line drawing width
float gsrlGetLineWidth(void)
{
    float width = 0;
    glGetFloatv(GL_LINE_WIDTH, &width);
    return width;
}

// Enable line aliasing
void gsrlEnableSmoothLines(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_11)
    glEnable(GL_LINE_SMOOTH);
#endif
}

// Disable line aliasing
void gsrlDisableSmoothLines(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_11)
    glDisable(GL_LINE_SMOOTH);
#endif
}

// Enable stereo rendering
void gsrlEnableStereoRender(void)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2))
    gsrl.State.stereoRender = true;
#endif
}

// Disable stereo rendering
void gsrlDisableStereoRender(void)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2))
    gsrl.State.stereoRender = false;
#endif
}

// Check if stereo render is enabled
bool gsrlIsStereoRenderEnabled(void)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2))
    return gsrl.State.stereoRender;
#else
    return false;
#endif
}

// Clear color buffer with color
void gsrlClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    // Color values clamp to 0.0f(0) and 1.0f(255)
    float cr = (float)r/255;
    float cg = (float)g/255;
    float cb = (float)b/255;
    float ca = (float)a/255;

    glClearColor(cr, cg, cb, ca);
}

// Clear used screen buffers (color and depth)
void gsrlClearScreenBuffers(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Clear used buffers: Color and Depth (Depth is used for 3D)
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);     // Stencil buffer not used...
}

// Check and log OpenGL error codes
void gsrlCheckErrors(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    int check = 1;
    while (check)
    {
        const GLenum err = glGetError();
        switch (err)
        {
            case GL_NO_ERROR: check = 0; break;
            case 0x0500: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_INVALID_ENUM"); break;
            case 0x0501: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_INVALID_VALUE"); break;
            case 0x0502: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_INVALID_OPERATION"); break;
            case 0x0503: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_STACK_OVERFLOW"); break;
            case 0x0504: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_STACK_UNDERFLOW"); break;
            case 0x0505: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_OUT_OF_MEMORY"); break;
            case 0x0506: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: GL_INVALID_FRAMEBUFFER_OPERATION"); break;
            default: TRACELOG(GSRL_LOG_WARNING, "GL: Error detected: Unknown error code: %x", err); break;
        }
    }
#endif
}

// Set blend mode
void gsrlSetBlendMode(int mode)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if ((gsrl.State.currentBlendMode != mode) || ((mode == GSRL_BLEND_CUSTOM || mode == GSRL_BLEND_CUSTOM_SEPARATE) && gsrl.State.glCustomBlendModeModified))
    {
        gsrlDrawRenderBatch(gsrl.currentBatch);

        switch (mode)
        {
            case GSRL_BLEND_ALPHA: glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glBlendEquation(GL_FUNC_ADD); break;
            case GSRL_BLEND_ADDITIVE: glBlendFunc(GL_SRC_ALPHA, GL_ONE); glBlendEquation(GL_FUNC_ADD); break;
            case GSRL_BLEND_MULTIPLIED: glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA); glBlendEquation(GL_FUNC_ADD); break;
            case GSRL_BLEND_ADD_COLORS: glBlendFunc(GL_ONE, GL_ONE); glBlendEquation(GL_FUNC_ADD); break;
            case GSRL_BLEND_SUBTRACT_COLORS: glBlendFunc(GL_ONE, GL_ONE); glBlendEquation(GL_FUNC_SUBTRACT); break;
            case GSRL_BLEND_ALPHA_PREMULTIPLY: glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); glBlendEquation(GL_FUNC_ADD); break;
            case GSRL_BLEND_CUSTOM:
            {
                // NOTE: Using GL blend src/dst factors and GL equation configured with gsrlSetBlendFactors()
                glBlendFunc(gsrl.State.glBlendSrcFactor, gsrl.State.glBlendDstFactor); glBlendEquation(gsrl.State.glBlendEquation);

            } break;
            case GSRL_BLEND_CUSTOM_SEPARATE:
            {
                // NOTE: Using GL blend src/dst factors and GL equation configured with gsrlSetBlendFactorsSeparate()
                glBlendFuncSeparate(gsrl.State.glBlendSrcFactorRGB, gsrl.State.glBlendDestFactorRGB, gsrl.State.glBlendSrcFactorAlpha, gsrl.State.glBlendDestFactorAlpha);
                glBlendEquationSeparate(gsrl.State.glBlendEquationRGB, gsrl.State.glBlendEquationAlpha);

            } break;
            default: break;
        }

        gsrl.State.currentBlendMode = mode;
        gsrl.State.glCustomBlendModeModified = false;
    }
#endif
}

// Set blending mode factor and equation
void gsrlSetBlendFactors(int glSrcFactor, int glDstFactor, int glEquation)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if ((gsrl.State.glBlendSrcFactor != glSrcFactor) ||
        (gsrl.State.glBlendDstFactor != glDstFactor) ||
        (gsrl.State.glBlendEquation != glEquation))
    {
        gsrl.State.glBlendSrcFactor = glSrcFactor;
        gsrl.State.glBlendDstFactor = glDstFactor;
        gsrl.State.glBlendEquation = glEquation;

        gsrl.State.glCustomBlendModeModified = true;
    }
#endif
}

// Set blending mode factor and equation separately for RGB and alpha
void gsrlSetBlendFactorsSeparate(int glSrcRGB, int glDstRGB, int glSrcAlpha, int glDstAlpha, int glEqRGB, int glEqAlpha)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if ((gsrl.State.glBlendSrcFactorRGB != glSrcRGB) ||
        (gsrl.State.glBlendDestFactorRGB != glDstRGB) ||
        (gsrl.State.glBlendSrcFactorAlpha != glSrcAlpha) ||
        (gsrl.State.glBlendDestFactorAlpha != glDstAlpha) ||
        (gsrl.State.glBlendEquationRGB != glEqRGB) ||
        (gsrl.State.glBlendEquationAlpha != glEqAlpha))
    {
        gsrl.State.glBlendSrcFactorRGB = glSrcRGB;
        gsrl.State.glBlendDestFactorRGB = glDstRGB;
        gsrl.State.glBlendSrcFactorAlpha = glSrcAlpha;
        gsrl.State.glBlendDestFactorAlpha = glDstAlpha;
        gsrl.State.glBlendEquationRGB = glEqRGB;
        gsrl.State.glBlendEquationAlpha = glEqAlpha;

        gsrl.State.glCustomBlendModeModified = true;
    }
#endif
}

//----------------------------------------------------------------------------------
// Module Functions Definition - OpenGL Debug
//----------------------------------------------------------------------------------
#if defined(gsrl_ENABLE_OPENGL_DEBUG_CONTEXT) && defined(GRAPHICS_API_OPENGL_43)
static void GLAPIENTRY gsrlDebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    // Ignore non-significant error/warning codes (NVidia drivers)
    // NOTE: Here there are the details with a sample output:
    // - #131169 - Framebuffer detailed info: The driver allocated storage for renderbuffer 2. (severity: low)
    // - #131185 - Buffer detailed info: Buffer object 1 (bound to GL_ELEMENT_ARRAY_BUFFER_ARB, usage hint is GL_ENUM_88e4)
    //             will use VIDEO memory as the source for buffer object operations. (severity: low)
    // - #131218 - Program/shader state performance warning: Vertex shader in program 7 is being recompiled based on GL state. (severity: medium)
    // - #131204 - Texture state usage warning: The texture object (0) bound to texture image unit 0 does not have
    //             a defined base level and cannot be used for texture mapping. (severity: low)
    if ((id == 131169) || (id == 131185) || (id == 131218) || (id == 131204)) return;

    const char *msgSource = NULL;
    switch (source)
    {
        case GL_DEBUG_SOURCE_API: msgSource = "API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM: msgSource = "WINDOW_SYSTEM"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: msgSource = "SHADER_COMPILER"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY: msgSource = "THIRD_PARTY"; break;
        case GL_DEBUG_SOURCE_APPLICATION: msgSource = "APPLICATION"; break;
        case GL_DEBUG_SOURCE_OTHER: msgSource = "OTHER"; break;
        default: break;
    }

    const char *msgType = NULL;
    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR: msgType = "ERROR"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: msgType = "DEPRECATED_BEHAVIOR"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: msgType = "UNDEFINED_BEHAVIOR"; break;
        case GL_DEBUG_TYPE_PORTABILITY: msgType = "PORTABILITY"; break;
        case GL_DEBUG_TYPE_PERFORMANCE: msgType = "PERFORMANCE"; break;
        case GL_DEBUG_TYPE_MARKER: msgType = "MARKER"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP: msgType = "PUSH_GROUP"; break;
        case GL_DEBUG_TYPE_POP_GROUP: msgType = "POP_GROUP"; break;
        case GL_DEBUG_TYPE_OTHER: msgType = "OTHER"; break;
        default: break;
    }

    const char *msgSeverity = "DEFAULT";
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_LOW: msgSeverity = "LOW"; break;
        case GL_DEBUG_SEVERITY_MEDIUM: msgSeverity = "MEDIUM"; break;
        case GL_DEBUG_SEVERITY_HIGH: msgSeverity = "HIGH"; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: msgSeverity = "NOTIFICATION"; break;
        default: break;
    }

    TRACELOG(LOG_WARNING, "GL: OpenGL debug message: %s", message);
    TRACELOG(LOG_WARNING, "    > Type: %s", msgType);
    TRACELOG(LOG_WARNING, "    > Source = %s", msgSource);
    TRACELOG(LOG_WARNING, "    > Severity = %s", msgSeverity);
}
#endif

//----------------------------------------------------------------------------------
// Module Functions Definition - gsrl functionality
//----------------------------------------------------------------------------------

// Initialize gsrl: OpenGL extensions, default buffers/shaders/textures, OpenGL states
void gsrlInit(int width, int height)
{
    // Enable OpenGL debug context if required
#if defined(gsrl_ENABLE_OPENGL_DEBUG_CONTEXT) && defined(GRAPHICS_API_OPENGL_43)
    if ((glDebugMessageCallback != NULL) && (glDebugMessageControl != NULL))
    {
        glDebugMessageCallback(gsrlDebugMessageCallback, 0);
        // glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DEBUG_TYPE_ERROR, GL_DEBUG_SEVERITY_HIGH, 0, 0, GL_TRUE);

        // Debug context options:
        //  - GL_DEBUG_OUTPUT - Faster version but not useful for breakpoints
        //  - GL_DEBUG_OUTPUT_SYNCHRONUS - Callback is in sync with errors, so a breakpoint can be placed on the callback in order to get a stacktrace for the GL error
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    }
#endif

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // Init default white texture
    unsigned char pixels[4] = { 255, 255, 255, 255 };   // 1 pixel RGBA (4 bytes)
    gsrl.State.defaultTextureId = gsrlLoadTexture(pixels, 1, 1, GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8, 1);

    if (gsrl.State.defaultTextureId != 0) TRACELOG(GSRL_LOG_INFO, "TEXTURE: [ID %i] Default texture loaded successfully", gsrl.State.defaultTextureId);
    else TRACELOG(GSRL_LOG_WARNING, "TEXTURE: Failed to load default texture");

    // Init default Shader (customized for GL 3.3 and ES2)
    // Loaded: gsrl.State.defaultShaderId + gsrl.State.defaultShaderLocs
    gsrlLoadShaderDefault();
    gsrl.State.currentShaderId = gsrl.State.defaultShaderId;
    gsrl.State.currentShaderLocs = gsrl.State.defaultShaderLocs;

    // Init default vertex arrays buffers
    // Simulate that the default shader has the location GSRL_SHADER_LOC_VERTEX_NORMAL to bind the normal buffer for the default render batch
    gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL] = GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL;
    gsrl.defaultBatch = gsrlLoadRenderBatch(GSRL_DEFAULT_BATCH_BUFFERS, GSRL_DEFAULT_BATCH_BUFFER_ELEMENTS);
    gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL] = -1;
    gsrl.currentBatch = &gsrl.defaultBatch;

    // Init stack matrices (emulating OpenGL 1.1)
    for (int i = 0; i < GSRL_MAX_MATRIX_STACK_SIZE; i++) gsrl.State.stack[i] = gsrlMatrixIdentity();

    // Init internal matrices
    gsrl.State.transform = gsrlMatrixIdentity();
    gsrl.State.projection = gsrlMatrixIdentity();
    gsrl.State.modelview = gsrlMatrixIdentity();
    gsrl.State.currentMatrix = &gsrl.State.modelview;
#endif  // GRAPHICS_API_OPENGL_33 || GRAPHICS_API_OPENGL_ES2

    // Initialize OpenGL default states
    //----------------------------------------------------------
    // Init state: Depth test
    glDepthFunc(GL_LEQUAL);                                 // Type of depth testing to apply
    glDisable(GL_DEPTH_TEST);                               // Disable depth testing for 2D (only used for 3D)

    // Init state: Blending mode
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);      // Color blending function (how colors are mixed)
    glEnable(GL_BLEND);                                     // Enable color blending (required to work with transparencies)

    // Init state: Culling
    // NOTE: All shapes/models triangles are drawn CCW
    glCullFace(GL_BACK);                                    // Cull the back face (default)
    glFrontFace(GL_CCW);                                    // Front face are defined counter clockwise (default)
    glEnable(GL_CULL_FACE);                                 // Enable backface culling

    // Init state: Cubemap seamless
#if defined(GRAPHICS_API_OPENGL_33)
    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);                 // Seamless cubemaps (not supported on OpenGL ES 2.0)
#endif

#if defined(GRAPHICS_API_OPENGL_11)
    // Init state: Color hints (deprecated in OpenGL 3.0+)
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);      // Improve quality of color and texture coordinate interpolation
    glShadeModel(GL_SMOOTH);                                // Smooth shading between vertex (vertex colors interpolation)
#endif

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // Store screen size into global variables
    gsrl.State.framebufferWidth = width;
    gsrl.State.framebufferHeight = height;

    TRACELOG(GSRL_LOG_INFO, "gsrl: Default OpenGL state initialized successfully");
    //----------------------------------------------------------
#endif

    // Init state: Color/Depth buffers clear
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                   // Set clear color (black)
    glClearDepth(1.0f);                                     // Set clear depth value (default)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Clear color and depth buffers (depth buffer required for 3D)
}

// Vertex Buffer Object deinitialization (memory free)
void gsrlClose(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrlUnloadRenderBatch(gsrl.defaultBatch);

    gsrlUnloadShaderDefault();          // Unload default shader

    glDeleteTextures(1, &gsrl.State.defaultTextureId); // Unload default texture
    TRACELOG(GSRL_LOG_INFO, "TEXTURE: [ID %i] Default texture unloaded successfully", gsrl.State.defaultTextureId);
#endif
}

// Load OpenGL extensions
// NOTE: External loader function must be provided
void gsrlLoadExtensions(void *loader)
{
#if defined(GRAPHICS_API_OPENGL_33)     // Also defined for GRAPHICS_API_OPENGL_21
    // NOTE: glad is generated and contains only required OpenGL 3.3 Core extensions (and lower versions)
    if (gladLoadGL((GLADloadfunc)loader) == 0) TRACELOG(GSRL_LOG_WARNING, "GLAD: Cannot load OpenGL extensions");
    else TRACELOG(GSRL_LOG_INFO, "GLAD: OpenGL extensions loaded successfully");

    // Get number of supported extensions
    GLint numExt = 0;
    glGetIntegerv(GL_NUM_EXTENSIONS, &numExt);
    TRACELOG(GSRL_LOG_INFO, "GL: Supported extensions count: %i", numExt);

#if defined(gsrl_SHOW_GL_DETAILS_INFO)
    // Get supported extensions list
    // WARNING: glGetStringi() not available on OpenGL 2.1
    TRACELOG(GSRL_LOG_INFO, "GL: OpenGL extensions:");
    for (int i = 0; i < numExt; i++) TRACELOG(GSRL_LOG_INFO, "    %s", glGetStringi(GL_EXTENSIONS, i));
#endif

#if defined(GRAPHICS_API_OPENGL_21)
    // Register supported extensions flags
    // Optional OpenGL 2.1 extensions
    gsrl.ExtSupported.vao = GLAD_GL_ARB_vertex_array_object;
    gsrl.ExtSupported.instancing = (GLAD_GL_EXT_draw_instanced && GLAD_GL_ARB_instanced_arrays);
    gsrl.ExtSupported.texNPOT = GLAD_GL_ARB_texture_non_power_of_two;
    gsrl.ExtSupported.texFloat32 = GLAD_GL_ARB_texture_float;
    gsrl.ExtSupported.texFloat16 = GLAD_GL_ARB_texture_float;
    gsrl.ExtSupported.texDepth = GLAD_GL_ARB_depth_texture;
    gsrl.ExtSupported.maxDepthBits = 32;
    gsrl.ExtSupported.texAnisoFilter = GLAD_GL_EXT_texture_filter_anisotropic;
    gsrl.ExtSupported.texMirrorClamp = GLAD_GL_EXT_texture_mirror_clamp;
#else
    // Register supported extensions flags
    // OpenGL 3.3 extensions supported by default (core)
    gsrl.ExtSupported.vao = true;
    gsrl.ExtSupported.instancing = true;
    gsrl.ExtSupported.texNPOT = true;
    gsrl.ExtSupported.texFloat32 = true;
    gsrl.ExtSupported.texFloat16 = true;
    gsrl.ExtSupported.texDepth = true;
    gsrl.ExtSupported.maxDepthBits = 32;
    gsrl.ExtSupported.texAnisoFilter = true;
    gsrl.ExtSupported.texMirrorClamp = true;
#endif

    // Optional OpenGL 3.3 extensions
    gsrl.ExtSupported.texCompASTC = GLAD_GL_KHR_texture_compression_astc_hdr && GLAD_GL_KHR_texture_compression_astc_ldr;
    gsrl.ExtSupported.texCompDXT = GLAD_GL_EXT_texture_compression_s3tc;  // Texture compression: DXT
    gsrl.ExtSupported.texCompETC2 = GLAD_GL_ARB_ES3_compatibility;        // Texture compression: ETC2/EAC
    #if defined(GRAPHICS_API_OPENGL_43)
    gsrl.ExtSupported.computeShader = GLAD_GL_ARB_compute_shader;
    gsrl.ExtSupported.ssbo = GLAD_GL_ARB_shader_storage_buffer_object;
    #endif

#endif  // GRAPHICS_API_OPENGL_33

#if defined(GRAPHICS_API_OPENGL_ES3)
    // Register supported extensions flags
    // OpenGL ES 3.0 extensions supported by default (or it should be)
    gsrl.ExtSupported.vao = true;
    gsrl.ExtSupported.instancing = true;
    gsrl.ExtSupported.texNPOT = true;
    gsrl.ExtSupported.texFloat32 = true;
    gsrl.ExtSupported.texFloat16 = true;
    gsrl.ExtSupported.texDepth = true;
    gsrl.ExtSupported.texDepthWebGL = true;
    gsrl.ExtSupported.maxDepthBits = 24;
    gsrl.ExtSupported.texAnisoFilter = true;
    gsrl.ExtSupported.texMirrorClamp = true;
    // TODO: Check for additional OpenGL ES 3.0 supported extensions:
    //gsrl.ExtSupported.texCompDXT = true;
    //gsrl.ExtSupported.texCompETC1 = true;
    //gsrl.ExtSupported.texCompETC2 = true;
    //gsrl.ExtSupported.texCompPVRT = true;
    //gsrl.ExtSupported.texCompASTC = true;
    //gsrl.ExtSupported.maxAnisotropyLevel = true;
    //gsrl.ExtSupported.computeShader = true;
    //gsrl.ExtSupported.ssbo = true;

#elif defined(GRAPHICS_API_OPENGL_ES2)

    #if defined(PLATFORM_DESKTOP_GLFW) || defined(PLATFORM_DESKTOP_SDL)
    // TODO: Support GLAD loader for OpenGL ES 3.0
    if (gladLoadGLES2((GLADloadfunc)loader) == 0) TRACELOG(GSRL_LOG_WARNING, "GLAD: Cannot load OpenGL ES2.0 functions");
    else TRACELOG(GSRL_LOG_INFO, "GLAD: OpenGL ES 2.0 loaded successfully");
    #endif

    // Get supported extensions list
    GLint numExt = 0;
    const char **extList = GSRL_MALLOC(512*sizeof(const char *)); // Allocate 512 strings pointers (2 KB)
    const char *extensions = (const char *)glGetString(GL_EXTENSIONS);  // One big const string

    // NOTE: We have to duplicate string because glGetString() returns a const string
    int size = strlen(extensions) + 1;      // Get extensions string size in bytes
    char *extensionsDup = (char *)GSRL_CALLOC(size, sizeof(char));
    strcpy(extensionsDup, extensions);
    extList[numExt] = extensionsDup;

    for (int i = 0; i < size; i++)
    {
        if (extensionsDup[i] == ' ')
        {
            extensionsDup[i] = '\0';
            numExt++;
            extList[numExt] = &extensionsDup[i + 1];
        }
    }

    TRACELOG(GSRL_LOG_INFO, "GL: Supported extensions count: %i", numExt);

#if defined(gsrl_SHOW_GL_DETAILS_INFO)
    TRACELOG(GSRL_LOG_INFO, "GL: OpenGL extensions:");
    for (int i = 0; i < numExt; i++) TRACELOG(GSRL_LOG_INFO, "    %s", extList[i]);
#endif

    // Check required extensions
    for (int i = 0; i < numExt; i++)
    {
        // Check VAO support
        // NOTE: Only check on OpenGL ES, OpenGL 3.3 has VAO support as core feature
        if (strcmp(extList[i], (const char *)"GL_OES_vertex_array_object") == 0)
        {
            // The extension is supported by our hardware and driver, try to get related functions pointers
            // NOTE: emscripten does not support VAOs natively, it uses emulation and it reduces overall performance...
            glGenVertexArrays = (PFNGLGENVERTEXARRAYSOESPROC)((gsrlLoadProc)loader)("glGenVertexArraysOES");
            glBindVertexArray = (PFNGLBINDVERTEXARRAYOESPROC)((gsrlLoadProc)loader)("glBindVertexArrayOES");
            glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSOESPROC)((gsrlLoadProc)loader)("glDeleteVertexArraysOES");
            //glIsVertexArray = (PFNGLISVERTEXARRAYOESPROC)loader("glIsVertexArrayOES");     // NOTE: Fails in WebGL, omitted

            if ((glGenVertexArrays != NULL) && (glBindVertexArray != NULL) && (glDeleteVertexArrays != NULL)) gsrl.ExtSupported.vao = true;
        }

        // Check instanced rendering support
        if (strstr(extList[i], (const char*)"instanced_arrays") != NULL)   // Broad check for instanced_arrays
        {
            // Specific check
            if (strcmp(extList[i], (const char *)"GL_ANGLE_instanced_arrays") == 0)      // ANGLE
            {
                glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawArraysInstancedANGLE");
                glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawElementsInstancedANGLE");
                glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISOREXTPROC)((gsrlLoadProc)loader)("glVertexAttribDivisorANGLE");
            }
            else if (strcmp(extList[i], (const char *)"GL_EXT_instanced_arrays") == 0)   // EXT
            {
                glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawArraysInstancedEXT");
                glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawElementsInstancedEXT");
                glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISOREXTPROC)((gsrlLoadProc)loader)("glVertexAttribDivisorEXT");
            }
            else if (strcmp(extList[i], (const char *)"GL_NV_instanced_arrays") == 0)    // NVIDIA GLES
            {
                glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawArraysInstancedNV");
                glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawElementsInstancedNV");
                glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISOREXTPROC)((gsrlLoadProc)loader)("glVertexAttribDivisorNV");
            }

            // The feature will only be marked as supported if the elements from GL_XXX_instanced_arrays are present
            if ((glDrawArraysInstanced != NULL) && (glDrawElementsInstanced != NULL) && (glVertexAttribDivisor != NULL)) gsrl.ExtSupported.instancing = true;
        }
        else if (strstr(extList[i], (const char *)"draw_instanced") != NULL)
        {
            // GL_ANGLE_draw_instanced doesn't exist
            if (strcmp(extList[i], (const char *)"GL_EXT_draw_instanced") == 0)
            {
                glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawArraysInstancedEXT");
                glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawElementsInstancedEXT");
            }
            else if (strcmp(extList[i], (const char*)"GL_NV_draw_instanced") == 0)
            {
                glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawArraysInstancedNV");
                glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)((gsrlLoadProc)loader)("glDrawElementsInstancedNV");
            }

            // But the functions will at least be loaded if only GL_XX_EXT_draw_instanced exist
            if ((glDrawArraysInstanced != NULL) && (glDrawElementsInstanced != NULL) && (glVertexAttribDivisor != NULL)) gsrl.ExtSupported.instancing = true;
        }

        // Check NPOT textures support
        // NOTE: Only check on OpenGL ES, OpenGL 3.3 has NPOT textures full support as core feature
        if (strcmp(extList[i], (const char *)"GL_OES_texture_npot") == 0) gsrl.ExtSupported.texNPOT = true;

        // Check texture float support
        if (strcmp(extList[i], (const char *)"GL_OES_texture_float") == 0) gsrl.ExtSupported.texFloat32 = true;
        if (strcmp(extList[i], (const char *)"GL_OES_texture_half_float") == 0) gsrl.ExtSupported.texFloat16 = true;

        // Check depth texture support
        if (strcmp(extList[i], (const char *)"GL_OES_depth_texture") == 0) gsrl.ExtSupported.texDepth = true;
        if (strcmp(extList[i], (const char *)"GL_WEBGL_depth_texture") == 0) gsrl.ExtSupported.texDepthWebGL = true;    // WebGL requires unsized internal format
        if (gsrl.ExtSupported.texDepthWebGL) gsrl.ExtSupported.texDepth = true;

        if (strcmp(extList[i], (const char *)"GL_OES_depth24") == 0) gsrl.ExtSupported.maxDepthBits = 24;   // Not available on WebGL
        if (strcmp(extList[i], (const char *)"GL_OES_depth32") == 0) gsrl.ExtSupported.maxDepthBits = 32;   // Not available on WebGL

        // Check texture compression support: DXT
        if ((strcmp(extList[i], (const char *)"GL_EXT_texture_compression_s3tc") == 0) ||
            (strcmp(extList[i], (const char *)"GL_WEBGL_compressed_texture_s3tc") == 0) ||
            (strcmp(extList[i], (const char *)"GL_WEBKIT_WEBGL_compressed_texture_s3tc") == 0)) gsrl.ExtSupported.texCompDXT = true;

        // Check texture compression support: ETC1
        if ((strcmp(extList[i], (const char *)"GL_OES_compressed_ETC1_RGB8_texture") == 0) ||
            (strcmp(extList[i], (const char *)"GL_WEBGL_compressed_texture_etc1") == 0)) gsrl.ExtSupported.texCompETC1 = true;

        // Check texture compression support: ETC2/EAC
        if (strcmp(extList[i], (const char *)"GL_ARB_ES3_compatibility") == 0) gsrl.ExtSupported.texCompETC2 = true;

        // Check texture compression support: PVR
        if (strcmp(extList[i], (const char *)"GL_IMG_texture_compression_pvrtc") == 0) gsrl.ExtSupported.texCompPVRT = true;

        // Check texture compression support: ASTC
        if (strcmp(extList[i], (const char *)"GL_KHR_texture_compression_astc_hdr") == 0) gsrl.ExtSupported.texCompASTC = true;

        // Check anisotropic texture filter support
        if (strcmp(extList[i], (const char *)"GL_EXT_texture_filter_anisotropic") == 0) gsrl.ExtSupported.texAnisoFilter = true;

        // Check clamp mirror wrap mode support
        if (strcmp(extList[i], (const char *)"GL_EXT_texture_mirror_clamp") == 0) gsrl.ExtSupported.texMirrorClamp = true;
    }

    // Free extensions pointers
    GSRL_FREE(extList);
    GSRL_FREE(extensionsDup);    // Duplicated string must be deallocated
#endif  // GRAPHICS_API_OPENGL_ES2

    // Check OpenGL information and capabilities
    //------------------------------------------------------------------------------
    // Show current OpenGL and GLSL version
    TRACELOG(GSRL_LOG_INFO, "GL: OpenGL device information:");
    TRACELOG(GSRL_LOG_INFO, "    > Vendor:   %s", glGetString(GL_VENDOR));
    TRACELOG(GSRL_LOG_INFO, "    > Renderer: %s", glGetString(GL_RENDERER));
    TRACELOG(GSRL_LOG_INFO, "    > Version:  %s", glGetString(GL_VERSION));
    TRACELOG(GSRL_LOG_INFO, "    > GLSL:     %s", glGetString(GL_SHADING_LANGUAGE_VERSION));

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // NOTE: Anisotropy levels capability is an extension
    #ifndef GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
        #define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
    #endif
    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &gsrl.ExtSupported.maxAnisotropyLevel);

#if defined(gsrl_SHOW_GL_DETAILS_INFO)
    // Show some OpenGL GPU capabilities
    TRACELOG(GSRL_LOG_INFO, "GL: OpenGL capabilities:");
    GLint capability = 0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_TEXTURE_SIZE: %i", capability);
    glGetIntegerv(GL_MAX_CUBE_MAP_TEXTURE_SIZE, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_CUBE_MAP_TEXTURE_SIZE: %i", capability);
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_TEXTURE_IMAGE_UNITS: %i", capability);
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_VERTEX_ATTRIBS: %i", capability);
    #if !defined(GRAPHICS_API_OPENGL_ES2)
    glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_UNIFORM_BLOCK_SIZE: %i", capability);
    glGetIntegerv(GL_MAX_DRAW_BUFFERS, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_DRAW_BUFFERS: %i", capability);
    if (gsrl.ExtSupported.texAnisoFilter) TRACELOG(GSRL_LOG_INFO, "    GL_MAX_TEXTURE_MAX_ANISOTROPY: %.0f", gsrl.ExtSupported.maxAnisotropyLevel);
    #endif
    glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_NUM_COMPRESSED_TEXTURE_FORMATS: %i", capability);
    GLint *compFormats = (GLint *)GSRL_CALLOC(capability, sizeof(GLint));
    glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, compFormats);
    for (int i = 0; i < capability; i++) TRACELOG(GSRL_LOG_INFO, "        %s", gsrlGetCompressedFormatName(compFormats[i]));
    GSRL_FREE(compFormats);

#if defined(GRAPHICS_API_OPENGL_43)
    glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_VERTEX_ATTRIB_BINDINGS: %i", capability);
    glGetIntegerv(GL_MAX_UNIFORM_LOCATIONS, &capability);
    TRACELOG(GSRL_LOG_INFO, "    GL_MAX_UNIFORM_LOCATIONS: %i", capability);
#endif  // GRAPHICS_API_OPENGL_43
#else   // gsrl_SHOW_GL_DETAILS_INFO

    // Show some basic info about GL supported features
    if (gsrl.ExtSupported.vao) TRACELOG(GSRL_LOG_INFO, "GL: VAO extension detected, VAO functions loaded successfully");
    else TRACELOG(GSRL_LOG_WARNING, "GL: VAO extension not found, VAO not supported");
    if (gsrl.ExtSupported.texNPOT) TRACELOG(GSRL_LOG_INFO, "GL: NPOT textures extension detected, full NPOT textures supported");
    else TRACELOG(GSRL_LOG_WARNING, "GL: NPOT textures extension not found, limited NPOT support (no-mipmaps, no-repeat)");
    if (gsrl.ExtSupported.texCompDXT) TRACELOG(GSRL_LOG_INFO, "GL: DXT compressed textures supported");
    if (gsrl.ExtSupported.texCompETC1) TRACELOG(GSRL_LOG_INFO, "GL: ETC1 compressed textures supported");
    if (gsrl.ExtSupported.texCompETC2) TRACELOG(GSRL_LOG_INFO, "GL: ETC2/EAC compressed textures supported");
    if (gsrl.ExtSupported.texCompPVRT) TRACELOG(GSRL_LOG_INFO, "GL: PVRT compressed textures supported");
    if (gsrl.ExtSupported.texCompASTC) TRACELOG(GSRL_LOG_INFO, "GL: ASTC compressed textures supported");
    if (gsrl.ExtSupported.computeShader) TRACELOG(GSRL_LOG_INFO, "GL: Compute shaders supported");
    if (gsrl.ExtSupported.ssbo) TRACELOG(GSRL_LOG_INFO, "GL: Shader storage buffer objects supported");
#endif  // gsrl_SHOW_GL_DETAILS_INFO

#endif  // GRAPHICS_API_OPENGL_33 || GRAPHICS_API_OPENGL_ES2
}

// Get current OpenGL version
int gsrlGetVersion(void)
{
    int glVersion = 0;
#if defined(GRAPHICS_API_OPENGL_11)
    glVersion = GSRL_OPENGL_11;
#endif
#if defined(GRAPHICS_API_OPENGL_21)
    glVersion = GSRL_OPENGL_21;
#elif defined(GRAPHICS_API_OPENGL_43)
    glVersion = GSRL_OPENGL_43;
#elif defined(GRAPHICS_API_OPENGL_33)
    glVersion = GSRL_OPENGL_33;
#endif
#if defined(GRAPHICS_API_OPENGL_ES3)
    glVersion = GSRL_OPENGL_ES_30;
#elif defined(GRAPHICS_API_OPENGL_ES2)
    glVersion = GSRL_OPENGL_ES_20;
#endif

    return glVersion;
}

// Set current framebuffer width
void gsrlSetFramebufferWidth(int width)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrl.State.framebufferWidth = width;
#endif
}

// Set current framebuffer height
void gsrlSetFramebufferHeight(int height)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrl.State.framebufferHeight = height;
#endif
}

// Get default framebuffer width
int gsrlGetFramebufferWidth(void)
{
    int width = 0;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    width = gsrl.State.framebufferWidth;
#endif
    return width;
}

// Get default framebuffer height
int gsrlGetFramebufferHeight(void)
{
    int height = 0;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    height = gsrl.State.framebufferHeight;
#endif
    return height;
}

// Get default internal texture (white texture)
// NOTE: Default texture is a 1x1 pixel UNCOMPRESSED_R8G8B8A8
unsigned int gsrlGetTextureIdDefault(void)
{
    unsigned int id = 0;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    id = gsrl.State.defaultTextureId;
#endif
    return id;
}

// Get default shader id
unsigned int gsrlGetShaderIdDefault(void)
{
    unsigned int id = 0;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    id = gsrl.State.defaultShaderId;
#endif
    return id;
}

// Get default shader locs
int *gsrlGetShaderLocsDefault(void)
{
    int *locs = NULL;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    locs = gsrl.State.defaultShaderLocs;
#endif
    return locs;
}

// Render batch management
//------------------------------------------------------------------------------------------------
// Load render batch
#if defined(GRAPHICS_API_OPENGL_33)
static void gsrlVbRingInit(int bufferElements);   /* [ps2x vbring] defined below */
#endif
void ps2xgsrlVbRingForget(unsigned int prog);
gsrlRenderBatch gsrlLoadRenderBatch(int numBuffers, int bufferElements)
{
    gsrlRenderBatch batch = { 0 };

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // Initialize CPU (RAM) vertex buffers (position, texcoord, color data and indexes)
    //--------------------------------------------------------------------------------------------
    batch.vertexBuffer = (gsrlVertexBuffer *)GSRL_MALLOC(numBuffers*sizeof(gsrlVertexBuffer));

    for (int i = 0; i < numBuffers; i++)
    {
        batch.vertexBuffer[i].elementCount = bufferElements;

        batch.vertexBuffer[i].vertices = (float *)GSRL_MALLOC(bufferElements*3*4*sizeof(float));        // 3 float by vertex, 4 vertex by quad
        batch.vertexBuffer[i].texcoords = (float *)GSRL_MALLOC(bufferElements*2*4*sizeof(float));       // 2 float by texcoord, 4 texcoord by quad
        batch.vertexBuffer[i].normals = (float *)GSRL_MALLOC(bufferElements*3*4*sizeof(float));        // 3 float by vertex, 4 vertex by quad
        batch.vertexBuffer[i].colors = (unsigned char *)GSRL_MALLOC(bufferElements*4*4*sizeof(unsigned char));   // 4 float by color, 4 colors by quad
#if defined(GRAPHICS_API_OPENGL_33)
        batch.vertexBuffer[i].indices = (unsigned int *)GSRL_MALLOC(bufferElements*6*sizeof(unsigned int));      // 6 int by quad (indices)
#endif
#if defined(GRAPHICS_API_OPENGL_ES2)
        batch.vertexBuffer[i].indices = (unsigned short *)GSRL_MALLOC(bufferElements*6*sizeof(unsigned short));  // 6 int by quad (indices)
#endif

        for (int j = 0; j < (3*4*bufferElements); j++) batch.vertexBuffer[i].vertices[j] = 0.0f;
        for (int j = 0; j < (2*4*bufferElements); j++) batch.vertexBuffer[i].texcoords[j] = 0.0f;
        for (int j = 0; j < (3*4*bufferElements); j++) batch.vertexBuffer[i].normals[j] = 0.0f;
        for (int j = 0; j < (4*4*bufferElements); j++) batch.vertexBuffer[i].colors[j] = 0;

        int k = 0;

        // Indices can be initialized right now
        for (int j = 0; j < (6*bufferElements); j += 6)
        {
            batch.vertexBuffer[i].indices[j] = 4*k;
            batch.vertexBuffer[i].indices[j + 1] = 4*k + 1;
            batch.vertexBuffer[i].indices[j + 2] = 4*k + 2;
            batch.vertexBuffer[i].indices[j + 3] = 4*k;
            batch.vertexBuffer[i].indices[j + 4] = 4*k + 2;
            batch.vertexBuffer[i].indices[j + 5] = 4*k + 3;

            k++;
        }

        gsrl.State.vertexCounter = 0;
    }

    TRACELOG(GSRL_LOG_INFO, "gsrl: Render batch vertex buffers loaded successfully in RAM (CPU)");
    //--------------------------------------------------------------------------------------------

    // Upload to GPU (VRAM) vertex data and initialize VAOs/VBOs
    //--------------------------------------------------------------------------------------------
    for (int i = 0; i < numBuffers; i++)
    {
        if (gsrl.ExtSupported.vao)
        {
            // Initialize Quads VAO
            glGenVertexArrays(1, &batch.vertexBuffer[i].vaoId);
            glBindVertexArray(batch.vertexBuffer[i].vaoId);
        }

        // Quads - Vertex buffers binding and attributes enable
        // Vertex position buffer (shader-location = 0)
        glGenBuffers(1, &batch.vertexBuffer[i].vboId[0]);
        glBindBuffer(GL_ARRAY_BUFFER, batch.vertexBuffer[i].vboId[0]);
        glBufferData(GL_ARRAY_BUFFER, bufferElements*3*4*sizeof(float), batch.vertexBuffer[i].vertices, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_POSITION]);
        glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_POSITION], 3, GL_FLOAT, 0, 0, 0);

        // Vertex texcoord buffer (shader-location = 1)
        glGenBuffers(1, &batch.vertexBuffer[i].vboId[1]);
        glBindBuffer(GL_ARRAY_BUFFER, batch.vertexBuffer[i].vboId[1]);
        glBufferData(GL_ARRAY_BUFFER, bufferElements*2*4*sizeof(float), batch.vertexBuffer[i].texcoords, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_TEXCOORD01]);
        glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_TEXCOORD01], 2, GL_FLOAT, 0, 0, 0);

        // Vertex normal buffer (shader-location = 2)
        glGenBuffers(1, &batch.vertexBuffer[i].vboId[2]);
        glBindBuffer(GL_ARRAY_BUFFER, batch.vertexBuffer[i].vboId[2]);
        glBufferData(GL_ARRAY_BUFFER, bufferElements*3*4*sizeof(float), batch.vertexBuffer[i].normals, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL]);
        glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL], 3, GL_FLOAT, 0, 0, 0);

        // Vertex color buffer (shader-location = 3)
        glGenBuffers(1, &batch.vertexBuffer[i].vboId[3]);
        glBindBuffer(GL_ARRAY_BUFFER, batch.vertexBuffer[i].vboId[3]);
        glBufferData(GL_ARRAY_BUFFER, bufferElements*4*4*sizeof(unsigned char), batch.vertexBuffer[i].colors, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_COLOR]);
        glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_COLOR], 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);

        // Fill index buffer
        glGenBuffers(1, &batch.vertexBuffer[i].vboId[4]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch.vertexBuffer[i].vboId[4]);
#if defined(GRAPHICS_API_OPENGL_33)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferElements*6*sizeof(int), batch.vertexBuffer[i].indices, GL_STATIC_DRAW);
#endif
#if defined(GRAPHICS_API_OPENGL_ES2)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferElements*6*sizeof(short), batch.vertexBuffer[i].indices, GL_STATIC_DRAW);
#endif
    }

#if defined(GRAPHICS_API_OPENGL_33)
    gsrlVbRingInit(bufferElements);   /* [ps2x vbring] */
#endif
    TRACELOG(GSRL_LOG_INFO, "gsrl: Render batch vertex buffers loaded successfully in VRAM (GPU)");

    // Unbind the current VAO
    if (gsrl.ExtSupported.vao) glBindVertexArray(0);
    //--------------------------------------------------------------------------------------------

    // Init draw calls tracking system
    //--------------------------------------------------------------------------------------------
    batch.draws = (gsrlDrawCall *)GSRL_MALLOC(GSRL_DEFAULT_BATCH_DRAWCALLS*sizeof(gsrlDrawCall));

    for (int i = 0; i < GSRL_DEFAULT_BATCH_DRAWCALLS; i++)
    {
        batch.draws[i].mode = GSRL_QUADS;
        batch.draws[i].vertexCount = 0;
        batch.draws[i].vertexAlignment = 0;
        //batch.draws[i].vaoId = 0;
        //batch.draws[i].shaderId = 0;
        batch.draws[i].textureId = gsrl.State.defaultTextureId;
        //batch.draws[i].gsrl.State.projection = gsrlMatrixIdentity();
        //batch.draws[i].gsrl.State.modelview = gsrlMatrixIdentity();
    }

    batch.bufferCount = numBuffers;    // Record buffer count
    batch.drawCounter = 1;             // Reset draws counter
    batch.currentDepth = -1.0f;         // Reset depth value
    //--------------------------------------------------------------------------------------------
#endif

    return batch;
}

// Unload default internal buffers vertex data from CPU and GPU
void gsrlUnloadRenderBatch(gsrlRenderBatch batch)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // Unbind everything
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Unload all vertex buffers data
    for (int i = 0; i < batch.bufferCount; i++)
    {
        // Unbind VAO attribs data
        if (gsrl.ExtSupported.vao)
        {
            glBindVertexArray(batch.vertexBuffer[i].vaoId);
            glDisableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION);
            glDisableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD);
            glDisableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL);
            glDisableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_COLOR);
            glBindVertexArray(0);
        }

        // Delete VBOs from GPU (VRAM)
        glDeleteBuffers(1, &batch.vertexBuffer[i].vboId[0]);
        glDeleteBuffers(1, &batch.vertexBuffer[i].vboId[1]);
        glDeleteBuffers(1, &batch.vertexBuffer[i].vboId[2]);
        glDeleteBuffers(1, &batch.vertexBuffer[i].vboId[3]);
        glDeleteBuffers(1, &batch.vertexBuffer[i].vboId[4]);

        // Delete VAOs from GPU (VRAM)
        if (gsrl.ExtSupported.vao) glDeleteVertexArrays(1, &batch.vertexBuffer[i].vaoId);

        // Free vertex arrays memory from CPU (RAM)
        GSRL_FREE(batch.vertexBuffer[i].vertices);
        GSRL_FREE(batch.vertexBuffer[i].texcoords);
        GSRL_FREE(batch.vertexBuffer[i].normals);
        GSRL_FREE(batch.vertexBuffer[i].colors);
        GSRL_FREE(batch.vertexBuffer[i].indices);
    }

    // Unload arrays
    GSRL_FREE(batch.vertexBuffer);
    GSRL_FREE(batch.draws);
#endif
}

// Draw render batch
// NOTE: We require a pointer to reset batch and increase current buffer (multi-buffer)
unsigned long long g_gsrlDrawCalls = 0, g_gsrlBatchFlushes = 0;   /* [ps2x glcalls] read by the runtime fps line */
double g_gsrlFlushNs = 0.0;   /* [ps2x flushtime] wall ns spent inside non-empty gsrlDrawRenderBatch calls */

/* [ps2x vbring] persistent-mapped vertex ring. Every gsrl flush used to upload its vertices with four
   glBufferSubData calls into a 4-deep buffer ring (driver-side copy + rename + a DMA before the draw) and then
   re-send the MVP matrix and the two constant uniforms. With ~3000 flushes/frame that fixed per-flush work was
   ~80 GPU ms/s + ~2.5 CPU us/flush on the fast box and dominated the low-end machines. Here the CPU-side batch
   arrays are memcpy'd straight into a persistently mapped (GL_MAP_PERSISTENT|COHERENT) ring, the draws index
   the ring at the cursor, and a fence per ring segment keeps us from overwriting data the GPU still reads.
   Uniforms are re-sent only when the program or the matrix changed. Needs GL_ARB_buffer_storage (GL 4.4);
   without it, or with PS2X_VBRING=0, the original SubData path runs unchanged.
   PS2X_VBRING=N sets the ring size in vertices; PS2X_VBRING_NOCACHE bit 1 = always re-send the MVP, bit 2 = always
   re-send the constants (both were measured harmless on this box; kept as switches). */
#if !defined(GSRL_VBRING_VERTS)
    #define GSRL_VBRING_VERTS   (1 << 19)     /* 524288 vertices = 8 full batches, ~10 fight frames */
#endif
#define GSRL_VBRING_SEGS  4
typedef struct gsrlVbRing {
    int on, tried, persistent;
    unsigned int vao, vbo[4], ibo;
    unsigned char *map[4];
    int ringVerts, segVerts, cursor, curSeg, lastFencedSeg;
    void *fence[GSRL_VBRING_SEGS];
    unsigned int mvpProg[16]; float mvp[16][16]; int mvpN;   /* per-program cache of the last uploaded MVP */
    unsigned int constProg[16]; int constN;                   /* programs that already got colDiffuse/texture0 */
} gsrlVbRing;
static gsrlVbRing g_vbr = { 0 };
static int g_vbrNoCache = -1;
static int gsrlVbRingNoCache(void) { if (g_vbrNoCache < 0) { const char *e = getenv("PS2X_VBRING_NOCACHE"); g_vbrNoCache = e ? atoi(e) : 0; } return g_vbrNoCache; }
unsigned long long g_gsrlVbRingWaits = 0, g_gsrlVbRingWraps = 0, g_gsrlVbRingBytes = 0, g_gsrlVbRingMvpSkips = 0;   /* read by the runtime */
int g_gsrlVbRingOn = 0;

#if defined(GRAPHICS_API_OPENGL_33)
static void gsrlVbRingInit(int bufferElements)
{
    if (g_vbr.tried) return;
    g_vbr.tried = 1;
    const char *env = getenv("PS2X_VBRING");
    if (env && env[0] == '0') { TRACELOG(GSRL_LOG_INFO, "gsrl: [vbring] disabled by PS2X_VBRING=0"); return; }
    if (!gsrl.ExtSupported.vao || !glMapBufferRange || !glFenceSync || !glClientWaitSync || !glDeleteSync
#if !defined(__APPLE__)
        || !glBufferStorage
#endif
       )
    {
        TRACELOG(GSRL_LOG_INFO, "gsrl: [vbring] not available (vao=%d bufferStorage=%d) - SubData path", gsrl.ExtSupported.vao, glBufferStorage != NULL);
        return;
    }
    int ringVerts = GSRL_VBRING_VERTS;
    if (env && env[0] != '0' && atoi(env) > 1) ringVerts = atoi(env);
    ringVerts = (ringVerts + 3) & ~3;
    const int maxBatchVerts = bufferElements*4;
    if (ringVerts < maxBatchVerts*GSRL_VBRING_SEGS) ringVerts = maxBatchVerts*GSRL_VBRING_SEGS;
    ringVerts = (ringVerts/GSRL_VBRING_SEGS + 3) & ~3;   /* segment size, 4-aligned */
    g_vbr.segVerts = ringVerts;
    g_vbr.ringVerts = ringVerts*GSRL_VBRING_SEGS;

    g_vbr.persistent = (glBufferStorage != NULL);
    const unsigned int flags = GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT;
    const size_t bytes[4] = { (size_t)g_vbr.ringVerts*3*sizeof(float), (size_t)g_vbr.ringVerts*2*sizeof(float),
                              (size_t)g_vbr.ringVerts*3*sizeof(float), (size_t)g_vbr.ringVerts*4 };
    const int locs[4] = { gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_POSITION], gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_TEXCOORD01],
                          gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL], gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_COLOR] };
    while (glGetError() != GL_NO_ERROR) { }
    glGenVertexArrays(1, &g_vbr.vao);
    glBindVertexArray(g_vbr.vao);
    int ok = 1;
    for (int k = 0; k < 4; k++)
    {
        glGenBuffers(1, &g_vbr.vbo[k]);
        glBindBuffer(GL_ARRAY_BUFFER, g_vbr.vbo[k]);
        if (g_vbr.persistent)
        {
            glBufferStorage(GL_ARRAY_BUFFER, (GLsizeiptr)bytes[k], NULL, flags);
            g_vbr.map[k] = (unsigned char *)glMapBufferRange(GL_ARRAY_BUFFER, 0, (GLsizeiptr)bytes[k], flags);
            if (!g_vbr.map[k] || glGetError() != GL_NO_ERROR) { ok = 0; break; }
        }
        else
        {
            glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)bytes[k], NULL, GL_STREAM_DRAW);
            if (glGetError() != GL_NO_ERROR) { ok = 0; break; }
        }
        glEnableVertexAttribArray(locs[k]);
        if (k == 3) glVertexAttribPointer(locs[k], 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        else glVertexAttribPointer(locs[k], (k == 1)? 2 : 3, GL_FLOAT, 0, 0, 0);
    }
    if (ok)
    {
        /* one quad index pattern over the whole ring: quads at ring vertex 4q use indices 6q.. */
        const size_t quads = (size_t)g_vbr.ringVerts/4;
        unsigned int *idx = (unsigned int *)GSRL_MALLOC(quads*6*sizeof(unsigned int));
        for (size_t q = 0; q < quads; q++)
        {
            const unsigned int b = (unsigned int)(q*4);
            idx[q*6 + 0] = b; idx[q*6 + 1] = b + 1; idx[q*6 + 2] = b + 2;
            idx[q*6 + 3] = b; idx[q*6 + 4] = b + 2; idx[q*6 + 5] = b + 3;
        }
        glGenBuffers(1, &g_vbr.ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_vbr.ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)(quads*6*sizeof(unsigned int)), idx, GL_STATIC_DRAW);
        GSRL_FREE(idx);
        if (glGetError() != GL_NO_ERROR) ok = 0;
    }
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    if (!ok)
    {
        TRACELOG(GSRL_LOG_WARNING, "gsrl: [vbring] setup failed - SubData path");
        return;
    }
    g_vbr.cursor = 0; g_vbr.curSeg = 0; g_vbr.lastFencedSeg = -1;
    g_vbr.on = 1; g_gsrlVbRingOn = 1;
    TRACELOG(GSRL_LOG_INFO, "gsrl: [vbring] %s vertex ring on: %d vertices (%d segments of %d), %.1f MB",
             g_vbr.persistent ? "persistent" : "mapped", g_vbr.ringVerts, GSRL_VBRING_SEGS, g_vbr.segVerts,
             (bytes[0] + bytes[1] + bytes[2] + bytes[3])/1048576.0);
}

/* fence every segment written since the last fence, then wait for the fence of each segment we are about to reuse */
static void gsrlVbRingFenceAndWait(int segStart, int segEnd)
{
    if (segStart != g_vbr.curSeg)
    {
        /* all draws that read segments (lastFencedSeg, curSeg] were issued before this call */
        int s = (g_vbr.lastFencedSeg + 1) % GSRL_VBRING_SEGS;
        for (int guard = 0; guard < GSRL_VBRING_SEGS; guard++)
        {
            if (g_vbr.fence[s]) glDeleteSync((GLsync)g_vbr.fence[s]);
            g_vbr.fence[s] = (void *)glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
            if (s == g_vbr.curSeg) break;
            s = (s + 1) % GSRL_VBRING_SEGS;
        }
        g_vbr.lastFencedSeg = g_vbr.curSeg;
    }
    for (int s = segStart; s <= segEnd; s++)
    {
        if (!g_vbr.fence[s]) continue;
        const unsigned int r = glClientWaitSync((GLsync)g_vbr.fence[s], GL_SYNC_FLUSH_COMMANDS_BIT, 1000000000ull);
        if (r != GL_ALREADY_SIGNALED) g_gsrlVbRingWaits++;
        glDeleteSync((GLsync)g_vbr.fence[s]);
        g_vbr.fence[s] = NULL;
    }
    g_vbr.curSeg = segEnd;
}

/* copy the batch's CPU arrays into the ring; returns the ring base vertex of this batch */
static int gsrlVbRingUpload(gsrlRenderBatch *batch)
{
    const int n = gsrl.State.vertexCounter;
    const int nAligned = (n + 3) & ~3;
    if (g_vbr.cursor + nAligned > g_vbr.ringVerts) { g_vbr.cursor = 0; g_gsrlVbRingWraps++; }
    const int base = g_vbr.cursor;
    gsrlVbRingFenceAndWait(base/g_vbr.segVerts, (base + nAligned - 1)/g_vbr.segVerts);
    const gsrlVertexBuffer *vb = &batch->vertexBuffer[batch->currentBuffer];
    const size_t offsets[4] = { (size_t)base*3*sizeof(float), (size_t)base*2*sizeof(float),
                                (size_t)base*3*sizeof(float), (size_t)base*4 };
    const size_t lengths[4] = { (size_t)n*3*sizeof(float), (size_t)n*2*sizeof(float),
                                (size_t)n*3*sizeof(float), (size_t)n*4 };
    const void *sources[4] = { vb->vertices, vb->texcoords, vb->normals, vb->colors };
    for (int k = 0; k < 4; k++)
    {
        if (g_vbr.persistent) memcpy(g_vbr.map[k] + offsets[k], sources[k], lengths[k]);
        else
        {
            glBindBuffer(GL_ARRAY_BUFFER, g_vbr.vbo[k]);
            void *dst = glMapBufferRange(GL_ARRAY_BUFFER, (GLintptr)offsets[k], (GLsizeiptr)lengths[k],
                                         GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT | GL_MAP_UNSYNCHRONIZED_BIT);
            if (!dst) return -1;
            memcpy(dst, sources[k], lengths[k]);
            glUnmapBuffer(GL_ARRAY_BUFFER);
        }
    }
    g_gsrlVbRingBytes += (unsigned long long)n*36;
    g_vbr.cursor = base + nAligned;
    return base;
}

/* returns 1 when the MVP for this program must be (re)sent */
static int gsrlVbRingMvpDirty(unsigned int prog, const float *m)
{
    if (gsrlVbRingNoCache() & 1) return 1;
    for (int i = 0; i < g_vbr.mvpN; i++)
    {
        if (g_vbr.mvpProg[i] != prog) continue;
        if (memcmp(g_vbr.mvp[i], m, 16*sizeof(float)) == 0) { g_gsrlVbRingMvpSkips++; return 0; }
        memcpy(g_vbr.mvp[i], m, 16*sizeof(float));
        return 1;
    }
    if (g_vbr.mvpN < 16) { g_vbr.mvpProg[g_vbr.mvpN] = prog; memcpy(g_vbr.mvp[g_vbr.mvpN], m, 16*sizeof(float)); g_vbr.mvpN++; }
    return 1;
}
static int gsrlVbRingConstDirty(unsigned int prog)
{
    if (gsrlVbRingNoCache() & 2) return 1;
    for (int i = 0; i < g_vbr.constN; i++) if (g_vbr.constProg[i] == prog) return 0;
    if (g_vbr.constN < 16) g_vbr.constProg[g_vbr.constN++] = prog;
    return 1;
}
/* a (re)linked or deleted program has fresh uniforms: drop it from both caches (gsrlLoadShaderProgram / gsrlUnloadShaderProgram call this) */
void ps2xgsrlVbRingForget(unsigned int prog)
{
    for (int i = 0; i < g_vbr.mvpN; i++) if (g_vbr.mvpProg[i] == prog) g_vbr.mvpProg[i] = 0;
    for (int i = 0; i < g_vbr.constN; i++) if (g_vbr.constProg[i] == prog) g_vbr.constProg[i] = 0;
}
#endif
#include <time.h>
#if defined(_WIN32)
static inline double ps2xgsrlNowNs(void) { struct timespec ts; timespec_get(&ts, TIME_UTC); return (double)ts.tv_sec * 1e9 + (double)ts.tv_nsec; }   /* UCRT: no clock_gettime */
#else
static inline double ps2xgsrlNowNs(void) { struct timespec ts; clock_gettime(CLOCK_MONOTONIC, &ts); return (double)ts.tv_sec * 1e9 + (double)ts.tv_nsec; }
#endif
static void gsrlDrawRenderBatchInner(gsrlRenderBatch *batch);
void gsrlDrawRenderBatch(gsrlRenderBatch *batch)
{
    if (gsrl.State.vertexCounter > 0)
    {
        g_gsrlBatchFlushes++;
        const double t0 = ps2xgsrlNowNs();
        gsrlDrawRenderBatchInner(batch);
        g_gsrlFlushNs += ps2xgsrlNowNs() - t0;
        return;
    }
    gsrlDrawRenderBatchInner(batch);
}
static void gsrlDrawRenderBatchInner(gsrlRenderBatch *batch)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // Update batch vertex buffers
    //------------------------------------------------------------------------------------------------------------
    // NOTE: If there is not vertex data, buffers doesn't need to be updated (vertexCount > 0)
    // TODO: If no data changed on the CPU arrays --> No need to re-update GPU arrays (use a change detector flag?)
    int vbrBase = -1;   /* [ps2x vbring] ring base vertex of this batch, -1 = SubData path */
#if defined(GRAPHICS_API_OPENGL_33)
    if ((gsrl.State.vertexCounter > 0) && g_vbr.on) vbrBase = gsrlVbRingUpload(batch);
#endif
    if ((gsrl.State.vertexCounter > 0) && (vbrBase < 0))
    {
        // Activate elements VAO
        if (gsrl.ExtSupported.vao) glBindVertexArray(batch->vertexBuffer[batch->currentBuffer].vaoId);

        // Vertex positions buffer
        glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[0]);
#if defined(__APPLE__)
        glBufferData(GL_ARRAY_BUFFER, gsrl.State.vertexCounter*3*sizeof(float), batch->vertexBuffer[batch->currentBuffer].vertices, GL_STREAM_DRAW);
#else
        glBufferSubData(GL_ARRAY_BUFFER, 0, gsrl.State.vertexCounter*3*sizeof(float), batch->vertexBuffer[batch->currentBuffer].vertices);
#endif
        //glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*4*batch->vertexBuffer[batch->currentBuffer].elementCount, batch->vertexBuffer[batch->currentBuffer].vertices, GL_DYNAMIC_DRAW);  // Update all buffer

        // Texture coordinates buffer
        glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[1]);
#if defined(__APPLE__)
        glBufferData(GL_ARRAY_BUFFER, gsrl.State.vertexCounter*2*sizeof(float), batch->vertexBuffer[batch->currentBuffer].texcoords, GL_STREAM_DRAW);
#else
        glBufferSubData(GL_ARRAY_BUFFER, 0, gsrl.State.vertexCounter*2*sizeof(float), batch->vertexBuffer[batch->currentBuffer].texcoords);
#endif
        //glBufferData(GL_ARRAY_BUFFER, sizeof(float)*2*4*batch->vertexBuffer[batch->currentBuffer].elementCount, batch->vertexBuffer[batch->currentBuffer].texcoords, GL_DYNAMIC_DRAW); // Update all buffer

        // Normals buffer
        glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[2]);
#if defined(__APPLE__)
        glBufferData(GL_ARRAY_BUFFER, gsrl.State.vertexCounter*3*sizeof(float), batch->vertexBuffer[batch->currentBuffer].normals, GL_STREAM_DRAW);
#else
        glBufferSubData(GL_ARRAY_BUFFER, 0, gsrl.State.vertexCounter*3*sizeof(float), batch->vertexBuffer[batch->currentBuffer].normals);
#endif
        //glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*4*batch->vertexBuffer[batch->currentBuffer].elementCount, batch->vertexBuffer[batch->currentBuffer].normals, GL_DYNAMIC_DRAW); // Update all buffer

        // Colors buffer
        glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[3]);
#if defined(__APPLE__)
        glBufferData(GL_ARRAY_BUFFER, gsrl.State.vertexCounter*4*sizeof(unsigned char), batch->vertexBuffer[batch->currentBuffer].colors, GL_STREAM_DRAW);
#else
        glBufferSubData(GL_ARRAY_BUFFER, 0, gsrl.State.vertexCounter*4*sizeof(unsigned char), batch->vertexBuffer[batch->currentBuffer].colors);
#endif
        //glBufferData(GL_ARRAY_BUFFER, sizeof(float)*4*4*batch->vertexBuffer[batch->currentBuffer].elementCount, batch->vertexBuffer[batch->currentBuffer].colors, GL_DYNAMIC_DRAW);    // Update all buffer

        // NOTE: glMapBuffer() causes sync issue
        // If GPU is working with this buffer, glMapBuffer() will wait(stall) until GPU to finish its job
        // To avoid waiting (idle), you can call first glBufferData() with NULL pointer before glMapBuffer()
        // If you do that, the previous data in PBO will be discarded and glMapBuffer() returns a new
        // allocated pointer immediately even if GPU is still working with the previous data

        // Another option: map the buffer object into client's memory
        // Probably this code could be moved somewhere else...
        // batch->vertexBuffer[batch->currentBuffer].vertices = (float *)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
        // if (batch->vertexBuffer[batch->currentBuffer].vertices)
        // {
            // Update vertex data
        // }
        // glUnmapBuffer(GL_ARRAY_BUFFER);

        // Unbind the current VAO
        if (gsrl.ExtSupported.vao) glBindVertexArray(0);
    }
    //------------------------------------------------------------------------------------------------------------

    // Draw batch vertex buffers (considering VR stereo if required)
    //------------------------------------------------------------------------------------------------------------
    Matrix matProjection = gsrl.State.projection;
    Matrix matModelView = gsrl.State.modelview;

    int eyeCount = 1;
    if (gsrl.State.stereoRender) eyeCount = 2;

    for (int eye = 0; eye < eyeCount; eye++)
    {
        if (eyeCount == 2)
        {
            // Setup current eye viewport (half screen width)
            gsrlViewport(eye*gsrl.State.framebufferWidth/2, 0, gsrl.State.framebufferWidth/2, gsrl.State.framebufferHeight);

            // Set current eye view offset to modelview matrix
            gsrlSetMatrixModelview(gsrlMatrixMultiply(matModelView, gsrl.State.viewOffsetStereo[eye]));
            // Set current eye projection matrix
            gsrlSetMatrixProjection(gsrl.State.projectionStereo[eye]);
        }

        // Draw buffers
        if (gsrl.State.vertexCounter > 0)
        {
            // Set current shader and upload current MVP matrix
            glUseProgram(gsrl.State.currentShaderId);

            // Create modelview-projection matrix and upload to shader
            Matrix matMVP = gsrlMatrixMultiply(gsrl.State.modelview, gsrl.State.projection);
#if defined(GRAPHICS_API_OPENGL_33)
            /* [ps2x vbring] a program keeps its uniforms: re-send the MVP only when it changed for this program */
            if (!g_vbr.on || gsrlVbRingMvpDirty(gsrl.State.currentShaderId, gsrlMatrixToFloat(matMVP)))
#endif
            glUniformMatrix4fv(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_MVP], 1, false, gsrlMatrixToFloat(matMVP));

            if (gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_PROJECTION] != -1)
            {
                glUniformMatrix4fv(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_PROJECTION], 1, false, gsrlMatrixToFloat(gsrl.State.projection));
            }

            // WARNING: For the following setup of the view, model, and normal matrices, it is expected that
            // transformations and rendering occur between gsrlPushMatrix() and gsrlPopMatrix()

            if (gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_VIEW] != -1)
            {
                glUniformMatrix4fv(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_VIEW], 1, false, gsrlMatrixToFloat(gsrl.State.modelview));
            }

            if (gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_MODEL] != -1)
            {
                glUniformMatrix4fv(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_MODEL], 1, false, gsrlMatrixToFloat(gsrl.State.transform));
            }

            if (gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_NORMAL] != -1)
            {
                glUniformMatrix4fv(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MATRIX_NORMAL], 1, false, gsrlMatrixToFloat(gsrlMatrixTranspose(gsrlMatrixInvert(gsrl.State.transform))));
            }

            if (vbrBase >= 0) glBindVertexArray(g_vbr.vao);   /* [ps2x vbring] */
            else if (gsrl.ExtSupported.vao) glBindVertexArray(batch->vertexBuffer[batch->currentBuffer].vaoId);
            else
            {
                // Bind vertex attrib: position (shader-location = 0)
                glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[0]);
                glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_POSITION], 3, GL_FLOAT, 0, 0, 0);
                glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_POSITION]);

                // Bind vertex attrib: texcoord (shader-location = 1)
                glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[1]);
                glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_TEXCOORD01], 2, GL_FLOAT, 0, 0, 0);
                glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_TEXCOORD01]);

                // Bind vertex attrib: normal (shader-location = 2)
                glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[2]);
                glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL], 3, GL_FLOAT, 0, 0, 0);
                glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_NORMAL]);

                // Bind vertex attrib: color (shader-location = 3)
                glBindBuffer(GL_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[3]);
                glVertexAttribPointer(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_COLOR], 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
                glEnableVertexAttribArray(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_VERTEX_COLOR]);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, batch->vertexBuffer[batch->currentBuffer].vboId[4]);
            }

            // Setup some default shader values
#if defined(GRAPHICS_API_OPENGL_33)
            if (!g_vbr.on || gsrlVbRingConstDirty(gsrl.State.currentShaderId))   /* [ps2x vbring] constants: once per program */
#endif
            {
            glUniform4f(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_COLOR_DIFFUSE], 1.0f, 1.0f, 1.0f, 1.0f);
            glUniform1i(gsrl.State.currentShaderLocs[GSRL_SHADER_LOC_MAP_DIFFUSE], 0);  // Active default sampler2D: texture0
            }

            // Activate additional sampler textures
            // Those additional textures will be common for all draw calls of the batch
            for (int i = 0; i < GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS; i++)
            {
                if (gsrl.State.activeTextureId[i] > 0)
                {
                    glActiveTexture(GL_TEXTURE0 + 1 + i);
                    glBindTexture(GL_TEXTURE_2D, gsrl.State.activeTextureId[i]);
                }
            }

            // Activate default sampler2D texture0 (one texture is always active for default batch shader)
            // NOTE: Batch system accumulates calls by texture0 changes, additional textures are enabled for all the draw calls
            glActiveTexture(GL_TEXTURE0);

            for (int i = 0, vertexOffset = (vbrBase > 0)? vbrBase : 0; i < batch->drawCounter; i++)   /* [ps2x vbring] draws index the ring */
            {
                // Bind current draw call texture, activated as GL_TEXTURE0 and Bound to sampler2D texture0 by default
                glBindTexture(GL_TEXTURE_2D, batch->draws[i].textureId);

                g_gsrlDrawCalls++;   /* [ps2x glcalls] one driver draw per batch entry */
                if ((batch->draws[i].mode == GSRL_LINES) || (batch->draws[i].mode == GSRL_TRIANGLES)) glDrawArrays(batch->draws[i].mode, vertexOffset, batch->draws[i].vertexCount);
                else
                {
    #if defined(GRAPHICS_API_OPENGL_33)
                    // We need to define the number of indices to be processed: elementCount*6
                    // NOTE: The final parameter tells the GPU the offset in bytes from the
                    // start of the index buffer to the location of the first index to process
                    glDrawElements(GL_TRIANGLES, batch->draws[i].vertexCount/4*6, GL_UNSIGNED_INT, (GLvoid *)(vertexOffset/4*6*sizeof(GLuint)));
    #endif
    #if defined(GRAPHICS_API_OPENGL_ES2)
                    glDrawElements(GL_TRIANGLES, batch->draws[i].vertexCount/4*6, GL_UNSIGNED_SHORT, (GLvoid *)(vertexOffset/4*6*sizeof(GLushort)));
    #endif
                }

                vertexOffset += (batch->draws[i].vertexCount + batch->draws[i].vertexAlignment);
            }

            if (!gsrl.ExtSupported.vao)
            {
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            }

            /* [ps2x lean flush] per-flush unbinds (texture, VAO, program) are pure driver overhead: every flush

               re-binds all three at its start. Define gsrl_PS2X_UNBIND to restore them. */
#if defined(gsrl_PS2X_UNBIND)

            glBindTexture(GL_TEXTURE_2D, 0);
#endif
        }
#if defined(gsrl_PS2X_UNBIND)

        if (gsrl.ExtSupported.vao) glBindVertexArray(0);

        glUseProgram(0);
#endif
    }

    // Restore viewport to default measures
    if (eyeCount == 2) gsrlViewport(0, 0, gsrl.State.framebufferWidth, gsrl.State.framebufferHeight);
    //------------------------------------------------------------------------------------------------------------

    // Reset batch buffers
    //------------------------------------------------------------------------------------------------------------
    // Reset vertex counter for next frame
    gsrl.State.vertexCounter = 0;

    // Reset depth for next draw
    batch->currentDepth = -1.0f;

    // Restore projection/modelview matrices
    gsrl.State.projection = matProjection;
    gsrl.State.modelview = matModelView;

    // Reset gsrl.currentBatch->draws array
    for (int i = 0; i < GSRL_DEFAULT_BATCH_DRAWCALLS; i++)
    {
        batch->draws[i].mode = GSRL_QUADS;
        batch->draws[i].vertexCount = 0;
        batch->draws[i].textureId = gsrl.State.defaultTextureId;
    }

    // Reset active texture units for next batch
    for (int i = 0; i < GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS; i++) gsrl.State.activeTextureId[i] = 0;

    // Reset draws counter to one draw for the batch
    batch->drawCounter = 1;
    //------------------------------------------------------------------------------------------------------------

    // Change to next buffer in the list (in case of multi-buffering)
    batch->currentBuffer++;
    if (batch->currentBuffer >= batch->bufferCount) batch->currentBuffer = 0;
#endif
}

// Set the active render batch for gsrl
void gsrlSetRenderBatchActive(gsrlRenderBatch *batch)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrlDrawRenderBatch(gsrl.currentBatch);

    if (batch != NULL) gsrl.currentBatch = batch;
    else gsrl.currentBatch = &gsrl.defaultBatch;
#endif
}

// Update and draw internal render batch
void gsrlDrawRenderBatchActive(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrlDrawRenderBatch(gsrl.currentBatch);    // NOTE: Stereo rendering is checked inside
#endif
}

// Check internal buffer overflow for a given number of vertex
// and force a gsrlRenderBatch draw call if required
bool gsrlCheckRenderBatchLimit(int vCount)
{
    bool overflow = false;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if ((gsrl.State.vertexCounter + vCount) >=
        (gsrl.currentBatch->vertexBuffer[gsrl.currentBatch->currentBuffer].elementCount*4))
    {
        overflow = true;

        // Store current primitive drawing mode and texture id
        int currentMode = gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode;
        int currentTexture = gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].textureId;

        gsrlDrawRenderBatch(gsrl.currentBatch);    // NOTE: Stereo rendering is checked inside

        // Restore state of last batch so we can continue adding vertices
        gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].mode = currentMode;
        gsrl.currentBatch->draws[gsrl.currentBatch->drawCounter - 1].textureId = currentTexture;
    }
#endif

    return overflow;
}

// Textures data management
//-----------------------------------------------------------------------------------------
// Convert image data to OpenGL texture (returns OpenGL valid Id)
unsigned int gsrlLoadTexture(const void *data, int width, int height, int format, int mipmapCount)
{
    unsigned int id = 0;

    glBindTexture(GL_TEXTURE_2D, 0);    // Free any old binding

    // Check texture format support by OpenGL 1.1 (compressed textures not supported)
#if defined(GRAPHICS_API_OPENGL_11)
    if (format >= GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB)
    {
        TRACELOG(GSRL_LOG_WARNING, "GL: OpenGL 1.1 does not support GPU compressed texture formats");
        return id;
    }
#else
    if ((!gsrl.ExtSupported.texCompDXT) && ((format == GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB) || (format == GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGBA) ||
        (format == GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA) || (format == GSRL_PIXELFORMAT_COMPRESSED_DXT5_RGBA)))
    {
        TRACELOG(GSRL_LOG_WARNING, "GL: DXT compressed texture format not supported");
        return id;
    }
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if ((!gsrl.ExtSupported.texCompETC1) && (format == GSRL_PIXELFORMAT_COMPRESSED_ETC1_RGB))
    {
        TRACELOG(GSRL_LOG_WARNING, "GL: ETC1 compressed texture format not supported");
        return id;
    }

    if ((!gsrl.ExtSupported.texCompETC2) && ((format == GSRL_PIXELFORMAT_COMPRESSED_ETC2_RGB) || (format == GSRL_PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA)))
    {
        TRACELOG(GSRL_LOG_WARNING, "GL: ETC2 compressed texture format not supported");
        return id;
    }

    if ((!gsrl.ExtSupported.texCompPVRT) && ((format == GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGB) || (format == GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGBA)))
    {
        TRACELOG(GSRL_LOG_WARNING, "GL: PVRT compressed texture format not supported");
        return id;
    }

    if ((!gsrl.ExtSupported.texCompASTC) && ((format == GSRL_PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA) || (format == GSRL_PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA)))
    {
        TRACELOG(GSRL_LOG_WARNING, "GL: ASTC compressed texture format not supported");
        return id;
    }
#endif
#endif  // GRAPHICS_API_OPENGL_11

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &id);              // Generate texture id

    glBindTexture(GL_TEXTURE_2D, id);

    int mipWidth = width;
    int mipHeight = height;
    int mipOffset = 0;          // Mipmap data offset, only used for tracelog

    // NOTE: Added pointer math separately from function to avoid UBSAN complaining
    unsigned char *dataPtr = NULL;
    if (data != NULL) dataPtr = (unsigned char *)data;

    // Load the different mipmap levels
    for (int i = 0; i < mipmapCount; i++)
    {
        unsigned int mipSize = gsrlGetPixelDataSize(mipWidth, mipHeight, format);

        unsigned int glInternalFormat, glFormat, glType;
        gsrlGetGlTextureFormats(format, &glInternalFormat, &glFormat, &glType);

        TRACELOGD("TEXTURE: Load mipmap level %i (%i x %i), size: %i, offset: %i", i, mipWidth, mipHeight, mipSize, mipOffset);

        if (glInternalFormat != 0)
        {
            if (format < GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB) glTexImage2D(GL_TEXTURE_2D, i, glInternalFormat, mipWidth, mipHeight, 0, glFormat, glType, dataPtr);
#if !defined(GRAPHICS_API_OPENGL_11)
            else glCompressedTexImage2D(GL_TEXTURE_2D, i, glInternalFormat, mipWidth, mipHeight, 0, mipSize, dataPtr);
#endif

#if defined(GRAPHICS_API_OPENGL_33)
            if (format == GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE)
            {
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
            }
            else if (format == GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA)
            {
#if defined(GRAPHICS_API_OPENGL_21)
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ALPHA };
#elif defined(GRAPHICS_API_OPENGL_33)
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_GREEN };
#endif
                glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
            }
#endif
        }

        mipWidth /= 2;
        mipHeight /= 2;
        mipOffset += mipSize;       // Increment offset position to next mipmap
        if (data != NULL) dataPtr += mipSize;         // Increment data pointer to next mipmap

        // Security check for NPOT textures
        if (mipWidth < 1) mipWidth = 1;
        if (mipHeight < 1) mipHeight = 1;
    }

    // Texture parameters configuration
    // NOTE: glTexParameteri does NOT affect texture uploading, just the way it's used
#if defined(GRAPHICS_API_OPENGL_ES2)
    // NOTE: OpenGL ES 2.0 with no GL_OES_texture_npot support (i.e. WebGL) has limited NPOT support, so CLAMP_TO_EDGE must be used
    if (gsrl.ExtSupported.texNPOT)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);       // Set texture to repeat on x-axis
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);       // Set texture to repeat on y-axis
    }
    else
    {
        // NOTE: If using negative texture coordinates (LoadOBJ()), it does not work!
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);       // Set texture to clamp on x-axis
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);       // Set texture to clamp on y-axis
    }
#else
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);       // Set texture to repeat on x-axis
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);       // Set texture to repeat on y-axis
#endif

    // Magnification and minification filters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  // Alternative: GL_LINEAR
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);  // Alternative: GL_LINEAR

#if defined(GRAPHICS_API_OPENGL_33)
    if (mipmapCount > 1)
    {
        // Activate Trilinear filtering if mipmaps are available
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    }
#endif

    // At this point we have the texture loaded in GPU and texture parameters configured

    // NOTE: If mipmaps were not in data, they are not generated automatically

    // Unbind current texture
    glBindTexture(GL_TEXTURE_2D, 0);

    if (id > 0) TRACELOG(GSRL_LOG_INFO, "TEXTURE: [ID %i] Texture loaded successfully (%ix%i | %s | %i mipmaps)", id, width, height, gsrlGetPixelFormatName(format), mipmapCount);
    else TRACELOG(GSRL_LOG_WARNING, "TEXTURE: Failed to load texture");

    return id;
}

// Load depth texture/renderbuffer (to be attached to fbo)
// WARNING: OpenGL ES 2.0 requires GL_OES_depth_texture and WebGL requires WEBGL_depth_texture extensions
unsigned int gsrlLoadTextureDepth(int width, int height, bool useRenderBuffer)
{
    unsigned int id = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // In case depth textures not supported, we force renderbuffer usage
    if (!gsrl.ExtSupported.texDepth) useRenderBuffer = true;

    // NOTE: We let the implementation to choose the best bit-depth
    // Possible formats: GL_DEPTH_COMPONENT16, GL_DEPTH_COMPONENT24, GL_DEPTH_COMPONENT32 and GL_DEPTH_COMPONENT32F
    unsigned int glInternalFormat = GL_DEPTH_COMPONENT;

#if (defined(GRAPHICS_API_OPENGL_ES2) || defined(GRAPHICS_API_OPENGL_ES3))
    // WARNING: WebGL platform requires unsized internal format definition (GL_DEPTH_COMPONENT)
    // while other platforms using OpenGL ES 2.0 require/support sized internal formats depending on the GPU capabilities
    if (!gsrl.ExtSupported.texDepthWebGL || useRenderBuffer)
    {
        if (gsrl.ExtSupported.maxDepthBits == 32) glInternalFormat = GL_DEPTH_COMPONENT32_OES;
        else if (gsrl.ExtSupported.maxDepthBits == 24) glInternalFormat = GL_DEPTH_COMPONENT24_OES;
        else glInternalFormat = GL_DEPTH_COMPONENT16;
    }
#endif

    if (!useRenderBuffer && gsrl.ExtSupported.texDepth)
    {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, glInternalFormat, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glBindTexture(GL_TEXTURE_2D, 0);

        TRACELOG(GSRL_LOG_INFO, "TEXTURE: Depth texture loaded successfully");
    }
    else
    {
        // Create the renderbuffer that will serve as the depth attachment for the framebuffer
        // NOTE: A renderbuffer is simpler than a texture and could offer better performance on embedded devices
        glGenRenderbuffers(1, &id);
        glBindRenderbuffer(GL_RENDERBUFFER, id);
        glRenderbufferStorage(GL_RENDERBUFFER, glInternalFormat, width, height);

        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        TRACELOG(GSRL_LOG_INFO, "TEXTURE: [ID %i] Depth renderbuffer loaded successfully (%i bits)", id, (gsrl.ExtSupported.maxDepthBits >= 24)? gsrl.ExtSupported.maxDepthBits : 16);
    }
#endif

    return id;
}

// Load texture cubemap
// NOTE: Cubemap data is expected to be 6 images in a single data array (one after the other),
// expected the following convention: +X, -X, +Y, -Y, +Z, -Z
unsigned int gsrlLoadTextureCubemap(const void *data, int size, int format, int mipmapCount)
{
    unsigned int id = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    int mipSize = size;

    // NOTE: Added pointer math separately from function to avoid UBSAN complaining
    unsigned char *dataPtr = NULL;
    if (data != NULL) dataPtr = (unsigned char *)data;

    unsigned int dataSize = gsrlGetPixelDataSize(size, size, format);

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);

    unsigned int glInternalFormat, glFormat, glType;
    gsrlGetGlTextureFormats(format, &glInternalFormat, &glFormat, &glType);

    if (glInternalFormat != 0)
    {
        // Load cubemap faces/mipmaps
        for (int i = 0; i < 6*mipmapCount; i++)
        {
            int mipmapLevel = i/6;
            int face = i%6;

            if (data == NULL)
            {
                if (format < GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB)
                {
                    if ((format == GSRL_PIXELFORMAT_UNCOMPRESSED_R32) || 
                        (format == GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32) ||
                        (format == GSRL_PIXELFORMAT_UNCOMPRESSED_R16) || 
                        (format == GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16)) TRACELOG(GSRL_LOG_WARNING, "TEXTURES: Cubemap requested format not supported");
                    else glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, mipmapLevel, glInternalFormat, mipSize, mipSize, 0, glFormat, glType, NULL);
                }
                else TRACELOG(GSRL_LOG_WARNING, "TEXTURES: Empty cubemap creation does not support compressed format");
            }
            else
            {
                if (format < GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB) glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, mipmapLevel, glInternalFormat, mipSize, mipSize, 0, glFormat, glType, (unsigned char *)dataPtr + face*dataSize);
                else glCompressedTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, mipmapLevel, glInternalFormat, mipSize, mipSize, 0, dataSize, (unsigned char *)dataPtr + face*dataSize);
            }

#if defined(GRAPHICS_API_OPENGL_33)
            if (format == GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE)
            {
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
                glTexParameteriv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
            }
            else if (format == GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA)
            {
#if defined(GRAPHICS_API_OPENGL_21)
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ALPHA };
#elif defined(GRAPHICS_API_OPENGL_33)
                GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_GREEN };
#endif
                glTexParameteriv(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
            }
#endif
            if (face == 5)
            {
                mipSize /= 2;
                if (data != NULL) dataPtr += dataSize*6; // Increment data pointer to next mipmap

                // Security check for NPOT textures
                if (mipSize < 1) mipSize = 1;

                dataSize = gsrlGetPixelDataSize(mipSize, mipSize, format);
            }
        }
    }

    // Set cubemap texture sampling parameters
    if (mipmapCount > 1) glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    else glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
#if defined(GRAPHICS_API_OPENGL_33)
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);  // Flag not supported on OpenGL ES 2.0
#endif

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
#endif

    if (id > 0) TRACELOG(GSRL_LOG_INFO, "TEXTURE: [ID %i] Cubemap texture loaded successfully (%ix%i)", id, size, size);
    else TRACELOG(GSRL_LOG_WARNING, "TEXTURE: Failed to load cubemap texture");

    return id;
}

// Update already loaded texture in GPU with new data
// NOTE: We don't know safely if internal texture format is the expected one...
void gsrlUpdateTexture(unsigned int id, int offsetX, int offsetY, int width, int height, int format, const void *data)
{
    glBindTexture(GL_TEXTURE_2D, id);

    unsigned int glInternalFormat, glFormat, glType;
    gsrlGetGlTextureFormats(format, &glInternalFormat, &glFormat, &glType);

    if ((glInternalFormat != 0) && (format < GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB))
    {
        glTexSubImage2D(GL_TEXTURE_2D, 0, offsetX, offsetY, width, height, glFormat, glType, data);
    }
    else TRACELOG(GSRL_LOG_WARNING, "TEXTURE: [ID %i] Failed to update for current texture format (%i)", id, format);
}

// Get OpenGL internal formats and data type from raylib PixelFormat
void gsrlGetGlTextureFormats(int format, unsigned int *glInternalFormat, unsigned int *glFormat, unsigned int *glType)
{
    *glInternalFormat = 0;
    *glFormat = 0;
    *glType = 0;

    switch (format)
    {
    #if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_21) || defined(GRAPHICS_API_OPENGL_ES2)
        // NOTE: on OpenGL ES 2.0 (WebGL), internalFormat must match format and options allowed are: GL_LUMINANCE, GL_RGB, GL_RGBA
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE: *glInternalFormat = GL_LUMINANCE; *glFormat = GL_LUMINANCE; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA: *glInternalFormat = GL_LUMINANCE_ALPHA; *glFormat = GL_LUMINANCE_ALPHA; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G6B5: *glInternalFormat = GL_RGB; *glFormat = GL_RGB; *glType = GL_UNSIGNED_SHORT_5_6_5; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8: *glInternalFormat = GL_RGB; *glFormat = GL_RGB; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G5B5A1: *glInternalFormat = GL_RGBA; *glFormat = GL_RGBA; *glType = GL_UNSIGNED_SHORT_5_5_5_1; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R4G4B4A4: *glInternalFormat = GL_RGBA; *glFormat = GL_RGBA; *glType = GL_UNSIGNED_SHORT_4_4_4_4; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8: *glInternalFormat = GL_RGBA; *glFormat = GL_RGBA; *glType = GL_UNSIGNED_BYTE; break;
        #if !defined(GRAPHICS_API_OPENGL_11)
        #if defined(GRAPHICS_API_OPENGL_ES3)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_R32F_EXT; *glFormat = GL_RED_EXT; *glType = GL_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_RGB32F_EXT; *glFormat = GL_RGB; *glType = GL_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_RGBA32F_EXT; *glFormat = GL_RGBA; *glType = GL_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_R16F_EXT; *glFormat = GL_RED_EXT; *glType = GL_HALF_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGB16F_EXT; *glFormat = GL_RGB; *glType = GL_HALF_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGBA16F_EXT; *glFormat = GL_RGBA; *glType = GL_HALF_FLOAT; break;
        #else
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_LUMINANCE; *glFormat = GL_LUMINANCE; *glType = GL_FLOAT; break;            // NOTE: Requires extension OES_texture_float
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_RGB; *glFormat = GL_RGB; *glType = GL_FLOAT; break;                  // NOTE: Requires extension OES_texture_float
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_RGBA; *glFormat = GL_RGBA; *glType = GL_FLOAT; break;             // NOTE: Requires extension OES_texture_float
        #if defined(GRAPHICS_API_OPENGL_21)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_LUMINANCE; *glFormat = GL_LUMINANCE; *glType = GL_HALF_FLOAT_ARB; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGB; *glFormat = GL_RGB; *glType = GL_HALF_FLOAT_ARB; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGBA; *glFormat = GL_RGBA; *glType = GL_HALF_FLOAT_ARB; break;
        #else // defined(GRAPHICS_API_OPENGL_ES2)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_LUMINANCE; *glFormat = GL_LUMINANCE; *glType = GL_HALF_FLOAT_OES; break;   // NOTE: Requires extension OES_texture_half_float
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGB; *glFormat = GL_RGB; *glType = GL_HALF_FLOAT_OES; break;         // NOTE: Requires extension OES_texture_half_float
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGBA; *glFormat = GL_RGBA; *glType = GL_HALF_FLOAT_OES; break;    // NOTE: Requires extension OES_texture_half_float
        #endif
        #endif
        #endif
    #elif defined(GRAPHICS_API_OPENGL_33)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE: *glInternalFormat = GL_R8; *glFormat = GL_RED; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA: *glInternalFormat = GL_RG8; *glFormat = GL_RG; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G6B5: *glInternalFormat = GL_RGB565; *glFormat = GL_RGB; *glType = GL_UNSIGNED_SHORT_5_6_5; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8: *glInternalFormat = GL_RGB8; *glFormat = GL_RGB; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G5B5A1: *glInternalFormat = GL_RGB5_A1; *glFormat = GL_RGBA; *glType = GL_UNSIGNED_SHORT_5_5_5_1; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R4G4B4A4: *glInternalFormat = GL_RGBA4; *glFormat = GL_RGBA; *glType = GL_UNSIGNED_SHORT_4_4_4_4; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8: *glInternalFormat = GL_RGBA8; *glFormat = GL_RGBA; *glType = GL_UNSIGNED_BYTE; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_R32F; *glFormat = GL_RED; *glType = GL_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_RGB32F; *glFormat = GL_RGB; *glType = GL_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32: if (gsrl.ExtSupported.texFloat32) *glInternalFormat = GL_RGBA32F; *glFormat = GL_RGBA; *glType = GL_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_R16F; *glFormat = GL_RED; *glType = GL_HALF_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGB16F; *glFormat = GL_RGB; *glType = GL_HALF_FLOAT; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: if (gsrl.ExtSupported.texFloat16) *glInternalFormat = GL_RGBA16F; *glFormat = GL_RGBA; *glType = GL_HALF_FLOAT; break;
    #endif
    #if !defined(GRAPHICS_API_OPENGL_11)
        case GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB: if (gsrl.ExtSupported.texCompDXT) *glInternalFormat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT; break;
        case GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGBA: if (gsrl.ExtSupported.texCompDXT) *glInternalFormat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT; break;
        case GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA: if (gsrl.ExtSupported.texCompDXT) *glInternalFormat = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT; break;
        case GSRL_PIXELFORMAT_COMPRESSED_DXT5_RGBA: if (gsrl.ExtSupported.texCompDXT) *glInternalFormat = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT; break;
        case GSRL_PIXELFORMAT_COMPRESSED_ETC1_RGB: if (gsrl.ExtSupported.texCompETC1) *glInternalFormat = GL_ETC1_RGB8_OES; break;                      // NOTE: Requires OpenGL ES 2.0 or OpenGL 4.3
        case GSRL_PIXELFORMAT_COMPRESSED_ETC2_RGB: if (gsrl.ExtSupported.texCompETC2) *glInternalFormat = GL_COMPRESSED_RGB8_ETC2; break;               // NOTE: Requires OpenGL ES 3.0 or OpenGL 4.3
        case GSRL_PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA: if (gsrl.ExtSupported.texCompETC2) *glInternalFormat = GL_COMPRESSED_RGBA8_ETC2_EAC; break;     // NOTE: Requires OpenGL ES 3.0 or OpenGL 4.3
        case GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGB: if (gsrl.ExtSupported.texCompPVRT) *glInternalFormat = GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG; break;    // NOTE: Requires PowerVR GPU
        case GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGBA: if (gsrl.ExtSupported.texCompPVRT) *glInternalFormat = GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG; break;  // NOTE: Requires PowerVR GPU
        case GSRL_PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA: if (gsrl.ExtSupported.texCompASTC) *glInternalFormat = GL_COMPRESSED_RGBA_ASTC_4x4_KHR; break;  // NOTE: Requires OpenGL ES 3.1 or OpenGL 4.3
        case GSRL_PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA: if (gsrl.ExtSupported.texCompASTC) *glInternalFormat = GL_COMPRESSED_RGBA_ASTC_8x8_KHR; break;  // NOTE: Requires OpenGL ES 3.1 or OpenGL 4.3
    #endif
        default: TRACELOG(GSRL_LOG_WARNING, "TEXTURE: Current format not supported (%i)", format); break;
    }
}

// Unload texture from GPU memory
void gsrlUnloadTexture(unsigned int id)
{
    glDeleteTextures(1, &id);
}

// Generate mipmap data for selected texture
// NOTE: Only supports GPU mipmap generation
void gsrlGenTextureMipmaps(unsigned int id, int width, int height, int format, int *mipmaps)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindTexture(GL_TEXTURE_2D, id);

    // Check if texture is power-of-two (POT)
    bool texIsPOT = false;

    if (((width > 0) && ((width & (width - 1)) == 0)) &&
        ((height > 0) && ((height & (height - 1)) == 0))) texIsPOT = true;

    if ((texIsPOT) || (gsrl.ExtSupported.texNPOT))
    {
        //glHint(GL_GENERATE_MIPMAP_HINT, GL_DONT_CARE);   // Hint for mipmaps generation algorithm: GL_FASTEST, GL_NICEST, GL_DONT_CARE
        glGenerateMipmap(GL_TEXTURE_2D);    // Generate mipmaps automatically

        #define MIN(a,b) (((a)<(b))? (a):(b))
        #define MAX(a,b) (((a)>(b))? (a):(b))

        *mipmaps = 1 + (int)floor(log(MAX(width, height))/log(2));
        TRACELOG(GSRL_LOG_INFO, "TEXTURE: [ID %i] Mipmaps generated automatically, total: %i", id, *mipmaps);
    }
    else TRACELOG(GSRL_LOG_WARNING, "TEXTURE: [ID %i] Failed to generate mipmaps", id);

    glBindTexture(GL_TEXTURE_2D, 0);
#else
    TRACELOG(GSRL_LOG_WARNING, "TEXTURE: [ID %i] GPU mipmap generation not supported", id);
#endif
}

// Read texture pixel data
void *gsrlReadTexturePixels(unsigned int id, int width, int height, int format)
{
    void *pixels = NULL;

#if defined(GRAPHICS_API_OPENGL_11) || defined(GRAPHICS_API_OPENGL_33)
    glBindTexture(GL_TEXTURE_2D, id);

    // NOTE: Using texture id, we can retrieve some texture info (but not on OpenGL ES 2.0)
    // Possible texture info: GL_TEXTURE_RED_SIZE, GL_TEXTURE_GREEN_SIZE, GL_TEXTURE_BLUE_SIZE, GL_TEXTURE_ALPHA_SIZE
    //int width, height, format;
    //glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
    //glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
    //glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &format);

    // NOTE: Each row written to or read from by OpenGL pixel operations like glGetTexImage are aligned to a 4 byte boundary by default, which may add some padding
    // Use glPixelStorei to modify padding with the GL_[UN]PACK_ALIGNMENT setting
    // GL_PACK_ALIGNMENT affects operations that read from OpenGL memory (glReadPixels, glGetTexImage, etc.)
    // GL_UNPACK_ALIGNMENT affects operations that write to OpenGL memory (glTexImage, etc.)
    glPixelStorei(GL_PACK_ALIGNMENT, 1);

    unsigned int glInternalFormat, glFormat, glType;
    gsrlGetGlTextureFormats(format, &glInternalFormat, &glFormat, &glType);
    unsigned int size = gsrlGetPixelDataSize(width, height, format);

    if ((glInternalFormat != 0) && (format < GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB))
    {
        pixels = GSRL_MALLOC(size);
        glGetTexImage(GL_TEXTURE_2D, 0, glFormat, glType, pixels);
    }
    else TRACELOG(GSRL_LOG_WARNING, "TEXTURE: [ID %i] Data retrieval not suported for pixel format (%i)", id, format);

    glBindTexture(GL_TEXTURE_2D, 0);
#endif

#if defined(GRAPHICS_API_OPENGL_ES2)
    // glGetTexImage() is not available on OpenGL ES 2.0
    // Texture width and height are required on OpenGL ES 2.0, there is no way to get it from texture id
    // Two possible Options:
    // 1 - Bind texture to color fbo attachment and glReadPixels()
    // 2 - Create an fbo, activate it, render quad with texture, glReadPixels()
    // We are using Option 1, just need to care for texture format on retrieval
    // NOTE: This behaviour could be conditioned by graphic driver...
    unsigned int fboId = gsrlLoadFramebuffer();

    glBindFramebuffer(GL_FRAMEBUFFER, fboId);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Attach our texture to FBO
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, id, 0);

    // We read data as RGBA because FBO texture is configured as RGBA, despite binding another texture format
    pixels = (unsigned char *)GSRL_MALLOC(gsrlGetPixelDataSize(width, height, GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8));
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Clean up temporal fbo
    gsrlUnloadFramebuffer(fboId);
#endif

    return pixels;
}

// Read screen pixel data (color buffer)
unsigned char *gsrlReadScreenPixels(int width, int height)
{
    unsigned char *screenData = (unsigned char *)GSRL_CALLOC(width*height*4, sizeof(unsigned char));

    // NOTE 1: glReadPixels returns image flipped vertically -> (0,0) is the bottom left corner of the framebuffer
    // NOTE 2: We are getting alpha channel! Be careful, it can be transparent if not cleared properly!
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, screenData);

    // Flip image vertically!
    unsigned char *imgData = (unsigned char *)GSRL_MALLOC(width*height*4*sizeof(unsigned char));

    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < (width*4); x++)
        {
            imgData[((height - 1) - y)*width*4 + x] = screenData[(y*width*4) + x];  // Flip line

            // Set alpha component value to 255 (no trasparent image retrieval)
            // NOTE: Alpha value has already been applied to RGB in framebuffer, we don't need it!
            if (((x + 1)%4) == 0) imgData[((height - 1) - y)*width*4 + x] = 255;
        }
    }

    GSRL_FREE(screenData);

    return imgData;     // NOTE: image data should be freed
}

// Framebuffer management (fbo)
//-----------------------------------------------------------------------------------------
// Load a framebuffer to be used for rendering
// NOTE: No textures attached
unsigned int gsrlLoadFramebuffer(void)
{
    unsigned int fboId = 0;

#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glGenFramebuffers(1, &fboId);       // Create the framebuffer object
    glBindFramebuffer(GL_FRAMEBUFFER, 0);   // Unbind any framebuffer
#endif

    return fboId;
}

// Attach color buffer texture to an fbo (unloads previous attachment)
// NOTE: Attach type: 0-Color, 1-Depth renderbuffer, 2-Depth texture
void gsrlFramebufferAttach(unsigned int fboId, unsigned int texId, int attachType, int texType, int mipLevel)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glBindFramebuffer(GL_FRAMEBUFFER, fboId);

    switch (attachType)
    {
        case GSRL_ATTACHMENT_COLOR_CHANNEL0:
        case GSRL_ATTACHMENT_COLOR_CHANNEL1:
        case GSRL_ATTACHMENT_COLOR_CHANNEL2:
        case GSRL_ATTACHMENT_COLOR_CHANNEL3:
        case GSRL_ATTACHMENT_COLOR_CHANNEL4:
        case GSRL_ATTACHMENT_COLOR_CHANNEL5:
        case GSRL_ATTACHMENT_COLOR_CHANNEL6:
        case GSRL_ATTACHMENT_COLOR_CHANNEL7:
        {
            if (texType == GSRL_ATTACHMENT_TEXTURE2D) glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachType, GL_TEXTURE_2D, texId, mipLevel);
            else if (texType == GSRL_ATTACHMENT_RENDERBUFFER) glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachType, GL_RENDERBUFFER, texId);
            else if (texType >= GSRL_ATTACHMENT_CUBEMAP_POSITIVE_X) glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + attachType, GL_TEXTURE_CUBE_MAP_POSITIVE_X + texType, texId, mipLevel);

        } break;
        case GSRL_ATTACHMENT_DEPTH:
        {
            if (texType == GSRL_ATTACHMENT_TEXTURE2D) glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texId, mipLevel);
            else if (texType == GSRL_ATTACHMENT_RENDERBUFFER)  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, texId);

        } break;
        case GSRL_ATTACHMENT_STENCIL:
        {
            if (texType == GSRL_ATTACHMENT_TEXTURE2D) glFramebufferTexture2D(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texId, mipLevel);
            else if (texType == GSRL_ATTACHMENT_RENDERBUFFER)  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, texId);

        } break;
        default: break;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif
}

// Verify render texture is complete
bool gsrlFramebufferComplete(unsigned int id)
{
    bool result = false;

#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    glBindFramebuffer(GL_FRAMEBUFFER, id);

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    if (status != GL_FRAMEBUFFER_COMPLETE)
    {
        switch (status)
        {
            case GL_FRAMEBUFFER_UNSUPPORTED: TRACELOG(GSRL_LOG_WARNING, "FBO: [ID %i] Framebuffer is unsupported", id); break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: TRACELOG(GSRL_LOG_WARNING, "FBO: [ID %i] Framebuffer has incomplete attachment", id); break;
#if defined(GRAPHICS_API_OPENGL_ES2)
            case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS: TRACELOG(GSRL_LOG_WARNING, "FBO: [ID %i] Framebuffer has incomplete dimensions", id); break;
#endif
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: TRACELOG(GSRL_LOG_WARNING, "FBO: [ID %i] Framebuffer has a missing attachment", id); break;
            default: break;
        }
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    result = (status == GL_FRAMEBUFFER_COMPLETE);
#endif

    return result;
}

// Unload framebuffer from GPU memory
// NOTE: All attached textures/cubemaps/renderbuffers are also deleted
void gsrlUnloadFramebuffer(unsigned int id)
{
#if (defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)) && defined(gsrl_RENDER_TEXTURES_HINT)
    // Query depth attachment to automatically delete texture/renderbuffer
    int depthType = 0, depthId = 0;
    glBindFramebuffer(GL_FRAMEBUFFER, id);   // Bind framebuffer to query depth texture type
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, &depthType);

    // TODO: Review warning retrieving object name in WebGL
    // WARNING: WebGL: INVALID_ENUM: getFramebufferAttachmentParameter: invalid parameter name
    // https://registry.khronos.org/webgl/specs/latest/1.0/
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &depthId);

    unsigned int depthIdU = (unsigned int)depthId;
    if (depthType == GL_RENDERBUFFER) glDeleteRenderbuffers(1, &depthIdU);
    else if (depthType == GL_TEXTURE) glDeleteTextures(1, &depthIdU);

    // NOTE: If a texture object is deleted while its image is attached to the *currently bound* framebuffer,
    // the texture image is automatically detached from the currently bound framebuffer

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers(1, &id);

    TRACELOG(GSRL_LOG_INFO, "FBO: [ID %i] Unloaded framebuffer from VRAM (GPU)", id);
#endif
}

// Vertex data management
//-----------------------------------------------------------------------------------------
// Load a new attributes buffer
unsigned int gsrlLoadVertexBuffer(const void *buffer, int size, bool dynamic)
{
    unsigned int id = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, buffer, dynamic? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
#endif

    return id;
}

// Load a new attributes element buffer
unsigned int gsrlLoadVertexBufferElement(const void *buffer, int size, bool dynamic)
{
    unsigned int id = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, dynamic? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
#endif

    return id;
}

// Enable vertex buffer (VBO)
void gsrlEnableVertexBuffer(unsigned int id)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindBuffer(GL_ARRAY_BUFFER, id);
#endif
}

// Disable vertex buffer (VBO)
void gsrlDisableVertexBuffer(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

// Enable vertex buffer element (VBO element)
void gsrlEnableVertexBufferElement(unsigned int id)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
#endif
}

// Disable vertex buffer element (VBO element)
void gsrlDisableVertexBufferElement(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
#endif
}

// Update vertex buffer with new data
// NOTE: dataSize and offset must be provided in bytes
void gsrlUpdateVertexBuffer(unsigned int id, const void *data, int dataSize, int offset)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferSubData(GL_ARRAY_BUFFER, offset, dataSize, data);
#endif
}

// Update vertex buffer elements with new data
// NOTE: dataSize and offset must be provided in bytes
void gsrlUpdateVertexBufferElements(unsigned int id, const void *data, int dataSize, int offset)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, dataSize, data);
#endif
}

// Enable vertex array object (VAO)
bool gsrlEnableVertexArray(unsigned int vaoId)
{
    bool result = false;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if (gsrl.ExtSupported.vao)
    {
        glBindVertexArray(vaoId);
        result = true;
    }
#endif
    return result;
}

// Disable vertex array object (VAO)
void gsrlDisableVertexArray(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if (gsrl.ExtSupported.vao) glBindVertexArray(0);
#endif
}

// Enable vertex attribute index
void gsrlEnableVertexAttribute(unsigned int index)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glEnableVertexAttribArray(index);
#endif
}

// Disable vertex attribute index
void gsrlDisableVertexAttribute(unsigned int index)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glDisableVertexAttribArray(index);
#endif
}

// Draw vertex array
void gsrlDrawVertexArray(int offset, int count)
{
    glDrawArrays(GL_TRIANGLES, offset, count);
}

// Draw vertex array elements
void gsrlDrawVertexArrayElements(int offset, int count, const void *buffer)
{
    // NOTE: Added pointer math separately from function to avoid UBSAN complaining
    unsigned short *bufferPtr = (unsigned short *)buffer;
    if (offset > 0) bufferPtr += offset;

    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, (const unsigned short *)bufferPtr);
}

// Draw vertex array instanced
void gsrlDrawVertexArrayInstanced(int offset, int count, int instances)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glDrawArraysInstanced(GL_TRIANGLES, 0, count, instances);
#endif
}

// Draw vertex array elements instanced
void gsrlDrawVertexArrayElementsInstanced(int offset, int count, const void *buffer, int instances)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // NOTE: Added pointer math separately from function to avoid UBSAN complaining
    unsigned short *bufferPtr = (unsigned short *)buffer;
    if (offset > 0) bufferPtr += offset;

    glDrawElementsInstanced(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, (const unsigned short *)bufferPtr, instances);
#endif
}

#if defined(GRAPHICS_API_OPENGL_11)
// Enable vertex state pointer
void gsrlEnableStatePointer(int vertexAttribType, void *buffer)
{
    if (buffer != NULL) glEnableClientState(vertexAttribType);
    switch (vertexAttribType)
    {
        case GL_VERTEX_ARRAY: glVertexPointer(3, GL_FLOAT, 0, buffer); break;
        case GL_TEXTURE_COORD_ARRAY: glTexCoordPointer(2, GL_FLOAT, 0, buffer); break;
        case GL_NORMAL_ARRAY: if (buffer != NULL) glNormalPointer(GL_FLOAT, 0, buffer); break;
        case GL_COLOR_ARRAY: if (buffer != NULL) glColorPointer(4, GL_UNSIGNED_BYTE, 0, buffer); break;
        //case GL_INDEX_ARRAY: if (buffer != NULL) glIndexPointer(GL_SHORT, 0, buffer); break; // Indexed colors
        default: break;
    }
}

// Disable vertex state pointer
void gsrlDisableStatePointer(int vertexAttribType)
{
    glDisableClientState(vertexAttribType);
}
#endif

// Load vertex array object (VAO)
unsigned int gsrlLoadVertexArray(void)
{
    unsigned int vaoId = 0;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if (gsrl.ExtSupported.vao)
    {
        glGenVertexArrays(1, &vaoId);
    }
#endif
    return vaoId;
}

// Set vertex attribute
void gsrlSetVertexAttribute(unsigned int index, int compSize, int type, bool normalized, int stride, int offset)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // NOTE: Data type could be: GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT, GL_INT, GL_UNSIGNED_INT
    // Additional types (depends on OpenGL version or extensions):
    //  - GL_HALF_FLOAT, GL_FLOAT, GL_DOUBLE, GL_FIXED,
    //  - GL_INT_2_10_10_10_REV, GL_UNSIGNED_INT_2_10_10_10_REV, GL_UNSIGNED_INT_10F_11F_11F_REV

    size_t offsetNative = offset;
    glVertexAttribPointer(index, compSize, type, normalized, stride, (void *)offsetNative);
#endif
}

// Set vertex attribute divisor
void gsrlSetVertexAttributeDivisor(unsigned int index, int divisor)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glVertexAttribDivisor(index, divisor);
#endif
}

// Unload vertex array object (VAO)
void gsrlUnloadVertexArray(unsigned int vaoId)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if (gsrl.ExtSupported.vao)
    {
        glBindVertexArray(0);
        glDeleteVertexArrays(1, &vaoId);
        TRACELOG(GSRL_LOG_INFO, "VAO: [ID %i] Unloaded vertex array data from VRAM (GPU)", vaoId);
    }
#endif
}

// Unload vertex buffer (VBO)
void gsrlUnloadVertexBuffer(unsigned int vboId)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glDeleteBuffers(1, &vboId);
    //TRACELOG(GSRL_LOG_INFO, "VBO: Unloaded vertex data from VRAM (GPU)");
#endif
}

// Shaders management
//-----------------------------------------------------------------------------------------------
// Load shader from code strings
// NOTE: If shader string is NULL, using default vertex/fragment shaders
unsigned int gsrlLoadShaderCode(const char *vsCode, const char *fsCode)
{
    unsigned int id = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    unsigned int vertexShaderId = 0;
    unsigned int fragmentShaderId = 0;

    // Compile vertex shader (if provided)
    // NOTE: If not vertex shader is provided, use default one
    if (vsCode != NULL) vertexShaderId = gsrlCompileShader(vsCode, GL_VERTEX_SHADER);
    else vertexShaderId = gsrl.State.defaultVShaderId;

    // Compile fragment shader (if provided)
    // NOTE: If not vertex shader is provided, use default one
    if (fsCode != NULL) fragmentShaderId = gsrlCompileShader(fsCode, GL_FRAGMENT_SHADER);
    else fragmentShaderId = gsrl.State.defaultFShaderId;

    // In case vertex and fragment shader are the default ones, no need to recompile, we can just assign the default shader program id
    if ((vertexShaderId == gsrl.State.defaultVShaderId) && (fragmentShaderId == gsrl.State.defaultFShaderId)) id = gsrl.State.defaultShaderId;
    else if ((vertexShaderId > 0) && (fragmentShaderId > 0))
    {
        // One of or both shader are new, we need to compile a new shader program
        id = gsrlLoadShaderProgram(vertexShaderId, fragmentShaderId);

        // We can detach and delete vertex/fragment shaders (if not default ones)
        // NOTE: We detach shader before deletion to make sure memory is freed
        if (vertexShaderId != gsrl.State.defaultVShaderId)
        {
            // WARNING: Shader program linkage could fail and returned id is 0
            if (id > 0) glDetachShader(id, vertexShaderId);
            glDeleteShader(vertexShaderId);
        }
        if (fragmentShaderId != gsrl.State.defaultFShaderId)
        {
            // WARNING: Shader program linkage could fail and returned id is 0
            if (id > 0) glDetachShader(id, fragmentShaderId);
            glDeleteShader(fragmentShaderId);
        }

        // In case shader program loading failed, we assign default shader
        if (id == 0)
        {
            // In case shader loading fails, we return the default shader
            TRACELOG(GSRL_LOG_WARNING, "SHADER: Failed to load custom shader code, using default shader");
            id = gsrl.State.defaultShaderId;
        }
        /*
        else
        {
            // Get available shader uniforms
            // NOTE: This information is useful for debug...
            int uniformCount = -1;
            glGetProgramiv(id, GL_ACTIVE_UNIFORMS, &uniformCount);

            for (int i = 0; i < uniformCount; i++)
            {
                int namelen = -1;
                int num = -1;
                char name[256] = { 0 };     // Assume no variable names longer than 256
                GLenum type = GL_ZERO;

                // Get the name of the uniforms
                glGetActiveUniform(id, i, sizeof(name) - 1, &namelen, &num, &type, name);

                name[namelen] = 0;
                TRACELOGD("SHADER: [ID %i] Active uniform (%s) set at location: %i", id, name, glGetUniformLocation(id, name));
            }
        }
        */
    }
#endif

    return id;
}

// Compile custom shader and return shader id
unsigned int gsrlCompileShader(const char *shaderCode, int type)
{
    unsigned int shader = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderCode, NULL);

    GLint success = 0;
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        switch (type)
        {
            case GL_VERTEX_SHADER: TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to compile vertex shader code", shader); break;
            case GL_FRAGMENT_SHADER: TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to compile fragment shader code", shader); break;
            //case GL_GEOMETRY_SHADER:
        #if defined(GRAPHICS_API_OPENGL_43)
            case GL_COMPUTE_SHADER: TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to compile compute shader code", shader); break;
        #elif defined(GRAPHICS_API_OPENGL_33)
            case GL_COMPUTE_SHADER: TRACELOG(GSRL_LOG_WARNING, "SHADER: Compute shaders not enabled. Define GRAPHICS_API_OPENGL_43", shader); break;
        #endif
            default: break;
        }

        int maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        if (maxLength > 0)
        {
            int length = 0;
            char *log = (char *)GSRL_CALLOC(maxLength, sizeof(char));
            glGetShaderInfoLog(shader, maxLength, &length, log);
            TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Compile error: %s", shader, log);
            GSRL_FREE(log);
        }

        shader = 0;
    }
    else
    {
        switch (type)
        {
            case GL_VERTEX_SHADER: TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Vertex shader compiled successfully", shader); break;
            case GL_FRAGMENT_SHADER: TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Fragment shader compiled successfully", shader); break;
            //case GL_GEOMETRY_SHADER:
        #if defined(GRAPHICS_API_OPENGL_43)
            case GL_COMPUTE_SHADER: TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Compute shader compiled successfully", shader); break;
        #elif defined(GRAPHICS_API_OPENGL_33)
            case GL_COMPUTE_SHADER: TRACELOG(GSRL_LOG_WARNING, "SHADER: Compute shaders not enabled. Define GRAPHICS_API_OPENGL_43", shader); break;
        #endif
            default: break;
        }
    }
#endif

    return shader;
}

// Load custom shader strings and return program id
unsigned int gsrlLoadShaderProgram(unsigned int vShaderId, unsigned int fShaderId)
{
    unsigned int program = 0;

#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    GLint success = 0;
    program = glCreateProgram();

    glAttachShader(program, vShaderId);
    glAttachShader(program, fShaderId);

    // NOTE: Default attribute shader locations must be Bound before linking
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION, GSRL_DEFAULT_SHADER_ATTRIB_NAME_POSITION);
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD, GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD);
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL, GSRL_DEFAULT_SHADER_ATTRIB_NAME_NORMAL);
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_COLOR, GSRL_DEFAULT_SHADER_ATTRIB_NAME_COLOR);
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TANGENT, GSRL_DEFAULT_SHADER_ATTRIB_NAME_TANGENT);
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD2, GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD2);

#ifdef GSRL_SUPPORT_MESH_GPU_SKINNING
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEIDS, GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEIDS);
    glBindAttribLocation(program, GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_BONEWEIGHTS, GSRL_DEFAULT_SHADER_ATTRIB_NAME_BONEWEIGHTS);
#endif

    // NOTE: If some attrib name is no found on the shader, it locations becomes -1

    glLinkProgram(program);

    // NOTE: All uniform variables are intitialised to 0 when a program links

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (success == GL_FALSE)
    {
        TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to link shader program", program);

        int maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        if (maxLength > 0)
        {
            int length = 0;
            char *log = (char *)GSRL_CALLOC(maxLength, sizeof(char));
            glGetProgramInfoLog(program, maxLength, &length, log);
            TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Link error: %s", program, log);
            GSRL_FREE(log);
        }

        glDeleteProgram(program);

        program = 0;
    }
    else
    {
        // Get the size of compiled shader program (not available on OpenGL ES 2.0)
        // NOTE: If GL_LINK_STATUS is GL_FALSE, program binary length is zero
        //GLint binarySize = 0;
        //glGetProgramiv(id, GL_PROGRAM_BINARY_LENGTH, &binarySize);

        TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Program shader loaded successfully", program);
    }
#endif
#if defined(GRAPHICS_API_OPENGL_33)
    ps2xgsrlVbRingForget(program);   /* [ps2x vbring] a fresh program (possibly a reused id) has zero uniforms */
#endif
    return program;
}

// Unload shader program
void gsrlUnloadShaderProgram(unsigned int id)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    glDeleteProgram(id);
#if defined(GRAPHICS_API_OPENGL_33)
    ps2xgsrlVbRingForget(id);   /* [ps2x vbring] */
#endif

    TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Unloaded shader program data from VRAM (GPU)", id);
#endif
}

// Get shader location uniform
int gsrlGetLocationUniform(unsigned int shaderId, const char *uniformName)
{
    int location = -1;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    location = glGetUniformLocation(shaderId, uniformName);

    //if (location == -1) TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to find shader uniform: %s", shaderId, uniformName);
    //else TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Shader uniform (%s) set at location: %i", shaderId, uniformName, location);
#endif
    return location;
}

// Get shader location attribute
int gsrlGetLocationAttrib(unsigned int shaderId, const char *attribName)
{
    int location = -1;
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    location = glGetAttribLocation(shaderId, attribName);

    //if (location == -1) TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to find shader attribute: %s", shaderId, attribName);
    //else TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Shader attribute (%s) set at location: %i", shaderId, attribName, location);
#endif
    return location;
}

// Set shader value uniform
void gsrlSetUniform(int locIndex, const void *value, int uniformType, int count)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    switch (uniformType)
    {
        case GSRL_SHADER_UNIFORM_FLOAT: glUniform1fv(locIndex, count, (float *)value); break;
        case GSRL_SHADER_UNIFORM_VEC2: glUniform2fv(locIndex, count, (float *)value); break;
        case GSRL_SHADER_UNIFORM_VEC3: glUniform3fv(locIndex, count, (float *)value); break;
        case GSRL_SHADER_UNIFORM_VEC4: glUniform4fv(locIndex, count, (float *)value); break;
        case GSRL_SHADER_UNIFORM_INT: glUniform1iv(locIndex, count, (int *)value); break;
        case GSRL_SHADER_UNIFORM_IVEC2: glUniform2iv(locIndex, count, (int *)value); break;
        case GSRL_SHADER_UNIFORM_IVEC3: glUniform3iv(locIndex, count, (int *)value); break;
        case GSRL_SHADER_UNIFORM_IVEC4: glUniform4iv(locIndex, count, (int *)value); break;
    #if !defined(GRAPHICS_API_OPENGL_ES2)
        case GSRL_SHADER_UNIFORM_UINT: glUniform1uiv(locIndex, count, (unsigned int *)value); break;
        case GSRL_SHADER_UNIFORM_UIVEC2: glUniform2uiv(locIndex, count, (unsigned int *)value); break;
        case GSRL_SHADER_UNIFORM_UIVEC3: glUniform3uiv(locIndex, count, (unsigned int *)value); break;
        case GSRL_SHADER_UNIFORM_UIVEC4: glUniform4uiv(locIndex, count, (unsigned int *)value); break;
    #endif
        case GSRL_SHADER_UNIFORM_SAMPLER2D: glUniform1iv(locIndex, count, (int *)value); break;
        default: TRACELOG(GSRL_LOG_WARNING, "SHADER: Failed to set uniform value, data type not recognized");

        // TODO: Support glUniform1uiv(), glUniform2uiv(), glUniform3uiv(), glUniform4uiv()
    }
#endif
}

// Set shader value attribute
void gsrlSetVertexAttributeDefault(int locIndex, const void *value, int attribType, int count)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    switch (attribType)
    {
        case GSRL_SHADER_ATTRIB_FLOAT: if (count == 1) glVertexAttrib1fv(locIndex, (float *)value); break;
        case GSRL_SHADER_ATTRIB_VEC2: if (count == 2) glVertexAttrib2fv(locIndex, (float *)value); break;
        case GSRL_SHADER_ATTRIB_VEC3: if (count == 3) glVertexAttrib3fv(locIndex, (float *)value); break;
        case GSRL_SHADER_ATTRIB_VEC4: if (count == 4) glVertexAttrib4fv(locIndex, (float *)value); break;
        default: TRACELOG(GSRL_LOG_WARNING, "SHADER: Failed to set attrib default value, data type not recognized");
    }
#endif
}

// Set shader value uniform matrix
void gsrlSetUniformMatrix(int locIndex, Matrix mat)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    float matfloat[16] = {
        mat.m0, mat.m1, mat.m2, mat.m3,
        mat.m4, mat.m5, mat.m6, mat.m7,
        mat.m8, mat.m9, mat.m10, mat.m11,
        mat.m12, mat.m13, mat.m14, mat.m15
    };
    glUniformMatrix4fv(locIndex, 1, false, matfloat);
#endif
}

// Set shader value uniform matrix
void gsrlSetUniformMatrices(int locIndex, const Matrix *matrices, int count)
{
#if defined(GRAPHICS_API_OPENGL_33)
    glUniformMatrix4fv(locIndex, count, true, (const float *)matrices);
#elif defined(GRAPHICS_API_OPENGL_ES2)
    // WARNING: WebGL does not support Matrix transpose ("true" parameter)
    // REF: https://developer.mozilla.org/en-US/docs/Web/API/WebGLRenderingContext/uniformMatrix
    glUniformMatrix4fv(locIndex, count, false, (const float *)matrices);
#endif
}

// Set shader value uniform sampler
void gsrlSetUniformSampler(int locIndex, unsigned int textureId)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // Check if texture is already active
    for (int i = 0; i < GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS; i++)
    {
        if (gsrl.State.activeTextureId[i] == textureId)
        {
            glUniform1i(locIndex, 1 + i);
            return;
        }
    }

    // Register a new active texture for the internal batch system
    // NOTE: Default texture is always activated as GL_TEXTURE0
    for (int i = 0; i < GSRL_DEFAULT_BATCH_MAX_TEXTURE_UNITS; i++)
    {
        if (gsrl.State.activeTextureId[i] == 0)
        {
            glUniform1i(locIndex, 1 + i);              // Activate new texture unit
            gsrl.State.activeTextureId[i] = textureId; // Save texture id for binding on drawing
            break;
        }
    }
#endif
}

// Set shader currently active (id and locations)
void gsrlSetShader(unsigned int id, int *locs)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    if (gsrl.State.currentShaderId != id)
    {
        gsrlDrawRenderBatch(gsrl.currentBatch);
        gsrl.State.currentShaderId = id;
        gsrl.State.currentShaderLocs = locs;
    }
#endif
}

// Load compute shader program
unsigned int gsrlLoadComputeShaderProgram(unsigned int shaderId)
{
    unsigned int program = 0;

#if defined(GRAPHICS_API_OPENGL_43)
    GLint success = 0;
    program = glCreateProgram();
    glAttachShader(program, shaderId);
    glLinkProgram(program);

    // NOTE: All uniform variables are intitialised to 0 when a program links

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (success == GL_FALSE)
    {
        TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to link compute shader program", program);

        int maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        if (maxLength > 0)
        {
            int length = 0;
            char *log = (char *)GSRL_CALLOC(maxLength, sizeof(char));
            glGetProgramInfoLog(program, maxLength, &length, log);
            TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Link error: %s", program, log);
            GSRL_FREE(log);
        }

        glDeleteProgram(program);

        program = 0;
    }
    else
    {
        // Get the size of compiled shader program (not available on OpenGL ES 2.0)
        // NOTE: If GL_LINK_STATUS is GL_FALSE, program binary length is zero
        //GLint binarySize = 0;
        //glGetProgramiv(id, GL_PROGRAM_BINARY_LENGTH, &binarySize);

        TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Compute shader program loaded successfully", program);
    }
#else
    TRACELOG(GSRL_LOG_WARNING, "SHADER: Compute shaders not enabled. Define GRAPHICS_API_OPENGL_43");
#endif

    return program;
}

// Dispatch compute shader (equivalent to *draw* for graphics pilepine)
void gsrlComputeShaderDispatch(unsigned int groupX, unsigned int groupY, unsigned int groupZ)
{
#if defined(GRAPHICS_API_OPENGL_43)
    glDispatchCompute(groupX, groupY, groupZ);
#endif
}

// Load shader storage buffer object (SSBO)
unsigned int gsrlLoadShaderBuffer(unsigned int size, const void *data, int usageHint)
{
    unsigned int ssbo = 0;

#if defined(GRAPHICS_API_OPENGL_43)
    glGenBuffers(1, &ssbo);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
    glBufferData(GL_SHADER_STORAGE_BUFFER, size, data, usageHint? usageHint : GSRL_STREAM_COPY);
    if (data == NULL) glClearBufferData(GL_SHADER_STORAGE_BUFFER, GL_R8UI, GL_RED_INTEGER, GL_UNSIGNED_BYTE, NULL);    // Clear buffer data to 0
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
#else
    TRACELOG(GSRL_LOG_WARNING, "SSBO: SSBO not enabled. Define GRAPHICS_API_OPENGL_43");
#endif

    return ssbo;
}

// Unload shader storage buffer object (SSBO)
void gsrlUnloadShaderBuffer(unsigned int ssboId)
{
#if defined(GRAPHICS_API_OPENGL_43)
    glDeleteBuffers(1, &ssboId);
#else
    TRACELOG(GSRL_LOG_WARNING, "SSBO: SSBO not enabled. Define GRAPHICS_API_OPENGL_43");
#endif

}

// Update SSBO buffer data
void gsrlUpdateShaderBuffer(unsigned int id, const void *data, unsigned int dataSize, unsigned int offset)
{
#if defined(GRAPHICS_API_OPENGL_43)
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, id);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, offset, dataSize, data);
#endif
}

// Get SSBO buffer size
unsigned int gsrlGetShaderBufferSize(unsigned int id)
{
#if defined(GRAPHICS_API_OPENGL_43)
    GLint64 size = 0;
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, id);
    glGetBufferParameteri64v(GL_SHADER_STORAGE_BUFFER, GL_BUFFER_SIZE, &size);
    return (size > 0)? (unsigned int)size : 0;
#else
    return 0;
#endif
}

// Read SSBO buffer data (GPU->CPU)
void gsrlReadShaderBuffer(unsigned int id, void *dest, unsigned int count, unsigned int offset)
{
#if defined(GRAPHICS_API_OPENGL_43)
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, id);
    glGetBufferSubData(GL_SHADER_STORAGE_BUFFER, offset, count, dest);
#endif
}

// Bind SSBO buffer
void gsrlBindShaderBuffer(unsigned int id, unsigned int index)
{
#if defined(GRAPHICS_API_OPENGL_43)
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, id);
#endif
}

// Copy SSBO buffer data
void gsrlCopyShaderBuffer(unsigned int destId, unsigned int srcId, unsigned int destOffset, unsigned int srcOffset, unsigned int count)
{
#if defined(GRAPHICS_API_OPENGL_43)
    glBindBuffer(GL_COPY_READ_BUFFER, srcId);
    glBindBuffer(GL_COPY_WRITE_BUFFER, destId);
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, srcOffset, destOffset, count);
#endif
}

// Bind image texture
void gsrlBindImageTexture(unsigned int id, unsigned int index, int format, bool readonly)
{
#if defined(GRAPHICS_API_OPENGL_43)
    unsigned int glInternalFormat = 0, glFormat = 0, glType = 0;

    gsrlGetGlTextureFormats(format, &glInternalFormat, &glFormat, &glType);
    glBindImageTexture(index, id, 0, 0, 0, readonly? GL_READ_ONLY : GL_READ_WRITE, glInternalFormat);
#else
    TRACELOG(GSRL_LOG_WARNING, "TEXTURE: Image texture binding not enabled. Define GRAPHICS_API_OPENGL_43");
#endif
}

// Matrix state management
//-----------------------------------------------------------------------------------------
// Get internal modelview matrix
Matrix gsrlGetMatrixModelview(void)
{
    Matrix matrix = gsrlMatrixIdentity();
#if defined(GRAPHICS_API_OPENGL_11)
    float mat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, mat);
    matrix.m0 = mat[0];
    matrix.m1 = mat[1];
    matrix.m2 = mat[2];
    matrix.m3 = mat[3];
    matrix.m4 = mat[4];
    matrix.m5 = mat[5];
    matrix.m6 = mat[6];
    matrix.m7 = mat[7];
    matrix.m8 = mat[8];
    matrix.m9 = mat[9];
    matrix.m10 = mat[10];
    matrix.m11 = mat[11];
    matrix.m12 = mat[12];
    matrix.m13 = mat[13];
    matrix.m14 = mat[14];
    matrix.m15 = mat[15];
#else
    matrix = gsrl.State.modelview;
#endif
    return matrix;
}

// Get internal projection matrix
Matrix gsrlGetMatrixProjection(void)
{
#if defined(GRAPHICS_API_OPENGL_11)
    float mat[16];
    glGetFloatv(GL_PROJECTION_MATRIX,mat);
    Matrix m;
    m.m0 = mat[0];
    m.m1 = mat[1];
    m.m2 = mat[2];
    m.m3 = mat[3];
    m.m4 = mat[4];
    m.m5 = mat[5];
    m.m6 = mat[6];
    m.m7 = mat[7];
    m.m8 = mat[8];
    m.m9 = mat[9];
    m.m10 = mat[10];
    m.m11 = mat[11];
    m.m12 = mat[12];
    m.m13 = mat[13];
    m.m14 = mat[14];
    m.m15 = mat[15];
    return m;
#else
    return gsrl.State.projection;
#endif
}

// Get internal accumulated transform matrix
Matrix gsrlGetMatrixTransform(void)
{
    Matrix mat = gsrlMatrixIdentity();
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    // TODO: Consider possible transform matrices in the gsrl.State.stack
    // Is this the right order? or should we start with the first stored matrix instead of the last one?
    //Matrix matStackTransform = gsrlMatrixIdentity();
    //for (int i = gsrl.State.stackCounter; i > 0; i--) matStackTransform = gsrlMatrixMultiply(gsrl.State.stack[i], matStackTransform);
    mat = gsrl.State.transform;
#endif
    return mat;
}

// Get internal projection matrix for stereo render (selected eye)
Matrix gsrlGetMatrixProjectionStereo(int eye)
{
    Matrix mat = gsrlMatrixIdentity();
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    mat = gsrl.State.projectionStereo[eye];
#endif
    return mat;
}

// Get internal view offset matrix for stereo render (selected eye)
Matrix gsrlGetMatrixViewOffsetStereo(int eye)
{
    Matrix mat = gsrlMatrixIdentity();
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    mat = gsrl.State.viewOffsetStereo[eye];
#endif
    return mat;
}

// Set a custom modelview matrix (replaces internal modelview matrix)
void gsrlSetMatrixModelview(Matrix view)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrl.State.modelview = view;
#endif
}

// Set a custom projection matrix (replaces internal projection matrix)
void gsrlSetMatrixProjection(Matrix projection)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrl.State.projection = projection;
#endif
}

// Set eyes projection matrices for stereo rendering
void gsrlSetMatrixProjectionStereo(Matrix right, Matrix left)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrl.State.projectionStereo[0] = right;
    gsrl.State.projectionStereo[1] = left;
#endif
}

// Set eyes view offsets matrices for stereo rendering
void gsrlSetMatrixViewOffsetStereo(Matrix right, Matrix left)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    gsrl.State.viewOffsetStereo[0] = right;
    gsrl.State.viewOffsetStereo[1] = left;
#endif
}

// Load and draw a quad in NDC
void gsrlLoadDrawQuad(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    unsigned int quadVAO = 0;
    unsigned int quadVBO = 0;

    float vertices[] = {
         // Positions         Texcoords
        -1.0f,  1.0f, 0.0f,   0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f,   0.0f, 0.0f,
         1.0f,  1.0f, 0.0f,   1.0f, 1.0f,
         1.0f, -1.0f, 0.0f,   1.0f, 0.0f,
    };

    // Gen VAO to contain VBO
    glGenVertexArrays(1, &quadVAO);
    glBindVertexArray(quadVAO);

    // Gen and fill vertex buffer (VBO)
    glGenBuffers(1, &quadVBO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    // Bind vertex attributes (position, texcoords)
    glEnableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION);
    glVertexAttribPointer(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void *)0); // Positions
    glEnableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD);
    glVertexAttribPointer(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void *)(3*sizeof(float))); // Texcoords

    // Draw quad
    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);

    // Delete buffers (VBO and VAO)
    glDeleteBuffers(1, &quadVBO);
    glDeleteVertexArrays(1, &quadVAO);
#endif
}

// Load and draw a cube in NDC
void gsrlLoadDrawCube(void)
{
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
    unsigned int cubeVAO = 0;
    unsigned int cubeVBO = 0;

    float vertices[] = {
         // Positions          Normals               Texcoords
        -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
         1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
         1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f, 0.0f,
         1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f, 0.0f,
        -1.0f,  1.0f, -1.0f,   0.0f,  0.0f, -1.0f,   0.0f, 1.0f,
        -1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
         1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   1.0f, 1.0f,
        -1.0f,  1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f, 1.0f,
        -1.0f, -1.0f,  1.0f,   0.0f,  0.0f,  1.0f,   0.0f, 0.0f,
        -1.0f,  1.0f,  1.0f,  -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
        -1.0f,  1.0f, -1.0f,  -1.0f,  0.0f,  0.0f,   1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,  -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,  -1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
        -1.0f, -1.0f,  1.0f,  -1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
        -1.0f,  1.0f,  1.0f,  -1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,   1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
         1.0f, -1.0f, -1.0f,   1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
         1.0f,  1.0f, -1.0f,   1.0f,  0.0f,  0.0f,   1.0f, 1.0f,
         1.0f, -1.0f, -1.0f,   1.0f,  0.0f,  0.0f,   0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,   1.0f,  0.0f,  0.0f,   1.0f, 0.0f,
         1.0f, -1.0f,  1.0f,   1.0f,  0.0f,  0.0f,   0.0f, 0.0f,
        -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f, 1.0f,
         1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   1.0f, 1.0f,
         1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f, 0.0f,
         1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   1.0f, 0.0f,
        -1.0f, -1.0f,  1.0f,   0.0f, -1.0f,  0.0f,   0.0f, 0.0f,
        -1.0f, -1.0f, -1.0f,   0.0f, -1.0f,  0.0f,   0.0f, 1.0f,
        -1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   1.0f, 0.0f,
         1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   1.0f, 1.0f,
         1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   1.0f, 0.0f,
        -1.0f,  1.0f, -1.0f,   0.0f,  1.0f,  0.0f,   0.0f, 1.0f,
        -1.0f,  1.0f,  1.0f,   0.0f,  1.0f,  0.0f,   0.0f, 0.0f
    };

    // Gen VAO to contain VBO
    glGenVertexArrays(1, &cubeVAO);
    glBindVertexArray(cubeVAO);

    // Gen and fill vertex buffer (VBO)
    glGenBuffers(1, &cubeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Bind vertex attributes (position, normals, texcoords)
    glBindVertexArray(cubeVAO);
    glEnableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION);
    glVertexAttribPointer(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_POSITION, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void *)0); // Positions
    glEnableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL);
    glVertexAttribPointer(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_NORMAL, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void *)(3*sizeof(float))); // Normals
    glEnableVertexAttribArray(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD);
    glVertexAttribPointer(GSRL_DEFAULT_SHADER_ATTRIB_LOCATION_TEXCOORD, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void *)(6*sizeof(float))); // Texcoords
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Draw cube
    glBindVertexArray(cubeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    // Delete VBO and VAO
    glDeleteBuffers(1, &cubeVBO);
    glDeleteVertexArrays(1, &cubeVAO);
#endif
}

// Get name string for pixel format
const char *gsrlGetPixelFormatName(unsigned int format)
{
    switch (format)
    {
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE: return "GRAYSCALE"; break;         // 8 bit per pixel (no alpha)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA: return "GRAY_ALPHA"; break;       // 8*2 bpp (2 channels)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G6B5: return "R5G6B5"; break;               // 16 bpp
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8: return "R8G8B8"; break;               // 24 bpp
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G5B5A1: return "R5G5B5A1"; break;           // 16 bpp (1 bit alpha)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R4G4B4A4: return "R4G4B4A4"; break;           // 16 bpp (4 bit alpha)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8: return "R8G8B8A8"; break;           // 32 bpp
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32: return "R32"; break;                     // 32 bpp (1 channel - float)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32: return "R32G32B32"; break;         // 32*3 bpp (3 channels - float)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32: return "R32G32B32A32"; break;   // 32*4 bpp (4 channels - float)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16: return "R16"; break;                     // 16 bpp (1 channel - half float)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16: return "R16G16B16"; break;         // 16*3 bpp (3 channels - half float)
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: return "R16G16B16A16"; break;   // 16*4 bpp (4 channels - half float)
        case GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB: return "DXT1_RGB"; break;             // 4 bpp (no alpha)
        case GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGBA: return "DXT1_RGBA"; break;           // 4 bpp (1 bit alpha)
        case GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA: return "DXT3_RGBA"; break;           // 8 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_DXT5_RGBA: return "DXT5_RGBA"; break;           // 8 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_ETC1_RGB: return "ETC1_RGB"; break;             // 4 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_ETC2_RGB: return "ETC2_RGB"; break;             // 4 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA: return "ETC2_RGBA"; break;       // 8 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGB: return "PVRT_RGB"; break;             // 4 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGBA: return "PVRT_RGBA"; break;           // 4 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA: return "ASTC_4x4_RGBA"; break;   // 8 bpp
        case GSRL_PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA: return "ASTC_8x8_RGBA"; break;   // 2 bpp
        default: return "UNKNOWN"; break;
    }
}

//----------------------------------------------------------------------------------
// Module specific Functions Definition
//----------------------------------------------------------------------------------
#if defined(GRAPHICS_API_OPENGL_33) || defined(GRAPHICS_API_OPENGL_ES2)
// Load default shader (just vertex positioning and texture coloring)
// NOTE: This shader program is used for internal buffers
// NOTE: Loaded: gsrl.State.defaultShaderId, gsrl.State.defaultShaderLocs
static void gsrlLoadShaderDefault(void)
{
    gsrl.State.defaultShaderLocs = (int *)GSRL_CALLOC(GSRL_MAX_SHADER_LOCATIONS, sizeof(int));

    // NOTE: All locations must be reseted to -1 (no location)
    for (int i = 0; i < GSRL_MAX_SHADER_LOCATIONS; i++) gsrl.State.defaultShaderLocs[i] = -1;

    // Vertex shader directly defined, no external file required
    const char *defaultVShaderCode =
#if defined(GRAPHICS_API_OPENGL_21)
    "#version 120                       \n"
    "attribute vec3 vertexPosition;     \n"
    "attribute vec2 vertexTexCoord;     \n"
    "attribute vec4 vertexColor;        \n"
    "varying vec2 fragTexCoord;         \n"
    "varying vec4 fragColor;            \n"
#elif defined(GRAPHICS_API_OPENGL_33)
    "#version 330                       \n"
    "in vec3 vertexPosition;            \n"
    "in vec2 vertexTexCoord;            \n"
    "in vec4 vertexColor;               \n"
    "out vec2 fragTexCoord;             \n"
    "out vec4 fragColor;                \n"
#endif

#if defined(GRAPHICS_API_OPENGL_ES3)
    "#version 300 es                    \n"
    "precision mediump float;           \n"     // Precision required for OpenGL ES3 (WebGL 2) (on some browsers)
    "in vec3 vertexPosition;            \n"
    "in vec2 vertexTexCoord;            \n"
    "in vec4 vertexColor;               \n"
    "out vec2 fragTexCoord;             \n"
    "out vec4 fragColor;                \n"
#elif defined(GRAPHICS_API_OPENGL_ES2)
    "#version 100                       \n"
    "precision mediump float;           \n"     // Precision required for OpenGL ES2 (WebGL) (on some browsers)
    "attribute vec3 vertexPosition;     \n"
    "attribute vec2 vertexTexCoord;     \n"
    "attribute vec4 vertexColor;        \n"
    "varying vec2 fragTexCoord;         \n"
    "varying vec4 fragColor;            \n"
#endif

    "uniform mat4 mvp;                  \n"
    "void main()                        \n"
    "{                                  \n"
    "    fragTexCoord = vertexTexCoord; \n"
    "    fragColor = vertexColor;       \n"
    "    gl_Position = mvp*vec4(vertexPosition, 1.0); \n"
    "}                                  \n";

    // Fragment shader directly defined, no external file required
    const char *defaultFShaderCode =
#if defined(GRAPHICS_API_OPENGL_21)
    "#version 120                       \n"
    "varying vec2 fragTexCoord;         \n"
    "varying vec4 fragColor;            \n"
    "uniform sampler2D texture0;        \n"
    "uniform vec4 colDiffuse;           \n"
    "void main()                        \n"
    "{                                  \n"
    "    vec4 texelColor = texture2D(texture0, fragTexCoord); \n"
    "    gl_FragColor = texelColor*colDiffuse*fragColor;      \n"
    "}                                  \n";
#elif defined(GRAPHICS_API_OPENGL_33)
    "#version 330       \n"
    "in vec2 fragTexCoord;              \n"
    "in vec4 fragColor;                 \n"
    "out vec4 finalColor;               \n"
    "uniform sampler2D texture0;        \n"
    "uniform vec4 colDiffuse;           \n"
    "void main()                        \n"
    "{                                  \n"
    "    vec4 texelColor = texture(texture0, fragTexCoord);   \n"
    "    finalColor = texelColor*colDiffuse*fragColor;        \n"
    "}                                  \n";
#endif

#if defined(GRAPHICS_API_OPENGL_ES3)
    "#version 300 es                    \n"
    "precision mediump float;           \n"     // Precision required for OpenGL ES3 (WebGL 2)
    "in vec2 fragTexCoord;              \n"
    "in vec4 fragColor;                 \n"
    "out vec4 finalColor;               \n"
    "uniform sampler2D texture0;        \n"
    "uniform vec4 colDiffuse;           \n"
    "void main()                        \n"
    "{                                  \n"
    "    vec4 texelColor = texture(texture0, fragTexCoord);   \n"
    "    finalColor = texelColor*colDiffuse*fragColor;        \n"
    "}                                  \n";
#elif defined(GRAPHICS_API_OPENGL_ES2)
    "#version 100                       \n"
    "precision mediump float;           \n"     // Precision required for OpenGL ES2 (WebGL)
    "varying vec2 fragTexCoord;         \n"
    "varying vec4 fragColor;            \n"
    "uniform sampler2D texture0;        \n"
    "uniform vec4 colDiffuse;           \n"
    "void main()                        \n"
    "{                                  \n"
    "    vec4 texelColor = texture2D(texture0, fragTexCoord); \n"
    "    gl_FragColor = texelColor*colDiffuse*fragColor;      \n"
    "}                                  \n";
#endif

    // NOTE: Compiled vertex/fragment shaders are not deleted,
    // they are kept for re-use as default shaders in case some shader loading fails
    gsrl.State.defaultVShaderId = gsrlCompileShader(defaultVShaderCode, GL_VERTEX_SHADER);     // Compile default vertex shader
    gsrl.State.defaultFShaderId = gsrlCompileShader(defaultFShaderCode, GL_FRAGMENT_SHADER);   // Compile default fragment shader

    gsrl.State.defaultShaderId = gsrlLoadShaderProgram(gsrl.State.defaultVShaderId, gsrl.State.defaultFShaderId);

    if (gsrl.State.defaultShaderId > 0)
    {
        TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Default shader loaded successfully", gsrl.State.defaultShaderId);

        // Set default shader locations: attributes locations
        gsrl.State.defaultShaderLocs[GSRL_SHADER_LOC_VERTEX_POSITION] = glGetAttribLocation(gsrl.State.defaultShaderId, GSRL_DEFAULT_SHADER_ATTRIB_NAME_POSITION);
        gsrl.State.defaultShaderLocs[GSRL_SHADER_LOC_VERTEX_TEXCOORD01] = glGetAttribLocation(gsrl.State.defaultShaderId, GSRL_DEFAULT_SHADER_ATTRIB_NAME_TEXCOORD);
        gsrl.State.defaultShaderLocs[GSRL_SHADER_LOC_VERTEX_COLOR] = glGetAttribLocation(gsrl.State.defaultShaderId, GSRL_DEFAULT_SHADER_ATTRIB_NAME_COLOR);

        // Set default shader locations: uniform locations
        gsrl.State.defaultShaderLocs[GSRL_SHADER_LOC_MATRIX_MVP] = glGetUniformLocation(gsrl.State.defaultShaderId, GSRL_DEFAULT_SHADER_UNIFORM_NAME_MVP);
        gsrl.State.defaultShaderLocs[GSRL_SHADER_LOC_COLOR_DIFFUSE] = glGetUniformLocation(gsrl.State.defaultShaderId, GSRL_DEFAULT_SHADER_UNIFORM_NAME_COLOR);
        gsrl.State.defaultShaderLocs[GSRL_SHADER_LOC_MAP_DIFFUSE] = glGetUniformLocation(gsrl.State.defaultShaderId, GSRL_DEFAULT_SHADER_SAMPLER2D_NAME_TEXTURE0);
    }
    else TRACELOG(GSRL_LOG_WARNING, "SHADER: [ID %i] Failed to load default shader", gsrl.State.defaultShaderId);
}

// Unload default shader
// NOTE: Unloads: gsrl.State.defaultShaderId, gsrl.State.defaultShaderLocs
static void gsrlUnloadShaderDefault(void)
{
    glUseProgram(0);

    glDetachShader(gsrl.State.defaultShaderId, gsrl.State.defaultVShaderId);
    glDetachShader(gsrl.State.defaultShaderId, gsrl.State.defaultFShaderId);
    glDeleteShader(gsrl.State.defaultVShaderId);
    glDeleteShader(gsrl.State.defaultFShaderId);

    glDeleteProgram(gsrl.State.defaultShaderId);

    GSRL_FREE(gsrl.State.defaultShaderLocs);

    TRACELOG(GSRL_LOG_INFO, "SHADER: [ID %i] Default shader unloaded successfully", gsrl.State.defaultShaderId);
}

#if defined(gsrl_SHOW_GL_DETAILS_INFO)
// Get compressed format official GL identifier name
static const char *gsrlGetCompressedFormatName(int format)
{
    switch (format)
    {
        // GL_EXT_texture_compression_s3tc
        case 0x83F0: return "GL_COMPRESSED_RGB_S3TC_DXT1_EXT"; break;
        case 0x83F1: return "GL_COMPRESSED_RGBA_S3TC_DXT1_EXT"; break;
        case 0x83F2: return "GL_COMPRESSED_RGBA_S3TC_DXT3_EXT"; break;
        case 0x83F3: return "GL_COMPRESSED_RGBA_S3TC_DXT5_EXT"; break;
        // GL_3DFX_texture_compression_FXT1
        case 0x86B0: return "GL_COMPRESSED_RGB_FXT1_3DFX"; break;
        case 0x86B1: return "GL_COMPRESSED_RGBA_FXT1_3DFX"; break;
        // GL_IMG_texture_compression_pvrtc
        case 0x8C00: return "GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG"; break;
        case 0x8C01: return "GL_COMPRESSED_RGB_PVRTC_2BPPV1_IMG"; break;
        case 0x8C02: return "GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG"; break;
        case 0x8C03: return "GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG"; break;
        // GL_OES_compressed_ETC1_RGB8_texture
        case 0x8D64: return "GL_ETC1_RGB8_OES"; break;
        // GL_ARB_texture_compression_rgtc
        case 0x8DBB: return "GL_COMPRESSED_RED_RGTC1"; break;
        case 0x8DBC: return "GL_COMPRESSED_SIGNED_RED_RGTC1"; break;
        case 0x8DBD: return "GL_COMPRESSED_RG_RGTC2"; break;
        case 0x8DBE: return "GL_COMPRESSED_SIGNED_RG_RGTC2"; break;
        // GL_ARB_texture_compression_bptc
        case 0x8E8C: return "GL_COMPRESSED_RGBA_BPTC_UNORM_ARB"; break;
        case 0x8E8D: return "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB"; break;
        case 0x8E8E: return "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB"; break;
        case 0x8E8F: return "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB"; break;
        // GL_ARB_ES3_compatibility
        case 0x9274: return "GL_COMPRESSED_RGB8_ETC2"; break;
        case 0x9275: return "GL_COMPRESSED_SRGB8_ETC2"; break;
        case 0x9276: return "GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2"; break;
        case 0x9277: return "GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2"; break;
        case 0x9278: return "GL_COMPRESSED_RGBA8_ETC2_EAC"; break;
        case 0x9279: return "GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC"; break;
        case 0x9270: return "GL_COMPRESSED_R11_EAC"; break;
        case 0x9271: return "GL_COMPRESSED_SIGNED_R11_EAC"; break;
        case 0x9272: return "GL_COMPRESSED_RG11_EAC"; break;
        case 0x9273: return "GL_COMPRESSED_SIGNED_RG11_EAC"; break;
        // GL_KHR_texture_compression_astc_hdr
        case 0x93B0: return "GL_COMPRESSED_RGBA_ASTC_4x4_KHR"; break;
        case 0x93B1: return "GL_COMPRESSED_RGBA_ASTC_5x4_KHR"; break;
        case 0x93B2: return "GL_COMPRESSED_RGBA_ASTC_5x5_KHR"; break;
        case 0x93B3: return "GL_COMPRESSED_RGBA_ASTC_6x5_KHR"; break;
        case 0x93B4: return "GL_COMPRESSED_RGBA_ASTC_6x6_KHR"; break;
        case 0x93B5: return "GL_COMPRESSED_RGBA_ASTC_8x5_KHR"; break;
        case 0x93B6: return "GL_COMPRESSED_RGBA_ASTC_8x6_KHR"; break;
        case 0x93B7: return "GL_COMPRESSED_RGBA_ASTC_8x8_KHR"; break;
        case 0x93B8: return "GL_COMPRESSED_RGBA_ASTC_10x5_KHR"; break;
        case 0x93B9: return "GL_COMPRESSED_RGBA_ASTC_10x6_KHR"; break;
        case 0x93BA: return "GL_COMPRESSED_RGBA_ASTC_10x8_KHR"; break;
        case 0x93BB: return "GL_COMPRESSED_RGBA_ASTC_10x10_KHR"; break;
        case 0x93BC: return "GL_COMPRESSED_RGBA_ASTC_12x10_KHR"; break;
        case 0x93BD: return "GL_COMPRESSED_RGBA_ASTC_12x12_KHR"; break;
        case 0x93D0: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR"; break;
        case 0x93D1: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR"; break;
        case 0x93D2: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR"; break;
        case 0x93D3: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR"; break;
        case 0x93D4: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR"; break;
        case 0x93D5: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR"; break;
        case 0x93D6: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR"; break;
        case 0x93D7: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR"; break;
        case 0x93D8: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR"; break;
        case 0x93D9: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR"; break;
        case 0x93DA: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR"; break;
        case 0x93DB: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR"; break;
        case 0x93DC: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR"; break;
        case 0x93DD: return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR"; break;
        default: return "GL_COMPRESSED_UNKNOWN"; break;
    }
}
#endif  // gsrl_SHOW_GL_DETAILS_INFO

#endif  // GRAPHICS_API_OPENGL_33 || GRAPHICS_API_OPENGL_ES2

// Get pixel data size in bytes (image or texture)
// NOTE: Size depends on pixel format
static int gsrlGetPixelDataSize(int width, int height, int format)
{
    int dataSize = 0;       // Size in bytes
    int bpp = 0;            // Bits per pixel

    switch (format)
    {
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAYSCALE: bpp = 8; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA:
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G6B5:
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R5G5B5A1:
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R4G4B4A4: bpp = 16; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8: bpp = 32; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R8G8B8: bpp = 24; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32: bpp = 32; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32: bpp = 32*3; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R32G32B32A32: bpp = 32*4; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16: bpp = 16; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16: bpp = 16*3; break;
        case GSRL_PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: bpp = 16*4; break;
        case GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB:
        case GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGBA:
        case GSRL_PIXELFORMAT_COMPRESSED_ETC1_RGB:
        case GSRL_PIXELFORMAT_COMPRESSED_ETC2_RGB:
        case GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGB:
        case GSRL_PIXELFORMAT_COMPRESSED_PVRT_RGBA: bpp = 4; break;
        case GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA:
        case GSRL_PIXELFORMAT_COMPRESSED_DXT5_RGBA:
        case GSRL_PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA:
        case GSRL_PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA: bpp = 8; break;
        case GSRL_PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA: bpp = 2; break;
        default: break;
    }

    double bytesPerPixel = (double)bpp/8.0;
    dataSize = (int)(bytesPerPixel*width*height); // Total data size in bytes

    // Most compressed formats works on 4x4 blocks,
    // if texture is smaller, minimum dataSize is 8 or 16
    if ((width < 4) && (height < 4))
    {
        if ((format >= GSRL_PIXELFORMAT_COMPRESSED_DXT1_RGB) && (format < GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA)) dataSize = 8;
        else if ((format >= GSRL_PIXELFORMAT_COMPRESSED_DXT3_RGBA) && (format < GSRL_PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA)) dataSize = 16;
    }

    return dataSize;
}

// Auxiliar math functions

// Get float array of matrix data
static GSRL_float16 gsrlMatrixToFloatV(Matrix mat)
{
    GSRL_float16 result = { 0 };

    result.v[0] = mat.m0;
    result.v[1] = mat.m1;
    result.v[2] = mat.m2;
    result.v[3] = mat.m3;
    result.v[4] = mat.m4;
    result.v[5] = mat.m5;
    result.v[6] = mat.m6;
    result.v[7] = mat.m7;
    result.v[8] = mat.m8;
    result.v[9] = mat.m9;
    result.v[10] = mat.m10;
    result.v[11] = mat.m11;
    result.v[12] = mat.m12;
    result.v[13] = mat.m13;
    result.v[14] = mat.m14;
    result.v[15] = mat.m15;

    return result;
}

// Get identity matrix
static Matrix gsrlMatrixIdentity(void)
{
    Matrix result = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    return result;
}

// Get two matrix multiplication
// NOTE: When multiplying matrices... the order matters!
static Matrix gsrlMatrixMultiply(Matrix left, Matrix right)
{
    Matrix result = { 0 };

    result.m0 = left.m0*right.m0 + left.m1*right.m4 + left.m2*right.m8 + left.m3*right.m12;
    result.m1 = left.m0*right.m1 + left.m1*right.m5 + left.m2*right.m9 + left.m3*right.m13;
    result.m2 = left.m0*right.m2 + left.m1*right.m6 + left.m2*right.m10 + left.m3*right.m14;
    result.m3 = left.m0*right.m3 + left.m1*right.m7 + left.m2*right.m11 + left.m3*right.m15;
    result.m4 = left.m4*right.m0 + left.m5*right.m4 + left.m6*right.m8 + left.m7*right.m12;
    result.m5 = left.m4*right.m1 + left.m5*right.m5 + left.m6*right.m9 + left.m7*right.m13;
    result.m6 = left.m4*right.m2 + left.m5*right.m6 + left.m6*right.m10 + left.m7*right.m14;
    result.m7 = left.m4*right.m3 + left.m5*right.m7 + left.m6*right.m11 + left.m7*right.m15;
    result.m8 = left.m8*right.m0 + left.m9*right.m4 + left.m10*right.m8 + left.m11*right.m12;
    result.m9 = left.m8*right.m1 + left.m9*right.m5 + left.m10*right.m9 + left.m11*right.m13;
    result.m10 = left.m8*right.m2 + left.m9*right.m6 + left.m10*right.m10 + left.m11*right.m14;
    result.m11 = left.m8*right.m3 + left.m9*right.m7 + left.m10*right.m11 + left.m11*right.m15;
    result.m12 = left.m12*right.m0 + left.m13*right.m4 + left.m14*right.m8 + left.m15*right.m12;
    result.m13 = left.m12*right.m1 + left.m13*right.m5 + left.m14*right.m9 + left.m15*right.m13;
    result.m14 = left.m12*right.m2 + left.m13*right.m6 + left.m14*right.m10 + left.m15*right.m14;
    result.m15 = left.m12*right.m3 + left.m13*right.m7 + left.m14*right.m11 + left.m15*right.m15;

    return result;
}

// Transposes provided matrix
static Matrix gsrlMatrixTranspose(Matrix mat)
{
    Matrix result = { 0 };

    result.m0 = mat.m0;
    result.m1 = mat.m4;
    result.m2 = mat.m8;
    result.m3 = mat.m12;
    result.m4 = mat.m1;
    result.m5 = mat.m5;
    result.m6 = mat.m9;
    result.m7 = mat.m13;
    result.m8 = mat.m2;
    result.m9 = mat.m6;
    result.m10 = mat.m10;
    result.m11 = mat.m14;
    result.m12 = mat.m3;
    result.m13 = mat.m7;
    result.m14 = mat.m11;
    result.m15 = mat.m15;

    return result;
}

// Invert provided matrix
static Matrix gsrlMatrixInvert(Matrix mat)
{
    Matrix result = { 0 };

    // Cache the matrix values (speed optimization)
    float a00 = mat.m0, a01 = mat.m1, a02 = mat.m2, a03 = mat.m3;
    float a10 = mat.m4, a11 = mat.m5, a12 = mat.m6, a13 = mat.m7;
    float a20 = mat.m8, a21 = mat.m9, a22 = mat.m10, a23 = mat.m11;
    float a30 = mat.m12, a31 = mat.m13, a32 = mat.m14, a33 = mat.m15;

    float b00 = a00*a11 - a01*a10;
    float b01 = a00*a12 - a02*a10;
    float b02 = a00*a13 - a03*a10;
    float b03 = a01*a12 - a02*a11;
    float b04 = a01*a13 - a03*a11;
    float b05 = a02*a13 - a03*a12;
    float b06 = a20*a31 - a21*a30;
    float b07 = a20*a32 - a22*a30;
    float b08 = a20*a33 - a23*a30;
    float b09 = a21*a32 - a22*a31;
    float b10 = a21*a33 - a23*a31;
    float b11 = a22*a33 - a23*a32;

    // Calculate the invert determinant (inlined to avoid double-caching)
    float invDet = 1.0f/(b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06);

    result.m0 = (a11*b11 - a12*b10 + a13*b09)*invDet;
    result.m1 = (-a01*b11 + a02*b10 - a03*b09)*invDet;
    result.m2 = (a31*b05 - a32*b04 + a33*b03)*invDet;
    result.m3 = (-a21*b05 + a22*b04 - a23*b03)*invDet;
    result.m4 = (-a10*b11 + a12*b08 - a13*b07)*invDet;
    result.m5 = (a00*b11 - a02*b08 + a03*b07)*invDet;
    result.m6 = (-a30*b05 + a32*b02 - a33*b01)*invDet;
    result.m7 = (a20*b05 - a22*b02 + a23*b01)*invDet;
    result.m8 = (a10*b10 - a11*b08 + a13*b06)*invDet;
    result.m9 = (-a00*b10 + a01*b08 - a03*b06)*invDet;
    result.m10 = (a30*b04 - a31*b02 + a33*b00)*invDet;
    result.m11 = (-a20*b04 + a21*b02 - a23*b00)*invDet;
    result.m12 = (-a10*b09 + a11*b07 - a12*b06)*invDet;
    result.m13 = (a00*b09 - a01*b07 + a02*b06)*invDet;
    result.m14 = (-a30*b03 + a31*b01 - a32*b00)*invDet;
    result.m15 = (a20*b03 - a21*b01 + a22*b00)*invDet;

    return result;
}

#endif  // GSRL_IMPLEMENTATION
