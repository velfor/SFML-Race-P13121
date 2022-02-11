#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Car{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Car() {
		texture.loadFromFile(CAR_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setScale(0.1f, 0.1f);
		sprite.setPosition(WINDOW_WIDTH/2 - sprite.getGlobalBounds().width/2,
			WINDOW_HEIGHT - sprite.getGlobalBounds().height - 10 );
	}
	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			speed.x = -CAR_SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			speed.x = CAR_SPEED;
		}
		sprite.move(speed);
		sf::Vector2f curr_pos = sprite.getPosition();
		if (curr_pos.x <= 0) {
			curr_pos.x = 0;
		}
		if (curr_pos.x >= WINDOW_WIDTH - getHitBox().width) {
			curr_pos.x = WINDOW_WIDTH - getHitBox().width;
		}
		sprite.setPosition(curr_pos);
	}
};
