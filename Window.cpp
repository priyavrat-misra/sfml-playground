#include <SFML/Window.hpp>
#include <iostream>

int main() {
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	std::cout << "Is window valid? " << mode.isValid() << std::endl;
	std::cout << "Opening a "
		<< mode.width << "x" << mode.height
		<< " (" << mode.bitsPerPixel << " bpp)"
		<< "window." << std::endl;
	sf::Window window(mode, "Hello Window!", sf::Style::Titlebar);
	// another approach:
	// sf::Window window;
	// window.create(sf::VideoMode(640, 480), "Title", sf::Style::Default);

	// run the following as long as the window is open
	while (window.isOpen()) {
		// keep track of all the events that were triggered
		// e.g., movement of mouse, key press, resize, close etc.
		sf::Event event;
		while (window.pollEvent(event))
			// close window requested
			if (event.type == sf::Event::Closed) {
				std::cout << "Window closed." << std::endl;
				window.close();
			}
	}
}
