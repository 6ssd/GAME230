#include "Paddle.h"

using namespace sf;
using namespace gm;

//constructor
Paddle::Paddle(const Vector2f& position, const Vector2f& size) : GameObject(position, size){
	body.setPosition(position);
	body.setSize(size);
}

//update and render
void Paddle::update(RenderWindow& window) {

}

void Paddle::render(RenderWindow& window) {
	window.draw(body);
}

//move Paddle
void Paddle::move() {

}

//deconstructor
Paddle::~Paddle() {

}