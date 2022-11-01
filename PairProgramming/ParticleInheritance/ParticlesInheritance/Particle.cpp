//Nanxiang Wang & Akshat Sachan

#include "Particle.h"

using namespace gm;
using namespace sf;
using namespace std;

//constructor
Particle::Particle() {}

//functions
const CircleShape* Particle::getShape() const {
	return body;
}

const Vector2f& Particle::getPosition() const {
	return position;
}

const Vector2f& Particle::getVelocity() const{
	return velocity;
}

const int Particle::getLifespan() const {
	return lifespan;
}

const bool Particle::isAlive() const{
	return alive;
}

void Particle::setVelocity(Vector2f& vel) {
	velocity = vel;
}

void Particle::setRadius(float r) {
	radius = r;
}

void Particle::setPos(Vector2f& pos)
{
	position = pos;
	body->setPosition(pos);
}

void Particle::setColor(int a, int b, int c)
{
	body->setFillColor(Color(a, b, c));
}