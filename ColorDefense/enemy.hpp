#pragma once
#include "stdafx.h"
#include "Logger.hpp"
#include "animation.hpp"
#include "util.hpp"
#include "path.hpp"

#include <sstream>
#include <iomanip>  
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

namespace game {

	class enemy {
	public:
		enemy(int color, sf::Vector2i startPos);
		~enemy(void);

		void updateColor(void); //sets shape color to the colorvalue
		void setColor(int color); //sets the color
		int getColor(void) const; //returns color
		sf::Vector2i getTilePosition(void) const;
		sf::Vector2f getPixelPosition(void) const;
		sf::CircleShape getShape(void);
		int getSpot(void) const;
		void incrSpot(void);
		bool operator==(const enemy& that);
		void moveTo(sf::Vector2i vec, bool animate);
		void moveTo(int x, int y, bool animate);
		bool animFinished(void) const;
		bool isAnimating(void) const;
		sf::Vector2f getPositionAt(int ticks, const path& path) const;

	private:
		int color;
		sf::Vector2i position;
		sf::Color color_real;
		sf::CircleShape shape;
		int spot;
		bool _isAnimating;
		animation anim;
	};

}
