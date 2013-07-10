#include "stdafx.h"
#include "wave.hpp"


wave::wave(void)
{
}


wave::~wave(void)
{
}


enemy* wave::spawn(void) {
	if(it != this->end()) {
		return *it++;
	}
	else  {
		finished = true;
		return *it++;
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
