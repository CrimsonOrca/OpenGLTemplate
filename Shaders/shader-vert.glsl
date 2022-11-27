#version 420 core

layout (location = 0) in vec3 a_position;
layout (location = 1) in vec3 a_normal;
layout (location = 2) in vec2 a_textureCoordinate;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

out vec2 textureCoordinate;

void main()
{
	gl_Position = projection * view * model * vec4(a_position, 1.0f);
	textureCoordinate = a_textureCoordinate;
}