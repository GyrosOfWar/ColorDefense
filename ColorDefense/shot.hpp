#pragma once
#include "stdafx.h"
#include "enemy.hpp"

namespace game {
class shot {
public:
	shot(int color, sf::Vector2f start_pos, sf::Vector2f target_pos, enemy* target);
	~shot(void);
	int getColor(void) const;
	void setColor(int color);
	sf::RectangleShape getShape(void) const;
	void setPosition(sf::Vector2i pos);
	void setPosition(int x, int y);
	sf::Vector2i getPosition(void) const;
	bool move(void);
	bool operator==(const shot& that);
	sf::Vector2f getPixelPosition(void) const;
	sf::Vector2f getTargetPosition(void) const;

private:
	int color;
	sf::RectangleShape shape;
	sf::Vector2i position;
	sf::Vector2f start_pos;
	sf::Vector2f target_pos;
	sf::Vector2f pixel_position;
	sf::Vector2f shot_direction;
	enemy* target;

};
}
