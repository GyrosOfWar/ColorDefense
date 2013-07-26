#pragma once
#include "stdafx.h"
#include "enemy.hpp"

namespace game {
class shot {
public:
	shot(int color, enemy* en, sf::Vector2f start_pos);
	~shot(void);
	int getColor(void) const;
	void setColor(int color);
	enemy* getTarget(void) const;
	void setTarget(enemy* target);
	sf::RectangleShape getShape(void) const;
	void setPosition(sf::Vector2i pos);
	void setPosition(int x, int y);
	sf::Vector2i getPosition(void) const;
	bool move(void);
	bool operator==(const shot& that);

private:
	int color;
	enemy* target;
	sf::RectangleShape shape;
	sf::Vector2i position;
	sf::Vector2f start_pos;
};
}
