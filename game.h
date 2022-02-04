#pragma once
#include "SFML/Graphics.hpp"
#include "road.h"

class Game {
private:
	sf::RenderWindow window;
	Road road1, road2;
public:
	Game();
	void play();
	void checkEvents();
	void update();
	void draw();
};