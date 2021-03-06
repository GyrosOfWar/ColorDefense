#include "stdafx.h"
#include "tower.hpp"

using namespace game;

tower::tower(int color) { 
	this->color = color;
	updateColor();
	this->shape = sf::RectangleShape(sf::Vector2f((TILEHEIGHT / 2) - 2.0f, (TILEHEIGHT / 2) - 2.0f));
	
	shape.setFillColor(color_real);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.0f);
	this->set = false;

}

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
	this->position = convertToCellCoords(sf::Vector2f(vec));

	//** get the center of the TILE */
	sf::Vector2f left_upper = sf::Vector2f(position.x * TILEWIDTH, position.y * TILEHEIGHT);
	left_upper.x += TILEWIDTH/4;
	left_upper.y += TILEHEIGHT/4;



	//this->sprite.setPosition(sf::Vector2f(vec));
	this->shape.setPosition(left_upper);
}

void tower::setPosition(int x, int y) {
	this->setPosition(sf::Vector2i(x, y));
}

sf::Vector2i tower::getPosition(void) const {
	return this->position;
}

sf::RectangleShape tower::getShape(void) {
	return this->shape;
}

void tower::updateColor(void) {
	int r = this->color >> 16;
	int g = this->color >> 8;
	g %= 0x100;
	int b = this->color % 0x100;

	color_real = sf::Color(r,g,b);
}

void tower::set_set(bool set) {
	this->set = set;
}

bool tower::is_set(void) {
	return this->set;
}