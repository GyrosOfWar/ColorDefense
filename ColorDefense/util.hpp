#pragma once
#include <SFML/Graphics.hpp>
#include "gamelogic.hpp"

inline sf::Vector2i convertToCellCoords(float x, float y) {
	return sf::Vector2i((int) x / TILEWIDTH, (int) y / TILEHEIGHT);
}

inline sf::Vector2f convertToPixelCoords(int x, int y) {
	return sf::Vector2f(x * TILEWIDTH, y * TILEHEIGHT);
}

inline float clamp(float x, float a, float b) {
	return x < a ? a : (x > b ? b : x);
}