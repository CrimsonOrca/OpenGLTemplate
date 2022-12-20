#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

typedef glm::vec3 Position;
typedef glm::vec3 Normal;
typedef glm::vec2 TextureCoordinate;

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 textureCoordinate;
};

#endif // _VERTEX_H_
