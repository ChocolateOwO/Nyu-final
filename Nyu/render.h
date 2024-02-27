#include "SnakeGame.h"

void SnakeGame::render() {
    window.clear();

    for (const sf::Vector2i& segment : snake) {
        sf::RectangleShape snakeSegment(sf::Vector2f(gridSize, gridSize));
        snakeSegment.setPosition(segment.x * gridSize, segment.y * gridSize);
        snakeSegment.setFillColor(sf::Color::Green);
        window.draw(snakeSegment);
    }

    sf::RectangleShape foodItem(sf::Vector2f(gridSize, gridSize));
    foodItem.setPosition(food.x * gridSize, food.y * gridSize);
    foodItem.setFillColor(sf::Color::Red);
    window.draw(foodItem);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    window.draw(scoreText);

    window.display();
}