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
	protected:
		//Global variables
		sf::CircleShape* body;
		float radius;
		sf::Vector2f position;
		sf::Vector2f velocity;
		short lifespan;
		bool alive;
	public:
		//Prototypes
		Particle();
		virtual void update(sf::RenderWindow& window) = 0;
		virtual void render(sf::RenderWindow& window) = 0;

		//Getters
		virtual const sf::Vector2f& getPosition() const;
		virtual const sf::CircleShape* getShape() const;
		virtual const sf::Vector2f& getVelocity() const;
		virtual const int getLifespan() const;
		virtual const bool isAlive() const;

		//Setters
		virtual void setVelocity(sf::Vector2f& vel);
		virtual void setRadius(float r);
		virtual void setPos(sf::Vector2f& pos);
		virtual void setColor(int a, int b, int c);
	};
}

#endif