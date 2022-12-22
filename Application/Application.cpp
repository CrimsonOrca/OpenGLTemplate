#include "OpenGLTemplate.h"

int main()
{
	Window window;

	Time time;

	glm::vec3 cameraPosition {0.0f, 0.0f, 10.0f};
	Camera camera {cameraPosition};

	Shader materialsShader("Assets/Shaders/light-casters-vert.glsl", "Assets/Shaders/light-casters-frag.glsl");
	materialsShader.Use();

	Texture containerTexture("Assets/Textures/container2.png");
	Texture steelBorderTexture("Assets/Textures/container2_specular.png");

	Renderer renderer;
	renderer.EnableDepthTesting();
	renderer.SetMesh<Cube>();

	Position cubePositions[] = {
		Position( 0.0f,  0.0f,  0.0f),
		Position( 2.0f,  5.0f, -15.0f),
		Position(-1.5f, -2.2f, -2.5f),
		Position(-3.8f, -2.0f, -12.3f),
		Position( 2.4f, -0.4f, -3.5f),
		Position(-1.7f,  3.0f, -7.5f),
		Position( 1.3f, -2.0f, -2.5f),
		Position( 1.5f,  2.0f, -2.5f),
		Position( 1.5f,  0.2f, -1.5f),
		Position(-1.3f,  1.0f, -1.5f)
	};

	while (!window.ShouldClose())
	{
		time.Start();

		// process inputs and events...
		window.ProcessInput();
		camera.ProcessInput(time.GetTimeStep());

		// bind texture units ... 
		containerTexture.Bind(0);
		materialsShader.SetInt("uMaterial.diffuse", 0);
		containerTexture.Bind(1);
		materialsShader.SetInt("uMaterial.specular", 1);

		// set shader uniforms...
		materialsShader.SetMatrix("uView", camera.GetViewMatrix());
		materialsShader.SetMatrix("uProjection", camera.GetProjectionMatrix());
		materialsShader.SetVector("uViewPosition", camera.GetPosition());
		materialsShader.SetFloat("uMaterial.shininess", 32.0f);
		materialsShader.SetVector("uLight.direction", glm::normalize(glm::vec3(-0.2f, -1.0f, -0.3f)));
		materialsShader.SetVector("uLight.ambient", Color(0.2f, 0.2f, 0.2f));
		materialsShader.SetVector("uLight.diffuse", Color(0.5f, 0.5f, 0.5f));
		materialsShader.SetVector("uLight.specular", Color(1.0f, 1.0f, 1.0f));

		// rendering commands...
		renderer.ClearScreen();

		for (int i = 0; i < 10; i++)
		{
			Transformation model;
			model.Translate(cubePositions[i].x, cubePositions[i].y, cubePositions[i].z);
			float angle = 20.0f * i;
			model.Rotate(glm::normalize(glm::vec3(1.0f, 0.3f, 0.5f)), angle);
			materialsShader.SetMatrix("uModel", model.GetModelMatrix());
			renderer.Draw();
		}
	
		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}