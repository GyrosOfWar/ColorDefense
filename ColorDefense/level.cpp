#include "stdafx.h"
#include "level.hpp"


level::level(void)
{
}


level::~level(void)
{
}

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