#include "stdafx.h"
#include "level.hpp"
<<<<<<< HEAD
#include "Logger.hpp"

level::level(void) { }
=======
using namespace game;
>>>>>>> Classes

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

bool level::loadFromFile(const std::string& path) {
	Logger *logger = Logger::get();
	sf::Image levelImg;
	if(!levelImg.loadFromFile(path))
		return false;
	
	unsigned int N = levelImg.getSize().x;
	unsigned int M = levelImg.getSize().y;
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < M; j++) {\
			sf::Color c = levelImg.getPixel(i, j);
			if(c == sf::Color::Black)
				logger->info("Buildable tile");
			if(c == sf::Color::White)
				logger->info("Walkable tile");
			if(c == sf::Color::Green)
				logger->info("Start tile");
			if(c == sf::Color::Red)
				logger->info("End tile");
		}
	}
	return true;
}