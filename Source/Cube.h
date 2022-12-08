#ifndef _CUBE_H_
#define _CUBE_H_

#include "Mesh.h"

class Cube : public Mesh
{
	public:
		Cube();
		virtual ~Cube() override;
		virtual void GenerateVertices() override;
		virtual void GenerateIndices() override;
	private:
		float mSize;
};

#endif 
