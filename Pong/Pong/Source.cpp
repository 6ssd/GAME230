//My Classes
#include "Game.h"

//Namespaces
using namespace sf;
using namespace std;
using namespace gm;


//Functions


//Main
int main()
{
    //create window
    RenderWindow window( VideoMode(910, 450), "SFML works!");

    Game g;

    //game loop
    while (window.isOpen())
    {

        g.play(window);
    }

    return 0;
}