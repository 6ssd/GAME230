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

namespace gm {
	class Game {
	public:
		//Prototypes
		Game();
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~Game();
	};


	class Particle {
	private:
		//Global variables
		sf::CircleShape body;
		float radius = 10;
		sf::Vector2f position;
		sf::Vector2f velocity;
		short lifespan;
		bool alive;
	public:
		//Prototypes
		Particle();
		Particle(sf::Vector2f pos);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		sf::CircleShape getShape() const;
		sf::Vector2f getVelocity() const;
		bool isAlive() const;
		void setVelocity(sf::Vector2f vel);
		~Particle();
	};

	class ParticleEffect {
	private:
		//Global variables
		Particle* arr[10];
		sf::Clock clock;
	public:
		//Prototypes
		ParticleEffect();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		void emit(sf::Vector2f pos);
		Particle* addParticle(int index, Particle* particle);
		~ParticleEffect();
	};
}

#endif