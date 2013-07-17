#include "stdafx.h"
#include "util.hpp"
#include "level.hpp"
#include "gamelogic.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

namespace game {
class path {
public:
	path(void);
	~path(void);

	vector<sf::Vector2i>::iterator begin();
	vector<sf::Vector2i>::iterator end();
	void makePath(level& level);
private:
	vector<sf::Vector2i> points;
	void addPoint(int x, int y);
	void addPoint(float x, float y);
	void addPoint(sf::Vector2i v);
};
}