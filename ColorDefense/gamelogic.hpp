#pragma once
#include "level.hpp"

/*

Class for the gamelogic

*/



namespace game {
class gamelogic
{
public:
	gamelogic(void);
	~gamelogic(void);

private:
	level* lvl;
};

}