#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"

Player::Player( float x, float y, int spriteWidth, int spriteHeight, int scale ) : GameObject( x, y, spriteWidth, spriteHeight, scale ) {

	if( !this->texture.loadFromFile( "Assets/playerTexture.png" ) ) {
		std::cout << "ERROR: Player.cpp, Player::Player(...): loading texture " << std::endl;
	}	//Wczytanie pliku z wszystkimi pojendynczymi obrazkami do zmiennej texture

	this->shape = new sf::RectangleShape( sf::Vector2f(this->getSize()) );	//Tworzenie prostokata gracza
	this->shape->setTextureRect( sf::IntRect( 0, 0, this->spriteWidth, this->spriteHeight) );	//Nalozenie odpowiedniego sprita z textury
	this->shape->setTexture( &this->texture );	//Przypisanie textury do prostokata

	this->isInverted = false;
	this->isGrounded = false;

	this->isIdling = true;
	this->isRunning = false;
	this->isJumping = false;
	this->isAttacking = false;

}

void Player::update() {	//Funckcja update wywolywana w kazdej ramce

	if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) { 
		this->move(-8, 0);
		this->isRunning = true;
		this->isIdling = false;
		this->isInverted = true;
	}
	else if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) { 
		this->move(8, 0);
		this->isRunning = true;
		this->isIdling = false;
		this->isInverted = false;
	}	//Zmiana pozycji gracza w osi X w zaleznosci od inputu klawiatury
	else {
		this->isIdling = true;
		this->isRunning = false;
	}


}
