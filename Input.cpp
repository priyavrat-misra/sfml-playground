#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Box", sf::Style::Close);
	sf::RectangleShape box(sf::Vector2f(50.f, 50.f));
	box.setFillColor(sf::Color::White);
	box.setOrigin(25.f, 25.f);
	box.setPosition(320.f, 240.f);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			box.move(-1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			box.move(1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			box.move(0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			box.move(0.f, 1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			box.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}

		window.clear();
		window.draw(box);
		window.display();
	}
}
