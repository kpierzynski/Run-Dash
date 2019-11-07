#ifndef PLAYER_H_
#define PLAYER_H_	//Instrukcje preprocesora, dbaja, aby plik naglowkowy nie byl includowany wiele razy

#include <SFML/Graphics.hpp>

class Player {
	private:
		sf::Texture texture;

		float x;
		float y;

		int width;
		int height;

		float velocityX = 0;
		float velocityY = 0;

		float accelerationX = 0;
		float accelerationY = 0;

		float gravity = 2;

	public:
		sf::RectangleShape shape;

		int scale;

		int spriteWidth;
		int spriteHeight;

		bool isGrounded;
		bool isInverted;

		bool isIdling;
		bool isRunning;
		bool isJumping;
		bool isAttacking;

		Player( float x, float y );
		void update();
		void setPosition( float x, float y );
		void jump();
};

#endif
