#pragma once
#include "tile.hpp"
#include "wave.hpp"
#include "tile_map.hpp"
#include "constants.hpp"
#include "Logger.hpp"
#include "buildable_tile.hpp"
#include "passable_tile.hpp"
#include "blocked_tile.hpp"
#include "path.hpp"
#include <list>
#include <map>

namespace game {
	// Forward declarations
	class gamelogic;
	// This file has to include path.hpp since we want to
	// make a path member variable, not just use it as a parameter
	// or something like that.
	//class path;

	const sf::Color BUILDABLE_TILE = sf::Color::Black;
	const sf::Color PASSABLE_TILE = sf::Color::White;
	const sf::Color START_TILE = sf::Color::Green;
	const sf::Color END_TILE = sf::Color::Red;
	const sf::Color BLOCKED_TILE = sf::Color::Blue;

	class level
	{
	public:
		level(string levelFilePath, string tilesPath, int lvl);
		// FIXME
		level(void);
		~level(void);
		wave getNextWave(void);
		const vector<tile>& getMap(void) const;
		int getLvlno(void);
		bool isFinished(void);
		const tile_map& getTileMap() const;
		// Returns tile at the given position, in tile coordinates
		const tile* getTileAt(sf::Vector2i vec) const;
		const tile* getTileAt(int x, int y) const;
		// Returns the coordinates of the start tile (in tile coordinates)
		sf::Vector2i getStartTileCoords() const;
		// Returns the coordinates of the end tile (in tile coordinates)
		sf::Vector2i getEndTileCoords() const;

		//creates the waves for this lvl
		void createWaves(int lvl);
		void setTileAt(int x, int y, tile value);
		void setTileAt(sf::Vector2i pos, tile value);

		path getEnemyPath(void);

	private:
		vector<tile> map;
		vector<wave> waves;
		int lvlno;
		//list<wave>::iterator it;
		bool finished;
		tile_map level_tile_map;
		unsigned int currentWaveNum;
		sf::Vector2i startTile;
		sf::Vector2i endTile;
		path enemyPath;

		bool loadFromFile(const std::string& path);
		bool fillTileMap(const std::string& path);
		void makePath();
	};
}
