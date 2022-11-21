#ifndef _VERTEX_ARRAY_H_
#define _VERTEX_ARRAY_H_

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind();
	void Unbind();
private:
	GLuint _ID;
};

#endif // _VERTEX_ARRAY_H_