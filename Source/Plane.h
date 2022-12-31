#ifndef _PLANE_H_
#define _PLANE_H_

#include "Mesh.h"

class Plane : public Mesh {
public:
	Plane();
	Plane(float size);
	Plane(float width, float length);
	virtual ~Plane() override;
	virtual void GenerateVertices() override;
	virtual void GenerateIndices() override;
	virtual void Draw() const override;
private:
	float mWidth;
	float mLength;
};

#endif 
