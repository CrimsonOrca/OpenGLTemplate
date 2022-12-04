#include "OpenGLTemplate.h"
#include <memory>

int main()
{
	Window window;

	Time time;

	glm::vec3 cameraPosition {0.0f, 0.0f, 5.0f};
	Camera camera {cameraPosition};

	Shader shader { "Assets/Shaders/shader-vert.glsl" , "Assets/Shaders/shader-frag.glsl" };
	shader.Use();

	Texture awesomeface { "Assets/Textures/awesomeface.png" };
	awesomeface.Bind(1);

	glEnable(GL_DEPTH);

	Quad quadMesh;
	Renderer renderer;
	renderer.SetMesh(quadMesh);

	while (!window.ShouldClose())
	{
		time.Start();

		// process inputs and events...
		window.ProcessInput();
		camera.ProcessInput(time.GetTimeStep());

		// set shader uniforms...
		Transformation model;
		shader.SetMatrix("uModel", model.GetModelMatrix());
		shader.SetMatrix("uView", camera.GetViewMatrix());
		shader.SetMatrix("uProjection", camera.GetProjectionMatrix());

		// rendering commands...
		window.ClearScreen();
		glClear(GL_DEPTH_BUFFER_BIT);

		renderer.Draw();

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}