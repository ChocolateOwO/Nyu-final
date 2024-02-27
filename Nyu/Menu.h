#pragma once
#include <SFML/Graphics.hpp>
#define MAX_ITEM 2 //Play,Exit

class Menu
{
public:
	Menu(float width,float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int Pressed() {
		return selectMenu;
	}

private:
	int selectMenu = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEM];
};

