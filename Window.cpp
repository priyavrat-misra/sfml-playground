#include <SFML/Window.hpp>
#include <iostream>

int main() {
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	std::cout << "Is window valid? " << mode.isValid() << std::endl;
	std::cout << "Opening a "
		<< mode.width << "x" << mode.height
		<< " (" << mode.bitsPerPixel << " bpp)"
		<< "window." << std::endl;

	// creates an unresizable window
	sf::Window window(mode, "Hello Window!", sf::Style::Titlebar | sf::Style::Close);

	// another approach:
	// sf::Window window;
	// window.create(sf::VideoMode(640, 480), "Title", sf::Style::Default);
	
	// change the position of the window (relatively to the desktop)
	// window.setPosition(sf::Vector2i(10, 10));

	// change the title of the window
	window.setTitle("New Title!");

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
