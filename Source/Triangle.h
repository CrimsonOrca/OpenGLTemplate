#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Mesh.h"

class Triangle : public Mesh
{
public:
	Triangle();
	~Triangle();
	void GenerateVertices();
	void GenerateIndices();
private:

};

#endif _TRIANGLE_H_