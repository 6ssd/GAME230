//Nanxiang Wang & Akshat Sachan

#include "SnowEffect.h"

using namespace gm;
using namespace sf;
using namespace std;

//constructor
SnowEffect::SnowEffect() {
	arr = new CircleParticle * [15];
	for (int i = 0; i < 15; i++)
	{
		arr[i] = NULL;
	}
}

//functions
void SnowEffect::update(RenderWindow& window) {
	if (arr[0] != NULL)
	{
		Time t = clock.getElapsedTime();
		if (t.asSeconds() > arr[0]->getLifespan())
		{
			for (int i = 0; i < 15; i++)
			{
				delete arr[i];
				arr[i] = NULL;
			}
			clock.restart();
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (arr[i] != NULL)
		{
			arr[i]->update(window);
		}
	}
}

void SnowEffect::render(RenderWindow& window) {
	window.clear();

	for (int i = 0; i < 15; i++)
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

void SnowEffect::emit(Vector2f& pos) {
	for (int i = 0; i < 15; i++)
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

CircleParticle* SnowEffect::addParticle(int index, CircleParticle* particle) {
	particle->setColor(255, 255, 255);
	Vector2f temp = Vector2f(particle->getPosition().x + ((float(index) - 5.5f) * 30.0f), (particle->getPosition().y) + float(15*int((index/5))));
	particle->setPos(temp);
	Vector2f vel = Vector2f(0.0f, 3.0f);
	cout << "velocity: " << vel.x << " ," << vel.y << endl;
	particle->setVelocity(vel);
	return particle;
}

SnowEffect::~SnowEffect() {
	for (int i = 0; i < 15; i++)
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