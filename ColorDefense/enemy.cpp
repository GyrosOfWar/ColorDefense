#include "stdafx.h"
#include "enemy.hpp"

using namespace std;
using namespace game;

enemy::enemy(int color) {
	this->color = color;
	updateTexture();
	shape = sf::CircleShape((50 / 2) - 2.0f);
	shape.setFillColor(color_real);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(2.0f);
	shape.setOrigin(-2.0f, -2.0f);
}

enemy::~enemy(void) { }

void enemy::updateTexture(void) {
	/*string path = "res/sprites/";
	string color;
	string end = ".png";

	stringstream ss;
	ss << setfill('0') << setw(6) << std::hex << this->color;


	/*color = ss.str();

	string final = path + color + end;

	this->texture.loadFromFile(final);
	
	sprite.setPosition(x_pos,y_pos);
	*/

	int r = this->color >> 16;
	int g = this->color >> 8;
	g %= 0x100;
	int b = this->color % 0x100;

	color_real = sf::Color(r,g,b);
	shape.setFillColor(color_real);
	
	shape.setPosition(x_pos,y_pos);
	
}

/*sf::Texture* enemy::getTexture(void) {
	return &texture;
}

sf::Sprite* enemy::getSprite(void) {
	return &sprite;
}*/

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

sf::CircleShape* enemy::getShape(void) {
	return &shape;
}
