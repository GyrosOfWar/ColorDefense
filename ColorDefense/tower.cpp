#include "stdafx.h"
#include "tower.hpp"

using namespace game;

tower::tower(void) { }

tower::~tower(void) { }

int tower::getShootingRate(void) const {
	return shooting_rate;
}

void tower::setShootingRate(int rate) {
	this->shooting_rate = rate;
}

int tower::getColor(void) const {
	return this->color;
}

void tower::setColor(int color) {
	this->color = color;
}

sf::Sprite tower::getSprite(void) const {
	return sprite;
}

void tower::setSprite(sf::Sprite s) {
	this->sprite = s;
}

void tower::setPosition(sf::Vector2i vec) {
	this->position = vec;
	this->sprite.setPosition(convertToPixelCoords(vec.x, vec.y));
}

void tower::setPosition(int x, int y) {
	this->setPosition(sf::Vector2i(x, y));
}

sf::Vector2i tower::getPosition(void) const {
	return this->position;
}
