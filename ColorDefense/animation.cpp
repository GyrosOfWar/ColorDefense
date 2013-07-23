#include "stdafx.h"
#include "animation.hpp"

animation::animation(sf::Vector2f start, sf::Vector2f end, sf::CircleShape shape, float speed):
	start(start), end(end), shape(shape), speed(speed) {
		this->increment = MOVE_DISTANCE * speed;
		this->direction = normalizeVec(end - start);
		this->finished = false;
		this->position = start;
}

animation::animation(void):
	start(sf::Vector2f(-1, -1)), end(sf::Vector2f(-1, -1)), shape(sf::CircleShape(23.0f)), speed(1.0f) {		
		this->increment = MOVE_DISTANCE * speed;
		this->direction = normalizeVec(end - start);
		this->finished = false;
		this->position = start;
}

sf::CircleShape animation::getShape(void) {
	return shape;
}

bool animation::isFinished(void) {
	return finished;
}

void animation::animate() {
	if(!finished) {
		auto newPos = position;
		newPos += increment * direction;
		position = newPos;
		shape.setPosition(position);
		if(epsilonCompare(end, position)) {
			finished = true;
		}
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

void animation::setShape(sf::CircleShape shape) {
	this->shape =shape;
}