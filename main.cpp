#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.hpp"
#include "Animation.hpp"
#include "Platform.hpp"
#include "Physics.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GAME_TITLE "Run&Dash"

int main()
{
	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(120);	//Limit klatek do 60

	Player player = Player(0, 0, 50, 37, 4);	//Stworzenie obiektu gracza na pozycji (10,20)
	Physics physicsPlayer = Physics( &player, 60 );
	physicsPlayer.applyGravity();
	
	Platform platform = Platform(50, 500, 50, 5, 4);
	Physics physicsPlatform = Physics( &platform, 1 );

	PhysicsManager pManager = PhysicsManager();
	pManager.addObject(&physicsPlayer);
	pManager.addObject(&physicsPlatform);

	Animation animationIdle = Animation(player.getShape(), PLAY_MODE::LOOP);	//Dodanie animacji do gracza
	Animation animationRunning = Animation(player.getShape(), PLAY_MODE::LOOP);
	Animation animationJumping = Animation(player.getShape(), PLAY_MODE::ONCE);

	sf::Vector2i size = player.getSpriteSize();

	TFrame framesIdle[4] = {
		{sf::IntRect( 0*size.x, 0, size.x, size.y ), 0.15f},
		{sf::IntRect( 1*size.x, 0, size.x, size.y ), 0.15f},
		{sf::IntRect( 2*size.x, 0, size.x, size.y ), 0.15f},
		{sf::IntRect( 3*size.x, 0, size.x, size.y ), 0.2f}
	};

	TFrame framesRunning[6] = {	
		{sf::IntRect( 1*size.x, 1*size.y, size.x, size.y ), 0.15f},
		{sf::IntRect( 2*size.x, 1*size.y, size.x, size.y ), 0.15f},
		{sf::IntRect( 3*size.x, 1*size.y, size.x, size.y ), 0.15f},
		{sf::IntRect( 4*size.x, 1*size.y, size.x, size.y ), 0.15f},
		{sf::IntRect( 5*size.x, 1*size.y, size.x, size.y ), 0.15f},
		{sf::IntRect( 6*size.x, 1*size.y, size.x, size.y ), 0.15f},
	};

	TFrame framesJumping[4] = {
		{sf::IntRect( 0*size.x, 2*size.y, size.x, size.y ), (1.0f/2)*(5.0f/100)},
		{sf::IntRect( 1*size.x, 2*size.y, size.x, size.y ), (1.0f/2)*(18.0f/100)},
		{sf::IntRect( 2*size.x, 2*size.y, size.x, size.y ), (1.0f/2)*(27.0f/100)},
		{sf::IntRect( 3*size.x, 2*size.y, size.x, size.y ), (1.0f/2)*(50.0f/100)},
	};
	
	animationIdle.addFrames(framesIdle, 4);
	animationRunning.addFrames(framesRunning, 6);	
	animationJumping.addFrames(framesJumping, 4);
	//Uzupelnienie animacji klatkami i ich czasami

	animationIdle.play();
	animationRunning.play();

	sf::Clock clock;	//Zegar do obslugi animacji i fizyki
	
	while (window.isOpen())	//Petla glowna programu
	{
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if( event.type == sf::Event::KeyPressed) {
				if( event.key.code == sf::Keyboard::Space ) {
					animationJumping.play();				
					physicsPlayer.setVelocity( sf::Vector2f(0, -6) );
				}
			}
		}

		window.clear(); //Czyszczenie ramki

		sf::Time elapsed = clock.restart();
		
		if( player.isIdling )
			animationIdle.update(elapsed, player.isInverted); //Aktualizacja stanow obiektow w ramce
		if( player.isRunning )
			animationRunning.update(elapsed, player.isInverted);
		if( player.isJumping ) 
			animationJumping.update(elapsed, player.isInverted);

		player.update();
		platform.update();

		physicsPlayer.update(elapsed);
		
		pManager.update();

		window.draw( platform );
		window.draw( player ); //Rysowanie gracza
		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
