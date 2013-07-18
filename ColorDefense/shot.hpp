#pragma once
#include "stdafx.h"
#include "enemy.hpp"

namespace game {
class shot {
public:
	shot(int color);
	~shot(void);
	int getColor(void);
	void setColor(int color);
	enemy* getTarget(void);
	void setTarget(enemy* target);
	sf::Shape* getShape(void);
	void setPosition(sf::Vector2i pos);
	void setPosition(int x, int y);
	sf::Vector2i getPosition(void);

private:
	int color;
	enemy* target;
	sf::Shape* shape;
	sf::Vector2i position;
};
}
