#ifndef _SPHERE_H
#define _SPHERE_H

#include "Constants.h"
#include "Mesh.h"

#include <unordered_map>

class Sphere: public Mesh
{
public:
	Sphere(float radius);
	Sphere();
	virtual ~Sphere() override;
	virtual void GenerateVertices() override;
	virtual void GenerateIndices() override;
	Vertex CalculateMidpoint(const Vertex& v1, const Vertex& v2);
	void Subdivide();
private:
	float mRadius;
	std::unordered_map<GLuint, GLuint> mCache;
	const std::size_t SUBDIVISIONS { 4 };
};

#endif