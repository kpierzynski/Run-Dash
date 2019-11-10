#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable {
	private:
		float x,y;
	protected:
	
		int spriteWidth, spriteHeight;
		int scale;
		int width, height;
		
		sf::Shape * shape;
	public:

		GameObject( float x, float y, int spriteWidth, int spriteHeight, int scale );
		virtual void update() = 0;

		sf::Shape * getShape();

		void setPosition( float x, float y );
		void setPosition( sf::Vector2f position );
		sf::Vector2f getPosition();

		sf::Vector2i getSize();

		int getScale();

		sf::Vector2i getSpriteSize();

		void move( float dx, float dy );
		void move( sf::Vector2f dPosition );

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states ) const;
};

#endif
