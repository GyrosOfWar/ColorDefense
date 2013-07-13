#pragma once
#include "tile.hpp"
#include <list>
#include "wave.hpp"
namespace game {
class level
{
public:
	level(void);
	~level(void);
	wave* getNextWave(void);
	vector<tile> getMap(void);
	int getLvlno(void);
	bool isFinished(void);
	bool loadFromFile(const std::string& path);
private:
	//tile** map;
	vector<tile> map;
	list<wave*> waves;
	int lvlno;
	list<wave*>::iterator it;
	bool finished;
};

}
