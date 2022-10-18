//My Classes
#include "Game.h"
#include "Random.h"

//Namespaces
using namespace sf;
using namespace std;
using namespace gm;


//Functions


//Main
int main()
{
    //create window
    RenderWindow window( VideoMode(700, 910), "SFML works!");

    Game g;

    //game loop
    while (window.isOpen())
    {
        g.handleInput(window);

        g.update(window);

        g.render(window);

    }

    return 0;
}