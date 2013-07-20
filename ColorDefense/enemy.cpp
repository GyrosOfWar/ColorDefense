#include "stdafx.h"
#include "enemy.hpp"
#include "util.hpp"

using namespace std;
using namespace game;

enemy::enemy(int color, int maxHealth = 100) {
	this->color = color;
	updateColor();
	shape = sf::CircleShape((TILEHEIGHT / 2) - 2.0f);
	shape.setFillColor(color_real);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.0f);
	shape.setOrigin(-2.0f, -2.0f);
	position = sf::Vector2i(0, 0);
	lastPosition = sf::Vector2i(-1, -1);
	this->maxHealth = maxHealth;
	health = this->maxHealth;
	this->spot = 0;
}

enemy::~enemy(void) { }

void enemy::updateColor(void) {
	int r = this->color >> 16;
	int g = this->color >> 8;
	g %= 0x100;
	int b = this->color % 0x100;

	color_real = sf::Color(r,g,b);
	shape.setFillColor(color_real);
	shape.setPosition(convertToPixelCoords(position.x, position.y));
}

void enemy::setColor(int color) {
	this->color = color;
	updateColor();
}

int enemy::getColor(void) const {
	return color;
}

sf::Vector2i enemy::getPosition() const {
	return position;
}

void enemy::setPosition(sf::Vector2i vec, bool setLastPosition) {
	if(setLastPosition) {
		this->lastPosition = position;
	}
	this->shape.setPosition(convertToPixelCoords(vec.x, vec.y));
	this->position = vec;
}

void enemy::setPosition(int x, int y, bool setLastPosition) {
	this->setPosition(sf::Vector2i(x, y), setLastPosition);
}

sf::CircleShape enemy::getShape(void) {
	return shape;
}

sf::Vector2i enemy::getLastPosition(void) const {
	return lastPosition;
}

int enemy::getHealth(void) {
	return health;
}

void enemy::setHealth(int h) {
	this->health = h;
}

vector<sf::Vector2i>::iterator& enemy::getPathIterator(void) {
	return pathIterator; 
}

int enemy::getSpot(void) const {
	return spot;
}

void enemy::incrSpot(void) {
	this->spot++;
}

bool enemy::operator==(const enemy& that) {
	return this->getPosition() == that.getPosition() && this->getSpot() == that.getSpot();
}



//bool operator==(const enemy& lhs, const enemy& rhs) {
//		 
//	//if(&lhs == &rhs) return true;
//
//
//	//if(lhs.getColor() != rhs.getColor()) return false;
//	////int health;
//	////int maxHealth;
//	//if(lhs.getPosition() != rhs.getPosition()) return false;
//	////sf::Color color_real;
//	////sf::CircleShape shape;
//	////sf::Vector2i lastPosition;
//	////vector<sf::Vector2i>::iterator pathIterator;
//	//if(lhs.getSpot() != rhs.getSpot()) return false;
//
//	//return true;
//	return lhs.getPosition() == rhs.getPosition() && lhs.getSpot() == rhs.getSpot();
//}