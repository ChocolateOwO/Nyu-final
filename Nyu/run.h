#include "SnakeGame"

void SnakeGame::run() {
    while (window.isOpen()) {
        processInput();
        update();
        render();
        sf::sleep(sf::milliseconds(tailspeed()));
    }
}
