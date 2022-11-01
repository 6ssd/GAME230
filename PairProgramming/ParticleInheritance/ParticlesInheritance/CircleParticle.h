#ifndef CIRCLEPARTICLE_H
#define CIRCLEPARTICLE_H

#include "Particle.h"

namespace gm {

	class CircleParticle : public Particle {
	public:
		//Prototypes
		CircleParticle();
		CircleParticle(sf::Vector2f& pos);
		virtual void update(sf::RenderWindow& window) override;
		virtual void render(sf::RenderWindow& window) override;
		virtual ~CircleParticle();
	};
}

#endif
