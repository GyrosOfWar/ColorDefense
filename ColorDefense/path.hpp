#include "stdafx.h"
#include "util.hpp"
#include "level.hpp"
#include "gamelogic.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class path {
public:
	path(void);
	~path(void);

	vector<sf::Vector2f>::iterator begin();
	vector<sf::Vector2f>::iterator end();
	void makePath(const level& level);
private:
	vector<sf::Vector2f> points;
	void addPoint(int x, int y);
	void addPoint(float x, float y);
	void addPoint(sf::Vector2i v);
};