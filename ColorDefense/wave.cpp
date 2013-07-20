#include "stdafx.h"
#include "wave.hpp"
using namespace game;

wave::wave(void) {}

wave::wave(string wave_string) {
	finished = false;
	/*enemy test(0x000000, 100);
	enemy test2(0xff0000, 100);
	enemy test3(0x8fff80, 100);
	
	this->push_back(test);
	this->push_back(test2);
	this->push_back(test3);*/

	/*
	TODO: split string into single enemies.. string format: #xxxxxx#yyyyyy#... where x and y are numbers between 0 and f **/
	vector<string> enemies = string_split(wave_string, '#');
	for(vector<string>::iterator it = enemies.begin(); it != enemies.end(); ++it) {

		stringstream colorstream(*it);
		int color_value;
		colorstream >> hex >> color_value;

		this->push_back(enemy(color_value, 100));
	}


}

enemy wave::spawn(void) {
	enemy out (0, 100);
	if(it != this->end()) {
		out = *it++;
		if(it == this->end()) finished = true;
		return out;
	}
	return out;
}

void wave::ready(void) {
	it = this->begin();
}

void wave::setFinished(bool finished) {
	this->finished = finished;
}

bool wave::isFinished(void) {
	return this->finished;
}
