#include "stdafx.h"
#include <SFML/Graphics.hpp>

const int xSize = 800;
const int ySize = 600;
bool drawCircle = true;

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
	sf::Texture enemyTexture; 
	enemyTexture.loadFromFile("res/sprites/enemy1.png");
	sf::Sprite enemy;
	enemy.setTexture(enemyTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
			handleEvents(event, window);
        }

        window.clear(sf::Color::White);
		if(drawCircle)
			window.draw(enemy);
        window.display();
    }

    return 0;
}