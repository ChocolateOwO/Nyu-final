#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("arial.ttf"))
	{
		//prevent error!!
	}
	menu[0].setFont(font);
	menu[0].setCharacterSize(50);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setOutlineColor(sf::Color::Black);
	menu[0].setOutlineThickness(-2);
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(400,295));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setOutlineColor(sf::Color::Black);
	menu[1].setOutlineThickness(-2);
	menu[1].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(740,545));
}

void Menu::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_ITEM; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectMenu - 1 >= 0) {
		menu[selectMenu].setFillColor(sf::Color::White);
		selectMenu--;
		menu[selectMenu].setFillColor(sf::Color::Green);

	}
}

void Menu::MoveDown() {
	if (selectMenu + 1 <= 1) {
		menu[selectMenu].setFillColor(sf::Color::White);
		selectMenu++;
		menu[selectMenu].setFillColor(sf::Color::Red);

	}
}
