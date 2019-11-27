#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Objects/GameObject.hpp"

class Background: public GameObject {
	private:
		sf::Texture bgTexture;

	public:
		Background(std::string filename, sf::Shape* shape);
};

#endif
