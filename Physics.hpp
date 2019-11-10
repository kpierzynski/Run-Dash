#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Physics {

	protected:
		b2BodyDef objectDef;
		b2PolygonShape objectShape;
		b2FixtureDef objectFixtureDef;

		b2Body * object;
	public:
		Physics( float x, float y, float width, float heigh, float density, float friction, b2BodyType bodyType, b2World * world );

		virtual void update() = 0;



};


#endif
