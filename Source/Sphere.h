#ifndef _SPHERE_H
#define _SPHERE_H

#include <unordered_map>
#include "Constants.h"
#include "Mesh.h"

typedef glm::vec3 Position;
typedef glm::vec3 Normal;
typedef glm::vec2 TextureCoordinate;

class Sphere: public Mesh
{
	public:
		Sphere(std::size_t subdivisions = 4);
		virtual ~Sphere() override;
		virtual void GenerateVertices() override;
		virtual void GenerateIndices() override;
	private:
		Vertex CalculateMidpointVertex(const GLuint& v1, const GLuint& v2);
		GLuint CalculateMidpointIndex(const GLuint& i1, const GLuint& i2);
		void Subdivide();
		std::unordered_map<uint64_t, GLuint> mCache;
		std::size_t mSubdivisions;
};

#endif