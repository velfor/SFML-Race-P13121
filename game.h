#pragma once
#include "SFML/Graphics.hpp"
#include "road.h"
#include "splash.h"
#include "car.h"
#include "barrier.h"
#include "text.h"

class Game {
public:
	enum GameState { SPLASH, PLAY, GAME_OVER };
	Game();
	void play();
	void checkEvents();
	void update();
	void draw();
	void check_collisions();
	
private:
	sf::RenderWindow window;
	GameState game_state{ SPLASH };
	Road road1, road2;
	SplashScreen splash_screen, game_over_screen;
	Car car;
	Barrier barrier1, barrier2;
	TextObject score_text;
	
};