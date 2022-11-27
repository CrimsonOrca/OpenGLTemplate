#include <iostream>

#include "Window.h"

Window::Window(int width, int height)
    : _width  {width}
    , _height {height}
    , _window {NULL}
{
    if (!Initialize())
    {
        std::cout << "FAILED WINDOW OBJECT INITIALIZATION..." << std::endl;
    }
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

GLFWwindow* Window::GetWindowPointer()
{
    return _window;
}

Mouse Window::GetMouse() const 
{ 
    return mMouse;
}

int Window::Initialize()
{
    if (!glfwInit())
    {
        std::cout << "FAILED TO INTIALIZE GLFW..." << std::endl;
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(_width, _height, "", NULL, NULL);

    if (_window == NULL)
    {
        std::cout << "FAILED TO CREATE GLFW WINDOW..." << std::endl;
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(_window);

    glfwSetWindowUserPointer(_window, this);

    glfwSetCursorPosCallback(_window, CursorPositionCallback);

    glfwSetScrollCallback(_window, ScrollCallback);

    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

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

void Window::CursorPositionCallback(GLFWwindow* window, double mousePositionX, double mousePositionY)
{
    auto* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

    float& x = w->mMouse.x;
    float& y = w->mMouse.y;
    float& deltaX = w->mMouse.deltaX;
    float& deltaY = w->mMouse.deltaY;

    float xCurrent = static_cast<float>(mousePositionX);
    float yCurrent = static_cast<float>(mousePositionY);

    static bool isFirst = true;

    if (isFirst)
    {
        x = xCurrent;
        y = yCurrent;
        isFirst = false;
    }

    deltaX = xCurrent - x;
    deltaY = y - yCurrent;

    x = xCurrent;
    y = yCurrent;
}

void Window::ScrollCallback(GLFWwindow* window, double x, double y)
{
    Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

}