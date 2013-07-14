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
	auto x = clamp(enemy.getPosition().x, 1, CELLX-1);
	auto y = clamp(enemy.getPosition().y, 1, CELLY-1);
	tile neighbors[8];
	neighbors[0] = lvl.getTileAt(x-1, y-1);
	neighbors[1] = lvl.getTileAt(x-1, y);
	neighbors[2] = lvl.getTileAt(x-1, y+1);
	neighbors[3] = lvl.getTileAt(x, y-1);
	neighbors[4] = lvl.getTileAt(x, y+1);
	neighbors[5] = lvl.getTileAt(x+1, y-1);
	neighbors[6] = lvl.getTileAt(x+1, y);
	neighbors[7] = lvl.getTileAt(x+1, y+1);
	sf::Vector2i selectedPos(-1.0f, -1.0f);
	for(int i = 0; i < 8; i++) {
		auto p = sf::Vector2i(i / 3, i % 3);
		cout << p.x << " " << p.y << endl;
		if(neighbors[i].isPassable() && p != enemy.getLastPosition()) {
			cout << "Picked: " << p.x << " " << p.y << endl << endl;
			//selectedPos = p;
			enemy.setPosition(selectedPos);
			enemy.updateTexture();
			return;
		}
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
	lvl = level(levelFilePath.str(),  tilesPath.str()); 
}

level gamelogic::getLevel() {
	return lvl;
}