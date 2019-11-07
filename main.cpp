#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"
#include "Animation.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GAME_TITLE "Run&Dash"

int main()
{
	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(60);	//Limit klatek do 60

	Player player = Player(0, 0);	//Stworzenie obiektu gracza na pozycji (10,20)
	//player.setPosition( 0, SCREEN_HEIGHT-player.spriteHeight*player.scale );
	
	Animation animationIdle = Animation(&player.shape, PLAY_MODE::LOOP);	//Dodanie animacji do gracza
	Animation animationRunning = Animation(&player.shape, PLAY_MODE::LOOP);
	Animation animationJumping = Animation(&player.shape, PLAY_MODE::ONCE);

	TFrame framesIdle[4] = {
		{sf::IntRect(0*player.spriteWidth,0,player.spriteWidth,player.spriteHeight), 0.15f},
		{sf::IntRect(1*player.spriteWidth,0,player.spriteWidth,player.spriteHeight), 0.15f},
		{sf::IntRect(2*player.spriteWidth,0,player.spriteWidth,player.spriteHeight), 0.15f},
		{sf::IntRect(3*player.spriteWidth,0,player.spriteWidth,player.spriteHeight), 0.2f}
	};

	TFrame framesRunning[6] = {	
		{sf::IntRect(1*player.spriteWidth,1*player.spriteHeight, player.spriteWidth, player.spriteHeight), 0.15f},
		{sf::IntRect(2*player.spriteWidth,1*player.spriteHeight, player.spriteWidth, player.spriteHeight), 0.15f},
		{sf::IntRect(3*player.spriteWidth,1*player.spriteHeight, player.spriteWidth, player.spriteHeight), 0.15f},
		{sf::IntRect(4*player.spriteWidth,1*player.spriteHeight, player.spriteWidth, player.spriteHeight), 0.15f},
		{sf::IntRect(5*player.spriteWidth,1*player.spriteHeight, player.spriteWidth, player.spriteHeight), 0.15f},
		{sf::IntRect(6*player.spriteWidth,1*player.spriteHeight, player.spriteWidth, player.spriteHeight), 0.15f},
	};

	TFrame framesJumping[4] = {
		{sf::IntRect(0*player.spriteWidth,2*player.spriteHeight, player.spriteWidth, player.spriteHeight), (1.0f/3)*(15.0f/100)},
		{sf::IntRect(1*player.spriteWidth,2*player.spriteHeight, player.spriteWidth, player.spriteHeight), (1.0f/3)*(20.0f/100)},
		{sf::IntRect(2*player.spriteWidth,2*player.spriteHeight, player.spriteWidth, player.spriteHeight), (1.0f/3)*(30.0f/100)},
		{sf::IntRect(3*player.spriteWidth,2*player.spriteHeight, player.spriteWidth, player.spriteHeight), (1.0f/3)*(35.0f/100)},
	};
	
	animationIdle.addFrames(framesIdle, 4);
	animationRunning.addFrames(framesRunning, 6);	
	animationJumping.addFrames(framesJumping, 4);
	//Uzupelnienie animacji klatkami i ich czasami

	animationIdle.play();
	animationRunning.play();
	animationJumping.play();

	sf::Clock clock;	//Zegar do obslugi animacji
	
	while (window.isOpen())	//Petla glowna programu
	{
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if( event.type == sf::Event::KeyPressed) {
				if( event.key.code == sf::Keyboard::Space ) {
					player.jump(); 
					animationJumping.play();				
				}
			}
		}

		window.clear(); //Czyszczenie ramki

		float elapsed = clock.restart().asSeconds();
		
		if( player.isIdling ) {
			animationIdle.update(elapsed, player.isInverted); //Aktualizacja stanow obiektow w ramce
		}
		if( player.isRunning ) {
			animationRunning.update(elapsed, player.isInverted);
		}
		if( player.isJumping ) {
			animationJumping.update(elapsed, player.isInverted);
		}
		player.update();

		window.draw( player.shape ); //Rysowanie gracza
		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
