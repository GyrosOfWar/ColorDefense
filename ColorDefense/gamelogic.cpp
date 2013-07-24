#pragma once
#include "stdafx.h"
#include "gamelogic.hpp"

using namespace game;
using namespace chrono;

gamelogic::gamelogic(void) {
	std::stringstream levelFilePath;
	levelFilePath << BASE_PATH << 1 << LEVELFILE_SUFFIX;

	std::stringstream tilesPath;
	tilesPath << BASE_PATH << 1 << TILES_SUFFIX;
	this->lvl = level(levelFilePath.str(),  tilesPath.str(), 1); 
	/*this->current_wave = lvl.getNextWave();
	this->enemies = current_wave;*/ //UNCOMMEND ME
	this->shots = list<shot>();
	this->running = true;
}

gamelogic::~gamelogic(void) { }

void gamelogic::update(void) {

	if(enemies.empty()) {
		this->current_wave = this->lvl.getNextWave();
		current_wave.ready();
	}
	else {
		for(auto it = enemies.begin(); it != enemies.end(); ++it) {
			bool removedEnemy = this->move_enemy(*it);
			if(removedEnemy) 
				it = enemies.begin();
			if(enemies.empty())
				break;
		}
	}

	auto startPos = lvl.getStartTileCoords();
	tile* startTile = (tile*) lvl.getTileAt(startPos);

	if(!current_wave.isFinished()) {
		if(!startTile->isOccupied()) {
			set_on_field(current_wave.spawn());
		}
	}
}

void gamelogic::set_on_field(enemy enemy) {
	//gegner aufs feld setzten
	//gegner position = startposition
	//enemy in liste
	auto startPos = lvl.getStartTileCoords();
	tile* startTile = (tile*) lvl.getTileAt(startPos);
	if(!startTile->isOccupied()) {
		startTile->setOccupied(true);
		enemies.push_back(enemy);
	}
}

bool gamelogic::move_enemy(enemy& enemy) {
	auto en_path = lvl.getEnemyPath();
	auto currentPos = en_path.getPoint(enemy.getSpot());
	bool hitEnd = false;

	if(currentPos != en_path.getLast()) {
		if(enemy.animFinished() && enemy.isAnimating()) {
			tile* prev = (tile*)lvl.getTileAt(currentPos);
			prev->setOccupied(false);
			enemy.incrSpot();
		}
		enemy.moveTo(en_path.getPoint(enemy.getSpot()), true);
		if(currentPos != lvl.getEndTileCoords() && !hitEnd) {
			hitEnd = true;
			tile* next = (tile*)lvl.getTileAt(en_path.getPoint(enemy.getSpot()));
			next->setOccupied(true);
		}
		return false;
	}
	else {
		cout << "Enemy to remove: " << enemy.getPixelPosition().x << " " << enemy.getPixelPosition().y << endl;
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