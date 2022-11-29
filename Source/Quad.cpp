#include "Quad.h"

Quad::Quad()
	: Quad(0.5f, 0.5f)
{

}

Quad::~Quad()
{

}

Quad::Quad(float width, float length)
	: mWidth  {width}
	, mLength {length}
{
	GenerateVertices();
	GenerateIndices();
	Create();
}

void Quad::GenerateVertices()
{
	_vertices.push_back({ { mWidth,  mLength, 0.0f}, {}, {1.0f, 1.0f} });
	_vertices.push_back({ {-mWidth,  mLength, 0.0f}, {}, {0.0f, 1.0f} });
	_vertices.push_back({ {-mWidth, -mLength, 0.0f}, {}, {0.0f, 0.0f} });
	_vertices.push_back({ { mWidth, -mLength, 0.0f}, {}, {1.0f, 0.0f} });
}

void Quad::GenerateIndices() 
{
	_indices.push_back(0);
	_indices.push_back(1);
	_indices.push_back(2);

	_indices.push_back(0);
	_indices.push_back(2);
	_indices.push_back(3);
}

void Quad::Render()
{
	_vertexArray.Bind();
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
	_vertexArray.Unbind();
}