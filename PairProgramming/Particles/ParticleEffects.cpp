//Nanxiang Wang & Akshat Sachan

#include "Game.h"
#include "Random.h"

using namespace gm;

//constructor
ParticleEffect::ParticleEffect(){
	for (int i = 0; i < 10; i++)
	{
		arr[i] = NULL;
	}
}

//functions
void ParticleEffect::update(RenderWindow& window) {
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			arr[i]->update(window);
		}
	}
}

void ParticleEffect::render(RenderWindow& window) {
	window.clear();

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			window.draw(arr[i]->getShape());
			cout << arr[i]->getShape().getPosition().x << " ," << arr[i]->getShape().getPosition().y << endl;
			cout << "drew " << i << endl;
		}
	}

	window.display();
}

void ParticleEffect::emit() {
	for (int i = 0; i < 10; i++)
	{
		Particle* ptr = new Particle();
		arr[i] = addParticle(i, ptr);
	}
}

Particle* ParticleEffect::addParticle(int index, Particle* particle) {
	Vector2f vel = Vector2f(Random::Range(-0.5f, 0.5f), Random::Range(-0.5f, 0.5f));
	cout << "velocity: " << vel.x << " ," << vel.y << endl;
	particle->setVelocity(vel);
	/*for (int i = 0; i <= index; i++)
	{
		cout << "assigned velocity: " << arr[i]->getVelocity().x << " ," << arr[i]->getVelocity().y << endl;
	}*/
	return particle;
}