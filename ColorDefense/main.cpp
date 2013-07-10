#include "stdafx.h"
#include "Logger.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

const int xSize = 800;
const int ySize = 600;
// Don't change, at least for now (level files have 16x12 cells currently)
const int numCellsX = 16;
const int numCellsY = 12;
// Requires that xSize % numCellsX == 0, or else there's a gap to the side
const int cellSizeX = xSize / numCellsX;
const int cellSizeY = ySize / numCellsY;
Logger* logger = Logger::get();

bool debugDraw = true;
sf::Vector2f circlePos(0, 0);

// Clamps the value x to the interval [a, b] (if x < a: x = a, if x > b: b, else a)
inline float clamp(float x, float a, float b) {
	return x < a ? a : (x > b ? b : x);
}

// Handles keyboard and mouse inputs
void handleEvents(sf::Event& e, sf::Window& window) {
	switch (e.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch(e.key.code) {
				case sf::Keyboard::Up:
					circlePos.y -= cellSizeY; 
					circlePos.y = clamp(circlePos.y, 0, ySize-cellSizeY);
					break;
				case sf::Keyboard::Down:
					circlePos.y += cellSizeY;
					circlePos.y = clamp(circlePos.y, 0, ySize-cellSizeY);
					break;
				case sf::Keyboard::Left:
					circlePos.x -= cellSizeX; 
					circlePos.x = clamp(circlePos.x, 0, xSize-cellSizeX);
					break;
				case sf::Keyboard::Right:
					circlePos.x += cellSizeX;
					circlePos.x = clamp(circlePos.x, 0, xSize-cellSizeX);
					break;
				case sf::Keyboard::Space:
					debugDraw = !debugDraw; break;
				}
			break;
		default:
			break;
		}
}

// Draws cell boundaries as small rectangles for debugging purposes
void drawCells(sf::RenderWindow& window) {
	for(int i = 0; i < xSize; i += cellSizeX) {
		for(int j = 0; j < ySize; j  += cellSizeY) {
			sf::RectangleShape rect(sf::Vector2f(5, 5));
			rect.setFillColor(sf::Color::Black);
			rect.move(i, j);
			window.draw(rect);
		}
	}
}

inline sf::Vector2i convertToCellCoords(float x, float y) {
	return sf::Vector2i((int) x / cellSizeX, (int) y / cellSizeY);
}

inline sf::Vector2f convertToPixelCoords(int x, int y) {
	return sf::Vector2f(x * cellSizeX, y * cellSizeY);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(xSize, ySize), "ColorDefense", sf::Style::Default, sf::ContextSettings(24, 8, 4));
	window.setFramerateLimit(60);

	sf::Texture tower1Texture; 
	tower1Texture.loadFromFile("res/sprites/tower1.png");
	sf::Sprite tower;
	tower.setTexture(tower1Texture);
	tower.setPosition(convertToPixelCoords(15, 11));
	
	sf::CircleShape enemy = sf::CircleShape((cellSizeX / 2) - 2.0f);
	enemy.setFillColor(sf::Color::Blue);
	enemy.setOutlineColor(sf::Color::Black);
	enemy.setOutlineThickness(2.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
			handleEvents(event, window);
        }

        window.clear(sf::Color::White);
		enemy.setPosition(circlePos + sf::Vector2f(2.0f, 2.0f));
		if(debugDraw)
			drawCells(window);
		window.draw(enemy);
		window.draw(tower);
        window.display();
    }

    return 0;
}