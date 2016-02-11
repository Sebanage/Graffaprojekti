#include "Peli.h"
#include <iostream>
#include <string>


void fatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}
Peli::Peli()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_state = state::PLAY;
}

void Peli::run()
{
	//initialize systems
	init();

	_sprite.init(-1,-1, 1, 1);

	//run main game loop
	gameLoop();
}

void Peli::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("SUPERGRAFFAJUTTUJEEE!!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

	
	if (_window == nullptr) {
		fatalError("SDL window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL window could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glew!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f,0.0f,1.0f,1.0);
}

void Peli::input()
{
	SDL_Event event;
	

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_state = state::EXIT;
		case SDL_MOUSEMOTION:
			std::cout << event.motion.x << "  " << event.motion.y << std::endl;
		}
	}

}

void Peli::gameLoop()
{
	while (_state != state::EXIT) {
		input();
		draw();
	}

}

void Peli::draw()
{
	glClearDepth(1.0);

	//Bitwise "or" = call both!
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_sprite.draw();

	SDL_GL_SwapWindow(_window);

}




Peli::~Peli()
{

}