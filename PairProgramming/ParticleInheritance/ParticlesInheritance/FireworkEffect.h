#ifndef FIREWORKEFFECT_H
#define FIREWORKEFFECT_H

#include "ParticleEffects.h"

namespace gm {
	class FireworkEffect : public ParticleEffect {
	public:
		//Prototype
		FireworkEffect();
		virtual void update(sf::RenderWindow& window) override;
		virtual void render(sf::RenderWindow& window) override;
		virtual void emit(sf::Vector2f& pos) override;
		virtual CircleParticle* addParticle(int index, CircleParticle* particle) override;
		~FireworkEffect();
	};
}
#endif 