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
	
	Animation animationIdle = Animation(&player.shape);	//Dodanie animacji do gracza
	Animation animationRunning = Animation(&player.shape);

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
	
	animationIdle.addFrames(framesIdle, 4);
	animationRunning.addFrames(framesRunning, 6);	
	
	//Uzupelnienie animacji klatkami i ich czasami

	sf::Clock clock;	//Zegar do obslugi animacji

	while (window.isOpen())	//Petla glowna programu
	{
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if( event.type == sf::Event::KeyPressed) {
				if( event.key.code == sf::Keyboard::Space ) player.jump(); 
			}
		}

		window.clear(); //Czyszczenie ramki

		sf::Time elapsed = clock.restart();

		if( player.isIdling ) {
			animationIdle.update(elapsed.asSeconds(), player.isInverted); //Aktualizacja stanow obiektow w ramce
		}
		if( player.isRunning ) {
			animationRunning.update(elapsed.asSeconds(), player.isInverted);
		}
		player.update();

		window.draw( player.shape ); //Rysowanie gracza
		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
