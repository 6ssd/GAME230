//Nanxiang Wang & Akshat Sachan

#ifndef PARTICLEEFFECTS_H
#define PARTICLEEFFECTS_H


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
#include "Particle.h"

namespace gm {
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
		void emit(sf::Vector2f& pos);
		Particle* addParticle(int index, Particle* particle);
		~ParticleEffect();
	};
}
#endif