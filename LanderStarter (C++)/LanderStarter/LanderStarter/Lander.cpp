#include "StdAfx.h"
#include "Lander.h"
#include "math.h"
#include "Terrain.h"
#include <cstdlib>
#include <ctime>
#include "Ufo.h"
#include "Game.h"


Lander::Lander(void)
{
	Reset();
	
	
}
Lander::~Lander(void)
{

}
void Lander::Reset()
{
	rotation=0;
	gravity = -0.2;
	rotationSpeed=5;
	engine_acceleration=Vector(0.0,0.5);
	pos=Vector(30,700.0);
	vel=Vector(0.0,0.0);
    flame=false;
	score = 0;
	Draw_Ship = true;
	dead = false;
	
	landed = false;
	
}
// DRAWS EVERYTHING 
void Lander::Draw(void)
{
	if (Draw_Ship == true)
	{
	const int  num_body_points=7; 
    const int  num_leg_points=4;
    float body_points[num_body_points*2][2]={{0,20},{5,18},{5,18},{10,14},{10,14},{5,5},{5,5},{-5,5},{-5,5},{-10,14},{-10,14},{-5,18},{-5,18},{0,20}};
    float leg_points[num_leg_points][2]={{8,9},{15,0},{20,0},{10,0}};
	//static float  frame=0;
	
    // the lunar lander

	glPushMatrix();//a
	glColor3f(1.0,1.0,1.0);
	
	if(!dead)
	{
		glTranslated(pos.x,pos.y,0);
		glRotated(rotation,0,0,1);
		glTranslated(0,-6,0);
		glBegin(GL_LINES);
		for(int i=0;i<num_body_points*2;i++)
		{
			glVertex2d(body_points[i][0],body_points[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for(int i=0;i<num_leg_points;i++)
		{
			glVertex2d(leg_points[i][0],leg_points[i][1]);
		}
		glEnd();

		glScaled(-1,1,1);
		glBegin(GL_LINES);
		for(int i=0;i<num_leg_points;i++){
			glVertex2d(leg_points[i][0],leg_points[i][1]);
		}
		glEnd();
	}

	
	}
	if(flame)DrawFlame();
	
	glPopMatrix();
	
	

}

void Lander::DrawFlame(void)
{
	
    const int  flame=10;
	int flame_points[flame][2]={{0,4},{0,-6},{1,3},{4,-4},{-1,3},{-4,-4},{2,2},{6,-3},{-2,2},{-6,-3}};

    glBegin(GL_LINES);
    for(int i=0;i<flame;i++)
	{
		glColor3f(1.0,0,0);
        glVertex2d(flame_points[i][0],flame_points[i][1]);
    }
    glEnd();

}
void Lander::Update()
{ // update lander position for each frame
	Vector accel(0,0); // initial acceleration is zero
	vel.y += gravity;
	
	
    if(GetKeyState('A') & 128 )
	{
        rotation+=rotationSpeed;
	}
    if(GetKeyState('S') & 128)
	{
        rotation-=rotationSpeed;
	}
    if(GetKeyState(VK_SPACE) & 128)
	{
        flame=true;
		Vector thrust=engine_acceleration;
		thrust.rotate(-rotation);
        accel.add(thrust) ; // add thrust to gravity
		fuel--;
    }
    else
	{
        flame=false;
    }

	//Enemy bulletCollision;
    vel.add(accel); //calculate new speed
    Vector new_pos=pos;
 
	new_pos.add(vel); // calculate new position to check for out of bounds
	//get the size of the viewport
	GLint p[4];
	glGetIntegerv(GL_VIEWPORT,p);
	int vpwidth=p[2];
	int vpheight=p[3];

	//check for out of bounds (bounce off sides of window)
	if(new_pos.x < 0)
	{
		pos.x  = 1300;
	}
	if(new_pos.x > 1300)
	{
		pos.x = -10 ;
	}
	pos.add(vel); // calculate new position
	
	

}
void Lander::StopShip()
{
	vel.y = 0;
	vel.x = 0;
	gravity = 0;
}




	

