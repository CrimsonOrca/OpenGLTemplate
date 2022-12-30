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

void Renderer::StoreMesh(std::string name, std::shared_ptr<Mesh> mesh)
{
	mCache.emplace(name, mMeshCount);

	mMeshes.push_back(mesh);

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

void Renderer::Draw(std::string name)
{
	if (mCache.contains(name))
	{
		auto index {mCache.at(name)};

		mVertexArrays.at(index)->Bind();

		auto mesh { mMeshes.at(index) };

		if (mesh->GetIndexCount())
			glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
		else
			glDrawArrays(GL_TRIANGLES, 0, mesh->GetVertexCount());

		mVertexArrays.at(index)->Unbind();
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