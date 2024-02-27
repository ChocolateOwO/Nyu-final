#include <SFML/Graphics.hpp>
#include <deque>
#include <random>

class SnakeGame {
public:
    SnakeGame();
    void run();
    int slep = 140;
    int ntail;
    int oldtail = 0;
    int score = 0;

private:
    int tailspeed();
    void processInput();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Vector2i direction;
    std::deque<sf::Vector2i> snake;
    sf::Vector2i food;
    sf::Text text;
    sf::Font font;

    const int gridSize = 20;
};