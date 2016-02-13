#pragma once

#include <SDL/SDL.h>
#include <GL\glew.h>

#include "InputDevice.h"
#include "Screen.h"
#include "Audio.h"
#include "Sprite.h"

//states of game
enum class state {PLAY, EXIT};

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void init();
	void input();
	void gameLoop();
	void draw();

	InputDevice _input;
	Screen _screen;
	Audio _audio;

	SDL_Window* _window;
	int _screenWidth, _screenHeight;
	state _state;

	Sprite _sprite;
};

