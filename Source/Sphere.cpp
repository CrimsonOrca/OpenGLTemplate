#include "Sphere.h"

Sphere::Sphere()
	: Sphere(5.0f)
{

}

Sphere::Sphere(float radius)
	: mRadius {radius}
{
	GenerateVertices();
	GenerateIndices();
	Subdivide();
}

Sphere::~Sphere() 
{

}

void Sphere::GenerateVertices() 
{
	const float X = 0.525731112119133606f;
	const float Z = 0.850650808352039932f;
	const float N = 0.0f;

	const Vertex V01 = { glm::normalize(glm::vec3(-X, N, Z)) };
	const Vertex V02 = { glm::normalize(glm::vec3( X, N, Z)) };
	const Vertex V03 = { glm::normalize(glm::vec3(-X, N,-Z)) };
	const Vertex V04 = { glm::normalize(glm::vec3( X, N,-Z)) };
	const Vertex V05 = { glm::normalize(glm::vec3( N, Z, X)) };
	const Vertex V06 = { glm::normalize(glm::vec3( N, Z,-X)) };
	const Vertex V07 = { glm::normalize(glm::vec3( N,-Z, X)) };
	const Vertex V08 = { glm::normalize(glm::vec3( N,-Z,-X)) };
	const Vertex V09 = { glm::normalize(glm::vec3( Z, X, N)) };
	const Vertex V10 = { glm::normalize(glm::vec3(-Z, X, N)) };
	const Vertex V11 = { glm::normalize(glm::vec3( Z,-X, N)) };
	const Vertex V12 = { glm::normalize(glm::vec3(-Z,-X, N)) };

	InsertVertex(V01);
	InsertVertex(V02);
	InsertVertex(V03);
	InsertVertex(V04);
	InsertVertex(V05);
	InsertVertex(V06);
	InsertVertex(V07);
	InsertVertex(V08);
	InsertVertex(V09);
	InsertVertex(V10);
	InsertVertex(V11);
	InsertVertex(V12);

	mVertexCount = mVertices.size();
}

void Sphere::GenerateIndices()
{
	mIndices = { 
		0,  4,  1, 
		0,  9,  4, 
		9,  5,  4, 
		4,  5,  8, 
		4,  8,  1, 
		8, 10,  1, 
		8,  3, 10, 
		5,  3,  8, 
		5,  2,  3, 
		2,  7,  3, 
		7, 10,  3, 
		7,  6, 10, 
		7, 11,  6, 
	    11, 0,  6, 
		0,  1,  6, 
		6,  1, 10, 
		9,  0, 11, 
		9, 11,  2, 
		9,  2,  5, 
		7,  2, 11
	};

	mIndexCount = mIndices.size();
}

Vertex Sphere::CalculateMidpoint(const Vertex& v1, const Vertex& v2)
{
	float x = (v1.position.x + v2.position.x) / 2.0f;
	float y = (v1.position.y + v2.position.y) / 2.0f;
	float z = (v1.position.z + v2.position.z) / 2.0f;

	float magnitude = std::sqrt(x * x + y * y + z * z);

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;

	return { glm::vec3(x, y, z) , glm::vec3(), glm::vec2() };
}

void Sphere::Subdivide()
{
	GLuint index = 0;

	for (std::size_t i {0}; i < SUBDIVISIONS; i++)
	{
		std::vector<GLuint> indices;

		for (std::size_t j {0}; j < mIndices.size(); j += 3)
		{
			const GLuint I1 = mIndices.at(j + 0);
			const GLuint I2 = mIndices.at(j + 1);
			const GLuint I3 = mIndices.at(j + 2);

			const Vertex V1 = mVertices.at(I1);
			const Vertex V2 = mVertices.at(I2);
			const Vertex V3 = mVertices.at(I3);

			const Vertex V4 = CalculateMidpoint(V1, V2);
			const Vertex V5 = CalculateMidpoint(V2, V3);
			const Vertex V6 = CalculateMidpoint(V3, V1);

			//indices.push_back(); indices.push_back(); indices.push_back();
			//indices.push_back(); indices.push_back(); indices.push_back();
			//indices.push_back(); indices.push_back(); indices.push_back();
			//indices.push_back(); indices.push_back(); indices.push_back();
		}
		mIndices.clear();
		mIndices = std::move(indices);
	}

	mIndexCount = mIndices.size();
	mVertexCount = mVertices.size();
}