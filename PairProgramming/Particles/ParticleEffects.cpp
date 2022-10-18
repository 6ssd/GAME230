#include "Game.h"
#include "Random.h"

using namespace gm;

//Global variables
Particle* arr[10];

//constructor
ParticleEffect::ParticleEffect(){

}

//functions
void ParticleEffect::update(RenderWindow& window) {
	for (int i = 0; i < 10; i++)
	{
		arr[i]->update(window);
	}
}

void ParticleEffect::render(RenderWindow& window) {
	window.clear();

	for (int i = 0; i < 10; i++)
	{
		window.draw(arr[i]->getPosition());
	}

	window.display();
}

void ParticleEffect::emit() {
	for (int i = 0; i < 10; i++)
	{
		addParticle(i);
	}
}

void ParticleEffect::addParticle(int index) {
	Vector2f vel = Vector2f(Random::Range(-10.0f, 10.0f), Random::Range(-10.0f, 10.0f));
	arr[index] = new Particle();
	arr[index]->setVelocity(vel);
}