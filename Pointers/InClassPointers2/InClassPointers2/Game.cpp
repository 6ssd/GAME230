#include "Game.h"

using namespace gm;

//Global variables

//constructor
Game::Game() {
}

class GameObject {
    private:
        Shape* shape;
    public:
        GameObject(const Vector2f& position, float size) {
            shape = new CircleShape(size);
            shape->setPosition(position);
        }

        void update(RenderWindow& window) {

        }

        void render(RenderWindow& window) {
            window.draw(*shape);
        }

        ~GameObject() {
            delete shape;
        }
};

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