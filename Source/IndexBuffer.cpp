#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
	: _ID{ 0 }
	, _indices{ }
{
	glGenBuffers(1, &_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
}

IndexBuffer::IndexBuffer(std::vector<GLuint> indices)
	: _ID{ 0 }
	, _indices{ indices }
{
	glGenBuffers(1, &_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), &_indices.at(0), GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_ID);
}

void IndexBuffer::SetIndices(std::vector<GLuint> indices)
{
	_indices = indices;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), &_indices.at(0), GL_STATIC_DRAW);
}