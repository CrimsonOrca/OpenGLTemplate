#include "Window.h"

int main()
{
	Window window{ 800, 600 };
	
	while (!window.ShouldClose())
	{

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}