#include "graphics/Window.hpp"

int main(void)
{
	using namespace pong;
	using namespace graphics;

	Window window("Pong!", 800, 600);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	while (!window.closed()) {
		window.clear();
		window.update();
	}


	return(0);
}