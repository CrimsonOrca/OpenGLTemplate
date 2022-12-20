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
