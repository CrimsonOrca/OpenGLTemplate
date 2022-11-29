#include "ShaderStorageBuffer.h"

ShaderStorageBuffer::ShaderStorageBuffer(GLuint shaderProgramID, const char* blockName, GLuint blockBinding, GLsizeiptr bufferSize)
	: mID {0}
{
	glShaderStorageBlockBinding(shaderProgramID, glGetProgramResourceIndex(shaderProgramID, GL_SHADER_STORAGE_BLOCK, blockName), blockBinding);
	glGenBuffers(1, &mID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, mID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, blockBinding, mID);
}

ShaderStorageBuffer::~ShaderStorageBuffer()
{
	glDeleteBuffers(1, &mID);
}

void ShaderStorageBuffer::UpdateData(GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, mID);
	glBufferSubData(GL_SHADER_STORAGE_BUFFER, offset, size, data);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void ShaderStorageBuffer::Bind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, mID);
}

void ShaderStorageBuffer::Unbind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}