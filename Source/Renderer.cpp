#include "Renderer.h"

Renderer::Renderer()
	: mMesh {nullptr}
{

}

Renderer::~Renderer()
{
	
}

void Renderer::ShowWireFrame()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::Draw()
{
	mVertexArray.Bind();
	glDrawElements(GL_TRIANGLES, mMesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
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