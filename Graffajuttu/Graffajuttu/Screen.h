#pragma once

#include "Sprite.h"
#include <GL\glew.h>

class Screen
{
public:
	Screen();
	~Screen();
	void draw();

private:
	Sprite _sprite;

};

