#include <SFML/Graphics.hpp>
#include <iterator>
#include <vector>
#include <stdexcept>

#include "./GameObject.hpp"
#include "Component.hpp"

GameObject::GameObject(sf::Shape* shape, sf::Vector2f coords) {
	this->shape = shape;
	this->shape->setPosition(coords);
}

GameObject::GameObject(sf::Shape* shape, float x, float y) {
	this->shape = shape;
	this->shape->setPosition(x, y);
}

void GameObject::addComponent(Component* component) {
	for(size_t i = 0; i < this->components.size(); i++) {
		//Sprawdzamy czy oba wskaźniki wskazują na ten sam komponent
		//Jeżeli tak to nie dodajemy
		if(component == this->components[i]) {
			throw std::invalid_argument("Cannot add the same component twice.");		
		}
	}
	this->components.push_back(component);	
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*this->shape);
}

void GameObject::update() {
	for( size_t i = 0; i < this->components.size(); i++ ) this->components[i]->update();
}

sf::Vector2f GameObject::getPosition() {
	return this->shape->getPosition();
}

void GameObject::setPosition(float x, float y) {
	this->setPosition( sf::Vector2f(x,y) );
}

void GameObject::setPosition(sf::Vector2f pos) {
	this->shape->setPosition(pos);
}

