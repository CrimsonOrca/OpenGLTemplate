#include "OpenGLTemplate.h"

int main()
{
	Window window;

	Time time;

	glm::vec3 cameraPosition {0.0f, 0.0f, 10.0f};
	Camera camera {cameraPosition};

	Shader shader { "Assets/Shaders/shader-vert.glsl" , "Assets/Shaders/shader-frag.glsl" };
	shader.Use();

	Renderer renderer;
	renderer.EnableDepthTesting();
	renderer.SetMesh<Sphere>();

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
		renderer.ClearScreen();
		renderer.ShowWireFrame();
		renderer.Draw();
	
		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}