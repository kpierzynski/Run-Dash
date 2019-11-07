#include <SFML/Graphics.hpp>

#include <iostream>
#include <iterator>

#include "Animation.hpp"

Animation::Animation(sf::RectangleShape * shape, PLAY_MODE mode) {
	this->shape = shape;	//Zapamietanie elementu docelowego do animacji
	this->length = 0;	//Dlugosc animacji
	this->progress = 0;	//Obecny stan animacji

	this->mode = mode;

	this->isPlaying = false;
}

void Animation::addFrame( TFrame frame ) {
	this->length += frame.duration;
	this->frames.push_back( frame );	//Zapisanie klatki animacji do bufora
}

void Animation::addFrames( TFrame * frames, int length ) {

	for( int i = 0; i < length; i++ ) {
		this->addFrame(frames[i]);
	}

}

void Animation::play() {
	this->isPlaying = true;
}

void Animation::stop() {
	this->isPlaying = false;
}

void Animation::update( double elapsedTime, bool isInverted ) {
	if( this->isPlaying != true ) return;

	this->progress += elapsedTime;	//Dodanie do obecnego stanu animacji czasu jaki uplynal od ostatniej klatki
	double time = this->progress;	//Zmienna pomocnicza

	for( size_t i = 0; i < this->frames.size(); i++ ) {	//Petla szuka takiego indeksu i, dla ktorego uplyniety czas odpowiada ustalonej klatce
		time -= this->frames[i].duration;

		if( time <= 0 ) { //Jesli time jest <= 0 , to znaczy ze indeks i wskazuje na klatke animacji, ktora powinna byc wyswietlona
			TFrame fr = frames[i];
			if( isInverted ) {
				fr.pos.left += fr.pos.width;
			       	fr.pos.width = -fr.pos.width;
			}
			this->shape->setTextureRect(fr.pos);
			break;
		}


		if( i+1 == this->frames.size() ) {
			this->progress = 0; //Jesli trafilismy na ostatnia klatke, cofamy animacje do poczatku => LOOP animacji
			if( this->mode != PLAY_MODE::LOOP ) this->isPlaying = false; 
		}
	}
}
