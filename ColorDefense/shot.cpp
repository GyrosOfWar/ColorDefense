#include "stdafx.h"
#include "shot.hpp"

using namespace game;

shot::shot(void)
{
}


shot::~shot(void)
{
}


int shot::getColor(void) {
	return this->color;
}
void shot::setColor(int color) {
	this->color = color;
}
int shot::getX(void) {
	return this->x_pos;
}
void shot::setX(int x) {
	this->x_pos = x;
}
int shot::getY(void) {
	return this->y_pos;
}
void shot::setY(int y) {
	this->y_pos = y;
}
enemy* shot::getTarget(void) {
	return this->target;
}
void shot::setTarget(enemy* target) {
	this->target = target;
}