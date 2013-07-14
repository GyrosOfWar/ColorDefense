#include "stdafx.h"
#include "tile.hpp"
using namespace game;

bool tile::isPassable(void) {
	return this->passable;
}

bool tile::isBuildable(void) {
	return this->buildable;
}

sf::Sprite tile::getSprite(void) {
	return sprite;
}
void tile::setSprite(sf::Sprite sprite) {
	this->sprite = sprite;
}

int tile::getTileNumber(void) const {
	return this->tileNumber;
}