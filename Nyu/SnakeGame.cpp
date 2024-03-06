#include "SnakeGame.h"

SnakeGame::SnakeGame() : window(sf::VideoMode(800, 600), "Snake Game") {
    direction = sf::Vector2i(0,0); 
    snake.push_front(sf::Vector2i((window.getSize().x / gridSize) / 2, (window.getSize().y / gridSize) / 2));

    if (!font.loadFromFile("arial.ttf"))
    {
    }
}

int SnakeGame::tailspeed() {
    if (oldtail < ntail)
       if (slep >50) slep -= 3;
    oldtail = ntail;
    return slep;
}

void SnakeGame::run() {
    srand(time(0));
    while (window.isOpen()) {
        processInput();
        generate1();
        generate2();
        update();
        render();
       if(boost) sf::sleep(sf::milliseconds(20));
       else sf::sleep(sf::milliseconds(tailspeed()));
    }
}


void SnakeGame::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up && direction.y != 1) {
                if(reverse && direction.y != -1)direction = sf::Vector2i(0, 1);
                else direction = sf::Vector2i(0, -1);
            }
            else if (event.key.code == sf::Keyboard::Down && direction.y != -1) {
                if (reverse && direction.y != 1) direction = sf::Vector2i(0, -1);
                else direction = sf::Vector2i(0, 1);
            }
            else if (event.key.code == sf::Keyboard::Left && direction.x != 1) {
                if(reverse && direction.x != -1) direction = sf::Vector2i(1, 0);
                else direction = sf::Vector2i(-1, 0);
            }
            else if (event.key.code == sf::Keyboard::Right && direction.x != -1) {
                if(reverse && direction.x != 1) direction = sf::Vector2i(-1, 0);
                else direction = sf::Vector2i(1, 0);
            }
        }
    }
}

void SnakeGame::generate1() {
    if (fruiteat) {
        int ranx =rand()%(window.getSize().x / gridSize);
        int rany = rand() % (window.getSize().y / gridSize);
        int per = rand() % 100 + 1;
        food = sf::Vector2i(window.getSize().x / gridSize + 1, window.getSize().y / gridSize + 1);
        Boostfood = sf::Vector2i(window.getSize().x / gridSize + 1, window.getSize().y / gridSize + 1);
        Reversefood = sf::Vector2i(window.getSize().x / gridSize + 1, window.getSize().y / gridSize + 1);
        Minusfood = sf::Vector2i(window.getSize().x / gridSize + 1, window.getSize().y / gridSize + 1);
        Poisonfood = sf::Vector2i(window.getSize().x / gridSize + 1, window.getSize().y / gridSize + 1);
        if (per <= 30) {
            food = sf::Vector2i(ranx, rany);
            fruit1 = 'F';
        }
        if (per <= 50 && per > 30) {
            Boostfood = sf::Vector2i(ranx, rany);
            fruit1 = 'B';
        }
        if (per <= 70 && per > 50) {
            Poisonfood = sf::Vector2i(ranx, rany);
            fruit1 = 'P';
        }
        if (per <= 80 && per > 70) {
            Reversefood = sf::Vector2i(ranx, rany);
            fruit1 = 'R';
        }
        if (per <= 100 && per > 80) {
            Minusfood = sf::Vector2i(ranx, rany);
            fruit1 = 'M';
        }
    }
}

void SnakeGame::generate2() {
    if (fruiteat) {
        int ranx = rand() % (window.getSize().x / gridSize);
        int rany = rand() % (window.getSize().y / gridSize);
        int per = rand() % 100 + 1;
        if (per <= 30 && fruit1 != 'F') {
            food = sf::Vector2i(ranx, rany);
            
        }
        else if (per <= 30 && fruit1 == 'F') {
            generate2();
        }
        if (per <= 50 && per > 30 && fruit1 != 'B') {
            Boostfood = sf::Vector2i(ranx, rany);
 
        }
        else if (per <= 50 && per > 30 && fruit1 == 'B') {
            generate2();
        }
        if (per <= 70 && per > 50 && fruit1 != 'P') {
            Poisonfood = sf::Vector2i(ranx, rany);
            
        }
        else if (per <= 70 && per > 50 && fruit1 == 'P') {
            generate2();
        }
        if (per <= 80 && per > 70 && fruit1 != 'R') {
            Reversefood = sf::Vector2i(ranx, rany);
            
        }
        else if (per <= 80 && per > 70 && fruit1 == 'R') {
            generate2();
        }
        if (per <= 100 && per > 80 && fruit1 != 'M') {
            Minusfood = sf::Vector2i(ranx, rany);
            
        }
        else if (per <= 100 && per > 80 && fruit1 == 'M') {
            generate2();
        }

        fruiteat = false;
    }

}

