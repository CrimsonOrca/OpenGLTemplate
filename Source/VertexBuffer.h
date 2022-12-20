#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

#include <iostream>
#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"

class VertexBuffer
{
	public:
		VertexBuffer();
		VertexBuffer(std::vector<Vertex> vertices);
		~VertexBuffer();
		void SetVertices(std::vector<Vertex> vertices);
		void SpecifyBufferLayout(GLuint index, GLuint size, void* offset);
	private:
		const GLsizei VERTEX_OFFSET = sizeof(Vertex);

		void* POSITION_OFFSET           = (void*)(offsetof(Vertex, position));
		void* NORMAL_OFFSET             = (void*)(offsetof(Vertex, normal));
		void* TEXTURE_COORDINATE_OFFSET = (void*)(offsetof(Vertex, textureCoordinate));

		const GLuint POSITION_INDEX           = 0;
		const GLuint NORMAL_INDEX             = 1;
		const GLuint TEXTURE_COORDINATE_INDEX = 2;

		const GLuint NUM_COMP_PER_POSITION           = 3;
		const GLuint NUM_COMP_PER_NORMAL             = 3;
		const GLuint NUM_COMP_PER_TEXTURE_COORDINATE = 2;

		GLuint _ID;
		std::vector<Vertex> _vertices;
};

#endif