#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Component;

template<typename T>
class GameObject {

	private:
		sf::Shape* shape;
		std::vector<T> components;
	
	public:
		GameObject(sf::Shape* shape, sf::Vector2f coords);
		GameObject(sf::Shape* shape, float x, float y);

		void addComponent(T* component);
		std::vector<T> getComponent();
};

#endif
