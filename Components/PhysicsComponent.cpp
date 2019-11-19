#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

#include "PhysicsComponent.hpp"
#include "../Objects/GameObject.hpp"
#include "../Objects/Component.hpp"

#define PIXELS2METERS 0.02f
#define METERS2PIXELS 50.0f

PhysicsComponent::PhysicsComponent( GameObject * parent, b2BodyType bodyType, float density, float friction, b2World * world ) : Component(parent) {
	b2PolygonShape shape;
	
	b2BodyDef bodyDef;
	bodyDef.type = bodyType;
	bodyDef.position.Set( parent->shape->getPosition().x, parent->shape->getPosition().y );

	this->body = world->CreateBody(&bodyDef);



	size_t points = this->parent->shape->getPointCount();
	b2Vec2 * vertices = new b2Vec2[points];
	for( size_t i = 0; i < points; i++ ) {
		sf::Vector2f pos = this->parent->shape->getPoint(i);
		vertices[i] = b2Vec2(pos.x*PIXELS2METERS,pos.y*PIXELS2METERS);
	}
	for( size_t i = 0; i < points; i++ ) std::cout << "( " << vertices[i].x << ", " << vertices[i].y << " )" << std::endl;

	shape.Set(vertices, points);

	b2FixtureDef bodyFixtureDef;
	bodyFixtureDef.shape = &shape;
	bodyFixtureDef.density = density;
	bodyFixtureDef.friction = friction;
	this->body->CreateFixture(&bodyFixtureDef);

}

void PhysicsComponent::update() {

	b2Vec2 pos = this->body->GetPosition();
	this->parent->setPosition(pos.x*METERS2PIXELS,pos.y*METERS2PIXELS);
}
