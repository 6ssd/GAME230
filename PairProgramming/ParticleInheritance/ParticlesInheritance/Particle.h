//Nanxiang Wang & Akshat Sachan

#ifndef PARTICLE_H
#define PARTICLE_H


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
		Particle(sf::Vector2f& pos);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		const sf::CircleShape getShape() const;
		const sf::Vector2f& getVelocity() const;
		const int getLifespan() const;
		const bool isAlive() const;
		void setVelocity(sf::Vector2f& vel);
		~Particle();
	};
}

#endif