#pragma once
#include "tile.hpp"
namespace game {
class buildable_tile: public tile
{
public:
	buildable_tile(void);
	~buildable_tile(void);
};
}