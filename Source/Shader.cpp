#include "Shader.h"

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	std::string vertexSource = ReadShader(vertexShaderPath);
	std::string fragmentSource = ReadShader(fragmentShaderPath);

	CompileShader(vertexSource, GL_VERTEX_SHADER);
	CompileShader(fragmentSource, GL_FRAGMENT_SHADER);

	LinkShaders();
}

std::string Shader::ReadShader(std::string shaderPath)
{
	std::string shaderString;

	std::ifstream shaderFileStream;
	shaderFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		shaderFileStream.open(shaderPath);

		std::stringstream shaderStringStream;
		shaderStringStream << shaderFileStream.rdbuf();

		shaderFileStream.close();

		shaderString = shaderStringStream.str();
	}
	catch (std::ifstream::failure exc)
	{
		std::cout << "ERROR: " << shaderPath << " NOT SUCCESSFULLY READ" << std::endl;
	}

	return shaderString;
}

void Shader::CompileShader(std::string shaderString, GLenum shaderType)
{
	switch (shaderType)
	{
		case GL_VERTEX_SHADER:
			CompileVertexShader(shaderString);
			break;
		case GL_FRAGMENT_SHADER:
			CompileFragmentShader(shaderString);
			break;
		default:
			std::cout << "..." << std::endl;
	}
}

void Shader::CompileVertexShader(std::string vertexShaderString)
{
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertexShaderSource = vertexShaderString.c_str();
	glShaderSource(_vertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(_vertexShaderID);
}

void Shader::CompileFragmentShader(std::string fragmentShaderString)
{
	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragmentShaderSource = fragmentShaderString.c_str();
	glShaderSource(_fragmentShaderID, 1, &fragmentShaderSource, NULL);
	glCompileShader(_fragmentShaderID);
	CheckCompileStatus(_fragmentShaderID);
}

void Shader::CheckCompileStatus(GLuint shaderID)
{
	GLint success;
	GLchar message[512];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shaderID, 512, NULL, message);
		std::cout << "ERROR - SHADER COMPILATION FAILED\n" << message << std::endl;
	}
}

void Shader::LinkShaders()
{
	_shaderProgramID = glCreateProgram();

	glAttachShader(_shaderProgramID, _vertexShaderID);
	glAttachShader(_shaderProgramID, _fragmentShaderID);
	
	glLinkProgram(_shaderProgramID);
	CheckLinkStatus();

	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void Shader::CheckLinkStatus()
{
	GLint success;
	GLchar message[512];

	glGetProgramiv(_shaderProgramID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(_shaderProgramID, 512, NULL, message);
		std::cout << "ERROR - SHADER PROGRAM LINKING FAILED\n" << message << std::endl;
	}
}

void Shader::UseShader()
{
	glUseProgram(_shaderProgramID);
}