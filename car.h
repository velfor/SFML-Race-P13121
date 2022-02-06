#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"
#include <iostream>

class Car{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Car() {
		texture.loadFromFile(CAR_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setOrigin(sprite.getLocalBounds().width / 2, 
			sprite.getLocalBounds().height / 2);
		sprite.setScale(0.1f, 0.1f);
		sprite.setRotation(90.f);
		sprite.setPosition(WINDOW_WIDTH / 2, 
			WINDOW_HEIGHT - sprite.getGlobalBounds().height/2 -5 );
		
		
	}
	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};
