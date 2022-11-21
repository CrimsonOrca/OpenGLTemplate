#include "Mesh.h"

Mesh::Mesh()
	: _vertices     {}
	, _indices      {}
	, _vertexArray  {}
	, _vertexBuffer {}
	, _indexBuffer  {}
{
	/*
		Generate mesh vertices and indices via custom alorithm...
		Send mesh data to GPU...
		DerivedClass::GenerateVertices();
		DerivedClass::GenerateIndices();
		Mesh::Create();
	*/
}

Mesh::~Mesh() 
{

}

void Mesh::Create()
{
	_vertexArray.Bind();
	_vertexBuffer.SetVertices(_vertices);
	_indexBuffer.SetIndices(_indices);
	_vertexArray.Unbind();
}

void Mesh::Render()
{
	_vertexArray.Bind();
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
	_vertexArray.Unbind();
}

void Mesh::SetVertices(std::vector<Vertex> vertices)
{
	_vertices = vertices;
}

void Mesh::SetIndices(std::vector<GLuint> indices)
{
	_indices = indices;
}