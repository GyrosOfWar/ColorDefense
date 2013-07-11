#pragma once
#include <SFML/Graphics.hpp>
namespace game {

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
	bool passable;
	bool buildable;
	sf::Texture texture; 
	sf::Sprite sprite;
};

}