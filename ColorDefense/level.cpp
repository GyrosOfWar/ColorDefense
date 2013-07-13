#include "stdafx.h"
#include "level.hpp"
#include "Logger.hpp"
#include "buildable_tile.hpp"
#include "passable_tile.hpp"
#include "blocked_tile.hpp"
#include "tile.hpp"

using namespace game;

level::~level(void) { }

wave* level::getNextWave(void) {
	if(it != waves.end()) {
		return *it++;
	}
	else  {
		finished = true;
		return *it++;
	}
}

tile** level::getMap(void) {
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
	Logger *logger = Logger::get();
	sf::Image levelImg;
	if(!levelImg.loadFromFile(path))
		return false;
	
	unsigned int N = levelImg.getSize().x;
	unsigned int M = levelImg.getSize().y;
	unsigned int mapIdx = 0;
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < M; j++) {\
			sf::Color c = levelImg.getPixel(i, j);
			if(c == sf::Color::Black) {
				map[mapIdx++] = new buildable_tile();
				logger->info("Buildable tile");
			}
			if(c == sf::Color::White) {
				map[mapIdx++] = new passable_tile();
				logger->info("Passable tile");
			}
			if(c == sf::Color::Green) {
				logger->info("Start tile");
			}
			if(c == sf::Color::Red)
				logger->info("End tile");
		}
	}
	return true;
}