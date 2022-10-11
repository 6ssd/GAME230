//My Classes
#include "Game.h";

//Namespaces
using namespace sf;
using namespace std;
using namespace gm;

//Main
int main()
{
    //create window
    RenderWindow window( VideoMode(700, 910), "SFML works!");

    Game g;

    //load tileset
    if (g.loadTileset() == -1)
    {
        //error
        return -1;
    }

    //put tiles into array
    if (g.tilesToArray() == -1)
    {
        //error
        return -1;
    }

    //initialize array of tile positions
    g.initializeTilePositions();

    //game loop
    while (window.isOpen())
    {

        g.handleInput(window);

        g.update(window);

        g.render(window);
    }

    return 0;
}