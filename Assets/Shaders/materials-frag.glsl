#version 430 core

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Light 
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 oFragmentPosition;
in vec3 oNormal;
vec3 iFragmentPosition = oFragmentPosition;
vec3 iNormal = oNormal;

uniform vec3 uViewPosition;
uniform Material uMaterial;
uniform Light uLight;

out vec4 oFragmentColor;

void main()
{
	vec3 lightColor     = vec3(1.0f, 1.0f, 1.0f);
	vec3 lightPosition  = vec3(5.0f, 5.0f, 5.0f);
	vec3 normal         = normalize(iNormal);
	vec3 lightDirection = normalize(lightPosition - iFragmentPosition);

	vec3 ambient = uMaterial.ambient * uLight.ambient;

	vec3 diffuse =  uLight.diffuse * (max(dot(normal, lightDirection), 0.0f) * uMaterial.diffuse);

	vec3 viewDirection     = normalize(uViewPosition - iFragmentPosition);
	vec3 reflectDirection  = reflect(-lightDirection, normal);
	vec3 specular          = uLight.specular * (uMaterial.specular * pow(max(dot(viewDirection, reflectDirection), 0.0f), uMaterial.shininess));

	vec3 result    = (ambient + diffuse + specular);
	oFragmentColor = vec4(result, 1.0f);
}