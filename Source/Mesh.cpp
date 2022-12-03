#include "Mesh.h"

Mesh::~Mesh() 
{

}

void Mesh::Setup()
{
	mVertexArray.Bind();
	mVertexBuffer.SetVertices(mVertices);
	mIndexBuffer.SetIndices(mIndices);
	mVertexArray.Unbind();
}