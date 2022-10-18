//Nanxiang Wang & Akshat Sachan

#include "Game.h"
#include "Random.h"

using namespace gm;

//Global variables
CircleShape body;
float radius = 10;
Vector2f position;
Vector2f velocity;
short lifespan;
bool alive;

//constructor
Particle::Particle() {
	body = CircleShape(radius);
	body.setFillColor(Color(255,0,255));
	position = Vector2f(350, 455);
	velocity = Vector2f(0.0f,0.0f);
	body.setPosition(position);
	lifespan = 5;
	alive = true;
}

//functions
void Particle::update(RenderWindow& window) {
	body.setPosition(position + velocity);
	position = body.getPosition();
}

void Particle::render(RenderWindow& window) {

}


CircleShape Particle::getShape() {
	return body;
}

Vector2f Particle::getVelocity() {
	return velocity;
}

bool Particle::isAlive() {
	return alive;
}

void Particle::setVelocity(Vector2f vel) {
	velocity = vel;
}

Particle::~Particle() {

}