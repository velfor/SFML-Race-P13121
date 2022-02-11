#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Barrier {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Barrier() {
		texture.loadFromFile(BARRIER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setScale(0.35f, 0.35f);
	}
	void init(float x, float y) { sprite.setPosition(x, y); }
	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		sf::Vector2f speed = sf::Vector2f(0.f, 3.f);
		sprite.move(speed);

		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			size_t line = rand() % 3;
			sprite.setPosition(line * 200, 0 - getHitBox().height);
		}
	}
};
