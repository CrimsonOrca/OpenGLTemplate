#version 430 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTextureCoordinate;

uniform mat4 uModel;
uniform mat4 uProjection;
uniform mat4 uView;

out vec3 oNormal;
out vec3 oFragmentPosition;

void main()
{
	gl_Position = uProjection * uView * uModel * vec4(aPosition, 1.0f);
	oNormal = mat3(transpose(inverse(uModel))) * aNormal;
	oFragmentPosition = vec3(uModel * vec4(aPosition, 1.0f));
}