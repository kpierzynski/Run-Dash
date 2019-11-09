#include <SFML/Graphics.hpp>

#include <iostream>

#include "GameObject.hpp"

void GameObject::setPosition( float x, float y ) {
	this->x = x;
	this->y = y;
	this->shape->setPosition( this->x, this->y );
}

void GameObject::setPosition( sf::Vector2f position ) {
	this->setPosition(position.x, position.y);
}

sf::Vector2f GameObject::getPosition() {
	return sf::Vector2f( this->x, this->y );
}

void GameObject::setScale( int scale ) {
	this->scale = scale;
}

int GameObject::getScale() {
	return this->scale;
}

sf::Vector2i GameObject::getSize() {
	return sf::Vector2i( this->width, this->height );
}

void GameObject::move(float dx, float dy) {
	this->x += dx;
	this->y += dy;
	this->shape->move( dx, dy );
}

void GameObject::move(sf::Vector2f dPosition) {
	this->move( dPosition.x, dPosition.y );
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const {

	target.draw( *this->shape );

}
