#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Component;

class GameObject: public sf::Drawable {

	private:
		std::vector<Component*> components;
	
	public:
		sf::Shape* shape;
		GameObject(sf::Shape* shape, sf::Vector2f coords);
		GameObject(sf::Shape* shape, float x, float y);

		void addComponent(Component* component);
		void getComponent(std::string name);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class TestGO: public GameObject {
	public:
		TestGO(sf::Shape* shape, sf::Vector2f coords);
};

#endif
