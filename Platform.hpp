#ifndef PLATFORM_H_
#define PLATFORM_H_

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

class Platform : public GameObject {
	private:

	public:
		Platform( float x, float y, int spriteWidth, int spriteHeight, int scale );
		void update() override;
};

#endif
