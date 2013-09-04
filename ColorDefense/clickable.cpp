#include "stdafx.h"
#include "clickable.hpp"

using namespace game;

clickable::clickable()
{
}


clickable::~clickable(void)
{
}

bool clickable::clicked(sf::Vector2f click_pos) {
	return this->left_top.y < click_pos.y  && this->left_top.x < click_pos.x && this->right_bot.y > click_pos.y && this->right_bot.x > click_pos.x;
}

vector<sf::Drawable*> clickable::get_graphics() {
	return graphics;
}