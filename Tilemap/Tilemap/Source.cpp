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
using namespace std;

//Global variables
Music bgm;
SoundBuffer sfxBuffer;
Sound sfx;
Image tileset;
Texture tileTexture[21][7];
Sprite tileSprite[21][7];

//Prototypes
void handleInput(RenderWindow& window, Event& e);
void update(RenderWindow& window);
void render(RenderWindow& window);

//Main
int main()
{
    //create window
    RenderWindow window( VideoMode(1600, 600), "SFML works!");
    
    //load tileset
    if (!tileset.loadFromFile("Assets/Tileset/Platformer-70x70.png"))
    {
        //error
        return -1;
    }

    for (int i = 0; i <= 20; i++)
    {
        string pathName = "Assets/Tileset/Tile" + to_string(i) + ".png";
        for (int j = 0; j <= 6; j++)
        {
            if (!tileTexture[i][j].loadFromImage(tileset,IntRect(70*i, 70*j, 70, 70))) {
                //error
                return -1;
            }
            tileSprite[i][j].setTexture(tileTexture[i][j]);
            tileSprite[i][j].setPosition(70 * float(i), 70 * float(j));
        }
    }

    //game loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            //create screenshot
            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::F)) {
                Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("Screenshot.png"))
                {
                    cout << "Screenshot saved" << endl;
                }
            }

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

    }

    if (event.type == Event::Closed)
        window.close();
}

void update(RenderWindow& window) {

}

void render(RenderWindow& window) {
    window.clear();

    for (int i = 0; i < sizeof(tileSprite)/sizeof(tileSprite[0]); i++)
    {
        for (int j = 0; j < sizeof(tileSprite[0])/sizeof(tileSprite[0][0]); j++)
        {
            window.draw(tileSprite[i][j]);
        }
    }

    window.display();
}