#include <list>
#include "enemy.hpp"
#include "util.hpp"
#pragma once

namespace game {
class wave: public std::list<enemy> {
public:
	//wave_string: representing enemies, format: #xxxxxx#yyyyyy#... where x and y are numbers between 0 and f (#enemy#enemy#e...) (no # at end)
	wave(string wave_string, sf::Vector2i startPos);

	wave(void);

	enemy spawn(void);
	void ready(void);
	void setFinished(bool finished);
	bool isFinished(void);

private:
	sf::Vector2i startPos;
	list<enemy>::iterator it;
	bool finished;
};
}