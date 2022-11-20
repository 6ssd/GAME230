#ifndef PADDLE_H
#define PADDLE_H

#include "GameObject.h"

namespace gm {
	class Paddle : public GameObject {
	public:
		//constructor
		Paddle(const sf::Vector2f& position, const sf::Vector2f& size);
		
		//update and render
		virtual void update(sf::RenderWindow& window) override;
		virtual void render(sf::RenderWindow& window) override;

		//move Paddle
		virtual void move() override;

		//deconstructor
		~Paddle();
	};
}

#endif // PADDLE_H
