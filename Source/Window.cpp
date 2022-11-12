#include <iostream>

#include "Window.h"

Window::Window(int width, int height)
	: _width  {width}
	, _height {height}
{
    if (glfwInit() != GLFW_TRUE)
    {
        std::cout << "FAILED TO INTIALIZE GLFW..." << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    _window = glfwCreateWindow(_width, _height, "", NULL, NULL);
    if (_window == NULL)
    {
        std::cout << "FAILED TO CREATE GLFW WINDOW..." << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FAILED TO INITIALIZE GLAD..." << std::endl;
    }

    glViewport(0, 0, _width, _height);

    while (!glfwWindowShouldClose(_window))
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

}

Window::~Window()
{
    glfwTerminate();
}
