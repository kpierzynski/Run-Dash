#include <SFML/Graphics.hpp>

#include <iostream>
#include <iterator>

#include "AnimationComponent.hpp"
#include "../Objects/GameObject.hpp"
#include "../Objects/Component.hpp"

AnimationComponent::AnimationComponent( GameObject * parent, 
					AnimationComponent::PlayMode playMode, 
					std::tuple<sf::IntRect, float> * frames, 
					size_t size ) 
					: Component( parent ) {
	this->progress = 0;
	this->isPlaying = false;
	this->playMode = playMode;
	for( size_t i = 0; i < size; i++ ) this->frames.push_back(frames[i]);
}

void AnimationComponent::update( sf::Time elapsed ) {
	if( !this->isPlaying ) return;

	this->progress += elapsed.asSeconds();	

	float time = this->progress;

	for( size_t i = 0; i < this->frames.size(); i++ ) {
		time -= std::get<1>(this->frames[i]);

		if( time <= 0 ) {
			this->parent->shape->setTextureRect( std::get<0>(this->frames[i]));
			break;
		}

		if( i+1 == this->frames.size() ) {
		       	this->progress = 0;
			if( this->playMode != PlayMode::LOOP ) this->isPlaying = false;
		}
	}
}

void AnimationComponent::play() {
	this->isPlaying = true;
}

void AnimationComponent::stop() {
	this->progress = 0;
	this->isPlaying = false;
}

void AnimationComponent::pause() {
	this->isPlaying = false;
}
