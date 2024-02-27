#include "SnakeGame.h"

void SnakeGame::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {  
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up && direction.y != 1) {
                direction = sf::Vector2i(0, -1);
            }
            else if (event.key.code == sf::Keyboard::Down && direction.y != -1) {
                direction = sf::Vector2i(0, 1);
            }
            else if (event.key.code == sf::Keyboard::Left && direction.x != 1) {
                direction = sf::Vector2i(-1, 0);
            }
            else if (event.key.code == sf::Keyboard::Right && direction.x != -1) {
                direction = sf::Vector2i(1, 0);
            }
        }
    }
}