#include <SFML/Graphics.hpp>
#include <deque>
#include <ctime>

class SnakeGame {
public:
    SnakeGame();
    void run();
    int slep = 140;
    int ntail;
    int oldtail = 0;
    int score = 0;
    bool fruiteat = true;
    char fruit1;
    bool boost = false;
    int boostDuration;
    bool reverse = false;
    int recountdown;
    int reverseDuration;

private:
    int tailspeed();
    void processInput();
    void update();
    void render();
    void generate1();
    void generate2();

    sf::RenderWindow window;
    sf::Vector2i direction;
    std::deque<sf::Vector2i> snake;
    sf::Vector2i food;
    sf::Vector2i Boostfood;
    sf::Vector2i Reversefood;
    sf::Vector2i Minusfood;
    sf::Vector2i Poisonfood;
    sf::Text text;
    sf::Font font;

    const int gridSize = 20;
};