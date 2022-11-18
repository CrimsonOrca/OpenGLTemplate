#include "Window.h"

int main()
{
	const int windowWidth{ 800 };
	const int windowHeight{ 600 };
	Window window{ windowWidth, windowHeight };



	while (!window.ShouldClose())
	{	
		// inputs...
		window.ProcessInput();

		// rendering commands...
		window.ClearScreen();

		// check and call events, swap the front and back buffers...
		window.SwapBuffers();
		window.ProcessEvents();
	}

	return 0;
}