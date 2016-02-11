#pragma once

#include <GL\glew.h>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);
	void draw();

private:
	int _x;
	int _y;
	int _width;
	int _height;

	//Gl unsigned int guaranteed to be 32 bits!
	GLuint _vboID;
};

