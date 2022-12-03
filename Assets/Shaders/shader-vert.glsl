#version 430 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTextureCoordinate;

uniform mat4 uModel;
uniform mat4 uProjection;
uniform mat4 uView;

out vec2 oTextureCoordinate;

void main()
{
	gl_Position = uProjection * uView * uModel * vec4(aPosition, 1.0f);
	oTextureCoordinate = aTextureCoordinate;
}