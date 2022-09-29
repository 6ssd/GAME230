#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

//Namespaces
using namespace sf;

//Global variables
Music bgm;
SoundBuffer sfxBuffer;
Sound sfx;
Texture tileTexture;
Sprite tileSprite;

//Prototypes
void handleInput(RenderWindow& window, Event& e);
void update(RenderWindow& window);
void render(RenderWindow& window);

//Main
int main()
{
    //create window
    RenderWindow window( VideoMode(800, 600), "SFML works!");

    //load audio
    if (!bgm.openFromFile("Assets/Audio/BGM.wav")) {
        //error
        return -1;
    }
    bgm.play();
    bgm.setLoop(true);

    //sound effects
    if (!sfxBuffer.loadFromFile("Assets/Audio/Victory Jingle SFX.wav")) {
        //error
        return -1;
    }
    sfx.setBuffer(sfxBuffer);
    
    //load sprite
    if (!tileTexture.loadFromFile("Assets/Graphics/Tile1.png")) {
        //error
        return -1;
    }
    tileSprite.setTexture(tileTexture);

    //game loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            handleInput(window, event);
        }

        update(window);

        render(window);
    }

    return 0;
}

void handleInput(RenderWindow& window, Event& event) {
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        sfx.play();
    }

    if (event.type == Event::Closed)
        window.close();
}

void update(RenderWindow& window) {

}

void render(RenderWindow& window) {
    window.clear();

    window.draw(tileSprite);

    window.display();
}