#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>

class Shader
{
public:
	Shader(std::string vertexPath, std::string fragmentPath);
	std::string Read(std::string shaderFile);
	void Compile(std::string shaderSource);
	void Link();
private:
	unsigned int _programReference;
	unsigned int _shaderReference;
};

#endif _SHADER_H_