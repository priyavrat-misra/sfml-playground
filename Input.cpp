#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Box", sf::Style::Close);
	sf::CircleShape box;
	box.setRadius(25.f);
	box.setPointCount(3);
	box.setFillColor(sf::Color(255, 255, 255));
	box.setOrigin(25.f, 25.f);
	box.setPosition(320.f, 240.f);
	float angle = 0.f;
	std::size_t pointCount = box.getPointCount();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::KeyPressed:
					switch (event.key.code) {
						case sf::Keyboard::Right:
							++angle;
							break;
						case sf::Keyboard::Left:
							--angle;
							break;
						case sf::Keyboard::Up:
							pointCount += 1;
							box.setPointCount(pointCount);
							break;
						case sf::Keyboard::Down:
							pointCount -= pointCount > 3;
							box.setPointCount(pointCount);
							break;
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			box.move(-1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			box.move(1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			box.move(0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			box.move(0.f, 1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			box.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}

		window.clear();
		box.rotate(angle);
		window.draw(box);
		window.display();
	}
}
