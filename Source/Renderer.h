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
		void StoreMesh(std::string name, std::shared_ptr<Mesh> mesh);
		void Draw(std::string name);
		void DrawWireFrame();
		void ClearScreen();
		void EnableDepthTesting();
	private:
		std::vector<std::unique_ptr<VertexArray>> mVertexArrays{};
		std::vector<std::unique_ptr<VertexBuffer>> mVertexBuffers{};
		std::vector<std::unique_ptr<IndexBuffer>> mIndexBuffers{};
		std::vector<std::shared_ptr<Mesh>> mMeshes;
		std::map<std::string, int> mCache;
		int mMeshCount;
};

#endif