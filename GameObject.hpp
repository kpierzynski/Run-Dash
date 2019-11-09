#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable {
	
	protected:
		float x,y;
	
	public:

		sf::Shape * shape;
		
		int spriteWidth, spriteHeight;
		int scale;
		int width, height;

		virtual void update() = 0;

		void setPosition( float x, float y );
		void setPosition( sf::Vector2f position );
		sf::Vector2f getPosition();

		sf::Vector2i getSize();

		int getScale();
		void setScale( int scale );

		void move( float dx, float dy );
		void move( sf::Vector2f dPosition );

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states ) const;
};

#endif
