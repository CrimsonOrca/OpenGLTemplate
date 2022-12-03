#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
	: _ID       {0}
	, _vertices { }
{
	glGenBuffers(1, &_ID);
	glBindBuffer(GL_ARRAY_BUFFER, _ID);
}

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices)
	: _ID       {0}
	, _vertices {vertices}
{
	glGenBuffers(1, &_ID);
	glBindBuffer(GL_ARRAY_BUFFER, _ID);
	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * VERTEX_OFFSET, &_vertices[0], GL_STATIC_DRAW);

	SpecifyBufferLayout(POSITION_INDEX, NUM_COMP_PER_POSITION, POSITION_OFFSET);

	SpecifyBufferLayout(NORMAL_INDEX, NUM_COMP_PER_NORMAL, NORMAL_OFFSET);

	SpecifyBufferLayout(TEXTURE_COORDINATE_INDEX, NUM_COMP_PER_TEXTURE_COORDINATE, TEXTURE_COORDINATE_OFFSET);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_ID);
}

void VertexBuffer::SetVertices(std::vector<Vertex> vertices)
{
	_vertices = vertices;

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

	SpecifyBufferLayout(POSITION_INDEX, NUM_COMP_PER_POSITION, POSITION_OFFSET);

	SpecifyBufferLayout(NORMAL_INDEX, NUM_COMP_PER_NORMAL, NORMAL_OFFSET);

	SpecifyBufferLayout(TEXTURE_COORDINATE_INDEX, NUM_COMP_PER_TEXTURE_COORDINATE, TEXTURE_COORDINATE_OFFSET);
}

void VertexBuffer::SpecifyBufferLayout(GLuint index, GLuint size, void* offset)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, VERTEX_OFFSET, offset);
}



