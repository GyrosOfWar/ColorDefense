#pragma once
#include "tile.hpp"
#include <list>
#include "wave.hpp"
#include "tile_map.hpp"
namespace game {
class level
{
public:
	level(string levelFilePath, string tilesPath);
	~level(void);
	wave getNextWave(void);
	vector<tile> getMap(void);
	int getLvlno(void);
	bool isFinished(void);
private:
	//tile** map;
	vector<tile> map;
	list<wave> waves;
	int lvlno;
	list<wave>::iterator it;
	bool finished;
	//tile_map level_tile_map;
	
	bool loadFromFile(const std::string& path);
	bool fillTileMap(const std::string& path);
};

}
