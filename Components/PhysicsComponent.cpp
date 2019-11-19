#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "PhysicsComponent.hpp"
#include "../Objects/GameObject.hpp"
#include "../Objects/Component.hpp"

PhysicsComponent::PhysicsComponent( GameObject * parent, b2BodyType bodyType, float density, float friction, b2PolygonShape * shape, b2World * world ) : Component(parent) {
	
	b2BodyDef bodyDef;
	bodyDef.type = bodyType;
	bodyDef.position.Set( parent->shape->getPosition().x, parent->shape->getPosition().y );

	this->body = world->CreateBody(&bodyDef);

	b2FixtureDef bodyFixtureDef;
	bodyFixtureDef.shape = shape;
	bodyFixtureDef.density = density;
	bodyFixtureDef.friction = friction;

	this->body->CreateFixture(&bodyFixtureDef);

}

void PhysicsComponent::update() {

	b2Vec2 pos = this->body->GetPosition();
	this->parent->setPosition(pos.x,pos.y);
}
