#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Window
{
public:
	Window(int width, int height);
	~Window();
private:
	int _width;
	int _height;
	GLFWwindow* _window;
};

#endif // !_WINDOW_H