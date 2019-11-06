#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.hpp>

typedef struct {
	sf::IntRect pos;
	double duration;
} TFrame;

class Animation {
	private:
		double progress;
		double length;

		sf::RectangleShape * shape;
		std::vector<TFrame> frames;

	public:
		Animation(sf::RectangleShape * shape);
		void addFrame( TFrame frame );
		void update( double elapsedTime );
};

#endif