#pragma once
#include "stdafx.h"
#include "path.hpp"

using namespace game;

path::path(void) { 
	points = vector<sf::Vector2i>();
}

path::~path(void) {
}

vector<sf::Vector2i>::iterator path::begin() {
	return points.begin();
}

vector<sf::Vector2i>::iterator path::end() {
	return points.end();
}

void path::makePath(level& lvl) {
	auto start = lvl.getStartTileCoords();
	auto end = lvl.getEndTileCoords();
	auto pos = start;
	auto lastPos = sf::Vector2i(-1, -1);
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

		if(sf::Vector2i(x, y) == end) {
			foundEnd = true;
			break;
		}

		for(int i = x-1; i <= x+1; i++) {
			for(int j = y-1; j <= y+1; j++) {
				if(i >= 0 && j >= 0 && i < CELLX && j < CELLY) {
					tile currentTile = lvl.getTileAt(i, j);
					sf::Vector2i currentPos (i, j);

					if(currentTile.isPassable() && currentPos != lastPos) {
						if(find(neighbors.begin(), neighbors.end(), currentPos) == neighbors.end())
							continue;
						addPoint(i, j);
						currentTile.setOccupied(true);
						lvl.setTileAt(i, j, currentTile);
						lastPos = pos;
						pos = currentPos;
						if(lastPos.x != -1) {
							tile previousTile = lvl.getTileAt(lastPos.x, lastPos.y);
							previousTile.setOccupied(false);
							lvl.setTileAt(lastPos.x, lastPos.y, previousTile);
						}
					}
				}
			}
		}
	}
	if(!foundEnd) throw "Could not find an end tile!";
}

void path::addPoint(sf::Vector2i v) {
	points.push_back(v);
}

void path::addPoint(int x, int y) {
	points.push_back(sf::Vector2i(x, y));
}

void path::addPoint(float x, float y) {
	points.push_back(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)));
}