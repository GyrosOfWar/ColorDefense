#pragma once
#include "stdafx.h"
#include "util.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

namespace game {
	class path {
	public:
		path(void);
		~path(void);

		vector<sf::Vector2i>::const_iterator cbegin() const;
		vector<sf::Vector2i>::const_iterator cend() const;
		void addPoint(int x, int y);
		void addPoint(float x, float y);
		void addPoint(sf::Vector2i v);

		void insertPoint(int x, int y, int position);
		void insertPoint(float x, float y, int position);
		void insertPoint(sf::Vector2i v, int position);

		sf::Vector2i getPoint(int index);

		sf::Vector2i getLast(void);
	private:
		vector<sf::Vector2i> points;
	};
}