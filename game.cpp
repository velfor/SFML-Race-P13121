#include "game.h"
#include "const.h"

Game::Game():
	window	(	sf::VideoMode(
				static_cast<size_t>(WINDOW_WIDTH), 
				static_cast<size_t>(WINDOW_HEIGHT)),
				WINDOW_TITLE
			),
	splash_screen(SPLASH_FILE_NAME, 1.2f, 1.43f),
	game_over_screen(GAME_OVER_FILE_NAME, 1.351f, 2.135f),
	road1(0.f, 0.f),
	road2(0.f, -WINDOW_HEIGHT),
	barrier1(0.f, -barrier1.getHitBox().height),
	barrier2(200.f, -WINDOW_HEIGHT / 2)
{
	window.setVerticalSyncEnabled(true);
}
void Game::play() {
	while (window.isOpen()) {
		checkEvents();
		update();
		check_collisions();
		draw();
	}
}
void Game::checkEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyPressed ) {
			if (game_state == SPLASH && event.key.code == sf::Keyboard::Space) {
				game_state = PLAY;
			}
		}
	}
}
void Game::update() {
	switch (game_state) {
	case SPLASH:

		break;
	case PLAY:
		road1.update();
		road2.update();
		car.update();
		barrier1.update();
		barrier2.update();
		break;
	case GAME_OVER:
		break;
	}
}
void Game::draw() {
	
	switch (game_state) {
	case SPLASH:
		window.clear(sf::Color::White);
		window.draw(splash_screen.getSprite());
		break;
	case PLAY:
		window.clear(sf::Color(150, 150, 150));
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.draw(barrier1.getSprite());
		window.draw(barrier2.getSprite());
		window.draw(car.getSprite());
		break;
	case GAME_OVER:
		window.clear(sf::Color(150, 150, 150));
		window.draw(game_over_screen.getSprite());
		break;
	}
	window.display();
}
void Game::check_collisions() {
	if (car.getHitBox().intersects(barrier1.getHitBox()) ||
		car.getHitBox().intersects(barrier2.getHitBox())
		)
	{
		//какие-то действия
		game_state = GAME_OVER;
	}
}