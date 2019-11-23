#include <SFML/Graphics.hpp>

#include "./Background.hpp"
#include "../Objects/GameObject.hpp"

Background::Background(
		sf::Shape* shape, 
		sf::Texture* bgTexture

): GameObject(
	shape,
	sf::Vector2f(0.0f, 0.0f)

) {
	this->shape->setTexture(bgTexture);
}
