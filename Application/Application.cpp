#include "OpenGLTemplate.h"

int main()
{
	Window window;

	Time time;

	glm::vec3 cameraPosition {0.0f, 0.0f, 10.0f};
	Camera camera {cameraPosition};

	Shader lightingShader("Assets/Shaders/basic-lighting-vert.glsl", "Assets/Shaders/basic-lighting-frag.glsl");
	lightingShader.Use();

	Renderer renderer;
	renderer.EnableDepthTesting();
	renderer.SetMesh<Cube>();

	while (!window.ShouldClose())
	{
		time.Start();

		// process inputs and events...
		window.ProcessInput();
		camera.ProcessInput(time.GetTimeStep());

		// set shader uniforms...
		Transformation model;
		lightingShader.SetVector("uViewPosition", camera.GetPosition());
		lightingShader.SetMatrix("uModel", model.GetModelMatrix());
		lightingShader.SetMatrix("uView", camera.GetViewMatrix());
		lightingShader.SetMatrix("uProjection", camera.GetProjectionMatrix());

		// rendering commands...
		renderer.ClearScreen();

		renderer.Draw();
	
		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}