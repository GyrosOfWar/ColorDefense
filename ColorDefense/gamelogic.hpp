#pragma once
#include "stdafx.h"
#include "constants.hpp"
#include "util.hpp"
#include "level.hpp"
#include "shot.hpp"
#include "wave.hpp"
#include "animation.hpp"
#include <algorithm>
#include <list>
#include <sstream>

/*
Class for the gamelogic
*/

using std::list;

namespace game {
	class gamelogic {
	public:
		gamelogic(void);
		~gamelogic(void);
		void update(void);
		void set_on_field(void);
		bool isRunning(void);
		void set_on_field(enemy enemy);
		bool move_enemy(enemy& enemy);
		void move_shot(const shot& shot);
		void loadLevel(int n);
		level& getLevel(void);
		list<enemy>& getEnemies(void);
	private:
		level lvl;
		wave current_wave;
		list<enemy> enemies;
		list<shot> shots;
		bool running;
	};

}
