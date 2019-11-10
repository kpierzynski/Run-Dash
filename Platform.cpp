#include <SFML/Graphics.hpp>

#include <iostream>

#include "Platform.hpp"
#include "GameObject.hpp"

Platform::Platform( float x, float y, int spriteWidth, int spriteHeight, int scale ) : GameObject( x, y, spriteWidth, spriteHeight, scale ) {
	
	this->scale = scale;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;

	this->width = this->spriteWidth * this->scale;
	this->height = this->spriteHeight * this->scale;

	this->shape = new sf::RectangleShape( sf::Vector2f( this->width, this->height ) );
	this->shape->setPosition(x, y);

	this->shape->setOutlineColor(sf::Color::Red);
	this->shape->setOutlineThickness(5);

	this->setPosition(x, y);
	
}

void Platform::update() {

}
