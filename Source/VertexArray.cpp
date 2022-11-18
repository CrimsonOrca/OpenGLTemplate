#include "VertexArray.h"

VertexArray::VertexArray()
	: _ID {0}
{
	glGenVertexArrays(1, &_ID);
	glBindVertexArray(_ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &_ID);
}

void VertexArray::Bind()
{
	glBindVertexArray(_ID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

GLuint VertexArray::GetID() const
{
	return _ID;
}