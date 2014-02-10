#include "stdafx.h"
#include "Crash.h"
#include "opengl.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Shield.h"



Shield::Shield(void)
{
	sidesOfShield = 100;
	radiusOfShield = 50;
	PI = 3.14;
}
Shield::~Shield(void)
{

}
int Shield::shieldShowing(int point1, int point2)
{
	glColor3f(1.0f,.0f,.0f);
	
	glBegin(GL_POINTS);
	{
		for(int i = 0; i <sidesOfShield; i++)
		{
			shield1= cos((i+1) * 2 * 3.14/sidesOfShield) * radiusOfShield;
			shield2= sin((i+1) * 2 * 3.14/sidesOfShield) * radiusOfShield;
			glVertex2d(shield1 + point1, shield2 + point2);
		}
	}
	glEnd();
	return 0;

}