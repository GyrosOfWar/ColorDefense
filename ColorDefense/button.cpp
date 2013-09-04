#include "stdafx.h"
#include "button.hpp"

using namespace game;

button::button(string text, sf::Vector2f left_top, sf::Vector2f right_bot)
{
	this->left_top = left_top;
	this->right_bot = right_bot;
	this->shape = sf::RectangleShape(sf::Vector2f(right_bot.x-left_top.x,right_bot.y-left_top.y));
	this->font.loadFromFile("arial.ttf");

	this->g_text = sf::Text(text, font, 20U);
	this->g_text.setColor(sf::Color(0,0,0,255));
	this->g_text.setPosition(sf::Vector2f(this->left_top.x + 15,this->left_top.y + 15));
	this->graphics.push_back(&shape);
	this->graphics.push_back(&g_text);
}


button::~button(void)
{
}
