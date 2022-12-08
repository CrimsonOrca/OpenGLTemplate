#include "Mesh.h"

Mesh::~Mesh() 
{

}

std::vector<Vertex> Mesh::GetVertices() const 
{ 
	return mVertices; 
}

std::vector<GLuint> Mesh::GetIndices() const 
{ 
	return mIndices; 
}

GLuint Mesh::GetVertexCount() const
{ 
	return mVertexCount; 
}

GLuint Mesh::GetIndexCount() const
{ 
	return mIndexCount; 
}

void Mesh::InsertVertex(const Vertex& vertex)
{
	mVertices.push_back(vertex);
}

void Mesh::InsertIndex(const GLuint& index)
{
	mIndices.push_back(index);
}

void Mesh::InsertTriangleIndices(const GLuint& i, const GLuint& j, const GLuint& k)
{
	InsertIndex(i);
	InsertIndex(j);
	InsertIndex(k);
}