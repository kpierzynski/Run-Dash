#ifndef PLAYER_H_
#define PLAYER_H_	//Instrukcje preprocesora, dbaja, aby plik naglowkowy nie byl includowany wiele razy

#include <SFML/Graphics.hpp>

class Player {
	private:
		sf::Texture texture;

		float x;
		float y;

		int width = 50*4;
		int height = 37*4;
	public:
		sf::RectangleShape shape;

		int spriteWidth;
		int spriteHeight;

		bool isInverted;

		bool isIdling;
		bool isRunning;
		bool isJumping;
		bool isAttacking;

		Player( float x, float y );
		void update();
};

#endif
