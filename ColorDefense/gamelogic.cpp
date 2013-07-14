#pragma once
#include "stdafx.h"
#include "gamelogic.hpp"
#include "util.hpp"

using namespace game;

gamelogic::gamelogic(void) {
	loadLevel(1);
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
	//		this.move_enemy(*i);
	//	}
	//}

	//if(!shots.isEmpty()) {
	//	for(auto i = shots.begin(); i != shots.end(); i++) {
	//		this.move_shot(*i);
	//	}
	//}

}

void gamelogic::set_on_field(enemy enemy) {
	//gegner aufs feld setzten
	//gegner position = startposition
	//enemy in liste
	//	enemy.setPosition(lvl.getStartPos());
	enemies.push_back(enemy);
}

void gamelogic::move_enemy(enemy& enemy) {
	//nächstes feld auswählen und bewegungschritt ausrechnen
	//gegner pos updaten, dann updateTexture callen (updateTexture noch umbenennen!)
	//enemy am zielfeld auswerten, aus liste entfernen

	// (1, 1) and (0, 1) have the same neighbors because of this.. fix
	auto x = enemy.getPosition().x;
	auto y = enemy.getPosition().y;
	vector<tile*> neighbors = getNeighbors(x, y);
	for(int i = 0; i < 8; i++) {
		auto p = sf::Vector2i(i / 3, i % 3);
		auto cur = neighbors[i];
		
		cout << p.x << " " << p.y << endl;
		if(cur != nullptr && cur->isPassable() && p != enemy.getLastPosition()) {
			//selectedPos = p;
			enemy.setPosition(p);
			enemy.updateTexture();
			return;
		}
	}
	cout << endl;
}

vector<tile*> gamelogic::getNeighbors(int x, int y) {
	vector<tile*> ret;
	int start_x = x-1;
	int start_y = y-1;
	int end_x = x+1;
	int end_y = y+1;
	for(int i = start_x; i <= end_x; i++) {
		for(int j = start_y; j <= end_y; j++) {
			if(i > 0 && j > 0 && i < (CELLX-1) && j < (CELLY-1))
				ret.push_back(&lvl.getTileAt(i, j));
			else
				ret.push_back(nullptr);
		}
	}

	return ret;
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
	lvl = level(levelFilePath.str(),  tilesPath.str()); 
}

level gamelogic::getLevel() {
	return lvl;
}