void SnakeGame::update() {

    sf::Vector2i newHead = snake.front() + direction;

    if (newHead.x < 0) newHead.x = window.getSize().x / gridSize - 1;
    if (newHead.x >= window.getSize().x / gridSize) newHead.x = 0;
    if (newHead.y < 0) newHead.y = window.getSize().y / gridSize - 1;
    if (newHead.y >= window.getSize().y / gridSize) newHead.y = 0;

    snake.push_front(newHead);

    if (newHead == food) {
        ntail += 1;
        score += 10;
        fruiteat = true;
    }
    else if (newHead == Boostfood) {
        boost = true;
        boostDuration = 30;
        score += 20;
        fruiteat = true;
        snake.pop_back();
    }
    else if (newHead == Poisonfood) window.close();
    else if (newHead == Reversefood) {
        reverse = true;
        reverseDuration = 30;
        score += 30;
        fruiteat = true;
        ntail += 1;

    }
    else if (newHead == Minusfood) {
        score -= 10;
        fruiteat = true;
        if (ntail > 0) {
            ntail -= 1;
            snake.pop_back();
            snake.pop_back();
        }
        else snake.pop_back();
    }
    else {
        snake.pop_back();
    }

    if (boost) {
        boostDuration--;
        if (boostDuration == 0) {
            boost = false;
        }
    }

    if (reverse) {
        reverseDuration--;
        if (reverseDuration == 0) {
            reverse = false;
        }
    }

    if (reverseDuration == 29)recountdown = 3;

    if (reverseDuration == 19) {
        recountdown = 2;
    }

    if (reverseDuration == 9) {
        recountdown = 1;
    }

    for (auto it = snake.begin() + 1; it != snake.end(); ++it) {
        if (*it == newHead) {
            window.close();
        }
    }
}

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
    foodItem.setFillColor(sf::Color::White);
    window.draw(foodItem);

    sf::RectangleShape boostfoodItem(sf::Vector2f(gridSize, gridSize));
    boostfoodItem.setPosition(Boostfood.x * gridSize, Boostfood.y * gridSize);
    boostfoodItem.setFillColor(sf::Color::Blue);
    window.draw(boostfoodItem);

    sf::RectangleShape PoisonfoodItem(sf::Vector2f(gridSize, gridSize));
    PoisonfoodItem.setPosition(Poisonfood.x * gridSize, Poisonfood.y * gridSize);
    PoisonfoodItem.setFillColor(sf::Color::Magenta);
    window.draw(PoisonfoodItem);

    sf::RectangleShape ReversefoodItem(sf::Vector2f(gridSize, gridSize));
    ReversefoodItem.setPosition(Reversefood.x * gridSize, Reversefood.y * gridSize);
    ReversefoodItem.setFillColor(sf::Color::Yellow);
    window.draw(ReversefoodItem);

    sf::RectangleShape MinusfoodItem(sf::Vector2f(gridSize, gridSize));
    MinusfoodItem.setPosition(Minusfood.x * gridSize, Minusfood.y * gridSize);
    MinusfoodItem.setFillColor(sf::Color::Red);
    window.draw(MinusfoodItem);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 560);
    window.draw(scoreText);

    if (reverse) {

        sf::Text reverseText;
        reverseText.setFont(font);
        reverseText.setString("Reverse Countdown: " + std::to_string(recountdown));
        reverseText.setCharacterSize(24);
        reverseText.setFillColor(sf::Color::White);
        reverseText.setPosition(200, 560);
        window.draw(reverseText);
    }


    window.display();
}