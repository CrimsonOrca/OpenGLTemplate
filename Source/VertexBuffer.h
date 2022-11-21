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
private:
	GLuint _ID;
	std::vector<Vertex> _vertices;
};

#endif // !_VERTEX_BUFFER_H_