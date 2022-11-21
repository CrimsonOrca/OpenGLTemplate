#include "Transformation.h"

Transformation::Transformation()
	: _transformation(1.0f)
{

}

glm::mat4 Transformation::GetTransformationMatrix() const
{
	return _transformation;
}

void Transformation::Rotate(const glm::vec3& axis, float degrees)
{
	_transformation = glm::rotate(_transformation, glm::radians(degrees), axis);
}

void Transformation::Scale(float x, float y, float z)
{
	_transformation = glm::scale(_transformation, glm::vec3(x, y, z));
}

void Transformation::Translate(float x, float y, float z)
{
	_transformation = glm::translate(_transformation, glm::vec3(x, y, z));
}