#ifndef _SHADER_STORAGE_BUFFER_H_
#define _SHADER_STORAGE_BUFFER_H_

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class ShaderStorageBuffer
{
public:
	ShaderStorageBuffer(GLuint shaderProgramID, const char* blockName, GLuint blockBinding, GLsizeiptr bufferSize);
	~ShaderStorageBuffer();
	void Bind();
	void Unbind();
	void UpdateData(GLintptr offset, GLsizeiptr size, const GLvoid* data);
private:
	GLuint mID;
};

#endif // !_SHADER_STORAGE_BUFFER_H_