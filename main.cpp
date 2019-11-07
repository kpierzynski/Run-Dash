#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"
#include "Animation.hpp"
#include "Level.hpp"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define GAME_TITLE "Run&Dash"

int main()
{
	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(60);	//Limit klatek do 60

	Player player = Player(10, 20);	//Stworzenie obiektu gracza na pozycji (10,20)
	Animation animationIdle = Animation(&player.shape);	//Dodanie animacji do gracza

	TFrame frames[4] = {
		{sf::IntRect(0*50,0,50,37), 0.2f},
		{sf::IntRect(1*50,0,50,37), 0.2f},
		{sf::IntRect(2*50,0,50,37), 0.15f},
		{sf::IntRect(3*50,0,50,37), 0.2f}
	 };

	animationIdle.addFrame( frames[0] );
	animationIdle.addFrame( frames[1] );
	animationIdle.addFrame( frames[2] );
	animationIdle.addFrame( frames[3] );
	//Uzupelnienie animacji klatkami i ich czasami

	sf::Clock clock;	//Zegar do obslugi animacji
	sf::Texture bgTexture; //Tekstura tla

	if(!bgTexture.loadFromFile("Assets/background.jpg"))
		return -1;

	Level level = Level(&bgTexture);

	while (window.isOpen())	//Petla glowna programu
	{
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(); //Czyszczenie ramki

		if( player.state == State::idle )
			animationIdle.update(clock.restart().asSeconds()); //Aktualizacja stanow obiektow w ramce
		player.update();

		window.draw(level.background); //Rysowanie tla
		window.draw( player.shape ); //Rysowanie gracza
		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
