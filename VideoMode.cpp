#include <SFML/Window.hpp>
#include <iostream>

int main() {
	// Display the list of all the video modes available for fullscreen
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	for (sf::VideoMode& mode : modes) {
		std::cout << mode.width << "x" << mode.height << " - "
			<< mode.bitsPerPixel << " bpp" << std::endl;
	}
	
	// Display desktop mode
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	std::cout << "Desktop"  << "\t" 
		<< mode.width << "x" << mode.height << " - "
		<< mode.bitsPerPixel << " bpp" << std::endl;
}
