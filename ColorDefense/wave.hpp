#include <list>
#include "enemy.hpp"
#pragma once
namespace game {
class wave : public std::list<enemy>
{
public:
	wave(void);
	enemy spawn(void);
	void ready(void);
	void setFinished(bool finished);
	bool isFinished(void);

private:
	list<enemy>::iterator it;
	bool finished;
};

}