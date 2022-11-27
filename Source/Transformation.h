#ifndef _TRANSFORMATION_H_
#define _TRANSFORMATION_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const glm::vec3 POSITIVE_Z_AXIS { 0.0f, 0.0f, 1.0f };
const glm::vec3 POSITIVE_Y_AXIS { 0.0f, 1.0f, 0.0f };
const glm::vec3 POSITIVE_X_AXIS { 1.0f, 0.0f, 0.0f };
const glm::vec3 NEGATIVE_Z_AXIS { -POSITIVE_Z_AXIS };
const glm::vec3 NEGATIVE_Y_AXIS { -POSITIVE_Y_AXIS };
const glm::vec3 NEGATIVE_X_AXIS { -POSITIVE_X_AXIS };

class Transformation
{
public:
	Transformation();
	glm::mat4 GetModelMatrix() const;
	void Rotate(const glm::vec3& axis, float degrees);
	void Scale(float x, float y, float z);
	void Translate(float x, float y, float z);
private:
	glm::mat4 _model; /* scale, rotate, and translate... */
};

#endif // !_TRANSFORMATION_H_