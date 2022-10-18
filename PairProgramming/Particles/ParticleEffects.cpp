#include "Game.h"
#include "Random.h"

using namespace gm;

//Global variables
Particle *arr[10];

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
		cout << arr[i]->getPosition().getPosition().x << " ," << arr[i]->getPosition().getPosition().y << endl;
		cout << "drew " << i << endl;
	}

	window.display();
}

void ParticleEffect::emit() {
	for (int i = 0; i < 10; i++)
	{
		Particle* ptr = new Particle();
		addParticle(i, ptr);
	}
}

void ParticleEffect::addParticle(int index, Particle* particle) {
	Vector2f vel = Vector2f(Random::Range(-0.1f, 0.1f), Random::Range(-0.1f, 0.1f));
	cout << "velocity: " << vel.x << " ," << vel.y << endl;
	particle->setVelocity(vel);
	arr[index] = particle;
}