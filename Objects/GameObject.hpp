#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Component;

class GameObject {

	private:
		sf::Shape* shape;
		std::vector<Component*> components;
	
	public:
		GameObject(sf::Shape* shape, sf::Vector2f coords);
		GameObject(sf::Shape* shape, float x, float y);

		void addComponent(Component* component);
		void getComponent(std::string name);
};

#endif
