#include "Game.h"

using namespace std;
using namespace sf;
using namespace gm;

//Global variables

//constructor
Game::Game() : paddle1(Vector2f(75,185), Vector2f(15,80)), paddle2(Vector2f(835, 185), Vector2f(15, 80)) {

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

    paddle1.render(window);
    paddle2.render(window);

    window.display();
        
}

Game::~Game() {

}