#include "SnakeGame.h"

SnakeGame::SnakeGame() : window(sf::VideoMode(800, 600), "Snake Game") {
    direction = sf::Vector2i(0,0); 
    snake.push_front(sf::Vector2i((window.getSize().x / gridSize) / 2, (window.getSize().y / gridSize) / 2)); 
    food = sf::Vector2i(10, 10); 
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
}

int SnakeGame::tailspeed() {
    if (oldtail < ntail)
       if (slep >50) slep -= 3;
    oldtail = ntail;
    return slep;
}