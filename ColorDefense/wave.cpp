#include "stdafx.h"
#include "wave.hpp"
using namespace game;

wave::wave(void) {
	finished = false;
}

enemy wave::spawn(void) {
	enemy out (0);
	if(it != this->end()) {
		out = *it++;
		if(it == this->end()) finished = true;
		return out;
	}
	else  {
		return NULL;
	}
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
