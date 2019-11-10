#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <iostream>

#include "Physics.hpp"

Physics::Physics( float x, float y, float width, float height, float density, float friction, b2BodyType bodyType, b2World * world ) {


	this->objectDef.type = bodyType;
	this->objectDef.position.Set( x, y );

	object = world->CreateBody(&this->objectDef);
	
	this->objectShape.SetAsBox( width, height );
	
	this->objectFixtureDef.shape = &this->objectShape;
	this->objectFixtureDef.density = density;
	this->objectFixtureDef.friction = friction;

	this->object->CreateFixture( &this->objectFixtureDef );
}
