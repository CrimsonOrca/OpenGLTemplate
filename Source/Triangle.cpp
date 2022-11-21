#include "Triangle.h"

Triangle::Triangle()
{
	GenerateVertices();
	GenerateIndices();
	Create();
}

Triangle::~Triangle()
{

}

void Triangle::GenerateVertices()
{
	_vertices.push_back({ {-0.5f, -0.5f, 0.0f}, {}, {} });
	_vertices.push_back({ { 0.5f, -0.5f, 0.0f}, {}, {} });
	_vertices.push_back({ { 0.0f,  0.5f, 0.0f}, {}, {} });
}

void Triangle::GenerateIndices()
{
	_indices.push_back(0);
	_indices.push_back(1);
	_indices.push_back(2);
}