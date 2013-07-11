#pragma once
#include "enemy.hpp"
namespace game {
class shot

{
public:
	shot(int color);
	~shot(void);
	int getColor(void);
	void setColor(int color);
	int getX(void);
	void setX(int x);
	int getY(void);
	void setY(int y);
	enemy* getTarget(void);
	void setTarget(enemy* target);
	sf::Shape* getShape(void);

private:
	int color;
	int x_pos;
	int y_pos;
	enemy* target;
	sf::Shape* shape;


};
}
