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

using namespace game;

bool drawCircle = true;
Logger* logger = Logger::get();
bool debugDraw = true;
sf::Vector2f circlePos(0, 0);

// Handles keyboard and mouse inputs
void handleEvents(sf::Event& e, sf::Window& window) {
	switch (e.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch(e.key.code) {
				case sf::Keyboard::Up:
					circlePos.y -= TILEHEIGHT; 
					circlePos.y = clamp(circlePos.y, 0, SCREENHEIGHT-TILEHEIGHT);
					break;
				case sf::Keyboard::Down:
					circlePos.y += TILEHEIGHT;
					circlePos.y = clamp(circlePos.y, 0, SCREENHEIGHT-TILEHEIGHT);
					break;
				case sf::Keyboard::Left:
					circlePos.x -= TILEWIDTH; 
					circlePos.x = clamp(circlePos.x, 0, SCREENWIDTH-TILEWIDTH);
					break;
				case sf::Keyboard::Right:
					circlePos.x += TILEWIDTH;
					circlePos.x = clamp(circlePos.x, 0, SCREENWIDTH-TILEWIDTH);
					break;
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
void drawCells(sf::RenderWindow& window) {
	for(int i = 0; i < SCREENWIDTH; i += TILEWIDTH) {
		for(int j = 0; j < SCREENHEIGHT; j  += TILEHEIGHT) {
			sf::RectangleShape rect(sf::Vector2f(5, 5));
			rect.setFillColor(sf::Color::Black);
			rect.move(i, j);
			window.draw(rect);
		}
	}
}

//int main() {
//	sf::RenderWindow window(
//		sf::VideoMode(SCREENWIDTH, SCREENHEIGHT),
//		"ColorDefense", 
//		sf::Style::Default, 
//		sf::ContextSettings(24, 8, 4)); // depth buffer size, stencil buffer size, number of AA samples
//	window.setFramerateLimit(60);
//
//	sf::Texture tower1Texture; 
//	tower1Texture.loadFromFile("res/sprites/tower1.png");
//	sf::Sprite tower;
//	tower.setTexture(tower1Texture);
//	tower.setPosition(convertToPixelCoords(15, 11));
//	
//	sf::CircleShape enemyx = sf::CircleShape((TILEWIDTH / 2) - 2.0f);
//	enemyx.setFillColor(sf::Color::Blue);
//	enemyx.setOutlineColor(sf::Color::Black);
//	enemyx.setOutlineThickness(2.0f);
//	enemyx.setOrigin(-2.0f, -2.0f);
//
//	/** random enemy*/
//	enemy x = enemy(0x000000);
//	wave y;
//	y.insert(y.end(), x);
//	
//
//	int i = 0;
//	y.ready();
//	enemy z (0);
//	while(!y.isFinished())  {
//		logger->debug("not finished");
//		z = y.spawn();
//	}
//	if(y.isFinished()) logger->debug("finished");
//	z.setPosition(500, 500);
//	z.updateTexture();
//
//    while (window.isOpen()) {
//		
//        sf::Event event;
//        while (window.pollEvent(event)) {
//			handleEvents(event, window);
//        }
//
//        window.clear(sf::Color::White);
//
//		enemyx.setPosition(circlePos);
//		if(debugDraw)
//			drawCells(window);
//		window.draw(enemyx);
//		window.draw(tower);
//
//		if(drawCircle)
//			window.draw(*z.getShape());
//
//        window.display();
//		
//		/** change color, just as demonstration*/
//		i++;
//		if(i == 150) {
//			z.setColor(z.getColor() + 0x0000ff);
//			z.updateTexture();
//			
//		}
//		if(i == 300) {
//			z.setColor(z.getColor() + 0x00ff00);
//			z.updateTexture();
//		}
//
//		if(i == 450) {
//			z.setColor(z.getColor() + 0xff0000);
//			z.updateTexture();
//		}
//    }
//
//    return 0;
//}

int main() {
	sf::RenderWindow window(
		sf::VideoMode(SCREENWIDTH, SCREENHEIGHT),
		"ColorDefense", 
		sf::Style::Default, 
		sf::ContextSettings(24, 8, 4)); // depth buffer size, stencil buffer size, number of AA samples
	window.setFramerateLimit(60);

	gamelogic gl;
	enemy test(0x00ff00);
	//auto pos = convertToCellCoords(500, 500);
	//test.setPosition(pos.x, pos.y);
	gl.add_enemy(test);
	test.setPosition(1, 3);
	sf::Shape* sh = test.getShape();
	sh->setPosition(50, 150);
	//gl.move_enemy(test);
	int i = 0;
	while(window.isOpen()) {
		if(i == 150) {
			cout << "Moving enemy! Old position: " << test.getPosition().x << " " << test.getPosition().y << endl;
			gl.move_enemy(test);
			cout << "New position: " << test.getPosition().x << " " << test.getPosition().y << endl;
		}
		sf::Event e;
		while(window.pollEvent(e)) {
			handleEvents(e, window);
		}
		window.clear(sf::Color::White);
		window.draw(gl.getLevel().getTileMap());
		window.draw(*test.getShape());
		window.display();
		i++;
	}

	return 0;
}