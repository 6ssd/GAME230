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

#include "CircleParticle.h"

namespace gm {
	class ParticleEffect {
	protected:
		//Global variables
		CircleParticle** arr;
		sf::Clock clock;
	public:
		//Prototypes
		ParticleEffect();
		virtual void update(sf::RenderWindow& window) = 0;
		virtual void render(sf::RenderWindow& window) = 0;
		virtual void emit(sf::Vector2f& pos) = 0;
		virtual CircleParticle* addParticle(int index, CircleParticle* particle) = 0;
	};
}
#endif