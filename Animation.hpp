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
		double lenght;

		sf::RectangleShape * shape;
		std::vector<TFrame> frames;

	public:
		Animation(sf::RectangleShape * shape);
		void addFrame( TFrame frame );
		void addFrames( TFrame * frames, int length );
		void update( double elapsedTime, bool isInverted );
};

#endif
