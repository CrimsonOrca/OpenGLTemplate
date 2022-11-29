#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Constants.h"
#include "Window.h"

const glm::vec3 WORLD_UP      { 0.0f, 1.0f, 0.0f };
const glm::vec3 WORLD_FORWARD { 0.0f, 0.0f, -1.0f };
const glm::vec3 WORLD_RIGHT   { 1.0f, 0.0f, 0.0f };
const glm::vec3 WORLD_ORIGIN  { 0.0f, 0.0f, 0.0f };

const float FIELD_OF_VIEW_MAX  { 45.0f };
const float FIELD_OF_VIEW_MIN  { 1.0f };
const float NEAR_PLANE         { 0.1f };
const float FAR_PLANE          { 100.0f };
const float ASPECT_RATIO       { static_cast<float>(SCREEN_WIDTH) / static_cast<float>(SCREEN_HEIGHT) };
const float CAMERA_SPEED       { 2.5f };
const float CAMERA_SENSITIVITY { 0.1f };

const float	PITCH_MAX { 89.0f };
const float	PITCH_MIN { -1.0f * PITCH_MAX };

class Camera
{
	public:
		Camera(glm::vec3 position);
		void ProcessInput(Window& window, float timeStep);
		void ProcessKeyboardButtonPress(Window& window, float timeStep);
		void ProcessMouseMovement(Window& window);
		void ProcessMouseScroll(Window& window);
		void UpdateCameraVectors();
		glm::mat4 GetViewMatrix() const;
		glm::mat4 GetProjectionMatrix() const;
	private:
		glm::vec3 mPosition;
		glm::vec3 mDirection; // front...
		glm::vec3 mUp;
		glm::vec3 mRight;
		float mYaw;
		float mPitch;
		float mZoom;
};

#endif // !_CAMERA_H_