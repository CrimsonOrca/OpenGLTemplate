#include <iostream>

#include "Window.h"

Mouse Window::mMouse { 0.0f, 0.0f, 0.0f, 0.0f };

Input Window::mInput { nullptr };

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

Mouse Window::GetMouse()
{ 
    return mMouse;
}

Input Window::GetInput() 
{ 
    return mInput; 
}

void Window::SetCursorPosition(float x, float y)
{
    mMouse.x = x;
    mMouse.y = y;
}

void Window::SetCursorPositionOffset(float xDelta, float yDelta)
{
    mMouse.deltaX = xDelta;
    mMouse.deltaY = yDelta;
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

    mInput.window = _window;

    if (_window == NULL)
    {
        std::cout << "FAILED TO CREATE GLFW WINDOW..." << std::endl;
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(_window);

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

void Window::ProcessEvents()
{
    glfwPollEvents();
}

void Window::CursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
    float x { static_cast<float>(xPos) };
    float y { static_cast<float>(yPos) };

    static bool isFirst { true };
    if (isFirst)
    {
        SetCursorPosition(x, y);
        isFirst = false;
    }

    SetCursorPositionOffset(x - mMouse.x, mMouse.y - y);
    SetCursorPosition(x, y);
}

void Window::ScrollCallback(GLFWwindow* window, double x, double y)
{
    
}