//Nanxiang Wang & Akshat Sachan

#include "Game.h"

using namespace gm;
using namespace sf;
using namespace std;

//Global Variable
ParticleEffect* e;

//constructor
Game::Game() {
    e = new FireworkEffect();
}

//functions
void Game::handleInput(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))
    {
        //create particle effect
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            Vector2f mousePos = Vector2f(float(event.mouseButton.x-10), float(event.mouseButton.y-10));
            e->emit(mousePos);
        }

        //Firework Effect: Press 1
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Num1)
        {
            delete e;
            e = nullptr;
            e = new FireworkEffect();
        }

        //Snow Effect: Press 2
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Num2)
        {
            delete e;
            e = nullptr;
            e = new SnowEffect();
        }

        //Exit program
        if (event.type == Event::Closed)
            window.close();
    }
}

void Game::update(RenderWindow& window){
    e->update(window);
}

void Game::render(RenderWindow& window) {
    e->render(window);
}

Game::~Game() {

}