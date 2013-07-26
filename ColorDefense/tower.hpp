#pragma once
#include <SFML/Graphics.hpp>
#include "util.hpp"
namespace game {
class tower {
public:
	tower(int color);
	~tower(void);
	int getShootingRate(void) const;
	void setShootingRate(int rate);
	
	// sets the position in tile coordinates ([0 .. CELLX-1], [0, CELLY-1])
	sf::Vector2i getPosition(void) const;
	// sets the position in tile coordinates ([0 .. CELLX-1], [0, CELLY-1])
	void setPosition(sf::Vector2i vec);
	// returns position in tile coordinates ([0 .. CELLX-1], [0, CELLY-1])
	void setPosition(int x, int y);

	int getColor(void) const;
	void setColor(int color);

	sf::Sprite getSprite(void) const;
	void setSprite(sf::Sprite s);

	sf::RectangleShape getShape(void);
	void updateColor(void);
	bool is_set(void);
	void set_set(bool set);
private:
	int shooting_rate;
	sf::Vector2i position;
	int color;

	bool set;

	sf::Color color_real;

	sf::RectangleShape shape;

	//grafik
	sf::Sprite sprite;
	// Sprite only stores a pointer to the texture,
	// so we need to keep the texture around.
	sf::Texture texture;
};
}