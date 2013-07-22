#pragma once
#include "stdafx.h"
#include "Logger.hpp"
#include "animation.hpp"

#include <sstream>
#include <iomanip>  
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

namespace game {

	class enemy {
	public:
		enemy(int color, int maxHealth);
		~enemy(void);

		void updateColor(void); //sets shape color to the colorvalue
		void setColor(int color); //sets the color
		int getColor(void) const; //returns color
		sf::Vector2i getPosition(void) const;
		void setPosition(sf::Vector2i vec);
		void setPosition(int x, int y);
		sf::CircleShape getShape(void);
		int getHealth(void);
		void setHealth(int h);
		int getSpot(void) const;
		void incrSpot(void);
		bool operator==(const enemy& that);
		void moveTo(sf::Vector2i vec, bool animate);
		void moveTo(int x, int y, bool animate);
		bool animFinished(void);
	private:
		int color;
		int health;
		int maxHealth;
		sf::Vector2i position;
		sf::Color color_real;
		//sf::CircleShape shape;
		//sf::Vector2i lastPosition;
		int spot;
		animation anim;
	};

}
