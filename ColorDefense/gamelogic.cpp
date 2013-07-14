#include "stdafx.h"
#include "gamelogic.hpp"

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
	//if(!current_wave->isFinished()) {
	//	if(start_field->isEmpty())
	//	this->setOnField(current_wave->spawn());
	//}
	//else {
	//	if(enemies.isEmpty()) //lvl geschafft
	//}
	//if(!enemies.isEmpty()) {
	//	for(auto i = enemies.begin(); i != enemies.end(); i++) {
	//		this->move_enemy(*i);
	//	}
	//}

	//if(!shots.isEmpty()) {
	//	for(auto i = shots.begin(); i != shots.end(); i++) {
	//		this->move_shot(*i);
	//	}
	//}

}

void gamelogic::set_on_field(enemy& enemy) {
	//gegner aufs feld setzten
	//gegner position = startposition
	//enemy in liste

}

void gamelogic::move_enemy(enemy& enemy) {
	//nächstes feld auswählen und bewegungschritt ausrechnen
	//gegner pos updaten, dann updateTexture callen (updateTexture noch umbenennen!)
	//enemy am zielfeld auswerten, aus liste entfernen
    //auto x = enemy.position.x;
    //auto y = enemy.position.y;
    //tile neighbors[8] = tile[] { field(x-1, y-1), field(x-1, y), field(x-1, y+1) } // etc.
    //tile selected;
    //for(int i = 0; i < 8; i++) {
    //   if(neighbors[i].isPassable() && neighbors[i] != enemy.getLastPosition()) {
    //       selected = neighbors[i];
    //   }
    //}

}

void gamelogic::move_shot(shot& shot) {
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