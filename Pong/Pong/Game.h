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
#include "Paddle.h"
#include "Ball.h"

namespace gm {
	enum gameState {
		gameStop = 1,
		gamePlay = 2
	};

	enum gameMode {
		onePlayer = 1,
		twoPlayer = 2
	};

	class Game {
	private:
		//font and text
		sf::Font f;
		sf::Text player1Text;
		sf::Text player2Text;
		sf::Text winText;

		//sounds
		sf::SoundBuffer paddleHitSfx;
		sf::SoundBuffer wallHitSfx;
		sf::SoundBuffer scoreSfx;
		sf::SoundBuffer winSfx;
		sf::Sound s;

		//default position values
		const sf::Vector2f ballDefaultPos = sf::Vector2f(445, 215);
		const sf::Vector2f paddle1DefaultPos = sf::Vector2f(20, 185);
		const sf::Vector2f paddle2DefaultPos = sf::Vector2f(875, 185);
		const sf::Vector2f winTextDefaultPos = sf::Vector2f(455, 225);

		//clock
		sf::Clock c;
		float deltaTime;

		//paddles
		Paddle paddle1;
		Paddle paddle2;
		
		//ball
		Ball ball;
		
		//game state
		gameState gameState;
		gameMode gameMode;

		//score
		int player1Score;
		int player2Score;
	public:
		//Prototypes
		Game();
		void play(sf::RenderWindow& window);
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		void reset();
		~Game();
	};
}

#endif