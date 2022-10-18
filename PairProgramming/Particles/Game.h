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
	public:
		//Prototypes
		Particle();
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		CircleShape getPosition();
		bool isAlive();
		void setVelocity(Vector2f vel);
		~Particle();
	};

	class ParticleEffect {
	public:
		//Prototypes
		ParticleEffect();
		void update(RenderWindow& window);
		void render(RenderWindow& window);
		void emit();
		void addParticle(int index);
	};
}

#endif