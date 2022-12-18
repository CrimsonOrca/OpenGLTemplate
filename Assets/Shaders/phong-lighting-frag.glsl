#version 430 core

in vec3 oFragmentPosition;
in vec3 oNormal;

uniform vec3 uViewPosition;

out vec4 oFragmentColor;

void main()
{
	vec3 objectColor    = vec3(1.0f, 0.45f, 0.0f);
	vec3 lightColor     = vec3(1.0f, 1.0f, 1.0f);
	vec3 lightPosition  = vec3(2.5f, 2.5f, 2.5f);
	vec3 normal         = normalize(oNormal);
	vec3 lightDirection = normalize(lightPosition - oFragmentPosition);

	float ambientStrength = 0.1f;
	vec3 ambient          = ambientStrength * lightColor;

	vec3 diffuse = max(dot(normal, lightDirection), 0.0f) * lightColor;

	float specularStrength = 0.5f;
	vec3 viewDirection     = normalize(uViewPosition - oFragmentPosition);
	vec3 reflectDirection  = reflect(-lightDirection, normal);
	vec3 specular          = specularStrength * pow(max(dot(viewDirection, reflectDirection), 0.0f), 32.0f) * lightColor;

	vec3 result    = (ambient + diffuse + specular) * objectColor;
	oFragmentColor = vec4(result, 1.0f);
}