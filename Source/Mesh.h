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
		virtual void GenerateVertices() = 0;
		virtual void GenerateIndices() = 0;
		std::vector<Vertex> GetVertices() const;
		std::vector<GLuint> GetIndices() const;
		GLuint GetVertexCount() const;
		GLuint GetIndexCount() const;
		void InsertVertex(Vertex vertex)
		{
			mVertices.push_back(vertex);
		}
		void InsertIndex(const GLuint& index)
		{
			mIndices.push_back(index);
		}
	protected:
		std::vector<Vertex> mVertices;
		std::vector<GLuint> mIndices;
		GLuint mVertexCount;
		GLuint mIndexCount;
};

#endif 