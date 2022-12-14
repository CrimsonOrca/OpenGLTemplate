#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Constants.h"

const int OPENGL_VERSION_MAJOR { 4 };
const int OPENGL_VERSION_MINOR { 3 };

struct Mouse
{
	float x;
	float y;
	float deltaX;
	float deltaY;
};

struct Input
{
	GLFWwindow* window;
};

class Window
{
	public:
		Window(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
		~Window();
		int GetWidth() const;
		int GetHeight() const;
		int Initialize();
		int ShouldClose();
		void ProcessInput();
		void SwapBuffers();
		void ProcessEvents();
		static void CursorPositionCallback(GLFWwindow* window, double x, double y);
		static void ScrollCallback(GLFWwindow* window, double x, double y);
		static Mouse GetMouse();
		static void SetCursorPosition(float x, float y);
		static void SetCursorPositionOffset(float xDelta, float yDelta);
		static Input GetInput();
	private:
		int _width;
		int _height;
		GLFWwindow* _window;
		static Mouse mMouse;
		static Input mInput;
};

#endif