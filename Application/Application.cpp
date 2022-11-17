#include "Window.h"
#include "Triangle.h"
#include "Shader.h"

int main()
{
	const int windowWidth{ 800 };
	const int windowHeight{ 600 };
	Window window{ windowWidth, windowHeight };

	std::string path = "C:/Users/basir/Tutorials/Computer Graphics/OpenGL/OpenGLTemplate/Shaders/";
	Shader triangleShader{ path + "shader.vert", path + "shader.frag" };
	triangleShader.UseShader();

	Triangle triangleMesh;

	while (!window.ShouldClose())
	{	
		// inputs...
		window.ProcessInput();

		// rendering commands...
		window.ClearScreen();

		triangleMesh.RenderMesh();

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}