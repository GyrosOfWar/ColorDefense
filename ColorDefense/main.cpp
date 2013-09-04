#include "stdafx.h"
#include "Logger.hpp"
#include "enemy.hpp"
#include "wave.hpp"
#include "gamelogic.hpp"
#include "util.hpp"
#include "tower.hpp"
#include "animation.hpp"
#include "button.hpp"

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
bool game_is_running;
vector<clickable> clickables;

// Handles keyboard and mouse inputs
void handleEvents(sf::Window& window, game::gamelogic& gl) {
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
			case sf::Keyboard::B: 
				gl.add_tower(tower(0)); break;
			case sf::Keyboard::W: 
				gl.add_tower(tower(0xffffff)); break;
			case sf::Keyboard::G: 
				gl.add_tower(tower(0xff00)); break;
			default: break;
			}
			break;
		case sf::Event::MouseButtonReleased:
			{
				sf::Vector2i m_pos_i = sf::Mouse::getPosition(window);
				sf::Vector2f m_pos = sf::Vector2f(m_pos_i);

				for(auto it = clickables.begin(); it != clickables.end(); ++it) {
					if(it->clicked(m_pos)) game_is_running = true;
				}
				if(gl.showDialog() && m_pos.x > 225 && m_pos.x < 375 && m_pos.y > 300 && m_pos.y < 375) {
					if(gl.is_finished()) window.close();
					else gl.next_lvl();
				}
				if(gl.is_adding_tower()) {
					gl.set_tower(m_pos_i);
				}
				break;
			}
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
			if(gl.getLevel().getTileAt(i, j)->isOccupied()) {
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

void drawTowers(gamelogic& gl, sf::RenderWindow& window) {
	auto towers = gl.getTowers();
	for(auto it = towers.begin(); it != towers.end(); ++it) {
		if(it->is_set()) window.draw(it->getShape());
	}
}

void drawEverything(gamelogic& gl, sf::RenderWindow& window) {
	window.clear(sf::Color::White);
	window.draw(gl.getLevel().getTileMap());
	drawEnemies(gl, window);
	drawTowers(gl,window);
	if(gl.showDialog()) {
		vector<sf::Drawable*> dialogue = gl.createDialogue();
		for(vector<sf::Drawable*>::iterator it = dialogue.begin(); it < dialogue.end(); ++it) { 
			window.draw(**it); 
		}
	}
	if(debugDraw) drawCells(window, gl);

}
void draw_menu(sf::RenderWindow& window) {
	window.clear(sf::Color::White);
	button start_game = button("start game", sf::Vector2f(1,1), sf::Vector2f(100,100));
	button end = button("end", sf::Vector2f(200,200), sf::Vector2f(300,300));
	clickables.push_back(start_game);
	clickables.push_back(end);
	vector<sf::Drawable*> buttons = start_game.get_graphics();
	for(vector<sf::Drawable*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
		window.draw(**it);
	}
	buttons = end.get_graphics();
	for(vector<sf::Drawable*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
		window.draw(**it);
	}
}

int main() {
	game_is_running = false;
	sf::RenderWindow window(
		sf::VideoMode(SCREENWIDTH, SCREENHEIGHT),
		"ColorDefense",
		sf::Style::Default,
		sf::ContextSettings(24, 8, 4)); // depth buffer size, stencil buffer size, number of AA samples
	window.setFramerateLimit(60);

	gamelogic gl;

	while(window.isOpen()) {
		if(game_is_running) {
			updateGameState(gl);
			handleEvents(window, gl);
			drawEverything(gl, window);
		}
		else {
			handleEvents(window, gl);
			draw_menu(window);
		}

		window.display();
	}
	return 0;
}