#pragma once
#include "stdafx.h"
#include "constants.hpp"
#include "util.hpp"
#include "level.hpp"
#include "shot.hpp"
#include "wave.hpp"
#include "animation.hpp"
#include "tower.hpp"
#include <algorithm>
#include <list>
#include <sstream>

/*
Class for the gamelogic
*/

using std::list;

namespace game {

	struct dialouge_struct {
		sf::RectangleShape next_lvl;
		sf::RectangleShape border;
		sf::Text header;
		sf::Font font;
		string text;
	};
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
		bool showDialog(void);
		vector<sf::Drawable*> createDialogue(void);
		void next_lvl(void);
		bool is_finished(void);
		void add_tower(tower t);
		list<tower>& getTowers(void);
		bool is_adding_tower(void);
		void set_tower(sf::Vector2i pos);
	private:
		int lvl_no;
		level lvl;
		wave current_wave;
		list<enemy> enemies;
		list<shot> shots;
		list<tower> towers;
		bool running;
		bool bshowDialog;
		bool finished;
		vector<sf::Drawable*> dialogue;
		dialouge_struct Sdialogue;
		bool adding_tower;
	};

}
