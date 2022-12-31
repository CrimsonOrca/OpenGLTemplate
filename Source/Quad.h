#ifndef _QUAD_H_
#define _QUAD_H_

#include "Mesh.h"

class Quad : public Mesh
{
public:
	Quad();
	Quad(float size);
	Quad(float width, float length);
	virtual ~Quad() override;
	virtual void Draw() const override;
	virtual void GenerateVertices() override;
	virtual void GenerateIndices() override;
private:
	float mWidth;  // x-direction
	float mLength; // y-direction
};

#endif 