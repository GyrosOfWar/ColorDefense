#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "enemy.hpp"
#include "Logger.hpp"
#include <sstream>
#include <string>
#include "wave.hpp"
using namespace game;

const int xSize = 800;
const int ySize = 600;
bool drawCircle = true;
Logger* logger = Logger::get();

void handleEvents(sf::Event& e, sf::Window& window) {
	switch (e.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch(e.key.code) {
				case sf::Keyboard::Space:
					drawCircle = !drawCircle;
					break;
				}
			break;
		default:
			break;
		}
}

int main() {
    sf::RenderWindow window(sf::VideoMode(xSize, ySize), "ColorDefense");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(60);
	/*sf::Texture enemyTexture; 
	enemyTexture.loadFromFile("res/sprites/enemy1.png");
	sf::Sprite enemy;
	enemy.setTexture(enemyTexture);*/

	/** random enemy*/
	enemy x = enemy(0x00ff00);
	wave y;
	y.insert(y.end(),&x);

	int i = 0;
	y.ready();
	if(!y.isFinished()) logger->debug("not finished");

	enemy* z = y.spawn();
	if(y.isFinished()) logger->debug("finished");

    while (window.isOpen()) {
		
        sf::Event event;
        while (window.pollEvent(event)) {
			handleEvents(event, window);
        }

        window.clear(sf::Color::White);
		if(drawCircle)
			window.draw(*x.getSprite());
        window.display();
		
		/** change color, just as demonstration*/
		i++;
		if(i == 300) {
			x.setColor(0xff0000);
			x.updateTexture();
		}
    }

    return 0;
}