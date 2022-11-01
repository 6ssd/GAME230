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

//Headers
#include "CircleParticle.h"
#include "FireworkEffect.h"
#include "SnowEffect.h"
#include "Random.h"

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
}

#endif