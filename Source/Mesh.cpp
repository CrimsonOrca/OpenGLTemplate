#include "Mesh.h"

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