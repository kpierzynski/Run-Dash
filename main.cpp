#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"
#include "Animation.hpp"

#define HEIGHT 800
#define WIDTH 800
int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Run&Dash");	//Tworzenie okna glownego GUI o rozmiarach 600x600 i danym tytule
	window.setFramerateLimit(60);	//Limit klatek do 60

	Player player = Player(10, 20);	//Stworzenie obiektu gracza na pozycji (10,20)
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
	
	animationIdle.addFrame( framesIdle[0] );
	animationIdle.addFrame( framesIdle[1] );
	animationIdle.addFrame( framesIdle[2] );
	animationIdle.addFrame( framesIdle[3] );

	animationRunning.addFrame(framesRunning[0]);
	animationRunning.addFrame(framesRunning[1]);
	animationRunning.addFrame(framesRunning[2]);
	animationRunning.addFrame(framesRunning[3]);
	animationRunning.addFrame(framesRunning[4]);
	animationRunning.addFrame(framesRunning[5]);
	//Uzupelnienie animacji klatkami i ich czasami

	sf::Clock clock;	//Zegar do obslugi animacji

	while (window.isOpen())	//Petla glowna programu
	{
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
