#include "Renderer.h"

Renderer::Renderer()
	: mMeshCount {0}
{

}

Renderer::~Renderer()
{
	
}

void Renderer::DrawWireFrame()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::Draw(std::string name)
{
	if (mCache.find(name) != mCache.end())
	{
		mVertexArrays.at(mCache.at(name))->Bind();

		if (mMeshes.at(mCache.at(name))->GetIndexCount())
			glDrawElements(GL_TRIANGLES, mMeshes.at(mCache.at(name))->GetIndexCount(), GL_UNSIGNED_INT, 0);
		else
			glDrawArrays(GL_TRIANGLES, 0, mMeshes.at(mCache.at(name))->GetVertexCount());

		mVertexArrays.at(mCache.at(name))->Unbind();
	}
	else
		std::cout << "'" << name << "' MESH NAME/NUMBER NOT FOUND\n";
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