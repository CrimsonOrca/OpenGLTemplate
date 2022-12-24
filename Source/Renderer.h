#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <memory>
#include <map>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Mesh.h"

class Renderer
{
	public:
		Renderer();
		~Renderer();
		template<typename Type, typename... Arguments> void AddMesh(std::string name, Arguments... arguments);
		void Draw(std::string name);
		void DrawWireFrame();
		void ClearScreen();
		void EnableDepthTesting();
	private:
		std::vector<std::shared_ptr<VertexArray>> mVertexArrays;
		std::vector<std::shared_ptr<VertexBuffer>> mVertexBuffers;
		std::vector<std::shared_ptr<IndexBuffer>> mIndexBuffers;
		std::vector<std::shared_ptr<Mesh>> mMeshes;
		std::map<std::string, int> mCache;
		int mMeshCount;
};

template<typename Type, typename... Arguments> 
void Renderer::AddMesh(std::string name, Arguments... arguments)
{
	mCache.emplace(name, mMeshCount);

	mMeshes.push_back(std::make_shared<Type>(arguments...));

	mVertexArrays.push_back(std::make_shared<VertexArray>());
	mVertexBuffers.push_back(std::make_shared<VertexBuffer>());
	mIndexBuffers.push_back(std::make_shared<IndexBuffer>());

	mVertexArrays.at(mMeshCount)->Bind();

	mVertexBuffers.at(mMeshCount)->SetVertices(mMeshes.at(mMeshCount)->GetVertices());

	if (mMeshes.at(mMeshCount)->GetIndexCount())
		mIndexBuffers.at(mMeshCount)->SetIndices(mMeshes.at(mMeshCount)->GetIndices());

	mVertexArrays.at(mMeshCount)->Unbind();

	mMeshCount++;
}

#endif