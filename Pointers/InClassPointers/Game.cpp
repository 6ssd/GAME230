#include "Game.h"

using namespace gm;

//Global variables

//constructor
Game::Game() {
}

//functions
void Game::handleInput(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))
    {
        //Exit program
        if (event.type == Event::Closed)
            window.close();
    }
}

void Game::update(RenderWindow& window){
    Event event;
    while (window.pollEvent(event))
    {

    }
}

void Game::render(RenderWindow& window) {
    window.clear();

    window.display();
        
}

Game::~Game() {

}