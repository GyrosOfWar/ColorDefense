#pragma once
#include <SFML/Graphics.hpp>
namespace game {

class tile
{
public:
	bool isPassable(void);
	bool isBuildable(void);
	int getTileNumber(void) const;
	sf::Sprite getSprite(void);
	void setSprite(sf::Sprite sprite);
protected:
	bool passable;
	bool buildable;
	int tileNumber;
	sf::Texture texture; 
	sf::Sprite sprite;
};

}
