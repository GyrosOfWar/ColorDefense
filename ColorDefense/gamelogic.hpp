#pragma once
#include "stdafx.h"
#include "level.hpp"
#include "shot.hpp"
#include "wave.hpp"
#include <list>
#include <sstream>

/*
Class for the gamelogic
*/

using std::list;

namespace game {
const int SCREENHEIGHT = 600;
const int SCREENWIDTH = 800;
const int CELLX = 16;
const int CELLY = 12;
const int TILEHEIGHT = SCREENHEIGHT/CELLY;
const int TILEWIDTH = SCREENWIDTH/CELLX;
const int FPS = 1;
const string BASE_PATH = "res/levels/level";
const string TILES_SUFFIX = "tiles.png";
const string LEVELFILE_SUFFIX = "lvl.png";
const float MOVE_DISTANCE = static_cast<float>(TILEHEIGHT) / static_cast<float>(FPS);

class gamelogic
{
public:
	gamelogic(void);
	~gamelogic(void);
	void update(void);
	void set_on_field(void);
	bool isRunning(void);
	void set_on_field(enemy enemy);
	void move_enemy(enemy& enemy);
	void move_shot(const shot& shot);
	void loadLevel(int n);
	level& getLevel();
	list<enemy>& getEnemies();
private:
	level lvl;
	wave current_wave;
	list<enemy> enemies;
	list<shot> shots;
	bool running;
	
	sf::Vector2f calcNewPosition(const sf::Vector2f& oldPos, const sf::Vector2f& direction, float speed);
};

}
