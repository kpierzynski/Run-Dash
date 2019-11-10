#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"

Player::Player( float x, float y, int spriteWidth, int spriteHeight, int scale, float density, float friction, b2World * world ) : GameObject( x, y, spriteWidth, spriteHeight, scale ), Physics(x,y,spriteWidth*scale*1.0f, spriteHeight*scale*1.0f, density, friction, b2_dynamicBody, world) {

	if( !this->texture.loadFromFile( "Assets/playerTexture.png" ) ) {
		std::cout << "ERROR: Player.cpp, Player::Player(...): loading texture " << std::endl;
	}	//Wczytanie pliku z wszystkimi pojendynczymi obrazkami do zmiennej texture

	this->shape = new sf::RectangleShape( sf::Vector2f( this->width, this->height) );	//Tworzenie prostokata gracza
	this->shape->setTextureRect( sf::IntRect( 0, 0, this->spriteWidth, this->spriteHeight) );	//Nalozenie odpowiedniego sprita z textury
	this->shape->setTexture( &this->texture );	//Przypisanie textury do prostokata

	this->isInverted = false;
	this->isGrounded = false;

	this->isIdling = true;
	this->isRunning = false;
	this->isJumping = false;
	this->isAttacking = false;

	this->shape->setPosition( this->x, this->y ); //Przypisanie (x,y) do prostokatu
}

void Player::setPosition( float x, float y ) {
	this->x = x;
	this->y = y;
	this->shape->setPosition( this->x, this->y ); //Przypisanie (x,y) do prostokatu
}

void Player::update() {	//Funckcja update wywolywana w kazdej ramce

	b2Vec2 pos = this->object->GetPosition();

	if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) { 
		this->object->SetTransform(pos+b2Vec2(-10,0), 0);
		this->isRunning = true;
		this->isIdling = false;
		this->isInverted = true;
	}
	else if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) { 
		this->object->SetTransform(pos+b2Vec2(10,0), 0);
		this->isRunning = true;
		this->isIdling = false;
		this->isInverted = false;
	}	//Zmiana pozycji gracza w osi X w zaleznosci od inputu klawiatury
	else {
		this->isIdling = true;
		this->isRunning = false;
	}

	this->shape->setPosition( pos.x, pos.y );	//Aktualizacja pozycji prostokata gracza

}
