#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

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
	class GameObject {
	private:
		sf::CircleShape* shape;
	public:
		GameObject(const sf::Vector2f& position, float size);

		void update(sf::RenderWindow& window);

		void render(sf::RenderWindow& window);

		void setPosition(const sf::Vector2f& position);

		~GameObject();
	};
}
#endif
