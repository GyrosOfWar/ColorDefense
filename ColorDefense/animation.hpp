#pragma once
#include "stdafx.h"
#include "util.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace game {
	class animation {
	public:
		animation(sf::Vector2f start, sf::Vector2f end, sf::CircleShape shape, float speed);
		sf::CircleShape getShape(void) const;
		void setShape(sf::CircleShape shape);
		bool isFinished(void) const;
		void animate(void);
		void update(sf::Vector2f start, sf::Vector2f end, float speed);
		void update(sf::Vector2i start, sf::Vector2i end, float speed);
	private:
		sf::Vector2f start;
		sf::Vector2f end;
		sf::Vector2f position;
		sf::CircleShape shape;
		sf::Vector2f direction;
		float speed;
		float increment;
		bool finished;
	};
}