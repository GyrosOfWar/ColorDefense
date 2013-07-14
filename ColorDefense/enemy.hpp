#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include <string>
#include "Logger.hpp"
#include <sstream>
#include <iomanip>  
#include <iostream>

namespace game {
class enemy
{
public:
	enemy(int color);
	~enemy(void);

	void updateTexture(void); //sets texture to the colorvalue
	void setColor(int color); //sets the color
	int getColor(void) const; //returns color
	sf::Vector2i getPosition(void) const;
	sf::Vector2i getLastPosition(void) const;
	void setPosition(sf::Vector2i vec, bool setLastPosition);
	void setPosition(int x, int y, bool setLastPosition);
	sf::CircleShape getShape(void);

private:
	int color;
	sf::Vector2i position;
	sf::Color color_real;
	sf::CircleShape shape;
	sf::Vector2i lastPosition;
};

}
