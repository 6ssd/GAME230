//Nanxiang Wang & Akshat Sachan

#include "FireworkEffect.h"
#include "Random.h"

using namespace gm;
using namespace sf;
using namespace std;

//constructor
FireworkEffect::FireworkEffect() {
	arr = new CircleParticle * [10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = NULL;
	}
}

//functions
void FireworkEffect::update(RenderWindow& window) {
	if (arr[0] != NULL)
	{
		Time t = clock.getElapsedTime();
		if (t.asSeconds() > arr[0]->getLifespan())
		{
			for (int i = 0; i < 10; i++)
			{
				delete arr[i];
				arr[i] = NULL;
			}
			clock.restart();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			arr[i]->update(window);
		}
	}
}

void FireworkEffect::render(RenderWindow& window) {
	window.clear();

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			window.draw(*(arr[i])->getShape());
			cout << (*(arr[i])->getShape()).getPosition().x << " ," << (*(arr[i])->getShape()).getPosition().y << endl;
			cout << "drew " << i << endl;
		}
	}

	window.display();
}

void FireworkEffect::emit(Vector2f& pos) {
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			delete arr[i];
			arr[i] = NULL;
		}
		CircleParticle* ptr = new CircleParticle(pos);
		arr[i] = addParticle(i, ptr);
		cout << "assigned velocity: " << arr[i]->getVelocity().x << " ," << arr[i]->getVelocity().y << endl;

		clock.restart();
	}
}

CircleParticle* FireworkEffect::addParticle(int index, CircleParticle* particle) {
	Vector2f vel = Vector2f(Random::Range(-0.5f, 0.5f), Random::Range(-0.5f, 0.5f));
	cout << "velocity: " << vel.x << " ," << vel.y << endl;
	particle->setVelocity(vel);
	return particle;
}

FireworkEffect::~FireworkEffect() {
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			delete arr[i];
			arr[i] = nullptr;
		}
	}

	delete arr;
	*arr = nullptr;
	arr = nullptr;
}