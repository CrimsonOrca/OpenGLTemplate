#include "Mesh.h"

Mesh::Mesh()
	: _vertices     {}
	, _indices      {}
	, _vertexArray  {}
	, _vertexBuffer {}
	, _indexBuffer  {}
{

}

Mesh::~Mesh() 
{

}

void Mesh::CreateMesh()
{
	_vertexArray.Bind();
	_vertexBuffer.SetVertices(_vertices);
	_indexBuffer.SetIndices(_indices);
	_vertexArray.Unbind();
}

void Mesh::RenderMesh()
{
	_vertexArray.Bind();
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
	_vertexArray.Unbind();
}

void Mesh::DeleteMesh()
{

}

void Mesh::SetVertices(std::vector<Vertex> vertices)
{
	_vertices = vertices;
}

void Mesh::SetIndices(std::vector<GLuint> indices)
{
	_indices = indices;
}

void Mesh::GenerateVertices()
{

}

void Mesh::GenerateIndices()
{

}