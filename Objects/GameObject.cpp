#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <iterator>
#include <vector>
#include <iostream>

#include "./GameObject.hpp"

GameObject::GameObject(sf::Shape* shape, sf::Vector2f coords) {
	this->shape = shape;
	this->shape->setPosition(coords);
}

GameObject::GameObject(sf::Shape* shape, float x, float y) {
	this->shape = shape;
	this->shape->setPosition(x, y);
}

void GameObject::addComponent(Component* component) {
	this->components.push_back(component);	
}

void GameObject::getComponent(std::string name) {
	std::cout << typeid(GameObject).name() << std::endl;
	std::cout << name << std::endl;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*this->shape);
}

TestGO::TestGO(sf::Shape* shape, sf::Vector2f coords): GameObject(shape, coords) {}
