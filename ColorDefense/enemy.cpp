#include "stdafx.h"
#include "enemy.hpp"
#include "util.hpp"

using namespace std;
using namespace game;

enemy::enemy(int color, int maxHealth = 100) {
	this->color = color;
	updateColor();
	sf::CircleShape shape((TILEHEIGHT / 3) - 2.0f);
	shape.setFillColor(color_real);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.0f);
	shape.setOrigin(-2.0f, -2.0f);
	position = sf::Vector2i(0, 0);
	this->maxHealth = maxHealth;
	health = this->maxHealth;
	this->spot = 0;

	anim.setShape(shape);
}

enemy::~enemy(void) { }

void enemy::updateColor(void) {
	int r = this->color >> 16;
	int g = this->color >> 8;
	g %= 0x100;
	int b = this->color % 0x100;

	color_real = sf::Color(r,g,b);
	auto shape = anim.getShape();
	shape.setFillColor(color_real);
	shape.setPosition(convertToPixelCoords(position.x, position.y));
	anim.setShape(shape);
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

void enemy::setPosition(sf::Vector2i vec) {
	//this->shape.setPosition(convertToPixelCoords(vec.x, vec.y));
	this->position = vec;
}

// Moves enemy to given position, animated.
void enemy::moveTo(sf::Vector2i vec, bool animate) {
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
		if(vec.y == 0) vec.y--;
		else if(vec.x == 0) vec.x--;
		anim.update(convertToPixelCoords(vec), convertToPixelCoords(position), 1.0f);
	}
}

void enemy::moveTo(int x, int y, bool animate) {
	this->moveTo(sf::Vector2i(x, y), animate);
}

void enemy::setPosition(int x, int y) {
	this->setPosition(sf::Vector2i(x, y));
}

sf::CircleShape enemy::getShape(void) {
	return anim.getShape();
}

int enemy::getHealth(void) {
	return health;
}

void enemy::setHealth(int h) {
	this->health = h;
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

bool enemy::animFinished(void) {
	return anim.isFinished();
}