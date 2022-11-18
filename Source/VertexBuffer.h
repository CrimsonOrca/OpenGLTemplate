#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

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
	GLuint GetID();
	void SetVertices(std::vector<Vertex> vertices);
private:
	GLuint _ID;
	std::vector<Vertex> _vertices;
};

#endif // !_VERTEX_BUFFER_H_