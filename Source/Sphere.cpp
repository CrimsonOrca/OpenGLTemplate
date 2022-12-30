#include "Sphere.h"

Sphere::Sphere(std::size_t subdivisions)
	: mSubdivisions { subdivisions }
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
	float s = 1.0f;
	float t = ( 1.0f + std::sqrt(5.0f) ) * 0.5f;
	float distance = std::sqrt(s * s + t * t);

	s /= distance;
	t /= distance;

	mVertices = {
		{ Position(-s,  t, 0.0f), Normal(-s,  t, 0.0f) },
		{ Position( s,  t, 0.0f), Normal( s,  t, 0.0f) },
		{ Position(-s, -t, 0.0f), Normal(-s, -t, 0.0f) },
		{ Position( s, -t, 0.0f), Normal( s, -t, 0.0f) },
		
		{ Position(0.0f, -s,  t), Normal(0.0f, -s,  t) },
		{ Position(0.0f,  s,  t), Normal(0.0f,  s,  t) },
		{ Position(0.0f, -s, -t), Normal(0.0f, -s, -t) },
		{ Position(0.0f,  s, -t), Normal(0.0f,  s, -t) },

		{ Position( t, 0.0f, -s), Normal( t, 0.0f, -s) },
		{ Position( t, 0.0f,  s), Normal( t, 0.0f,  s) },
		{ Position(-t, 0.0f, -s), Normal(-t, 0.0f, -s) },
		{ Position(-t, 0.0f,  s), Normal(-t, 0.0f,  s) },
	};

	mVertexCount = mVertices.size();
}

void Sphere::GenerateIndices()
{
	mIndices = {
		0, 11, 5, 0, 5, 1, 0, 1, 7, 0, 7, 10, 0, 10, 11,
		1, 5, 9, 5, 11, 4, 11, 10, 2, 10, 7, 6, 7, 1, 8,
		3, 9, 4, 3, 4, 2, 3, 2, 6, 3, 6, 8, 3, 8, 9, 
		4, 9, 5, 2, 4, 11, 6, 2, 10, 8, 6, 7, 9, 8, 1
	};

	mIndexCount = mIndices.size();
}

Vertex Sphere::CalculateMidpointVertex(const GLuint& i1, const GLuint& i2)
{
	Vertex v1 = mVertices.at(i1);
	Vertex v2 = mVertices.at(i2);

	glm::vec3 position = glm::normalize((v1.position + v2.position) * 0.5f);
	glm::vec3 normal = glm::normalize((v1.position + v2.position) * 0.5f);

	return { position, normal };
}

GLuint Sphere::CalculateMidpointIndex(const GLuint& i1, const GLuint& i2)
{
	uint64_t smallerIndex = std::min(i1, i2);
	uint64_t largerIndex = std::max(i1, i2);
	uint64_t key = (smallerIndex << 32) + largerIndex;

	if (mCache.contains(key))
		return mCache.at(key);
		
	GLuint index = mVertices.size();
	mCache.emplace(key, index);

	Vertex vertex = CalculateMidpointVertex(i1, i2);
	mVertices.push_back(vertex);
	
	return index;
}

void Sphere::Subdivide()
{
	for (std::size_t i = 0; i < mSubdivisions; i++)
	{
		std::vector<GLuint> indices {};
		for (std::size_t j = 0; j < mIndices.size(); j += 3)
		{
			GLuint a = mIndices.at(j + 0);
			GLuint b = mIndices.at(j + 1);
			GLuint c = mIndices.at(j + 2);

			GLuint ab = CalculateMidpointIndex(a, b);
			GLuint bc = CalculateMidpointIndex(b, c);
			GLuint ca = CalculateMidpointIndex(c, a);

			indices.insert(indices.end(), {  a, ab, ca });
			indices.insert(indices.end(), {  b, bc, ab });
			indices.insert(indices.end(), {  c, ca, bc });
			indices.insert(indices.end(), { ab, bc, ca });
		}
		mIndices = std::move(indices);
	}
	mIndexCount = mIndices.size();
	mVertexCount = mVertices.size();
}