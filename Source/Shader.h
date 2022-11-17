#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shader
{
public:
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
	std::string ReadShader(std::string shaderPath);
	void CompileShader(std::string shaderString, GLenum shaderType);
	void CompileVertexShader(std::string shaderString);
	void CompileFragmentShader(std::string shaderString);
	void CheckCompileStatus(GLuint shaderID);
	void LinkShaders();
	void CheckLinkStatus();

	void UseShader();

private:
	GLuint _shaderProgramID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};

#endif _SHADER_H_ // !_SHADER_H_