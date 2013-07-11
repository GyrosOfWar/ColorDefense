#pragma once
#include <SFML/Graphics.hpp>
class tile
{
public:
	bool isPassable(void);
	bool isBuildable(void);
	sf::Texture* getTexture(void);
	void setTexture(sf::Texture* texture);
	sf::Sprite* getSprite(void);
	void setSprite(sf::Sprite* sprite);
protected:
	static bool passable;
	static bool buildable;
	sf::Texture texture; 
	sf::Sprite sprite;
};

