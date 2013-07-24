#include "stdafx.h"
#include "wave.hpp"
using namespace game;

wave::wave(void) {}

wave::wave(string wave_string, sf::Vector2i startPos): startPos(startPos) {
	finished = false;
	vector<string> enemies = string_split(wave_string, '#');
	for(auto it = enemies.begin(); it != enemies.end(); ++it) {
		stringstream colorstream(*it);
		int color_value;
		colorstream >> hex >> color_value;
		this->push_back(enemy(color_value, startPos));
	}
}

enemy wave::spawn(void) {
	enemy out (0, startPos);
	if(it != this->end()) {
		out = *it++;
		if(it == this->end()) finished = true;
		return out;
	}
	return out;
}

void wave::ready(void) {
	it = this->begin();
	this->finished = false;
}

void wave::setFinished(bool finished) {
	this->finished = finished;
}

bool wave::isFinished(void) {
	return this->finished;
}