#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

#include "Objects/Component.hpp"
#include "Objects/GameObject.hpp"

#include "Components/PhysicsComponent.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GAME_TITLE "Run&Dash"

#define PIXELS2METERS 0.02f //Przeniesc to stad w pizdu do jednego pliku..
#define METERS2PIXELS 50.0f //@up

int main() {

	b2World world = b2World( b2Vec2(0.0f, 10.0f) );

	b2BodyDef groundDef;
	groundDef.position.Set(0.0f*PIXELS2METERS, 400.0f*PIXELS2METERS);
	b2Body * ground = world.CreateBody(&groundDef);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(1000.0f/2*PIXELS2METERS, 5.0f/2*PIXELS2METERS);
	ground->CreateFixture(&groundShape, 1.0f);

	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(60);	//Limit klatek do 60
	
	sf::RectangleShape rec = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
	TestGO testGO = TestGO(&rec, sf::Vector2f(2.0f, 2.0f));
	testGO.shape->setFillColor(sf::Color::Cyan);

	PhysicsComponent * phComp = new PhysicsComponent(&testGO, b2_dynamicBody, 1.0f, 0.1f, &world );
	testGO.addComponent( phComp );

	
	//Uzupelnienie animacji klatkami i ich czasami

	sf::Clock clock;	//Zegar do obslugi animacji

	while (window.isOpen())	//Petla glowna programu
	{
		sf::Time elapsed = clock.restart();
		world.Step(elapsed.asSeconds(), 8,3 );
		sf::Event event; //Polling eventow
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(); //Czyszczenie ramki

		testGO.update();
		window.draw(testGO);

		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
