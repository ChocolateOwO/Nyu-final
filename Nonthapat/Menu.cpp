#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(float width, float height) {
	if (!font.loadFromFile("arial.ttf"))
	{
		//prevent error!!
	}
	menu[0].setFont(font);
	menu[0].setCharacterSize(72);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM+1)*1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEM+1)*2));
}
Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window)  {

	for (int i = 0; i < MAX_ITEM; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectMenu - 1 >= 0) {
		menu[selectMenu].setFillColor(sf::Color::White);
		selectMenu--;
		menu[selectMenu].setFillColor(sf::Color::Red);

	}
}

void Menu::MoveDown() {
	if (selectMenu + 1 <= 1) {
		menu[selectMenu].setFillColor(sf::Color::White);
		selectMenu++;
		menu[selectMenu].setFillColor(sf::Color::Red);

	}
}