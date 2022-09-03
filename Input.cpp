#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Box", sf::Style::Close);

	sf::CircleShape box;
	box.setRadius(25.f);
	box.setPointCount(3);
	box.setFillColor(sf::Color(255, 255, 255, 0));
	box.setOutlineThickness(1.f);
	box.setOutlineColor(sf::Color::White);
	box.setOrigin(25.f, 25.f);
	box.setPosition(320.f, 240.f);

	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(310.f, 240.f), sf::Color::Yellow),
		sf::Vertex(sf::Vector2f(330.f, 240.f), sf::Color::Green),
		sf::Vertex(sf::Vector2f(320.f, 230.f), sf::Color::Green),
		sf::Vertex(sf::Vector2f(320.f, 250.f), sf::Color::Yellow)
	};

	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(10.f, 10.f));
	convex.setPoint(1, sf::Vector2f(610.f, 10.f));
	convex.setPoint(2, sf::Vector2f(610.f, 450.f));
	convex.setPoint(3, sf::Vector2f(10.f, 450.f));
	convex.setOrigin(310.f, 230.f);
	convex.setPosition(320.f, 240.f);
	convex.setFillColor(sf::Color(255, 255, 255, 31));

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
						case sf::Keyboard::Escape:
							window.close();
						default:
							break;
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && box.getPosition().x - 25.f > 0)
			box.move(-1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && box.getPosition().x + 25.f < 640)
			box.move(1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && box.getPosition().y - 25.f > 0)
			box.move(0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && box.getPosition().y + 25.f < 480)
			box.move(0.f, 1.f);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (mousePos.x < 25)
				mousePos.x = 25;
			if (mousePos.x > 615) // 640 - 25
				mousePos.x = 615; 
			if (mousePos.y < 25)
				mousePos.y = 25;
			if (mousePos.y > 455) // 480 - 25
				mousePos.y = 455;
			box.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}

		window.clear();
		box.rotate(angle);
		window.draw(convex);
		window.draw(line, 4, sf::Lines);
		window.draw(box);
		window.display();
	}
}
