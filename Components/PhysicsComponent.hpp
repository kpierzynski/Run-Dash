#ifndef PHYSICSCOMPONENT_H_
#define PHYSICSCOMPONENT_H_

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "../Objects/Component.hpp"
#include "../Objects/GameObject.hpp"
#include "../Objects/Physics.hpp"

class PhysicsComponent : public Component {

	private:
		b2Body * body;
	public:
		enum BodyType { dynamicBody = b2_dynamicBody, staticBody = b2_staticBody };

		PhysicsComponent( GameObject * parent, BodyType bodyType, float density, float friction, Physics * world );
		void update();

};

#endif
