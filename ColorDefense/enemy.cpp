#include "stdafx.h"
#include "enemy.hpp"

using namespace std;
using namespace game;



enemy::enemy(int color, sf::Vector2i startPos): anim(animation(convertToPixelCoords(startPos), convertToPixelCoords(startPos), sf::CircleShape(23.0f), 1.0f)) {
	this->color = color;
	updateColor();
	sf::CircleShape shape((TILEHEIGHT / 3) - 2.0f);
	shape.setFillColor(color_real);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.0f);
	shape.setOrigin(-2.0f, -2.0f);
	position = startPos;
	this->spot = 0;

	anim.setShape(shape);
	this->moveTo(startPos, false);
}

enemy::~enemy(void) { }

void enemy::updateColor(void) {
	int r = this->color >> 16;
	int g = this->color >> 8;
	g %= 0x100;
	int b = this->color % 0x100;

	color_real = sf::Color(r,g,b);
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


// Moves enemy to given position, animated.
void enemy::moveTo(sf::Vector2i vec, bool animate) {
	if(animate) {
		_isAnimating = true;
		if(anim.isFinished()) {
			//cout << "old pos: " << position.x << " " << position.y << ", new pos: " << vec.x << " " << vec.y << endl;
			position.x += 0.5;
			position.y += 0.5;
			vec.x += 0.5;
			vec.y += 0.5;
			anim.update(convertToPixelCoords(position), convertToPixelCoords(vec), 1.0f);
			anim.animate();
			position = vec;
		}
		else {
			anim.animate();
		}
	}
	else {
		_isAnimating = false;
		if(vec.y == 0) vec.y--;
		else if(vec.x == 0) vec.x--;
		anim.update(convertToPixelCoords(vec), convertToPixelCoords(vec), 1.0f);
		anim.animate();
		position = vec;
	}
}

void enemy::moveTo(int x, int y, bool animate) {
	this->moveTo(sf::Vector2i(x, y), animate);
}

sf::CircleShape enemy::getShape(void) {
	return anim.getShape();
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

bool enemy::animFinished(void) const {
	return anim.isFinished();
}

bool enemy::isAnimating(void) const {
	return _isAnimating;
}