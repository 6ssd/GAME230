#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>



int main()
{
    sf::Vector2f mousePosition;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(40.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //draw shape
            if (event.type == sf::Event::MouseMoved)
            {
                shape.setPosition(window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x - int(shape.getRadius()), event.mouseMove.y - int(shape.getRadius()))));
                window.draw(shape);
                window.display();
            }

            //change transparency
            //Z for more transparency, X for more opacity
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Z)) {
                if (shape.getFillColor().a > 0)
                {
                    shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, shape.getFillColor().a - 15));
                }
                std::cout << "Alpha Value: " << (int)shape.getFillColor().a << std::endl;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::X)) {
                if (shape.getFillColor().a < 255)
                {
                    shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, shape.getFillColor().a + 15));
                }
                std::cout << "Alpha Value: " << (int)shape.getFillColor().a << std::endl;
            }

            //change size
            //Q for smaller, E for larger
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Q)) {
                if (shape.getRadius() > 0)
                {
                    shape.setRadius(shape.getRadius() - 5);
                }
                std::cout << "Radius: " << shape.getRadius() << std::endl;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::E)) {
                shape.setRadius(shape.getRadius() + 5);
                std::cout << "Radius: " << shape.getRadius() << std::endl;
            }

            //change color
            //1 for red, 2 for green, 3 for blue
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1)) {
                shape.setFillColor(sf::Color(255,0,0,shape.getFillColor().a));
                std::cout << "Color: Red" << std::endl;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2)) {
                shape.setFillColor(sf::Color(0,255, 0, shape.getFillColor().a));
                std::cout << "Color: Green" << std::endl;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3)) {
                shape.setFillColor(sf::Color(0, 0, 255, shape.getFillColor().a));
                std::cout << "Color: Blue" << std::endl;
            }

            //create screenshot
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F)) {
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("Screenshot.png"))
                {
                    std::cout << "Screenshot saved" << std::endl;
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(shape);
        window.display();
    }
    return 0;
}