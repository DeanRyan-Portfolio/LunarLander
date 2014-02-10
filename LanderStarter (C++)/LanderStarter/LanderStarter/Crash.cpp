#include "stdafx.h"
#include "Crash.h"
#include "opengl.h"
#define _USE_MATH_DEFINES
#include <cmath>



Crash::Crash(void)
{
	sides = 100;
	radius = 60;
	PI = 3.14;
}
Crash::~Crash(void)
{

}
int Crash::crashEffect(int point1, int point2)
{
	glColor3f(1.0f,.0f,.0f);
	
	glBegin(GL_POINTS);
	{
		for(int i = 0; i <sides; i++)
		{
			crash1= cos((i+1) * 2 * 3.14/sides) * radius;
			crash2= sin((i+1) * 2 * 3.14/sides) * radius;
			glVertex2d(crash1 + point1, crash2 + point2);
		}
	}
	glEnd();
	return 0;

}