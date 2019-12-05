#ifndef COMPONENT_H_
#define COMPONENT_H_

class GameObject;

class Component {

	protected:
		GameObject* parent;
	
	public:
		virtual void update() = 0;
		Component(GameObject* parent);
};


#endif
