#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Road {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed{ sf::Vector2f(ROAD_SPEED_X, ROAD_SPEED_Y) };
public:
	Road(float x, float y) {
		texture.loadFromFile(ROAD_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setScale(ROAD_SCALE_X, ROAD_SCALE_Y);
		sprite.setPosition(x, y);
	}
	
	sf::Sprite getSprite() { return sprite; }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(0.f, -WINDOW_HEIGHT);
		}
	}
};
