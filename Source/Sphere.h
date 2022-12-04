#ifndef _SPHERE_H
#define _SPHERE_H

#include "Mesh.h"

class Sphere: public Mesh
{
public:
	Sphere(float radius, glm::vec3 center)
		: mRadius {radius}
		, mCenter {center}
	{

	}
	Sphere()
		: Sphere(1.0f, glm::vec3(0.0f, 0.0f, 0.0f))
	{
		std::cout << "...";
	}
	virtual ~Sphere() override
	{

	}
	virtual void GenerateVertices() override
	{

	}
	virtual void GenerateIndices() override
	{

	}
private:
	float mRadius;
	glm::vec3 mCenter;
};

#endif