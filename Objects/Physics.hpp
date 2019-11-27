#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#define PIXELS2METERS 0.02f
#define METERS2PIXELS 50.0f

class Physics : public b2World {
	private:

	public:
		Physics();

		void update( sf::Time elapsed );
};	

#endif
