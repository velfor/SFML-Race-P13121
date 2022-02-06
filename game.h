#pragma once
#include "SFML/Graphics.hpp"
#include "road.h"
#include "splash.h"
#include "car.h"

class Game {
public:
	Game();
	void play();
	void checkEvents();
	void update();
	void draw();
	enum GameState {SPLASH, PLAY, GAME_OVER};
private:
	sf::RenderWindow window;
	GameState game_state{ SPLASH };
	Road road1, road2;
	SplashScreen splash;
	Car car;
};