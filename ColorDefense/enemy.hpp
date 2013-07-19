#pragma once
#include "stdafx.h"
#include "Logger.hpp"
#include "animation.hpp"

#include <sstream>
#include <iomanip>  
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

namespace game {
class enemy {
public:
	enemy(int color, sf::Vector2f startPos);
	~enemy(void);

	void updateColor(void); //sets shape color to the colorvalue
	void setColor(int color); //sets the color
	int getColor(void) const; //returns color
	sf::Vector2i getPosition(void) const;
	sf::Vector2i getLastPosition(void) const;
	void setPosition(sf::Vector2i vec, bool animate);
	void setPosition(int x, int y, bool animate);
	sf::CircleShape getShape(void);
	int getHealth(void);
	void setHealth(int h);
	vector<sf::Vector2i>::iterator& getPathIterator();
	int getSpot(void);
	void incrSpot(void);
private:
	int color;
	int health;
	int maxHealth;
	sf::Vector2i position;
	sf::Color color_real;
	sf::CircleShape shape;
	sf::Vector2i lastPosition;
	vector<sf::Vector2i>::iterator pathIterator;
	int spot;
	animation anim;
};
}
