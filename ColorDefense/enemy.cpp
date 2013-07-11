#include "stdafx.h"
#include "enemy.hpp"
#include <string>
#include "Logger.hpp"
#include <sstream>
#include <iomanip>  

using namespace std;
using namespace game;

enemy::enemy(int color)
{

	this->color = color;

	updateTexture();
	sprite.setTexture(texture);
}


enemy::~enemy(void)
{
}

void enemy::updateTexture(void) {
	string path = "res/sprites/";
	string color;
	string end = ".png";

	stringstream ss;
	ss << setfill('0') << setw(6) << std::hex << this->color;


	color = ss.str();

	string final = path + color + end;

	this->texture.loadFromFile(final);
	
}

sf::Texture* enemy::getTexture(void) {
	return &texture;
}

sf::Sprite* enemy::getSprite(void) {
	return &sprite;
}

void enemy::setColor(int color){
	this->color = color;
}

int enemy::getColor(void) {
	return color;
}

int enemy::getX(void) {
	return this->x_pos;
}

int enemy::getY(void) {
	return this->y_pos;
}

void enemy::setX(int x) {
	this->x_pos = x;
}

void enemy::setY(int y) {
	this->y_pos = y;
}