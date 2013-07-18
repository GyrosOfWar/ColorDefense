#pragma once
#include "stdafx.h"
#include "tile.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace game;

namespace game {
class tile_map: public sf::Drawable, public sf::Transformable {
public:
	tile_map();
	~tile_map();
	bool load(const std::string& tileset, sf::Vector2u tileSize, const std::vector<tile>& tiles, unsigned int width, unsigned int height);
	
private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
}