#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "Rectangle.h"
#include "Transformation.h"
#include "Camera.h"

const std::string PATH_PREFIX { "../../../../" };

int main()
{
	Window window;

	Time time;

	glm::vec3 cameraPosition(0.0f, 0.0f, 5.0f);
	Camera camera(cameraPosition);

	Shader shader { PATH_PREFIX + "Shaders/shader-vert.glsl" , PATH_PREFIX + "Shaders/shader-frag.glsl" };
	shader.Use();

	Texture awesomeface { PATH_PREFIX + "Textures/awesomeface.png" };
	awesomeface.Bind(1);

	Rectangle recMesh;

	glEnable(GL_DEPTH);

	while (!window.ShouldClose())
	{
		time.Start();

		// process inputs and events...
		window.ProcessInput();
		camera.ProcessInput(window, time.GetTimeStep());

		// set shader uniforms...
		Transformation model;
		model.Rotate(POSITIVE_Z_AXIS, 45.0f);
		shader.SetMatrix("model", model.GetModelMatrix());
		shader.SetMatrix("view", camera.GetViewMatrix());
		shader.SetMatrix("projection", camera.GetProjectionMatrix());

		// rendering commands...
		window.ClearScreen();
		glClear(GL_DEPTH_BUFFER_BIT);

		recMesh.Render();

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}