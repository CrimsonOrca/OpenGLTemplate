#version 430 core

in vec2 textureCoordinate;

layout (binding = 0) uniform sampler2D woodContainer;
layout (binding = 1) uniform sampler2D awesomeFace;

out vec4 fragmentColor;

void main()
{
	fragmentColor = texture(awesomeFace, textureCoordinate);
}