#version 430 core

in vec3 oFragmentPosition;
in vec3 oNormal;
in vec2 oTextureCoordinate;

vec3 iFragmentPosition = oFragmentPosition;
vec3 iNormal = normalize(oNormal);
vec2 iTextureCoordinate = oTextureCoordinate;

layout (binding = 0) uniform sampler2D meshTexture;

float near = 0.1;
float far = 100.0;

float LinearizeDepth(float depth) 
{
	float z = depth * 2.0 - 1.0;
	return (2.0 * near * far) / (far + near - z * (far - near));
}

out vec4 oFragmentColor;

void main()
{
    oFragmentColor = texture(meshTexture, iTextureCoordinate);

	// float depth = LinearizeDepth(gl_FragCoord.z) / far;
	// oFragmentColor = vec4(vec3(depth), 1.0);
}