#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"

Player::Player( float x, float y ) {

	if( !this->texture.loadFromFile( "Assets/playerTexture.png" ) ) {
		std::cout << "ERROR: Player.cpp, Player::Player(...): loading texture " << std::endl;
	}	//Wczytanie pliku z wszystkimi pojendynczymi obrazkami do zmiennej texture

	this->scale = 4;

	this->spriteWidth = 50;
	this->spriteHeight = 37;

	this->width = this->spriteWidth * this->scale;
	this->height = this->spriteHeight * this->scale;
	this->shape = sf::RectangleShape( sf::Vector2f(this->width, this->height) );	//Tworzenie prostokata gracza
	this->shape.setTextureRect( sf::IntRect(0,0,this->spriteWidth,this->spriteHeight) );	//Nalozenie odpowiedniego sprita z textury
	this->shape.setTexture( &this->texture );	//Przypisanie textury do prostokata

	this->x = x;
	this->y = y;	//Ustawienie prostokata gracza na pozycji (x,y)

	this->isInverted = false;
	this->isGrounded = false;

	this->isIdling = true;
	this->isRunning = false;
	this->isJumping = false;
	this->isAttacking = false;

	this->shape.setPosition( this->x, this->y ); //Przypisanie (x,y) do prostokatu
}

void Player::setPosition( float x, float y ) {
	this->x = x;
	this->y = y;
}

void Player::jump() {
	
	if( this->isGrounded ) {
		this->isJumping = true;
		this->velocityY = -20;
	}
}

void Player::update() {	//Funckcja update wywolywana w kazdej ramce
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) { 
		this->x -= 8; 
		this->isRunning = true;
		this->isIdling = false;
		this->isInverted = true;
	}
	else if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) { 
		this->x += 8; 
		this->isRunning = true;
		this->isIdling = false;
		this->isInverted = false;
	}	//Zmiana pozycji gracza w osi X w zaleznosci od inputu klawiatury
	else {
		this->isIdling = true;
		this->isRunning = false;
	}


	if( this->y < 500 ) {
		velocityY += gravity;
		this->isGrounded = false;
	} else {
		this->y = 500;
		this->isGrounded = true;
	}

	this->velocityX += this->accelerationX;
	this->velocityY += this->accelerationY;

	this->x += this->velocityX;
	this->y += this->velocityY;

	this->shape.setPosition( this->x, this->y );	//Aktualizacja pozycji prostokata gracza

}
