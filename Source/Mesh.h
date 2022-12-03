#ifndef _MESH_H_
#define _MESH_H_

#include <iostream>
#include <vector>
#include <cstddef>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh
{
	public:
		virtual ~Mesh();
		void Setup();
		virtual void Render() = 0;
		virtual void GenerateVertices() = 0;
		virtual void GenerateIndices() = 0;
	protected:
		std::vector<Vertex> mVertices;
		std::vector<GLuint> mIndices;
		VertexArray mVertexArray;
		VertexBuffer mVertexBuffer;
		IndexBuffer mIndexBuffer;
};

#endif 