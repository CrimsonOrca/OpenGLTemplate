#ifndef _RENDERER_H_
#define _RENDERER_H_

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
	void SetMesh(Mesh& mesh);
	template<typename T, typename... Params> void SetMesh(Params... params)
	{
		mMesh = new T(params...);
		mVertexArray.Bind();
		mVertexBuffer.SetVertices(mMesh->GetVertices());
		mIndexBuffer.SetIndices(mMesh->GetIndices());
		mVertexArray.Unbind();
	}
	void Draw();
	void ShowWireFrame() 
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
protected:
	VertexArray mVertexArray;
	VertexBuffer mVertexBuffer;
	IndexBuffer mIndexBuffer;
	Mesh* mMesh;
};

#endif