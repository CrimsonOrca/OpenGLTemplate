#ifndef _INDEX_BUFFER_H_
#define _INDEX_BUFFER_H_

#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"

class IndexBuffer
{
public:
	IndexBuffer();
	IndexBuffer(std::vector<GLuint> indices);
	~IndexBuffer();
	GLuint GetID() const;
	void SetIndices(std::vector<GLuint> indices);
private:
	GLuint _ID;
	std::vector<GLuint> _indices;
};

#endif // !_INDEX_BUFFER_H_