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

class TestCmp: public Component {
	public:
		TestCmp(GameObject* parent);
		void update() override;
};


#endif
