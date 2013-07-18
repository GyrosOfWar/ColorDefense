#include "stdafx.h"
#include "Logger.hpp"
#include "enemy.hpp"
#include "wave.hpp"
#include "gamelogic.hpp"
#include "util.hpp"
#include "tower.hpp"
#include "animation.hpp"

#include <sstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace game;
using namespace chrono;

Logger* logger = Logger::get();
bool debugDraw = false;
system_clock::time_point lastTime;
const milliseconds frameTime(1000/FPS);

// Handles keyboard and mouse inputs
void handleEvents(sf::Window& window) {
	float x, y;
	sf::Event e;
	while(window.pollEvent(e)) {
		switch (e.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized: 
			x = e.size.width;
			y = e.size.height;
			if(x / y != ASPECT_RATIO) {
				// resize window to the closest fitting size that is in the appropriate aspect ratio
				window.setSize(sf::Vector2u(static_cast<float>(x), static_cast<float>(x / ASPECT_RATIO)));
			}
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
}

// Draws cell boundaries as small rectangles for debugging purposes
void drawCells(sf::RenderWindow& window, gamelogic& gl) {
	for(int i = 0; i < CELLX; i++) {
		for(int j = 0; j < CELLY; j++) {
			sf::RectangleShape rect(sf::Vector2f(5, 5));
			auto pixelPos = convertToPixelCoords(i, j);
			rect.move(pixelPos);
			if(gl.getLevel().getTileAt(i, j).isOccupied()) {
				rect.setFillColor(sf::Color::Green);
			} else {
				rect.setFillColor(sf::Color::Black);
			}
			window.draw(rect);
		}
	}
}

void updateGameState(gamelogic& gl) {
	auto now = system_clock::now();
	auto diff = now - lastTime;
	if(diff > frameTime) {
		gl.update();
		lastTime = system_clock::now();
	}
}

void drawEnemies(gamelogic& gl, sf::RenderWindow& window) {
	auto enemies = gl.getEnemies();
	for(auto it = enemies.begin(); it != enemies.end(); ++it) {
		enemy cur = *it;
		window.draw(cur.getShape());
	}
}

void drawEverything(gamelogic& gl, sf::RenderWindow& window) {
	window.clear(sf::Color::White);
	window.draw(gl.getLevel().getTileMap());
	drawEnemies(gl, window);
	if(debugDraw) drawCells(window, gl);
	window.display();
}

//void testPath(gamelogic& gl) {
//	path p;
//	p.makePath(gl.getLevel());
//	for(vector<sf::Vector2i>::iterator it = p.begin(); it != p.end(); it++) {
//		cout << it->x << " " << it->y << endl;
//	}
//}

int main() {
	sf::RenderWindow window(
		sf::VideoMode(SCREENWIDTH, SCREENHEIGHT),
		"ColorDefense",
		sf::Style::Default,
		sf::ContextSettings(24, 8, 4)); // depth buffer size, stencil buffer size, number of AA samples
	window.setFramerateLimit(60);

	gamelogic gl;
	enemy test(0xff00ff, 100);
	tower t;
	sf::Sprite towerSprite;
	sf::Texture towerTexture;
	towerTexture.loadFromFile("res/sprites/tower1.png");
	towerSprite.setTexture(towerTexture);
	t.setSprite(towerSprite);
	t.setPosition(2, 0);
	gl.set_on_field(test);

	/*testPath(gl);*/

	//sf::CircleShape* circle = new sf::CircleShape(23.0f);
	//circle->setFillColor(sf::Color::Black);
	//animation animation(sf::Vector2f(15.f, 15.f), sf::Vector2f(15.f, 150.f), *circle, 1.0f);

	while(window.isOpen()) {
		updateGameState(gl);
		handleEvents(window);
		drawEverything(gl, window);
	}
	//delete circle;
	return 0;
}