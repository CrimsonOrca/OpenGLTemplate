#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	
}

void Renderer::DrawWireFrame()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::Draw()
{
	mVertexArray.Bind();

	if (mMesh->GetIndexCount())
		glDrawElements(GL_TRIANGLES, mMesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, mMesh->GetVertexCount());

	mVertexArray.Unbind();
}

void Renderer::ClearScreen()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::EnableDepthTesting()
{
	glEnable(GL_DEPTH_TEST);
}