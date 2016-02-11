#pragma once

#include <SDL/SDL.h>
#include <GL\glew.h>

#include "Sprite.h"

//states of game
enum class state {PLAY, EXIT};

class Peli
{
public:
	Peli();
	~Peli();

	void run();

private:
	void init();
	void input();
	void gameLoop();
	void draw();

	SDL_Window* _window;
	int _screenWidth, _screenHeight;
	state _state;

	Sprite _sprite;
};

