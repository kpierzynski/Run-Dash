#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>

#include "./Background.hpp"
#include "../Objects/GameObject.hpp"

Background::Background(
		std::string filename,
		sf::Shape* shape
): GameObject(
	shape,
	sf::Vector2f(0.0f, 0.0f)
) {
	if(!this->bgTexture.loadFromFile(filename)) {
		throw std::invalid_argument("Wrong background image path");
	}

	this->shape->setTexture(&this->bgTexture);
}
