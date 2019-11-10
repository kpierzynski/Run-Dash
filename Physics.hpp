#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

class Physics {

	private:
		GameObject * object;

		sf::Vector2f force;
		sf::Vector2f acceleration;
		sf::Vector2f velocity;

		float mass;

	public:

		Physics( GameObject * object, float mass );

		GameObject * getObject();
 
		void update( sf::Time elapsed );
		
		void applyGravity();

		void addForce( sf::Vector2f force );
		void addVelocity( sf::Vector2f velocity );
		void setVelocity( sf::Vector2f velocity );
};

class PhysicsManager {
	
	private:
		std::vector<Physics *> objects;		
	public:
		PhysicsManager();
		
		void update();
		void addObject( Physics * object );
};

#endif
