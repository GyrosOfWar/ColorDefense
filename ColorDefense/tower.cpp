#include "stdafx.h"
#include "tower.hpp"

using namespace game;

tower::tower(void)
{
}


tower::~tower(void)
{
}


int tower::get_shooting_rate(void) {
	return shooting_rate;
}
void tower::set_shooting_rate(int rate) {
	this->shooting_rate = rate;
}

int tower::getX(void) {
	return this->x_pos;
}
void tower::setX(int x) {
	this->x_pos = x;
}
int tower::getY(void) {
	return this->y_pos;
}
void tower::setY(int y) {
	this->y_pos = y;
}

int tower::getColor(void) {
	return this->color;
}
void tower::setColor(int color) {
	this->color = color;
}
