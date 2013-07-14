#include "stdafx.h"
#include "buildable_tile.hpp"
using namespace game;

buildable_tile::buildable_tile(void)
{
	passable = false;
	buildable = true;
	tileNumber = 1;
}


buildable_tile::~buildable_tile(void)
{
}
