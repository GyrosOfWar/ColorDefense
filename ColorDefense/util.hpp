#pragma once
#include <SFML/Graphics.hpp>
#include "constants.hpp"

using namespace game;
using namespace std;

inline sf::Vector2i convertToCellCoords(float x, float y) {
	return sf::Vector2i(static_cast<int>(x / TILEWIDTH), static_cast<int>(y / TILEHEIGHT));
}

inline sf::Vector2f convertToPixelCoords(int x, int y) {
	return sf::Vector2f(static_cast<float>(x * TILEWIDTH), static_cast<float>(y * TILEHEIGHT));
}

inline sf::Vector2i convertToCellCoords(sf::Vector2f vec) {
	return sf::Vector2i(static_cast<int>(vec.x / TILEWIDTH), static_cast<int>(vec.y / TILEHEIGHT));
}

inline sf::Vector2f convertToPixelCoords(sf::Vector2i vec) {
	return sf::Vector2f(static_cast<float>(vec.x * TILEWIDTH), static_cast<float>(vec.y * TILEHEIGHT));
}

inline float clamp(float x, float a, float b) {
	return x < a ? a : (x > b ? b : x);
}

inline sf::Vector2f normalizeVec(const sf::Vector2f& source) {
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	return (length == 0) ? source : sf::Vector2f(source.x / length, source.y / length);
}

inline vector<string> string_split(string to_split, char delimiter) {
	vector<string> out;
	string buffer;
	for(int i = 0; i < to_split.length(); i++) {
		if(to_split[i] == delimiter) {
			if(i > 0) {
				out.push_back(buffer);
				buffer = "";
			}
		}
		else {
			buffer += to_split[i];
		}
	}

	return out;

}

// Returns true if two float vectors are equal.
// Don't use for anything other than checking if an animation has finished! (tolerance too low)
inline bool epsilonCompare(sf::Vector2f a, sf::Vector2f b) {
	bool cmpX = fabs(a.x - b.x) <= 0.001f;
	bool cmpY = fabs(a.y - b.y) <= 0.001f;

	return cmpX && cmpY;
}