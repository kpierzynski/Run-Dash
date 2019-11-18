#include <SFML/Graphics.hpp>
#include <iostream>

#include "Objects/Component.hpp"
#include "Objects/GameObject.hpp"
#include "Background/Background.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define GAME_TITLE "Run&Dash"


int main() {

	//Tworzenie okna glownego GUI
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE);
	window.setFramerateLimit(60);	//Limit klatek do 60
	
	// Testowe obiekty=========
	sf::RectangleShape rec = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
	TestGO testGO = TestGO(&rec, sf::Vector2f(2.0f, 2.0f));
	testGO.shape->setFillColor(sf::Color::Magenta);

	TestCmp testCmp = TestCmp(&testGO);
	testGO.addComponent(&testCmp);
	testGO.getComponent<TestCmp>();
	// ==============================
	//
	// Załadowanie tła
	sf::Texture bgTexture;
	if(!bgTexture.loadFromFile("Assets/background.jpg")) {
		return -1;
	}
	Background background = Background(&bgTexture);
	
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
		window.draw(background.image); // Rysowanie tła
		window.draw(testGO); // Rysowanie testowego obiektu
		window.display();	//Ostateczne wyslanie ramki na ekran
	}

	return 0;
}
