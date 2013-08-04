#pragma once
#include "stdafx.h"
#include "gamelogic.hpp"

using namespace game;
using namespace chrono;

gamelogic::gamelogic(void) {
	this->finished = false;
	lvl_no = 0;
	this->next_lvl();
	this->adding_tower = false;
}

gamelogic::~gamelogic(void) { }

void gamelogic::update(void) {
#pragma region LVLRUNNING
	if(!lvl.isFinished()) {
		auto startPos = lvl.getStartTileCoords();
		tile* startTile = (tile*) lvl.getTileAt(startPos);

		//getting next wave
		if(enemies.empty()) {
			this->current_wave = this->lvl.getNextWave();
			current_wave.ready();
		}


		//spawning opponents
		if(!current_wave.isFinished()) {
			if(!startTile->isOccupied()) {
				//extra check for lvl end
				if(!lvl.isFinished()) set_on_field(current_wave.spawn());
			}
		}


		//moving enemies
		if(!enemies.empty()) {
			for(auto it = enemies.begin(); it != enemies.end(); ++it) {
				bool removedEnemy = this->move_enemy(*it);
				if(removedEnemy) 
					it = enemies.begin();
				if(enemies.empty())
					break;
			}
		}
	}
#pragma endregion
#pragma region LVLFINISHED
	else {
		this->bshowDialog = true;
		if(lvl_no == MAXLVLS) {
			finished = true;
		}
	}
#pragma endregion


}

void gamelogic::set_on_field(enemy enemy) {
	//gegner aufs feld setzten
	//gegner position = startposition
	//enemy in liste
	auto startPos = lvl.getStartTileCoords();
	tile* startTile = (tile*) lvl.getTileAt(startPos);
	if(!startTile->isOccupied()) {
		//enemy.moveTo(startPos, false);
		startTile->setOccupied(true);
		enemies.push_back(enemy);
	}
}

bool gamelogic::move_enemy(enemy& enemy) {
	auto en_path = lvl.getEnemyPath();
	auto currentPos = en_path.getPoint(enemy.getSpot());

	if(currentPos != lvl.getEndTileCoords()) {

		if(enemy.animFinished() && enemy.isAnimating()) {
			tile* prev = (tile*)lvl.getTileAt(currentPos);
			prev->setOccupied(false);
			enemy.incrSpot();
		}
		enemy.moveTo(en_path.getPoint(enemy.getSpot()), true);
		tile* next = (tile*)lvl.getTileAt(en_path.getPoint(enemy.getSpot()));
		next->setOccupied(true);
		return false;
	}
	else {
		lvl.setTileAt(lvl.getEndTileCoords(), passable_tile());
		enemies.remove(enemy);
		return true;
	}
}

void gamelogic::move_shot(const shot& shot) {
	//shot weiterbewegen richtung enemy oder richtung sein ziel
	//ziel davor ausrechnen, damit shot nicht bloed fliegt (gerade statt komische parabel oda so xD)

	//if shot.pos == target _-> target changeColor!!
	//shot aus liste entfernen

	// | X | T | X: enemy, T: tower 
	// | . | . |
	// | . | . |
	// | Y | . | Y: Enemy position at shot impact
	//
	// Y = X + time/speed

}

void gamelogic::loadLevel(int n) {
	std::stringstream levelFilePath;
	levelFilePath << BASE_PATH << n << LEVELFILE_SUFFIX;

	std::stringstream tilesPath;
	tilesPath << BASE_PATH << n << TILES_SUFFIX;
	this->lvl = level(levelFilePath.str(),  tilesPath.str(), 1); 
}

level& gamelogic::getLevel() {
	return lvl;
}

list<enemy>& gamelogic::getEnemies(void) {
	return enemies;
}

bool gamelogic::showDialog(void) {
	return bshowDialog;
}

vector<sf::Drawable*> gamelogic::createDialogue(void) {
	this->Sdialogue.next_lvl = sf::RectangleShape(sf::Vector2f(150,75));
	this->Sdialogue.border = sf::RectangleShape(sf::Vector2f(400,200));

	this->Sdialogue.border.setPosition(200,200);
	this->Sdialogue.next_lvl.setPosition(225, 300);

	this->Sdialogue.next_lvl.setFillColor(sf::Color(0,255,0,255));

	this->Sdialogue.font.loadFromFile("arial.ttf");
	if(!finished) {
		this->Sdialogue.text = "continue";
	}
	else {
		this->Sdialogue.text = "finish";
	}
	this->Sdialogue.header = sf::Text(Sdialogue.text, Sdialogue.font, 20U);
	this->Sdialogue.header.setColor(sf::Color(0,0,0,255));
	this->Sdialogue.header.setPosition(sf::Vector2f(235,315));
	dialogue.push_back(&Sdialogue.border);
	dialogue.push_back(&Sdialogue.next_lvl);
	dialogue.push_back(&Sdialogue.header);

	return dialogue; 


}

void gamelogic::next_lvl(void) {
	this->bshowDialog = false;
	lvl_no++;

	std::stringstream levelFilePath;
	levelFilePath << BASE_PATH << lvl_no << LEVELFILE_SUFFIX;

	std::stringstream tilesPath;
	tilesPath << BASE_PATH << lvl_no << TILES_SUFFIX;
	this->lvl = level(levelFilePath.str(),  tilesPath.str(), lvl_no); 
	/*this->current_wave = lvl.getNextWave();
	this->enemies = current_wave;*/ //UNCOMMEND ME
	this->shots = list<shot>();
	this->running = true;


}

bool gamelogic::is_finished(void) {
	return this->finished;
}

void gamelogic::add_tower(tower t) {
	if(adding_tower) towers.pop_back();
	this->towers.push_back(t);
	this->adding_tower = true;
}

list<tower>& gamelogic::getTowers(void) {
	return this->towers;
}

bool gamelogic::is_adding_tower(void) {
	return this->adding_tower;
}

void gamelogic::set_tower(sf::Vector2i pos) {
	auto it = towers.end();
	it--;
	it->setPosition(pos);
	tile* target = (tile*) lvl.getTileAt(convertToCellCoords(sf::Vector2f(pos)));
	if(target->isBuildable() && !target->isOccupied()) {
		it->set_set(true);
		this->adding_tower = false;
		target->setOccupied(true);
	}
	
}