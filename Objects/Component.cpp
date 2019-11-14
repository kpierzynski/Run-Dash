#include "./Component.hpp"

Component::Component(GameObject<Component>* parent) {
	this->parent = parent;
}

void TestCmp::update() {};
TestCmp::TestCmp(GameObject<Component>* parent): Component(parent) {}

