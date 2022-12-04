#include "Renderer.h"

Renderer::Renderer()
	: mMesh {nullptr}
{

}

Renderer::~Renderer()
{
	if (mMesh)
		mMesh = nullptr;
}

void Renderer::SetMesh(Mesh& mesh)
{
	mMesh = &mesh;
	mVertexArray.Bind();
	mVertexBuffer.SetVertices(mMesh->GetVertices());
	mIndexBuffer.SetIndices(mMesh->GetIndices());
	mVertexArray.Unbind();
}

void Renderer::Draw()
{
	mVertexArray.Bind();
	glDrawElements(GL_TRIANGLES, mMesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
	mVertexArray.Unbind();
}