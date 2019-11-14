#ifndef COMPONENT_H_
#define COMPONENT_H_

template<typename T>
class GameObject;

class Component {

	private:
		GameObject<Component>* parent;
	
	public:
		virtual void update() = 0;
		Component(GameObject<Component>* parent);
};

class TestCmp: public Component {
	public:
		TestCmp(GameObject<Component>* parent);
		void update() override;
};


#endif
