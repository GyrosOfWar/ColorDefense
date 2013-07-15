#include "stdafx.h"
#include "Logger.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "enemy.hpp"
#include "Logger.hpp"
#include <sstream>
#include <string>
#include "wave.hpp"
#include "gamelogic.hpp"
#include "util.hpp"
#include "tower.hpp"

using namespace game;
using namespace chrono;

Logger* logger = Logger::get();
bool debugDraw = false;
system_clock::time_point lastTime;
const milliseconds frameTime;

// Handles keyboard and mouse inputs
void handleEvents(sf::Event& e, sf::Window& window) {
	switch (e.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch(e.key.code) {
				case sf::Keyboard::Space:
					debugDraw = !debugDraw; break;
				default: break;
				}
			break;
		default:
			break;
		}
}

// Draws cell boundaries as small rectangles for debugging purposes
void drawCells(sf::RenderWindow& window, gamelogic& gl) {
	for(int i = 0; i < SCREENWIDTH; i += TILEWIDTH) {
		for(int j = 0; j < SCREENHEIGHT; j  += TILEHEIGHT) {
			sf::RectangleShape rect(sf::Vector2f(5, 5));
			rect.setFillColor(sf::Color::Black);
			// auto p = convertToCellCoords(i, j);
			// if(gl.getLevel()->getTileAt(p.x, p.y).isOccupied()) {
			// 	rect.setFillColor(sf::Color::Green);
			// }
			rect.move(i, j);
			window.draw(rect);
		}
	}
}


void updateGameState(gamelogic& gl) {
	auto now = chrono::system_clock::now();
	//if(difftime(lastTime, now) < 1000.0 / FPS) {
	//	gl.update();
	//}
	//return now;
	auto diff = now - lastTime;
}

int main() {
	sf::RenderWindow window(
		sf::VideoMode(SCREENWIDTH, SCREENHEIGHT),
		"ColorDefense",
		sf::Style::Default,
		sf::ContextSettings(24, 8, 4)); // depth buffer size, stencil buffer size, number of AA samples
	window.setFramerateLimit(60);

	gamelogic gl;
	enemy test(0x00ff00);
	tower t;
	sf::Sprite towerSprite;
	sf::Texture towerTexture;
	towerTexture.loadFromFile("res/sprites/tower1.png");
	towerSprite.setTexture(towerTexture);
	t.setSprite(towerSprite);
	t.setPosition(2, 0);
	gl.set_on_field(test);
	test.setPosition(1, 0, false);
	int i = 0;
	while(window.isOpen()) {
		sf::Event e;
		while(window.pollEvent(e)) {
			handleEvents(e, window);
		}
		window.clear(sf::Color::White);
		window.draw(gl->getLevel().getTileMap());
		window.draw(test.getShape());
		if(debugDraw) {
			drawCells(window, gl);
		}
		window.draw(t.getSprite());
		window.display();
		i++;
	}

	return 0;
}