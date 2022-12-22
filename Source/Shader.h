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

//struct Material
//{
//	glm::vec3 ambient;
//	glm::vec3 diffuse;
//	glm::vec3 specular;
//	float shininess;
//};
//
//const Material emerald = {
//	glm::vec3(0.0215f, 0.1745f, 0.0215f),
//	glm::vec3(0.07568f, 0.61424f, 0.07568f),
//	glm::vec3(0.633f, 0.727811f, 0.633f),
//	0.6f
//};

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
		/*void SetMaterial(std::string name, const Material value);*/
	private:
		GLuint _ID;
		GLuint _vertexID;
		GLuint _fragmentID;
};




#endif _SHADER_H_ 