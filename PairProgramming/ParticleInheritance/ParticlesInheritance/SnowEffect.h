#ifndef SNOWEFFECT_H
#define SNOWEFFECT_H

#include "ParticleEffects.h"

namespace gm {
	class SnowEffect : public ParticleEffect {
	public:
		//Prototype
		SnowEffect();
		virtual void update(sf::RenderWindow& window) override;
		virtual void render(sf::RenderWindow& window) override;
		virtual void emit(sf::Vector2f& pos) override;
		virtual CircleParticle* addParticle(int index, CircleParticle* particle) override;
		virtual ~SnowEffect();
	};
}

#endif
