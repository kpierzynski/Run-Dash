#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"

Player::Player( float x, float y ) {

	if( !this->texture.loadFromFile( "Assets/playerTexture.png" ) ) {
		std::cout << "ERROR: Player.cpp, Player::Player(...): loading texture " << std::endl;
	}	//Wczytanie pliku z wszystkimi pojendynczymi obrazkami do zmiennej texture

	this->shape = sf::RectangleShape( sf::Vector2f(this->width, this->height) );	//Tworzenie prostokata gracza
	this->shape.setTextureRect( sf::IntRect(0,0,this->spriteWidth,this->spriteHeight) );	//Nalozenie odpowiedniego sprita z textury
	this->shape.setTexture( &this->texture );	//Przypisanie textury do prostokata

	this->x = x;
	this->y = y;	//Ustawienie prostokata gracza na pozycji (x,y)

	this->shape.setPosition( this->x, this->y ); //Przypisanie (x,y) do prostokatu
	this->state = idle;

}

void Player::update() {	//Funckcja update wywolywana w kazdej ramce
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) { this->x -= 2; this->state = run; }
	else if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) { this->x += 2; this->state = run; }	//Zmiana pozycji gracza w osi X w zaleznosci od inputu klawiatury
	else this->state = idle;

	this->shape.setPosition( this->x, this->y );	//Aktualizacja pozycji prostokata gracza

}
