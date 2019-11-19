#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "../Objects/Component.hpp"
#include "../Objects/GameObject.hpp"

class PhysicsComponent : public Component {

	private:
		b2Body * body;
	public:
		PhysicsComponent( GameObject * parent, b2BodyType bodyType, float density, float friction, b2World * world );
		void update();

};
