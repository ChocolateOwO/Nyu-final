#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "SnakeGame.h"
using namespace std;

int main()
{   
    SnakeGame game;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snakegame");
    Menu menu(window.getSize().x, window.getSize().y); //Resize realtime window

    sf::Texture texture;
    if (!texture.loadFromFile("55555.JPG")) {
        //Prevent error!
    }
    sf::Sprite background;
    background.setTexture(texture);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case::sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.Pressed())
                    {
                    case 0:
                        cout << "Play has pressed" << '\n';
                        window.close();
                        game.run();
                        
                    case 1:
                        cout << "Exit has pressed" << '\n';
                        window.close();
                        break;
                    }
                    break;
                }

                break;
            case::sf::Event::Closed:
                window.close();
                break;
            }


        }
        window.clear();
        window.draw(background);
        menu.draw(window);
        window.display();

    }

    return 0;
}

