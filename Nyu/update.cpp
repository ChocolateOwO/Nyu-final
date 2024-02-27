#include "SnakeGame.h"

void SnakeGame::update() {
    sf::Vector2i newHead = snake.front() + direction;

    if (newHead.x < 0) newHead.x = window.getSize().x / gridSize - 1;
    if (newHead.x >= window.getSize().x / gridSize) newHead.x = 0;
    if (newHead.y < 0) newHead.y = window.getSize().y / gridSize - 1;
    if (newHead.y >= window.getSize().y / gridSize) newHead.y = 0;

    snake.push_front(newHead);
    if (newHead == food) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribX(0, (window.getSize().x / gridSize) - 1);
        std::uniform_int_distribution<int> distribY(0, (window.getSize().y / gridSize) - 1);
        food = sf::Vector2i(distribX(gen), distribY(gen));
        ntail += 1;
        score += 10;
    }
    else {
        snake.pop_back();
    }
    for (auto it = snake.begin() + 1; it != snake.end(); ++it) {
        if (*it == newHead) {
            window.close();
        }
    }
}
