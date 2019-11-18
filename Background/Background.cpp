#include <SFML/Graphics.hpp>
#include "./Background.hpp"

Background::Background(sf::Texture* bgTexture) {
	this->image.setTexture(*bgTexture);
	this->image.setPosition(0, -300);
}
