#include <SFML/Graphics.hpp>

#include <iostream>

#include "Animation.hpp"

Animation::Animation(sf::RectangleShape * shape) {
	this->shape = shape;	//Zapamietanie elementu docelowego do animacji
	this->length = 0;	//Dlugosc animacji
	this->progress = 0;	//Obecny stan animacji
}

void Animation::addFrame( TFrame frame ) {
	this->length += frame.duration;
	this->frames.push_back( frame );	//Zapisanie klatki animacji do bufora
}

void Animation::update( double elapsedTime ) {

	this->progress += elapsedTime;	//Dodanie do obecnego stanu animacji czasu jaki uplynal od ostatniej klatki
	double time = this->progress;	//Zmienna pomocnicza

	for( size_t i = 0; i < this->frames.size(); i++ ) {	//Petla szuka takiego indeksu i, dla ktorego uplyniety czas odpowiada ustalonej klatce
		time -= this->frames[i].duration;

		if( time <= 0 ) { //Jesli time jest <= 0 , to znaczy ze indeks i wskazuje na klatke animacji, ktora powinna byc wyswietlona
			this->shape->setTextureRect(frames[i].pos);
			break;
		}

		if( i+1 == this->frames.size() ) this->progress = 0; //Jesli trafilismy na ostatnia klatke, cofamy animacje do poczatku => LOOP animacji
		//Nie wszystkie animacje sa zapetlone: TODO parametryzacja trybu animacji: LOOP, ONCE


	}
}