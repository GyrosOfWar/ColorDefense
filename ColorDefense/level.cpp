#include "stdafx.h"
#include "level.hpp"

using namespace game;

level::level(string levelFilePath, string tilesPath, int lvl) {
	map = vector<tile>();
	waves = vector<wave>();
	//it = waves.begin();
	currentWaveNum = 0;
	finished = false;
	level_tile_map = tile_map();
	// FIXME
	lvlno = 0;
	if(!loadFromFile(levelFilePath))
		throw "Failed to open level file.";
	if(!fillTileMap(tilesPath))
		throw "Failed to open tile file.";
	makePath();
	this->createWaves(lvl);
}

level::level(void) {
}

level::~level(void) { }
// Error: Incompatible iterators (?)
wave level::getNextWave(void) {
	//if(it != waves.end()) {
	//	return *it++;
	//}
	//else  {
	//	finished = true;
	//	return *it++;
	//}

	// FIXME
	if(finished) {//unneccesary
		return wave();
	}
	if(currentWaveNum < waves.size()) {
		return waves[currentWaveNum++];
	}
	else { //unneccesary
		finished = true;
		return wave();
	}
}

const vector<tile>& level::getMap(void) const {
	return map;
}

int level::getLvlno(void) {
	return lvlno;
}

bool level::isFinished(void) {
	return finished;
}

// Loads a level from an image located at path.
// Tiles are in column-major order
// Returns true on success, false otherwise.
bool level::loadFromFile(const std::string& path) {
	sf::Image levelImg;
	if(!levelImg.loadFromFile(path))
		return false;
	
	unsigned int N = levelImg.getSize().x;
	unsigned int M = levelImg.getSize().y;
	for(unsigned int i = 0; i < N; i++) {
		for(unsigned int j = 0; j < M; j++) {
			sf::Color c = levelImg.getPixel(i, j);
			if(c == BUILDABLE_TILE) {
				map.push_back(buildable_tile());
			}
			if(c == PASSABLE_TILE) {
				map.push_back(passable_tile());
			}
			if(c == START_TILE) {
				startTile = sf::Vector2i(i, j);
				map.push_back(passable_tile());
			}
			if(c == END_TILE) {
				endTile = sf::Vector2i(i, j);
				map.push_back(passable_tile());
			}
		}
	}
	return true;
}

bool level::fillTileMap(const string& path) {
	return level_tile_map.load(path, sf::Vector2u(TILEWIDTH, TILEHEIGHT), map, CELLX, CELLY);
}

const tile_map& level::getTileMap() const { 
	return level_tile_map;
}

const tile* level::getTileAt(sf::Vector2i vec) const {
	return getTileAt(vec.x, vec.y);
}

const tile* level::getTileAt(int i, int j) const {	 
	return &map[i * CELLY + j];
}

void level::setTileAt(int i, int j, tile value) {
	map[i * CELLY + j] = value;
}

void level::setTileAt(sf::Vector2i pos, tile value) {
	this->setTileAt(pos.x, pos.y, value);
}

sf::Vector2i level::getStartTileCoords() const {
	return startTile;
}

sf::Vector2i level::getEndTileCoords() const {
	return endTile;
}

void level::makePath(void) {
	auto start = this->getStartTileCoords();
	auto end = this->getEndTileCoords();
	auto pos = start;
	auto lastPos = sf::Vector2i(-1, -1);
	enemyPath.addPoint(start);

	bool foundEnd = false;
	while(!foundEnd) {
		auto x = pos.x;
		auto y = pos.y;

		vector<sf::Vector2i> neighbors;
		neighbors.push_back(sf::Vector2i(x-1, y));
		neighbors.push_back(sf::Vector2i(x+1, y));
		neighbors.push_back(sf::Vector2i(x, y-1));
		neighbors.push_back(sf::Vector2i(x, y+1));

		if(sf::Vector2i(x, y) == end) {
			foundEnd = true;
			break;
		}

		for(int i = x-1; i <= x+1; i++) {
			for(int j = y-1; j <= y+1; j++) {
				if(i >= 0 && j >= 0 && i < CELLX && j < CELLY) {
					tile currentTile = *this->getTileAt(i, j);
					sf::Vector2i currentPos (i, j);

					if(currentTile.isPassable() && currentPos != lastPos) {
						if(find(neighbors.begin(), neighbors.end(), currentPos) == neighbors.end())
							continue;
						enemyPath.addPoint(i, j);
						//currentTile.setOccupied(true);
						//this->setTileAt(i, j, currentTile);
						lastPos = pos;
						pos = currentPos;
						//if(lastPos.x != -1) {
						//	tile previousTile = this->getTileAt(lastPos.x, lastPos.y);
						//	previousTile.setOccupied(false);
						//	this->setTileAt(lastPos.x, lastPos.y, previousTile);
						//}
					}
				}
			}
		}
	}
	if(!foundEnd) throw "Could not find an end tile!";
}

path level::getEnemyPath(void) {
	return enemyPath;
}


void level::createWaves(int lvl) {
	stringstream wavespath;
	wavespath << BASE_PATH << lvl << LEVELWAVE_SUFFIX;

	ifstream in;    // Create an input file stream.
	in.open(wavespath.str());  // Use it to read from a file named data.txt.

	string str;


	cout << in.good();
	cout << "\n";
	cout << in.fail();
	cout << "\n";
	cout << in.bad();
	cout << "\n";
	cout << in.eof();
	cout << "\n";


	while(getline(in,str)) {
		waves.push_back(wave(str));  // Process the line.
	}



		in.close();
}

