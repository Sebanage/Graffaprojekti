#include "Circle.h"
#include <math.h>
#include <GL\glew.h>

static float pi = 3.14159265359;

//conversion factor from degrees to radians
static float radConvert = pi/180;

//conversion factor from radians to degrees
static float degConvert = 180/pi;

Circle::Circle(float* r, int *n)
{
	_radius = *r;
	//n m‰‰r‰ kolmioita, jokainen kolmio = 3 pistett‰, jokainen piste 2 koordinaattia. n*3*2 = 6n

	//keskipiste
	vertexData[0] = 0;
	vertexData[1] = 0;

	int vrtIndex = 2; //mihin vertexDatan indeksiin talletetaan
	for (int i = 0; i < 360; i++) {
		//1. keh‰piste
		vertexData[vrtIndex] = cos(deg2rad(i)*_radius);
		vrtIndex++;
		vertexData[vrtIndex] = sin(deg2rad(i)*_radius);
		vrtIndex++;

		//siirryt‰‰n seuraavaan keh‰pisteeseen
		i = 360 / (*n);

		//2. keh‰piste
		vertexData[vrtIndex] = cos(deg2rad(i)*_radius);
		vrtIndex++;
		vertexData[vrtIndex] = sin(deg2rad(i)*_radius);
		vrtIndex++;

		//keskipiste
		vertexData[vrtIndex] = 0;
		vrtIndex++;
		vertexData[vrtIndex] = 0;
		vrtIndex++;
	}
	int i = 2;
	//generate circle data
	while (i < sizeof(vertexData)) {
		//vertexData[i] = cos();
		i++;
	}

}

void Circle::draw()
{
	//bind buffer
	//glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	//t‰ss‰ tulee kaatuminen! Intel HD Graphics driver issue?
	//glDisableVertexArrayAttrib(GL_ARRAY_BUFFER, 0);

	//unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

float Circle::deg2rad(float deg) {
	return deg * radConvert;
}

Circle::~Circle()
{
	
}




