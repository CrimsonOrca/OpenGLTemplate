#version 420 core

layout (location = 0) in vec3 a_position;
layout (location = 1) in vec3 a_normal;
layout (location = 2) in vec2 a_textureCoordinate;

uniform mat4 transform;

out vec2 textureCoordinate;

void main()
{
	gl_Position = transform * vec4(a_position, 1.0f);
	textureCoordinate = a_textureCoordinate;
}