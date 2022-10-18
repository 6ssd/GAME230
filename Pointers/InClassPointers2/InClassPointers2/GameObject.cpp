#include "GameObject.h"

using namespace sf;
using namespace gm;

GameObject::GameObject()
{
	shape = new CircleShape();
	shape->setFillColor(Color::White);
}

GameObject::GameObject(const Vector2f& position, float size) {
	shape = new CircleShape(size);
	shape->setPosition(position);
}

void GameObject::update(RenderWindow& window) {

}

void GameObject::render(RenderWindow& window) {
	window.draw(*shape);
}

//Getters
const Vector2f getPosition

//Setters
void GameObject::setPosition(const Vector2f& position) {
	shape->setPosition(position);
}

void GameObject::set

GameObject::~GameObject() {
	delete shape;
}