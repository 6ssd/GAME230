#include "GameObject.h"

using namespace sf;
using namespace gm;

GameObject::GameObject(const Vector2f& position, float size) {
	shape = new CircleShape(size);
	shape->setPosition(position);
}

void GameObject::update(RenderWindow& window) {

}

void GameObject::render(RenderWindow& window) {
	window.draw(*shape);
}

GameObject::~GameObject() {
	delete shape;
}