#include "Game.h"

using namespace gm;

//Global variables

//tileset arrays
Image tileset;
Texture tileTexture[7][21];
Sprite tileSprite[7][21];

//array of positions of placed tiles
//height by width
int tilePositions[13][10];

//values of current tile indexes and sprite
int tileIndexI;
int tileIndexJ;
Sprite currentTile;

//value for current mouse position
Vector2f mousePosition;

//values for rounding mouse position to nearest 70x70 tile location
int numXMultiply;
int numYMultiply;

//values for number of rows and columns of tile positions
int rows;
int cols;

//constructor
Game::Game() {
}

//functions
void Game::handleInput(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))
    {
        //F key: create screenshot
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::F)) {
            Texture texture;
            texture.create(window.getSize().x, window.getSize().y);
            texture.update(window);
            if (texture.copyToImage().saveToFile("Screenshot.png"))
            {
                cout << "Screenshot saved" << endl;
            }
        }

        //S key: save level to level.txt file
        {
            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::S))
            {
                ofstream myfile("level.txt");
                if (myfile.is_open())
                {
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            myfile << tilePositions[i][j] << " ";
                        }
                        if (i != rows - 1)
                        {
                            myfile << endl;
                        }
                    }
                    myfile.close();
                    cout << "File saved" << endl;
                }
                else {
                    cout << "Unable to open file" << endl;
                }
            }
        }

        //L key: load level from level.txt file
        {
            if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::L))
            {
                ifstream myfile("level.txt");
                if (myfile.is_open())
                {
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
                        {
                            myfile >> tilePositions[i][j];
                        }
                    }
                    myfile.close();
                    cout << "Loaded level" << endl;
                }
                else {
                    cout << "Unable to open file" << endl;
                }
            }
        }

        //set tile position at mouse position
        //position is rounded to every 70x70 tile space
        if (event.type == sf::Event::MouseMoved)
        {
            float xPosition = float(event.mouseMove.x);
            numXMultiply = int(xPosition / 70);
            xPosition = 70.0f * float(numXMultiply);

            float yPosition = float(event.mouseMove.y);
            numYMultiply = int(yPosition / 70);
            yPosition = 70.0f * float(numYMultiply);

            mousePosition = Vector2f(xPosition, yPosition);
            currentTile.setPosition(mousePosition);
        }

        //Left mouse button: Save tile type and position of placed tile
        if ((event.type == Event::MouseButtonPressed) && (event.mouseButton.button == Mouse::Left))
        {
            //numYMultiply and numXMultiply are values of the x and y positions of every 70x70 tile
            //tileIndexI and tileIndexJ are math values to determine which tile should be placed
            tilePositions[numYMultiply][numXMultiply] = (7*tileIndexJ)+tileIndexI;
            cout << "Row: " << numYMultiply << ", Col: " << numXMultiply << endl;
            cout << (7 * tileIndexJ) + tileIndexI << endl;
        }

        //Right mouse button: Erase tile
        if ((event.type == Event::MouseButtonPressed) && (event.mouseButton.button == Mouse::Right))
        {
            //numYMultiply and numXMultiply are values of the x and y positions of every 70x70 tile
            //tileIndexI and tileIndexJ are math values to determine which tile should be placed
            tilePositions[numYMultiply][numXMultiply] = -1;
            cout << "Row: " << numYMultiply << ", Col: " << numXMultiply << endl;
            cout << -1 << endl;
        }

        //Up arrow: Goes to next avaliable tile
        //Loops back to start if at end of available tiles
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Up))
        {
            if (tileIndexI < 6)
            {
                tileIndexI++;
            }
            else
            {
                tileIndexI = 0;
                if (tileIndexJ < 20)
                {
                    tileIndexJ++;
                }
                else
                {
                    tileIndexJ = 0;
                }
            }
            cout << "Sprite array index: " << tileIndexI << ", " << tileIndexJ << endl;
            currentTile = tileSprite[tileIndexI][tileIndexJ];
            currentTile.setPosition(mousePosition);
        }

        //Down arrow: Goes to previous avaliable tile
        //Loops back to end if at start of available tiles
        if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Down))
        {
            if (tileIndexI > 0)
            {
                tileIndexI--;
            }
            else
            {
                tileIndexI = 6;
                if (tileIndexJ > 0)
                {
                    tileIndexJ--;
                }
                else
                {
                    tileIndexJ = 20;
                }
            }
            cout << "Sprite array index: " << tileIndexI << ", " << tileIndexJ << endl;
            currentTile = tileSprite[tileIndexI][tileIndexJ];
            currentTile.setPosition(mousePosition);
        }

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
    rows = sizeof(tilePositions) / sizeof(tilePositions[0]);
    cols = sizeof(tilePositions[0]) / sizeof(tilePositions[0][0]);
    
    window.clear();

    //draw placed tiles
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (tilePositions[i][j] != -1)
            {
                int tileNumber = tilePositions[i][j];
                Sprite tile = tileSprite[tileNumber%7][tileNumber/7];
                tile.setPosition(float(j * 70), float(i * 70));
                window.draw(tile);
            }
        }
    }

    //draw tile user is selecting
    window.draw(currentTile);

    window.display();
        
}

//load tileset
int Game::loadTileset() {
    if (!tileset.loadFromFile("Assets/Tileset/Platformer-70x70.png"))
    {
        //error
        return -1;
    }
    cout << "Tileset loaded" << endl;
    return 0;
}


//put tiles into array
int Game::tilesToArray()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (!tileTexture[i][j].loadFromImage(tileset, IntRect(70 * j, 70 * i, 70, 70))) {
                //error
                return -1;
            }
            tileSprite[i][j].setTexture(tileTexture[i][j]);
        }
    }
    currentTile = tileSprite[0][0];
    tileIndexI, tileIndexJ = 0;
    cout << "Textures set" << endl;
    return 0;
}

void Game::initializeTilePositions()
{
    int rows = sizeof(tilePositions) / sizeof(tilePositions[0]);
    int cols = sizeof(tilePositions[0]) / sizeof(tilePositions[0][0]);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tilePositions[i][j] = -1;
        }
    }
}

Game::~Game() {

}