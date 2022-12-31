#include "Quad.h"

Quad::Quad()
	: Quad(1.0f, 1.0f)
{

}

Quad::Quad(float size)
	: Quad (size, size)
{

}

Quad::Quad(float width, float length)
	: mWidth  {width}
	, mLength {length}
{
	GenerateVertices();
	GenerateIndices();
}

Quad::~Quad()
{

}

void Quad::GenerateVertices()
{
	const Vertex TOP_RIGHT    = { Position( mWidth,  mLength, 0.0f), Normal(), TextureCoordinate(1.0f, 1.0f) };
	const Vertex TOP_LEFT     = { Position(-mWidth,  mLength, 0.0f), Normal(), TextureCoordinate(0.0f, 1.0f) };
	const Vertex BOTTOM_LEFT  = { Position(-mWidth, -mLength, 0.0f), Normal(), TextureCoordinate(0.0f, 0.0f) };
	const Vertex BOTTOM_RIGHT = { Position( mWidth, -mLength, 0.0f), Normal(), TextureCoordinate(1.0f, 0.0f) };

	mVertices.push_back(TOP_RIGHT);
	mVertices.push_back(TOP_LEFT);
	mVertices.push_back(BOTTOM_LEFT);
	mVertices.push_back(BOTTOM_RIGHT);

	mVertexCount = mVertices.size();
}

void Quad::GenerateIndices() 
{
	const GLuint TOP_RIGHT    = 0;
	const GLuint TOP_LEFT     = 1;
	const GLuint BOTTOM_LEFT  = 2;
	const GLuint BOTTOM_RIGHT = 3;

	mIndices.push_back(TOP_RIGHT);
	mIndices.push_back(TOP_LEFT);
	mIndices.push_back(BOTTOM_LEFT);

	mIndices.push_back(TOP_RIGHT);
	mIndices.push_back(BOTTOM_LEFT);
	mIndices.push_back(BOTTOM_RIGHT);

	mIndexCount = mIndices.size();
}

void Quad::Draw() const
{
	glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);
}