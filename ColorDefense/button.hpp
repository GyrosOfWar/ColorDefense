#pragma once
#include "clickable.hpp"
using namespace std;
namespace game {
class button :
	public clickable
{
public:
	button(string text, sf::Vector2f left_top, sf::Vector2f right_bot);
	~button(void);

private:
	sf::Text g_text;
	sf::Font font;
	sf::RectangleShape shape;
	string text;


};
}

