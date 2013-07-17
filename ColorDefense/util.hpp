#pragma once
#include <SFML/Graphics.hpp>
#include "gamelogic.hpp"

inline sf::Vector2i convertToCellCoords(float x, float y) {
	return sf::Vector2i(static_cast<int>(x / TILEWIDTH), static_cast<int>(y / TILEHEIGHT));
}

inline sf::Vector2f convertToPixelCoords(int x, int y) {
	return sf::Vector2f(static_cast<float>(x * TILEWIDTH), static_cast<float>(y * TILEHEIGHT));
}

inline float clamp(float x, float a, float b) {
	return x < a ? a : (x > b ? b : x);
}