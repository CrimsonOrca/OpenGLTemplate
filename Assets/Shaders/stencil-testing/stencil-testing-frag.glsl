#version 430 core

in vec2 oTextureCoordinate;

vec2 iTextureCoordinate = oTextureCoordinate;

layout (binding = 0) uniform sampler2D meshTexture;

out vec4 oFragmentColor;

void main()
{
    oFragmentColor = texture(meshTexture, iTextureCoordinate);
}