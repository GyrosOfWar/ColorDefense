#include "stdafx.h"
#include "shot.hpp"
#include "util.hpp"

using namespace game;

shot::shot(int color)
{
	this->color = color;
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
enemy* shot::getTarget(void) {
	return this->target;
}
void shot::setTarget(enemy* target) {
	this->target = target;
}

sf::Shape* shot::getShape(void) {
	return shape;
}

sf::Vector2i shot::getPosition(void) {
	return position;
}

void shot::setPosition(sf::Vector2i pos) {
	position = pos;
	shape->setPosition(convertToPixelCoords(pos.x, pos.y));
}

void shot::setPosition(int x, int y) {
	this->setPosition(sf::Vector2i(x, y));
}