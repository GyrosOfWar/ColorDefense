#pragma once
#include "stdafx.h"
#include "util.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace game {
	class animation {
	public:
		animation(sf::Vector2f start, sf::Vector2f end, sf::Shape& shape, float speed);
		sf::Shape& getShape(void);
		bool isFinished(void);
		void animate(void);
	private:
		sf::Vector2f start;
		sf::Vector2f end;
		sf::Vector2f position;
		sf::Shape* shape;
		sf::Vector2f direction;
		float speed;
		float increment;
		bool finished;
	};
}