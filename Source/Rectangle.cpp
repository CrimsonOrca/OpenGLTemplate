#include "Rectangle.h"

Rectangle::Rectangle()
	: Rectangle(0.5f, 0.5f)
{

}

Rectangle::Rectangle(float width, float length)
	: _width  {width}
	, _length {length}
{
	GenerateVertices();
	GenerateIndices();
	Create();
}

void Rectangle::GenerateVertices()
{
	_vertices.push_back({ { _width,  _length, 0.0f}, {}, {1.0f, 1.0f} });
	_vertices.push_back({ {-_width,  _length, 0.0f}, {}, {0.0f, 1.0f} });
	_vertices.push_back({ {-_width, -_length, 0.0f}, {}, {0.0f, 0.0f} });
	_vertices.push_back({ { _width, -_length, 0.0f}, {}, {1.0f, 0.0f} });
}

void Rectangle::GenerateIndices()
{
	_indices.push_back(0);
	_indices.push_back(1);
	_indices.push_back(2);

	_indices.push_back(0);
	_indices.push_back(2);
	_indices.push_back(3);
}

void Rectangle::SetWidth(float width)
{
	_width = width;
}

void Rectangle::SetLength(float length)
{
	_length = length;
}

float Rectangle::GetWidth() const
{
	return _width;
}

float Rectangle::GetLength() const
{
	return _length;
}