#include "stdafx.h"
#include "enemy.hpp"
#include "util.hpp"

using namespace std;
using namespace game;

enemy::enemy(int color, sf::Vector2f startPos): anim(animation(startPos, startPos, shape, 1.0f)) {
	this->color = color;
	updateColor();
	shape = sf::CircleShape((TILEHEIGHT / 2) - 2.0f);
	shape.setFillColor(color_real);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.0f);
	shape.setOrigin(-2.0f, -2.0f);
	position = sf::Vector2i(0, 0);
	lastPosition = sf::Vector2i(-1, -1);
	this->maxHealth = 100;
	health = this->maxHealth;
	this->spot = 0;
// 	this->anim = animation(sf::Vector2f(0, 0),
// 						   sf::Vector2f(0, 0),
// 						   this->shape,
// 						   1.0f);
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

void enemy::setPosition(sf::Vector2i vec, bool animate) {
// 	if(animate) {
// 		this->lastPosition = position;
// 	}
// 	this->shape.setPosition(convertToPixelCoords(vec.x, vec.y));
// 	this->position = vec;
	if(animate) {
		if(anim.isFinished()) {
			//cout << "old pos: " << position.x << " " << position.y << ", new pos: " << vec.x << " " << vec.y << endl;
			anim.update(convertToPixelCoords(position), convertToPixelCoords(vec), 1.0f);
			anim.animate();
			position = vec;
		}
		else {
			anim.animate();
		}
	}
	else {
		//cout << "Not animating!" << endl;
		position = vec;
		anim.update(convertToPixelCoords(vec), convertToPixelCoords(vec), 1.0f);
	}
}

void enemy::setPosition(int x, int y, bool animate) {
	this->setPosition(sf::Vector2i(x, y), animate);
}

sf::Shape& enemy::getShape(void) {
	return anim.getShape();
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

int enemy::getSpot(void) {
	return spot;
}

void enemy::incrSpot(void) {
	if(anim.isFinished())
	this->spot++;
}