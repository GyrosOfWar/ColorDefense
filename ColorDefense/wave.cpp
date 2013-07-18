#include "stdafx.h"
#include "wave.hpp"
using namespace game;

wave::wave(void) {
	finished = false;
	enemy test(0x000000, 100);
	enemy test2(0xff0000, 100);
	enemy test3(0x8fff80, 100);
	
	this->push_back(test);
	this->push_back(test2);
	this->push_back(test3);

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
