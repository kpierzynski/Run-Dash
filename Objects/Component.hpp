#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <SFML/Graphics.hpp>

class GameObject;

class Component {

	protected:
		GameObject* parent;
	
	public:
		virtual void update( sf::Time elapsed ) = 0;
		Component(GameObject* parent);
};


#endif
