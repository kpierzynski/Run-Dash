#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>

#include "../Objects/GameObject.hpp"

class Background: public GameObject {
	public:
		Background(sf::Shape* shape, sf::Texture* bgTexture); 

};

#endif
