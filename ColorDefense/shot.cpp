#include "stdafx.h"
#include "shot.hpp"
#include "util.hpp"
#include <math.h>

using namespace game;

shot::shot(int color, sf::Vector2f start_pos, sf::Vector2f target_pos, enemy* target)
{
	this->color = color;
	this->shape = sf::RectangleShape(sf::Vector2f(10,5));
	this->start_pos = start_pos;
	this->pixel_position = start_pos;
	
	
	int r = this->color >> 16;
	int g = this->color >> 8;
	g %= 0x100;
	int b = this->color % 0x100;

	this->shape.setFillColor(sf::Color(r,g,b));
	this->target_pos = target_pos;
	this->target = target;
	shot_direction = normalizeVec(target_pos - start_pos);
}


shot::~shot(void)
{
}


int shot::getColor(void) const {
	return this->color;
}
void shot::setColor(int color) {
	this->color = color;
}

sf::RectangleShape shot::getShape(void) const {
	return shape;
}

sf::Vector2i shot::getPosition(void) const {
	return position;
}

void shot::setPosition(sf::Vector2i pos) {
	position = pos;
	shape.setPosition(convertToPixelCoords(pos.x, pos.y));
}

void shot::setPosition(int x, int y) {
	this->setPosition(sf::Vector2i(x, y));
}

float vectorLength(sf::Vector2f vec) {
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

bool shot::move(void) {

	//if(this->position == target->getTilePosition()) {
	//	target->setColor(target->getColor()+this->color);
	//	return true; //shot hit enemy
	//}
	//else {
	//	sf::Vector2f shot_pix = convertToPixelCoords(this->position);
	//	sf::Vector2f target_pix = target->getPixelPosition();
	//	auto diff_x = (fabs(this->start_pos.x - target_pix.x))/5;
	//	auto diff_y = (fabs(this->start_pos.y - target_pix.y))/5;
	//	if(shot_pix.x > target_pix.x) shot_pix.x -= diff_x;
	//	else shot_pix.x += diff_x;
	//	if(shot_pix.y > target_pix.y) shot_pix.y -= diff_y;
	//	else shot_pix.y += diff_y;
	//	this->shape.setPosition(shot_pix);
	//	this->position = convertToCellCoords(shot_pix);
	//}
	//return false;
	

	if(position == target->getTilePosition()) {
		target->setColor(target->getColor() + this->color);
		return true;
	}

	else {
		auto increment = MOVE_DISTANCE;
		auto newPos = pixel_position + (increment * shot_direction);

		this->pixel_position = newPos;
		shape.setPosition(newPos);
		this->position = convertToCellCoords(pixel_position);
		if(position == target->getTilePosition()) {
			return true;
		}
		return false;
	}

	
}

sf::Vector2f shot::getTargetPosition(void) const { return target_pos; }

sf::Vector2f shot::getPixelPosition(void) const { return pixel_position; }


bool shot::operator==(const shot& that) {
	return this->getTargetPosition() == that.getTargetPosition() && this->getColor() == that.getColor() && this->getPosition() == that.getPosition();
}
