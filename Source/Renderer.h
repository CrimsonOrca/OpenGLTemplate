#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <memory>
#include <unordered_map>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Mesh.h"

class Renderer
{
	public:
		Renderer();
		void StoreMesh(std::string name, std::unique_ptr<Mesh>&& mesh);
		void Draw(std::string name);
		void DrawWireFrame();
		void ClearScreen();
		void EnableDepthTesting();
	private:
		std::vector<std::unique_ptr<VertexArray>> mVertexArrays;
		std::vector<std::unique_ptr<VertexBuffer>> mVertexBuffers;
		std::vector<std::unique_ptr<IndexBuffer>> mIndexBuffers;
		std::vector<std::unique_ptr<Mesh>> mMeshes;
		std::unordered_map<std::string, std::size_t> mCache;
		int mMeshCount;
};

#endif