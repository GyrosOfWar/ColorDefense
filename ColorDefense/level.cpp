#include "stdafx.h"
#include "level.hpp"
#include "Logger.hpp"
#include "buildable_tile.hpp"
#include "passable_tile.hpp"
#include "blocked_tile.hpp"
#include "tile.hpp"
#include "gamelogic.hpp"

using namespace game;

level::level(string levelFilePath, string tilesPath) {
	map = vector<tile>();
	waves = vector<wave>();
	//it = waves.begin();
	currentWaveNum = 0;
	finished = false;
	level_tile_map = tile_map();
	// FIXME
	lvlno = 0;
	if(!loadFromFile(levelFilePath))
		throw "Failed to open level file.";
	if(!fillTileMap(tilesPath))
		throw "Failed to open tile file.";
}

level::level(void) {
}

level::~level(void) { }

// Error: Incompatible iterators (?)
wave level::getNextWave(void) {
	//if(it != waves.end()) {
	//	return *it++;
	//}
	//else  {
	//	finished = true;
	//	return *it++;
	//}

	// FIXME
	if(waves.empty()) {
		return wave();
	}
	if(currentWaveNum < waves.size()-1) {
		currentWaveNum++;
		return waves[currentWaveNum];
	}
	else {
		finished = true;
		return waves[currentWaveNum];
	}
}

vector<tile> level::getMap(void) {
	return map;
}

int level::getLvlno(void) {
	return lvlno;
}

bool level::isFinished(void) {
	return finished;
}

// Loads a level from an image located at path.
// Returns true on success, false otherwise.
bool level::loadFromFile(const std::string& path) {
	sf::Image levelImg;
	if(!levelImg.loadFromFile(path))
		return false;
	
	unsigned int N = levelImg.getSize().x;
	unsigned int M = levelImg.getSize().y;
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < M; j++) {
			sf::Color c = levelImg.getPixel(i, j);
			if(c == BUILDABLE_TILE) {
				map.push_back(buildable_tile());
			}
			if(c == PASSABLE_TILE) {
				map.push_back(passable_tile());
			}
			if(c == START_TILE) {
				map.push_back(passable_tile());
			}
			if(c == END_TILE) {
				map.push_back(passable_tile());
			}
		}
	}
	return true;
}

bool level::fillTileMap(const string& path) {
	return level_tile_map.load(path, sf::Vector2u(TILEWIDTH, TILEHEIGHT), map, CELLX, CELLY);
}

tile_map level::getTileMap() { 
	return level_tile_map;
}

tile level::getTileAt(int i, int j) {
	return map[i * CELLY + j];
}

sf::Vector2i level::getStartTileCoords() {
	return startTile;
}

sf::Vector2i level::getEndTileCoords() {
	return endTile;
}