#include <windows.h>
#include <string.h>
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <iostream>
#include "Game.h"

int main(int argc, char** argv) {
	Game p;
	p.run();
	
	std::cout << "Debug console started\n";

	return 0;
}