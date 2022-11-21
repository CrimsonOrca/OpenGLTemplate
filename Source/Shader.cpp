#include "Shader.h"

Shader::Shader(std::string vertexPath, std::string fragmentPath)
	: _ID         {glCreateProgram()}
	, _vertexID   {glCreateShader(GL_VERTEX_SHADER)}
	, _fragmentID {glCreateShader(GL_FRAGMENT_SHADER)}
{
	std::string vertexSource   {Read(vertexPath)};
	std::string fragmentSource {Read(fragmentPath)};

	Compile(_vertexID, vertexSource);
	Compile(_fragmentID, fragmentSource);
	Link();
}

std::string Shader::Read(std::string shaderPath)
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

void Shader::Compile(GLuint& shaderID, const std::string& shaderString)
{
	const GLchar* shaderSource = shaderString.c_str();
	glShaderSource(shaderID, 1, &shaderSource, NULL);
	glCompileShader(shaderID);
	CheckCompileStatus(shaderID);
}

void Shader::CheckCompileStatus(GLuint& shaderID)
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

void Shader::Attach(GLuint& shaderID)
{
	if (shaderID != 0)
		glAttachShader(_ID, shaderID);
}

void Shader::Link()
{
	Attach(_vertexID);
	Attach(_fragmentID);

	glLinkProgram(_ID);
	CheckLinkStatus();

	Detach(_vertexID);
	Detach(_fragmentID);

	Delete(_vertexID);
	Delete(_fragmentID);
}

void Shader::CheckLinkStatus()
{
	GLint success;
	GLchar message[512];

	glGetProgramiv(_ID, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(_ID, 512, NULL, message);
		std::cout << "ERROR - SHADER PROGRAM LINKING FAILED\n" << message << std::endl;
	}
}

void Shader::Detach(GLuint& shaderID)
{
	if (shaderID != 0)
		glDetachShader(_ID, shaderID);
}

void Shader::Delete(GLuint& shaderID)
{
	if (shaderID != 0)
		glDeleteShader(shaderID);
}

void Shader::Use()
{
	glUseProgram(_ID);
}

GLuint Shader::GetID() const
{
	return _ID;
}

void Shader::SetInt(std::string name, int value)
{
	glUniform1f(glGetUniformLocation(_ID, name.c_str()), value);
}

void Shader::SetFloat(std::string name, float value)
{
	glUniform1f(glGetUniformLocation(_ID, name.c_str()), value);
}

void Shader::SetVector(std::string name, const glm::vec3& value)
{
	glUniform3fv(glGetUniformLocation(_ID, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::SetMatrix(std::string name, const glm::mat4& value)
{
	glUniformMatrix4fv(glGetUniformLocation(_ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}