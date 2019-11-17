#include "./Component.hpp"

Component::Component(GameObject* parent) {
	this->parent = parent;
}

void TestCmp::update() {};
TestCmp::TestCmp(GameObject* parent): Component(parent) {}
