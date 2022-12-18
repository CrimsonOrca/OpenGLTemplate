#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <memory>

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
		template<typename T, typename... Args> void SetMesh(Args... args);
		void Draw();
		void DrawWireFrame();
		void ClearScreen();
		void EnableDepthTesting();
	private:
		VertexArray mVertexArray;
		VertexBuffer mVertexBuffer;
		IndexBuffer mIndexBuffer;
		std::shared_ptr<Mesh> mMesh;
};

template<typename T, typename... Args>
void Renderer::SetMesh(Args... args)
{
	mMesh = std::make_shared<T>(args...);
	mVertexArray.Bind();
	mVertexBuffer.SetVertices(mMesh->GetVertices());
	mIndexBuffer.SetIndices(mMesh->GetIndices());
	mVertexArray.Unbind();
}

#endif