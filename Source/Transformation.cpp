#include "Transformation.h"

Transformation::Transformation()
	: _model {1.0f}
{

}

glm::mat4 Transformation::GetModelMatrix() const
{
	return _model;
}

void Transformation::Rotate(const glm::vec3& axis, float degrees)
{
	_model = glm::rotate(_model, glm::radians(degrees), axis);
}

void Transformation::Scale(float x, float y, float z)
{
	_model = glm::scale(_model, glm::vec3(x, y, z));
}

void Transformation::Translate(float x, float y, float z)
{
	_model = glm::translate(_model, glm::vec3(x, y, z));
}