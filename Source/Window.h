#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Constants.h"

const int OPENGL_VERSION_MAJOR { 4 };
const int OPENGL_VERSION_MINOR { 2 };

struct Mouse
{
	float x = 0.0f;
	float y = 0.0f;
	float deltaX = 0.0f;
	float deltaY = 0.0f;
};

class Window
{
	public:
		Window(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
		~Window();
		int GetWidth() const;
		int GetHeight() const;
		GLFWwindow* GetWindowPointer();
		int Initialize();
		int ShouldClose();
		void ProcessInput();
		void ClearScreen();
		void SwapBuffers();
		void ProcessEvents();
		static void CursorPositionCallback(GLFWwindow* window, double x, double y);
		static void ScrollCallback(GLFWwindow* window, double x, double y);
		Mouse GetMouse() const;
	private:
		int _width;
		int _height;
		GLFWwindow* _window;
		Mouse mMouse;
};

#endif // !_WINDOW_H