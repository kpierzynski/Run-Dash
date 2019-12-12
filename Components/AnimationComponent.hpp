#ifndef ANIMATIONCOMPONENT_H_
#define ANIMATIONCOMPONENT_H_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "../Objects/Component.hpp"
#include "../Objects/GameObject.hpp"

class AnimationComponent : public Component {
	public:
		enum PlayMode { LOOP, ONCE };

	private:
		float progress;
		bool isPlaying;
		PlayMode playMode;

		std::vector<std::tuple<sf::IntRect, float>> frames;
	public:

		AnimationComponent( GameObject * parent, AnimationComponent::PlayMode playMode, std::tuple<sf::IntRect, float> * frames, size_t size );

		void addFrame( std::tuple<sf::IntRect, float> frame );
		void addFrames( std::tuple<sf::IntRect, float> * frames, size_t size );

		void play();
		void stop();
		void pause();

		void update( sf::Time elapsed );
};

#endif
