#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.hpp>

typedef struct {
	sf::IntRect pos;
	double duration;
} TFrame;

enum PLAY_MODE { LOOP, ONCE };

class Animation {
	private:
		double progress;
		double length;

		sf::Shape * shape;
		std::vector<TFrame> frames;

	public:
		PLAY_MODE mode;

		bool isPlaying;

		Animation(sf::Shape * shape, PLAY_MODE mode);
		void addFrame( TFrame frame );
		void addFrames( TFrame * frames, int length );
		void update( sf::Time elapsedTime, bool isInverted );
		void play();
		void stop();
};

#endif
