#pragma once
#include "tile.hpp"
#include <list>
#include "wave.hpp"
#include "tile_map.hpp"
namespace game {
const sf::Color BUILDABLE_TILE = sf::Color::Black;
const sf::Color PASSABLE_TILE = sf::Color::White;
const sf::Color START_TILE = sf::Color::Green;
const sf::Color END_TILE = sf::Color::Red;

class level
{
public:
	level(string levelFilePath, string tilesPath);
	level(void);
	~level(void);
	wave getNextWave(void);
	vector<tile> getMap(void);
	int getLvlno(void);
	bool isFinished(void);
	tile_map getTileMap();
	tile getTileAt(int x, int y);
	sf::Vector2i getStartTileCoords();
	sf::Vector2i getEndTileCoords();
private:
	vector<tile> map;
	vector<wave> waves;
	int lvlno;
	//list<wave>::iterator it;
	bool finished;
	tile_map level_tile_map;
	int currentWaveNum;
	sf::Vector2i startTile;
	sf::Vector2i endTile;
	
	bool loadFromFile(const std::string& path);
	bool fillTileMap(const std::string& path);
};
}
