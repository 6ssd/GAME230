//Nanxiang Wang & Akshat Sachan

#include "Game.h"
#include "Random.h"

using namespace gm;
using namespace sf;
using namespace std;

//Global Variable
ParticleEffect e;

//constructor
Game::Game() {
    e = ParticleEffect();
}

//functions
void Game::handleInput(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))
    {
        //create particle effect
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            e.emit();
        }

        //Exit program
        if (event.type == Event::Closed)
            window.close();
    }
}

void Game::update(RenderWindow& window){
    e.update(window);
}

void Game::render(RenderWindow& window) {
    e.render(window);
}

Game::~Game() {

}