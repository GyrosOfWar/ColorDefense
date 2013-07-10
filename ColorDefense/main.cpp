#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

const int xSize = 800;
const int ySize = 600;
const int numCellsX = 16;
const int numCellsY = 12;
const int cellSizeX = xSize / numCellsX;
const int cellSizeY = ySize / numCellsY;

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

int main() {
    sf::RenderWindow window(sf::VideoMode(xSize, ySize), "ColorDefense");
	window.setFramerateLimit(60);
	sf::Texture enemyTexture; 
	enemyTexture.loadFromFile("res/sprites/enemy1.png");
	sf::Sprite enemy;
	auto size = enemyTexture.getSize();
	float scaleFactorX = cellSizeX / (float) size.x;
	float scaleFactorY = cellSizeY / (float) size.y;
	enemy.setTexture(enemyTexture);
	enemy.setScale(scaleFactorX, scaleFactorY);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
			handleEvents(event, window);
        }

        window.clear(sf::Color::White);
		enemy.setPosition(circlePos);
		if(debugDraw)
			drawCells(window);
		window.draw(enemy);
        window.display();
    }

    return 0;
}