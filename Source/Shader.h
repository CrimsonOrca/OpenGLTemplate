#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Shader
{
	public:
		Shader(std::string vertexPath, std::string fragmentPath);
		std::string Read(std::string shaderPath);
		void Compile(GLuint& shaderID, const std::string& shaderString);
		void CheckCompileStatus(GLuint& shaderID);
		void Attach(GLuint& shaderID);
		void Link();
		void CheckLinkStatus();
		void Delete(GLuint& shaderID);
		void Detach(GLuint& shaderID);
		void Use();
		GLuint GetID() const;
		void SetInt(std::string uniform, int value);
		void SetFloat(std::string uniform, float value);
		void SetMatrix(std::string uniform, const glm::mat4& value);
		void SetVector(std::string uniform, const glm::vec3& value);
	private:
		GLuint _ID;
		GLuint _vertexID;
		GLuint _fragmentID;
		std::unordered_map<std::string, GLint> mCache;
};

#endif _SHADER_H_ 