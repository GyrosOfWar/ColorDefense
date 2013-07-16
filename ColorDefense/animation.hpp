#include "stdafx.h"
#include "util.hpp"
#include <SFML/Graphics.hpp>

namespace game {
	class animation {
	public:
		animation(sf::Vector2f start, sf::Vector2f end, sf::CircleShape shape, float speed);
		sf::CircleShape getShape(void);
		bool isFinished(void);
		void animate(void);
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