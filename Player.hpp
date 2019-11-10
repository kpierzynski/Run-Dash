#ifndef PLAYER_H_
#define PLAYER_H_	//Instrukcje preprocesora, dbaja, aby plik naglowkowy nie byl includowany wiele razy

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"
#include "Physics.hpp"

class Player : public GameObject, public Physics {
	private:
		sf::Texture texture;

	public:
		bool isGrounded;
		bool isInverted;

		bool isIdling;
		bool isRunning;
		bool isJumping;
		bool isAttacking;

		Player( float x, float y, int spriteWidth, int spriteHeight, int scale, float density, float friction, b2World * world );
		void setPosition( float x, float y );

		void update() override;
};

#endif
