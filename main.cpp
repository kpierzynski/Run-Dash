#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

#include "Objects/Component.hpp"
#include "Objects/GameObject.hpp"
#include "Objects/Physics.hpp"

#include "Components/PhysicsComponent.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GAME_TITLE "Run&Dash"

int main() {

	Physics physics = Physics();

	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(60);	//Limit klatek do 60
	
	sf::RectangleShape rec = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
	GameObject testGO = GameObject(&rec, sf::Vector2f(2.0f, 2.0f));
	testGO.shape->setFillColor(sf::Color::Cyan);
	PhysicsComponent * phComp = new PhysicsComponent(&testGO, PhysicsComponent::dynamicBody, 1.0f, 0.1f, &physics);
	testGO.addComponent( phComp );

	
	sf::RectangleShape rec1 = sf::RectangleShape(sf::Vector2f(500.0f, 5.0f));
	GameObject testGO1 = GameObject(&rec1, sf::Vector2f(400.0f, 400.0f));
	testGO1.shape->setFillColor(sf::Color::Red);	
	PhysicsComponent * phComp1 = new PhysicsComponent(&testGO1, PhysicsComponent::staticBody, 1.0f, 0.1f, &physics );
	testGO1.addComponent( phComp1 );
	//Uzupelnienie animacji klatkami i ich czasami

	sf::Clock clock;	//Zegar do obslugi animacji

	while (window.isOpen())	//Petla glowna programu
	{
		sf::Time elapsed = clock.restart();
		physics.update(elapsed);
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(); //Czyszczenie ramki

		testGO.update();
		testGO1.update();
		window.draw(testGO);
		window.draw(testGO1);

		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
