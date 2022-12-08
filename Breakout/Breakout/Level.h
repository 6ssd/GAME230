#ifndef LEVEL_H
#define LEVEL_H

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
#include "Brick.h"

namespace gm {
	class Level {
	private:
		BrickType normal_brick = {
			1, // hp
			sf::Color::White // color
		};

		BrickType tough_brick = {
			2, // hp
			sf::Color::Green // color
		};

		Brick* arr[30] = {};

		int level1[3][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1}
		};

		int level2[3][10] = {
			{0,1,0,1,0,1,0,1,0,1},
			{2,0,2,0,2,0,2,0,2,0},
			{0,1,0,1,0,1,0,1,0,1}
		};

		int level3[3][10] = {
			{2,2,2,2,2,2,2,2,2,2},
			{2,2,1,2,2,2,2,1,2,2},
			{1,1,1,1,1,1,1,1,1,1}
		};

		int currentLevel;
		int bricksBroken;
		int maxBricks;
	public:
		Level();
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		Brick* getBrick(int index);
		const int getCurrentLevel();
		const int getBricksBroken();
		const bool checkFinished();
		void setBricksBroken(int num);
		void setLevel(int l);
		void reset();
		~Level();
	};
}

#endif // 
