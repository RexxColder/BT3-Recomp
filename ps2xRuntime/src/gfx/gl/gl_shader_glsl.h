#pragma once

// [altGL] GLSL for the altGL layer. Attribute locations match gfx::gl::Vertex:
//   0 = position (vec2), 1 = uv (vec2), 2 = colour (vec4, unorm8), 3 = q (float), 4 = z (float).
// The GS shader (the full PS2 modulate/CLUT/alpha-test port) is added when the renderer is
// migrated; this header currently carries the blit used by the altGL probe/validation.

namespace ps2x::gfx { namespace gl
{
    inline const char *kGlBlitVertexShader = R"GLSL(
#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aUV;
layout (location = 2) in vec4 aCol;
layout (location = 3) in float aQ;
layout (location = 4) in float aZ;
uniform mat4 mvp;
out vec2 vUV;
out vec4 vCol;
void main()
{
    vUV = aUV;
    vCol = aCol;
    gl_Position = mvp * vec4(aPos, 0.0, 1.0);
}
)GLSL";

    inline const char *kGlBlitFragmentShader = R"GLSL(
#version 330 core
in vec2 vUV;
in vec4 vCol;
uniform sampler2D texture0;
out vec4 FragColor;
void main()
{
    FragColor = texture(texture0, vUV) * vCol;
}
)GLSL";
} }
