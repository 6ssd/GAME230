//Nanxiang Wang & Akshat Sachan

#include "ParticleEffects.h"
#include "Random.h"

using namespace gm;
using namespace sf;
using namespace std;

//constructor
ParticleEffect::ParticleEffect(){}

ParticleEffect::~ParticleEffect() {
	delete[] arr;
	delete arr;
}