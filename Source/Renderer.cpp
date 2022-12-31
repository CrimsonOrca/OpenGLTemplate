#include "Renderer.h"

Renderer::Renderer()
	: mVertexArrays {}
	, mVertexBuffers {}
	, mIndexBuffers {}
	, mMeshes {}
	, mCache {}
	, mMeshCount{}
{

}

void Renderer::DrawWireFrame()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::StoreMesh(std::string name, std::unique_ptr<Mesh>&& mesh)
{
	if (!mCache.contains(name))
	{
		mCache.emplace(name, mMeshCount);

		mMeshes.push_back(std::move(mesh));

		mVertexArrays.push_back(std::make_unique<VertexArray>());
		mVertexBuffers.push_back(std::make_unique<VertexBuffer>());
		mIndexBuffers.push_back(std::make_unique<IndexBuffer>());

		mVertexArrays.at(mMeshCount)->Bind();

		mVertexBuffers.at(mMeshCount)->SetVertices(mMeshes.at(mMeshCount)->GetVertices());

		if (mMeshes.at(mMeshCount)->GetIndexCount())
			mIndexBuffers.at(mMeshCount)->SetIndices(mMeshes.at(mMeshCount)->GetIndices());

		mVertexArrays.at(mMeshCount)->Unbind();

		mMeshCount++;
	}
}

void Renderer::Draw(std::string name)
{
	if (mCache.contains(name))
	{
		std::size_t index {mCache.at(name)};

		mVertexArrays.at(index)->Bind();

		mMeshes.at(index)->Draw();

		mVertexArrays.at(index)->Unbind();
	}
	else
		std::cout << "'" << name << "' MESH NAME/NUMBER NOT FOUND\n";
}

void Renderer::ClearScreen()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Renderer::EnableDepthTesting()
{
	glEnable(GL_DEPTH_TEST);
}