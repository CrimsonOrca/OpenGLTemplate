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
	mVertices = {
		// front...
		{ Position( mSize,  mSize, mSize), Normal(0.0f, 0.0f, 1.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize,  mSize, mSize), Normal(0.0f, 0.0f, 1.0f), TextureCoordinate(0.0f, 1.0f) },
		{ Position(-mSize, -mSize, mSize), Normal(0.0f, 0.0f, 1.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize,  mSize, mSize), Normal(0.0f, 0.0f, 1.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize, -mSize, mSize), Normal(0.0f, 0.0f, 1.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize, -mSize, mSize), Normal(0.0f, 0.0f, 1.0f), TextureCoordinate(1.0f, 0.0f) },
		// back...
		{ Position( mSize,  mSize, -mSize), Normal(0.0f, 0.0f, -1.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize,  mSize, -mSize), Normal(0.0f, 0.0f, -1.0f), TextureCoordinate(0.0f, 1.0f) },
		{ Position(-mSize, -mSize, -mSize), Normal(0.0f, 0.0f, -1.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize,  mSize, -mSize), Normal(0.0f, 0.0f, -1.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize, -mSize, -mSize), Normal(0.0f, 0.0f, -1.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize, -mSize, -mSize), Normal(0.0f, 0.0f, -1.0f), TextureCoordinate(1.0f, 0.0f) },
		// top...
		{ Position( mSize,  mSize, -mSize), Normal(0.0f, 1.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize,  mSize, -mSize), Normal(0.0f, 1.0f, 0.0f), TextureCoordinate(0.0f, 1.0f) },
		{ Position(-mSize,  mSize,  mSize), Normal(0.0f, 1.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize,  mSize, -mSize), Normal(0.0f, 1.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize,  mSize,  mSize), Normal(0.0f, 1.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize,  mSize,  mSize), Normal(0.0f, 1.0f, 0.0f), TextureCoordinate(1.0f, 0.0f) },
		// bottom...
		{ Position( mSize, -mSize, -mSize), Normal(0.0f, -1.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize, -mSize, -mSize), Normal(0.0f, -1.0f, 0.0f), TextureCoordinate(0.0f, 1.0f) },
		{ Position(-mSize, -mSize,  mSize), Normal(0.0f, -1.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize, -mSize, -mSize), Normal(0.0f, -1.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize, -mSize,  mSize), Normal(0.0f, -1.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position( mSize, -mSize,  mSize), Normal(0.0f, -1.0f, 0.0f), TextureCoordinate(1.0f, 0.0f) },
		// right...
		{ Position(mSize,  mSize, -mSize), Normal(1.0f, 0.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(mSize,  mSize,  mSize), Normal(1.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 1.0f) },
		{ Position(mSize, -mSize,  mSize), Normal(1.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position(mSize,  mSize, -mSize), Normal(1.0f, 0.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(mSize, -mSize,  mSize), Normal(1.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position(mSize, -mSize, -mSize), Normal(1.0f, 0.0f, 0.0f), TextureCoordinate(1.0f, 0.0f) },
		// left...
		{ Position(-mSize,  mSize, -mSize), Normal(-1.0f, 0.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize,  mSize,  mSize), Normal(-1.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 1.0f) },
		{ Position(-mSize, -mSize,  mSize), Normal(-1.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position(-mSize,  mSize, -mSize), Normal(-1.0f, 0.0f, 0.0f), TextureCoordinate(1.0f, 1.0f) },
		{ Position(-mSize, -mSize,  mSize), Normal(-1.0f, 0.0f, 0.0f), TextureCoordinate(0.0f, 0.0f) },
		{ Position(-mSize, -mSize, -mSize), Normal(-1.0f, 0.0f, 0.0f), TextureCoordinate(1.0f, 0.0f) }
	};

	mVertexCount = mVertices.size();
}

void Cube::GenerateIndices()
{
	
}