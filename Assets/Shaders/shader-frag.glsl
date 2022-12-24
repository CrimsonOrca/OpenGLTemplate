#version 430 core

in vec3 oFragmentPosition;
in vec3 oNormal;

out vec4 oFragmentColor;

void main()
{
	oFragmentColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
}