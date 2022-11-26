#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "Rectangle.h"
#include "Transformation.h"

int main()
{
	const int windowWidth{ 800 };
	const int windowHeight{ 600 };
	Window window{ windowWidth, windowHeight };

	Shader shader{ "../../../../Shaders/shader-vert.glsl" , "../../../../Shaders/shader-frag.glsl" };
	shader.Use();

	Texture woodContainer("../../../../Textures/container.jpg");
	Texture awesomeface("../../../../Textures/awesomeface.png");

	woodContainer.Bind(0);
	awesomeface.Bind(1);

	Rectangle recMesh;

	while (!window.ShouldClose())
	{
		// inputs...
		window.ProcessInput();

		// rendering commands...
		window.ClearScreen();

		recMesh.Render();

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}