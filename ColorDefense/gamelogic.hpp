#pragma once
#include "stdafx.h"
#include "level.hpp"
#include <list>
#include "shot.hpp"
#include "wave.hpp"

/*
Class for the gamelogic
*/

using std::list;

namespace game {
const int SCREENHEIGHT = 800;
const int SCREENWIDTH = 600;
const int CELLX = 16;
const int CELLY = 12;
const int TILEHEIGHT = SCREENHEIGHT/CELLY;
const int TILEWIDTH = SCREENWIDTH/CELLX;
const int FPS = 10;

class gamelogic
{
public:
	gamelogic(void);
	~gamelogic(void);
	void update(void);
	void set_on_field(void);
	bool isRunning(void);
	void set_on_field(enemy& enemy);
	void move_enemy(enemy& enemy);
	void move_shot(shot& shot);

private:
	level lvl;
	wave current_wave;
	// FIELD = variable fürs spielfeld (window.. oder zumindest pointer drauf)
	list<enemy> enemies;
	list<shot> shots;
	bool running;

};

}
