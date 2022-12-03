#version 430 core

in vec2 oTextureCoordinate;

layout (binding = 0) uniform sampler2D uWoodContainer;
layout (binding = 1) uniform sampler2D uAwesomeFace;

out vec4 oFragmentColor;

void main()
{
	oFragmentColor = texture(uAwesomeFace, oTextureCoordinate);
}