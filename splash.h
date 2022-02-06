#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class SplashScreen {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	SplashScreen() {
		texture.loadFromFile(SPLASH_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setScale(1.2f, 1.43f);
		sprite.setColor(sf::Color(255,228,181));
	}
	sf::Sprite getSprite() { return sprite; }
};