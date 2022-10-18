//Nanxiang Wang & Akshat Sachan

#ifndef GAME_H
#define GAME_H

//Includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

namespace gm {
	class Game {
	public:
		//Prototypes
		Game();
		void handleInput(RenderWindow& window);
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		~Game();
	};


	class Particle {
	private:
		//Global variables
		CircleShape body;
		float radius = 10;
		Vector2f position;
		Vector2f velocity;
		short lifespan;
		bool alive;
	public:
		//Prototypes
		Particle();
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		CircleShape getShape() const;
		Vector2f getVelocity() const;
		bool isAlive() const;
		void setVelocity(Vector2f vel);
		~Particle();
	};

	class ParticleEffect {
	private:
		//Global variables
		Particle* arr[10];
	public:
		//Prototypes
		ParticleEffect();
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		void emit();
		Particle* addParticle(int index, Particle* particle);
	};
}

#endif