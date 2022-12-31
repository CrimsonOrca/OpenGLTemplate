#include "Plane.h"

Plane::Plane() 
	: Plane(1.0f)
{
	GenerateVertices();
	GenerateIndices();
}

Plane::Plane(float size) 
	: Plane(size, size)
{

}

Plane::Plane(float width, float length) 
	: mWidth  {width}
	, mLength {length}
{

}

Plane::~Plane() 
{

}

void Plane::GenerateVertices() 
{
	mVertices = {
		{Position( 5.0f, 0.0f,  5.0f), Normal(), TextureCoordinate(2.0f, 0.0f)},
		{Position(-5.0f, 0.0f,  5.0f), Normal(), TextureCoordinate(0.0f, 0.0f)},
		{Position(-5.0f, 0.0f, -5.0f), Normal(), TextureCoordinate(0.0f, 2.0f)},
		{Position( 5.0f, 0.0f,  5.0f), Normal(), TextureCoordinate(2.0f, 0.0f)},
		{Position(-5.0f, 0.0f, -5.0f), Normal(), TextureCoordinate(0.0f, 2.0f)},
		{Position( 5.0f, 0.0f, -5.0f), Normal(), TextureCoordinate(2.0f, 2.0f)}
	};

	mVertexCount = mVertices.size();
}

void Plane::GenerateIndices() 
{

}

void Plane::Draw() const 
{
	glDrawArrays(GL_TRIANGLES, 0, mVertexCount);
}