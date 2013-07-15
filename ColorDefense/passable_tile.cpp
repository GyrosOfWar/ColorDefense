#include "stdafx.h"
#include "passable_tile.hpp"
using namespace game;

passable_tile::passable_tile(void)
{
	passable = true;
	occupied = false;
	buildable = false;
	tileNumber = 0;
}


passable_tile::~passable_tile(void)
{
}

