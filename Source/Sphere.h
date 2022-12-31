#ifndef _SPHERE_H
#define _SPHERE_H

/*
	sphere mesh generation algorithm inspired by
	https://www.youtube.com/watch?v=zxnaq2nhMCQ
	http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html
*/

#include <unordered_map>
#include "Constants.h"
#include "Mesh.h"

class Sphere: public Mesh
{
	public:
		Sphere(std::size_t subdivisions = 4);
		virtual ~Sphere() override;
		virtual void Draw() const override;
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