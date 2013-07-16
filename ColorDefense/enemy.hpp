#pragma once
#include "stdafx.h"
#include "Logger.hpp"

#include <sstream>
#include <iomanip>  
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

namespace game {
class enemy {
public:
	enemy(int color);
	~enemy(void);

	void updateColor(void); //sets shape color to the colorvalue
	void setColor(int color); //sets the color
	int getColor(void) const; //returns color
	sf::Vector2i getPosition(void) const;
	sf::Vector2i getLastPosition(void) const;
	void setPosition(sf::Vector2i vec, bool setLastPosition);
	void setPosition(int x, int y, bool setLastPosition);
	sf::CircleShape getShape(void);
	int getHealth(void);
	void setHealth(int h);
	void setShapePos(int x, int y);
	void setShapePos(sf::Vector2f pos);
private:
	int color;
	int health;
	sf::Vector2i position;
	sf::Color color_real;
	sf::CircleShape shape;
	sf::Vector2i lastPosition;
};
}
