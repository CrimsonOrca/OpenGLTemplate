#include "OpenGLTemplate.h"

namespace Utils {
	/*
		ensure Texture object's SetUnit(int) method was called prior to being passed in
		shader program(s): "layout (binding = <bind point>) uniform sampler2D <name>"
		<bind point> point should match 'mUnit' value of passed-in Texture object
	*/
	void Draw(std::string    name, 
		      Renderer&      renderer, 
		      Shader&        shader, 
		      Texture&       texture, 
		      Transformation transformation = Transformation()) 
	{
		shader.Use();
		texture.Bind();
		shader.SetMatrix("uModel", transformation.GetModelMatrix());
		renderer.Draw(name);
		texture.Unbind();
	}
};

int main()
{
	Window window;

	Time time;

	Camera camera { Position(0.0f, 5.0f, 10.0f) };

	Shader shader {
		"Assets/Shaders/stencil-testing/stencil-testing-vert.glsl",
		"Assets/Shaders/stencil-testing/stencil-testing-frag.glsl"
	};

	Shader borderColorShader {
		"Assets/Shaders/stencil-testing/stencil-testing-vert.glsl",
		"Assets/Shaders/stencil-testing/border-color-frag.glsl"
	};

	Texture marbleTexture { "Assets/Textures/marble.jpg" };
	marbleTexture.SetUnit(0);
	Texture concreteTexture { "Assets/Textures/concreteTexture.png" };
	concreteTexture.SetUnit(0);

	Renderer renderer;
	renderer.StoreMesh("cube1", std::make_unique<Cube>());
	renderer.StoreMesh("plane1", std::make_unique<Plane>());

	ObjectOutline::f1();

	while (!window.ShouldClose())
	{
		time.Start();

		// process inputs and events...
		window.ProcessInput();
		camera.ProcessInput(time.GetTimeStep());

		// set shader uniforms...
		shader.Use();
		shader.SetMatrix("uView", camera.GetViewMatrix());
		shader.SetMatrix("uProjection", camera.GetProjectionMatrix());

		borderColorShader.Use();
		borderColorShader.SetMatrix("uView", camera.GetViewMatrix());
		borderColorShader.SetMatrix("uProjection", camera.GetProjectionMatrix());
		
		// rendering commands...
		renderer.ClearScreen();

		ObjectOutline::f2();
		{
			Transformation transform;
			transform.Translate(0.0f, -1.01f, 0.0f);
			transform.Scale(5.0f, 0.0f, 5.0f);
			Utils::Draw("plane1", renderer, shader, concreteTexture, transform);
		}

		ObjectOutline::f3();
		{
			Utils::Draw("cube1", renderer, shader, marbleTexture);
		}
		{
			Transformation transformation;
			transformation.Translate(5, 0, 0);
			Utils::Draw("cube1", renderer, shader, marbleTexture, transformation);
		}

		ObjectOutline::f4();
		static float scale{ 1.05f };
		{
			Transformation transformation;
			transformation.Translate(0.0f, 0.0f, 0.0f);
			transformation.Scale(scale, scale, scale);
			Utils::Draw("cube1", renderer, borderColorShader, marbleTexture, transformation);
		}
		{
			Transformation transformation;
			transformation.Translate(5.0f, 0.0f, 0.0f);
			transformation.Scale(scale, scale, scale);
			Utils::Draw("cube1", renderer, borderColorShader, marbleTexture, transformation);
		}

		// color, depth, and stencil buffer reset...
		ObjectOutline::f5();

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}