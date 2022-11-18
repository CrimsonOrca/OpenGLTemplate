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
		Mesh();
		~Mesh();
		void CreateMesh();
		void RenderMesh();
		void DeleteMesh();
		void GenerateVertices();
		void GenerateIndices();
		void SetVertices(std::vector<Vertex> vertices);
		void SetIndices(std::vector<GLuint> indices);
	protected:
		std::vector<Vertex> _vertices;
		std::vector<GLuint> _indices;

		VertexArray  _vertexArray;
		VertexBuffer _vertexBuffer;
		IndexBuffer  _indexBuffer;
};

#endif // !_MESH_H_