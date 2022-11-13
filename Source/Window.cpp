#include <iostream>

#include "Window.h"

Window::Window(int width, int height)
    : _width  {width}
    , _height {height}
    , _window {nullptr}
{
    if (!Initialize())
    {
        std::cout << "FAILED WINDOW OBJECT INITIALIZATION..." << std::endl;
    }

    glViewport(0, 0, _width, _height);

}

Window::~Window()
{
    glfwTerminate();
}

int Window::GetWidth() const
{
    return _width;
}

int Window::GetHeight() const
{
    return _height;
}

int Window::Initialize()
{
    if (!glfwInit())
    {
        std::cout << "FAILED TO INTIALIZE GLFW..." << std::endl;
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(_width, _height, "", nullptr, nullptr);
    if (_window == NULL)
    {
        std::cout << "FAILED TO CREATE GLFW WINDOW..." << std::endl;
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FAILED TO INITIALIZE GLAD..." << std::endl;
        return 0;
    }

    return 1;
}

int Window::ShouldClose()
{
    return glfwWindowShouldClose(_window);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(_window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}