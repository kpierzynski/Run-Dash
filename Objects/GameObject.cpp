#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <vector>

#include "./GameObject.hpp"

template<typename T>
GameObject<T>::GameObject(sf::Shape* shape, sf::Vector2f coords) {
	this->shape = shape;
	this->shape->setPosition(coords);
}

template<typename T>
GameObject<T>::GameObject(sf::Shape* shape, float x, float y) {
	this->shape = shape;
	this->shape->setPosition(x, y);
}

template<typename T>
void GameObject<T>::addComponent(T* component) {
	this->components.push_back(*component);	
}

template<typename T>
std::vector<T> GameObject<T>::getComponent() {
	std::vector<T> result;
	
	for(int i = 0; i < this->components.size(); i++) {
		if(typeid(T).name() == typeid(result[i]).name())
			result.push_back(result[i]);
	}

	return result;
}
