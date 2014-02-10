#include "StdAfx.h"
#include "Lander.h"
#include "math.h"
#include "Ufo.h"


Ufo::Ufo(void)
{
	Reset();
}
Ufo::~Ufo(void)
{
}


void Ufo::Reset()
{
	
	////////////////////
	pos=Vector(-100,650);
	bulletPos = Vector(0,0);
	bulletVel = Vector(0.0,0.0);
	BulletShowing  = true;
	
}
void Ufo::Update()
{
	vel.x += .009;  
	bulletVel.y = -0.09;
    Vector new_pos=pos;
	
	//Vector bullet_new_pos=bulletPos;
	if(pos.x  > 100)
		{
			bulletPos.y -= 10;
			if(pos.x > 1400)
			{
				Reset();
			}
		}
	pos.add(vel); // calculate new position
	//bulletPos.add(bulletVel);
}


void Ufo::Draw(void) 
{
	glPushMatrix();
	glTranslated(pos.x ,pos.y ,0);

	glBegin(GL_QUADS);
		glColor3f(1.0,1.0,0.0);
		glVertex2d(start1Ufo.x,start1Ufo.y);
		glVertex2d(end1Ufo.x,end1Ufo.y);
		glColor3f(1.0,0.0,0.0);
		glVertex2d(start2Ufo.x,start2Ufo.y);
		glVertex2d(end2Ufo.x,end2Ufo.y);
		glColor3f(0.0,1.0,0.0);
		glVertex2d(start3Ufo.x,start3Ufo.y);
		glVertex2d(end3Ufo.x,end3Ufo.y);
		glColor3f(0.0,0.0,1.0);
		glVertex2d(start4Ufo.x,start4Ufo.y);
		glVertex2d(end4Ufo.x,end4Ufo.y);
		glEnd();

	if(BulletShowing)DrawBullet();
	glPopMatrix();
}
void Ufo::DrawBullet()
{
	
	glTranslated(bulletPos.x ,bulletPos.y,0);
	glBegin(GL_QUADS);
	{
		glColor3f(1.0,0.0,0.0);
		glVertex2d(-2,-2);
		glVertex2d(-2,2);
		glVertex2d(2,2);
		glVertex2d(2,-2);
	}
	glEnd();
}



