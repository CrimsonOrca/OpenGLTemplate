#ifndef _MESH_H_
#define _MESH_H_

#include <iostream>
#include <vector>
#include <cstddef>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textureCoordinate;
};

class Mesh
{
	public:
		Mesh();
		~Mesh();
		void CreateMesh();
		void RenderMesh();
		void DeleteMesh();
	protected:
		std::vector<Vertex> _vertices;
		std::vector<unsigned int> _indices;
		unsigned int _vertexArrayObject;
		unsigned int _vertexBufferObject;
		unsigned int _indexBufferObject;
};

#endif // !_MESH_H_