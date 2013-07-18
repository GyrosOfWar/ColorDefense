#pragma once
#include "stdafx.h"
#include "util.hpp"
//#include "level.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

namespace game {
	//class level;

	class path {
	public:
		path(void);
		~path(void);

		vector<sf::Vector2i>::iterator begin();
		vector<sf::Vector2i>::iterator end();
		void addPoint(int x, int y);
		void addPoint(float x, float y);
		void addPoint(sf::Vector2i v);
	private:
		vector<sf::Vector2i> points;
	};
}