#include "Quad.h"

Quad::Quad()
	: Quad(0.5f, 0.5f)
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
	const Vertex TOP_RIGHT    = { glm::vec3( mWidth,  mLength, 0.0f), glm::vec3(), glm::vec2(1.0f, 1.0f) };
	const Vertex TOP_LEFT     = { glm::vec3(-mWidth,  mLength, 0.0f), glm::vec3(), glm::vec2(0.0f, 1.0f) };
	const Vertex BOTTOM_LEFT  = { glm::vec3(-mWidth, -mLength, 0.0f), glm::vec3(), glm::vec2(0.0f, 0.0f) };
	const Vertex BOTTOM_RIGHT = { glm::vec3( mWidth, -mLength, 0.0f), glm::vec3(), glm::vec2(1.0f, 0.0f) };

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