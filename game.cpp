#include "game.h"
#include "const.h"

Game::Game() {
	window.create(sf::VideoMode(
		static_cast<size_t>(WINDOW_WIDTH),
		static_cast<size_t>(WINDOW_HEIGHT)
		), WINDOW_TITLE);
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	road1.init(0.f, 0.f);
	road2.init(0.f, -WINDOW_HEIGHT);
}
void Game::play() {
	while (window.isOpen()) {
		checkEvents();
		update();
		draw();
	}
}
void Game::checkEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
	}
}
void Game::update() {
	road1.update();
	road2.update();
}
void Game::draw() {
	window.clear(sf::Color(150,150,150));
	window.draw(road1.getSprite());
	window.draw(road2.getSprite());
	window.display();
}