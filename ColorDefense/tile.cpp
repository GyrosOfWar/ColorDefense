#include "stdafx.h"
#include "tile.hpp"


bool tile::isPassable(void) {
	return this->passable;
}

bool tile::isBuildable(void) {
	return this->buildable;
}

sf::Texture* tile::getTexture(void) {
	return &texture;
}
void tile::setTexture(sf::Texture* texture) {
	this->texture = *texture;
}
sf::Sprite* tile::getSprite(void) {
	return &sprite;
}
void tile::setSprite(sf::Sprite* sprite) {
	this->sprite = *sprite;
}