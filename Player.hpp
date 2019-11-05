#ifndef PLAYER_H_
#define PLAYER_H_	//Instrukcje preprocesora, dbaja, aby plik naglowkowy nie byl includowany wiele razy

#include <SFML/Graphics.hpp>

#include <stdint.h>

enum State { idle, run, attact, jump };

class Player {
	private:
		sf::Texture texture;

		float x;
		float y;

		uint16_t spriteWidth = 50;
		uint16_t spriteHeight = 37;

		uint16_t width = spriteWidth*4;
		uint16_t height = spriteHeight*4;
	public:
		sf::RectangleShape shape;

		State state;

		Player( float x, float y );
		void update();
};

#endif
