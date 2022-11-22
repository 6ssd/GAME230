#include "Paddle.h"

using namespace sf;
using namespace gm;

//constructor
Paddle::Paddle(const Vector2f& position, const Vector2f& size) : GameObject(position, size), direction(moveDir::None){
	body.setPosition(position);
	body.setSize(size);
}

//update and render
void Paddle::update(RenderWindow& window, float deltaTime) {
	if ((direction == Up && collider.top <= 0)||(direction == Down && (collider.top + collider.height) > window.getSize().y))
	{
		setMoveDirection(None);
	}
	setVelocity(Vector2f(0, 300 * direction * deltaTime));
	move();
}

void Paddle::render(RenderWindow& window, float deltaTime) {
	window.draw(body);
}

//move Paddle
void Paddle::move() {
	GameObject::move();
	body.setPosition(position);
}

//get and set move direction
moveDir Paddle::getMoveDirection() const {
	return direction;
}

void Paddle::setMoveDirection(moveDir direction) {
	this->direction = direction;
}

//deconstructor
Paddle::~Paddle() {

}