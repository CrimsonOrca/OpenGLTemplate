#version 430 core

struct Material
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct Light 
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct DirectionalLight
{
	Light light;
	vec3 direction;
};

struct PointLight
{
	Light light;
	vec3 position;
	float constant;
	float linear;
	float quadratic;
};

in vec3 oFragmentPosition;
in vec3 oNormal;
in vec2 oTextureCoordinate;
vec3 iFragmentPosition = oFragmentPosition;
vec3 iNormal = oNormal;
vec2 iTextureCoordinate = oTextureCoordinate;

uniform vec3 uViewPosition;
uniform Material uMaterial;
uniform DirectionalLight uDirectionalLight;
uniform PointLight uPointLight;

out vec4 oFragmentColor;

void applyDirectionalLight();
void applyPointLight();

void main()
{
	//applyDirectionalLight();
	applyPointLight();
}

void applyDirectionalLight()
{
	vec3 lightColor     = vec3(1.0f, 1.0f, 1.0f);
	vec3 lightPosition  = vec3(5.0f, 5.0f, 5.0f);
	vec3 normal         = normalize(iNormal);
	vec3 lightDirection = normalize(-1.0f * uDirectionalLight.direction);

	vec3 ambient = vec3(texture(uMaterial.diffuse, iTextureCoordinate)) * uDirectionalLight.light.ambient;

	vec3 diffuse =  uDirectionalLight.light.diffuse * max(dot(normal, lightDirection), 0.0f) * vec3(texture(uMaterial.diffuse, iTextureCoordinate));

	vec3 viewDirection     = normalize(uViewPosition - iFragmentPosition);
	vec3 reflectDirection  = reflect(-lightDirection, normal);
	vec3 specular          = uDirectionalLight.light.specular * vec3(texture(uMaterial.specular, iTextureCoordinate)) * 
	                         pow(max(dot(viewDirection, reflectDirection), 0.0f), uMaterial.shininess);

	oFragmentColor = vec4(ambient + diffuse + specular, 1.0f);
}

void applyPointLight()
{
	vec3 lightColor     = vec3(1.0f, 1.0f, 1.0f);
	vec3 lightPosition  = uPointLight.position;
	vec3 normal         = normalize(iNormal);
	vec3 lightDirection = normalize(lightPosition - iFragmentPosition);

	vec3 ambient = vec3(texture(uMaterial.diffuse, iTextureCoordinate)) * uPointLight.light.ambient;

	vec3 diffuse =  uPointLight.light.diffuse * max(dot(normal, lightDirection), 0.0f) * vec3(texture(uMaterial.diffuse, iTextureCoordinate));

	vec3 viewDirection     = normalize(uViewPosition - iFragmentPosition);
	vec3 reflectDirection  = reflect(-lightDirection, normal);
	vec3 specular          = uPointLight.light.specular * vec3(texture(uMaterial.specular, iTextureCoordinate)) * 
	                         pow(max(dot(viewDirection, reflectDirection), 0.0f), uMaterial.shininess);

	float distance = length(uPointLight.position - iFragmentPosition);
	float attenuation = 1.0f / ( uPointLight.constant + uPointLight.linear * distance + uPointLight.quadratic * (distance * distance) );

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	oFragmentColor = vec4(ambient + diffuse + specular, 1.0f);	

}