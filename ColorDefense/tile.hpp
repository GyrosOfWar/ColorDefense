#pragma once
#include <SFML/Graphics.hpp>
namespace game {

class tile
{
public:
	bool isPassable(void);
	bool isBuildable(void);
	bool isOccupied(void);
	int getTileNumber(void) const;
	sf::Sprite getSprite(void);
	void setSprite(sf::Sprite sprite);
	void setOccupied(bool occ);
protected:
	bool passable;
	bool buildable;
	bool occupied;
	int tileNumber;
	sf::Sprite sprite;
	// TODO Store texture here to make sure the 
	// pointer to the texture is never lost.
	sf::Texture texture;
};

}
