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

    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

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

GLFWwindow* Window::GetWindow()
{
    return _window;
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

void Window::ProcessInput()
{
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(_window, true);
    }
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(_window);
}

void Window::ClearScreen()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::ProcessEvents()
{
    glfwPollEvents();
}