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
	this->lvl = level(levelFilePath.str(),  tilesPath.str()); 
	this->current_wave = lvl.getNextWave();
	this->enemies = current_wave;
	this->shots = list<shot>();
	this->running = true;
}

gamelogic::~gamelogic(void) {
}

void gamelogic::update(void) {
	//if(!current_wave.isFinished()) {
	//	if(start_field.isEmpty())
	//	this.setOnField(current_wave.spawn());
	//}
	//else {
	//	if(enemies.isEmpty()) //lvl geschafft
	//}
	//if(!enemies.isEmpty()) {
	//	for(auto i = enemies.begin(); i != enemies.end(); i++) {
	//		this.move_enemy(i);
	//	}
	//}

	//if(!shots.isEmpty()) {
	//	for(auto i = shots.begin(); i != shots.end(); i++) {
	//		this.move_shot(i);
	//	}
	//}
	for(auto it = enemies.begin(); it != enemies.end(); it++) {
		this->move_enemy(*it);
	}
}

void gamelogic::set_on_field(enemy enemy) {
	//gegner aufs feld setzten
	//gegner position = startposition
	//enemy in liste
	auto startPos = lvl.getStartTileCoords();
	enemy.setPosition(startPos, false);
	//enemy.setShapePos(convertToPixelCoords(startPos.x, startPos.y));
	tile startTile = lvl.getTileAt(startPos);
	startTile.setOccupied(true);
	lvl.setTileAt(startPos, startTile);
	enemies.push_back(enemy);
}

void gamelogic::move_enemy(enemy& enemy) {
	//int x = enemy.getPosition().x;
	//int y = enemy.getPosition().y;
	//sf::CircleShape* cs = new sf::CircleShape(23.f);
	//if(enemy.getPosition() == lvl.getEndTileCoords()) {
	//	// TOOD == operator for enemy
	//	//enemies.remove(enemy);
	//	return;
	//}
	//vector<sf::Vector2i> neighbors;
	//neighbors.push_back(sf::Vector2i(x-1, y));
	//neighbors.push_back(sf::Vector2i(x+1, y));
	//neighbors.push_back(sf::Vector2i(x, y-1));
	//neighbors.push_back(sf::Vector2i(x, y+1));
	//// Go over all the tiles in the 4-neighborhood
	//// Check if they've been visited before and if they are passable
	//// Move the enemy to the appropirate tile
	//for(int i = x-1; i <= x+1; i++) {
	//	for(int j = y-1; j <= y+1; j++) {
	//		if(i >= 0 && j >= 0 && i < CELLX && j < CELLY) {
	//			tile cur = lvl.getTileAt(i, j);
	//			sf::Vector2i pos (i, j);
	//			if(cur.isPassable() && pos != enemy.getLastPosition()) {
	//				// ugly..
	//				// If the current position is not in the 4-neighborhood, continue
	//				if(find(neighbors.begin(), neighbors.end(), pos) == neighbors.end())
	//					continue;
	//				enemy.setPosition(pos, true);
	//				enemy.setShapePos(convertToPixelCoords(pos.x, pos.y));
	//				//animation anim (sf::Vector2f(x, y), sf::Vector2f(i, j), *cs, 1.0f);
	//				//anim.animate();
	//				auto lastPos = enemy.getLastPosition();
	//				if(lastPos.x != -1) {
	//					tile prev = lvl.getTileAt(lastPos);
	//					prev.setOccupied(false);
	//					lvl.setTileAt(lastPos, prev);
	//				}
	//				cur.setOccupied(true);
	//				lvl.setTileAt(pos, cur);
	//			}
	//		}
	//	}
	//}
	

	auto currentPos = lvl.getEnemyPath().getPoint(enemy.getSpot());
	if(currentPos != lvl.getEndTileCoords()) {
		enemy.incrSpot();
		enemy.setPosition(lvl.getEnemyPath().getPoint(enemy.getSpot()), true);
	}
}

void gamelogic::move_shot(const shot& shot) {
	//shot weiterbewegen richtung enemy oder richtung sein ziel
	//ziel davor ausrechnen, damit shot nicht bloed fliegt (gerade statt komische parabel oda so xD)

	//if shot.pos == target _-> target changeColor!!
	//shot aus liste entfernen

}

void gamelogic::loadLevel(int n) {
	std::stringstream levelFilePath;
	levelFilePath << BASE_PATH << n << LEVELFILE_SUFFIX;

	std::stringstream tilesPath;
	tilesPath << BASE_PATH << n << TILES_SUFFIX;
	this->lvl = level(levelFilePath.str(),  tilesPath.str()); 
}

level& gamelogic::getLevel() {
	return lvl;
}

list<enemy>& gamelogic::getEnemies(void) {
	return enemies;
}