#include <SFML/Graphics.hpp>
#include <iostream>

#include "Objects/GameObject.hpp"
#include "Objects/Component.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GAME_TITLE "Run&Dash"


int main() {

	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(60);	//Limit klatek do 60

	sf::RectangleShape* rec = new sf::RectangleShape(sf::Vector2f(0.0f, 0.0f));
	GameObject<Component> go = GameObject<Component>(rec, 0.0f, 0.0f);
	
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
		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
