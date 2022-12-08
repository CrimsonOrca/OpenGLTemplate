#include "Cube.h"

Cube::Cube()
	: mSize {1.0f}
{
	GenerateVertices();
	GenerateIndices();
}

Cube::~Cube() 
{

}

void Cube::GenerateVertices()
{
	const Vertex V0 { glm::vec3( mSize / 2.0f,  mSize / 2.0f, mSize / 2.0f), glm::vec3(), glm::vec2() };
	const Vertex V1 { glm::vec3(-mSize / 2.0f,  mSize / 2.0f, mSize / 2.0f), glm::vec3(), glm::vec2() };
	const Vertex V2 { glm::vec3(-mSize / 2.0f, -mSize / 2.0f, mSize / 2.0f), glm::vec3(), glm::vec2() };
	const Vertex V3 { glm::vec3( mSize / 2.0f, -mSize / 2.0f, mSize / 2.0f), glm::vec3(), glm::vec2() };

	const Vertex V4 { glm::vec3( mSize / 2.0f,  mSize / 2.0f, -mSize / 2.0f), glm::vec3(), glm::vec2() };
	const Vertex V5 { glm::vec3(-mSize / 2.0f,  mSize / 2.0f, -mSize / 2.0f), glm::vec3(), glm::vec2() };
	const Vertex V6 { glm::vec3(-mSize / 2.0f, -mSize / 2.0f, -mSize / 2.0f), glm::vec3(), glm::vec2() };
	const Vertex V7 { glm::vec3( mSize / 2.0f, -mSize / 2.0f, -mSize / 2.0f), glm::vec3(), glm::vec2() };

	InsertVertex(V0);
	InsertVertex(V1);
	InsertVertex(V2);
	InsertVertex(V3);
	InsertVertex(V4);
	InsertVertex(V5);
	InsertVertex(V6);
	InsertVertex(V7);

	mVertexCount = mVertices.size();
}

void Cube::GenerateIndices()
{
	InsertTriangleIndices(0, 1, 2);
	InsertTriangleIndices(0, 2, 3);

	InsertTriangleIndices(4, 5, 6);
	InsertTriangleIndices(4, 6, 7);

	InsertTriangleIndices(4, 5, 1);
	InsertTriangleIndices(4, 1, 0);

	InsertTriangleIndices(7, 6, 2);
	InsertTriangleIndices(7, 2, 3);

	InsertTriangleIndices(4, 0, 3);
	InsertTriangleIndices(4, 3, 7);

	InsertTriangleIndices(5, 1, 2);
	InsertTriangleIndices(5, 2, 6);

	mIndexCount = mIndices.size();
}