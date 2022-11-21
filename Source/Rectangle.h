#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Mesh.h"

class Rectangle : public Mesh
{
public:
	Rectangle();
	Rectangle(float width, float length);
	void GenerateVertices();
	void GenerateIndices();
	void SetWidth(float width);
	void SetLength(float length);
	float GetWidth() const;
	float GetLength() const;
private:
	float _width;  // x-direction
	float _length; // y-direction
};

#endif _RECTANGLE_H_ // !_RECTANGLE_H_