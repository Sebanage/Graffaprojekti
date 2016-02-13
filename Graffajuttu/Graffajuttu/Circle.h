#pragma once

#include "Sprite.h"

class Circle : public Sprite
{
public:
	Circle(float* r, int* n);
	~Circle();

	void draw();
	float deg2rad(float deg);

private:
	float _radius;
	float vertexData[50];
};

