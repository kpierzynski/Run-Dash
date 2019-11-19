#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "Physics.hpp"

Physics::Physics() : b2World( b2Vec2(0.0f, 9.8f) ){

}

void Physics::update( sf::Time elapsed ) {
	this->Step(elapsed.asSeconds(), 8, 3);
}
