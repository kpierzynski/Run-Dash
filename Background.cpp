#include <SFML/Graphics.hpp>

#include "Background.hpp"

Background::Background(sf::Texture* bgTexture){
	this->image.setTexture(*bgTexture);
}; 
