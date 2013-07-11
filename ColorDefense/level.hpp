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
	tile** getMap(void);
	int getLvlno(void);
	bool isFinished(void);
	bool loadFromFile(const std::string& path);
private:
	tile** map;
	std::list<wave*> waves;
	int lvlno;
	std::list<wave*>::iterator it;
	bool finished;
};

}
