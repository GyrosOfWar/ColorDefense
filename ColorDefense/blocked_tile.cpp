#include "stdafx.h"
#include "blocked_tile.hpp"
using namespace game;

blocked_tile::blocked_tile(void)
{
	passable = false;
	buildable = false;
	tileNumber = 2;
}


blocked_tile::~blocked_tile(void)
{
}

