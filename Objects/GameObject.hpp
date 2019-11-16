#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Component;

class GameObject: public sf::Drawable {

	private:
		std::vector<Component*> components;
	
	public:
		sf::Shape* shape;
		GameObject(sf::Shape* shape, sf::Vector2f coords);
		GameObject(sf::Shape* shape, float x, float y);

		void addComponent(Component* component);

		template<class T>
		std::vector<T*> getComponent() {
			std::vector<T*> result;

			for(size_t i = 0; i < this->components.size(); i++) {
				// Dynamic cast sprawdza czy moze zcastowac element na T*,
				// jezeli tak to mamy szukany obiekt
				T* isWanted = dynamic_cast<T*>(this->components[i]);
				if(isWanted)
					result.push_back(isWanted);
			}
			return result;
		};

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class TestGO: public GameObject {
	public:
		TestGO(sf::Shape* shape, sf::Vector2f coords);
};

#endif
