#include "Camera.h"

Camera::Camera(glm::vec3 position)
	: mPosition  { position }
	, mDirection { WORLD_FORWARD }
	, mUp        { WORLD_UP }
	, mRight     { glm::normalize(glm::cross(mDirection, mUp)) }
	, mYaw       { -90.0f }
	, mPitch     { 0.0f }
	, mZoom      { FIELD_OF_VIEW_MAX }
{

}

void Camera::ProcessKeyboardButtonPress(float timeStep)
{
	auto* window = Window::GetInput().window;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		mPosition += CAMERA_SPEED * timeStep * mDirection;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		mPosition -= CAMERA_SPEED * timeStep * mDirection;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		mPosition -= glm::normalize(glm::cross(mDirection, mUp)) * timeStep * CAMERA_SPEED;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		mPosition += glm::normalize(glm::cross(mDirection, mUp)) * timeStep * CAMERA_SPEED;
}

void Camera::ProcessMouseMovement()
{
	Mouse mouse = Window::GetMouse();
	mouse.deltaX *= CAMERA_SENSITIVITY;
	mouse.deltaY *= CAMERA_SENSITIVITY;

	static float x = 0.0f;
	static float y = 0.0f;

	bool isYaw = (x != mouse.x);
	bool isPitch = (y != mouse.y);

	if (isYaw)
		mYaw += mouse.deltaX;

	if (isPitch)
		mPitch += mouse.deltaY;

	if (mPitch > PITCH_MAX)
		mPitch = PITCH_MAX;

	if (mPitch < PITCH_MIN)
		mPitch = PITCH_MIN;

	x = mouse.x;
	y = mouse.y;

	UpdateCameraVectors();
}

void Camera::ProcessMouseScroll()
{

}

void Camera::ProcessInput(float timeStep)
{
	ProcessKeyboardButtonPress(timeStep);
	ProcessMouseMovement();
	ProcessMouseScroll();
}

void Camera::UpdateCameraVectors()
{
	mDirection.x = std::cos(glm::radians(mYaw)) * std::cos(glm::radians(mPitch));
	mDirection.y = std::sin(glm::radians(mPitch));
	mDirection.z = std::sin(glm::radians(mYaw)) * std::cos(glm::radians(mPitch));

	mDirection = glm::normalize(mDirection);
	mRight = glm::normalize(glm::cross(mDirection, WORLD_UP));
	mUp = glm::normalize(glm::cross(mRight, mDirection));
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(mPosition, mPosition + mDirection, mUp);
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return glm::perspective(glm::radians(mZoom), ASPECT_RATIO, NEAR_PLANE, FAR_PLANE);
}

glm::vec3 Camera::GetPosition() const
{
	return mPosition;
}