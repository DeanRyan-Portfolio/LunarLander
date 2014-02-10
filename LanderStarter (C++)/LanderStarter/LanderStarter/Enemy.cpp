#include "StdAfx.h"
#include "Lander.h"
#include "math.h"
#include "Enemy.h"


Enemy::Enemy(void)
{
	
	Reset();
	
	
}
Enemy::~Enemy(void)
{
}

void Enemy::Reset()
{
	gravity = -0.2;
	////////////////////
	pos=Vector(-100,675);
	bulletPos = Vector(0,5);
	bulletVel = Vector(0.0,0.0);
	BulletShowing  = true;
	////////////////////
	bulletPos2 = Vector(0,5);
	bulletVel2 = Vector(0.0,0.0);
	pos2=Vector(-100,100);
}
void Enemy::Update()
{
	vel.x += .009;  
	bulletVel.y = 0.2;
	//
	vel2.x += .009;
	bulletVel2.y = 0.2;
	//
    Vector new_pos=pos;
	Vector new_pos2 = pos2;
	//
	Vector bullet_new_pos=pos;
	Vector bullet_new_pos2=pos2;
	//
	if(pos.x  > 100)
		{
			bulletPos.y -= 10;
			bulletPos.x -= 2;
			if(pos.x > 1300)
			{
				Reset();
			}
		}
	
	if(pos2.x > 100)
	{
		bulletPos2.y += 5;
		bulletPos2.x -= 2;
		if(pos2.x > 300)
		{
			pos2.x = 300;
			vel2.y += 10;
			bulletVel2.y += 5;
		}
		
	}
	pos.add(vel); // calculate new position
	pos2.add(vel2);
	bullet_new_pos.add(bulletVel);
	bullet_new_pos2.add(bulletVel2);
}

void Enemy::Draw(void) 
{
	glPushMatrix();
	glTranslated(pos.x ,pos.y ,0);
	glBegin(GL_QUADS);
	{
		glVertex2d(-10,-10);
		glVertex2d(-10,10);
		glVertex2d(10,10);
		glVertex2d(10,-10);
	}
	glEnd();

	if(BulletShowing)DrawBullet();
	glPopMatrix();
}
void Enemy::DrawBullet()
{
	glTranslated(bulletPos.x ,bulletPos.y,0);
	glBegin(GL_QUADS);
	{
		glVertex2d(-2,-2);
		glVertex2d(-2,2);
		glVertex2d(2,2);
		glVertex2d(2,-2);
	}
	glEnd();
}


