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
	template<typename T> void SetMesh()
	{
		mMesh = std::make_shared<T>();
		mVertexArray.Bind();
		mVertexBuffer.SetVertices(mMesh->GetVertices());
		mIndexBuffer.SetIndices(mMesh->GetIndices());
		mVertexArray.Unbind();
	}
	void Draw();
	void ShowWireFrame();
	void ClearScreen();
	void EnableDepthTesting();
protected:
	VertexArray mVertexArray;
	VertexBuffer mVertexBuffer;
	IndexBuffer mIndexBuffer;
	std::shared_ptr<Mesh> mMesh;
};

#endif