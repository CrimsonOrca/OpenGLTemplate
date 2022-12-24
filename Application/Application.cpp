#include "OpenGLTemplate.h"

void DrawWoodenContainers(Shader&, Renderer&);

int main()
{
	Window window;

	Time time;

	Position cameraPosition = { 0.0f, 0.0f, 10.0f };
	Camera camera = cameraPosition;

	Shader shader("Assets/Shaders/multiple-lights-vert.glsl", "Assets/Shaders/multiple-lights-frag.glsl");

	Shader lightShader("Assets/Shaders/shader-vert.glsl", "Assets/Shaders/shader-frag.glsl");

	Texture woodenContainerTexture("Assets/Textures/container2.png");
	Texture steelBorderTexture("Assets/Textures/container2_specular.png");

	Renderer renderer;
	renderer.EnableDepthTesting();
	renderer.AddMesh<Cube>("Cube0");
	renderer.AddMesh<Sphere>("Sphere0");

	const int NUMBER_POINT_LIGHT_POSITIONS = 4;
	const Position pointLightPositions[] = {
		Position( 0.7f,  0.2f,  4.0f),
		Position( 2.3f, -3.3f, -4.0f),
		Position(-4.0f,  2.0f, -12.0f),
		Position( 0.0f,  0.0f, -3.0f)
	};

	const Color BLACK = { 0.0f, 0.0f, 0.0f };
	const Color GREEN = { 0.0f, 1.0f, 0.0f };
	const Color WHITE = { 1.0f, 1.0f, 1.0f };

	while (!window.ShouldClose())
	{
		time.Start();

		// process inputs and events...
		window.ProcessInput();
		camera.ProcessInput(time.GetTimeStep());

		// bind texture units ...
		shader.Use();
		shader.SetInt("uMaterial.diffuse", 0);
		shader.SetInt("uMaterial.specular", 1);
		woodenContainerTexture.Bind(0);
		steelBorderTexture.Bind(1);
		
		// set shader uniforms...
		shader.Use();
		//Transformation transformation;
		//shader.SetMatrix("uModel", transformation.GetModelMatrix());
		shader.SetMatrix("uView", camera.GetViewMatrix());
		shader.SetMatrix("uProjection", camera.GetProjectionMatrix());
		shader.SetVector("uViewPosition", camera.GetPosition());

		shader.SetFloat("uMaterial.shininess", 32.0f);

		shader.SetVector("uDirectionalLight.direction", Position(5.0f, 5.0f, 5.0f));
		shader.SetVector("uDirectionalLight.light.ambient", BLACK);
		shader.SetVector("uDirectionalLight.light.diffuse", GREEN);
		shader.SetVector("uDirectionalLight.light.specular", WHITE);

		for (int i = 0; i < NUMBER_POINT_LIGHT_POSITIONS; i++)
		{
			shader.SetVector("uPointLights[" + std::to_string(i) + "].light.ambient", BLACK);
			shader.SetVector("uPointLights[" + std::to_string(i) + "].light.diffuse", GREEN);
			shader.SetVector("uPointLights[" + std::to_string(i) + "].light.specular", WHITE);
			shader.SetVector("uPointLights[" + std::to_string(i) + "].position", pointLightPositions[i]);
			shader.SetFloat("uPointLights[" + std::to_string(i) + "].constant", 1.0f);
			shader.SetFloat("uPointLights[" + std::to_string(i) + "].linear", 0.09f);
			shader.SetFloat("uPointLights[" + std::to_string(i) + "].quadratic", 0.032f);
		}

		// rendering commands...
		renderer.ClearScreen(); 
		DrawWoodenContainers(shader, renderer);

		lightShader.Use();
		lightShader.SetMatrix("uView", camera.GetViewMatrix());
		lightShader.SetMatrix("uProjection", camera.GetProjectionMatrix());
		for (const auto& position : pointLightPositions)
		{
			Transformation transformation;
			transformation.Scale(0.5f, 0.5f, 0.5f);
			transformation.Translate(position.x, position.y, position.z);
			lightShader.SetMatrix("uModel", transformation.GetModelMatrix());
			renderer.Draw("Sphere0");
		}

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}

void DrawWoodenContainers(Shader& shader, Renderer& renderer)
{
	static const int numCubePositions = 10;

	static const Position cubePositions[numCubePositions] = {
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

	for (int i = 0; i < numCubePositions; i++)
	{
		Transformation transformation;
		transformation.Translate(cubePositions[i].x, cubePositions[i].y, cubePositions[i].z);
		float angle = 20.0f * i;
		transformation.Rotate(glm::normalize(glm::vec3(1.0f, 0.3f, 0.5f)), angle);
		shader.SetMatrix("uModel", transformation.GetModelMatrix());
		renderer.Draw("Cube0");
	}
}