#include "stdafx.h"
#include "buildable_tile.hpp"
using namespace game;

buildable_tile::buildable_tile(void)
{
	passable = false;
	buildable = true;
	occupied = false;
	tileNumber = 1;
}


buildable_tile::~buildable_tile(void)
{
}
