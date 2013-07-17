#include "stdafx.h"
#include "animation.hpp"

sf::Vector2f normalizeVec(const sf::Vector2f& source) {
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

//animation::animation(sf::Vector2f start, sf::Vector2f end, sf::Shape* shape, float speed): 
//	start(start), end(end), shape(shape), speed(speed) {
//		this->increment = MOVE_DISTANCE * speed;
//		this->direction = normalize(end - start);
//		this->finished = false;
//		cout << start.x << " " << start.y << endl;
//}
animation::animation(sf::Vector2f start, sf::Vector2f end, sf::CircleShape shape, float speed): 
	start(start), end(end), shape(shape), speed(speed) {
		this->increment = MOVE_DISTANCE * speed;
		this->direction = normalizeVec(end - start);
		this->finished = false;
		this->position = start;
}


//sf::Shape& animation::getShape(void) {
//	return *shape;
//}

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
		if(position == end)
			finished = true;
	}
}