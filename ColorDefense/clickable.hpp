#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
namespace game {
class clickable
{
public:
	clickable();
	~clickable(void);
	bool clicked(sf::Vector2f click_pos);
	vector<sf::Drawable*> get_graphics(void);
protected:
	vector<sf::Drawable*> graphics;
	sf::Vector2f left_top;
	sf::Vector2f right_bot;
};

}