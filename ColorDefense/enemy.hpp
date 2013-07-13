#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "enemy.hpp"
#include <string>
#include "Logger.hpp"
#include <sstream>
#include <iomanip>  
#include <iostream>
namespace game {
class enemy
{
public:
	enemy(int color);
	~enemy(void);

	void updateTexture(void); //sets texture to the colorvalue
	
	//sf::Texture* getTexture(void); //returns texture
	//sf::Sprite* getSprite(void); //returns sprite
	void setColor(int color); //sets the color
	int getColor(void); //returns color
	int getX(void);
	int getY(void);
	void setX(int x);
	void setY(int y);

	sf::CircleShape* getShape(void);

private:
	int color;
	/*sf::Texture texture; 
	sf::Sprite sprite;*/
	int x_pos;
	int y_pos;
	sf::Color color_real;

	sf::CircleShape shape;
};

}
