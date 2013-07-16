#include "stdafx.h"
#include "animation.hpp"

animation::animation(sf::Vector2f start, sf::Vector2f end, sf::CircleShape shape, float speed): 
	start(start), end(end), shape(shape), speed(speed) {
		this->increment = MOVE_DISTANCE * speed;
		this->direction = end - start;
		this->finished = false;
		cout << start.x << " " << start.y << endl;
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
		//cout << position.x << " " << position.y << endl;
		if(position == end)
			finished = true;
	}
}