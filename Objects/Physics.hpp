#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class Physics : public b2World {
	private:

	public:
		Physics();

		void update( sf::Time elapsed );
};	

#endif
