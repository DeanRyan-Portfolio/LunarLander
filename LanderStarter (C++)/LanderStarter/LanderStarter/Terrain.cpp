#pragma once
#include "StdAfx.h"
#include "Lander.h"
#include "math.h"
#include "Terrain.h"
#include <cstdlib>
#include <ctime>
#include "Ufo.h"


Terrain::Terrain(void)
{
	srand((unsigned)time(NULL)); 
	const int terrain_points = 10;
	
	const int landingPad_Points = 2;
	for(int j = 0; j < landingPad_Points ;j++)
	{
			//landPadRandom = rand()% 500;
			landingPadArray[j][0] =  j * 70;
			landingPadArray[j][1] = 200;
	}
}
Terrain::~Terrain(void)
{
}
void Terrain::landingPad(void)
{
	glColor3f(2,3,3);
	glBegin(GL_LINE_STRIP);
	{
		for(int i = 0; i < 2; i++)
		{
			glVertex2d(landingPadArray [i][0],landingPadArray[i][1]);
		}
	}
	glEnd();
}



bool Terrain::WithinFirstSegment(Vector p)
{
	if(p.x>= start1.x && p.x <= end1.x)
		return true;

	else
		return false;
}
bool Terrain::WithinSecondSegement(Vector p)
{
	if(p.x>= start2.x && p.x <= end2.x)// 
		return true;

	else
		return false;
}
bool Terrain::WithinThirdSegement(Vector p)
{

	if(p.x>= start3.x && p.x <= end3.x)// 
		return true;

	else
		return false;
}
bool Terrain::WithinForthSegement(Vector p)
{
	if(p.x>= start4.x && p.x <= end4.x)// 
		return true;

	else
		return false;
}



int Terrain::Distance1(Vector p)
{
	float m=(float)(end1.y-start1.y)/(end1.x-start1.x);
	float y= m*(p.x-start1.x)+start1.y;
	return p.y-y;
}
int Terrain::Distance2(Vector p)
{
	
	float m=(float)(end2.y-start2.y)/(end2.x-start2.x);
	float y= m*(p.x-start2.x)+start2.y;
	return p.y-y;

}
int Terrain::Distance3(Vector p)
{
	
	float m=(float)(end3.y-start3.y)/(end3.x-start3.x);
	float y= m*(p.x-start3.x)+start3.y;
	return p.y-y;
}
int Terrain::Distance4(Vector p)
{
	float m=(float)(end4.y-start4.y)/(end4.x-start4.x);
	float y= m*(p.x-start4.x)+start4.y;
	return p.y-y;
}
void Terrain::Draw()
{
		glBegin(GL_LINES);
		glVertex2d(start1.x,start1.y);
		glVertex2d(end1.x,end1.y);
		glVertex2d(start2.x,start2.y);
		glVertex2d(end2.x,end2.y);
		glVertex2d(start3.x,start3.y);
		glVertex2d(end3.x,end3.y);
		glVertex2d(start4.x,start4.y);
		glVertex2d(end4.x,end4.y);
		glEnd();
}



