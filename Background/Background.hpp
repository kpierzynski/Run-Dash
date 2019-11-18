#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>

class Background {
	public:
		Background(sf::Texture* bgTexture);
		sf::Sprite image;
};


#endif
