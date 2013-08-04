#include "stdafx.h"
#include "tile.hpp"
using namespace game;

bool tile::isPassable(void) const {
	return this->passable;
}

bool tile::isBuildable(void) const {
	return this->buildable;
}

sf::Sprite tile::getSprite(void) const {
	return sprite;
}

void tile::setSprite(sf::Sprite sprite) {
	this->sprite = sprite;
}

int tile::getTileNumber(void) const {
	return this->tileNumber;
}

bool tile::isOccupied(void) const {
	return occupied;
}

void tile::setOccupied(bool occ) {
	occupied = occ;
}