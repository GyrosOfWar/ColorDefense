#include "stdafx.h"
#include <SFML/Graphics.hpp>


class tile_map: public sf::Drawable, public sf::Transformable {
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	
private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};