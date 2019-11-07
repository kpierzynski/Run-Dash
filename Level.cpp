#include <SFML/Graphics.hpp>

#include "Level.hpp"

Level::Level(sf::Texture* bgTexture){
	this->background.setTexture(*bgTexture);
}; 
