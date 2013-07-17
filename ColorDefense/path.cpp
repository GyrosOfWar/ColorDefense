#include "stdafx.h"
#include "path.hpp"

path::path(void) { 
	points = vector<sf::Vector2f>();
}

vector<sf::Vector2f>::iterator path::begin() {
	return points.begin();
}

vector<sf::Vector2f>::iterator path::end() {
	return points.end();
}

void path::makePath(const level& level) {
	auto start = level.getEndTileCoords();
	auto end = level.getEndTileCoords();
	auto pos = start;
	addPoint(start);

	bool foundEnd = false;
	while(!foundEnd) {
		auto x = pos.x;
		auto y = pos.y;

		vector<sf::Vector2i> neighbors;
		neighbors.push_back(sf::Vector2i(x-1, y));
		neighbors.push_back(sf::Vector2i(x+1, y));
		neighbors.push_back(sf::Vector2i(x, y-1));
		neighbors.push_back(sf::Vector2i(x, y+1));

		auto lastPos = points[points.size() - 1];

		if(sf::Vector2i(x, y) == end) {
			foundEnd = true;
		}

		for(int i = x-1; i <= x+1; i++) {
			for(int j = y-1; j <= y+1; j++) {
				if(i >= 0 && j >= 0 && i < CELLX && j < CELLY) {
					tile currentTile = level.getTileAt(i, j);
					sf::Vector2f currentPos (i, j);

					if(currentTile.isPassable() && currentPos != lastPos) {

					}
				}
			}
		}
	}
}

void path::addPoint(sf::Vector2i v) {
	addPoint(v.x, v.y);
}

void path::addPoint(int x, int y) {
	points.push_back(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

void path::addPoint(float x, float y) {
	points.push_back(sf::Vector2f(x, y));
}