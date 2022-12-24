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

struct SpotLight
{
	Light light;
	vec3 position;
	vec3 direction;
	float cutoff;
	float outerCutoff;
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
uniform SpotLight uSpotLight;

#define NUMBER_POINT_LIGHTS 4
uniform PointLight uPointLights[NUMBER_POINT_LIGHTS];

out vec4 oFragmentColor;

vec3 CalcDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragmentPosition, vec3 viewDirection);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragmentPosition, vec3 viewDirection);

void main()
{
	vec3 normal = normalize(iNormal);
	vec3 viewDirection = normalize(uViewPosition - iFragmentPosition);
	vec3 result = vec3(0.0f, 0.0f, 0.0f);
	
	//result = CalcDirectionalLight(uDirectionalLight, normal, viewDirection);

	for (int i = 0; i < NUMBER_POINT_LIGHTS; i++)
	{
		result += CalcPointLight(uPointLights[i], normal, iFragmentPosition, viewDirection);
	}

	 //result += CalcSpotLight(uSpotLight, normal, fragmentPosition, viewDirection);

	oFragmentColor = vec4(result, 1.0f);
}

vec3 CalcDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection)
{
	vec3 lightDirection = normalize(-1.0f * light.direction);

	vec3 ambient = vec3(texture(uMaterial.diffuse, iTextureCoordinate)) * light.light.ambient;

	float diffuseStrength = max(dot(normal, lightDirection), 0.0f);
	vec3 diffuse =  light.light.diffuse * diffuseStrength * vec3(texture(uMaterial.diffuse, iTextureCoordinate));

	vec3 reflectDirection  = reflect(-lightDirection, normal);
	float specularStrength = pow(max(dot(viewDirection, reflectDirection), 0.0f), uMaterial.shininess);
	vec3 specular          = light.light.specular * vec3(texture(uMaterial.specular, iTextureCoordinate)) * specularStrength;

	return (ambient + diffuse + specular);	
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragmentPosition, vec3 viewDirection)
{
	vec3 lightDirection = normalize(light.position - fragmentPosition);

	vec3 ambient = vec3(texture(uMaterial.diffuse, iTextureCoordinate)) * light.light.ambient;

	float diffuseStrength = max(dot(normal, lightDirection), 0.0f);
	vec3 diffuse          =  light.light.diffuse * diffuseStrength * vec3(texture(uMaterial.diffuse, iTextureCoordinate));

	vec3 reflectDirection  = reflect(-lightDirection, normal);
	float specularStrength = pow(max(dot(viewDirection, reflectDirection), 0.0f), uMaterial.shininess);
	vec3 specular          = light.light.specular * vec3(texture(uMaterial.specular, iTextureCoordinate)) * specularStrength;

	float distance    = length(light.position - fragmentPosition);
	float attenuation = 1.0f / ( light.constant + light.linear * distance + light.quadratic * (distance * distance) );

	ambient  *= attenuation;
	diffuse  *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular);		
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragmentPosition, vec3 viewDirection)
{
	vec3 lightPosition  = light.position;
	vec3 lightDirection = normalize(lightPosition - fragmentPosition); /* from fragment to spotlight */

	float theta     = dot(lightDirection, normalize(-1.0f * light.direction));
	float epsilon   = light.cutoff - light.outerCutoff;
	float intensity = clamp((theta - light.outerCutoff) / epsilon, 0.0f, 1.0f);

	/*
	
	...

	*/

	return vec3(0.0f);
}