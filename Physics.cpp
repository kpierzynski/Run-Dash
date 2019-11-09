#include <SFML/Graphics.hpp>

#include <iostream>

#include "Physics.hpp"
#include "GameObject.hpp"

#define GRAVITATIONAL_ACCELERATION 9.81

#define DEBUG_INFO 0

Physics::Physics( GameObject * object, float mass ) {

	this->mass = mass;

	this->force = sf::Vector2f(0,0);
	this->acceleration = sf::Vector2f(0,0);
	this->velocity = sf::Vector2f(0,0);

	this->object = object;
}

void Physics::update(sf::Time elapsed) {
		
	sf::Vector2f ds = this->velocity*elapsed.asSeconds() + this->acceleration * (elapsed.asSeconds()*elapsed.asSeconds()) * (1.0f/2);

	this->velocity += this->acceleration*elapsed.asSeconds();

	this->object->setPosition(ds+this->object->getPosition() );	

#if DEBUG_INFO == 1
	std::cout << "Object force: (" << this->force.x << "," << this->force.y << ")" << std::endl;
	std::cout << "Object velocity: (" << this->velocity.x << "," << this->velocity.y << ")" << std::endl;
	std::cout << "Object acc: (" << this->acceleration.x << "," << this->acceleration.y << ")" << std::endl;
	std::cout << "Object d_s: (" << ds.x << "," << ds.y << ")" << std::endl << std::endl;
	std::cout << "Object pos: (" << this->object->getPosition().x << "," << this->object->getPosition().y << ")" << std::endl << std::endl;
#endif

}

void Physics::addForce( sf::Vector2f force ) {
	this->force += force;
	this->acceleration = this->force / this->mass;
}

void Physics::addVelocity(sf::Vector2f velocity) {
	this->velocity += velocity;
}

void Physics::setVelocity(sf::Vector2f velocity) {
	this->velocity = velocity;
}

void Physics::applyGravity() {
	this->addForce( sf::Vector2f(0, GRAVITATIONAL_ACCELERATION * this->mass));
}
