#pragma once
#include <SFML/Graphics.hpp>
class enemy
{
public:
	enemy(int color);
	~enemy(void);

	void updateTexture(void); //sets texture to the colorvalue
	
	sf::Texture* getTexture(void); //returns texture
	sf::Sprite* getSprite(void); //returns sprite
	void setColor(int color); //sets the color
	int getColor(void); //returns color

private:
	int color;
	sf::Texture texture; 
	sf::Sprite sprite;
};

