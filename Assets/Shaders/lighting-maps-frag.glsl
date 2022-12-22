#version 430 core

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
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
in vec2 oTextureCoordinate;
vec3 iFragmentPosition = oFragmentPosition;
vec3 iNormal = oNormal;
vec2 iTextureCoordinate = oTextureCoordinate;

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

	vec3 ambient = vec3(texture(uMaterial.diffuse, iTextureCoordinate)) * uLight.ambient;

	vec3 diffuse =  uLight.diffuse * max(dot(normal, lightDirection), 0.0f) * vec3(texture(uMaterial.diffuse, iTextureCoordinate));

	vec3 viewDirection     = normalize(uViewPosition - iFragmentPosition);
	vec3 reflectDirection  = reflect(-lightDirection, normal);
	vec3 specular          = uLight.specular * vec3(texture(uMaterial.specular, iTextureCoordinate)) * 
	                         pow(max(dot(viewDirection, reflectDirection), 0.0f), uMaterial.shininess);

	oFragmentColor = vec4(ambient + diffuse + specular, 1.0f);
}