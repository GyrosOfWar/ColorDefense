#include "stdafx.h"
#include "animation.hpp"

animation::animation(sf::Vector2f start, sf::Vector2f end, sf::Shape& shape, float speed): 
	start(start), end(end), shape(&shape), speed(speed) {
		this->increment = MOVE_DISTANCE * speed;
		this->direction = normalizeVec(end - start);
		this->finished = false;
		this->position = start;
}

sf::Shape& animation::getShape(void) {
	return *shape;
}

bool animation::isFinished(void) {
	return finished; 
}

void animation::animate() {
	if(!finished) {
		auto newPos = position;
		newPos += increment * direction;
		position = newPos;
		shape->setPosition(position);
		if(position == end)
			finished = true;
	}
}

void animation::update(sf::Vector2f start, sf::Vector2f end, float speed) {
	this->start = start;
	this->end = end;
	this->speed = speed;
	this->position = start;
	this->increment = MOVE_DISTANCE * speed;
	this->direction = normalizeVec(end - start);
	finished = false;
}

void animation::update(sf::Vector2i start, sf::Vector2i end, float speed) {
	this->update(sf::Vector2f(start.x, start.y), sf::Vector2f(end.x, end.y), speed);
}