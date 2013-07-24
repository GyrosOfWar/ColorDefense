#pragma once
#include "stdafx.h"
#include "path.hpp"

using namespace game;

path::path(void) { 
	points = vector<sf::Vector2i>();
}

path::~path(void) {
}

vector<sf::Vector2i>::iterator path::begin() {
	 return points.begin();
}

vector<sf::Vector2i>::iterator path::end() {
	return points.end();
}

void path::addPoint(sf::Vector2i v) {
	points.push_back(v);
}

void path::addPoint(int x, int y) {
	points.push_back(sf::Vector2i(x, y));
}

void path::addPoint(float x, float y) {
	points.push_back(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)));
}

sf::Vector2i path::getPoint(int index) {
	return points[index];
}

void path::insertPoint(int x, int y, int position) {
	this->insertPoint(sf::Vector2i(x, y), position);
}

void path::insertPoint(float x, float y, int position) {
	this->insertPoint(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)), position);
}

void path::insertPoint(sf::Vector2i v, int position) {
	points.insert(points.begin() + position, v); 
}