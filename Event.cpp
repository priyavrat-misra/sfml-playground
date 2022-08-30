#include <iostream>
#include <string>
#include <SFML/Window.hpp>

int main() {
	sf::Window window(sf::VideoMode(640, 480), "Resize to change title.", sf::Style::Default);
	window.setFramerateLimit(60);
	sf::Vector2u size = window.getSize();
	unsigned int w = size.x, h = size.y;
	std::cout << "Opening a " << w << "x" << h << " window." << std::endl;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Resized) {
				w = event.size.width;
				h = event.size.height;
				std::cout << "Resized window to " << w << "x" << h << std::endl;
				window.setTitle(std::to_string(w) + 'x' + std::to_string(h));
			}

			if (event.type == sf::Event::LostFocus) // can be used to pause game
				std::cout << "Window out of focus." << std::endl;
			if (event.type == sf::Event::GainedFocus) // can be used to resume game
				std::cout << "Window in focus." << std::endl;

			if (event.type == sf::Event::TextEntered)
				if (event.text.unicode < 128)
					std::cout << "ASCII character typed: " << (char) event.text.unicode << std::endl;

			if (event.type == sf::Event::MouseEntered)
				std::cout << "Cursor entered the window." << std::endl;
			if (event.type == sf::Event::MouseLeft)
				std::cout << "Cursor left the window." << std::endl;
			if (event.type == sf::Event::MouseMoved) {
				std::cout << "Cursor coordinates: ("
					<< std::to_string(event.mouseMove.x) << ", "
					<< std::to_string(event.mouseMove.y) << ")"
					<< std::endl;
			}

			if (
					event.type == sf::Event::Closed ||
					event.type == sf::Event::KeyPressed &&
					event.key.code == sf::Keyboard::Escape
			) {
				std::cout << "Window closed." << std::endl;
				window.close();
			}
		}
	}
}
