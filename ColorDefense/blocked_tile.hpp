#pragma once
#include "tile.hpp"
namespace game {
class blocked_tile: public tile {
public:
	blocked_tile(void);
	~blocked_tile(void);
};
}

