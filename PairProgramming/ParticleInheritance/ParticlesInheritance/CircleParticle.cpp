//Nanxiang Wang & Akshat Sachan

#include "CircleParticle.h"

using namespace gm;
using namespace sf;
using namespace std;

//constructor
CircleParticle::CircleParticle() {
	body = new CircleShape(radius);
	body->setFillColor(Color(255, 0, 255));
	position = Vector2f(350, 455);
	velocity = Vector2f(0.0f, 0.0f);
	body->setPosition(position);
	body->setRadius(10.0);
	lifespan = 5;
	alive = true;
}

CircleParticle::CircleParticle(Vector2f& pos)
{
	body = new CircleShape(radius);
	body->setFillColor(Color(255, 0, 255));
	position = pos;
	velocity = Vector2f(0.0f, 0.0f);
	body->setPosition(position);
	body->setRadius(10.0);
	lifespan = 5;
	alive = true;
}

//functions
void CircleParticle::update(RenderWindow& window) {
	body->setPosition(position + velocity);
	position = body->getPosition();
}

void CircleParticle::render(RenderWindow& window) {

}


CircleParticle::~CircleParticle() {
	delete body;
}